#ifndef __CSERVERSET_H__
#define __CSERVERSET_H__

#include <iostream>
#include "json.hpp"
#include "audiocfg.hpp"
#include "utils.h"

using namespace std;

namespace asns {

    class CServerSetResult {
    private:
        string cmd;
        int resultId;
        string msg;

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CServerSetResult, cmd, resultId, msg)

        void do_success() {
            cmd = "ServerSet";
            resultId = 1;
            msg = "ServerSet handle success";
        };
    };

    class CServerSet {
    private:
        string cmd;
        string serverAddress;
        string serverPort;
        string deviceCode;
        string password;

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CServerSet, cmd, serverAddress, serverPort, deviceCode, password)

        int do_req(CSocket *pClient) {
            CAudioCfgBusiness cfg;
            cfg.load();

            cfg.business[0].server = serverAddress;
            cfg.business[0].port = atoi(serverPort.c_str());
            cfg.business[0].deviceID = deviceCode;
            cfg.business[0].password = password;
            cfg.saveToJson();

            CUtils utils;
            if (utils.is_ros_platform()) {
                char buf[64] = {0};
                sprintf(buf, "cm set_val sys server %s", serverAddress.c_str());
                system(buf);
                sprintf(buf, "cm set_val sys port %s", serverPort.c_str());
                system(buf);
                sprintf(buf, "cm set_val sys password %s", password.c_str());
                system(buf);
                sprintf(buf, "cm set_val sys deviceid %s", deviceCode.c_str());
                system(buf);
            }
            LOG(INFO) << "serverAddress" << serverAddress << ",serverPort:" << serverPort << ",deviceCode:"
                                     << deviceCode
                                     << ",password:" << password;
            CServerSetResult res;
            res.do_success();
            json j = res;
            std::string s = j.dump();
            pClient->Send(s.c_str(), s.length());
            utils.cmd_system("asctrl.sh restart");
            return 1;
        }
    };

} // namespace tcpserver
#endif
