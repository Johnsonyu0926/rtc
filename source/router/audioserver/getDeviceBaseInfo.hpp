#pragma once

#include "json.hpp"
#include "audiocfg.hpp"
#include "utils.h"
#include "volume.hpp"
#include "Relay.hpp"

extern asns::CVolumeSet g_volumeSet;
namespace asns {

    class CDeviceBaseData {
    public:
        string codeVersion;
        string coreVersion;
        int relayMode;
        string ip;
        int storageType;
        int port;
        int playStatus;
        int volume;
        int relayStatus;
        string hardwareReleaseTime;
        int spiFreeSpace;
        int flashFreeSpace;
        string hardwareVersion;
        string password;
        int temperature;
        string netmask;
        string address;
        string gateway;
        string userName;
        string imei;
        string functionVersion;
        string deviceCode;
        string serverAddress;
        string serverPort;

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CDeviceBaseData, codeVersion, coreVersion, relayMode, ip, storageType, port,
                                       playStatus, volume, relayStatus, hardwareReleaseTime, spiFreeSpace,
                                       flashFreeSpace, hardwareVersion, password, temperature, netmask, address,
                                       gateway, userName, imei, functionVersion, deviceCode, serverAddress, serverPort)

    };

    class CGetDeviceBaseInfoResult {

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CGetDeviceBaseInfoResult, cmd, resultId, data, msg)

        void do_success() {
            CAudioCfgBusiness cfg;
            cfg.load();
            CUtils util;
            cmd = "GetDeviceBaseInfo";
            resultId = 1;
            msg = "Obtaining information successfully";

            data.codeVersion = cfg.business[0].codeVersion;
            data.coreVersion = util.get_core_version();
            data.relayMode = Relay::getInstance().getGpioModel();;
            data.ip = util.get_addr();
            data.storageType = 1;
            data.port = 34508;
            data.playStatus = PlayStatus::getInstance().getPlayState();
            g_volumeSet.load();
            data.volume = g_volumeSet.getVolume();
            data.relayStatus = Relay::getInstance().getGpioStatus();
            data.hardwareReleaseTime = util.get_hardware_release_time();
            data.spiFreeSpace = 9752500;
            data.flashFreeSpace = util.get_available_Disk("/mnt");
            data.hardwareVersion = util.get_res_by_cmd("uname -r");
            data.password = cfg.business[0].serverPassword;
            data.temperature = 12;
            data.netmask = util.get_netmask();
            data.address = "01";
            data.gateway = util.get_gateway();
            data.userName = "admin";
            data.imei = cfg.business[0].deviceID;
            data.functionVersion = "COMMON";
            data.deviceCode = cfg.business[0].deviceID;
            data.serverAddress = cfg.business[0].server;
            data.serverPort = to_string(cfg.business[0].port);
        };
    private:
        std::string cmd;
        int resultId;
        CDeviceBaseData data;
        std::string msg;
    };

    class CGetDeviceBaseInfo {
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CGetDeviceBaseInfo, cmd)

        int do_req(CSocket *pClient) {
            CGetDeviceBaseInfoResult deviceBaseInfoResult;
            deviceBaseInfoResult.do_success();
            json js = deviceBaseInfoResult;
            std::string s = js.dump();
            LOG(INFO) << "data:" << s;
            return pClient->Send(s.c_str(), s.length());
        }

    private:
        std::string cmd;
    };
}