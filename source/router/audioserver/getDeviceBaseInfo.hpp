#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DeviceBaseInfo {
public:
    DeviceBaseInfo() = default;
    DeviceBaseInfo(const std::string &deviceId, const std::string &deviceType, const std::string &firmwareVersion)
        : deviceId(deviceId), deviceType(deviceType), firmwareVersion(firmwareVersion) {}

    std::string getDeviceId() const { return deviceId; }
    void setDeviceId(const std::string &newDeviceId) { deviceId = newDeviceId; }

    std::string getDeviceType() const { return deviceType; }
    void setDeviceType(const std::string &newDeviceType) { deviceType = newDeviceType; }

    std::string getFirmwareVersion() const { return firmwareVersion; }
    void setFirmwareVersion(const std::string &newFirmwareVersion) { firmwareVersion = newFirmwareVersion; }

    json toJson() const {
        return json{
            {"deviceId", deviceId},
            {"deviceType", deviceType},
            {"firmwareVersion", firmwareVersion}};
    }

    static DeviceBaseInfo fromJson(const json &j) {
        return DeviceBaseInfo(
            j.at("deviceId").get<std::string>(),
            j.at("deviceType").get<std::string>(),
            j.at("firmwareVersion").get<std::string>());
    }

private:
    std::string deviceId;
    std::string deviceType;
    std::string firmwareVersion;
};
