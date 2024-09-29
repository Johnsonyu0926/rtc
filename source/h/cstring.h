#ifndef _CSTRING_H__
#define _CSTRING_H__

#include "Share.h"
#include "doorsbase.h"
#include <string>
#include <algorithm>

constexpr int MAX_PRINTABLE_STRING_LENGTH = 5000;

class CString {
public:
    CString();
    ~CString();

    CString(const CString &rhs);
    CString(const std::string &szBuf);

    operator std::string() const {
        return m_szBuf;
    }

    char operator [](int nIndex) const {
        if (!m_szBuf || nIndex < 0 || nIndex >= m_nTotal || m_nTotal <= 0)
            return GAP_INITIALIZER;
        return m_szBuf[nIndex];
    }

    CString &operator =(const CString &rhs);
    CString &operator =(const std::string &szBuf);

    const CString operator +(const CString &rhs) const;
    const CString operator +(const std::string &szBuf) const;

    CString &operator +=(const CString &rhs);
    CString &operator +=(const std::string &szBuf);
    CString &operator +=(char szCh);

    long GetLength() const;
    bool IsEmpty() const;
    void Empty();

    char GetAt(int nIndex) const;
    void SetAt(int nIndex, char ch);
    void Replace(char szSourceCh, char szDimCh);

    int Compare(const std::string &szBuf) const;
    int CompareNoCase(const std::string &szBuf) const;

    CString Mid(int nFirst) const;
    CString Mid(int nFirst, int nCount) const;
    CString Right(int nCount) const;
    CString Left(int nCount) const;

    void MakeUpper();
    void MakeLower();

    void TrimLeft();
    void TrimRight();

    int Find(const std::string &szValue, int nStart = 0) const;
    int Find(char szCh, int sStat = 0) const;

    void Format(const char *pFormat, ...);

private:
    bool GetValue(std::string &szValue) const;
    bool AddValue(const std::string &szValue, long nLen);
    bool AddValue(char szCh, long nLen);

private:
    char *m_szBuf;
    bool m_bFirstAdd;
    long m_nTotal;
};

#endif // _CSTRING_H__
