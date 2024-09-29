#ifndef _MEMFILE_H__
#define _MEMFILE_H__

#include <vector>
#include <cstring>

class CMemFile {
public:
    CMemFile();
    ~CMemFile();

    void SeekToBegin();
    int Read(char *szValue, int nSize);
    void Write(const char *szBuf, int nSize);

private:
    std::vector<char> m_szBuf;
    int m_nTotal;
    bool m_bFirstAdd;
    int m_nPos;
};

#endif // _MEMFILE_H__
