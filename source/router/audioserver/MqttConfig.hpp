#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class MqttConfig {
public:
    MqttConfig() = default;
    ~MqttConfig() = default;

    std::string get_request_topic() const { return request_topic; }
    void set_request_topic(const std::string &request_topic) { this->request_topic = request_topic; }

    std::string get_publish_topic() const { return publish_topic; }
    void set_publish_topic(const std::string &publish_topic) { this->publish_topic = publish_topic; }

    bool load_file() {
        std::ifstream i(MQTTCONFIG);
        if (!i.is_open()) {
            std::cerr << "Failed to open config file: " << MQTTCONFIG << std::endl;
            return false;
        }

        try {
            json js;
            i >> js;
            request_topic = js.at("request_topic").get<std::string>();
            publish_topic = js.at("publish_topic").get<std::string>();
        } catch (const json::exception &ex) {
            std::cerr << "JSON parse error: " << ex.what() << std::endl;
            return false;
        }

        return true;
    }

    bool file_update() {
        std::ofstream o(MQTTCONFIG);
        if (!o.is_open()) {
            std::cerr << "Failed to open config file: " << MQTTCONFIG << std::endl;
            return false;
        }

        json js;
        js["request_topic"] = request_topic;
        js["publish_topic"] = publish_topic;

        o << js.dump(4) << std::endl;
        return true;
    }

private:
    const std::string MQTTCONFIG = "/mnt/cfg/mqtt.json";
    std::string request_topic = "IOT/intranet/client/request/";
    std::string publish_topic = "IOT/intranet/server/report/";
};
