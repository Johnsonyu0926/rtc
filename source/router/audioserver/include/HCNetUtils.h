//��SDK��������
#ifndef _HC_NET_UTILS_H_
#define _HC_NET_UTILS_H_

#include "NPQ/NPQos.h"
/*******************ƽ̨��ص��������Ͷ��� begin**********************/	

#ifndef _WINDOWS_
    #if (defined(_WIN32) || defined(_WIN64))
        #include <winsock2.h>    
        #include <windows.h>
    #endif
#endif

//NETSDK_UTILS_STATIC ���������˶��壬��ʾʹ��HCNetUtils��̬�⣨Ŀǰֻ��HCNetSDKʹ��HCNetUtils��̬�⣩

#if (defined(_WIN32)) //windows
    #ifndef NETSDK_UTILS_STATIC
        #ifndef NET_UTILS_API
            #define NET_UTILS_API extern "C" __declspec(dllimport)
        #endif //NET_UTILS_API
    #define NET_UTILS_CLASS __declspec(dllimport)
#else
    #ifndef NET_UTILS_API
        #define NET_UTILS_API extern "C"
    #endif //NET_UTILS_API
    #define NET_UTILS_CLASS
#endif


    #define BOOL int
    typedef  unsigned __int64 UINT64;
#elif defined(__linux__) || defined(__APPLE__) //linux
typedef     unsigned int    DWORD;
typedef     unsigned short  WORD;
typedef     unsigned short  USHORT;
typedef     short           SHORT;
typedef     int             LONG;
typedef  	unsigned char	BYTE;
#define     BOOL int
typedef     unsigned int   	UINT;
typedef 	void* 			LPVOID;
typedef 	void* 			HANDLE;
typedef     unsigned int*  LPDWORD; 
typedef  unsigned long long UINT64;

#ifndef    TRUE
#define    TRUE	1
#endif
#ifndef    FALSE
#define	   FALSE 0
#endif
#ifndef    NULL
#define	   NULL 0
#endif

#define __stdcall 
#define CALLBACK  
#ifdef NETSDK_UTILS_STATIC
    #define NET_UTILS_API
#else
    #define NET_UTILS_API extern "C"
#endif
    #define NET_UTILS_CLASS
#endif

/*******************ƽ̨��ص��������Ͷ��� end**********************/	



/*******************ȫ�ִ����� begin**********************/
#ifndef _HC_NET_SDK_H_
//��Щ�������Ѿ���SDK�ж�����ˣ�����������SDK�ĺ궨�壬�˴����ٶ���

#define NET_DVR_NOERROR 					0	//û�д���

#define NET_DVR_NOINIT 						3	//û�г�ʼ��

#define NET_DVR_VERSIONNOMATCH				6	//�汾��ƥ��
#define NET_DVR_NETWORK_FAIL_CONNECT		7	//���ӷ�����ʧ��
#define NET_DVR_NETWORK_SEND_ERROR			8	//�����������ʧ��
#define NET_DVR_NETWORK_RECV_ERROR			9	//�ӷ�������������ʧ��
#define NET_DVR_NETWORK_RECV_TIMEOUT		10	//�ӷ������������ݳ�ʱ
#define NET_DVR_NETWORK_ERRORDATA			11	//���͵���������
#define NET_DVR_ORDER_ERROR					12	//���ô������

#define NET_DVR_PARAMETER_ERROR 			17  //��������

#define NET_DVR_FILEOPENFAIL                35  //���ļ�����

#define NET_DVR_DIR_ERROR					40	//·������
#define NET_DVR_ALLOC_RESOURCE_ERROR		41  //��Դ�������

#define NET_DVR_NOENOUGH_BUF				43	//������̫С
#define NET_DVR_CREATESOCKET_ERROR		 	44	//����SOCKET����
#define NET_DVR_SETSOCKET_ERROR				45	//����SOCKET����
#define NET_DVR_MAX_NUM                     46  //�����ﵽ���

#define NET_DVR_GETLOCALIPANDMACFAIL		53  //��ñ��ص�IP��ַ�������ַʧ��

#define NET_DVR_CREATEDIR_ERROR				71	//������־�ļ�Ŀ¼ʧ��
#define NET_DVR_BINDSOCKET_ERROR			72	//���׽���ʧ��
#define NET_DVR_SOCKETCLOSE_ERROR			73	//socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�
#define NET_DVR_USERID_ISUSING			    74	//ע��ʱ�û�ID���ڽ���ĳ����
#define NET_DVR_SOCKETLISTEN_ERROR			75	//����ʧ��

#define NET_DVR_FUNCTION_NOT_SUPPORT_OS     98  //�˹��ܲ�֧�ָò���ϵͳ
#define NET_DVR_USE_LOG_SWITCH_FILE			103  //����ʹ����־�����ļ�


#define NET_DVR_LOAD_SSL_LIB_ERROR          148  //����SSL��ʧ�ܣ������ǰ汾��ƥ�䣬Ҳ�����ǲ����ڣ�

#define NET_ERR_NPQ_BASE_INDEX    8000    //NPQ�������
#define NET_ERR_NPQ_PARAM       (NET_ERR_NPQ_BASE_INDEX + 1)        //NPQ���������
#define NET_ERR_NPQ_SYSTEM      (NET_ERR_NPQ_BASE_INDEX + 2)        //NPQ�����ϵͳ���ô���(������Դ����ʧ�ܻ��ڲ�����ȣ�
#define NET_ERR_NPQ_GENRAL      (NET_ERR_NPQ_BASE_INDEX + 3)        //NPQ���ڲ�ͨ�ô���
#define NET_ERR_NPQ_PRECONDITION    (NET_ERR_NPQ_BASE_INDEX + 4)        //NPQ�����˳�����
#define NET_ERR_NPQ_NOTSUPPORT        (NET_ERR_NPQ_BASE_INDEX + 5)        //NPQ�⹦�ܲ�֧��

#define NET_ERR_NPQ_NOTCALLBACK    (NET_ERR_NPQ_BASE_INDEX + 100)   //����û�лص�����
#define NET_ERR_NPQ_LOADLIB (NET_ERR_NPQ_BASE_INDEX + 101)   //NPQ�����ʧ��


#define NET_ERR_SIP_BASE_INDEX  8200    //SIP������
#define NET_ERR_SIP_CREATE_OUTGOINGHADLE_FAIL    (NET_ERR_SIP_BASE_INDEX + 1)    //�����������ʧ��
#define NET_ERR_SIP_NOT_RINGING (NET_ERR_SIP_BASE_INDEX + 2)    //δ��������峬ʱ
#define NET_ERR_SIP_MAX_CONNECTION_NUM  (NET_ERR_SIP_BASE_INDEX + 3)    //�����ն˴ﵽ������������
#define NET_ERR_SIP_LOADLIB (NET_ERR_SIP_BASE_INDEX + 4)    //����sip��ʧ��

#endif // !_HC_NET_SDK_H_
/*******************ȫ�ִ����� end**********************/

//״ֵ̬
#define HTTP_CERTIFICATE_ERROR          0x3    //֤�����

#define MACADDR_LEN                  6       //mac��ַ����
#define DEV_TYPE_NAME_LEN            24      //�豸�������Ƴ���
#define SERIALNO_LEN                 48      //���кų���
#define  SDK_MAX_IP_LEN              48
#define DEVICE_IDENTY_CODE           128

#define UPGRADE_SUCC    1   //�����ɹ�
#define UPGRADE_ING     2   //��������
#define UPGRADE_TIMEOUT 3   //����ʧ�ܣ����糬ʱ
#define UPGRADE_FAILED  4   //����ʧ�ܣ�ԭ��δ֪

#define MAX_DOMAIN_NAME                64        /* ����������� */

typedef	struct	tagDEVICE_SEEKHELP_INFO
{
    BYTE	 byDeviceMAC[MACADDR_LEN];	//mac��ַ
    char	 szDevDesc[DEV_TYPE_NAME_LEN];       //�豸����
    char	 szSerialNO[SERIALNO_LEN];	//�豸���к�
    char	 szDeviceAddress[SDK_MAX_IP_LEN];	//�豸��ַ
    WORD	 wIDCodeLen;	//ʶ���볤�ȣ��ϲ�Ӧ�ÿ�����ʱ����һ���жϣ�������ֶδ���128���뱨����ʾ�û����¹���/�ͻ��˰汾
    char	 szIDCode[DEVICE_IDENTY_CODE];
	BYTE     bySupportMultiCast;	//0-��֧�ֶಥ,1-֧�ֶಥ
    BYTE	 byRes[123];
}DEVICE_SEEKHELP_INFO,*LPDEVICE_SEEKHELP_INFO;

typedef BOOL (CALLBACK * UBOOT_DEVICEONLINE_CB) (LONG iHandle, LPDEVICE_SEEKHELP_INFO pSeekHelpInfo, void *pUser);

typedef struct tagNET_UTILS_UBOOT_START
{
    UBOOT_DEVICEONLINE_CB   fnCB;
    char            szLocalAddr[SDK_MAX_IP_LEN];
    void *          pUserData;   //�û�����
    BYTE            byRes[32]; 
}NET_UTILS_UBOOT_START,*LPNET_UTILS_UBOOT_START;

typedef struct tagDEVICE_TRYFIX_INFO 
{
    BYTE	byDeviceMAC[MACADDR_LEN];	            //mac��ַ
    char    szDeviceAddr[SDK_MAX_IP_LEN];  //�豸��ַ
    char    szTFTPAddr[SDK_MAX_IP_LEN];    //TFTP��ַ
    WORD    wTFTPPort;                     //TFTP�˿�
	BYTE	bySupportMultiCast;	//0-��֧�ֶಥ��1-֧�ֶಥ
    BYTE    byRes[127];
}DEVICE_TRYFIX_INFO,*LPDEVICE_TRYFIX_INFO;

typedef struct tagNET_DVR_CHECK_PAKAGE_COND
{
    DWORD  	dwSize;
    BYTE	byIDCode[128];
    WORD    wPort;
    BYTE    bySvrAddr[MAX_DOMAIN_NAME];
    BYTE	byRes[126];
}NET_DVR_CHECK_PAKAGE_COND,*LPNET_DVR_CHECK_PAKAGE_COND;

typedef struct tagNET_DVR_CHECK_PAKAGE_INFO
{
    DWORD	dwSize;
    BYTE	byIDCode[128];
    BYTE	byVersion[32];
    BYTE	byPakageUrl[512];
    BYTE	byRes[348];
}NET_DVR_CHECK_PAKAGE_INFO,*LPNET_DVR_CHECK_PAKAGE_INFO;

typedef void (CALLBACK *WriteLogStrFunc)(LONG nLevel, char const *pFile, LONG iLine, char const *pBuffer);

typedef struct tagNET_DVR_LOG_INFO
{
    BOOL      bExternalInterface;//�Ƿ�ʹ���ⲿ�ӿ�
    LONG      nLogLevel;
    char      *strLogDir;
    BOOL      bAutoDel;
    WriteLogStrFunc fnWriteLogStr;
}NET_DVR_LOG_INFO, *LPNET_DVR_LOG_INFO;

NET_UTILS_API BOOL    CALLBACK   NET_UTILS_Init();
NET_UTILS_API BOOL    CALLBACK   NET_UTILS_Fini();
NET_UTILS_API LONG    CALLBACK   NET_UTILS_GetLastError();
NET_UTILS_API BOOL    CALLBACK   NET_UTILS_SetLogToFile(LONG nLogLevel, char *strLogDir, BOOL bAutoDel);
NET_UTILS_API BOOL    CALLBACK   NET_UTILS_SetLogToFileEx(LPNET_DVR_LOG_INFO pParam);
NET_UTILS_API DWORD   CALLBACK   NET_UTILS_GetSDKBuildVersion();

#define UTILS_DLL_SSL_PATH  9

NET_UTILS_API BOOL    CALLBACK   NET_UTILS_SetDllLoadPath(DWORD dwDllType, const char *sDllName);

NET_UTILS_API LONG    CALLBACK   NET_UTILS_StartTFTPServer(char *pSvrAddr, WORD wSvrPort, char *pFilePath);
NET_UTILS_API BOOL    CALLBACK   NET_UTILS_StopTFTPServer(LONG   iHandle);
NET_UTILS_API BOOL    CALLBACK   NET_UTILS_GetSendFileProgress(LONG   iHandle, LONG *iProgress, LONG *iStatus);

NET_UTILS_API LONG    CALLBACK    NET_UTILS_StartUBootServer(NET_UTILS_UBOOT_START* pUBootStart);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_StopUBootServer(LONG iHandle);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_ReplyUBoot(LONG iHandle, DEVICE_TRYFIX_INFO *pFixInfo);

NET_UTILS_API BOOL    CALLBACK    NET_UTILS_GetPakageInfo(LPNET_DVR_CHECK_PAKAGE_COND lpCond, LPNET_DVR_CHECK_PAKAGE_INFO lpInfo);



//SMTP
#define HC_SMTP_MAX_ADDRESS_LEN     256
#define HC_SMTP_MAX_SUBJECT_LEN     256
#define HC_SMTP_MAX_ACCOUNT_LEN     256
#define HC_SMTP_MAX_PASSWORD_LEN    128
#define HC_SMTP_MAX_NAME_LEN        128

enum SMTP_SECURITY_TYPE
{
    DO_NOT_SET,     //������
    USE_TLS_OPT,    //���������֧��TLS��ʹ��STARTLS���ܴ���
    USE_SSL         //ʹ��SSL����
};

enum SMTP_CHARSET_TYPE
{
    US_ASCII,   //����ASCII��
    UTF_8,      //UTF-8
    GB_2312     //Windows gb2312���ı���
};

typedef	struct tagNET_UTILS_SMTP_PARAM
{
    SMTP_SECURITY_TYPE  enumSecurity;   //��������
    SMTP_CHARSET_TYPE   enumCharset;    //�ַ������ʽ
    char			    szSmtpServer[HC_SMTP_MAX_ADDRESS_LEN];  //SMTP�ʼ���������ַ��������������ip��ַ
    WORD		        wPort;  //SMTP�ʼ��������˿�
    char			    szSender[HC_SMTP_MAX_ADDRESS_LEN];  //�����������ַ
    char			    szSubject[HC_SMTP_MAX_SUBJECT_LEN]; //�ʼ�����
    char			    szAccount[HC_SMTP_MAX_ACCOUNT_LEN]; //�����������˺�
    char			    szPassword[HC_SMTP_MAX_PASSWORD_LEN];   //��������������
    BOOL		        bReadRecipient;     //�ʼ�����ִ
    BOOL                bAuthenticate;      //�����˺���֤ѡ�� 0-����֤ 1-��֤
    char                szSenderName[HC_SMTP_MAX_NAME_LEN]; //����������
    DWORD               dwConnectTimeOut;   //���ӳ�ʱʱ�䣬��λ���룬�������Ϊ0��Ĭ��10��
    DWORD               dwSendTimeOut;      //���ͳ�ʱʱ�䣬��λ���룬�������Ϊ0��Ĭ��10��
    DWORD               dwRecvTimeOut;      //���ճ�ʱʱ�䣬��λ���룬�������Ϊ0��Ĭ��10��
    BYTE                byRes[116];
}NET_UTILS_SMTP_PARAM, *LPNET_UTILS_SMTP_PARAM;

enum SMTP_RECIPIENT_TYPE
{
    COMMON_RECIPIENT,   //��ͨ�ռ���
    CC_RECIPIENT,       //�����ռ���
    BCC_RECIPIENT       //�����ռ���
};

enum SMTP_ATTACHMENT_TYPE
{
    PATH_TYPE,      //������·���ķ�ʽ
    BUFFER_TYPE     //�������������ݵķ�ʽ
};

enum SMTP_MAIL_BODY_TYPE
{
    PLAIN_TEXT,   //���ı�
    HTML_FORMAT   //HTML��ʽ
};

typedef struct tagSMTP_MAIL_BODY
{
    DWORD  dwBodyType; //�ʼ�������������  0-�ı�����(�궨��PLAIN_TEXT)
    BYTE   *pData;     //����ָ��
    DWORD  dwDataLen;  //���ݳ���
    BYTE   byRes[64];
}SMTP_MAIL_BODY, *LPSMTP_MAIL_BODY;

//���½ӿڷ������滻���ٽ����ŵļ����ӿ�
//NET_UTILS_API LONG CALLBACK NET_UTILS_SMTPCLIENT_Create(const NET_UTILS_SMTP_PARAM *pSmtpParam);
//NET_UTILS_API BOOL CALLBACK NET_UTILS_SMTPCLIENT_SendMail(LONG lHandle);
//NET_UTILS_API BOOL  CALLBACK NET_UTILS_SMTPCLIENT_Destroy(LONG lHandle);
//NET_UTILS_API BOOL  CALLBACK NET_UTILS_SMTPCLIENT_AddAttachment(LONG lHandle, SMTP_ATTACHMENT_TYPE enumType, const char* pFileName, const char* pData, DWORD dwDataLen);
//NET_UTILS_API BOOL  CALLBACK NET_UTILS_SMTPCLIENT_AddRecipient(LONG lHandle, SMTP_RECIPIENT_TYPE enumType, const char* pEmailAddress, const char* pName);
//NET_UTILS_API BOOL  CALLBACK NET_UTILS_SMTPCLIENT_SetMailText(LONG lHandle, const char* pText);

NET_UTILS_API LONG  CALLBACK NET_SMTPCLIENT_Create(const NET_UTILS_SMTP_PARAM *pSmtpParam);
NET_UTILS_API BOOL  CALLBACK NET_SMTPCLIENT_SendMail(LONG lHandle, BOOL (CALLBACK *MAIL_SEND_CB) (LONG lHandle, DWORD dwProgress, void* pUser), void* pUser);
NET_UTILS_API BOOL  CALLBACK NET_SMTPCLIENT_Destroy(LONG lHandle);
NET_UTILS_API BOOL  CALLBACK NET_SMTPCLIENT_AddAttachment(LONG lHandle, SMTP_ATTACHMENT_TYPE enumType, const char* pFileName, const char* pData, DWORD dwDataLen);
NET_UTILS_API BOOL  CALLBACK NET_SMTPCLIENT_AddRecipient(LONG lHandle, SMTP_RECIPIENT_TYPE enumType, const char* pEmailAddress, const char* pName);
NET_UTILS_API BOOL  CALLBACK NET_SMTPCLIENT_SetMailBody(LONG lHandle, const SMTP_MAIL_BODY *pBody);



//SMTP��׼������
#define SMTP_STD_SERVICE_UNAVAILABLE            421 //����δ����, �رմ����ŵ�
#define SMTP_STD_MAILBOX_IS_BUSY                450 //Ҫ����ʼ�����δ��ɣ����䲻���ã����磬����æ��
#define SMTP_STD_LOCAL_ERROR_IN_PROCESSING      451 //����Ҫ��Ĳ�������������г���
#define SMTP_STD_INSUFFICIENT_SYS_STORAGE       452 //ϵͳ�洢���㣬Ҫ��Ĳ���δִ�У���������߹��ࣩ
#define SMTP_STD_SYNTAX_ERR                     500 //��ʽ���������ʶ�𣨴˴���Ҳ���������й�����
#define SMTP_STD_PARAM_ERR                      501 //������ʽ���󣨱���ظ���ת��·�����ࣩ
#define SMTP_STD_CMD_NOT_IMPLEMENTED            502 //�����ʵ��
#define SMTP_STD_BAD_CMD_SEQ                    503 //�������������
#define SMTP_STD_CMD_PARAM_NOT_IMPLEMENTED      504 //�����������ʵ��
#define SMTP_STD_AUTH_REQUIRED                  530 //��Ҫ�����֤�ķ�������δ�������֤
#define SMTP_STD_AUTH_FAILED                    535 //�û���֤ʧ��
#define SMTP_STD_MAILBOX_UNAVAILABLE            550 //Ҫ����ʼ�����δ��ɣ����䲻���ã����磬����δ�ҵ����򲻿ɷ��ʣ�
#define SMTP_STD_USER_NOT_LOCAL                 551 //�û��Ǳ��أ��볢��<forward - path>
#define SMTP_STD_EXCEEDED_STROAGE_ALLOCATION    552 //�����Ĵ洢���䣬Ҫ��Ĳ���δִ�У����磬�ʼ����ݹ��ࣩ
#define SMTP_STD_MAILBOX_NAME_NOT_ALLOWED       553 //�����������ã�Ҫ��Ĳ���δִ�У����������ʽ����
#define SMTP_STD_TRANSACTION_FAILED             554 //�����������ʧ��



//SMTP�Զ��������
#define SMTP_ERROR_SERVER_DOMAIN_NOT_EIXST      5001    //����������������
#define SMTP_ERROR_ATTACHMENT_IS_TOO_LARGE      5002    //����������С
#define SMTP_ERROR_MAIL_RECIPIENT_IS_NONE       5003    //�ʼ�������Ϊ��
#define SMTP_ERROR_AUTH_TYPE_NOT_SUPPORT        5004    //��֤���Ͳ�֧��

/********************************HTTP begin****************************************/

typedef	struct tagNET_UTILS_HTTP_SHORT_EXCHANGE
{
    void*      lpReqUrl;		//[in]url���ַ�����ʽ��ʾ�����£�
    //http://10.17.133.26:80/ISAPI/PTZCtrl/channels/1/patrols/capabilities
    //https://10.17.130.245:443/ISAPI/PTZCtrl/channels/1/patrols/capabilities
    DWORD      dwReqUrlLen;	//[in]url���ȣ��ַ�������
    void*      lpOutBuf;	//[out]��������ڴ�,�ⲿ���룻���ݲ�����HTTP��Ӧͷ
    DWORD      dwOutBufLen;//[in]��������ڴ泤��
    DWORD      dwRetLen;	//[out]�������ʵ�ʳ���
    BYTE       byMothod;	//[in]0-GET,1-PUT,2-POST,3-DELETE
    void*      lpRspHead;  //[out]http��Ӧͷ���ⲿ����,����Ҫʱ��Ϊnull
    DWORD      dwRspHeadLen;//[in]http��Ӧͷ�ڴ��С������Ҫʱ0
    BYTE       byRes[16];
}NET_UTILS_HTTP_SHORT_EXCHANGE,*LPNET_UTILS_HTTP_SHORT_EXCHANGE;

typedef void(CALLBACK *HTTPClientCB)(char *pRecvData, DWORD dwDataLen, DWORD dwStats, void* pUserData);

typedef	struct tagNET_UTILS_HTTP_SHORT_EXCHANGE_EX
{
    void*       lpReqUrl;	   //[in]url���ַ�����ʽ��ʾ�����£�
    //http://10.17.133.26:80/ISAPI/PTZCtrl/channels/1/patrols/capabilities
    //https://10.17.130.245:443/ISAPI/PTZCtrl/channels/1/patrols/capabilities
    DWORD        dwReqUrlLen; //[in]url���ȣ��ַ�������
    const void*  lpOutBuf;	   //[out]ֻ������������ڴ�,�ⲿ�����ڽӿڷ���ʱ���������������ݲ�����HTTP��Ӧͷ
    DWORD        dwOutBufLen; //[out]ֻ������������ڴ泤��
    DWORD        dwHttpState; //[out]ֻ�������http״ֵ̬
    BYTE         byMothod;	  //[in]0-GET,1-PUT,2-POST,3-DELETE
    BYTE         byRes1[3];
    HTTPClientCB fnCB;
    void*        pUserData;
    BYTE         byRes[4];
}NET_UTILS_HTTP_SHORT_EXCHANGE_EX, *LPNET_UTILS_HTTP_SHORT_EXCHANGE_EX;

typedef enum tagHTTP_CMD_TYPE
{
    ENUM_HTTP_VER = 0,           //��value��Ч������int *,�ɲ����ã�Ĭ�϶�֧��,����0��ʾ��֧��HTTP1.1,����1��ʾ��֧��
    ENUM_HTTP_USER = 1,
    ENUM_HTTP_BODY = 2,
    ENUM_HTTP_PARAM = 3,
    ENUM_HTTP_CALIB_CERT = 4, //����
    ENUM_HTTP_NOCALIB_CERT = 5,//����
    ENUM_HTTP_AUTHEN_MODE = 6,
    ENUM_HTTP_SAFE_FIRST = 7,
    ENUM_HTTP_EFFIC_FIRST = 8,
    ENUM_HTTP_CONNECT_TIMEOUT = 9,
    ENUM_HTTP_SEND_TIMEOUT = 10,
    ENUM_HTTP_RECV_TIMEOUT = 11,
    ENUM_HTTP_ALPN_PROTO = 12,
    ENUM_HTTP_CERTIFICATE = 13,
    ENUM_HTTP_MIME_BODY = 14,
    ENUM_HTTP_RECV_BODY_SIZE = 15, //����HTTP���ջ�������С��Ĭ����64M����������Ϊ512M��
    ENUM_HTTP_LOCAL_IP = 16, //��������ʹ�õı���ip��ַ
    ENUM_HTTP_REQUEST_PARAM = 17 //��ȡ������� GETʹ��
}HTTP_CMD_TYPE;

typedef struct tagNET_UTILS_SSL_CERTIFICATE
{
    BYTE byVerifyMode;    //0-������֤, 1-˫����֤

    BYTE byCertificateFileType; //֤������0-pem, 1-ANS
    BYTE byPrivateKeyFileType;  //˽Կ����0-pem, 1-ANS

    char *pUserCertificateFile; //֤��
    char *pUserPrivateKeyFile;  //˽Կ
    char *pCACertificateFile;   //CA֤��

    BYTE byRes[32];
}NET_UTILS_SSL_CERTIFICATE, *LPNET_UTILS_SSL_CERTIFICATE;

NET_UTILS_API LONG    CALLBACK    NET_HTTPCLIENT_Create();
NET_UTILS_API BOOL    CALLBACK    NET_HTTPCLIENT_Destroy(LONG lHandle);
NET_UTILS_API BOOL    CALLBACK    NET_HTTPCLIENT_SetParam(LONG lHandle, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
NET_UTILS_API BOOL    CALLBACK    NET_HTTPCLIENT_GetParam(LONG lHandle, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
NET_UTILS_API BOOL    CALLBACK    NET_HTTPCLIENT_ShortLinkExchange(LONG lHandle, LPNET_UTILS_HTTP_SHORT_EXCHANGE_EX lpExchange);

////���½ӿڽ��������ã�ʵ�������Ѿ������������ṩ�ӿڸ������ˣ������ṩ
//NET_UTILS_API LONG    CALLBACK    NET_UTILS_CreateHttpClient();
//NET_UTILS_API BOOL    CALLBACK    NET_UTILS_DestroyHttpClient(LONG lHandle);
//NET_UTILS_API BOOL    CALLBACK    NET_UTILS_SetHttpParam(LONG lHandle, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
//NET_UTILS_API BOOL    CALLBACK    NET_UTILS_GetHttpParam(LONG lHandle, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
NET_UTILS_API LONG    CALLBACK    NET_UTILS_ShortLinkExchange(LONG lHandle, LPNET_UTILS_HTTP_SHORT_EXCHANGE lpExchange);

class NET_UTILS_CLASS CHCHttpClient
{
public:
    CHCHttpClient();
    ~CHCHttpClient();
    int   ShortLinkExchange(LPNET_UTILS_HTTP_SHORT_EXCHANGE lpExchange);
    BOOL   SetHttpParam(unsigned int dwCmdType, void* lpName, unsigned int dwNameLen, void* lpValue, unsigned int dwValueLen);
private:
    LONG   m_lHandle;
};


typedef struct tagNET_UTILS_HTTP_SERVER_DATA_CB
{
    DWORD   dwSize;      //���ṹ�峤��
    DWORD   dwStatus;    //״ֵ̬,�����ڵ���0xff00���������NET_HTTPSERVER_Close�رսӿ�
                         //       0x0-������������
                         //       0x1-���ĳ��ȹ������ִλص������к�������, 
                         //       0x2-��������mime����Ҫ����NET_UTILS_GetHttpServerRspParam��ȡmime����
                         //       0xff00-�����쳣 
                         //       0xff01-��Դ����
                         //       0xff02-�Զ˹ر�
                         //       0xffff-�����ر�
    DWORD   dwDataLen;   //���ݳ���
    char*   pRecvData;   //���յ�������
    DWORD   dwStreamID;  //�����H1Э�飬���ֶ�ʼ��Ϊ0������Ϊ0�������û����ùܾ������ֵ����ȡ������ʱ��ֱ�Ӹ���������
}NET_UTILS_HTTP_SERVER_DATA_CB, *LPNET_UTILS_HTTP_SERVER_DATA_CB;

typedef void (CALLBACK *HTTPSERVERDATACB)(LONG iCallbackHandle, void* pData, void* pUserData);

typedef struct tatNET_UTILS_HTTP_LISTEN_PARAM
{
    DWORD  dwType;          //�����˿����� 0��������֪��HTTPЭ�飬��1.1��2.0; 1:��֧��HTTP1.1
    BYTE   szIP[128];       //IP��ַ
    WORD   wPort;           //�˿�
    WORD   byRes[2];
    DWORD  dwWaitForAccept; //���ڵȴ�accept�����Ӹ���,�����ø�������������ֱ�ӱ��ܾ���Ĭ��0x7FFFFFFF���ò�����ʱ����Ч�����޸�core�Ĵ���
    DWORD  dwRecvBuffSize;  //Ĭ��64M(���֧��64M)�����ջ���������󣬳�������ֵ�����ֶ�λص����ݣ�����һ���Իص���ɣ���������ݵĴ��䵼���ڴ����
    DWORD  dwRecvTimeOut;   //���ճ�ʱ����λms��Ĭ��5000,��ʾ�����Ӷ���ղ������ݣ�����Ϊ�����쳣
    DWORD  dwSendTimeOut;   //���ͳ�ʱ����λms��Ĭ��5000
    HTTPSERVERDATACB fnCB;  //���յ�����ʱ�Ļص�
    void*  pUserData;       //�û�����
}NET_UTILS_HTTP_LISTEN_PARAM, *LPNET_UTILS_HTTP_LISTEN_PARAM;


typedef struct tatNET_UTILS_HTTP_LISTEN_PARAM_EX
{
    DWORD  dwType;          //�����˿����� 0��������֪��HTTPЭ�飬��1.1��2.0; 1:��֧��HTTP1.1
    BYTE   szIP[128];       //IP��ַ
    WORD   wPort;           //�˿�
    WORD   byRes[2];
    DWORD  dwWaitForAccept; //���ڵȴ�accept�����Ӹ���,�����ø�������������ֱ�ӱ��ܾ���Ĭ��0x7FFFFFFF���ò�����ʱ����Ч�����޸�core�Ĵ���
    DWORD  dwRecvBuffSize;  //Ĭ��64M(���֧��64M)�����ջ���������󣬳�������ֵ�����ֶ�λص����ݣ�����һ���Իص���ɣ���������ݵĴ��䵼���ڴ����
    DWORD  dwRecvTimeOut;   //���ճ�ʱ����λms��Ĭ��5000,��ʾ�����Ӷ���ղ������ݣ�����Ϊ�����쳣
    DWORD  dwSendTimeOut;   //���ͳ�ʱ����λms��Ĭ��5000
    HTTPSERVERDATACB fnCB;  //���յ�����ʱ�Ļص�
    void*  pUserData;       //�û�����

    BYTE byHttps;           //0-��ʹ��HTTPS, 1-ʹ��HTTPS
    BYTE byVerifyMode;      //0-������֤, 1-˫����֤
    BYTE byCertificateFileType; //֤������0-pem, 1-ANS1
    BYTE byPrivateKeyFileType; //˽Կ����0-pem, 1-ANS1

    BYTE *pAlpnProto;
    DWORD dwAlpnProtoLen;

    char *pUserCertificateFile; //��Կ֤��
    char *pUserPrivateKeyFile;  //˽Կ
    char *pCACertificateFile;   //CA֤��

    DWORD dwSSLVersion; //SSL Method�汾
    //0 - SSL23, 1 - SSL2, 2 - SSL3, 3 - TLS1.0, 4 - TLS1.1, 5 - TLS1.2
    //SSL23�Ǽ���ģʽ����Э�̿ͻ��˺ͷ����ʹ�õ���߰汾

    BYTE byRes3[60];

}NET_UTILS_HTTP_LISTEN_PARAM_EX, *LPNET_UTILS_HTTP_LISTEN_PARAM_EX;


//��������������������׼��"Param1:Param2",�����������������ֱ��ʹ��ENUM_HTTP_SERVER_ANY������
//�Ǳ�׼�ĸ�������������ע��
typedef enum enumNET_UTILS_HTTP_SERVER_REPLY_PARA
{
    ENUM_HTTP_SERVER_VER = 0,         //��value��Ч������NET_UTILS_HTTP_VER *,�ɲ����ã�Ĭ��http/1.1
    ENUM_HTTP_SERVER_STATS = 1,       //��value��Ч���ɲ����ã�Ĭ��Ϊ200 ok
    ENUM_HTTP_SERVER_CONTENTDISPOSITION = 2,    //��������Ч�����;�Ϊchar *���ɲ����ã���ɸ�ʽ"Content-Disposition: %s; filename=%s", lpname, lpvalue,��"Content-Disposition: attachment;filename="test.xls""
    ENUM_HTTP_SERVER_BOUNDARY = 3,    //���ͬʱ�ύ�ķ�ʽ�ݲ�֧�֣��ͻ���������ʵ���������Ƚ��鷳
    ENUM_HTTP_SERVER_CONTENT = 4,     //��value��Ч������char*���������ã�����Ӧʱ����Ӧ����ͷ���ޱ�����
    ENUM_HTTP_SERVER_SENDTIMEOUT = 5, //��value��Ч������ΪDWORD *���������ã���Ĭ��5s
    ENUM_HTTP_SERVER_WITHOUTHEAD = 6, //��������Ϣͷ
    ENUM_HTTP_SERVER_CONTENTWITHOUTHEAD = 7,//��������������������ͷ

    ENUM_HTTP_SERVER_ANY = 0xff,      //��������Ч�����;�Ϊchar *����ɷ�ʽ "%s: %s", lpname, lpvalue
                                      //����������Ƴ����ظ���������ĸ������е�
}NET_UTILS_HTTP_SERVER_REPLY_PARA;


//��������������������׼Э����һ�㶼�����,���ֵ���һ���ṹ���ȡ
//��׼��"Param1:Param2",����һ�㲻�Ǳش��ģ�ֱ��ʹ��ENUM_HTTP_SERVER_ANY������
typedef enum enumNET_UTILS_HTTP_SERVER_REQ_PARA
{
    ENUM_HTTP_SERVER_GENERAL_REQ  = 0,        //��value��Ч������NET_UTILS_HTTP_SERVER_REQ_PARAM *
    ENUM_HTTP_SERVER_MIME_COUNT   = 1,        //��value��Ч������DWORD*
    ENUM_HTTP_SERVER_MIME_CONTENT = 2,
    ENUM_HTTP_SERVER_REMOTE_ADDR = 3,        //��ȡԶ��IP����value��Ч *, ����Ϊchar *�����Ȳ�������48���ַ����Լ���IPv6
    ENUM_HTTP_SERVER_MIME_CONTENT_EX = 4,
    ENUM_HTTP_SERVER_ANY_REQ      = 0xff,    //��������Ч�����;�Ϊchar *, lpNameΪ�������ƣ�lpValueΪ������ֵ
}NET_UTILS_HTTP_SERVER_REQ_CMD;


#define MAX_UTILS_REALM_LEN 32                       //���realm����
//�����豸��ȫ������Ҫ������������Ϊ192
#define MAX_UTILS_NONCE_LEN 192                      //���nonce����

#define MAX_UTILS_DEGIST_SRC_LEN	1024*4          //���ժҪ��Ϣ����
#define MAX_HA_LEN 33						       //���ܴ���󳤶�
#define MAX_UTILS_HTTP_URL   2048

#define  MAX_UTILS_NAME_LEN  480

typedef struct tagNET_UTILS_HTTP_DIGET_PARA
{
    char szUseName[MAX_UTILS_NAME_LEN + 1];
    char szRealm[MAX_UTILS_REALM_LEN];
    char szNonce[MAX_UTILS_NONCE_LEN];
    char szUri[MAX_UTILS_HTTP_URL];
    char szCNonce[MAX_UTILS_NONCE_LEN];
    char szNC[12];
    char szQop[12];  //ֻ������ѡ��auth/auth-int,���Ͻ�����9���ֽڹ���
    char szRespone[MAX_HA_LEN];
}NET_UTILS_HTTP_DIGET_PARA;

typedef struct tagNET_UTILS_HTTP_SERVER_REQ_PARAM
{
    char  szUrl[MAX_UTILS_HTTP_URL];
    BYTE  byMethod;  //0 - GET, 1 - PUT, 2 - POST, 3 - DELETE
    BYTE  byRes[3];
    NET_UTILS_HTTP_DIGET_PARA struDiget;
}NET_UTILS_HTTP_SERVER_REQ_PARAM, *LPNET_UTILS_HTTP_SERVER_REQ_PARAM;
 
typedef struct tagNET_UTILS_HTTP_MIME
{
    char szContentType[32];
    char szDisposition[32];
    char szName[256];                   //windows�£�·�������ô��
    char szFilename[256];
    char szEncoding[32];                //7bit��8bit��binary ��quoted-printable��base64��custom
    char szDescription[256];            //���������
    DWORD dwContentLen;                 //Content�ĳ���
    const char* pContent;               //const�ͣ��û���Ҫ����dwContentLen�����ߣ����ܽ��г���������Ĳ���
}NET_UTILS_HTTP_MIME, *LPNET_UTILS_HTTP_MIME;

typedef struct tagNET_UTILS_HTTP_MIME_EX
{
    char szContentType[32];
    char szDisposition[32];
    char szName[256];     //windows�£�·�������ô��
    char szFilename[256];
    char szEncoding[32];                //7bit��8bit��binary ��quoted-printable��base64��custom
    char szDescription[256];            //���������
    DWORD dwContentLen;            //Content�ĳ���
    const char* pContent;               //const�ͣ��û���Ҫ����dwContentLen�����ߣ����ܽ��г���������Ĳ���
    DWORD dwMimeHeadLen;
    const char* pMimeHead;
    BYTE byRes[128];
} NET_UTILS_HTTP_MIME_EX, *LPNET_UTILS_HTTP_MIME_EX;

typedef struct tagNET_UTILS_MIME_UNIT
{
    //HTTP��ʽ����
    //Content-Disposition: form-data; name="upload"; filename="C:\Users\test\Desktop\11.txt"
    //Content-Type: text/plain
    char szContentType[32];               //��ӦContent-Type
    char szName[256];       //��Ӧname�ֶ�
    char szFilename[256];   //��Ӧfilename�ֶ�
    DWORD dwContentLen;              //Content�ĳ���
    char* pContent;                       //����ָ��
    BYTE bySelfRead;                 // 0-��紫���ļ� 1-�ڲ���ȡ���ݣ�ͨ��szFilename��������·����
    BYTE byRes[15];
}NET_UTILS_MIME_UNIT, *LPNET_UTILS_MIME_UNIT;



NET_UTILS_API LONG    CALLBACK    NET_HTTPSERVER_CreateListen(LPNET_UTILS_HTTP_LISTEN_PARAM lpStruParam);
NET_UTILS_API LONG    CALLBACK    NET_HTTPSERVER_CreateListenEx(LPNET_UTILS_HTTP_LISTEN_PARAM_EX lpStruParamEx);

NET_UTILS_API BOOL    CALLBACK    NET_HTTPSERVER_DestroyListen(LONG iListenHandle);

NET_UTILS_API BOOL    CALLBACK    NET_HTTPSERVER_SetParam(LONG iCallbackHandle, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
NET_UTILS_API BOOL    CALLBACK    NET_HTTPSERVER_GetParam(LONG iCallbackHandle, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
NET_UTILS_API LONG    CALLBACK    NET_HTTPSERVER_Reply(LONG iCallbackHandle, BOOL bAutoClose);
NET_UTILS_API BOOL    CALLBACK    NET_HTTPSERVER_Close(LONG iCallbackHandle, BOOL bForceClose);

//V2ָH2�ӿڣ���H1���ݣ���˽��鲻��H1����H2��ʹ�ñ��ӿ�
NET_UTILS_API BOOL    CALLBACK    NET_HTTPSERVER_GetParamV2(LONG iCallbackHandle, DWORD dwStreamID, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
NET_UTILS_API BOOL    CALLBACK    NET_HTTPSERVER_SetParamV2(LONG iCallbackHandle, DWORD dwStreamID, DWORD dwCmdType, void* lpName, DWORD dwNameLen, void* lpValue, DWORD dwValueLen);
NET_UTILS_API LONG    CALLBACK    NET_HTTPSERVER_ReplyV2(LONG iCallbackHandle, DWORD dwStreamID, BOOL bAutoClose);

/********************************HTTP end****************************************/

/********************************FTP start***************************************/

#define FTP_UPLOAD_GETSTATUS     1
#define FTP_UPLOAD_PAUSE         2
#define FTP_UPLOAD_RESUME        3
#define FTP_UPLOAD_GETSIZE       4
#define FTP_UPLOAD_MKDIR        5
#define FTP_UPLOAD_CHANGEDIR    6
#define FTP_UPLOAD_UTF8_ON       7
#define FTP_UPLOAD_UTF8_OFF      8


#define FTP_STATUS_SUCC         1
#define FTP_STATUS_UPLOAD       2
#define FTP_STATUS_NETERROR     3
#define FTP_STATUS_NOENOUGHBUF   4
#define FTP_STATUS_FAIL         5

typedef enum tagFTPCharEncodeType
{
    FTP_ENUM_MEM_CHAR_ENCODE_ERR = -1,         //Error   
    FTP_ENUM_MEM_CHAR_ENCODE_NO = 0,          //Don't know.
    FTP_ENUM_MEM_CHAR_ENCODE_CN = 1,          //EUC-CN, GB2312
    FTP_ENUM_MEM_CHAR_ENCODE_GBK = 2,          //EUC-CN, GB2312
    FTP_ENUM_MEM_CHAR_ENCODE_BIG5 = 3,          //BIG5
    FTP_ENUM_MEM_CHAR_ENCODE_JP = 4,          //JISX0208-1, EUC-JP
    FTP_ENUM_MEM_CHAR_ENCODE_KR = 5,          //EUC-KR
    FTP_ENUM_MEM_CHAR_ENCODE_UTF8 = 6,          //UTF-8
    FTP_ENUM_MEM_CHAR_ENCODE_ISO8859_1 = 7,    //ISO-8859-n: ENUM_MEM_CHAR_ENCODE_ISO8859_1 + n -1
}FTP_CHAR_ENCODE_TYPE;


typedef struct tagNET_UTILS_FTP_SERVER_INFO
{
    char    szSvrAddr[128]; //FTP IP��ַ
    WORD    wSvrPort;       //FTP �˿ڣ��������0��SDKĬ��ʹ��21
    char    szUserName[64];//�û���
    char    szPassword[64];//����
    BYTE    byRes[254];	 
}NET_UTILS_FTP_SERVER_INFO,*LPNET_UTILS_FTP_SERVER_INFO;

typedef struct tagNET_UTILS_FTP_FILE_INFO
{
    char    szFileName[256];//ȫ·���������ļ���
    char    szDstDir[256];  //�������ϵ�Ŀ¼����ʽ��xxx/xxx��Ϊ0��ʾ�ϴ���ftp��Ŀ¼
    DWORD   dwOffset;       //�ļ�ƫ����(�ֽ���)���ϵ�����ʱʹ�ã�0��ʾ��ƫ��
    BYTE    byEncodeType;   //���ر������ͣ���ָszDstDir�ֶ�
    BYTE    szFTPFileName[128];  //ftp�������ϴ��ļ�����
    BYTE    byStream;      //�Ƿ�Ϊ�ϴ������� 0-����·�����ļ��ϴ���1-���ݻ��������������ϴ�
    DWORD   dwSize;        //�ļ��ܳ���
    BYTE    byRes[118];
}NET_UTILS_FTP_FILE_INFO,*LPNET_UTILS_FTP_FILE_INFO;

typedef struct tagNET_UTILS_FTP_UPLOAD_STATUS
{
    DWORD  dwStatus;       //1-�ϴ��ɹ���2-�����ϴ���3-�����쳣��4-�������㣬5-�ϴ�ʧ�ܣ�100����-ftpԭʼ״̬��
    DWORD  dwProgress;	    //0~100
    DWORD  dwSendedSize;   //ʵ���ѷ��͵��ֽ���
    BYTE   byRes[52];
}NET_UTILS_FTP_UPLOAD_STATUS,*LPNET_UTILS_FTP_UPLOAD_STATUS;

typedef struct tagNET_UTILS_FTP_UPLOAD_FILE_INFO
{
    char    szDstFile[256];  //�������ϵ�Ŀ¼����ʽ��xxx/xxx,��Ҫָ�������ļ�
    BYTE    byRes[256];
}NET_UTILS_FTP_UPLOAD_FILEINFO, *LPNET_UTILS_FTP_UPLOAD_FILEINFO;

typedef struct tagNET_UTILS_FTP_UPLOAD_FILESIZE
{
    DWORD dwStatus;     //ftp���ص�״̬��
    DWORD dwSize;    //����ָ���ļ���С
    BYTE  byRes[256];
}NET_UTILS_FTP_UPLOAD_FILESIZE, *LPNET_UTILS_FTP_UPLOAD_FILESIZE;

NET_UTILS_API LONG    CALLBACK    NET_FTP_CreateClient(LPNET_UTILS_FTP_SERVER_INFO pSvrInfo);
NET_UTILS_API BOOL    CALLBACK    NET_FTP_UploadFile(LONG lUploadHandle, LPNET_UTILS_FTP_FILE_INFO pFileInfo);
NET_UTILS_API BOOL    CALLBACK    NET_FTP_Control(LONG lHandle, DWORD dwControlType, void* lpInBuffer, DWORD dwInLen, void* lpOutBuffer, DWORD dwOutLen);
NET_UTILS_API BOOL    CALLBACK    NET_FTP_DestroyClient(LONG lUploadHandle);

//����0xffffffff������ǽ����ϴ�
NET_UTILS_API BOOL    CALLBACK    NET_FTP_InputData(LONG lUploadHandle, void* lpInBuffer, DWORD dwInLen);


/***********************************FTP end******************************************/

/***********************************Websocket begin**********************************/

//webSocket ����������
typedef enum enumNET_UTILS_WEBSOCKET_REPLY_PARA
{
    ENUM_UTILS_WEBSOCKET_CUSTOM = 1,         //webSocket �Զ�������������
    ENUM_UTILS_WEBSOCKET_PACK_LEN = 2,       //��֧�ֵ����websocket֡���ȣ�Ĭ��64M�����64M
                                             //һ�����������϶������쳣������˻�Ͽ����ӣ��ͻ������ǶϿ����Ӻ�����
                                             //��Ҫ���ڱ������ն˲�����Ϊ����̫���ı��Ķ������ڴ治��
                                             //lpNameΪNULL���ɣ�lpValueΪ(unsign int *)����
    ENUM_UTILS_WEBSOCKET_REMOTE_ADDR = 5,    //���ڷ���˻�ȡ�ͻ��˵�����IP����value��Ч��Ŀǰ��֧�ַ���ˣ�lpValue����Ϊ��char *��
                                             //dwValueLen��������48���ֽڣ����ڼ���IPv6�����
    ENUM_UTILS_WEBSOCKET_REQ_URL = 6,        //���ڷ���˻�ȡ�ͻ��������URL����value��Ч��Ŀǰ��֧�ַ���ˣ�lpValue����Ϊ��char *��
}NET_UTILS_WEBSOCKET_REPLY_PARA;

typedef enum tagWEBSOCKET_MESSAGE_TYPE
{
    NO_TYPE = -1,                   //��ʱ�����մ������ݵȣ��ر�����ʱ����
    CONTINUATION_MSG = 0,
    TEXT_MSG = 1,
    BINARY_MSG = 2,
    CLOSE_MSG = 8,
    PING_MSG = 9,
    PONG_MSG = 10,
    ESTABLISH_MSG = 11,             //�������
    HANDSHAKE_REQ_MSG = 12,         //��������
    RECONN_START = 13,              //������ʼ
    RECONN_SUCC = 14                //�����ɹ�
}WEBSOCKET_MESSAGE_TYPE;


typedef void (CALLBACK *WEBSOCKETDATACB)(LONG iHandle, void* pData, void* pUserData);

typedef struct tagNET_UTILS_WEBSOCKET_DATA_CB
{
    DWORD   dwSize;                     //���ṹ�峤�ȣ������Ժ���չ��������һ���汾�������Ӹ��ֶ�
    DWORD   dwStatus;                   //״ֵ̬����SDK�����뱣��һ��
    DWORD   dwDataLen;                  //���ݳ���,������websocket֡ͷ,��ֻ֧�����64M
    WEBSOCKET_MESSAGE_TYPE eType;       //��������
    BOOL    bFin;                       //�Ƿ�Ϊβ֡
    char*   pRecvData;                  //���յ�������
}NET_UTILS_WEBSOCKET_DATA_CB, *LPNET_UTILS_WEBSOCKET_DATA_CB;

typedef struct tagNET_UTILS_WEBSOCKET_CLIENT_PARAM
{
    LPVOID  lpReqUrl;	          //[in]url���ַ�����ʽ��ʾ�����£�
    //http://www.websocket.com/chat
    //http://127.0.0.1:80/chat
    DWORD   dwReqUrlLen;         //[in]url���ȣ��ַ�������
    BYTE    byRelink;            //0:�ر��������ܣ�1��������������
    BYTE    byRes[15];           //����
    DWORD   dwRecvTimeOut;       //��λms�����ճ�ʱʱ�䣬Ĭ��30000ms����������������£��ó�ʱʱ�����㣬���������ر�����������£����ص������쳣֪ͨ
    DWORD   dwRelinkInterval;    //��λms�����������������ʧ�ܺ��ٴγ��������ļ��ʱ��
    DWORD   dwConnectTimeOut;    //��λms�����ӳ�ʱ��Ĭ��3000ms
    DWORD   dwSendTimeOut;       //��λms�����ͳ�ʱ��Ĭ��5000ms
    WEBSOCKETDATACB fnCB;        //���ڻص������Լ������쳣
    LPVOID  pUserData;           //�û�����
}NET_UTILS_WEBSOCKET_CLIENT_PARAM, *LPNET_UTILS_WEBSOCKET_CLIENT_PARAM;

NET_UTILS_API LONG   CALLBACK    NET_WEBSOCKETCLIENT_Create(LPNET_UTILS_WEBSOCKET_CLIENT_PARAM lpParam);
//websocketЭ�������û������ֵ�ʱ���Զ����ֶΣ���˿��Ÿýӿ�
NET_UTILS_API BOOL   CALLBACK    NET_WEBSOCKETCLIENT_SetParam(LONG lHandle, NET_UTILS_WEBSOCKET_REPLY_PARA byCmdType, LPVOID lpName, DWORD dwNameLen, LPVOID lpValue, DWORD dwValueLen);
//���ÿͻ��˷����������,�������ʹ��,���������5000����ı���,��λms
NET_UTILS_API BOOL   CALLBACK    NET_WEBSOCKETCLIENT_SetHbInterval(LONG iHandle, DWORD uInterval);
//�����������ֵĺ���
NET_UTILS_API BOOL   CALLBACK    NET_WEBSOCKETCLIENT_Start(LONG lHandle);
//���ڻ�ȡ�û��Զ����ͷ��
NET_UTILS_API BOOL   CALLBACK    NET_WEBSOCKETCLIENT_GetParam(LONG lHandle, NET_UTILS_WEBSOCKET_REPLY_PARA byCmdType, LPVOID lpName, DWORD dwNameLen, LPVOID lpValue, DWORD dwValueLen);
//��������
NET_UTILS_API BOOL   CALLBACK    NET_WEBSOCKETCLIENT_Send(LONG lHandle, WEBSOCKET_MESSAGE_TYPE byMsgType, BOOL bFin, LPVOID pBuff, DWORD dwDataLen);
//�ر�websocket����
NET_UTILS_API BOOL   CALLBACK    NET_WEBSOCKETCLIENT_Destroy(LONG lHandle);


typedef struct tagNET_UTILS_WEBSOCKET_LINK_CB
{
    DWORD   dwSize;      //���ṹ�峤�ȣ������Ժ���չ��������һ���汾�������Ӹ��ֶ�
    DWORD   dwStatus;    //״ֵ̬������
    BYTE    szSrcIP[128];//IP��ַ
    WORD   wSrcPort;    //�˿�
}NET_UTILS_WEBSOCKET_LINK_CB, *LPNET_UTILS_WEBSOCKET_LINK_CB;

//typedef BOOL(CALLBACK *WEBSOCKETLINKCB)(LONG lCallBackHandle, void* pData, void* pUserData);

typedef struct tatNET_UTILS_WEBSOCKET_LISTEN_PARAM
{
    BYTE   szIP[128];       //IP��ַ
    WORD   wPort;           //�˿�
    BYTE   byRes[2];
    DWORD  dwSendTimeOut;  //���ͳ�ʱ,Ĭ��5000ms
    DWORD  dwRecvTimeOut;  //���ճ�ʱ,Ĭ��30000ms
    DWORD  dwIntervalTime; //�������ʱ�䣬Ĭ��5000ms
    DWORD  dwWaitForAccept; //���ڵȴ�accept�����Ӹ���,�����ø�������������ֱ�ӱ��ܾ���Ĭ��0x7FFFFFFF���ò�����ʱ����Ч
    WEBSOCKETDATACB fnCB;   //���յ�����ʱ�Ļص�
    LPVOID pUserData;       //�û�����
}NET_UTILS_WEBSOCKET_LISTEN_PARAM, *LPNET_UTILS_WEBSOCKET_LISTEN_PARAM;

typedef struct tatNET_UTILS_WEBSOCKET_LISTEN_PARAM_EX
{
    BYTE   szIP[128];       //IP��ַ
    WORD   wPort;           //�˿�
    BYTE   byRes[2];
    DWORD  dwSendTimeOut;   //���ͳ�ʱ,Ĭ��5000ms
    DWORD  dwRecvTimeOut;   //���ճ�ʱ,Ĭ��30000ms
    DWORD  dwIntervalTime;  //�������ʱ�䣬Ĭ��5000ms
    DWORD  dwWaitForAccept; //���ڵȴ�accept�����Ӹ���,�����ø�������������ֱ�ӱ��ܾ���Ĭ��0x7FFFFFFF���ò�����ʱ����Ч
    WEBSOCKETDATACB fnCB;   //���յ�����ʱ�Ļص�
    LPVOID pUserData;       //�û�����

    BYTE bySSL;                 //0-��ʹ��SSL, 1-ʹ��SSL

    BYTE byVerifyMode;          //0-������֤, 1-˫����֤(Ŀǰ��֧��˫����֤��
    BYTE byCertificateFileType; //֤������0-pem, 1-ANS1
    BYTE byPrivateKeyFileType;  //˽Կ����0-pem, 1-ANS1

    char *pUserCertificateFile; //�����֤��
    char *pUserPrivateKeyFile;  //�����˽Կ
    char *pCACertificateFile;   //CA֤�飨��Ϊ��֧��˫����֤���ʸ��ֶ�Ŀǰ��Ч��

    DWORD dwSSLVersion; //SSL Method�汾
    //0 - SSL23, 1 - SSL2, 2 - SSL3, 3 - TLS1.0, 4 - TLS1.1, 5 - TLS1.2
    //SSL23�Ǽ���ģʽ����Э�̿ͻ��˺ͷ����ʹ�õ���߰汾

    BYTE byRes3[60];
}NET_UTILS_WEBSOCKET_LISTEN_PARAM_EX, *LPNET_UTILS_WEBSOCKET_LISTEN_PARAM_EX;

//typedef void (CALLBACK *WEBSOCKETSERVERDATACB)(LONG lCallBackHandle, void* pData, void* pUserData);

NET_UTILS_API LONG    CALLBACK    NET_WEBSOCKETSERVER_CreateListen(LPNET_UTILS_WEBSOCKET_LISTEN_PARAM lpParam);
NET_UTILS_API LONG    CALLBACK    NET_WEBSOCKETSERVER_CreateListenEx(LPNET_UTILS_WEBSOCKET_LISTEN_PARAM_EX lpParamEx);

//�����������ֵĺ���
NET_UTILS_API BOOL    CALLBACK    NET_WEBSOCKETSERVER_Start(LONG lCallBackHandle);
//�����û��Զ����ͷ��
NET_UTILS_API BOOL    CALLBACK    NET_WEBSOCKETSERVER_SetParam(LONG lCallBackHandle, NET_UTILS_WEBSOCKET_REPLY_PARA byCmdType, LPVOID lpName, DWORD dwNameLen, LPVOID lpValue, DWORD dwValueLen);
//��ȡ�û��Զ����ͷ��
NET_UTILS_API BOOL    CALLBACK    NET_WEBSOCKETSERVER_GetParam(LONG lCallBackHandle, NET_UTILS_WEBSOCKET_REPLY_PARA byCmdType, LPVOID lpName, DWORD dwNameLen, LPVOID lpValue, DWORD dwValueLen);
//��������
NET_UTILS_API BOOL    CALLBACK    NET_WEBSOCKETSERVER_Send(LONG lCallBackHandle, WEBSOCKET_MESSAGE_TYPE byMsgType, BOOL bFin, LPVOID pBuff, DWORD dwDataLen);
//�ر�websocket����
NET_UTILS_API BOOL    CALLBACK    NET_WEBSOCKETSERVER_Close(LONG lCallBackHandle);
//�ر�websocket����
NET_UTILS_API BOOL    CALLBACK    NET_WEBSOCKETSERVER_DestroyListen(LONG lHandle);

/***********************************Websocket end************************************/

/***********************************NPQ begin****************************************/

#define NET_ERR_NPQ_BASE_INDEX    8000    //NPQ�������
#define NET_ERR_NPQ_PARAM       (NET_ERR_NPQ_BASE_INDEX + 1)        //NPQ���������
#define NET_ERR_NPQ_SYSTEM      (NET_ERR_NPQ_BASE_INDEX + 2)        //NPQ�����ϵͳ���ô���(������Դ����ʧ�ܻ��ڲ�����ȣ�
#define NET_ERR_NPQ_GENRAL      (NET_ERR_NPQ_BASE_INDEX + 3)        //NPQ���ڲ�ͨ�ô���
#define NET_ERR_NPQ_PRECONDITION    (NET_ERR_NPQ_BASE_INDEX + 4)        //NPQ�����˳�����
#define NET_ERR_NPQ_NOTSUPPORT        (NET_ERR_NPQ_BASE_INDEX + 5)        //NPQ�⹦�ܲ�֧��

#define NET_ERR_NPQ_NOTCALLBACK    (NET_ERR_NPQ_BASE_INDEX + 100)   //����û�лص�����


//enum NPQ_DATA_TYPE
//{
//    NPQ_DATA_RTP_VIDEO,			//��ƵRTP����
//    NPQ_DATA_RTP_AUDIO,			//��ƵRTP����
//    NPQ_DATA_RTP_PRIVATE,		//˽�а�RTP����
//    NPQ_DATA_RTP_MUTI,          //RTP����������
//    NPQ_DATA_RTCP_VIDEO,		//��ƵRTCP
//    NPQ_DATA_RTCP_AUDIO,		//��ƵRTCP
//    NPQ_DATA_CMD,				//����ص�����ӦNPQ_CMD ��Ҫ�ⲿ����Ӧ����
//    NPQ_DATA_MULITIPLEX,        //δ֪�������ݣ��ⲿ��ȷ���������ͣ���NPQ�ڲ�ʶ��,��Ҫ���sdp��
//};

//enum NPQ_CMD_TYPE
//{
//    NPQ_CMD_ENCODE,		//����Ƶ�������
//    NPQ_CMD_FORCE_I_FRAME   //ǿ��I֡��Ϣ
//};

struct NET_UTILS_NPQ_ECODE_PARAM
{
    int iVersion;				//�ṹ��汾�������Ժ����
    int iMaxBitRate;			//�������   ��λ bps
    int iResolution;			//�ֱ���  ��������SDKЭ�鶨�������ֵ
    unsigned char res[244];
};

typedef struct tagNET_UTILS_NPQ_CMD
{
    int iVersion;					//�ṹ��汾�������Ժ����
    NPQ_CMD_TYPE enInfoType;		//��������
    union INFO_U
    {
        NET_UTILS_NPQ_ECODE_PARAM struEncode;
        unsigned char res[256];
    }unCmd;
}NET_UTILS_NPQ_CMD, *LPNET_UTILS_NPQ_CMD;

// ʱ��
typedef struct _HK_SYSTEMTIME_UTILS
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
}HK_SYSTEMTIME_UTILS;

typedef struct tagNET_UTILS_NPQ_PACK_PARAM
{
    // �̶��Ĳ���
    DWORD        pack_size;             // PS��TS��RTP������������0ΪĬ�ϳ���
    DWORD        track_index;           // �����
    DWORD        syc_video_track;       // ��������Ƶ�����

    DWORD        system_format;         // Ŀ���װ��ʽ
    DWORD        system_format_subtype; // Ŀ�����͵��Ӹ�ʽ��Ŀǰֻʹ����MP4��������װ������

    DWORD        video_format;          // ��Ƶ����
    DWORD        audio_format;          // ��Ƶ����
    DWORD        privt_format;          // ˽����������

    // �ο�֡��Ϣ���ǹ̶�����
    DWORD        is_hik_stream;         // �Ƿ���Ϻ�������
    DWORD        encrypt_type;          // ��������
    DWORD        frame_type;            // ��ǰ֡���� I/P/B/audio/privt
    DWORD        time_stamp;            // ʱ���
    float               duration;              // ֡ʱ��
    DWORD        frame_num;             // ֡��
    HK_SYSTEMTIME_UTILS       global_time;           // ȫ��ʱ�䣨�����������У�

    // ��Ƶ����
    struct
    {
        WORD  width_orig;            // �ֱ��ʣ�ԭʼ��
        WORD  height_orig;           // �ֱ��ʣ�ԭʼ��
        WORD  width_play;            // �ֱ��ʣ��ü���
        WORD  height_play;           // �ֱ��ʣ��ü���
        float           frame_rate;            // ֡��
        WORD  interlace;             // �Ƿ񳡱���
        WORD  b_frame_num;           // ��ģʽ�У�B֡�ĸ���
        DWORD    is_svc_stream;         // �Ƿ�SVC����
    }video;

    // ��Ƶ����
    struct
    {
        WORD  channels;              // ����
        WORD  bits_per_sample;       // ��λ
        DWORD    samples_rate;          // ������
        DWORD    bit_rate;              // ������
    }audio;

    // ˽�в���
    struct
    {
        DWORD    privt_type;            // ˽������
        DWORD    data_type;             // ������
    }privt;

}NET_UTILS_NPQ_PACK_PARAM, *LPNET_UTILS_NPQ_PACK_PARAM;

typedef struct tagNET_UTILS_IPADDRESS
{
    char szIP[128];     //IP��ַ
    WORD  wPort;      //�˿ں�
    BYTE    byRes[2];
}NET_UTILS_IPADDRESS, *LPNET_UTILS_IPADDRESS;

typedef struct tagNET_UTILS_NPQ_LINK_COND
{
    NET_UTILS_IPADDRESS struAudioRtp;       //��Ƶ����ַ
    NET_UTILS_IPADDRESS struAudioRtcp;     //��ƵRTCP��ַ
    NET_UTILS_IPADDRESS struVideoRtp;        //��Ƶ����ַ
    NET_UTILS_IPADDRESS struVideoRtcp;      //��ƵRTCP��ַ
    BYTE   byRes[32];
}NET_UTILS_NPQ_LINK_COND, *LPNET_UTILS_NPQ_LINK_COND;

typedef void (CALLBACK *NPQ_TRANS_CB)(LONG id, LONG iDataType, unsigned char* pData, DWORD nDataLen, void* pUser);

typedef struct tagNET_UTILS_NPQ_SERVICE_COND
{
    NET_UTILS_NPQ_LINK_COND struLinkLocal;      //��������Ƶ�����Ӻ�RTCP���ӵ�ַ��Ϣ
    NPQ_TRANS_CB fnDataCallBack;    //�������ݻص�����
    void* pUser;  //�ص������û�����
    char *sSdp; //����SDP��Ϣ
    char *sFile;    //�ļ�·��
    BYTE byRes[28];
}NET_UTILS_NPQ_SERVICE_COND, *LPNET_UTILS_NPQ_SERVICE_COND;

//enum NPQ_QOS_TYPE
//{
//    QOS_TYPE_NACK = (1 << 0),          //Nack		
//    QOS_TYPE_FEC = (1 << 1),			 //FEC
//    QOS_TYPE_DEJITTER = (1 << 2),		 //ȥ����
//    QOS_TYPE_BW = (1 << 3),			 //ӵ������
//    QOS_TYPE_PLI = (1 << 4),			 //PLI
//    QOS_TYPE_SYNCHRONOUS = (1 << 5),	 //����Ƶͬ��
//    QOS_TYPE_ALL = 0xff,
//};


typedef struct tagNET_UTILS_NPQ_STATE_SINGLE
{
    DWORD dwRttUs;			//rtt����λus
    DWORD dwRealRttUs;		//ʵʱrtt����λus
    BYTE byLossFraction;	//�����ʣ���λ1/256
    BYTE byLossFraction2;	//�����ָ�֮��Ķ����ʣ�ֻ���ڽ��ն˻�ȡ����λ1/256
    BYTE byRes1[2];
    DWORD dwBitRate;   //��ǰ����ʵʱ���ʣ���λ��bps
    BYTE byRes[120];
}NET_UTILS_NPQ_STATE_SINGLE, *LPNET_UTILS_NPQ_STATE_SINGLE;

typedef struct tagNET_UTILS_NPQ_STATE
{
    DWORD dwSize;
    NET_UTILS_NPQ_STATE_SINGLE struAudioState;  //��Ƶ����״̬
    NET_UTILS_NPQ_STATE_SINGLE struVideoState;  //��Ƶ����״̬
    BYTE byRes[256];
}NET_UTILS_NPQ_STATE, *LPNET_UTILS_NPQ_STATE;

typedef struct tagNET_UTILS_NPQ_CONNECT_PARAM
{
    NET_UTILS_NPQ_LINK_COND struLinkRemote;  //�Զ�����Ƶ�����Ӻ�RTCP���ӵ�ַ��Ϣ
    char *sSdp; //�Զ�SDP��Ϣ
    char *sFile;    //�ļ�·��
    BYTE byRes[60];
}NET_UTILS_NPQ_CONNECT_PARAM, *LPNET_UTILS_NPQ_CONNECT_PARAM;

typedef struct tagNET_UTILS_NPQ_COMPRESSINFO
{
    DWORD dwSize;
    DWORD dwMaxBitRate; //�������
    char *sFile;    //�ļ�·��
    BYTE byRes[60];
}NET_UTILS_NPQ_COMPRESSINFO, *LPNET_UTILS_NPQ_COMPRESSINFO;

typedef struct tagNET_UTILS_NPQ_PARAM_SINGLE
{
    int iType;  //Qos�������ͣ�����NPQ_QOS_TYPE
    BOOL bVideo;    //�Ƿ�����ƵQos
    BOOL bAudio;    //�Ƿ�����ƵQos
    BYTE byRes[256];
}NET_UTILS_NPQ_PARAM_SINGLE, *LPNET_UTILS_NPQ_PARAM_SINGLE;

typedef struct tagNET_UTILS_NPQ_PARAM
{
    DWORD dwSize;
    NET_UTILS_NPQ_PARAM_SINGLE struSenderParam; //��Ϊ���Ͷ˵�NPQ����
    NET_UTILS_NPQ_PARAM_SINGLE struReceiverParam; //��Ϊ���ն˵�NPQ����
    BYTE byRes[128];
}NET_UTILS_NPQ_PARAM, *LPNET_UTILS_NPQ_PARAM;


NET_UTILS_API LONG    CALLBACK    NET_UTILS_NpqTransStart(NET_UTILS_NPQ_SERVICE_COND *lpServiceCond);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_NpqTransInputData(LONG iHandle, LONG iDataType, unsigned char* pData, DWORD nDataLen);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_NpqTransInputRawData(LONG iHandle, LPNET_UTILS_NPQ_PACK_PARAM lpPackParam, unsigned char* pData, DWORD nDataLen);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_NpqTransGetState(LONG iHandle, LPNET_UTILS_NPQ_STATE lpNpqState);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_NpqTransStop(LONG iHandle);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_NpqTransGetCompressInfo(LONG iHandle, LPNET_UTILS_NPQ_COMPRESSINFO lpCompressInfo);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_NpqTransConnect(LONG iHandle, NET_UTILS_NPQ_CONNECT_PARAM *lpConnectParam);
NET_UTILS_API BOOL    CALLBACK    NET_UTILS_NpqSetParams(LONG iHandle, NET_UTILS_NPQ_PARAM *lpParam);


/***********************************NPQ end****************************************/

/***********************************SIP begin****************************************/

//SIP��ؽӿڷ�װ����
#define SIP_USERNAME_LEN    64  //SIP�û�������
#define SIP_PASSWORD_LEN    64  //SIP���볤��
#define SIP_CALL_ID_LEN          64  //����ID����
#define SIP_NAME_LEN       64   //sip�ն����Ƴ���
#define SIP_URL_LEN     256 //sip url����
#define SIP_SDP_LEN     16384   //SDP����
#define SIP_DEV_TYPE_LEN    24  //SIP�豸�������Ƴ���

typedef enum
{
    SIP_STATUS_100_TRYING = 100,
    SIP_STATUS_180_RINGING = 180,
    SIP_STATUS_181_CALL_IS_BEING_FORWARDED = 181,
    SIP_STATUS_182_QUEUED = 182,
    SIP_STATUS_183_SESSION_PROGRESS = 183,
    SIP_STATUS_200_OK = 200,
    SIP_STATUS_202_ACCEPTED = 202,
    SIP_STATUS_300_MULTIPLE_CHOICES = 300,
    SIP_STATUS_301_MOVED_PERMANENTLY = 301,
    SIP_STATUS_302_MOVED_TEMPORARILY = 302,
    SIP_STATUS_305_USE_PROXY = 305,
    SIP_STATUS_380_ALTERNATIVE_SERVICE = 380,
    SIP_STATUS_400_BAD_REQUEST = 400,
    SIP_STATUS_401_UNAUTHORIZED = 401,
    SIP_STATUS_402_PAYMENT_REQUIRED = 402,
    SIP_STATUS_403_FORBIDDEN = 403,
    SIP_STATUS_404_NOT_FOUND = 404,
    SIP_STATUS_405_METHOD_NOT_ALLOWED = 405,
    SIP_STATUS_406_NOT_ACCEPTABLE = 406,
    SIP_STATUS_407_PROXY_AUTH_REQUIRED = 407,
    SIP_STATUS_408_REQUEST_TIMEOUT = 408,
    SIP_STATUS_409_CONFLICT = 409,
    SIP_STATUS_410_GONE = 410,
    SIP_STATUS_411_LENGTH_REQUIRED = 411,
    SIP_STATUS_412_PRECONDITION_FAILED = 412,
    SIP_STATUS_413_REQUEST_TOO_LARGE = 413,
    SIP_STATUS_414_REQUEST_URI_TOO_LONG = 414,
    SIP_STATUS_415_UNSUPPORTED_MEDIA = 415,
    SIP_STATUS_416_UNSUPPORTED_URI = 416,
    SIP_STATUS_417_RESOURCE_PRIORITY = 417,
    SIP_STATUS_420_BAD_EXTENSION = 420,
    SIP_STATUS_421_EXTENSION_REQUIRED = 421,
    SIP_STATUS_422_SESSION_TIMER_TOO_SMALL = 422,
    SIP_STATUS_423_INTERVAL_TOO_BRIEF = 423,
    SIP_STATUS_423_REGISTRATION_TOO_BRIEF = 423,
    SIP_STATUS_480_TEMPORARILY_UNAVAILABLE = 480,
    SIP_STATUS_481_NO_CALL = 481,
    SIP_STATUS_481_NO_TRANSACTION = 481,
    SIP_STATUS_482_LOOP_DETECTED = 482,
    SIP_STATUS_483_TOO_MANY_HOPS = 483,
    SIP_STATUS_484_ADDRESS_INCOMPLETE = 484,
    SIP_STATUS_485_AMBIGUOUS = 485,
    SIP_STATUS_486_BUSY_HERE = 486,
    SIP_STATUS_487_REQUEST_CANCELLED = 487,
    SIP_STATUS_487_REQUEST_TERMINATED = 487,
    SIP_STATUS_488_NOT_ACCEPTABLE = 488,
    SIP_STATUS_489_BAD_EVENT = 489,
    SIP_STATUS_490_REQUEST_UPDATED = 490,
    SIP_STATUS_491_REQUEST_PENDING = 491,
    SIP_STATUS_493_UNDECIPHERABLE = 493,
    SIP_STATUS_494_SECAGREE_REQUIRED = 494,
    SIP_STATUS_500_INTERNAL_SERVER_ERROR = 500,
    SIP_STATUS_501_NOT_IMPLEMENTED = 501,
    SIP_STATUS_502_BAD_GATEWAY = 502,
    SIP_STATUS_503_SERVICE_UNAVAILABLE = 503,
    SIP_STATUS_504_GATEWAY_TIME_OUT = 504,
    SIP_STATUS_505_VERSION_NOT_SUPPORTED = 505,
    SIP_STATUS_513_MESSAGE_TOO_LARGE = 513,
    SIP_STATUS_580_PRECONDITION = 580,
    SIP_STATUS_590_SELF_DEF_NEEDWAIT = 590,
    SIP_STATUS_600_BUSY_EVERYWHERE = 600,
    SIP_STATUS_603_DECLINE = 603,
    SIP_STATUS_604_DOES_NOT_EXIST_ANYWHERE = 604,
    SIP_STATUS_606_NOT_ACCEPTABLE = 606,
    SIP_STATUS_687_DIALOG_TERMINATED = 687,
}SIP_STATUS_CODE;

typedef enum tagSIP_LINK_TYPE
{
    SIP_UDP = 0,
    SIP_TCP,
    SIP_TLS,
}SIP_LINK_TYPE;

//SIP_I_XXXΪ�Է����������״̬�ı��¼���SIP_R_XXXΪ�Է���Ӧ�������¼�
typedef enum tagSIP_EVENT_TYPE
{
    SIP_I_INVITE = 0,           //�����¼�
    SIP_I_ACTIVE,                //���н���
    SIP_I_TERMINATED,    //������ֹ
    SIP_I_INFO,                     //INFO��Ϣ�¼�
    SIP_R_INVITE,                //INVITE��Ӧ�¼�
    SIP_R_REGISTER,          //REGISTER��Ӧ�¼�
}SIP_EVENT_TYPE;

typedef struct tagNET_SIP_INVITE_INPUT
{
    char sCallID[SIP_CALL_ID_LEN];  //����ID,��������һ·SIP�Ự���˲������ڸ���һ·SIP�Ự��INVITE���󣬶����½��Ự���˲�����Ϊ��
    char sRequestUrl[SIP_URL_LEN];  //INVITE����URL��Ϣ��e.g. sip:test@10.10.10.10:5060
    char sSdp[SIP_SDP_LEN];     //SDP��Ϣ
    BYTE byRes[32];
}NET_SIP_INVITE_INPUT, *LPNET_SIP_INVITE_INPUT;

typedef struct tagNET_SIP_INVITE_OUTPUT
{
    char sCallID[SIP_CALL_ID_LEN];  //����ID,��������һ·SIP�Ự
    BYTE byRes[32];
}NET_SIP_INVITE_OUTPUT, *LPNET_SIP_INVITE_OUTPUT;

typedef struct tagNET_SIP_INFO_INPUT
{
    char sCallID[SIP_CALL_ID_LEN];  //����ID,��������һ·SIP�Ự
    char *pContent; //INFO��Ϣ����
    DWORD dwContentLength;  //INFO��Ϣ���ݳ���
    BYTE byRes[32];
}NET_SIP_INFO_INPUT, *LPNET_SIP_INFO_INPUT;

typedef struct tagNET_SIP_INFO_OUTPUT
{
    DWORD dwCseq;  //INFO��Ϣ�����к�
    BYTE byRes[124];
}NET_SIP_INFO_OUTPUT, *LPNET_SIP_INFO_OUTPUT;

typedef struct tagNET_SIP_REGISTER_INPUT
{
    NET_UTILS_IPADDRESS struSipAddress; //SIP�������ĵ�ַ��Ϣ
    char sUserName[SIP_USERNAME_LEN];   //SIP�û�����ע���������
    char sPassword[SIP_PASSWORD_LEN];    //SIP���룬ע���������
    DWORD dwExpires;    //ע����Ч�ڣ���λ���룬��0Ĭ��10min
    DWORD dwKeepAliveInterval;    //����������λ���룬��0Ĭ��5s
    BYTE byRes[32];
}NET_SIP_REGISTER_INPUT, *LPNET_SIP_REGISTER_INPUT;

typedef struct tagNET_SIP_ANSWER_INVITE_INPUT
{
    char sCallID[SIP_CALL_ID_LEN];  //����ID,��������һ·SIP�Ự
    BOOL bAccept;   //�Ƿ����
    char sSdp[SIP_SDP_LEN];     //SDP��Ϣ
    BYTE byRes[64];
}NET_SIP_ANSWER_INVITE_INPUT, *LPNET_SIP_ANSWER_INVITE_INPUT;

//�¼���Ӧ����

typedef struct tagNET_SIP_I_INVITE_PARAM
{
    char sRemoteUrl[SIP_URL_LEN]; //�Է��ն˱�ʶ,e.g. sip:test@10.10.10.10:5060
    char sSdp[SIP_SDP_LEN];     //SDP��Ϣ
    char sDevType[SIP_DEV_TYPE_LEN];    //�Զ��豸��������
    BYTE byRes[40];
}NET_SIP_I_INVITE_PARAM, *LPNET_SIP_I_INVITE_PARAM;

typedef struct tagNET_SIP_I_INFO_PARAM
{
    char *pContent; //INFO��Ϣ����
    DWORD dwContentLength;  //INFO��Ϣ���ݳ���
    DWORD dwCseq;    //INFO���к�
    BYTE byRes[60];
}NET_SIP_I_INFO_PARAM, *LPNET_SIP_I_INFO_PARAM;

typedef struct tagNET_SIP_R_INVITE_PARAM
{
    char sSdp[SIP_SDP_LEN];     //SDP��Ϣ
    char sDevType[SIP_DEV_TYPE_LEN];    //�Զ��豸��������
    BYTE byRes[40];
}NET_SIP_R_INVITE_PARAM, *LPNET_SIP_R_INVITE_PARAM;

typedef struct tagNET_SIP_EVENT_PARAM
{
    char sCallID[SIP_CALL_ID_LEN];  //����ID,��������һ·SIP�Ự
    union
    {
        BYTE byRes[16704];
        NET_SIP_I_INVITE_PARAM struIInvite; //״ֵ̬Ϊ200��SIP_I_INVITE�¼���Ч
        NET_SIP_I_INFO_PARAM struIInfo; //״ֵ̬Ϊ200��SIP_I_INFO�¼���Ч
        NET_SIP_R_INVITE_PARAM struRInvite; //״ֵ̬Ϊ200��SIP_R_INVITE�¼���Ч
    }uniEventParam;
}NET_SIP_EVENT_PARAM, *LPNET_SIP_EVENT_PARAM;

typedef NET_SIP_INVITE_OUTPUT NET_SIP_CLEAR_INPUT;

/** @fn typedef void (CALLBACK * SIP_EVENT_CALLBACK(CALLBACK *SIP_EVENT_CALLBACK)
*  @brief  SIP�¼��ص�����
*  @param (in)	LONG lHandle:   SIP����ʵ�������NET_SIP_Create�ķ���ֵ
*  @param (in)	SIP_EVENT_TYPE enEventType:   SIP�¼�����
*  @param (in)	SIP_STATUS_CODE enStatus:   SIP״̬��
*  @param (in)	NET_SIP_EVENT_PARAM* lpParam:   �¼���Ӧ����
*  @param (in)	void* pUser:   �û�����
*  @return SIP_STATUS_CODE
*	���յ�SIP_I_INVITE�¼�ʱ����ͨ������ֵ���ջ�ܾ���������
*	SIP_STATUS_200_OK��ʾ������һ�����Զ�����ʱʹ��
*	SIP_STATUS_590_SELF_DEF_NEEDWAIT ��ʾ��Ҫ�û�������ܾ���������ش�״̬����Ҫ
*	����NET_SIP_AnswerInvite�������߾ܽӺ���
*	���յ�SIP_R_INVITE�¼�ʱ����ͨ������ֵ���ջ�ܾ��Է����Լ����е���Ӧ
*	�����¼�ʱ������ֵ��Ч
*/
typedef SIP_STATUS_CODE(CALLBACK *SIP_EVENT_CALLBACK)(LONG lHandle, SIP_EVENT_TYPE enEventType, SIP_STATUS_CODE enStatus, NET_SIP_EVENT_PARAM* lpParam, void* pUser);

typedef struct tagNET_SIP_CREATE_INPUT
{
    NET_UTILS_IPADDRESS struSipAddress; //��������SIP����ĵ�ַ��Ϣ
    char sLocalName[SIP_NAME_LEN];  //��������
    SIP_LINK_TYPE enLinkType;   //ʹ�õĴ���Э�����ͣ�Ŀǰֻ֧��UDP
    SIP_EVENT_CALLBACK fnEventCallBack; //SIP�¼��Ļص�����
    void* pUser; //�û�����
    BYTE byRes[32];
}NET_SIP_CREATE_INPUT, *LPNET_SIP_CREATE_INPUT;

NET_UTILS_API LONG    CALLBACK    NET_SIP_Create(NET_SIP_CREATE_INPUT *lpCreateInput);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_Invite(LONG lHandle, NET_SIP_INVITE_INPUT *lpInviteInput, NET_SIP_INVITE_OUTPUT *lpInviteOutput);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_AnswerInvite(LONG lHandle, NET_SIP_ANSWER_INVITE_INPUT *lpAnswerInviteInput);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_ClearCall(LONG lHandle, NET_SIP_CLEAR_INPUT *lpClearInput);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_SendInfo(LONG lHandle, NET_SIP_INFO_INPUT *lpInfoInput);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_SendInfoEx(LONG lHandle, NET_SIP_INFO_INPUT *lpInfoInput, NET_SIP_INFO_OUTPUT *lpInfoOutput);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_Register(LONG lHandle, NET_SIP_REGISTER_INPUT *lpRegisterInput);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_UnRegister(LONG lHandle);

NET_UTILS_API BOOL    CALLBACK    NET_SIP_Destroy(LONG lHandle);

/***********************************SIP end****************************************/

typedef enum tagTRANS_TERMINAL_TYPE
{
    TRANS_TERMINAL_CLIENT = 0,
    TRANS_TERMINAL_SERVER = 1,
    TRANS_TERMINAL_SERVER_LINK = 2
}TRANS_TERMINAL_TYPE;

typedef enum tagTRANS_PROTO_TYPE
{
    TRANS_PROTO_TCP = 0,
    TRANS_PROTO_UDP = 1
}TRANS_PROTO_TYPE;

typedef enum tagTRANS_MODE_TYPE
{
    TRANS_MODE_ASYN = 0,
    TRANS_MODE_SYN = 1
}TRANS_MODE_TYPE;

typedef enum tagTRANS_STATUS_TYPE
{
    TRANS_STATUS_OK = 0,
    TRANS_STATUS_NEW = 1,
    TRANS_STATUS_CLOSE = 2
}TRANS_STATUS_TYPE;

typedef struct tagNET_TRANS_SEND_PARAM
{
    char* pBuf;       //���ͻ�����
    DWORD dwSendLen;  //���ͻ�������С
    DWORD dwTimeout;  //��ʱʱ�䣨��λ�����룩
    BYTE  byRes[36];
} NET_TRANS_SEND_PARAM, *LPNET_TRANS_SEND_PARAM;

typedef struct tagNET_TRANS_RECV_PARAM
{
    char* pBuf;       //���ջ�����
    DWORD dwBufLen;   //���ջ�������С��NET_TRANS_Recv�ӿ�ʹ�ã��첽�ص���ʹ�ã�
    DWORD dwTimeout;  //��ʱʱ�䣨��λ�����룩��NET_TRANS_Recv�ӿ�ʹ�ã��첽�ص���ʹ�ã�
    DWORD dwWant;     //�������յ����ݳ��ȣ�Ŀǰ�в�֧�֣�
    DWORD dwRecvLen;  //ʵ�ʽ��յ������ݳ���
    DWORD dwStatus;   //״ֵ̬��0-��ʾ������1-TCP�����ӣ�2-TCP���ӶϿ����첽ģʽ�£�
    BYTE  byRes[24];
} NET_TRANS_RECV_PARAM, *LPNET_TRANS_RECV_PARAM;

typedef struct tagNET_TRANS_PEER
{
    char  szPeerIP[128];
    WORD  wPeerPort;
    BYTE  byRes[30];
}NET_TRANS_PEER, *LPNET_TRANS_PEER;


typedef void (CALLBACK *TRANS_RECV_CB)(LONG lHandle, NET_TRANS_RECV_PARAM *pRecvParam, NET_TRANS_PEER *pPeer, void* pUser);

typedef struct tagNET_TRANS_PARAM
{
    BYTE byType;                 //0-Client 1-Server
    BYTE byProto;                //0-TCP 1-UDP
    BYTE byBind;                 //0-���� 1-��
    BYTE byMode;                 //0-ͬ�� 1-�첽
    BYTE byRes1[2];
    WORD wPort;           //�����˿�
    char szIP[128];       //����IP
    DWORD dwSendTimeout;  //Ĭ�Ϸ������ݳ�ʱʱ�䣨��λ�����룩
    DWORD dwRecvTimeout;  //Ĭ�Ͻ������ݳ�ʱʱ�䣨��λ�����룩
    DWORD dwConnectTimeout;  //���ӳ�ʱʱ�䣨��λ�����룩
    TRANS_RECV_CB fnRecvCB;  //���ݻص���TCP�����ṩ��UDP�����첽ģʽ���ṩ��
    void *pRecvUser;         //���ݻص��û�ָ��

    BYTE  byRes[32];
} NET_TRANS_PARAM, *LPNET_TRANS_PARAM;


NET_UTILS_API  LONG CALLBACK  NET_TRANS_Create(const NET_TRANS_PARAM *pServerParam);
NET_UTILS_API  LONG CALLBACK  NET_TRANS_Send(const LONG lHandle, NET_TRANS_SEND_PARAM *pSendParam, NET_TRANS_PEER *pPeer = NULL);
NET_UTILS_API  LONG CALLBACK  NET_TRANS_Recv(const LONG lHandle, NET_TRANS_RECV_PARAM *pRecvParam, NET_TRANS_PEER *pPeer = NULL);
NET_UTILS_API  int  CALLBACK  NET_TRANS_GetSocket(const LONG lHandle);
NET_UTILS_API  BOOL CALLBACK  NET_TRANS_Destroy(const LONG lHandle);


//--------------------------------RTSP�����-----------------------------------

typedef BOOL(CALLBACK * RTSPSERVERDATACB)(LONG lSessionHandle, DWORD dwType, void* pData, void* pUser);

typedef struct tagNET_RTSP_SERVER_PARAM
{
    char   szListenIP[128];      //IP��ַ
    WORD   wListenPort;    //RTSP�˿�(Ĭ��554)
    BYTE   byRes[2];

    RTSPSERVERDATACB fnCB;  //���յ�����ʱ�Ļص�
    void*  pUser;           //�û�����

    BYTE   byRes1[52];

}NET_RTSP_SERVER_PARAM, *LPNET_RTSP_SERVER_PARAM;

typedef struct tagNET_RTSP_SERVER_MCAST_PARAM
{
    char   szMCastIP[128];      //�ಥIP��ַ
    WORD   wMCastPort;          //�ಥ�˿�
    BYTE   byRes[2];
    char*  pConference;
    DWORD  dwConferenceLen;
    LONG   lRtspHandle;
    BYTE   byRes1[48];
}NET_RTSP_SERVER_MCAST_PARAM, *LPNET_RTSP_SERVER_MCAST_PARAM;


#define NET_RTSP_SET_PORT_RANGE  1
#define NET_RTSP_SET_MCAST_ADDR  2

typedef struct tatNET_RTSP_RTP_PORT_RANGE
{
    WORD   wStartPort;    //RTP�˿���ʼ��ַ(TCP/UDP/Mcast����)������
    WORD   wEndPort;      //RTP�˿ڽ�����ַ(TCP/UDP/Mcast����)��������
    BYTE    byRes[12];
}NET_RTSP_RTP_PORT_RANGE, *LPNET_RTSP_RTP_PORT_RANGE;

typedef struct tagNET_RTSP_RTP_MCAST_ADDR
{
    char szIP[128];  //�ಥIP��ַ
    BYTE byRes[32];
}NET_RTSP_RTP_MCAST_ADDR, *LPNET_RTSP_RTP_MCAST_ADDR;

NET_UTILS_API  LONG CALLBACK NET_RTSPSERVER_Create(LPNET_RTSP_SERVER_PARAM lpParam);

NET_UTILS_API  BOOL CALLBACK NET_RTSPSERVER_SetParam(LONG lHandle, DWORD dwCommand, void *pData, DWORD dwDataLen);

NET_UTILS_API  BOOL CALLBACK NET_RTSPSERVER_Start(LONG lHandle);

NET_UTILS_API  LONG CALLBACK NET_RTSPSERVER_RtpSend(LONG lSessionHandle, BYTE byRtpTag, char* pSendBuf, DWORD dwSendLen, DWORD dwTimeout);

NET_UTILS_API  BOOL CALLBACK NET_RTSPSERVER_Close(LONG lSessionHandle);

NET_UTILS_API  LONG CALLBACK NET_RTSPSERVER_CreateMCast(LPNET_RTSP_SERVER_MCAST_PARAM lpParam);
NET_UTILS_API  LONG CALLBACK NET_RTSPSERVER_MCastRtpSend(LONG lMCastHandle, BYTE byRtpTag, char* pSendBuf, DWORD dwSendLen, DWORD dwTimeout);
NET_UTILS_API  LONG CALLBACK NET_RTSPSERVER_DestroyMCast(LONG lMCastHandle);

NET_UTILS_API  BOOL CALLBACK NET_RTSPSERVER_Destroy(LONG lHandle);

#define RTSP_MSG_CONNECT       1 //RTSP���ӽ�����Ϣ
#define RTSP_MSG_DISCONNECT    2 //RTSP���ӶϿ���Ϣ

#define RTSP_MSG_DESCRIBE      3 //DESCRIBE��Ϣ
#define RTSP_MSG_SETUP         4 //SETUP��Ϣ
#define RTSP_MSG_PLAY          5 //PLAY��Ϣ
#define RTSP_MSG_TEARDOWN      6 //TEARDOWN��Ϣ
#define RTSP_MSG_PRIVATETRANS  7 // PRIVATETRANS��Ϣ

#define RTSP_MSG_ERROR         256 //����

//RTSP_MSG_CONNECT
typedef struct tagNET_RTSP_LINK_INFO
{
    char   szClientIP[128]; //RTSP�ͻ���IP
    WORD   wClientPort;     //RTSP�ͻ��˶˿�
    BYTE   byRes[2];
    //char   szLocalIP[128];  //RTSP�ͻ����ڱ��������ϵ�IP(�ಥʹ��)
    BYTE   byRes1[28];
} NET_RTSP_LINK_INFO, *LPNET_RTSP_LINK_INFO;

typedef struct tagNET_RTSP_SERVER_SDP_INFO
{
    DWORD dwStartTime; //��ʼʱ���(��λ:����)
    DWORD dwEndTime;   //����ʱ���(��λ:����)
    char  szHeader[256];      //ͷ����
    char  szEncryptDes[64];   //ͷ���ݼ��ܷ�ʽ
    char  szVideoControlUrl[512];    //��ƵURL
    char  szAudioControlUrl[512];    //��ƵURL(��ǰ�汾�в�֧����Ƶ)
    char  szVersion[128];     //�汾��Ϣ
    BYTE  byRes[256];
}NET_RTSP_SERVER_SDP_INFO, *LPNET_RTSP_SERVER_SDP_INFO;


typedef struct tagNET_RTSP_SERVER_DESCRIBE
{
    char*  pClientIP;        //RTSP�ͻ���IP��ַ
    WORD   wClientPort;      //RTSP�ͻ��˶˿�
    BYTE   byRes[2];
    char*  pUrl;             //URL��Ϣ
    char*  pAuth;            //��֤��Ϣ

    NET_RTSP_SERVER_SDP_INFO struSDPInfo; //�����SDP��Ϣ

    BYTE   byRes1[12];
}NET_RTSP_SERVER_DESCRIBE, *LPNET_RTSP_SERVER_DESCRIBE;

typedef struct tagNET_RTSP_SERVER_SETUP
{
    char* pControlUrl;   //SETUP���ݵ�URL
    char* pConference;   //Conference��Ϣ
    LONG  lMCastHandle;  //�ಥ���-1��ʾ�ಥ��δ������>=0��ʾ��Ҫ����Ķಥ��
    char* pMCastIP;
    WORD  wMCastPort;
    BYTE  byRes[14];
}NET_RTSP_SERVER_SETUP, *LPNET_RTSP_SERVER_SETUP;

typedef struct tagNET_RTSP_SERVER_PLAY
{
    BYTE  byType;   //0-��ͣ���ţ�1-�ָ����ţ�2-��ʱ�䷶Χ���ţ�3-�����ʲ���
    BYTE  byRtpTag; //0-��ƵRTP��· 1-��ƵRTP��·
    BYTE  byRes[2];
    DWORD dwStartTime; // byType=2ʱ��Ч��������ʼʱ��(��λ������)
    DWORD dwEndTime;   // byType=2ʱ��Ч�����Ž���ʱ��(��λ������)
    DWORD dwScale;     // byType=3ʱ��Ч�����ű���
    BYTE  byRes1[16];
}NET_RTSP_SERVER_PLAY, *LPNET_RTSP_SERVER_PLAY;


typedef struct tagNET_RTSP_SERVER_ERROR_INFO
{
    DWORD dwErrorCode;
    BYTE  byRes[28];
}NET_RTSP_SERVER_ERROR_INFO, *LPNET_RTSP_SERVER_ERROR_INFO;


//-----------------------------�����ͻ���-----------------------------------

typedef struct tagNET_PSTREAM_PUSH_PARAM
{
    char            szServerIP[128]; //IP��ַ
    WORD            wServerPort;     //�˿�
    BYTE            byLinkMode;      //�������ͣ�0-TCP��1-UDP(�в�֧��)��2-HRUDP(�в�֧��)
    BYTE            byPackageType;   //��װ��ʽ��0-RTP
    char            szDeviceID[32];  //�豸ID(�ͻ��˶���)
    char           *pHeader;         //ý��ͷ
    DWORD           dwHeaderLen;     //ý��ͷ����
    BYTE            byRes1[84];
}NET_PSTREAM_PUSH_PARAM, *LPNET_PSTREAM_PUSH_PARAM;

NET_UTILS_API  LONG CALLBACK  NET_PSTREAM_StartPush(LPNET_PSTREAM_PUSH_PARAM pParam);

typedef struct tagNET_PSTREAM_PUSH_DATA
{
    void    *pData;   //Ҫ���͵����ݻ�����
    DWORD   dwDataLen;//Ҫ���͵����ݳ���
    BYTE    byRes[24];
}NET_PSTREAM_PUSH_DATA, *LPNET_PSTREAM_PUSH_DATA;

NET_UTILS_API  LONG CALLBACK  NET_PSTREAM_Push(LONG lHandle, LPNET_PSTREAM_PUSH_DATA pData);
NET_UTILS_API  BOOL CALLBACK  NET_PSTREAM_StopPush(LONG lHandle);


#endif