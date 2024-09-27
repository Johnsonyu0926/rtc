#ifndef ICAP_H
#define ICAP_H

#include <string>
#include <memory>
#include "doorsbase.h"

struct ContentList {
    std::string Content;
    int ContentLen;
    int id;
    std::shared_ptr<ContentList> Next;
};

class CIcap {
public:
    CIcap()
        : MyList(std::make_shared<ContentList>()), pList(MyList),
          m_nContentLen(0), count(0) {
        MyList->Content = "";
        MyList->ContentLen = 0;
        MyList->Next = nullptr;
        m_pContent = nullptr;
    }

    ~CIcap() {
        if (m_pContent) {
            delete[] m_pContent;
            m_pContent = nullptr;
        }
    }

    void AddContent(const std::string& szContent) {
        DS_TRACE("ADD CONTENT \n" << count);
        count++;
        auto NewNode = std::make_shared<ContentList>();
        NewNode->Content = szContent;
        NewNode->ContentLen = szContent.length();
        NewNode->id = count;
        NewNode->Next = nullptr;
        pList->Next = NewNode;
        pList = pList->Next;
        m_nContentLen += szContent.length();
    }

    void SetIcapServer(const std::string& szServer, int nServerPort) {
        strncpy(m_szIcapServer, szServer.c_str(), sizeof(m_szIcapServer));
        m_nIcapServerPort = nServerPort;
    }

    // 使用 respmod 发送到 icap 服务器并检查响应。
    BOOL RespMod(char *pszAddress, int argflag, char *szVirus, int nLen);

    void PrintContent() {
        for (int i = 0; i < count; i++) {
            DS_TRACE("I IS : " << i);
        }
    }

    BOOL ReleaseList();

private:
    char *m_pContent;
    int m_nContentLen;
    char m_szIcapServer[32];
    int m_nIcapServerPort;
    std::shared_ptr<ContentList> MyList;
    std::shared_ptr<ContentList> pList;
    bool IsFirst;
    int count;
};

#endif // ICAP_H
