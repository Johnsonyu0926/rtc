#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class TtsConfig {
public:
    TtsConfig() = default;
    TtsConfig(const std::string &apiKey, const std::string &url, const std::string &voice)
        : apiKey(apiKey), url(url), voice(voice) {}

    std::string getApiKey() const { return apiKey; }
    void setApiKey(const std::string &newApiKey) { apiKey = newApiKey; }

    std::string getUrl() const { return url; }
    void setUrl(const std::string &newUrl) { url = newUrl; }

    std::string getVoice() const { return voice; }
    void setVoice(const std::string &newVoice) { voice = newVoice; }

    json toJson() const {
        return json{
            {"apiKey", apiKey},
            {"url", url},
            {"voice", voice}};
    }

    static TtsConfig fromJson(const json &j) {
        return TtsConfig(
            j.at("apiKey").get<std::string>(),
            j.at("url").get<std::string>(),
            j.at("voice").get<std::string>());
    }

private:
    std::string apiKey;
    std::string url;
    std::string voice;
};

class TtsConfigManager {
public:
    TtsConfigManager(const std::string &configPath) : configPath(configPath) {}

    bool load() {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            config = TtsConfig::fromJson(j);
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool save() const {
        try {
            json j = config.toJson();

            std::ofstream configFile(configPath);
            if (!configFile.is_open()) return false;

            configFile << j.dump(4);
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error saving config file: " << e.what() << std::endl;
            return false;
        }
    }

    TtsConfig getConfig() const { return config; }
    void setConfig(const TtsConfig &newConfig) { config = newConfig; }

private:
    std::string configPath;
    TtsConfig config;
};
