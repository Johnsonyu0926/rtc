#ifndef NETFILTER_H
#define NETFILTER_H

#include <string>
#include <vector>
#include <memory>

class CNetFilter {
public:
    CNetFilter();
    virtual ~CNetFilter();

    bool Init(const std::string& configFilePath);
    bool Filter(const std::string& packet, std::vector<std::string>& actions);

private:
    bool LoadConfig(const std::string& configFilePath);

    std::shared_ptr<CDsList> m_pRuleList;
    int m_nFilterMode;
};

#endif // NETFILTER_H
