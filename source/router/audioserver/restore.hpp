#pragma once

#include <string>
#include "json.hpp"
#include "utils.h"

namespace asns {

class CRestoreResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CRestoreResult, cmd, resultId, msg)

    void do_fail(const std::string& str) {
        cmd = "Restore";
        resultId = 2;
        msg = str;
    }

    void do_success() {
        cmd = "Restore";
        resultId = 1;
        msg = "Restore success";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CRestore {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CRestore, cmd)

    int do_req(CSocket *pClient) {
        CUtils utils;
        CRestoreResult res;
        res.do_success();
        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());
        utils.exec("restore factory settings");
        return 1;
    }

private:
    std::string cmd;
};

} // namespace asns
