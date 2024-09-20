/**  @file   EBaseInterface.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief  �ⲿ�ӿ�
 *   
 *   @author shijianfengyf2
 *   @modify shijianfengyf2
 *   @date   2018/08/09
 *   
 *   @note:
 */

#ifndef _DEVEBASE_SRC_INTERFACE_EBASEINTERFACE_H_
#define _DEVEBASE_SRC_INTERFACE_EBASEINTERFACE_H_

//#include "DevComPublicDef.h"
#include "HPR_Config.h"
#include "HPR_Types.h"

//����gcc�Լ�g++�������£�attribute�����ԣ���ǰ����Ϊhidden
#ifndef NET_COM_ATTRIBUTE_VISIBILITY
    #define NET_COM_ATTRIBUTE_VISIBILITY //���ֺ��ʹ�õı�������֧��������ܣ�����ȶ���ɿյģ��Ժ��и���һ��������ʹ��
    //#ifdef OS_POSIX
    //    #define NET_COM_ATTRIBUTE_VISIBILITY  __attribute__ ((visibility("hidden")))
    //#else  // !OS_POSIX
    //    #define NET_COM_ATTRIBUTE_VISIBILITY
    //#endif // !other os
#endif // NET_COM_ATTRIBUTE_VISIBILITY

#ifndef NET_COM_EXPORT_TYPE
    #ifdef __cplusplus
        #ifdef NETSDK_EXPORTS
            #define NET_COM_EXPORT_TYPE extern "C"__declspec(dllexport)
            #define NET_COM_CLASS_EXPORT_TYPE __declspec(dllexport)
        #else
            #define NET_COM_EXPORT_TYPE extern "C"
            #define NET_COM_CLASS_EXPORT_TYPE
        #endif // !NETSDK_EXPORTS
    #else
        #define NET_COM_EXPORT_TYPE
    #endif // !__cplusplus
#endif // !NET_COM_EXPORT_TYPE


//����ӿ��Լ��ർ����
#ifndef NET_COM_API
    #define NET_COM_API NET_COM_EXPORT_TYPE NET_COM_ATTRIBUTE_VISIBILITY
    #define NET_COM_CLASS NET_COM_CLASS_EXPORT_TYPE NET_COM_ATTRIBUTE_VISIBILITY
#endif  // !NET_COM_API

//����ӿڵ���˳��꣬����ʹ��Ĭ�ϵķ�ʽ
#ifndef CALLBACK
    #define CALLBACK
#endif // !CALLBACK

#if defined(OS_WINDOWS)
    typedef SOCKET HPR_SOCK_T;
#elif defined(OS_POSIX)
    typedef int HPR_SOCK_T;
#else
    #error OS Not Implement Yet.
#endif

/*******************ȫ�ִ����� begin**********************/
#define DEV_COM_ERROR_NONE                      0   //û�д���
#define DEV_COM_ERROR_NOINIT                    3   //û�г�ʼ��
#define DEV_COM_ERROR_CONNECT		            7	//���ӷ�����ʧ��
#define DEV_COM_ERROR_SEND			            8	//�����������ʧ��
#define DEV_COM_ERROR_RECV			            9	//�ӷ�������������ʧ��
#define DEV_COM_ERROR_RECV_TIMEOUT		        10	//�ӷ������������ݳ�ʱ
#define DEV_COM_ERROR_DATA                      11  //�����Ͻ��յ��������쳣
#define DEV_COM_ERROR_ORDER                     12  //���ô������
#define DEV_COM_ERROR_PARAMETER                 17  //��������
#define DEV_COM_ERROR_SUPPORT                   23  //��֧�ָù���
#define DEV_COM_ERROR_FILEOPENFAIL              35  //���ļ�����������Ϊ�ļ������ڻ���·������
#define DEV_COM_ERROR_OPERNOTFINISH             36  //�ϴεĲ�����û�����
#define DEV_COM_ERROR_ALLOC_RESOURCE            41  //��Դ�������
#define DEV_COM_ERROR_NOENOUGH_BUF              43  //������̫С
#define DEV_COM_ERROR_CREATESOCKET              44  //����SOCKET����
#define DEV_COM_ERROR_SETSOCKET                 45  //����SOCKET����
#define DEV_COM_ERROR_MAXNUM                    46  //�ﵽ�������
#define DEV_COM_ERROR_BINDSOCKET    			72	//���׽���ʧ��
#define DEV_COM_ERROR_SOCKETCLOSE   			73	//socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�

//��֤������
#define DEV_COM_ERROR_AUTHENTICATION_SUCCESS                     500  //��֤�ɹ�
#define DEV_COM_ERROR_AUTHENTICATION_FAIL                        501  //��֤ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_CMD_ERROR                   502  //�Ƿ�����
#define DEV_COM_ERROR_AUTHENTICATION_DATA_INVALID                503  //Э�����ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_DEV_ID_INVALID              504  //DevID�Ƿ�
#define DEV_COM_ERROR_AUTHENTICATION_QUERY_AUTHCODE_FAIL         505  //ƽ̨��ѯ��֤��ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_QUERY_REDIS_FAIL            506  //ƽ̨��ѯredisʧ��
#define DEV_COM_ERROR_AUTHENTICATION_SESSION_KEY_INVALID         507  //SessionKey��Ч
#define DEV_COM_ERROR_AUTHENTICATION_ENCRYPT_FAIL                508  //Э�����ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_QUERY_DATA_ERROR            509  //��ѯDas��Stun��Ϣʧ��
#define DEV_COM_ERROR_AUTHENTICATION_MASTERKEY_INVALID           510  //masterkey�Ƿ�
#define DEV_COM_ERROR_AUTHENTICATION_SESSION_KEY_INVALID_NOT          //�ݲ���
#define DEV_COM_ERROR_STUN_INVALID_AUTHENTICATION                512  //��ѯstun��֤ʧ��
#define DEV_COM_ERROR_DAS_INVALID_AUTHENTICATION                 513  //��ѯdas��֤ʧ��
#define DEV_COM_ERROR_CODE_ERROR                                 514  //�������̴���
#define DEV_COM_ERROR_LBS_UPDATE_REDIS_FAIL                      515  //ƽ̨�����豸��Ϣʧ��
#define DEV_COM_ERROR_LBS_MAX_DEV_LINK_ERROR                     516  //ƽ̨�豸���������Ѵ�����

//�����Խ�������
#define DEV_COM_ERROR_PARSING_FAIL               600  //������Ϣʧ��
#define DEV_COM_ERROR_CHECK_TOKEN                601  //��֤tokenʧ��

#define DEV_COM_ERROR_HTTP_ERROR                 700  //http�����յ�http��Ӧ����״̬��Ϊ200������״̬ͨ��������ʽ��ȡ

//өʯ΢�ں˴�����
#define DEV_COM_ERROR_EZDEVSDK_INDEX                100000
#define DEV_COM_ERROR_EZDEVSDK_INTERNAL             (DEV_COM_ERROR_EZDEVSDK_INDEX + 1)  //�ڲ�����
#define DEV_COM_ERROR_EZDEVSDK_INVALD_CALL          (DEV_COM_ERROR_EZDEVSDK_INDEX + 2)  //������������
#define DEV_COM_ERROR_EZDEVSDK_PARAMS_INVALID       (DEV_COM_ERROR_EZDEVSDK_INDEX + 3)  //�����Ƿ�
#define DEV_COM_ERROR_EZDEVSDK_BUFFER_TOO_SMALL     (DEV_COM_ERROR_EZDEVSDK_INDEX + 4)  //��������С����
#define DEV_COM_ERROR_EZDEVSDK_DATA_LEN_RANGE       (DEV_COM_ERROR_EZDEVSDK_INDEX + 5)  //���ݴ�С������Χ
#define DEV_COM_ERROR_EZDEVSDK_MEMORY               (DEV_COM_ERROR_EZDEVSDK_INDEX + 6)  //�ڴ��쳣
#define DEV_COM_ERROR_EZDEVSDK_JSON_INVALID         (DEV_COM_ERROR_EZDEVSDK_INDEX + 7)  //�Ƿ���json����
#define DEV_COM_ERROR_EZDEVSDK_JSON_FORMAT          (DEV_COM_ERROR_EZDEVSDK_INDEX + 8)  //json��������
#define DEV_COM_ERROR_EZDEVSDK_EXTEND_NO_FIND       (DEV_COM_ERROR_EZDEVSDK_INDEX + 9)  //����·���Ҳ�����Ӧ��ע������
#define DEV_COM_ERROR_EZDEVSDK_EXTEND_FULL          (DEV_COM_ERROR_EZDEVSDK_INDEX + 10) //��չע������
#define DEV_COM_ERROR_EZDEVSDK_EXTEND_EXISTED       (DEV_COM_ERROR_EZDEVSDK_INDEX + 11) //��չ�Ѿ�ע��
#define DEV_COM_ERROR_EZDEVSDK_QUEUE_FULL           (DEV_COM_ERROR_EZDEVSDK_INDEX + 12) //��Ϣ��������
#define DEV_COM_ERROR_EZDEVSDK_VALUE_LOAD           (DEV_COM_ERROR_EZDEVSDK_INDEX + 13) //��ȡ�豸����ʧ��
#define DEV_COM_ERROR_EZDEVSDK_VALUE_SAVE           (DEV_COM_ERROR_EZDEVSDK_INDEX + 14) //�����������豸ʧ��
#define DEV_COM_ERROR_EZDEVSDK_MSG_STOP_DISTRIBUTE  (DEV_COM_ERROR_EZDEVSDK_INDEX + 15) //�豸����ֹͣ,�ϲ���Ϣֹͣ�·�
#define DEV_COM_ERROR_EZDEVSDK_MSG_DEFLATE_FAIL     (DEV_COM_ERROR_EZDEVSDK_INDEX + 16) //���Ľ�ѹʧ��
#define DEV_COM_ERROR_EZDEVSDK_MSG_INFLATE_FAIL     (DEV_COM_ERROR_EZDEVSDK_INDEX + 17) //����ѹ��ʧ��
#define DEV_COM_ERROR_EZDEVSDK_INS_FULL             (DEV_COM_ERROR_EZDEVSDK_INDEX + 18) //�ͻ��������ﵽ����

#define DEV_COM_ERROR_EZDEVSDK_NET_INDEX            100300
#define DEV_COM_ERROR_EZDEVSDK_NET_CREATE           (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 1)  ///< ����socketʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_CONNECT          (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 2)  ///< ��������ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_DISCONNECTED     (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 3)  ///< �������ӶϿ�
#define DEV_COM_ERROR_EZDEVSDK_NET_TRANSMIT         (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 4)  ///< ���ݴ���ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_DNS              (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 5)  ///< ��������ʧ��

#define DEV_COM_ERROR_EZDEVSDK_LBS_INDEX                100600
#define DEV_COM_ERROR_EZDEVSDK_NET_AUTHCODE_MISMATCH    (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 1)  ///< ��֤�벻һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_INVALID_CALL         (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 2)  ///< �ͷ������Ľ�������������
#define DEV_COM_ERROR_EZDEVSDK_NET_INVALID_DATA         (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 3)  ///< �������յ���������
#define DEV_COM_ERROR_EZDEVSDK_NET_DEVID_MISMATCH       (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 4)  ///< devid��һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_MASTERKEY_MISMATCH   (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 5)  ///< masterkey��һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_SESSIONKEY_MISMATCH  (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 6)  ///< sessionkey��һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_INVALID_DEV          (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 7)  ///< ��Ч�豸
#define DEV_COM_ERROR_EZDEVSDK_NET_SERVER_CRYPTO        (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 8)  ///< �������ӽ���ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_GET_DATA             (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 9)  ///< ��ȡdas����stun��Ϣʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_SERVER_EXCEPTION     (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 10) ///< �������ڲ��쳣
#define DEV_COM_ERROR_EZDEVSDK_NET_CHECK_SESSIONKEY_FAIL (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 11) ///< sessionkey��֤ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_SIGN_CHECK_FAIL       (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 12)  ///< auth_iУ��signʧ�ܡ�����device idУ��signʧ��(������֤�����)

#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX              100900
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_DECRYPT_FAIL       (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 0)    ///< ����secretkey����ƽ̨����ʧ��
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_OVERFLOW_WINDOWS   (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 1)    ///< ����secretkey�����ڴ�����
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_NO_USER            (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 2)    ///< �豸δ���û�
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_SN_NOT_EXIST       (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 3)    ///< �豸������
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_AGAIN              (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 4)    ///< �豸�ظ�����

#define DEV_COM_ERROR_EZDEVSDK_DAS_INDEX                    101000
#define DEV_COM_ERROR_EZDEVSDK_DAS_NOSUPPORT_PROTOCOL_VER   (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 1)  ///< ��֧�ֵ�Э��汾
#define DEV_COM_ERROR_EZDEVSDK_DAS_CLIENT_ID_INVALID        (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 2)  ///< ���ϸ�Ŀͻ��˱�ʶ��
#define DEV_COM_ERROR_EZDEVSDK_DAS_SERVER_UNUSABLE          (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 3)  ///< ����˲�����(�������ڲ��쳣)
#define DEV_COM_ERROR_EZDEVSDK_DAS_INVALID_USERNAME         (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 4)  ///< ��Ч���û��������루�ֽ׶��ݲ�ʹ�ã�
#define DEV_COM_ERROR_EZDEVSDK_DAS_UNAUTHORIZED             (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 5)  ///< δ��Ȩ���ֽ׶��ݲ�ʹ�ã�
#define DEV_COM_ERROR_EZDEVSDK_DAS_SESSION_INVAILD          (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 6)  ///< ����ỰʧЧ
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_OFFLINE            (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 7)  ///< �豸��ǿ������
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_DEV_RISK           (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 8)  ///< �豸����أ���������
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_DOMAIN_RISK        (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 9)  ///< ���򱻷��
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_CMD_RISK           (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 10) ///< ָ����

/*******************ȫ�ִ����� end**********************/

/************************************************************************/
/*                        ���ع����������                              */
/************************************************************************/
typedef struct tagNET_EBASE_ABILITY_CFG
{
    HPR_UINT32 dwSize;          //[in]�ṹ���С
    HPR_UINT32 dwClientCnt;     //[in]��Ϊ�ͻ��ˣ�֧��ͬʱ����������Ĭ��Ϊ1��
    HPR_UINT32 dwAlarmCnt;      //[in]ͬʱ֧�ּ�·������Ĭ�ϲ�����
}NET_EBASE_ABILITY_CFG, *LPNET_EBASE_ABILITY_CFG;

typedef struct tagNET_EBASE_ABILITY_CFG_EX
{
    HPR_UINT32 dwSize;
    HPR_UINT32 dwClientCnt;
    HPR_UINT32 dwAlarmCnt;
    HPR_UINT32 dwLFCnt;
    HPR_UINT8  byRes[128];
}NET_EBASE_ABILITY_CFG_EX;

typedef void (CALLBACK *LogFunc)(HPR_UINT32 dwLevel, char const *pBuffer, HPR_VOIDPTR pUserData);
typedef struct tagNET_EBASE_LOGINFO
{
    HPR_UINT32  dwSize;         //[in]�ṹ���С
    HPR_UINT32  dwLevel;        //[in]��־�ĵȼ���Ĭ��Ϊ0����0-��ʾ�ر���־��1-��ʾֻ���ERROR������־��2-���ERROR������Ϣ��DEBUG������Ϣ��3-���ERROR������Ϣ��DEBUG������Ϣ��INFO��ͨ��Ϣ��������Ϣ
    LogFunc     fnLogFunc;      //[in]��־�ص�����
    HPR_VOIDPTR pUserData;      //[in]�û���Ϣ
}NET_EBASE_LOGINFO, *LPNET_EBASE_LOGINFO;

typedef struct tagNET_EBASE_TIMEOUT
{
    HPR_UINT32 dwConnectTimeOut;    //���ӳ�ʱ��Ĭ��3500ms��֮���Բ���3000ms������Ϊ3000ms�Ǻܶ�ϵͳconnect��һ��������ʱ�򣬶��500ms���൱�ڸ���һ�������Ļ���
    HPR_UINT32 dwSendTimeOut;       //���ͳ�ʱ��Ĭ��5000ms
    HPR_UINT32 dwRecvTimeOut;       //���ճ�ʱ��Ĭ��5000ms
}NET_EBASE_TIMEOUT, LPNET_EBASE_TIMEOUT;

typedef enum enumNET_EBASE_PARAM_TYPE
{
    EBASE_PARAM_UNKNOWN = -1,       //�������ͣ���ʵ�ʺ���
    EBASE_PARAM_LOCAL_IP = 0,       //����IP��ַ��ʹ����NET_EBASE_GetParam����Ӧ�ṹ��NET_EBASE_IPINFO
    EBASE_PARAM_ALIVE_INTERVAL= 1,  //�������ӱ������������ʹ����NET_EBASE_SetParam�������������HPR_UINT32����λms
    EBASE_PARAM_SESSION_INFO = 2,    //��ȡSessionKey��ʹ����NET_EBASE_GetParam����Ӧ�ṹ��NET_EBASE_SESSION_INFO
    EBASE_PARAM_CURINGDATA_CB = 3,       //����secretKey�ص��ӿڣ����������޲�����֤����豸������өʯ��ʱʹ�ã�ʹ��NET_EBASE_SetParam����Ӧ�ṹ��NET_EBASE_IOT_CURINGDATA_CB
    EBASE_PARAM_COMPRESS = 4,           //�����Ƿ�������ѹ�� ѹ���㷨��0-��ʾ��ѹ����1-��ʾ֧��gzipѹ���� ����HPR_UINT8
    EBASE_PARAM_MSG_SIZE = 5,           //�û��Զ����շ�������Ϣ����󳤶ȣ�ѹ��ǰ��,����HPR_UINT16����λkb��   ȡֵ��Χ0-255(������Χ����)��0��ʾ256kb(Ĭ��)    1-255��ʾ1kb-255kb
    EBASE_PARAM_LOAD_THIRD_PARTY = 6,  //[only OTAP]����өʯ��ƽ̨ʹ�ã�͸��ISAPIЭ�飬SDKĬ�ϼ��أ��û������ò�����,��Ӧ�ṹ��ΪHPR_UINT8, 0-�����أ�1-����
    EBASE_PARAM_ALARM_SUBSCRIBE_RULE_WORKING_MODE = 7, //[only OTAP]��Ӧ�ṹ��ΪHPR_UINT8, Ĭ�϶��Ĺ������豸ʵ�֣��Ա����ͻ�����Ч�� 0-�豸����ʵ�ֶ��Ĺ���1-SDK��ʵ�ֶ��Ĺ���
    EBASE_PARAM_ALARM_SUBSCRIBE_RULE = 8,        //[only OTAP]���ñ������Ĺ��򣻶Ա����ͻ�����Ч���ο�ö��ֵ7��������0-�豸����ʵ�ֶ��Ĺ���ʱ���������øò�����1-SDKʵ�ֶ��Ĺ���ʱ����δ���øò���������ȫ�����ˣ���ͨ���ò��������˶��Ĺ���SDK�����õĶ��Ĺ�������ϱ�����Ӧ�ṹ��NET_EBASE_ALARM_SUBSCRIBE_RULE_LIST
    EBASE_PARAM_ALARM_SWITCH = 9,         //[only OTAP]����өʯ��ƽ̨ʹ�ã����ñ�������,Ĭ���ǿ������Ա����ͻ�����Ч����Ӧ�ṹ��ΪHPR_UINT8��0-�رձ����ϱ���1-���������ϱ�
}NET_EBASE_PARAM_TYPE;

#define EHOME_IP_LEN 64 //IPv4��IPv6��ַ�����ַ�����ʾ��64���ֽ��Ѿ��㹻
#define EHOME_IP_LEN_MAX 256 //IPv4��IPv6��ַ�����ַ�����ʾ��64���ֽ��Ѿ��㹻,�����������256

typedef struct tagNET_EBASE_IPINFO
{
    HPR_UINT8  szIP[EHOME_IP_LEN/*64*/];//IP��ַ��֧��IPv4��IPv6,�����Խ���������
    HPR_UINT16 wPort;                   //�˿ں�
    HPR_UINT8  byRes[2];                //�ֽڶ���
}NET_EBASE_IPINFO, *LPNET_EBASE_IPINFO;

#define EHOME_SESSION_KEY_LEN 16 //SessionLey���ȣ�16���ֽ�
typedef struct tagNET_EBASE_SESSION_INFO
{
    HPR_UINT8  szSessionKey[EHOME_SESSION_KEY_LEN/*16*/];//SessionLey
    HPR_UINT32 dwSequence;//���кţ�ʹ��ʱ��Ҫ��1
    HPR_SOCK_T iSocket;//ͨ��socket
    HPR_UINT8  byRes[32];                //�����ֽ�
}NET_EBASE_SESSION_INFO, *LPNET_EBASE_SESSION_INFO;

typedef enum enumNET_EBASE_LOCALCFG_TYPE
{
    EBASE_LOCALCFG_UNKNOWN = -1,        //�������ͣ���ʵ�ʺ���
    EBASE_LOCALCFG_CLIENT_IPINFO = 0,   //OTAP:֧�ְ�IP��ַ�Ͷ˿ڣ�ʹ��NET_EBASE_SetIOTLocalCfg��ISUP5.0��֧�ְ�IP��ַ��ʹ��NET_EBASE_SetLocalCfg����Ӧ�ṹ��NET_EBASE_IPINFO�������ڿͻ�������
                                        //��֧��������ʽ��
    EBASE_LOCALCFG_THREAD_SIZE = 1,     //Ĭ���߳�ջ��С��ʹ����NET_EBASE_SetLocalCfg/NET_EBASE_SetIOTLocalCfg����ӦpParamΪHPR_UINT32*��������SDK�����߳��ƶ����߳�ջ��С����λΪB
}NET_EBASE_LOCALCFG_TYPE;

#define MAX_ALARM_SUBSCRIBE_EVENT_TYPE_LEN 128
#define MAX_ALARM_SUBSCRIBE_FILEPATH_TYPE_LEN 256
#define MAX_ALARM_SUBSCRIBE_CHANNELS_LEN 1024
#define MAX_ALARM_SUBSCRIBE_IOLIST_LEN 256

#define ALARM_SUBSCRIBE_ALL_EVENT_TYPE "all"
#define ALARM_SUBSCRIBE_ALL_FILEPATH_TYPE "all"
#define ALARM_SUBSCRIBE_ALL_CHANNELS_TYPE "all"
#define ALARM_SUBSCRIBE_ALL_IOLIST_TYPE "all"
typedef struct tagNET_EBASE_ALARM_SUBSCRIBE_RULE_NODE
{
    HPR_UINT8   byAlarmType[MAX_ALARM_SUBSCRIBE_EVENT_TYPE_LEN];         //�¼����ͣ���1������ȫ���¼�����ʱ������ΪALARM_SUBSCRIBE_ALL_EVENT_TYPE��2������һ���¼�����
    HPR_UINT8   byFilePathType[MAX_ALARM_SUBSCRIBE_FILEPATH_TYPE_LEN];   //ͼƬ�ϴ���ʽ,��1������ȫ��ʱ������ΪALARM_SUBSCRIBE_ALL_FILEPATH_TYPE��2������ͼƬ�ϴ���ʽ�����ж��֣�ÿ�ַ�ʽ�Զ��Ž�β����ϳ��ַ���
    HPR_UINT8   byChannels[MAX_ALARM_SUBSCRIBE_CHANNELS_LEN];            //����ͨ��,��1������ȫ��ʱ������ΪALARM_SUBSCRIBE_ALL_CHANNELS_TYPE��2������ͨ�������ж����ÿ��ͨ�����Զ��Ž�β����ϳ��ַ���
    HPR_UINT8   byIOList[MAX_ALARM_SUBSCRIBE_IOLIST_LEN];                //����IOͨ��,��1������ȫ��ʱ������ΪALARM_SUBSCRIBE_ALL_IOLIST_TYPE��2������IOͨ�������ж����ÿ��ͨ�����Զ��Ž�β����ϳ��ַ���
    HPR_UINT8   byRes[128];              
}NET_EBASE_ALARM_SUBSCRIBE_RULE_NODE, *LPNET_EBASE_ALARM_SUBSCRIBE_RULE_NODE;

typedef struct tagNET_EBASE_ALARM_SUBSCRIBE_RULE_LIST
{
    NET_EBASE_ALARM_SUBSCRIBE_RULE_NODE *pList;
    HPR_UINT32 dwListNum;
    HPR_UINT8  byRes[256];                //�����ֽ�
}NET_EBASE_ALARM_SUBSCRIBE_RULE_LIST, *LPNET_EBASE_ALARM_SUBSCRIBE_RULE_LIST;

/************************************************************************/
/*                          ע���������                                */
/************************************************************************/
typedef enum enumEBaseDataType
{
    DATETYPE_UNKNOW     = -1,       //δ֪����,           ClassType(pData) = NULL
    DATETYPE_EXPECTION  = 0,        //�����쳣,           ClassType(pData) = HPR_UINT32 *,��ʾ������

    //������������������
    DATETYPE_ISAPI                = 1,        //���յ����������    ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATETYPE_EZVIZ                = 2,        //���յ��ķ������Ӧ  ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATETYPE_EHOME                = 3,        //����EHome2.0/4.0�ķ��������  ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATETYPE_HTTP                 = 4,        //���յ������HTTP���� ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATETYPE_VOICESTART           = 5,        //�����Խ���ʼ ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATETYPE_VOICESTOP            = 6,        //�����Խ����� ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PREVIEWSTART         = 7,        //Ԥ����ʼ ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PREVIEWSTOP          = 8,        //Ԥ������ ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PLAYBACKSTART        = 9,        //�طſ�ʼ ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PLAYBACKSTOP         = 10,       //�طŽ��� ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PUBLISHACK           = 11,       //���յ�����˶�Ӧ��ϢID��ȷ����Ӧ ClassType(pData) = HPR_UINT32 *,��ʾ��ϢID
    DATATYPE_PREVIEWMAKEIFRAME    = 12,       //Ԥ��ǿ��I֡ ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PLAYBACKPAUSE        = 13,       //�ط���ͣ ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PLAYBACKRESTART      = 14,       //�طŻָ� ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_DEVICE_WAKEUP        = 15,       //�����豸 ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PLAYBACKREFAST       = 16,       //�طſ�� ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_PLAYBACKRESLOW       = 17,       //�طſ�� ClassType(pData) = LPNET_EBASE_SERVER_DATA
    DATATYPE_ALARMRECONNECT       = 18,       //��������
    DATATYPE_ALARMRECONNECTSUCCESS = 19,      //���������ɹ�
    DATATYPE_RCVLFDATA = 20,              //�����ļ��ڲ�ʹ��

    //�ָ���
    DATATYPE_SEPARATOR       = 100,      //��ʵ�����壬Ϊ�ָ���

    //�ͻ����������������
    DATATYPE_ALARM           = 101,      //���ͱ�������
    DATATYPE_EZVIZNOTICE     = 102,      //өʯЭ���������͸�����˵�publish��ĿǰEHomeSDK����ʶ/1100/12345,/30000/1
    DATATYPE_SENDLFDATA = 103,           //�����ļ��ڲ�ʹ��
    DATATYPE_SENDLFSESSION = 104,       //�����ļ��ڲ�sessionʹ��

    //�豸SDK�ص����豸APP��״̬
    DATATYPE_CONN_SUCC = 200,           //�豸�첽��ʽע��ɹ���Ŀǰֻ֧��IOTЭ�飬ClassType(pData) = LPNET_IOT_CONN_SUCC_INFO
    DATATYPE_RECONN_SUCC = 201,         //�豸�����ɹ���Ŀǰֻ֧��IOTЭ��

    //������������Э�����������ͨ���ϵ�����
    DATATYPE_IOT_KERNEL_READY = 1008,   //SDK�ں�׼����ɣ� ClassType(pData) = LPNET_EBASE_IOT_KERNEL_READY_INFO
    DATATYPE_IOT_RUNTIME_ERROR = 1009,  //�豸SDK����ʱ���󣬴�״̬������ʾ�豸���ߣ� ClassType(pData) = HPR_UINT32 *,��ʾ������
    DATATYPE_IOT = 1100,                //���յ���������󣬰������ԺͲ��� ClassType(pData) = LPNET_EBASE_SERVER_DATA

    //�ָ���
    DATATYPE_IOT_SEPARATOR = 1200,      //��ʵ�����壬Ϊ�ָ���

    //������Э��ͻ����������������
    DATATYPE_IOT_ALARM = 1201,          //���ͱ�������
    DATATYPE_IOT_NOTICE = 1202,         //�豸�������͸�����˵�publish
    DATATYPE_IOT_ISAPI_ALARM = 1203     //͸��ISAPI�ı���
}EBaseDataType;

#define MAX_DEVICE_ID_LEN_V50      256 //�豸ID����
#define FIRMWARE_VER_LEN           24  //�̼��汾
#define MAX_COMPLETE_SERIAL_LEN    64  //���кų���
#define MAX_SERIAL_LEN             12  //����ų���
#define MAX_FIRMWARE_LEN           12  //�豸�̼�����
#define MAX_FIRMWARE_LEN_OTAP         64 //�豸�̼�����
#define MAX_DEVNAME_LEN            64  //�豸���Ƴ���
#define MAX_EHOME50_KEY_LEN        32  //��Կ����
#define MAX_ADD_LEN                256 //��ַ����
#define MAX_VOICETALK_TOKEN_LEN    256 //Token����

#define MAX_IP_LEN                 64 //���IP����

//������Э��
#define MAX_IOT_CLIENT_SESSION     256
#define MAX_IOT_PATH_LEN            128 //�ļ�·������
#define MAX_IOT_DOMAIN_ID_LEN       64
#define MAX_IOT_RESOURCE_ID_LEN     64
#define MAX_IOT_RESOURCE_TYPE_LEN   64
#define MAX_IOT_IDENTIFIER_LEN      64
#define MAX_IOT_MODULE_LEN     64
#define MAX_IOT_METHOD_LEN          64
#define MAX_IOT_MSG_TYPE_LEN        32
#define MAX_IOT_CHILDID_LEN         64
#define MAX_IOT_SERIAL_LEN          72
#define MAX_IOT_BUSINESS_TYPE_LEN   64
#define MAX_IOT_EZACCESS_REGISTERURL_LEN   128
#define MAX_IOT_EZACCESS_TOKEN_LEN   64
#define MAX_DAS_SERVER_ID_LEN       64
#define MAX_SESSION_KEY_LEN         16

#define MAX_LF_SESSION_ID_LEN         128 //LF sessionid����

#define MAX_DEV_TYPE_LEN      256 //�豸���ͳ���
#define MAX_DEV_TYPE_DISPLAY_LEN      256 //�豸��ʾ���ͳ���
#define MAX_DEV_MAC_LEN      256 //�豸���������ַ

// #define version_max_len               32     ///< �汾����
// #define ezdev_sdk_extend_name_len     32     ///< ��չģ�����ֳ���
// #define ezdev_sdk_ip_max_len          64     ///< ip�����
// #define ezdev_sdk_timezone_max_len    32     ///< timezone�����
// #define ezdev_sdk_sessionkey_len      16     ///< �豸�Ự��Կ���ȣ�Ĭ����16���ֽ�
// #define ezdev_sdk_devid_len           32     ///< �豸Ψһ��ʶ����  Ĭ����32�ֽڵ��ַ���
// #define ezdev_sdk_masterkey_len       16     ///< �豸mastekey���� ,Ĭ����16���ֽ�
// #define ezdev_sdk_verify_code_maxlen  48     ///< �豸��֤��֧����󳤶�(��Ӧlicence��֤��product_key)

typedef void (CALLBACK *EBaseClientFunc)(HPR_INT32 dwHandle, EBaseDataType dwType, HPR_UINT32 dwLen, HPR_VOIDPTR pData, HPR_VOIDPTR pUserData);
typedef struct tagNET_EBASE_REGINFO
{
    HPR_UINT32  dwSize;
    HPR_UINT32  dwDevType;                                       //[in]�豸����
    HPR_UINT32  dwState;                                         //[in]�豸����״̬��1:��������ģʽ��5������������˯�ߣ�ģʽ
    HPR_UINT8   byDeviceSerial[MAX_COMPLETE_SERIAL_LEN/*64*/];   //[in]�豸���кţ��豸�ͺ�+����+�����+��չ
    HPR_UINT8   bySubSerial[MAX_SERIAL_LEN/*12*/];               //[in]�豸�����,�������к�
    HPR_UINT8   byDevName[MAX_DEVNAME_LEN/*64*/];                //[in]�豸����
    HPR_UINT8   byDeviceID[MAX_DEVICE_ID_LEN_V50/*256*/];        //[in]EHomeЭ���е�DeviceID
    HPR_UINT8   byShareKey[MAX_EHOME50_KEY_LEN/*32*/];           //[in]sharekey���ȣ�Ҫ���豸���洢EHomeKey�����Ǵ�sharekey:md5(md5(md5(SHA256(EHomeKey)+ deviceID)+www.88075998.com))  
    HPR_UINT8   byFirmwareVer[MAX_FIRMWARE_LEN/*12*/];           //[in]�豸�̼��汾
    HPR_UINT8   byServerAdd[MAX_ADD_LEN/*256*/];                 //[in]����˵�ַ��֧��IPv4��IPv6������
    HPR_UINT16  wServerPort;                                     //[in]����˶˿�
    //�豸֧�ֵĹ��������֧��"��"������֧��"��"���������ҵ���
    //��һλΪ1��ʾ֧��NPQԤ��(0b00000001)��
    //�ڶ�λΪ1��ʾ֧��NPQ�ط�(0b00000010)��
    //����λΪ1��ʾ֧��Ԥ�����طź������Խ���·���ܴ���(0b00000100)
    //����λΪ1��ʾ֧��HLS�ط�(0b00001000)
    //����λΪ1��ʾ֧�������Խ���·���㲥���䡪��ֻ��������������������(0b00010000)
    HPR_UINT8   bySupport;
    HPR_UINT8   byRes;                                           //[Res]�����������ֽڶ���
    EBaseClientFunc fnCB;                                        //[in]���յ������ݻص�
    HPR_VOIDPTR pUserData;                                       //[in]�û�����
}NET_EBASE_REGINFO, *LPNET_EBASE_REGINFO;

//ע��Э������
typedef enum enumEBaseRegisterMode
{
    REGISTER_PLATFORM_ISUP = 0,  //��ISUP5.0Э�����ISUPƽ̨
    REGISTER_PLATFORM_IOT = 1,   //��OTAPЭ�����өʯ��ƽ̨
    REGISTER_PLATFORM_OTAP = 2,  //��OTAPЭ�����˽�л�����ƽ̨
}EBaseRegisterMode;


/**
* \brief ��ȡ��������
*/
typedef enum enumEBaseIoTKeyValueType
{
    KEYVALUE_DEVICE_ID,         ///<	�豸Ψһ��ʶ  �״��豸���ߺ����� һ��Ҫд��flash
    KEYVALUE_MASTER_KEY,        ///<	�豸masterkey �״��豸���ߺ����� ����д��flash
    KEYVALUE_COUNT			    ///<	��ö������
}EBaseIoTKeyValueType;

typedef enum enumEBaseIoTCurringType
{
    CURINGDATA_SECRETKEY,           ///<	��֤�벻�Ϲ��豸���������secretkey��һ��Ҫ�̻�
    CURINGDATA_COUNT                   ///<	��ö������
}EBaseIoTCurringType;

//���������ص����������������ΪNET_EBASE_ConnectToIOTServer�ӿ��еĽṹ��NET_EBASE_IOT_REGINFO�е�pUserData
typedef void (CALLBACK *EBaseKeyValueFunc)(HPR_INT32 dwHandle, EBaseIoTKeyValueType dwKeyValueType, unsigned char* pData, HPR_UINT32 dwLen, HPR_VOIDPTR pUserData);
typedef void (CALLBACK *EBaseCuringFunc)(HPR_INT32 dwHandle, EBaseIoTCurringType dwKeyValueType, unsigned char* pData, HPR_UINT32 dwLen, HPR_VOIDPTR pUserData);

typedef struct tagNET_EBASE_IOT_REGINFO_EXTEND
{
    HPR_UINT8   byDevType[MAX_DEV_TYPE_LEN];                      //[in] [only OTAP] NET_EBASE_IOT_REGINFO��byDevInfoType=1ʱ����豸��ʵ�ͺţ������豸��̬ģ�ͱ���ʹ��
    HPR_UINT8   byDevTypeDisplay[MAX_DEV_TYPE_DISPLAY_LEN];       //[in] [only OTAP] NET_EBASE_IOT_REGINFO��byDevInfoType=1ʱ����豸��ʾ�ͺţ������ڽ�����ʾ�豸�ͺ�
    HPR_UINT8   byMAC[MAX_DEV_MAC_LEN];                           //[in] [only OTAP] NET_EBASE_IOT_REGINFO��byDevInfoType=1ʱ����豸���������ַ
    HPR_UINT8   byFirmwareVer[MAX_FIRMWARE_LEN_OTAP/*64*/];           //[in][only OTAP] NET_EBASE_IOT_REGINFO��byDevInfoType=1ʱ���� �豸�̼��汾
    HPR_UINT8   byRes[512];
}NET_EBASE_IOT_REGINFO_EXTEND;

typedef struct tagNET_EBASE_IOT_KERNEL_READY_INFO
{
    HPR_VOIDPTR pKernelPtr;
    HPR_UINT8   byRes[128];
}NET_EBASE_IOT_KERNEL_READY_INFO, *LPNET_EBASE_IOT_KERNEL_READY_INFO;

typedef struct tagNET_EBASE_IOT_REGINFO
{
    HPR_UINT32  dwSize;
    HPR_UINT32  dwDevType;                                       //[in] [only ISUP5.0] ���� �豸����
    HPR_UINT32  dwState;                                         //[in] [OTAP/ISUP5.0] OTAP��������δ�á�ISUP5.0:����豸����״̬��1:��������ģʽ��5������������˯�ߣ�ģʽ��������Ŀǰ��Ч��ʵ�ʰ�����������ģʽ��
    HPR_UINT8   byDeviceSerial[MAX_COMPLETE_SERIAL_LEN/*64*/];   //[in] [OTAP/ISUP5.0] OTAP��byDevInfoType=1ʱ���ISUP5.0:����豸���кţ��豸�ͺ�+����+�����+��չ��
    HPR_UINT8   bySubSerial[MAX_SERIAL_LEN/*12*/];               //[in] [only ISUP5.0] ���� �豸�����,�������к�
    HPR_UINT8   byDevName[MAX_DEVNAME_LEN/*64*/];                //[in] [OTAP/ISUP5.0] OTAP��������δ�á�ISUP5.0:����豸����
    HPR_UINT8   byDeviceID[MAX_DEVICE_ID_LEN_V50/*256*/];        //[in] [OTAP/ISUP5.0] OTAP:byDevInfoType=1ʱ����������豸����Ż�Ψһ���ֵ���֧��72�ֽڡ�ISUP5.0������豸ID��
    HPR_UINT8   byShareKey[MAX_EHOME50_KEY_LEN/*32*/];           //[in] [OTAP/ISUP5.0] �����豸Ҫ���ܴ洢OTAP dev_verification_code��isup5.0 EHomeKey�����Ǵ�sharekey��
                                                                                       //OTAP byDevInfoType=1ʱ���� sharekey�㷨: pdkdf2_SHA256(md5(md5(md5(dev_verification_code + dev_subserial) + www.88075998.com)))�����:otap_generate_sharekey
                                                                                       //ISUP5.0 ���� sharekey�㷨:��md5(md5(md5(SHA256(EHomeKey)+ deviceID)+www.88075998.com))�������generate_sharekey
    HPR_UINT8   byFirmwareVer[MAX_FIRMWARE_LEN/*12*/];           //[in] [only ISUP5.0] ISUP5.0:����豸�̼��汾��
    HPR_UINT8   byServerAdd[MAX_ADD_LEN/*256*/];                 //[in] [OTAP/ISUP5.0] �������˵�ַ��֧��IPv4��IPv6������
    HPR_UINT16  wServerPort;                                     //[in] [OTAP/ISUP5.0] �������˶˿ڣ�
    HPR_UINT8   byAsynConnect;                                   //[in] [only OTAP]    ����첽ע�ᣬ0-ͬ�����ӿڷ��سɹ���ʾע��ɹ�����1-�첽���ص�ע��ɹ���
    HPR_UINT8   byKeyValueMethod;                                //[in] [only OTAP]    ���ƽ̨DevID��MasterKey�洢��ʽ
                                                                                       //ֵΪ0-dev_id��masterkeyͨ���ļ���ʽ��ȡ����Ӧ�ֶ�byDevIDFile��byMasterKeyFile,
                                                                                       //ֵΪ1-ͨ���ص��ķ�ʽ��ȡ����Ӧ�ֶ�fnCBKeyValueLoad��fnCBKeyValueSave
    EBaseClientFunc fnCB;                                        //[out][OTAP/ISUP5.0] ����������ݻص�����
    HPR_VOIDPTR pUserData;                                       //[in] [OTAP/ISUP5.0] ��ѡ���û�����
    HPR_UINT8   byDevInfoFile[MAX_IOT_PATH_LEN/*128*/];          //[in] [only OTAP]    �豸��Ϣ�ļ�·����byDevInfoType=0����
    HPR_UINT8   byMasterKeyFile[MAX_IOT_PATH_LEN/*128*/];        //[in] [only OTAP]    masterkey�ļ�·����byKeyValueMethod =0ʱ����
    HPR_UINT8   byDevIDFile[MAX_IOT_PATH_LEN/*128*/];            //[in] [only OTAP]    ƽ̨dev_id�ļ�·����byKeyValueMethod =0ʱ����
    EBaseKeyValueFunc fnCBKeyValueLoad;                          //[in] [only OTAP]    SDKͨ���ûص���ȡdev_id��masterkey��byKeyValueMethod =1ʱ����
    EBaseKeyValueFunc fnCBKeyValueSave;                          //[out][only OTAP]    SDKͨ���ûص���dev_id��masterkey���û���byKeyValueMethod =1ʱ����
    HPR_UINT8   byDevInfoType;                                   //[in] [only OTAP]    ���� 1-�豸��Ϣͨ���ṹ�巽ʽ����SDK������ʹ�ô��ַ�ʽ���ļ���ʽ�豣����֤��dev_verification_code�������ϰ�ȫҪ�󣬴��ַ�ʽ���������֤�뾭��ժҪ�㷨�������byShareKey��������㷽ʽ�ο�byShareKey�ֶ�˵����
                                                                                       //   0-�豸��Ϣͨ���ļ���ʽ����SDK�����ַ�ʽ����������byDeviceSerial��byDeviceID��byShareKey��byFirmwareVer��pExDevInfo����Щ��Ϣ���ļ��ж��룬�ļ������ݸ�ʽ�ο�/Bin/Linux64/fileDepens/dev_info��
    HPR_UINT8   bySupport;                                       //[in] [only ISUP5.0] ��ѡ �豸֧�ֵĹ��������֧��"��"������֧��"��"���������ҵ���
                                                                                       //��һλΪ1��ʾ֧��NPQԤ��(0b00000001)��
                                                                                       //�ڶ�λΪ1��ʾ֧��NPQ�ط�(0b00000010)��
                                                                                       //����λΪ1��ʾ֧��Ԥ�����طź������Խ���·���ܴ���(0b00000100)
                                                                                       //����λΪ1��ʾ֧��HLS�ط�(0b00001000)
    HPR_UINT8   byAESIV[17];                                                           
    HPR_VOIDPTR pExDevInfo;                                      //[in] [only OTAP]    byDevInfoType=1ʱ����,ָ��ָ��ṹ��NET_EBASE_IOT_REGINFO_EXTEND
    HPR_UINT8   byRes[489];                                      //[Res]�����������ֽڶ���
}NET_EBASE_IOT_REGINFO, *LPNET_EBASE_IOT_REGINFO;

typedef struct tagNET_EALARM_IOT_REGINFO
{
    HPR_UINT32  dwSize;                                          //[in] [OTAP/ISUP5.0] �Ǳ���ṹ���С
    HPR_UINT8   byDeviceSerial[MAX_COMPLETE_SERIAL_LEN/*64*/];   //[in] [only ISUP5.0] ����豸���кţ��豸�ͺ�+����+�����+��չ
    HPR_UINT8   bySubSerial[MAX_SERIAL_LEN/*12*/];               //[in] [only ISUP5.0] ����豸�����,�������к�
    HPR_UINT8   byDevName[MAX_DEVNAME_LEN/*64*/];                //[in] [only ISUP5.0] ����豸����
    HPR_UINT8   byDeviceID[MAX_DEVICE_ID_LEN_V50/*256*/];        //[in] [only ISUP5.0] ���EHomeЭ���е�DeviceID
    HPR_UINT8   byFirmwareVer[MAX_FIRMWARE_LEN/*12*/];           //[in] [only ISUP5.0] ����豸�̼��汾
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN/*64*/];     //[in] [only OTAP]  �����Դid
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN/*64*/]; //[in] [only OTAP]  �����Դ����
    HPR_UINT8   byDomainID[MAX_IOT_DOMAIN_ID_LEN/*64*/];         //[in] [only OTAP]  �����Ϣ����id
    HPR_UINT8   byIdentifier[MAX_IOT_IDENTIFIER_LEN/*64*/];      //[in] [only OTAP]  ���ҵ���ʶ��OTAPƽ̨ע��ģʽ֧��
    HPR_UINT8   byServerAdd[MAX_ADD_LEN/*256*/];                 //[in] [OTAP/ISUP5.0] ֧��IPv4��IPv6��OTAP:�������Ӹñ�������˵�ַ����Ϊ�գ�����SDK�ڲ���ȡƽ̨�·��ĵ�ַ����ƽ̨δ�·���������ע����·��ISUP5.0:����
    HPR_UINT16  wServerPort;                                     //[in] [OTAP/ISUP5.0] ͬ��byServerAdd
    HPR_UINT8   byProtocolType;                                  //[out] [only OTAP]  �Ǳ���,��������Э�飬0-tcp
    HPR_UINT8   byRes1[3];
    EBaseClientFunc fnCB;                                        //[in] [OTAP/ISUP5.0] ������ݻص�����
    HPR_VOIDPTR pUserData;                                       //[in] [OTAP/ISUP5.0] �Ǳ���û�����
    HPR_UINT32  dwkeepAliveSec;                                  //[out][only OTAP] �Ǳ���,mqtt�������
    HPR_UINT8   byAESIV[17];                                     //[out][only OTAP] �Ǳ���
    HPR_UINT8   byRes[235];
}NET_EALARM_IOT_REGINFO, *LPNET_EALARM_IOT_REGINFO;

/***********************�豸SDK���豸Ӧ�ò�ص������� Start *********************************/
//NET_EBASE_ConnectToIOTServer
typedef struct tagNET_EBASE_SERVER_DATA
{
    HPR_UINT32      dwSize;         //[out]�ṹ�峤��
    HPR_UINT32      dwSequence;     //[out]���кţ��豸����Ӧ������ʱ���轫���ֵԭֵ���ø��ӿ�
    HPR_VOIDPTR     pCmdIdentify;   //[out][readonly]�����ڻص�֮��ʹ�ø�ָ�� 
                                    //      (1)��enumEBaseDataType == DATETYPE_ISAPI || enumEBaseDataType == DATETYPE_HTTP��Ϊurl
                                    //      (2)��enumEBaseDataType == DATETYPE_EHOMEʱ��ΪEHome�����е�<CommandType>ֵ
                                    //      (3)��enumEBaseDataType == DATATYPE_EZVIZ��Ϊөʯ�����topic����ǰEHomeSDK�ᷢ�͵�topic��/1100/10305���豸��Ӧ����Ӧ/1100/10306�����EHomeЭ���ĵ����������ܣ�
                                    //      (4)��enumEBaseDataType == DATATYPE_IOT��Ϊ������Э���topic��ָ��һ��NET_IOT_SERVER_COMMAND�ṹ��
    HPR_UINT32      dwBodyLen;      //[out]�����峤��
    HPR_VOIDPTR     pDodyData;      //[out][readonly]���������ݣ������ڻص�֮��ʹ�ø�ָ��
}NET_EBASE_SERVER_DATA, *LPNET_EBASE_SERVER_DATA;

//ģ������
typedef enum enumIotModuleType
{
    MODULE_TYPE_MODEL = 0,      //model
    MODULE_TYPE_OTA = 1,        //����OTA
    MODULE_TYPE_STRORAGE = 2,   //�洢
    MODULE_TYPE_UNKNOWN = 0XFF,    //��������ģ�飬ͨ���ַ���ƥ��ķ�ʽ�����������µ�ö�٣����NET_IOT_SERVER_COMMAND��NET_IOT_CLIENT_COMMAND�ֶ�byModule
}IotModuleType;

//Modelģ���еķ���
typedef enum enumIotModelMethod
{
    MODEL_METHOD_EVENT = 0,     //�¼����豸�ϱ�
    MODEL_METHOD_ATTRIBUTE = 1, //���ԣ��豸��ƽ̨��������������
    MODEL_METHOD_SERVICE = 2,   //�������豸��ƽ̨��������������
}IotModelMethod;

//OTAģ���еķ���
typedef enum enumIotOTAMethod
{
    OTA_METHOD_INFORM = 0,      //�̼��汾��Ϣ���豸��ƽ̨��������������
    OTA_METHOD_UPGRADE = 1,     //�̼�����֪ͨ��ƽ̨�·����豸
    OTA_METHOD_PROGRESS = 2,    //�̼��������ȣ��豸�ϱ�
}IotOTAMethod;

//STRORAGEģ���еķ���
typedef enum enumIotStorageMethod
{
    STOR_METHOD_UPLOAD_URL = 0,     //�洢�ϴ���ַ���豸��ƽ̨��ȡ
    STOR_METHOD_UPLOAD_RESULT = 1,  //�洢�ϴ�������豸�ϱ�
    STOR_METHOD_DOWNLOAD_URL = 2,   //�洢���ص�ַ���豸��ƽ̨��ȡ
}IotStorageMethod;

typedef struct tagNET_IOT_SERVER_COMMAND
{
    HPR_UINT32  dwSize;                                     //[out]�ṹ�峤��
    HPR_UINT16  wModuleType;                                //[out]�û���өʯ�Ʒ���Լ����ģ���ʶ,����:model��ģ�ͣ���ota����������storage���洢���ȣ�ֵΪenumIotModuleType
    HPR_UINT16  wMethod;                                    //[out]ģ���µķ���
                                                            //      (1)��wModuleType = MODULE_TYPE_MODEL�������У�event���¼�����attribute�����ԣ���service����������ֵΪenumIotModelMethod
                                                            //      (2)��wModuleType = MODULE_TYPE_OTA�������У�inform��upgrade��progress��ֵΪenumIotOTAMethod
                                                            //      (3)��wModuleType = MODULE_TYPE_STRORAGE�������У�upload/url��upload/result��download/url��ֵΪenumIotStorageMethod
    //HPR_UINT16  wStorageID;
    HPR_UINT16  wBusinessType;                              //[out]ҵ������
    HPR_UINT8   byRes1[2];                                  //[Res]�����������ֽڶ���
    HPR_UINT8   bySubSerial[MAX_IOT_SERIAL_LEN];            //[out]���豸���кţ�topic��$CHILDID�ֶ�
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[out]��Դid��topic��$LOCALINDEX�ֶ�
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[out]��Դ���ͣ�topic��$RESOURCETYPE�ֶ�
    HPR_UINT8   byDomainID[MAX_IOT_DOMAIN_ID_LEN];          //[out]��Ϣ����id, "model"��{DOMAIN}�ֶ�,����ģ����������
    HPR_UINT8   byIdentifier[MAX_IOT_IDENTIFIER_LEN];       //[out]ҵ���ʶ��"model"��{IDENTIFIER}�ֶ�,����ģ����������
    HPR_UINT8   byModule[MAX_IOT_MODULE_LEN];               //[out]ģ��,��ǰ��"model" "ota" "storage" "EZVIZAccess" "childmanage"
    HPR_UINT8   byMethod[MAX_IOT_METHOD_LEN];               //[out]������topic��module��byMsgType֮��Ĳ���
    HPR_UINT8   byMsgType[MAX_IOT_MSG_TYPE_LEN];            //[inout]��Ϣ����"operate" "set" "get" "report" "query" "set_reply" "get_reply" "operate_reply" "report_reply" "query_reply"��
    HPR_UINT32  dwmMulIndex;                                //[out]������������
    HPR_UINT8   byRes2[348];                                //[Res]�����������ֽڶ���
}NET_IOT_SERVER_COMMAND, *LPNET_IOT_SERVER_COMMAND;


typedef struct tagNET_IOT_CONN_SUCC_INFO
{
    HPR_UINT32  dwSize;                                 //[out]�ṹ�峤��
    HPR_UINT16  wDasTcpPort;                            //[out]das��������TCP�˿ں�
    HPR_UINT16  wDasUdpPort;                            //[out]das������UDP�˿ں�
    char        szDasIP[MAX_IP_LEN];                    //[out]das������IP
    char        szLbsIP[MAX_IP_LEN];                    //[out]lbs������IP
    HPR_UINT8   bySessionKey[MAX_SESSION_KEY_LEN];      //[out]�Ự��Կ
    HPR_INT32   iDasSocket;                             //[out]das��socket
    char        szDasDomain[MAX_ADD_LEN];               //[out]das������
    char        szDasServerID[MAX_DAS_SERVER_ID_LEN];   //[out]das��serverid
} NET_IOT_CONN_SUCC_INFO, *LPNET_IOT_CONN_SUCC_INFO;
/***********************�豸SDK���豸Ӧ�ò�ص������� End *********************************/


/***********************�豸Ӧ�ò����ø�SDK������ Start *********************************/
//NET_EBASE_Reponse
typedef struct tagNET_EBASE_CLIENT_DATA
{
    HPR_UINT32      dwSize;         //[in]�ṹ�峤�ȣ�δ����չʹ��
    EBaseDataType   dwDataType;     //[in]�������ͣ���enumEBaseDataType���壬�����������е�dwDataType����һ��
    HPR_UINT32      dwSequence;     //[in]���кţ������������е�dwSequence����һ�£����������Ӧ����˵�������0����
    HPR_VOIDPTR     pCommandType;   //[in][readonly]�����͸��豸����������
                                    //      (1)��enumEBaseDataType == DATETYPE_EHOMEʱ��Ч�������������е�pCommandType����һ��
                                    //      (2)��enumEBaseDataType == DATATYPE_EZVIZNOTICE��Ӧ������өʯ��Э�飬��д��Ӧ��topic��ĿǰEHiomeSDK��ʶ���topic��/1100/10306��/1100/12345,/30000/1
                                    //      (3)��enumEBaseDataType == DATATYPE_IOT��ΪNET_IOT_CLIENT_COMMAND
    HPR_UINT32      dwBodyLen;      //[in]�����峤��
    HPR_VOIDPTR     pBodyData;      //[in][readonly]����������
    HPR_UINT32      dwID;           //[out]��ϢID
}NET_EBASE_CLIENT_DATA, *LPNET_EBASE_CLIENT_DATA;

typedef struct tagNET_IOT_CLIENT_COMMAND
{
    HPR_UINT32  dwSize;                                     //[in]�ṹ�峤�ȣ�δ����չʹ��
    HPR_UINT16  wModuleType;                                //[in]�û���өʯ�Ʒ���Լ����ģ���ʶ,����:model��ģ�ͣ�/ota��������/basic/storage���洢���ȣ�ֵΪenumIotModuleType
    HPR_UINT16  wMethod;                                    //[in]ģ���µķ���
                                                            //      (1)��wModuleType = MODULE_TYPE_MODEL�������У�event���¼�����attribute�����ԣ���service����������ֵΪenumIotModelMethod
                                                            //      (2)��wModuleType = MODULE_TYPE_OTA�������У�inform��upgrade��progress��ֵΪenumIotOTAMethod
                                                            //      (3)��wModuleType = MODULE_TYPE_STRORAGE�������У�upload/url��upload/result��download/url��ֵΪenumIotStorageMethod
    //HPR_UINT16  wStorageID;
    HPR_UINT16  wBusinessType;                              //[in]ҵ������
                                                            //  (1)���ӿ�ΪNET_EBASE_Reponse��wMethodΪ�豸����ʱ��0-set��ƽ̨���豸�������ԣ���1-get��ƽ̨���豸��ȡ���ԣ�
                                                            //  (2)�������Ŀǰֵ��Ϊ0
                                                            //  �����ӿ�ΪNET_EBASE_Reponseʱ�����豸SDK�ص����豸Ӧ�ò�����NET_IOT_SERVER_COMMAND�е�wBusinessTypeֵһ��
                                                            //  ���ӿ�ΪNET_EBASE_SendPublish/NET_EALARM_SendIOTAlarmʱ��������ֵΪ0
    HPR_UINT8   byRes1[2];                                  //[Res]�����������ֽڶ���
    HPR_UINT8   bySubSerial[MAX_IOT_SERIAL_LEN];            //[in]���豸���к�, �����Դ���豸�����ò���Ϊ"global"
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[in]��Դid
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[in]��Դ����
    HPR_UINT8   byDomainID[MAX_IOT_DOMAIN_ID_LEN];          //[in]��Ϣ����id
    HPR_UINT8   byIdentifier[MAX_IOT_IDENTIFIER_LEN];       //[in]ҵ���ʶ
    HPR_UINT8   byModule[MAX_IOT_MODULE_LEN];           //[in]����:model��ģ�ͣ�/ota��������/basic/storage���洢��
    HPR_UINT8   byMethod[MAX_IOT_METHOD_LEN];           //[in]
    HPR_UINT8   byMsgType[MAX_IOT_MSG_TYPE_LEN];            //[inout]��Ϣ����"operate" "set" "get" "report" "query" "set_reply" "get_reply" "operate_reply" "report_reply" "query_reply"��
    HPR_UINT32  dwmMulIndex;                                //[in]������������,(1)�豸��Ӧƽ̨��Ϣʱ������NET_IOT_SERVER_COMMAND��dwmMulIndex����2���豸��������Ϣʱ����0;
    HPR_UINT8   byRes2[348];                                //[Res]�����������ֽڶ���
}NET_IOT_CLIENT_COMMAND, *LPNET_IOT_CLIENT_COMMAND;
/***********************�豸Ӧ�ò��������������� End *********************************/



/************************************************************************/
/*                            ���ؽӿ�                                  */
/************************************************************************/

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_Init(LPNET_EBASE_ABILITY_CFG lpStruAbility)
 *  @brief  ��ʼ����
 *  @param (in)	LPNET_EBASE_ABILITY_CFG lpStruAbility    
 *  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_Init(LPNET_EBASE_ABILITY_CFG lpStruAbility);

NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_InitEx(NET_EBASE_ABILITY_CFG_EX* lpStruAbilityEx);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_Cleanup()
 *  @brief ����ʼ����
 *  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_Fini();
/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SetLogInfo(LPNET_EBASE_LOGINFO lpLogInfo)
 *  @brief  ������־��Ϣ
 *  @param (in)	LPNET_EBASE_LOGINFO lpLogInfo    
 *  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_SetLogInfo(LPNET_EBASE_LOGINFO lpLogInfo);
/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_GetBuildVersion()
*  @brief ��ȡ�汾��
*  @return	HPR_UINT32 �汾��
*/
NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_GetBuildVersion();
/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_GetLastError()
 *  @brief ��ȡ������
 *  @return HPR_UINT32 ������ֵ��0���޴�������ֵΪ������
 */
NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_GetLastError();

/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_SetLocalCfg(HPR_UINT32 dwType, HPR_VOIDPTR pParam)
 *  @brief �������ã�ȫ������
 *  @param (in)	HPR_UINT32 dwType���ο�����NET_EBASE_LOCALCFG_TYPE 
 *  @param (in)	HPR_VOIDPTR pParam
 *  @return	NET_COM_API HPR_UINT32 CALLBACK
 */
NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SetLocalCfg(HPR_UINT32 dwType, HPR_VOIDPTR pParam);


/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_SetIOTLocalCfg(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR pParam)
*  @brief ��������,��Ե����豸
*  @param (in)	HPR_UINT32 dwType���ο�����NET_EBASE_LOCALCFG_TYPE
*  @param (in)	HPR_VOIDPTR pParam
*  @return	NET_COM_API HPR_UINT32 CALLBACK
*/
NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SetIOTLocalCfg(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR pParam);

/************************************************************************/
/*                            ���ܽӿ�                                  */
/************************************************************************/
/** @fn	NET_COM_API HPR_INT32 CALLBACK NET_EBASE_CreateClient()
 *  @brief  ����һ��EHome�ͻ���
 *  @return	HPR_INT32  ������ͻ��˱�ʶ
 */
NET_COM_API HPR_INT32  CALLBACK NET_EBASE_CreateClient();


/************************************************************************/
/*                            ���ܽӿ�                                  */
/************************************************************************/
/** @fn	NET_COM_API HPR_INT32 CALLBACK NET_EBASE_CreateIOTClient(HPR_UINT32 dwClientType)
*  @brief  ����һ��IOT�ͻ��ˣ�����NET_EBASE_CreateClient
*  @param (in)	HPR_UINT32 dwClientType��
                    ��ӦEBaseRegisterMode��
                    REGISTER_PLATFORM_ISUP��ʾ����NET_EBASE_CreateClient����ģʽ���Դ������ISUP�ͻ��ˣ���NET_EBASE_Init�������ֵ��Ĭ��һ��
                    REGISTER_PLATFORM_IOT����ģʽ����IOT�ͻ��ˣ�����өʯ��ƽ̨
                    REGISTER_PLATFORM_OTAP����ģʽ����IOT�ͻ��ˣ����뺣��˽��ƽ̨
*  @return	HPR_INT32  ������ͻ��˱�ʶ����0��ʼ����һ��������һ���ͻ��˶�Ӧһ���豸
*/
NET_COM_API HPR_INT32  CALLBACK NET_EBASE_CreateIOTClient(HPR_UINT32 dwClientType);


/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_ConnectToServer(HPR_INT32 dwHandle, LPNET_EBASE_REGINFO lpStruRegInfo)
 *  @brief  �����������
 *  @param (in)	HPR_INT32 dwHandle    
 *  @param (in)	LPNET_EBASE_REGINFO lpRegInfo    
 *  @return HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_ConnectToServer(HPR_INT32 iHandle, LPNET_EBASE_REGINFO lpRegInfo);


/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_ConnectToIOTServer(HPR_INT32 dwHandle, LPNET_EBASE_IOT_REGINFO lpStruRegInfo)
*  @brief  ����������ˣ�����NET_EBASE_ConnectToServer
*  @param (in)	HPR_INT32 dwHandleΪNET_EBASE_CreateIOTClient()����ֵ
*  @param (in)	LPNET_EBASE_IOT_REGINFO lpIOTRegInfo
*  @return HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_ConnectToIOTServer(HPR_INT32 iHandle, LPNET_EBASE_IOT_REGINFO lpIOTRegInfo);


/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_DeystoryClient(HPR_INT32 dwHandle)
 *  @brief  ����Ehome�ͻ���
 *  @param (in)	HPR_INT32 dwHandle    
 *  @return HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_DeystoryClient(HPR_INT32 iHandle);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SetParam(HPR_UINT32 dwHandle, HPR_UINT32 dwType, HPR_VOIDPTR lpParam)
 *  @brief ���ò�������������������,өʯIOTЭ�鲻֧���豸�˱����������������EBASE_PARAM_ALIVE_INTERVAL��
 *  @param (in)	HPR_INT32 dwHandle   NET_EBASE_CreateClient���صľ�� 
 *  @param (in)	HPR_UINT32 dwType     ����
 *  @param (in)	HPR_VOIDPTR lpParam   ����
 *  @param (in)	HPR_UINT32 dwSize     ����
 *  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_SetParam(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR lpParam, HPR_UINT32 dwSize);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_GetParam(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR lpParam)
 *  @brief ��ȡ����,өʯIOTЭ�鲻֧���豸�˱��ػ�ȡ�豸�����ַ��EBASE_PARAM_LOCAL_IP��
 *  @param (in)	HPR_INT32 iHandle   NET_EBASE_CreateClient���صľ�� 
 *  @param (in)	HPR_UINT32 dwType   ��Ҫ��ȡ�Ĳ������� 
 *  @param (in)	HPR_VOIDPTR lpParam ��ȡ�������ؽ��   
 *  @param (in)	HPR_UINT32 dwSize   lpParamָ��Ľṹ�峤̬��
 *  @return	NET_COM_API HPR_BOOL CALLBACK HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_GetParam(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR lpParam, HPR_UINT32 dwSize);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_Reponse(HPR_UINT32 dwHandle, LPNET_EBASE_CLIENT_DATA lpClientData)
 *  @brief ��Ӧ���������
 *  @param (in)	HPR_INT32 dwHandle    �����NET_EBASE_CreateClient����ֵ
 *  @param (in)	LPNET_EBASE_CLIENT_DATA lpClientData   ����Ӧ������ 
 *  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_Reponse(HPR_INT32 iHandle, LPNET_EBASE_CLIENT_DATA lpClientData);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_CheckHTTPSession(HPR_INT32 iHandle, char const * lpSession,HPR_UINT32 dwLen)
*  @brief У��HTTP session
*  @param (in)	HPR_INT32 dwHandle    �����NET_EBASE_CreateClient����ֵ
*  @param (in)	char const * lpSession   ��У�������
*  @param (in)	HPR_UINT32 dwLen   ��У�����ݵĳ���
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_CheckHTTPSession(HPR_INT32 iHandle, char const * lpSession,HPR_UINT32 dwLen);


/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SendPublish(HPR_INT32 iHandle, LPNET_EBASE_CLIENT_DATA lpClientData)
 *  @brief �ڷ���Ӧ��������󣬲��Ҳ���Ҫ�������Ӧ������£����ڷ���publish�Ľӿ�
 *  @param (in)	HPR_INT32 iHandle    
 *  @param (in)	LPNET_EBASE_CLIENT_DATA lpClientData    
 *  @return	NET_COM_API HPR_BOOL CALLBACK
 */
NET_COM_API HPR_BOOL   CALLBACK NET_EBASE_SendPublish(HPR_INT32 iHandle, LPNET_EBASE_CLIENT_DATA lpClientData);


#define MAX_OTAP_ERROR_MSG_LEN 256

typedef struct tagNET_EBASE_OTAP_ERROR_INFO
{
    HPR_UINT32  dwSize;                             //[out]�ṹ�峤��
    HPR_UINT32  dwStatusCode;                       //[out]����������
    HPR_UINT8   szErrorMsg[MAX_OTAP_ERROR_MSG_LEN]; //[out]����������,��ErrorNo��Ӧ
    HPR_UINT8   byRes[128];
}NET_EBASE_OTAP_ERROR_INFO, *LPNET_EBASE_OTAP_ERROR_INFO;


/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_GetOTAPErrorMsg(HPR_UINT32 dwErrorNo, LPNET_EBASE_OTAP_ERROR_INFO lpStruErrorInfo)
*  @brief ����Э�������ת��Ϊ������Ϣ(���������� + ����������)
*  @param (in)	HPR_UINT32 dwErrorNo
*  @param (out)	LPNET_EBASE_OTAP_ERROR_INFO lpStruErrorInfo
*  @return	NET_COM_API HPR_BOOL CALLBACK
*/
NET_COM_API HPR_BOOL CALLBACK NET_EBASE_GetOTAPErrorMsg(HPR_UINT32 dwErrorNo, LPNET_EBASE_OTAP_ERROR_INFO lpStruErrorInfo);

/** @fn	typedef HPR_BOOL(CALLBACK *OTAPGetErrMsgFun)(HPR_UINT32 dwErrorNo, LPNET_EBASE_OTAP_ERROR_INFO lpStruErrorInfo, HPR_VOIDPTR pUserData);
*  @brief ����Э�������ת��Ϊ������Ϣ�ص�����(���������� + ����������)
*  @param (out)	HPR_UINT32 dwErrorNo
*  @param (in)	LPNET_EBASE_OTAP_ERROR_INFO lpStruErrorInfo
*  @param (out)	HPR_VOIDPTR pUserData
*  @return	NET_COM_API HPR_BOOL CALLBACK
*/
typedef HPR_BOOL(CALLBACK *OTAPGetErrMsgFun)(HPR_UINT32 dwErrorNo, LPNET_EBASE_OTAP_ERROR_INFO lpStruErrorInfo, HPR_VOIDPTR pUserData);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SetOTAPErrorMsgCB(OTAPGetErrMsgFun pGetErrMsgCB, HPR_VOIDPTR pUserData);
*  @brief ��������Э�������ת��Ϊ������Ϣ�ص����������ú���ʹ�ÿ��е�ת����ͨ���ص��������û���ȡ������Ϣ
*  @param (in)	OTAPGetErrMsgFun pGetErrMsgCB �ص�����
*  @param (in)	HPR_VOIDPTR pUserData  �û�����
*  @return	NET_COM_API HPR_BOOL CALLBACK
*/
NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SetOTAPErrorMsgCB(OTAPGetErrMsgFun pGetErrMsgCB, HPR_VOIDPTR pUserData);


typedef struct tagNET_EBASE_OBERSER
{
    HPR_UINT8   szModule[MAX_IOT_MODULE_LEN];            //ģ��
    HPR_UINT8   szDomain[MAX_IOT_DOMAIN_ID_LEN];         //�������ͣ�����ģ��������ԡ���1����szDomainΪ�գ���ʾע������ģ�飬��2����szDomain��Ϊ�գ���ע�����ģ�������Ŀǰֻ��modelģ��ʹ�ñ�����
    HPR_UINT8   byIdentifier[MAX_IOT_IDENTIFIER_LEN];    //[in]ҵ���ܱ�ʶ
    EBaseClientFunc fnCB;
    HPR_VOIDPTR pUserData;
}NET_EBASE_OBERSER, *LPNET_EBASE_OBERSER;

typedef struct tagNET_EBASE_REMOVE_OBERSER
{
    HPR_UINT8   szModule[MAX_IOT_MODULE_LEN];       //ģ��
    HPR_UINT8   szDomain[MAX_IOT_DOMAIN_ID_LEN];    //�������ͣ�����ģ��������ԡ���1����szDomainΪ�գ���ʾע������ģ�飬��2����szDomain��Ϊ�գ���ע�����ģ�������Ŀǰֻ��modelģ��ʹ�ñ�����
    HPR_UINT8   byIdentifier[MAX_IOT_IDENTIFIER_LEN];    //[in]ҵ���ܱ�ʶ
}NET_EBASE_REMOVE_OBERSER, *LPNET_EBASE_REMOVE_OBERSER;


NET_COM_API HPR_INT32   CALLBACK NET_EBASE_SetMessageCallBack(LPNET_EBASE_OBERSER lpMsgInfo);
NET_COM_API HPR_INT32   CALLBACK NET_EBASE_RemoveMsgCallBack(LPNET_EBASE_REMOVE_OBERSER lpMsgInfo);


/************************************************************************/
/*                            �����ӿ�                                  */
/************************************************************************/
#define ALARM_SEND_SUCCESS 0
#define ALARM_IS_FILTERED  1
#define ALARM_SWITCH_CLOSE  2

typedef struct tagNET_EALARM_AlARMINFO
{
    HPR_UINT32  dwSize;         //[in]�ṹ�峤��
    HPR_UINT32  dwAlarmLen;     //[in]������Ϣ����
    HPR_VOIDPTR pAlarmInfo;     //[in]������Ϣ
    HPR_UINT32  dwAlarmID;      //[out]����ID
}NET_EALARM_AlARMINFO, *LPNET_EALARM_AlARMINFO;

typedef struct tagNET_EALARM_IOT_AlARMINFO
{
    HPR_UINT32  dwSize;             //[in]�ṹ�峤��
    HPR_UINT32  dwAlarmLen;         //[in]������Ϣ����
    HPR_VOIDPTR pAlarmInfo;         //[in]������Ϣ
    HPR_UINT32  dwAlarmID;          //[out]����ID
    NET_IOT_CLIENT_COMMAND struCmd; //[in]��byIsISAPIDataΪ0��struCmdΪ����topic��Ϣ,��byIsISAPIDataΪ1����͸��ISAPI���ģ�struCmdΪ��
    HPR_UINT8   byIsISAPIData;      //[in]�Ƿ���ISAPIЭ�鱨�ģ�0-��1-��
    HPR_UINT8   byResult;           //[out]���ͽ��������SDKʹ�ܶ��Ĺ�����Ч��1.ALARM_SEND_SUCCESS-���ͳɹ���2.ALARM_IS_FILTERED-δ���ĸ����ͱ����������ˡ�3.ALARM_SWITCH_CLOSE-өʯ�������ش��ڹر�״̬
    HPR_UINT8   byRes[510];         //[Res]�����������ֽڶ���
}NET_EALARM_IOT_AlARMINFO, *LPNET_EALARM_IOT_AlARMINFO;


/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EALARM_CreateClient(LPNET_EBASE_REGINFO lpRegInfo)
 *  @brief  ���������ͻ���
 *  @param (in) iLoginHandle ����NET_EBASE_CreateClient�����ľ��
 *  @param (in)	LPNET_EBASE_REGINFO lpRegInfo ����EHome�����������
 *  @return	HPR_INT32  -1��ʾʧ�ܣ�����ֵ��ʾ���
 */
NET_COM_API HPR_INT32 CALLBACK NET_EALARM_CreateClient(HPR_INT32 iLoginHandle, LPNET_EBASE_REGINFO lpRegInfo);

/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EALARM_CreateIOTClient(LPNET_EBASE_REGINFO lpRegInfo)
*  @brief  ���������ͻ���
*  @param (in) iLoginHandle ����NET_EBASE_CreateClient�����ľ��
*  @param (in)	LPNET_EBASE_REGINFO lpRegInfo ����EHome�����������
*  @return	HPR_INT32  -1��ʾʧ�ܣ�����ֵ��ʾ���
*/
NET_COM_API HPR_INT32 CALLBACK NET_EALARM_CreateIOTClient(HPR_INT32 iLoginHandle, LPNET_EALARM_IOT_REGINFO lpRegInfo);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EALARM_DestroyClient(HPR_INT32 dwHandle)
 *  @brief ���ٱ����ͻ���
 *  @param (in)	HPR_INT32 dwHandle  NET_EALARM_CreateClient����ֵ
 *  @return HPR_BOOL  HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL CALLBACK NET_EALARM_DestroyClient(HPR_INT32 iHandle);
/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EALARM_SendAlarm(HPR_INT32 dwHandle, LPNET_EALARM_AlARMINFO lpAlarmInfo)
 *  @brief ���ͱ�����Ϣ
 *  @param (in)	HPR_INT32 dwHandle NET_EALARM_CreateClient����ֵ   
 *  @param (in)	LPNET_EALARM_AlARMINFO lpAlarmInfo  ������Ϣ  
 *  @return HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL CALLBACK NET_EALARM_SendAlarm(HPR_INT32 iHandle, LPNET_EALARM_AlARMINFO lpAlarmInfo);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_EALARM_SendAlarm(HPR_INT32 dwHandle, LPNET_EALARM_AlARMINFO lpAlarmInfo)
*  @brief ���ͱ�����Ϣ������NET_EALARM_SendAlarm
*  @param (in)	HPR_INT32 dwHandle NET_EALARM_CreateClient����ֵ
*  @param (in)	LPNET_EALARM_IOT_AlARMINFO lpAlarmInfo  ������Ϣ
*  @return HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL CALLBACK NET_EALARM_SendIOTAlarm(HPR_INT32 iHandle, LPNET_EALARM_IOT_AlARMINFO lpAlarmInfo);

/************************************************************************/
/*                            ����өʯƽ̨������ӽӿ�                                  */
/************************************************************************/
//pData��Ӧ�ṹ��NET_EBASE_IOT_MSG
typedef HPR_VOID(CALLBACK *EBaseEZAccessCB)(HPR_INT32 dwHandle, HPR_VOIDPTR pData, HPR_VOIDPTR pUserData);

typedef struct tagNET_EBASE_EZACCESS_REG
{
    EBaseEZAccessCB fnCB;
    HPR_VOIDPTR pUserData;
    HPR_UINT8   byRes[256];                                //[Res]�����������ֽڶ���
}NET_EBASE_EZACCESS_REG;

//pBuf ��Ӧ�ṹ��
//GetDeviceToken query NET_EBASE_IOT_EZACCESS_GET_DEV_TOKEN_REQ
//GetDeviceToken query_reply NET_EBASE_IOT_EZACCESS_GET_DEV_TOKEN_RSP
typedef struct tagNET_EBASE_IOT_MSG
{
    HPR_UINT8   byModule[MAX_IOT_MODULE_LEN];           //[in]
    HPR_UINT8   byChildID[MAX_IOT_CHILDID_LEN];              //[inout]���豸���к�, �����Դ���豸���������������Ҫ��д
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[inout]��Դid
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[inout]��Դ����
    HPR_UINT8   byMethod[MAX_IOT_METHOD_LEN];               //[inout]��չ���ݣ�����"model"�е� "domainid/identifier"�ֶ�
    HPR_UINT8   byMsgType[MAX_IOT_MSG_TYPE_LEN];            //[inout]��Ϣ����"operate" "set" "get" "report" "query" "set_reply" "get_reply" "operate_reply" "report_reply" "query_reply"��
    HPR_UINT32  dwID;                                       //[inout]��ϢID
    HPR_UINT32  dwLen;
    char        *pBuf;                                     //�ɾ����ҵ���Ӧ��Ӧ�Ľṹ��
    HPR_UINT8   byRes[512];                                //[Res]�����������ֽڶ���
}NET_EBASE_IOT_MSG, *LPNET_EBASE_IOT_MSG;

typedef enum NET_EBASE_IOT_EZACCESS_EXPIRE_TYPE
{
    ENUM_PARAM_PERMANENT = 0,       //������Ч,token 16λ
    ENUM_PARAM_ONE_DAY = 1,         //24Сʱ��Ч,token 6λ
    ENUM_PARAM_THIRTY_DAY = 2,      //30����Ч,token 8λ
    ENUM_PARAM_NINETY_DAY = 3,      //90����Ч,token 12λ
}NET_EBASE_IOT_EZACCESS_EXPIRE_TYPE;

typedef struct tagNET_EBASE_IOT_EZACCESS_GET_DEV_TOKEN_REQ
{
    HPR_BOOL    bForce;                                      //[in]ǿ��ˢ�� ��Ĭ�� false��
    HPR_UINT32  dwExpire;                                    //[in]�μ�ö��NET_EBASE_IOT_EZACCESS_EXPIRE_TYPE
    HPR_UINT8   byRes[128];                                  //[Res]�����������ֽڶ���
}NET_EBASE_IOT_EZACCESS_GET_DEV_TOKEN_REQ;

typedef struct tagNET_EBASE_IOT_EZACCESS_GET_DEV_TOKEN_RSP
{
    HPR_UINT32  dwError;                                             //[out]0��ʾ�ɹ�
    HPR_UINT8   byRegisterUrl[MAX_IOT_EZACCESS_REGISTERURL_LEN];     //[out]
    HPR_UINT8   byToken[MAX_IOT_EZACCESS_TOKEN_LEN];                 //[out]
    HPR_UINT8   byRes[128];                                          //[Res]�����������ֽڶ���
}NET_EBASE_IOT_EZACCESS_GET_DEV_TOKEN_RSP;


typedef struct tagNET_EBASE_IOT_EZACCESS_TOKEN_BIND_REQ
{
    HPR_UINT8   byToken[MAX_IOT_EZACCESS_TOKEN_LEN];         //[in]����token
    HPR_UINT8   byRes[128];                                  //[Res]�����������ֽڶ���
}NET_EBASE_IOT_EZACCESS_TOKEN_BIND_REQ;

typedef struct tagNET_EBASE_IOT_EZACCESS_TOUCH_BIND_REQ
{
    HPR_UINT8   byToken[MAX_IOT_EZACCESS_TOKEN_LEN];         //[in]����token
    HPR_UINT8   byRes[128];                                  //[Res]�����������ֽڶ���
}NET_EBASE_IOT_EZACCESS_TOUCH_BIND_REQ;

typedef struct tagNET_EBASE_IOT_CURINGDATA_CB
{
    EBaseCuringFunc fnCBCuringDataLoad;                         //[in]�û�ͨ���ûص��ӿڽ�secretKey����SDK��IOTģʽ��Ч
    EBaseCuringFunc fnCBCuringDataSave;                         //[in]SDKͨ���ûص��ӿڽ�secretKey�ص����û����û��轫secretKey�̻����κ�����¾����ܶ�ʧ�������޷��ٽ���өʯ��ƽ̨��IOTģʽ��Ч
}NET_EBASE_IOT_CURINGDATA_CB, *LPNET_EBASE_IOT_CURINGDATA_CB;

NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SetEZVIZAccessMsgCB(NET_EBASE_EZACCESS_REG *pInfo);
NET_COM_API HPR_BOOL CALLBACK NET_EBASE_RemoveEZVIZAccessMsgCB();

NET_COM_API HPR_BOOL CALLBACK NET_EBASE_RegisterEZVIZAccess(HPR_INT32 iLoginHandle);
//�ݲ�֧��ע����өʯ΢�ں˲�֧�֣���ʵ��ʹ��Ӱ���С��
//NET_COM_API HPR_BOOL CALLBACK NET_EBASE_UnRegisterEZVIZAccess(HPR_INT32 iLoginHandle);

NET_COM_API HPR_BOOL CALLBACK NET_EBASE_SendEZVIZAccessMsg(HPR_INT32 iLoginHandle, LPNET_EBASE_IOT_MSG lpMsgInfo);


/************************************************************************/
/*                            ���ļ�����ӿ�                                  */
/************************************************************************/
#define MAX_LF_SEND_BUF_LEN        4 * 1024 * 1024    // ���ļ����η��͵����buffer���� 4M


typedef enum enumLFCallBackType
{
    TYPE_LF_UNKNOW = 0,                //δ֪����,               ClassType(pData) = NULL
    TYPE_LF_EXCEPTION = 1,             //�����쳣,               ClassType(pOutBuffer) = HPR_UINT32 *,��ʾ������
    TYPE_LF_UPLOAD_URL = 2,            //���ļ��ϴ�URL           ClassType(pOutBuffer) = NET_ISUP_BASE_LF_UPLOAD_URL_INFO ����bufΪURL
    TYPE_LF_UPLOAD_DATA = 3,           //���ļ��ϴ�              ClassType(pOutBuffer) = NET_ISUP_BASE_LF_UPLOAD_DATA_INFO ����bufΪ�ļ�����
    TYPE_LF_UPLOAD_END = 4,            //���ļ��ϴ��ɹ�           ClassType(pOutBuffer) = HPR_UINT32 * , ����sequence�� ClassType(pInBuffer) = NET_ISUP_BASE_LF_UPLOAD_END_INFO  
    TYPE_LF_DOWNLOAD_URL = 5,          //���ļ�����URL            ClassType(pOutBuffer) = NET_ISUP_BASE_LF_DOWNLOAD_CB_INFO
}NET_ISUP_BASE_LF_CALLBACK_TYPE;

/*��enumTypeΪ�������ͣ�����μ�NET_ISUP_BASE_LF_CALLBACK_TYPE */
typedef HPR_VOID(CALLBACK *LF_Func)(HPR_INT32 iHandle, NET_ISUP_BASE_LF_CALLBACK_TYPE enumType, HPR_VOIDPTR pOutBuffer, HPR_UINT32 dwOutLen, HPR_VOIDPTR pInBuffer, HPR_UINT32* dwInLen, HPR_VOIDPTR pUserData);

typedef struct tagNET_ISUP_BASE_LF_UPLOAD_URL_INFO
{
    void*                     pFileId;     //[out] �ϴ����ļ�fileid
    HPR_UINT32                dwFileIdLen; //[out] �ϴ�fileid��
    HPR_UINT32                dwSequence;  //[out] �ϴ���sequence �����Ƿ��ж�ͬһ���ļ�
    HPR_BOOL                  bResume;     //[out] �ϵ��������
    HPR_UINT32                dwStart;     //[out] ��bResume = True, �ϵ���������Ŀ�ʼλ�ã����ֽ���
    HPR_UINT32                dwEnd;       //[out] ��bResume = True, �ϵ���������Ľ���λ�ã����ֽ���
    HPR_UINT8                 byRes[128];
}NET_ISUP_BASE_LF_UPLOAD_URL_INFO, *LPNET_ISUP_BASE_LF_UPLOAD_URL_INFO;

typedef struct tagNET_ISUP_BASE_LF_UPLOAD_DATA_INFO
{
    void*                    pBuf;       //[out] �ϴ���Ӧ����
    HPR_UINT32               dwBufLen;   //[out] buf����
    HPR_UINT32               dwSequence; //[out] �ϴ��ļ���ʶsequence
    HPR_UINT8                byRes[124];
}NET_ISUP_BASE_LF_UPLOAD_DATA_INFO;


typedef struct tagNET_ISUP_BASE_LF_UPLOAD_END_INFO
{
    HPR_UINT32               dwResult;      //[in]  �ϴ����
    HPR_VOIDPTR              pUrl;          //[in]  �ϴ��ɹ�֮�󷵻ص�URL
    HPR_UINT32               dwUrlLen;      //[in]  URL����
    HPR_UINT8                byRes[124];
}NET_ISUP_BASE_LF_UPLOAD_END_INFO; //��pInBufferָ��Ľṹ��


typedef struct tagNET_ISUP_BASE_LF_DOWNLOAD_CB_INFO
{
    void*                     pUrl;       //[out] �������ص��ļ� uri
    HPR_UINT32                dwUrlLen;   //[out] uri����
    HPR_UINT32                dwSequence; //[out] ���ص�sequence 
    HPR_BOOL                  bResume;    //[out] �ϵ��������
    HPR_UINT32                dwStart;    //[out] ��bResume = True, �ϵ���������Ŀ�ʼλ�ã����ֽ���
    HPR_UINT32                dwEnd;      //[out] ��bResume = True, �ϵ���������Ľ���λ�ã����ֽ���
    HPR_UINT8                 byRes[128];
}NET_ISUP_BASE_LF_DOWNLOAD_CB_INFO;


typedef enum enumNET_ISUP_BASE_LF_BUSINESS_TYPE
{
    LF_SEND_DOWNLOAD_RSP_DATA = 0,    //���ط�����,��Ӧ���νṹ�� NET_ISUP_BASE_LF_SEND_DATA
    LF_SEND_DOWNLOAD_RSP_RESULT = 1,  //���ؽ���� ��Ӧ���νṹ�� NET_ISUP_BASE_LF_SEND_RESULT
}NET_ISUP_BASE_LF_BUSINESS_TYPE;

#define TAG_LF_TRANS_START 0x01  //��ʼ��ǣ�Ԥ�����ò�����
#define TAG_LF_TRANS_END   0x10  //�������, ���һ������ʱ������bufferһ����
#define TAG_LF_TRANS_DATA  0x00  //���ݴ�����

//���ļ�������

#define RESULT_LF_SUCCESS           0 //�ɹ�
#define RESULT_LF_UNKNOW_EXCEPTION     1 //δ֪�쳣
#define RESULT_LF_FILE_SIZE_LIMIT       2 //�ļ���С����
#define RESULT_LF_INVALID_FILE        3 //�Ƿ��ļ�
#define RESULT_LF_DEVICE_RESOURCE_ERROR       4  //�豸�ռ䲻��
#define RESULT_LF_FILE_NOT_FOUND       5 // �ļ�������
#define RESULT_LF_RESUME_POSITION_ERROR       6 //�ϵ�����λ�ô���
#define RESULT_LF_CALLBACK_PARAM_ERROR     7  //�ص���������
#define RESULT_LF_TRANS_CHANNEL_BUSY      8 // ͨ��æµ
#define RESULT_LF_TRANS_CHANNEL_NOT_FOUND     9 //ͨ��������
#define RESULT_LF_TRANS_CHANNEL_NOT_ESTABLISH   10 //ͨ��δ����
#define RESULT_LF_TRANS_READ_DATA_ERROR     11//��ȡ����ʧ��
#define RESULT_LF_TRANS_SEND_DATA_ERROR     12 //��������ʧ��


typedef struct tagNET_ISUP_BASE_LF_SEND_DATA
{
    void*                    pbuf;           //[in] �����ļ�����
    HPR_UINT32               dwbufLen;       //[in] buf���ȣ���������ж�ʵ�ʽ��յĳ���
    HPR_UINT32               dwSequence;     //[in] �û����ɻ���������URL��sequence����ͬһ��sequence����ͬһ���ļ�          
    HPR_UINT8                byTransStage;   //[in] �ļ������־ 0x010 �������  0x001 ��ʼ���(��ʵ����Ҫ) 0x000 ���ݴ���
    HPR_UINT8                byRes[127];
}NET_ISUP_BASE_LF_SEND_DATA, *LPNET_ISUP_BASE_LF_SEND_DATA;


typedef struct tagNET_ISUP_BASE_LF_SEND_RESULT
{
    HPR_UINT32               dwResult;  // [in] ���ļ�������ʱ ���� result = 6
    HPR_UINT32               dwSequence; //[in] �û����ɻ���������URL��sequence����ͬһ��sequence����ͬһ���ļ� 
    HPR_UINT8                byRes[128];
}NET_ISUP_BASE_LF_SEND_RESULT, *LPNET_ISUP_BASE_LF_SEND_RESULT;



typedef struct tagNET_ISUP_BASE_LFINFO
{
    HPR_UINT32  dwSize;
    HPR_UINT8   byDeviceSerial[MAX_COMPLETE_SERIAL_LEN/*64*/];   //[in]�豸���кţ��豸�ͺ�+����+�����+��չ
    HPR_UINT8   bySubSerial[MAX_SERIAL_LEN/*12*/];               //[in]�豸�����,�������к�
    HPR_UINT8   byDevName[MAX_DEVNAME_LEN/*64*/];                //[in]�豸����
    HPR_UINT8   byDeviceID[MAX_DEVICE_ID_LEN_V50/*256*/];        //[in]EHomeЭ���е�DeviceID
    HPR_UINT8   byShareKey[MAX_EHOME50_KEY_LEN/*32*/];           //[in]sharekey���ȣ�Ҫ���豸���洢EHomeKey�����Ǵ�sharekey:md5(md5(md5(SHA256(EHomeKey)+ deviceID)+www.88075998.com))  
    HPR_UINT8   byFirmwareVer[MAX_FIRMWARE_LEN/*12*/];           //[in]�豸�̼��汾
    HPR_UINT8   byServerAdd[MAX_ADD_LEN/*256*/];                 //[in]����˵�ַ��֧��IPv4��IPv6������
    HPR_UINT8   bySessionId[MAX_LF_SESSION_ID_LEN/*128*/];          //[in]CMS�·���sessionid
    HPR_UINT16  wServerPort;                                     //[in]����˶˿�
    HPR_UINT8   byRes1[2];                                       //[Res]�����������ֽڶ���
    LF_Func     fnCB;                                            //[in]���յ������ݻص�
    HPR_VOIDPTR pUserData;                                       //[in]�û�����
    HPR_UINT8   byRes[128];
}NET_ISUP_BASE_LFINFO, *LPNET_ISUP_BASE_LFINFO;


typedef enum tagENUM_SET_LF_PARAM_TYPE
{
    TYPE_LF_UNKNOW_PARAM = 0,
    TYPE_LF_SEND_TIMEOUT = 1,
    TYPE_LF_ALIVE_INTERVAL = 2,
}ENUM_SET_LF_PARAM_TYPE;

NET_COM_API HPR_INT32 CALLBACK  NET_ISUP_BASE_LFCreateClient(HPR_INT32 iLoginHandle, LPNET_ISUP_BASE_LFINFO lpLFInfo);

NET_COM_API HPR_BOOL CALLBACK NET_ISUP_BASE_LFDestroyClient(HPR_INT32 iHandle);

NET_COM_API HPR_BOOL CALLBACK NET_ISUP_BASE_LFSendData(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR lpLFParam, HPR_UINT32 dwSize);

NET_COM_API HPR_BOOL CALLBACK NET_ISUP_BASE_LFSetParam(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR lpLFParam, HPR_UINT32 dwSize);


#endif //_DEVEBASE_SRC_INTERFACE_EBASEINTERFACE_H_
