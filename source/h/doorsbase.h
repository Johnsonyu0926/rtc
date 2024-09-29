#ifndef DOORS_BASE_H
#define DOORS_BASE_H

#include <openssl/rsa.h>
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/md5.h>
#include <openssl/err.h>
#include <pthread.h>
#include <sys/time.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "doorsdefs.h"

#ifdef _DEBUG
#include <cassert>
#define DS_ASSERT assert
#else
#define DS_ASSERT(x) ((void)0)
#endif

class CConfig {
public:
    explicit CConfig(const std::string& szIniFile);
    ~CConfig();
    bool Init(const std::string& szInitFile);
    int Read(const std::string& szSess, const std::string& szItem, std::string& szValue, const std::string& szDefault);

private:
    FILE* m_pFp;
    std::string m_szFile;
};

enum class SHUTDOWN {
    RECEIVE = 0,
    SEND = 1,
    BOTH = 2
};

enum class SOCKTYPE {
    TCP,
    UDP,
    ARP,
    ALL,
    RAW
};

constexpr int BUF_MAX = 4096;

class CSocket {
public:
    CSocket();
    explicit CSocket(SOCKET s);
    ~CSocket();

    SOCKET GetHandle() const;
    bool Create(SOCKTYPE nSockType);
    bool Connect(const std::string& szServAddr, int nServPort);
    bool Connect(uint32_t dwIp, int nServPort);
    bool ConnectTimeOut(const std::string& szHost, uint16_t nPort, long timeout);

    bool Bind(int nBindPort);
    int Bind();
    bool Listen();
    bool Accept(CSocket* clnaccept);

    int Send(const void* buf, int nBytes);
    int Send(const std::string& szWillSend);
    int Recv(void* szRecvBuf, int nBufSize);
    int Recv(std::string& szRecvBuf);
    int Recv(char* szRecvBuf, int nBufSize, int nTimeOut);
    int Recv(char* szRecvBuf, int nBufSize, int nTimeOut, bool bSure);

    bool InetN2P(void* pSinAddr, char* szPtr, int nLen, int nFamily = AF_INET);
    bool InetP2N(const std::string& szIP, void* pSinAddr, int nFamily = AF_INET);
    uint32_t InetP2N(const std::string& szIP, int nFamily = AF_INET);

    bool SetNonBlock();
    bool ResetBlock();
    bool Close();
    int RecvLine(std::string& szBuf);
    bool GetMyIp(char* szIp);
    std::string GetRemoteIp();
    uint32_t GetPeerIp() const;
    uint16_t GetPeerPort() const;
    int ConnectionReset();
    bool Shutdown(int nHow);

    static bool QueryDns(std::string& szAddress, const std::string& szHost);
    static bool IsDotIp(const std::string& szHost);

private:
    bool ConnectIp(const std::string& szIp, int nPort);

private:
    SOCKET m_hSocket;
    uint32_t m_dwPeerIp;
    int m_nPeerPort;
    bool m_bConnected;
};

class CSThread {
public:
    CSThread();
    virtual ~CSThread();

    virtual bool InitInstance() = 0;
    virtual bool ExitInstance() = 0;

    bool SetAutoDelete(bool b);
    void SetJoinable(bool b);
    bool CreateThread();
    void WaitForEnd();

protected:
    virtual void Run() = 0;

private:
    static void* ThreadFunc(void* arg);

private:
    pthread_t m_threadId;
    bool m_bAutoDelete;
    bool m_bJoinable;
};

#endif // DOORS_BASE_H
class CThread {
public:
    CThread();
    virtual ~CThread();

    bool CreateThread();
    bool SuspendThread();
    bool ResumeThread();
    bool TerminateThread();
    bool WaitForThreadEnd();

protected:
    virtual void Run() = 0;

private:
    static void* ThreadFunc(void* pParam);

private:
    pthread_t m_thread;
    bool m_bRunning;
};

class CMutex {
public:
    CMutex();
    ~CMutex();

    void Lock();
    void Unlock();

private:
    pthread_mutex_t m_mutex;
};

class CEvent {
public:
    CEvent();
    ~CEvent();

    bool Wait();
    void Signal();
    void Reset();

private:
    pthread_cond_t m_cond;
    pthread_mutex_t m_mutex;
    bool m_bSignaled;
};

class CIniFile {
public:
    CIniFile();
    virtual ~CIniFile();

    bool Load(const std::string& filename);
    bool Save(const std::string& filename);
    std::string GetValue(const std::string& section, const std::string& key);
    void SetValue(const std::string& section, const std::string& key, const std::string& value);

private:
    std::map<std::string, std::map<std::string, std::string>> m_data;
    std::string m_filename;
};

#endif // DOORS_BASE_H
class CDatabase {
public:
    CDatabase();
    virtual ~CDatabase();

    bool Connect(const std::string& connectionString);
    void Disconnect();
    bool ExecuteQuery(const std::string& query);
    std::vector<std::string> FetchResults();

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // DOORS_BASE_H
