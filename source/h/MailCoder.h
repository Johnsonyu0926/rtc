#ifndef MAILCODER_H
#define MAILCODER_H

#include <string>
#include <memory>
#include "Base64.h"
#include "CString.h"

class CMailCoder {
public:
    CMailCoder() = default;
    virtual ~CMailCoder() = default;

    bool Encode(const CString& strSrc, CString& strEncoded);
    bool Decode(const CString& strEncoded, CString& strDecoded);
    bool DecodeFile(const std::string& szFileName, CString& strDecoded);
    bool EncodeFile(const std::string& szFileName, CString& strEncoded);

private:
    bool EncodeBase64(const CString& strSrc, CString& strEncoded);
    bool DecodeBase64(const CString& strEncoded, CString& strDecoded);
    bool ReadFile(const std::string& szFileName, CString& strContent);
    bool WriteFile(const std::string& szFileName, const CString& strContent);
};

#endif // MAILCODER_H
