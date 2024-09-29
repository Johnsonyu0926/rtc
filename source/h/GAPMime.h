#ifndef _GAPMIME_H__
#define _GAPMIME_H__

#include "Base64.h"
#include <string>
#include <vector>

class CGAPMime {
public:
    CGAPMime();
    virtual ~CGAPMime();

    bool Init(const uint8_t *pBody);
    bool Work(long *pnSuccess);
    bool SetBodyLen(long nBodyLen);
    bool GetPartCount(long *pnCount);
    bool GetPart(int nIndex, int nType, uint8_t *pnVal);

    std::string GetSubject() const { return m_szSubject; }
    std::string GetFrom() const { return m_szFrom; }
    std::string GetTo() const { return m_szTo; }
    std::string GetCc() const { return m_szCc; }
    std::string GetDate() const { return m_szDate; }

private:
    std::string GetValueFromKey(const std::string &szLine, const std::string &szKey);
    bool GetContentType(int &nContentType, std::string &pBoundary, int &nEncodingType, std::string &pFileName);
    bool GetContentType(const std::string &szBuf, std::string &szContentType);
    int GetContentType(const std::string &szContentType, int &nContentType);
    bool GetLine(std::string &szBuf);
    int GetFieldValue(const std::string &szBuf, int nPos, std::string &szValue);
    int GetEncodingType(const std::string &szBuf, int &nEncodingType);

    int DealWithTheContentType(int nContentType, const std::string &szBoundary, int nEncodingType, const std::string &szFileName);
    int DealWithMultPart(int nContentType, const std::string &szBoundary, int nEncodingType, const std::string &szFileName);
    int DealWithSinglePart(int nContentType, const std::string &szBoundary, int nEncodingType, const std::string &szFileName);
    int GotoBoundary(const std::string &szBoundary);
    int DealWithTextPlain(int nContextType, int nEncodingType, const std::string &szBoundary);
    int DealWithOct(int nEncodingType, const std::string &szBoundary, const std::string &szFileName);
    int DealWith7BitsPlainText(int nContextType, const std::string &szBoundary);
    int DealWithBase64PlainText(const std::string &szBoundary);
    int DealWithQP(const std::string &szBoundary);
    int RecvBodyAndDecode(const std::string &szFileName, const std::string &szBoundary);

private:
    const uint8_t *m_pBody;
    int m_nOffset;
    int m_nBodyLen;
    int m_nCurrentAttachmentCount;
    std::array<std::string, 128> m_szAttachmentName;
    long m_nPartCount;
    Gap_BodyPart_t m_pBodyPart;
    Gap_BodyPart_t BodyContentCreate();
    Gap_BodyPart_t BodyContentInsert(Gap_BodyPart_t pBodyPart, Gap_BodyPart_t szBodyPart);
    void BodyContentDestroy(Gap_BodyPart_t *pBodyPart);
    void BodyContentDestroyAll(Gap_BodyPart_t *pBodyPart);
    Gap_BodyPart_t BodyContentDelete(Gap_BodyPart_t pBodyPart, int nPart);
    std::string m_szSubject;
    std::string m_szCc;
    std::string m_szTo;
    std::string m_szFrom;
    std::string m_szDate;
};

extern void ToMakeUpper(char *pStr);

#endif // _GAPMIME_H__
