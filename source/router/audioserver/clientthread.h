#ifndef __CLIENT_THREAD_H__
#define __CLIENT_THREAD_H__

#include "json.hpp"
#include <vector>
#include <string>

class CSThread;
class CSocket;

using json = nlohmann::json;

class CClientThread : public CSThread {
public:
    CClientThread() : m_pClient(nullptr) {}
    virtual ~CClientThread() = default;

    virtual BOOL InitInstance();
    virtual BOOL ExitInstance();
    void SetClient(CSocket *pClient) { m_pClient = pClient; }

private:
    BOOL Check(const unsigned char *szBuf);
    BOOL Gen(BYTE *szBuf); // ensure the buffer size is 1024 Bytes
    int do_req(char *buf, CSocket *pClient);
    int do_verify(char *buf);
    int do_str_req(CSocket *pClient);
    int do_str_verify(char *buf, CSocket *pClient);

    CSocket *m_pClient;
    json m_json;
    std::vector<std::string> m_str;
};

#endif // __CLIENT_THREAD_H__
