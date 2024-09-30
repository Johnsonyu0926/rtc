#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class BroadcastPlan {
public:
    BroadcastPlan() = default;
    BroadcastPlan(int id, const std::string &name, const std::vector<std::string> &audioFiles)
        : id(id), name(name), audioFiles(audioFiles) {}

    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    std::string getName() const { return name; }
    void setName(const std::string &newName) { name = newName; }

    std::vector<std::string> getAudioFiles() const { return audioFiles; }
    void setAudioFiles(const std::vector<std::string> &newAudioFiles) { audioFiles = newAudioFiles; }

    json toJson() const {
        return json{
            {"id", id},
            {"name", name},
            {"audioFiles", audioFiles}};
    }

    static BroadcastPlan fromJson(const json &j) {
        return BroadcastPlan(
            j.at("id").get<int>(),
            j.at("name").get<std::string>(),
            j.at("audioFiles").get<std::vector<std::string>>());
    }

private:
    int id;
    std::string name;
    std::vector<std::string> audioFiles;
};

class BroadcastPlanManager {
public:
    BroadcastPlanManager(const std::string &configPath) : configPath(configPath) {}

    bool load() {
        try {
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) return false;

            json j;
            configFile >> j;

            for (const auto &item : j) {
                plans.push_back(BroadcastPlan::fromJson(item));
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
            for (const auto &plan : plans) {
                j.push_back(plan.toJson());
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

    void addPlan(const BroadcastPlan &plan) {
        plans.push_back(plan);
    }

    void removePlan(int id) {
        plans.erase(std::remove_if(plans.begin(), plans.end(),
            [&id](const BroadcastPlan &plan) { return plan.getId() == id; }), plans.end());
    }

    BroadcastPlan* findPlan(int id) {
        auto it = std::find_if(plans.begin(), plans.end(),
            [&id](const BroadcastPlan &plan) { return plan.getId() == id; });
        return (it != plans.end()) ? &(*it) : nullptr;
    }

private:
    std::string configPath;
    std::vector<BroadcastPlan> plans;
};
