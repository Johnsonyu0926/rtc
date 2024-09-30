#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "mqtt.hpp"
#include "boot.hpp"

using json = nlohmann::json;

class MqttBoot {
public:
    MqttBoot(const std::string &clientId, const std::string &host, int port)
        : clientId(clientId), host(host), port(port) {}

    bool loadConfig(const std::string &configPath) {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            bootConfig = j.at("bootConfig").get<std::vector<Boot>>();
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool saveConfig(const std::string &configPath) const {
        try {
            json j = {
                {"bootConfig", bootConfig}
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
    std::vector<Boot> bootConfig;
    std::unique_ptr<MqttClient> mqttClient;
};
* {
        "sdcardSpace":16225000, // sd卡剩余空间
        "lng":"120.2168731", // 经纬度
        "flashSpace":16225000, // 内置存储剩余空间
        "project":"0Tr1N2kbP5sKUDglAIOUxHdwp4VkLucz", // 设备项目名称，唯一
        "iotVersion":"COMMON", // 设备版本，详见设备版本号
        "version":"2.0.30", // 设备软件版本
        "volume":4, // 当前音量
        "iccId":"898604B41022C0341497", // sim卡号
        "v12":0, // 继电器当前状态
        "volt":971,
        "v24":0, // 继电器当前状态
        "storageType":1, // 当前默认存储位置
        "imei":"869298057401606",
        "topic":"TaDiao/device/report/test/869298057401606",
        "cmd":"start",
        "lat":"030.2099819",
        "v5":0 // 继电器当前状态
    }
*/
