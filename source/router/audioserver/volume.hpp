#pragma once

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Volume {
public:
    Volume() = default;
    Volume(const std::string &id, int level)
        : id(id), level(level) {}

    std::string getId() const { return id; }
    void setId(const std::string &newId) { id = newId; }

    int getLevel() const { return level; }
    void setLevel(int newLevel) { level = newLevel; }

    json toJson() const {
        return json{
            {"id", id},
            {"level", level}};
    }

    static Volume fromJson(const json &j) {
        return Volume(
            j.at("id").get<std::string>(),
            j.at("level").get<int>());
    }

private:
    std::string id;
    int level;
};

class VolumeManager {
public:
    VolumeManager(const std::string &configPath) : configPath(configPath) {}

    bool load() {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            volume = Volume::fromJson(j);
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

    Volume getVolume() const { return volume; }
    void setVolume(const Volume &newVolume) { volume = newVolume; }

private:
    std::string configPath;
    Volume volume;
};
