#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "utils.h"

using json = nlohmann::json;

class Rs485NoiseMange {
public:
    Rs485NoiseMange() = default;
    ~Rs485NoiseMange() = default;

    std::string get_noise_topic() const { return noise_topic; }
    void set_noise_topic(const std::string &noise_topic) { this->noise_topic = noise_topic; }

    bool load_file() {
        std::ifstream i(NOISECONFIG);
        if (!i.is_open()) {
            std::cerr << "Failed to open config file: " << NOISECONFIG << std::endl;
            return false;
        }

        try {
            json js;
            i >> js;
            noise_topic = js.at("noise_topic").get<std::string>();
        } catch (const json::exception &ex) {
            std::cerr << "JSON parse error: " << ex.what() << std::endl;
            return false;
        }

        return true;
    }

    bool file_update() {
        std::ofstream o(NOISECONFIG);
        if (!o.is_open()) {
            std::cerr << "Failed to open config file: " << NOISECONFIG << std::endl;
            return false;
        }

        json js;
        js["noise_topic"] = noise_topic;

        o << js.dump(4) << std::endl;
        return true;
    }

private:
    const std::string NOISECONFIG = "/mnt/cfg/noise.json";
    std::string noise_topic = "IOT/intranet/client/noise/";
};
