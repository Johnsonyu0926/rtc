#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class AudioFileInfo {
public:
    AudioFileInfo() = default;
    AudioFileInfo(const std::string &id, const std::string &name, const std::string &path)
        : id(id), name(name), path(path) {}

    std::string getId() const { return id; }
    void setId(const std::string &newId) { id = newId; }

    std::string getName() const { return name; }
    void setName(const std::string &newName) { name = newName; }

    std::string getPath() const { return path; }
    void setPath(const std::string &newPath) { path = newPath; }

    json toJson() const {
        return json{
            {"id", id},
            {"name", name},
            {"path", path}};
    }

    static AudioFileInfo fromJson(const json &j) {
        return AudioFileInfo(
            j.at("id").get<std::string>(),
            j.at("name").get<std::string>(),
            j.at("path").get<std::string>());
    }

private:
    std::string id;
    std::string name;
    std::string path;
};

class AudioFileInfoManager {
public:
    AudioFileInfoManager(const std::string &configPath) : configPath(configPath) {}

    bool load() {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            for (const auto &item : j) {
                files.push_back(AudioFileInfo::fromJson(item));
            }
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool save() const {
        try {
            json j;
            for (const auto &file : files) {
                j.push_back(file.toJson());
            }

            std::ofstream configFile(configPath);
            if (!configFile.is_open()) return false;

            configFile << j.dump(4);
            return true;
        } catch (const std::exception &e) {
            std::cerr << "Error saving config file: " << e.what() << std::endl;
            return false;
        }
    }

    void addFile(const AudioFileInfo &file) {
        files.push_back(file);
    }

    void removeFile(const std::string &id) {
        files.erase(std::remove_if(files.begin(), files.end(),
            [&id](const AudioFileInfo &file) { return file.getId() == id; }), files.end());
    }

    AudioFileInfo* findFile(const std::string &id) {
        auto it = std::find_if(files.begin(), files.end(),
            [&id](const AudioFileInfo &file) { return file.getId() == id; });
        return (it != files.end()) ? &(*it) : nullptr;
    }

private:
    std::string configPath;
    std::vector<AudioFileInfo> files;
};
