#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "mqtt.hpp"
#include "reTemp.hpp"

using json = nlohmann::json;

class MqttReTemp {
public:
    MqttReTemp(const std::string &clientId, const std::string &host, int port)
        : clientId(clientId), host(host), port(port) {}

    bool loadConfig(const std::string &configPath) {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            reTempConfig = j.at("reTempConfig").get<ReTemp>();
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool saveConfig(const std::string &configPath) const {
        try {
            json j = {
                {"reTempConfig", reTempConfig}
            };

            std::ofstream configFile(configPath);
            if (!configFile.is_open()) return false;

            configFile << j.dump(4);
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error saving config file: " << e.what() << std::endl;
            return false;
        }
    }

    void initializeClient() {
        mqttClient = std::make_unique<MqttClient>(clientId, host, port);
    }

    void setCallback(const std::function<void(const std::string &topic, const std::string &message)> &callback) {
        mqttClient->setMessageCallback(callback);
    }

    bool connect() {
        return mqttClient->connect();
    }

    void disconnect() {
        mqttClient->disconnect();
    }

    bool subscribe(const std::string &topic) {
        return mqttClient->subscribe(topic);
    }

    bool publish(const std::string &topic, const std::string &message) {
        return mqttClient->publish(topic, message);
    }

    void loopForever() {
        mqttClient->loopForever();
    }

private:
    std::string clientId;
    std::string host;
    int port;
    ReTemp reTempConfig;
    std::unique_ptr<MqttClient> mqttClient;
};
 * publishId: 172684, // Long,本次下发唯一ID
    cmd: "audioPlay", // String,本次下发功能标识；详见功能标识
    imei: "869298057401606" // String,设备唯一序列号
    operatorId: 1, // Long,操作者id
    data: "";


    {
    "result":"播放成功", // 处理结果
    "resultId":1, // 处理结果标记；0-表示未处理；1-表示处理成功；2-表示处理失败；
    "imei":"869298057401606", // 设备唯一序列号
    "topic":"TaDiao/device/report/test/869298057401606", // topic
    "cmd":"audioPlay", // 当次处理的功能标识
    "publishId":172684, // 平台下发的本次请求id
    "data": "" // 处理完成上传数据，如果有则需要上传，详情参照详细功能通信指令，已JSON格式体展现
}
 *
