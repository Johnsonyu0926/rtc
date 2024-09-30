#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "utils.h"
#include "CSocket.h"

using json = nlohmann::json;

namespace asns {

class CNetworkSetResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CNetworkSetResult, cmd, resultId, msg)

    void do_success() {
        cmd = "NetworkSet";
        resultId = 1;
        msg = "NetworkSet handle success";
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
};

class CNetworkSet {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CNetworkSet, cmd, ipAddress, gateway, netMask)

    int do_req(CSocket *pClient) {
        CUtils utils;
        CNetworkSetResult res;
        res.do_success();
        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());
        utils.network_set(gateway, ipAddress, netMask);
        return 1;
    }

private:
    std::string cmd;
    std::string ipAddress;
    std::string gateway;
    std::string netMask;
};

}  // namespace asns
