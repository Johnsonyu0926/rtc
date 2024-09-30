#pragma once

#include <string>
#include "json.hpp"
#include "utils.h"

namespace asns {

class CServerSetResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CServerSetResult, cmd, resultId, msg)

    void do_fail(const std::string& str) {
        cmd = "ServerSet";
        resultId = 2;
        msg = str;
    }

    void do_success() {
        cmd = "ServerSet";
        resultId = 1;
        msg = "ServerSet success";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CServerSet {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CServerSet, cmd, serverConfig)

    int do_req(CSocket *pClient) {
        CUtils utils;
        CServerSetResult res;
        res.do_success();
        if (serverConfig.empty()) {
            res.do_fail("serverConfig is empty");
        } else {
            std::string str = utils.hex_to_string(serverConfig);
            if (Rs485::_uart_work(str.c_str(), str.length()) != 1) {
                res.do_fail("serverConfig write fail");
            }
        }
        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());
        return 1;
    }

private:
    std::string cmd;
    std::string serverConfig;
};

} // namespace asns
