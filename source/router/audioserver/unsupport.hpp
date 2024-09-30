#pragma once

#include <string>
#include "json.hpp"
#include "CSocket.h"
#include "log.h"

namespace asns {

class CUnsupport {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CUnsupport, cmd, resultId, msg)

    void do_success(const std::string& reqcmd) {
        cmd = reqcmd;
        resultId = 2;
        msg = "unsupport operation";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CUnsupportBusiness {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CUnsupportBusiness, cmd)

    void setCmd(const std::string& unsupport_cmd) {
        cmd = unsupport_cmd;
    }

    int do_req(CSocket *pClient) {
        LOG(INFO) << "unsupport cmd: " << cmd;
        CUnsupport res;
        res.do_success(cmd);

        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());

        return 1;
    }

private:
    std::string cmd;
};

} // namespace asns
