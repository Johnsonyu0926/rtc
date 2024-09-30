#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class CAudioCfgBusiness {
public:
    CAudioCfgBusiness() = default;
    ~CAudioCfgBusiness() = default;

    bool load() {
        std::ifstream i(CONFIG_FILE);
        if (!i.is_open()) {
            std::cerr << "Failed to open config file: " << CONFIG_FILE << std::endl;
            return false;
        }

        try {
            i >> config_json;
        } catch (const json::exception &ex) {
            std::cerr << "JSON parse error: " << ex.what() << std::endl;
            return false;
        }

        return true;
    }

    std::string getAudioFilePath() const {
        return config_json.value("audioFilePath", "");
    }

private:
    static constexpr const char* CONFIG_FILE = "/mnt/cfg/audio.json";
    json config_json;
};
