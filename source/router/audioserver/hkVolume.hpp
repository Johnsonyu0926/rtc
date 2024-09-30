#pragma once

#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class HkVolume {
public:
    HkVolume() = default;
    ~HkVolume() = default;

    std::string getId() const { return id; }
    void setId(const std::string &newId) { id = newId; }

    int getVolume() const { return volume; }
    void setVolume(int newVolume) { volume = newVolume; }

    json toJson() const {
        return json{
            {"id", id},
            {"volume", volume}};
    }

    static HkVolume fromJson(const json &j) {
        return HkVolume(
            j.at("id").get<std::string>(),
            j.at("volume").get<int>());
    }

private:
    std::string id;
    int volume;
};

class HkVolumeManager {
public:
    HkVolumeManager(const std::string &configPath) : configPath(configPath) {}

    bool load() {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            volume = HkVolume::fromJson(j);
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool save() const {
        try {
            json j = volume.toJson();

            std::ofstream configFile(configPath);
            if (!configFile.is_open()) return false;

            configFile << j.dump(4);
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error saving config file: " << e.what() << std::endl;
            return false;
        }
    }

    HkVolume getVolume() const { return volume; }
    void setVolume(const HkVolume &newVolume) { volume = newVolume; }

private:
    std::string configPath;
    HkVolume volume;
};
