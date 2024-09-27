#include <fcntl.h>
#include <stdarg.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <netinet/if_ether.h>
#include <net/if_arp.h>
#include <cstring>
#include <cerrno>
#include <utmp.h>
#include <sys/stat.h>
#include <cstdlib>
#include <openssl/rsa.h>
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "doorsdefs.h"
#include "doorsbase.h"

#define CHK_NULL(x) if ((x) == NULL) exit(1)
#define CHK_ERR(err, s) if ((err) == -1) { perror(s); exit(1); }
#define CHK_SSL(err) if ((err) == -1) { ERR_print_errors_fp(stderr); exit(2); }

#define HOME "./"
#define CERTF HOME "foo-cert.pem"
#define KEYF HOME "foo-cert.pem"

CConfig::CConfig(const char *szFile) : m_pFp(nullptr), m_szFile(szFile ? szFile : "") {}

CConfig::~CConfig() = default;

int CConfig::Read(const char *szSess, const char *szItem, char *szValue, const char *szDefault) {
    m_pFp = fopen(m_szFile.c_str(), "r");
    if (m_pFp == nullptr) {
        strncpy(szValue, szDefault, strlen(szDefault) + 1);
        return 0;
    }

    std::string szSess1 = "[" + std::string(szSess) + "]";
    bool bEnterSess = false;
    char szLine[256];

    while (fgets(szLine, 255, m_pFp)) {
        if (!bEnterSess) {
            if (strncasecmp(szLine, szSess1.c_str(), szSess1.length()) == 0)
                bEnterSess = true;
        } else {
            if (szLine[0] == '[') {
                break;
            }
            if (strncasecmp(szLine, szItem, strlen(szItem)) == 0) {
                char *p = strchr(szLine, '=');
                if (!p) return 0;
                p++;
                while (*p == ' ') p++;
                char *p2 = strchr(p, ';');
                if (!p2) {
                    return 0;
                }
                strncpy(szValue, p, p2 - p);
                szValue[p2 - p] = '\0';
                fclose(m_pFp);
                m_pFp = nullptr;
                return 1;
            }
        }
    }
    strncpy(szValue, szDefault, strlen(szDefault) + 1);
    fclose(m_pFp);
    m_pFp = nullptr;
    return 0;
}
bool CSocket::GetMyIp(char *szBuf) {
    sockaddr_in sockaddr;
    bzero(&sockaddr, sizeof(sockaddr));
    unsigned int len;
    if (getpeername(m_hSocket, (sockaddr *)&sockaddr, &len) < 0) {
        return false;
    }
    strncpy(szBuf, inet_ntoa(sockaddr.sin_addr));
    return true;
}

CSocket::CSocket() : m_hSocket(INVALID_SOCKET), m_bConnected(false) {}

CSocket::CSocket(SOCKET s) : m_hSocket(s), m_bConnected(true) {}

CSocket::~CSocket() {
    Close();
}

void CSocket::SetSocket(SOCKET s) {
    m_hSocket = s;
    m_bConnected = true;
}

int CSocket::ConnectionReset() {
    m_bConnected = false;
    return 1;
}

bool CSocket::Create(SOCKTYPE nSockType) {
    switch (nSockType) {
        case SOCKTYPE::TCP:
            m_hSocket = socket(AF_INET, SOCK_STREAM, 0);
            break;
        case SOCKTYPE::UDP:
            m_hSocket = socket(AF_INET, SOCK_DGRAM, 0);
            break;
        case SOCKTYPE::ARP:
            m_hSocket = socket(PF_PACKET, SOCK_PACKET, htons(ETH_P_ARP));
            if (m_hSocket > 0) {
                int optval = 1;
                if (setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) == -1) {
                    std::cerr << "Could not setsocketopt on raw socket\n";
                    close(m_hSocket);
                    return false;
                }
            }
            break;
        case SOCKTYPE::ALL:
            m_hSocket = socket(PF_PACKET, SOCK_PACKET, htons(ETH_P_ALL));
            if (m_hSocket > 0) {
                int optval = 1;
                if (setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) == -1) {
                    std::cerr << "Could not setsocketopt on raw socket\n";
                    close(m_hSocket);
                    return false;
                }
            }
            break;
        default:
            return false;
    }
    return (m_hSocket != INVALID_SOCKET);
}

bool CSocket::Close() {
    if (m_hSocket != INVALID_SOCKET) {
        close(m_hSocket);
        m_hSocket = INVALID_SOCKET;
    }
    return true;
}
bool CSocket::Connect(const std::string& szServAddr, int nServPort) {
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(nServPort);
    servAddr.sin_addr.s_addr = inet_addr(szServAddr.c_str());

    if (connect(m_hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        return false;
    }
    return true;
}

bool CSocket::Connect(uint32_t dwIp, int nServPort) {
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(nServPort);
    servAddr.sin_addr.s_addr = dwIp;

    if (connect(m_hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        return false;
    }
    return true;
}

bool CSocket::ConnectTimeOut(const std::string& szHost, uint16_t nPort, long timeout) {
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(nPort);

    struct hostent* pHost = gethostbyname(szHost.c_str());
    if (pHost == NULL) {
        return false;
    }
    memcpy(&servAddr.sin_addr, pHost->h_addr, pHost->h_length);

    fcntl(m_hSocket, F_SETFL, O_NONBLOCK);
    connect(m_hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr));

    fd_set set;
    struct timeval tv;
    FD_ZERO(&set);
    FD_SET(m_hSocket, &set);
    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    if (select(m_hSocket + 1, NULL, &set, NULL, &tv) > 0) {
        int valopt;
        socklen_t lon = sizeof(int);
        getsockopt(m_hSocket, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon);
        if (valopt) {
            return false;
        }
    } else {
        return false;
    }

    fcntl(m_hSocket, F_SETFL, 0);
    return true;
}
