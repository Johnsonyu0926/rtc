#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <vector>
#include <memory>
#include <map>

class CGlobal {
public:
    CGlobal();
    virtual ~CGlobal() = default;

    bool Init(const std::string& configFilePath);
    bool LoadConfig(const std::string& configFilePath);
    std::string GetConfigValue(const std::string& key) const;

private:
    std::map<std::string, std::string> m_configs;
};

#endif // GLOBAL_H
