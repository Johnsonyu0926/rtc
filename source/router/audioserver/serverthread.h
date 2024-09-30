#ifndef __SERVER_THREAD_H__
#define __SERVER_THREAD_H__

#include "CSThread.h"

class CSocket;

class CServerThread : public CSThread {
public:
    BOOL InitInstance() override;
    BOOL ExitInstance() override;

    void SetPort(int nPort) { m_nPort = nPort; }

private:
    int m_nPort;
};

#endif
