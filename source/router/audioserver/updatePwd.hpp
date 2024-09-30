#pragma once

#include <string>
#include "json.hpp"
#include "audiocfg.hpp"
#include "utils.h"

namespace asns {

class CUpdateResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CUpdateResult, cmd, resultId, msg)

    void do_success() {
        cmd = "UpdatePwd";
        resultId = 1;
        msg = "update password success";
    }

    void do_fail() {
        cmd = "UpdatePwd";
        resultId = 2;
        msg = "update password fail";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CUpdate {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CUpdate, cmd, password, oldPassword)

    int do_req(CSocket *pClient) {
        CAudioCfgBusiness cfg;
        cfg.load();

        CUpdateResult updateResult;

        if (oldPassword != cfg.business[0].serverPassword) {
            updateResult.do_fail();
        } else {
            CUtils utils;
            utils.change_password(password.c_str());
            cfg.business[0].serverPassword = password;
            cfg.saveToJson();
            updateResult.do_success();
        }

        json resp = updateResult;
        std::string str = resp.dump();
        pClient->Send(str.c_str(), str.length());

        return (updateResult.resultId == 1) ? 1 : 0;
    }

private:
    std::string cmd;
    std::string password;
    std::string oldPassword;
};

} // namespace asns
