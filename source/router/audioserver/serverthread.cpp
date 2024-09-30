#include <stdio.h>
#include "doorsbase.h"
#include "serverthread.h"
#include "clientthread.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include "utils.h"

BOOL CServerThread::InitInstance() {
    CSocket socket;
    socket.Create(TCP);
    
    int opt = 1;
    setsockopt(socket.m_hSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (!socket.Bind(m_nPort)) {
        LOG(INFO) << "Failed to bind port: " << m_nPort;
        exit(1);
    }

    socket.Listen();
    int i = 0;

    while (true) {
        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        fd_set rset;
        FD_ZERO(&rset);
        FD_SET(socket.m_hSocket, &rset);

        CUtils utils;
        utils.heart_beat("/tmp/audio_server_netvoice_heartbeat.txt");

        int n = select(socket.m_hSocket + 1, &rset, nullptr, nullptr, &timeout);
        if (n < 0) {
            LOG(WARNING) << "Fatal error: select error!";
            return 0;
        } else if (n == 0) {
            continue;
        } else {
            LOG(INFO) << "Server select n = " << n;
        }

        auto *pClient = new CSocket;
        socket.Accept(pClient);
        LOG(INFO) << "Got the no." << i << " connection: " << pClient->GetRemoteIp() << ":" << ntohs(pClient->GetPeerPort());
        Singleton::getInstance().m_connIp = pClient->GetRemoteIp();
        i++;

        auto *pThread = new CClientThread;
        pThread->SetClient(pClient);
        pThread->CreateThread();
    }

    return TRUE;
}

BOOL CServerThread::ExitInstance() {
    return TRUE;
}
