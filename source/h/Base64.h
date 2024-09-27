#ifndef BASE64_H
#define BASE64_H

#include <string>
#include <vector>
#include <memory>
#include "CString.h"
#include "CMemFile.h"

class CBase64 {
public:
    CBase64() = default;
    virtual ~CBase64() = default;

    int DecodeBody(const CString& strSrc, CMemFile& mmfile);
    int DecodeString(const char* szSrc, CString& strDecoded);
    CString Encode(const std::string& szEncoding, int nSize);
    int DecodeBody(const CString& strBody, CString& strDecoded);
    int DecodeEx(const char* szSrc, int nSize, uint8_t* pBuf);

private:
    int DecodeStr(const std::string& szDecoding, std::string& szOutput);
    int Decode(const char* p6Bits, FILE* fp);
    int GetBodyText(CString& strBodyText);
    int Decode(const char* p6Bits, char* szDecoded);
    int Decode(const char* p6Bits, char* szDecoded, int& nBytes);
    int DecodeString(char* szSrc, char* szDecoded, int& nLineBytes);
    int AsciiTo6Bits(char cAsc);

    void WriteBits(uint32_t nBits, int nNumBits, std::string& szOutput, int& i);
    uint32_t ReadBits(int nNumBits, int* pBitsRead, int& lp);

    static const std::string m_sBase64Alphabet;
    static const int m_nMask[];
};

class CQp {
public:
    CQp() = default;
    virtual ~CQp() = default;

    int Decode(const CString& strBody, CMemFile& mmfile);
    int Decode(const CString& szSrc, CString& szDecoded);

private:
    int GetHex(char szHex);
    int GetCharByHex(const std::string& szHex, char& szChar);
};

class CUtf7 {
public:
    CUtf7() = default;
    virtual ~CUtf7() = default;

    int DecodeEx(const char* szBuf, char* szDecoded);
    int Decode(const char* p, char* pBuf);
    int Encode(const char* p, char* pBuf);

private:
    int Decode(const CString& strSrc, CString& strDecoded);
    int Encode(const char* szSrc, CString& szEncoded);
    int DealWithUtf7(const char* p, char* pBuf);
    int IsPrintable(char c);
    int HandleTheEncodedString(CString& strEncoded);
    int HandleTheDecodeString(CString& strSrc);
    int Encode(const uint8_t* bToEncode, int nSize, CString& strEncoded);
    unsigned short Exchange(unsigned short dwByte);
};

#endif // BASE64_H
