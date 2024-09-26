#ifndef AUDITCONFIGER_H
#define AUDITCONFIGER_H

#include <memory>
#include "CDsList.h"

class CAuditConfiger {
public:
    std::shared_ptr<CDsList> GetAttaList() const { return m_pAttaList; }
    std::shared_ptr<CDsList> GetContList() const { return m_pContList; }
    int GetAttaCheckMode() const { return m_nAttaCheckMode; }
    int GetContCheckMode() const { return m_nContCheckMode; }

    CAuditConfiger()
        : m_pAttaList(std::make_shared<CDsList>()), m_pContList(std::make_shared<CDsList>()) {}
    
    ~CAuditConfiger() = default;

    bool Init(const std::string& szConf);

private:
    std::shared_ptr<CDsList> m_pAttaList;
    std::shared_ptr<CDsList> m_pContList;
    int m_nAttaCheckMode;
    int m_nContCheckMode;
};

#endif // AUDITCONFIGER_H
