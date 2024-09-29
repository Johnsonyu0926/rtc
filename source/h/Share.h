#ifndef SHARE_H
#define SHARE_H

#include <string>
#include <memory>

constexpr int MAX_ATTACH_COUNT = 1024;

enum class DsCharsetType {
    DsCharsetNone = 1,
    DsCharsetGB2312 = 2
};

enum class DsEncodingMethod {
    DsEncodingNone = 1,
    DsEncoding8BIT = 2,
    DsEncodingBase64 = 3,
    DsEncoding7BIT = 4,
    DsEncodingQP = 5
};

enum class DsContextType {
    DsContextNone = 1,
    DsContextTextPlain = 2,
    DsContextTextHtml = 3,
    DsContextAppOct = 4,
    DsContextAppMsWord = 5
};

enum class DsDisposition {
    DsDispNone = 1,
    DsDispAttachment = 2
};

enum class DsAuditStatus {
    DsAuditSucceeded = 1,
    DsAuditFailed = 2,
    DsAuditFailSubject = 3,
    DsAuditFailBody = 4,
    DsAuditFailAttachment = 5
};

struct BodyPart {
    DsEncodingMethod m_nEncoding;
    DsContextType m_nContentType;
    int nPart;
    int m_nBodyLen;
    std::unique_ptr<char[]> m_pBody;
    int m_nDisp;
    std::unique_ptr<char[]> m_pAttachFileName;
    BodyPart *next;

    BodyPart()
        : m_nEncoding(DsEncodingMethod::DsEncodingNone), m_nContentType(DsContextType::DsContextNone), nPart(0), m_nBodyLen(0), next(nullptr) {}
};

using Gap_BodyPart_t = BodyPart*;

#endif // SHARE_H
