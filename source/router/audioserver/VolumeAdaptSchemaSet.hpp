#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class VolumeAdaptSchemaSet {
public:
    VolumeAdaptSchemaSet() = default;
    ~VolumeAdaptSchemaSet() = default;

    std::string get_schema() const { return schema; }
    void set_schema(const std::string &schema) { this->schema = schema; }

    bool load_file() {
        std::ifstream i(SCHEMACONFIG);
        if (!i.is_open()) {
            std::cerr << "Failed to open config file: " << SCHEMACONFIG << std::endl;
            return false;
        }

        try {
            json js;
            i >> js;
            schema = js.at("schema").get<std::string>();
        } catch (const json::exception &ex) {
            std::cerr << "JSON parse error: " << ex.what() << std::endl;
            return false;
        }

        return true;
    }

    bool file_update() {
        std::ofstream o(SCHEMACONFIG);
        if (!o.is_open()) {
            std::cerr << "Failed to open config file: " << SCHEMACONFIG << std::endl;
            return false;
        }

        json js;
        js["schema"] = schema;

        o << js.dump(4) << std::endl;
        return true;
    }

private:
    const std::string SCHEMACONFIG = "/mnt/cfg/schema.json";
    std::string schema = "default";
};
