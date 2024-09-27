#ifndef MAILAUDIT_H
#define MAILAUDIT_H

#include <string>
#include <vector>
#include <memory>
#include "Share.h"

class CMailAudit {
public:
    CMailAudit();
    virtual ~CMailAudit();

    bool Init(const std::string& configFilePath);
    bool Audit(const std::string& mailContent, std::vector<std::string>& issues);

private:
    bool LoadConfig(const std::string& configFilePath);
    bool CheckMailContent(const std::string& mailContent, std::vector<std::string>& issues);

    std::shared_ptr<CDsList> m_pAttaList;
    std::shared_ptr<CDsList> m_pContList;
    int m_nAttaCheckMode;
    int m_nContCheckMode;
};

#endif // MAILAUDIT_H
