#ifndef DOORS_DEFS_H
#define DOORS_DEFS_H

#include <cstdint>

using LONGLONG = int64_t;
using ULONG = uint32_t;
using INT32 = int32_t;
using INT = int;
using UINT = uint32_t;
using DWORD = uint32_t;
using BOOL = int;
using BYTE = uint8_t;
using WORD = uint16_t;
using SHORT = int16_t;
using USHORT = uint16_t;
using FLOAT = float;
using LONG = int32_t;
using LPBOOL = BOOL*;
using LPBYTE = BYTE*;
using LPWORD = WORD*;
using LPDWORD = DWORD*;
using LPINT32 = INT32*;
using LPINT = INT*;
using VOID = void;
using LPVOID = void*;
using LPCVOID = const void*;
using LPCSTR = const char*;
using LPCTSTR = LPCSTR;
using LPSTR = char*;
using LPTSTR = LPSTR;
using LPCWSTR = const uint16_t*;
using LPWSTR = uint16_t*;
using TCHAR = char;
using WCHAR = uint16_t;
using SOCKET = int;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INVALID_SOCKET
#define INVALID_SOCKET (SOCKET)(-1)
#endif

class COracleReader;

class IDsObject {
public:
    IDsObject() = default;
    virtual ~IDsObject() = default;
    virtual int AddRef() = 0;
    virtual int ReleaseRef() = 0;
};

class CDsObject : public IDsObject {
public:
    CDsObject() : m_dwRef(0) {}
    virtual ~CDsObject() = default;
    int AddRef() override {
        return ++m_dwRef;
    }
    int ReleaseRef() override {
        if (--m_dwRef == 0) {
            delete this;
            return 0;
        }
        return m_dwRef;
    }

protected:
    DWORD m_dwRef;
};

class IDsNetworkFilter : public CDsObject {
public:
    virtual void SetTimeRange(DWORD dwFromTime, DWORD dwToTime) = 0;
    virtual void IncludePort(int port) = 0;
    virtual void ExcludePort(int port) = 0;
    virtual void IncludeAddress(LPCSTR ip_address) = 0;
    virtual void IncludeAddress(LPCSTR ip_address1, LPCSTR ip_address2) = 0;
    virtual void ExcludeAddress(LPCSTR ip_address) = 0;
    virtual void ExcludeAddress(LPCSTR ip_address1, LPCSTR ip_address2) = 0;
    virtual BOOL CheckTime(DWORD dwTime) = 0;
    virtual BOOL CheckPort(int port) = 0;
    virtual BOOL CheckAddress(LPCSTR ip_address1, LPCSTR ip_address2) = 0;
    virtual BOOL CheckTimeAfter(DWORD dwTime) = 0;
    virtual BOOL CheckTimeBefore(DWORD dwTime) = 0;
    virtual DWORD GetFromTime() = 0;
    virtual BOOL IsRealTime() = 0;
    virtual DWORD GetToTime() = 0;
    virtual void SetFilePath(LPCSTR file_path) = 0;
    virtual LPCSTR GetFilePath() = 0;
    virtual LPCSTR GetAddress() = 0;
    virtual WORD GetPort() = 0;
    virtual DWORD GetRealToTime() = 0;
    virtual void SetRealToTime(DWORD dwTime) = 0;
    virtual void SetInterval(DWORD interval) = 0;
    virtual void SetSrcToDst(LPCSTR pSrcIP, LPCSTR pDstIP) = 0;
    virtual LPCSTR GetSrcAddr() = 0;
    virtual LPCSTR GetDstAddr() = 0;
};

extern "C" {
    void DsCreateNetworkFilter(IDsNetworkFilter** ppNetFilter, DWORD* pdwTime);
}

#endif // DOORS_DEFS_H
