#include <stdio.h>
#include "doorsbase.h"
#define HTTP_LOG "../log/httpd.log"
#ifdef LOG_ON_HDC
#define SMTP_SUCCESS_LOG	"/mnt/hdc/configroot/usr/local/pegap/log/smtpsuccess.log"
#define SMTP_FAIL_LOG		"/mnt/hdc/configroot/usr/local/pegap/log/smtpfail.log"

#define POP3_SUCCESS_LOG	"/mnt/hdc/configroot/usr/local/pegap/log/pop3success.log"
#define POP3_FAIL_LOG		"/mnt/hdc/configroot/usr/local/pegap/log/pop3fail.log"
#define POP3_LOGIN_LOG		"/mnt/hdc/configroot/usr/local/pegap/log/pop3login.log"


#define HTTP_SUCCESS_LOG	"/mnt/hdc/configroot/usr/local/pegap/log/httpsuccess.log"
#define HTTP_FAIL_LOG		"/mnt/hdc/configroot/usr/local/pegap/log/httpfail.log"

#else

#define SMTP_SUCCESS_LOG	"../log/smtpsuccess.log"
#define SMTP_FAIL_LOG		"../log/smtpfail.log"

#define POP3_SUCCESS_LOG	"../log/pop3success.log"
#define POP3_FAIL_LOG		"../log/pop3fail.log"
#define POP3_LOGIN_LOG		"../log/pop3login.log"


#define HTTP_SUCCESS_LOG	"../log/httpsuccess.log"
#define HTTP_FAIL_LOG		"../log/httpfail.log"

#endif

class CLog
{
public:
	CLog(char* szSuccessLog)
	{
		DS_TRACE("szSuccessLog:"<<szSuccessLog);
		m_fpSuccess = fopen(szSuccessLog,"a");
	}
	~CLog()
	{
		if(m_fpSuccess)
			fclose(m_fpSuccess);
	}

protected:
	FILE* m_fpSuccess;

	CSTime m_timetool;
	void CheckValid(char* szItem);
};

typedef 
enum _tagHTTPLogType 
    {	DsHTTPSuccess	= 1,	//���ʳɹ�
	DsHTTPFailNotAuth	= 2, //ʧ��,ԭ����: δ��֤
	DsHTTPFailPostDeny	= 3, //ʧ��,ԭ����: POST��������ֹ 
	DsHTTPFailGetDeny	= 4, //ʧ��,ԭ����: GET��������ֹ 
	DsHTTPFailPostContentDeny	= 5, //ʧ��,ԭ����: POST��������������Ϣ 
	DsHTTPFailGetContentDeny	= 6, //ʧ��,ԭ����: GET��������������Ϣ 
	DsHTTPFailUrlDeny	= 7, //ʧ��,ԭ����: ��վ����ֹ 
	DsHTTPFailUnknown	= 8 //����δ֪��ʧ��ԭ��
    }	DsHTTPLogType;
class CHTTPLog:public CLog
{
	public:
		CHTTPLog():CLog(HTTP_LOG)
		{
		}
		~CHTTPLog(){}
	public:
		void Log(
			char* szUser,
			char* szFromIp,
			char* szMethod, //GET or POST 
			char* szHost,	//���ʵ�URL
			char* szPath,   // path.
			int nRespCode, //��׼��HTTPӦ����
			DsHTTPLogType nLogType) ;	
			
};

#if 0
class CLog
{
public:
	CLog()//char* szSuccessLog,char* szFailLog)
	{
		DS_TRACE("szSuccessLog:"<<szSuccessLog);
		DS_TRACE("szFailLog:"<<szFailLog);
		m_fpSuccess = fopen(szSuccessLog,"a");
		m_fpFail = fopen(szFailLog,"a");
	}
	~CLog()
	{
		if(m_fpSuccess)
			fclose(m_fpSuccess);
		if(m_fpFail)
			fclose(m_fpFail);
	}

protected:
	FILE* m_fpSuccess;
	FILE* m_fpFail;

	CSTime m_timetool;
	void CheckValid(char* szItem);
};

typedef 
enum _tagSMTPLogType 
    {	DsSMTPSuccess	= 1,	//���ͳɹ�
	DsSMTPFailNotAuth	= 2, //����ʧ��,ԭ����: δ��֤
	DsSMTPFailAuditSubject	= 3, //�ʼ��������зǷ�����
	DsSMTPFailAuditBody	= 4, //�ʼ��������зǷ��ؼ���
	DsSMTPFailAuditAttachment	= 5, //�ʼ��������зǷ��ؼ���
	DsSMTPFailUnknown	= 6 //����δ֪�ķ���ʧ��ԭ��
    }	DsSMTPLogType;
class CSMTPLog:public CLog
{
	public:
		 CSMTPLog():CLog(SMTP_SUCCESS_LOG,SMTP_FAIL_LOG)
		{
			//m_fpAuth = fopen(SMTP_AUTH_LOG,"a");
		}
		~CSMTPLog()
		{
		}

	public:

		void Log(
			char* szUser,	//szUser is different to szMailFrom. szUser is the UAC's account, szMailFrom is the sender's mail address.
			char* szFromIp,	//from where.
			char* szMailFrom,
			char* szMailTo,
			char* szCc,
			char* szSubject,
			DsSMTPLogType nCode);

	private:
		//FILE* m_fpAuth;

};

typedef 
enum _tagPOP3LogType 
    {	DsPOP3Success	= 1,	//
	DsPOP3FailNotAuth	= 2, //����ʧ��:δ��֤ 
	DsPOP3FailUnknown	= 3, //����δ֪������ʧ��ԭ��
	DsPOP3LoginSuccess		= 4, //POP3��¼�ɹ�
	DsPOP3LoginFail			= 5 //POP3��¼ʧ��
    }	DsPOP3LogType;

class CPOP3Log
{
	private:
		FILE* m_pFp;
		int m_nShouldLog;
		char m_szLog[128];
	public:
		CPOP3Log(int nShouldLog,char* szLog)
		{
			m_pFp = NULL;
			m_nShouldLog = nShouldLog;
			if(!m_nShouldLog)
				return ;
			strncpy(m_szLog,szLog,sizeof(szLog));
			m_pFp = fopen(m_szLog,"a");
		}
		~CPOP3Log(){
			if(m_pFp)
			{
				fclose(m_pFp);
				m_pFp = NULL;
			}
		}

	public:
		void Log(
			char* szUser, //������
			char* szFromIp, //receiver's ip.
			char* szMailFrom,	
			char* szMailTo,
			char* szCc,
			char* szSubject,
			DsPOP3LogType nLogType) ;
			
};

typedef 
enum _tagHTTPLogType 
    {	DsHTTPSuccess	= 1,	//���ʳɹ�
	DsHTTPFailNotAuth	= 2, //ʧ��,ԭ����: δ��֤
	DsHTTPFailPostDeny	= 3, //ʧ��,ԭ����: POST��������ֹ 
	DsHTTPFailGetDeny	= 4, //ʧ��,ԭ����: GET��������ֹ 
	DsHTTPFailPostContentDeny	= 5, //ʧ��,ԭ����: POST��������������Ϣ 
	DsHTTPFailGetContentDeny	= 6, //ʧ��,ԭ����: GET��������������Ϣ 
	DsHTTPFailUrlDeny	= 7, //ʧ��,ԭ����: ��վ����ֹ 
	DsHTTPFailUnknown	= 8 //����δ֪��ʧ��ԭ��
    }	DsHTTPLogType;
class CHTTPLog:public CLog
{
	public:
		CHTTPLog():CLog(HTTP_SUCCESS_LOG,HTTP_FAIL_LOG)
		{
		}
		~CHTTPLog(){}
	public:
		void Log(
			char* szUser,
			char* szFromIp,
			char* szMethod, //GET or POST 
			char* szHost,	//���ʵ�URL
			char* szPath,   // path.
			int nRespCode, //��׼��HTTPӦ����
			DsHTTPLogType nLogType) ;	
			
};
#endif
