#pragma once

#include <string>
#include "json.hpp"
#include "utils.h"

namespace asns {

class CRelaySetResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CRelaySetResult, cmd, resultId, msg)

    void do_fail(const std::string& str) {
        cmd = "RelaySet";
        resultId = 2;
        msg = str;
    }

    void do_success() {
        cmd = "RelaySet";
        resultId = 1;
        msg = "RelaySet success";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CRelaySet {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CRelaySet, cmd, relayState)

    int do_req(CSocket *pClient) {
        CUtils utils;
        CRelaySetResult res;
        res.do_success();
        if (relayState.empty()) {
            res.do_fail("relayState is empty");
        } else {
            std::string str = utils.hex_to_string(relayState);
            if (Rs485::_uart_work(str.c_str(), str.length()) != 1) {
                res.do_fail("relayState write fail");
            }
        }
        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());
        return 1;
    }

private:
    std::string cmd;
    std::string relayState;
};

} // namespace asns
