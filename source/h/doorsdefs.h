#ifndef __DOORS_DEFS_H__
#define __DOORS_DEFS_H__

#include <cstdint>

typedef int64_t LONGLONG;
typedef uint32_t ULONG;
typedef int32_t INT32;
typedef int INT;
typedef uint32_t UINT;
typedef uint32_t DWORD;
typedef int BOOL;
typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef int16_t SHORT;
typedef uint16_t USHORT;
typedef float FLOAT;
typedef int32_t LONG;
typedef BOOL *LPBOOL;
typedef BYTE *LPBYTE;
typedef WORD *LPWORD;
typedef DWORD *LPDWORD;
typedef INT32 *LPINT32;
typedef INT *LPINT;
typedef void VOID;
typedef void *LPVOID;
typedef const void *LPCVOID;
typedef const char *LPCSTR;
typedef LPCSTR LPCTSTR;
typedef char *LPSTR;
typedef LPSTR LPTSTR;
typedef const uint16_t *LPCWSTR;
typedef uint16_t *LPWSTR;
typedef char TCHAR;
typedef uint16_t WCHAR;
typedef int SOCKET;

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
    virtual ~IDsObject() {}
    virtual int AddRef() = 0;
    virtual int ReleaseRef() = 0;
};

class CDsObject : public IDsObject {
public:
    CDsObject() : m_dwRef(0) {}
    virtual ~CDsObject() {}

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
    virtual void SetInterval(DWORD dwInterval) = 0;
    virtual void SetSrcToDst(LPCSTR pSrcIP, LPCSTR pDstIP) = 0;
    virtual LPCSTR GetSrcAddr() = 0;
    virtual LPCSTR GetDstAddr() = 0;
    virtual BOOL CheckSrcAndDstAddr(LPCSTR lpSrcIPAddr, LPCSTR lpDstIPAddr) = 0;
    virtual void SetLogTime(int nLogTime) = 0;
    virtual int GetLogTime() = 0;
    virtual int GetCacheCount() = 0;
    virtual void SetCacheCount(int nCount) = 0;
    virtual void SetOracle(COracleReader *oracle) = 0;
    virtual COracleReader *GetOracle() = 0;
};

extern "C" {
    void DsCreateNetworkFilter(IDsNetworkFilter **ppNetFilter, DWORD *pdwTime);
}

#endif // __DOORS_DEFS_H__
