#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "mqtt.hpp"
#include "ledShowSet.hpp"

using json = nlohmann::json;

class MqttLedShowSet {
public:
    MqttLedShowSet(const std::string &clientId, const std::string &host, int port)
        : clientId(clientId), host(host), port(port) {}

    bool loadConfig(const std::string &configPath) {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            ledShowConfig = j.at("ledShowConfig").get<LedShowSet>();
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool saveConfig(const std::string &configPath) const {
        try {
            json j = {
                {"ledShowConfig", ledShowConfig}
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
    LedShowSet ledShowConfig;
    std::unique_ptr<MqttClient> mqttClient;
};
