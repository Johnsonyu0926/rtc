#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class FileUpload {
public:
    FileUpload() = default;
    ~FileUpload() = default;

    std::string getFileName() const { return fileName; }
    void setFileName(const std::string &newFileName) { fileName = newFileName; }

    bool uploadFile(const std::string &filePath, const std::string &destination) {
        try {
            std::ifstream source(filePath, std::ios::binary);
            if (!source.is_open()) {
                std::cerr << "Failed to open source file: " << filePath << std::endl;
                return false;
            }

            std::ofstream dest(destination, std::ios::binary);
            if (!dest.is_open()) {
                std::cerr << "Failed to open destination file: " << destination << std::endl;
                return false;
            }

            dest << source.rdbuf();

            source.close();
            dest.close();

            return true;
        } catch (const std::exception &e) {
            std::cerr << "Exception during file upload: " << e.what() << std::endl;
            return false;
        }
    }

    json toJson() const {
        return json{
            {"fileName", fileName}};
    }

    static FileUpload fromJson(const json &j) {
        return FileUpload(j.at("fileName").get<std::string>());
    }

private:
    std::string fileName;
};
