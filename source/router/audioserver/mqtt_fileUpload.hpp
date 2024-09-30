#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "mqtt.hpp"
#include "gpioSet.hpp"

using json = nlohmann::json;

class MqttGpioSet {
public:
    MqttGpioSet(const std::string &clientId, const std::string &host, int port)
        : clientId(clientId), host(host), port(port) {}

    bool loadConfig(const std::string &configPath) {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            gpioConfig = j.at("gpioConfig").get<GpioSet>();
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool saveConfig(const std::string &configPath) const {
        try {
            json j = {
                {"gpioConfig", gpioConfig}
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
    GpioSet gpioConfig;
    std::unique_ptr<MqttClient> mqttClient;
};
 * {
    "downloadUrl":"http://172.16.1.20:9999/data/voice/cd5710aa-aef4-4e86-b0a0-2e430c1a2dc9.mp3", // 音频文件下载路径
    "fileName":"103.mp3", // 文件存储名称
    "audioUploadRecordId":434, // 文件上传记录唯一ID
    "storageType":1
}
curl --location --request GET 'http://218.108.199.238:9999/data/test01.mp3' --output 1.mp3
 {
    "audioUploadRecordId":434, // 文件上传记录唯一ID
}
 *
}
