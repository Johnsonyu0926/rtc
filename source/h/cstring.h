#ifndef CSTRING_H
#define CSTRING_H

#include <string>
#include <memory>
#include "Share.h"
#include "doorsbase.h"

constexpr int MAX_PRINTABLE_STRING_LENGTH = 5000;

class CString {
public:
    CString();
    ~CString();

    CString(const CString& rhs);
    CString(const char* szBuf);

    operator const char*() const { return m_szBuf.get(); }

    char operator[](int nIndex) const {
        if (!m_szBuf || nIndex < 0 || nIndex >= m_nTotal || m_nTotal <= 0)
            return GAP_INITIALIZER;
        return m_szBuf[nIndex];
    }

    CString& operator=(const CString& rhs);
    CString& operator=(const char* szBuf);
    CString operator+(const CString& rhs) const;
    CString operator+(const char* szBuf) const;
    CString& operator+=(const CString& rhs);
    CString& operator+=(const char* szBuf);
    CString& operator+=(char szCh);

    long GetLength() const;
    bool IsEmpty() const;
    void Empty();

    char GetAt(int nIndex) const;
    void SetAt(int nIndex, char ch);
    void Replace(char szSourceCh, char szDimCh);

    int Compare(const char* szBuf) const; // 0代表两者相等，其他代表两者不等
    int CompareNoCase(const char* szBuf) const; // 0代表两者相等，其他代表两者不等

    CString Mid(int nFirst) const;
    CString Mid(int nFirst, int nCount) const;
    CString Right(int nCount) const;
    CString Left(int nCount) const;

    void MakeUpper();
    void MakeLower();

    void TrimLeft();
    void TrimRight();

    int Find(const char* szValue, int nStart = 0) const; // >= 0代表找到，< 0代表没找到
    int Find(char szCh, int sStat = 0) const;

    void Format(const char* pFormat, ...);

private:
    bool GetValue(char* szValue) const;
    bool AddValue(const char* szValue, long nLen);
    bool AddValue(char szCh, long nLen);

private:
    std::unique_ptr<char[]> m_szBuf;
    bool m_bFirstAdd;
    long m_nTotal;
};

#endif // CSTRING_H
