// CDNSRecordSearch.h: interface for the CDNSRecordSearch class.
//
//////////////////////////////////////////////////////////////////////

//#if !defined(AFX_CDNSRECORDSEARCH_H__C65EECAA_1F54_11D3_81FD_0000210B0D41__INCLUDED_)
//#define AFX_CDNSRECORDSEARCH_H__C65EECAA_1F54_11D3_81FD_0000210B0D41__INCLUDED_

#ifndef _CDNSRECORDSEARCH_H__
#define _CDNSRECORDSEARCH_H__

#include "doorsbase.h"
#include "cstring.h"

#define ATYPE		1
#define NSTYPE		2
#define MDTYPE		3
#define MFTYPE		4
#define CNAMETYPE	5
#define SOATYPE		6
#define MBTYPE		7
#define MGTYPE      8
#define MRTYPE      9
#define NULLTYPE	10
#define WKSTYPE		11
#define PTRTYPE		12
#define HINFOTYPE	13
#define MINFOTYPE	14
#define MXTYPE		15
#define TXTTYPE		16
#define AXFRTYPE	252
#define MAILBTYPE	253
#define MAILATYPE   254
#define ALLTYPE		255

#define INCLASS		1
#define CSCLASS		2
#define CHCLASS		3
#define HSCLASS		4
#define ALLCLASS	255

typedef struct mxrecord
{
	char szRecord[16][255];
	unsigned short nNum;
	mxrecord()
	{
		nNum=0;
	}
}MX_RECORD;

struct DNSHeadTag
{
	unsigned short m_nID;
	unsigned char  m_szCode[2];
	unsigned short m_nQDCount;
	unsigned short m_nANCount;
	unsigned short m_nNSCount;
	unsigned short m_nARCount;
};
struct ResponseRecord
{
	CString m_strName;
	CString m_strAnswer;
};


class CDNSRecordSearch  
{
public:
	BOOL Run();
	CDNSRecordSearch(char *DNSServerIPAddress,char *ServerName
		,unsigned short Type,unsigned short Class);
	virtual ~CDNSRecordSearch();
	//ȡ����Ϣ���Ӽ�¼���е���Դ��¼
	ResponseRecord * GetARRecord(int index);
	//ȡ����ϢȨ�޽��е���Դ��¼
	ResponseRecord * GetNSRecord(int index);
	//ȡ����Ϣ�Ļش𲿷�ָ������Դ��¼
	ResponseRecord * GetANRecord(int index);

private:
	BOOL DealWithResponse();
	int  GetResponse();
	BOOL SendRequest();
	void AddANRecords();
	void AddNSRecords();
	void AddARRecords();
	void RemoveRecordsFromList();
	int  GetRecordData(int StartIndex, CString &Data,BOOL IsIPAddress);
	void GetNextAnswer(int PassBytes,ResponseRecord *Data);

//���¶�������
public:
	BOOL Init();
	//��Ϣ�Ļش𲿷�ָ������Դ��¼��
	unsigned short m_nANRecordCount;
	//��Ϣ��Ȩ�޽��е���Դ��¼��
	unsigned short m_nNSRecordCount;
	//��Ϣ�ĸ��Ӽ�¼���е���Դ��¼��
	unsigned short m_nARRecordCount;

	unsigned short m_nType;
	unsigned short m_nClass;
private:
	CSocket m_ssServerSocket;
	unsigned char m_szBuf[512+1];
	int m_nBufPos;
	int m_nReceiveBytes;
	CDsList m_listANRecords;
	CDsList m_listNSRecords;
	CDsList m_listARRecords;
	CString  m_strServerName ;
	CString  m_strDNSServerIPAddress;	
};

extern BOOL _GetMXAddressByName(const char *szDNSServerIP,
						 const char *szMXServerName, 
						 MX_RECORD &MXRecord);

#endif // !defined(AFX_CDNSRECORDSEARCH_H__C65EECAA_1F54_11D3_81FD_0000210B0D41__INCLUDED_)
