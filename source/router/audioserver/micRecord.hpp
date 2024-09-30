#pragma once

#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class MicRecord {
public:
    MicRecord() = default;
    MicRecord(const std::string &id, const std::string &name, const std::string &path)
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

    static MicRecord fromJson(const json &j) {
        return MicRecord(
            j.at("id").get<std::string>(),
            j.at("name").get<std::string>(),
            j.at("path").get<std::string>());
    }

private:
    std::string id;
    std::string name;
    std::string path;
};

class MicRecordManager {
public:
    MicRecordManager(const std::string &configPath) : configPath(configPath) {}

    bool load() {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            for (const auto &item : j) {
                records.push_back(MicRecord::fromJson(item));
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
            for (const auto &record : records) {
                j.push_back(record.toJson());
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

    void addRecord(const MicRecord &record) {
        records.push_back(record);
    }

    void removeRecord(const std::string &id) {
        records.erase(std::remove_if(records.begin(), records.end(),
            [&id](const MicRecord &record) { return record.getId() == id; }), records.end());
    }

    MicRecord* findRecord(const std::string &id) {
        auto it = std::find_if(records.begin(), records.end(),
            [&id](const MicRecord &record) { return record.getId() == id; });
        return (it != records.end()) ? &(*it) : nullptr;
    }

private:
    std::string configPath;
    std::vector<MicRecord> records;
};
