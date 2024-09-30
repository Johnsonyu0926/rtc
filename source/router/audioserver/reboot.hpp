#pragma once

#include <string>
#include "json.hpp"
#include "utils.h"

namespace asns {

class CRebootResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CRebootResult, cmd, resultId, msg)

    void do_fail(const std::string& str) {
        cmd = "Reboot";
        resultId = 2;
        msg = str;
    }

    void do_success() {
        cmd = "Reboot";
        resultId = 1;
        msg = "Reboot success";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CReboot {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CReboot, cmd)

    int do_req(CSocket *pClient) {
        CUtils utils;
        CRebootResult res;
        res.do_success();
        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());
        utils.exec("reboot");
        return 1;
    }

private:
    std::string cmd;
};

} // namespace asns
