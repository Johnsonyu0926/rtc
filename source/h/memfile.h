#ifndef MEMFILE_H
#define MEMFILE_H

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

#endif // MEMFILE_H
