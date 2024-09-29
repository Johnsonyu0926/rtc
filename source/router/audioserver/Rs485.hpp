#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Rs485Config {
public:
    Rs485Config() = default;
    ~Rs485Config() = default;

    std::string get_rs485_topic() const { return rs485_topic; }
    void set_rs485_topic(const std::string &rs485_topic) { this->rs485_topic = rs485_topic; }

    bool load_file() {
        std::ifstream i(RS485CONFIG);
        if (!i.is_open()) {
            std::cerr << "Failed to open config file: " << RS485CONFIG << std::endl;
            return false;
        }

        try {
            json js;
            i >> js;
            rs485_topic = js.at("rs485_topic").get<std::string>();
        } catch (const json::exception &ex) {
            std::cerr << "JSON parse error: " << ex.what() << std::endl;
            return false;
        }

        return true;
    }

    bool file_update() {
        std::ofstream o(RS485CONFIG);
        if (!o.is_open()) {
            std::cerr << "Failed to open config file: " << RS485CONFIG << std::endl;
            return false;
        }

        json js;
        js["rs485_topic"] = rs485_topic;

        o << js.dump(4) << std::endl;
        return true;
    }

private:
    const std::string RS485CONFIG = "/mnt/cfg/rs485.json";
    std::string rs485_topic = "IOT/intranet/client/rs485/";
};
