#ifndef _GAPAUDIT_H__
#define _GAPAUDIT_H__

#define RULECOUNT 100

#include "GAPMime.h"
#include <string>

class CGAPAudit {
public:
    CGAPAudit();
    ~CGAPAudit();

    bool AddContent(uint8_t *pBuf, int nLen);
    bool InitRule();
    bool Audit(DsAuditStatus *pAudited);

    std::string GetSubject() const { return m_szSubject; }
    std::string GetFrom() const { return m_szFrom; }
    std::string GetTo() const { return m_szTo; }
    std::string GetCc() const { return m_szCc; }
    std::string GetDate() const { return m_szDate; }

    bool SetContent(const std::string &szBuf, int nLen);

private:
    bool Decode(DsEncodingMethod EncodingMethod, const CString &strBody, CString &strDecoded);
    bool AuditTextPlain(const uint8_t *pBody);
    bool AuditHtml(const uint8_t *pBody);
    bool AuditAttachment(const std::string &szFileName, int nFileType);
    int CheckFileName(const CString &strFileName);
    int AuditSubject();

private:
    std::string m_szDate;
    int m_bReleaseMem;

    int m_nDenyAll;
    std::string m_szSubject;
    std::string m_szFrom;
    std::string m_szTo;
    std::string m_szCc;

    std::unique_ptr<char[]> m_szContent;
    long m_nContentLen;
    bool m_bFirstAdd;

    std::array<std::unique_ptr<char[]>, RULECOUNT> m_pRuleContent;
    int m_nRuleContentCount;
    std::array<std::unique_ptr<char[]>, RULECOUNT> m_pRuleAttachMent;
    int m_nRuleAttachMentCount;
    std::array<std::unique_ptr<char[]>, RULECOUNT> m_pRuleScript;
    int m_nRuleScriptCount;

    CGAPMime m_Mime;
};

#endif // _GAPAUDIT_H__
