#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

class CustomAudioFile {
public:
    CustomAudioFile(const std::string& id, const std::string& name, const std::string& path)
        : id(id), name(name), path(path) {}

    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getPath() const { return path; }

    void setId(const std::string& newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setPath(const std::string& newPath) { path = newPath; }

    nlohmann::json toJson() const {
        return nlohmann::json{
            {"id", id},
            {"name", name},
            {"path", path}
        };
    }

    static CustomAudioFile fromJson(const nlohmann::json& j) {
        return CustomAudioFile(
            j.at("id").get<std::string>(),
            j.at("name").get<std::string>(),
            j.at("path").get<std::string>()
        );
    }

private:
    std::string id;
    std::string name;
    std::string path;
};

class CustomAudioFileManager {
public:
    CustomAudioFileManager(const std::string& configPath) : configPath(configPath) {}

    bool load() {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            nlohmann::json j;
            configFile >> j;

            for (const auto& item : j) {
                files.emplace_back(CustomAudioFile::fromJson(item));
            }
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            return false;
        }
    }

    bool save() const {
        try {
            nlohmann::json j;
            for (const auto& file : files) {
                j.push_back(file.toJson());
            }

            std::ofstream configFile(configPath);
            if (!configFile.is_open()) return false;

            configFile << j.dump(4);
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error saving config file: " << e.what() << std::endl;
            return false;
        }
    }

    void addFile(const CustomAudioFile& file) {
        files.emplace_back(file);
    }

    void removeFile(const std::string& id) {
        files.erase(std::remove_if(files.begin(), files.end(),
            [&id](const CustomAudioFile& file) { return file.getId() == id; }), files.end());
    }

    CustomAudioFile* findFile(const std::string& id) {
        auto it = std::find_if(files.begin(), files.end(),
            [&id](const CustomAudioFile& file) { return file.getId() == id; });
        return (it != files.end()) ? &(*it) : nullptr;
    }

private:
    std::string configPath;
    std::vector<CustomAudioFile> files;
};
