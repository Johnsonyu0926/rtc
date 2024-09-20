#ifndef _MEMFILE_H__
#define _MEMFILE_H__

class CMemFile
{
public:
	CMemFile();
	~CMemFile();

	void SeekToBegin();
	int Read(char* szValue, int nSize);
	void Write(const char *szBuf, int nSize);

public:

private:
	char *m_szBuf;
	int m_nTotal;
	BOOL m_bFirstAdd;

	int m_nPos;  //���ص�ǰָ��ָ�����ݵ�λ��

private:

};

#endif

