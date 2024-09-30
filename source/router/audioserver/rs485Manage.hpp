#pragma once

#include <string>
#include "json.hpp"
#include "utils.h"

namespace asns {

class CRs485ManageResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CRs485ManageResult, cmd, resultId, msg)

    void do_fail(const std::string& str) {
        cmd = "Rs485Manage";
        resultId = 2;
        msg = str;
    }

    void do_success() {
        cmd = "Rs485Manage";
        resultId = 1;
        msg = "Rs485Manage success";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CRs485Manage {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CRs485Manage, cmd, rs485Config)

    int do_req(CSocket *pClient) {
        CUtils utils;
        CRs485ManageResult res;
        res.do_success();
        if (rs485Config.empty()) {
            res.do_fail("rs485Config is empty");
        } else {
            std::string str = utils.hex_to_string(rs485Config);
            if (Rs485::_uart_work(str.c_str(), str.length()) != 1) {
                res.do_fail("rs485Config write fail");
            }
        }
        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());
        return 1;
    }

private:
    std::string cmd;
    std::string rs485Config;
};

} // namespace asns
