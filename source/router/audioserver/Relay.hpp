#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class RelayConfig {
public:
    RelayConfig() = default;
    ~RelayConfig() = default;

    std::string get_relay_topic() const { return relay_topic; }
    void set_relay_topic(const std::string &relay_topic) { this->relay_topic = relay_topic; }

    bool load_file() {
        std::ifstream i(RELAYCONFIG);
        if (!i.is_open()) {
            std::cerr << "Failed to open config file: " << RELAYCONFIG << std::endl;
            return false;
        }

        try {
            json js;
            i >> js;
            relay_topic = js.at("relay_topic").get<std::string>();
        } catch (const json::exception &ex) {
            std::cerr << "JSON parse error: " << ex.what() << std::endl;
            return false;
        }

        return true;
    }

    bool file_update() {
        std::ofstream o(RELAYCONFIG);
        if (!o.is_open()) {
            std::cerr << "Failed to open config file: " << RELAYCONFIG << std::endl;
            return false;
        }

        json js;
        js["relay_topic"] = relay_topic;

        o << js.dump(4) << std::endl;
        return true;
    }

private:
    const std::string RELAYCONFIG = "/mnt/cfg/relay.json";
    std::string relay_topic = "IOT/intranet/client/relay/";
};
