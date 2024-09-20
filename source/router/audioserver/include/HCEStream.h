#ifndef _ECOM_STREAMINTERFACE_H_ 
#define _ECOM_STREAMINTERFACE_H_

#include "HCEBase.h"

typedef struct tagNET_ESTREAM_ABILITY_CFG
{
    HPR_UINT32 dwBitStreamCount;    //(1)ISUPΪԤ���ط��ܹ�֧�ֵ�·����Ĭ��256��OTAPΪԤ���ط������Խ��ܹ�֧�ֵ�·����Ĭ��256
    HPR_UINT32 dwVoiceTalkCount;    //ISUP�����Խ�֧�ֵ�·����Ĭ��1
}NET_ESTREAM_ABILITY_CFG, *LPNET_ESTREAM_ABILITY_CFG;

typedef struct tagNET_OTAP_STREAM_RUNTIME_INFO
{
    HPR_UINT32	 dwType;                                   ///< ��Ϣ����\c EZDEVSDK_STREAM_RUNTIME_INFO_E
    void         *pData;                                   ///< ָ�����type���͵�����
    HPR_UINT32   dwLen;                                    ///< data���ݳ���
    void         *pUserData;
    HPR_UINT8    byRes[32];
} NET_OTAP_STREAM_RUNTIME_INFO, *LPNET_OTAP_STREAM_RUNTIME_INFO;

typedef struct tagNET_OTAP_STREAM_MSG_TO_DEV
{
    HPR_UINT32	 dwType;                                   //[out]��Ϣ����,�ο��ṹ�壺NET_OTAP_STREAM_MSG_TO_DEV_TYPE_E
    HPR_UINT32   dwLen;                                    //[out]ָ����Ϣ���ݵĳ���
    void         *pData;                                   //[out]ָ����Ϣ���ݵ�ָ��
    void         *pUserData;                               //[out]�û�����
    HPR_INT32    iHandle;                                  //[out]��ӦNET_EBASE_CreateIOTClient�ͻ��˴����ӿڷ��صľ��
    HPR_UINT8    byRes[28];
} NET_OTAP_STREAM_MSG_TO_DEV, *LPNET_OTAP_STREAM_MSG_TO_DEV;

typedef enum tagNET_OTAP_STREAM_DATA_TYPE_ENUM
{
    ENUM_OTAP_STREAM_DATA_TYPE_EXCEPTION = 0, //��·�������쳣��pDataΪ4�ֽ�HPR_UINT32����ʾ������
    ENUM_OTAP_STREAM_DATA_TYPE_STREAM = 1, //��������,�����Խ�֧��
}NET_OTAP_STREAM_DATA_TYPE_ENUM;

typedef struct tagNET_OTAP_RECV_STREAM_DATA
{
    HPR_UINT8       byDataType;     //��NET_OTAP_STREAM_DATA_TYPE_ENUM
    HPR_UINT8       byRes1[7];      //�����ֽڣ���֤8�ֽڶ��룩
    HPR_UINT8*      pData;          //����ָ��
    void*           pUserData;
    HPR_UINT32      dwDataLen;      //���ݳ���
    HPR_UINT32      dwSid;          ///< �����ỰID������ʱ��Ϊ�������
    HPR_INT32       iHandle;        //[out]��ӦNET_EBASE_CreateIOTClient�ͻ��˴����ӿڷ��صľ��
    HPR_UINT8       byRes[24];      //����
} NET_OTAP_RECV_STREAM_DATA;


typedef enum tagNET_OTAP_STREAM_EXCEPTION_ENUM//������·�쳣����
{
    ENUM_HEARTBEAT_TIMEOUT_EXCEPTION = 0, //������ʱ
}NET_OTAP_STREAM_EXCEPTION_ENUM;

typedef struct tagNET_OTAP_STREAM_EXCEPTION
{
    HPR_UINT8       byExceptionType;//<NET_OTAP_STREAM_EXCEPTION_ENUM
    HPR_UINT8       byRes1[3];      //�����ֽڣ���֤8�ֽڶ��룩
    HPR_UINT32      dwSid;          ///< �����ỰID������ʱ��Ϊ�������
    void*           pUserData;
    HPR_UINT8       byRes2[28];      //����
}NET_OTAP_STREAM_EXCEPTION;

typedef HPR_BOOL(CALLBACK *StreamDataCallback)(NET_OTAP_RECV_STREAM_DATA *pStreamData);
typedef HPR_INT32(CALLBACK *RecvMsgCB)(NET_OTAP_STREAM_MSG_TO_DEV *pMsg);              ///< ��Ϣ�ص��ӿڣ�������������������ز�Ϊ0��ʾ����ʧ��
typedef HPR_BOOL(CALLBACK *ExceptionCallback)(NET_OTAP_STREAM_EXCEPTION *pStreamData);

typedef struct tagNET_OTAP_STREAM_CALLBACK
{
    RecvMsgCB fnRecvMsgCB;
    StreamDataCallback fnStreamDataCB;
    ExceptionCallback fnExceptionCB;//�쳣�ص�
    void         *pUserData;
    HPR_UINT8    byRes[28];
} NET_OTAP_STREAM_CALLBACK;

typedef struct tagNET_OTAP_STREAM_INIT_INFO
{
    NET_OTAP_STREAM_CALLBACK struCallBack;                ///< �ص�����
    HPR_UINT8    byRes[32];
} NET_OTAP_STREAM_INIT_INFO, *LPNET_OTAP_STREAM_INIT_INFO;

typedef struct tagNET_OTAP_STREAM_INIT_PARAM
{
    LPNET_ESTREAM_ABILITY_CFG   pEstreamAbility;    //��������ΪNULL
    LPNET_OTAP_STREAM_INIT_INFO pStreamInitInfo;    //OTAPȡ��ʱ��Ч������
    HPR_UINT8    byRes[32];
}NET_OTAP_STREAM_INIT_PARAM, *LPNET_OTAP_STREAM_INIT_PARAM;

typedef enum enumNET_STREAM_LOCAL_CFG_TYPE
{
    STREAM_LOCAL_CFG_TYPE_UNKNOW = -1,                   //δ֪����
    STREAM_LOCAL_CFG_TYPE_CLIENT_CERT_PATH = 0,          //�ͻ���֤��·������ӦpParamΪ�ַ�������󳤶�128�ֽڣ�ĩβ��\0��β
    STREAM_LOCAL_CFG_TYPE_CLIENT_PRIKEY_PATH = 1,        //�ͻ���˽Կ·��, ��ӦpParamΪ�ַ�������󳤶�128�ֽڣ�ĩβ��\0��β
    STREAM_LOCAL_CFG_TYPE_SERVER_CACERT_PATH = 2         //����˸�֤��·��, ��ӦpParamΪ�ַ�������󳤶�128�ֽڣ�ĩβ��\0��β
}NET_STREAM_LOCAL_CFG_TYPE;

/************************************************************************/
/*                            ���ؽӿ�                                  */
/************************************************************************/

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_Init(LPNET_EBASE_ABILITY_CFG lpStruAbility)
*  @brief  ��ʼ����
*  @param (in)	LPNET_EBASE_ABILITY_CFG lpStruAbility
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_ESTREAM_Init(LPNET_ESTREAM_ABILITY_CFG lpStruAbility);
NET_COM_API HPR_BOOL   CALLBACK NET_OTAP_ESTREAM_Init(LPNET_OTAP_STREAM_INIT_PARAM lpStreamInitParam);
/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_Fini()
*  @brief ����ʼ����
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_ESTREAM_Fini();
/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_GetBuildVersion()
*  @brief ��ȡ�汾��
*  @return	HPR_UINT32 �汾��
*/
NET_COM_API HPR_UINT32 CALLBACK NET_ESTREAM_GetBuildVersion();
/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_ESTREAM_SetLocalCfg(HPR_UINT32 dwType, HPR_VOIDPTR pParam)
*  @brief
*  @param (in)	HPR_UINT32 dwType �μ�ö��NET_STREAM_LOCAL_CFG_TYPE
*  @param (in)	HPR_VOIDPTR pParam
*  @return	NET_COM_API HPR_UINT32 CALLBACK
*/
NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_SetLocalCfg(HPR_UINT32 dwType, HPR_VOIDPTR pParam);

/************************************************************************/
/*                            �����Խ��ӿ�                              */
/************************************************************************/
typedef enum enumEVoiceTalkDataType
{
    TYPE_UNKNOW = -1,       //δ֪����,           ClassType(pData) = NULL
    TYPE_SIGNAL = 0,        //�����Խ�����        ClassType(pData) = LPNET_SIGNAL_VOICE_TALK_DATA
    TYPE_STREAM = 1,        //�����Խ���          ClassType(pData) = LPNET_ESTREAM_VOICE_TALK_DATA
}EVoiceTalkDataType;

typedef enum enumEVoiceTalkSignal
{
    STATUS_UNKNOW = -1,                //δ֪����,           
    STATUS_START = 0,                  //�����Խ���ʼ     
    STATUS_STOP  = 1,                  //�����Խ����� 
    STATUS_KEEPLIVE_FAIL = 2,          //�����Խ�����ʧ��
}EVoiceTalkSignal;

typedef struct tagNET_SIGNAL_VOICE_TALK_DATA
{
    HPR_INT32                   iSessionID;                 //�ỰID,Baseģ�鿪�������Խ������з���˷���
    HPR_UINT32                  dwVoiceTalkSignal;          //�����Խ�����
    HPR_UINT32                  dwStatus;                   //�����״̬
    HPR_UINT32                  dwMediaInfoLen;             
    HPR_VOIDPTR                 pMediaInfo;                 //�������Խ���ʼǰ���ͻ��˺ͷ�������Ҫ�໥��֪�Է�ý������,xml��ʽ����֧��2048���ֽڣ�����������,���������Խ�����TYPE_SIGNAL��STATUS_START��Ч
    HPR_UINT8                   byRes[128];
}NET_SIGNAL_VOICE_TALK_DATA, *LPNET_SIGNAL_VOICE_TALK_DATA;

typedef struct tagNET_ESTREAM_VOICE_TALK_DATA
{
    HPR_INT32                   iSessionID;               //�ỰID,Baseģ�鿪�������Խ������з���˷��أ�ÿһ·�Խ�sessionidΨһ
    HPR_UINT8 *                 pVoiceTalkData;           //�����Խ�����
    HPR_UINT32                  dwDataLen;                //�����Խ����ݳ���
    HPR_UINT32                  AudioDataType;            //��Ƶ���ݰ�����
    HPR_UINT32                  dwSendLen;                //[out]�����Խ�ʵ�ʷ������ݳ���
    HPR_UINT8                   byRes[124];
}NET_ESTREAM_VOICE_TALK_DATA, *LPNET_ESTREAM_VOICE_TALK_DATA;

/*��dwDataTypeΪ�����Խ��������ͣ��������pOutBuffer���������pInBuffer��Ӧ�ṹ���ΪNET_SIGNAL_VOICE_TALK_DATA����dwDataTypeΪ�����Խ������ͣ��������pOutBuffer��Ӧ�ṹ��ΪNET_ESTREAM_VOICE_TALK_DATA��
  �������pInBufferΪNULL�����÷������� */
typedef void (CALLBACK *EVoiceTalkFunc)(HPR_INT32 dwHandle, EVoiceTalkDataType dwDataType, HPR_VOIDPTR pOutBuffer, HPR_INT32 dwOutLen, HPR_VOIDPTR pInBuffer, HPR_VOIDPTR pUserData);
typedef struct tagNET_ESTREAM_VOICE_TALK_INFO
{
    HPR_UINT32                  dwSize;                                      //[in]�ṹ�峤��
    HPR_INT32                   iSessionID;                                  //�ỰID,Baseģ�鿪�������Խ������з���˷���
    HPR_UINT8                   byToken[MAX_VOICETALK_TOKEN_LEN];            //Token��Baseģ�鿪�������Խ������з���˷���
    HPR_UINT8                   byTTSAdd[MAX_ADD_LEN];                       //[in]��ý�����˵�ַ��֧��IPv4��IPv6��������Baseģ�鿪�������Խ������з���˷���
    EVoiceTalkFunc              fnCB;                                        //[in]���յ������ݻص�
    HPR_VOIDPTR                 pUserData;                                   //[in]�û�����
    HPR_UINT16                  wTTSPort;                                    //[in]��ý�����˶˿ڣ�Baseģ�鿪�������Խ������з���˷���
    HPR_UINT8                   byEncodeType;                                //�����Խ������ʽ����0- G722_1��1- G711U��2- G711A��3- G726��4- AAC��5- MP2L2��6- PCM, 7-MP3, 8-G723, 9-MP1L2, 99-RAW
    HPR_UINT8                   bySupport;                                   //bit0(bySupport&0x01==0x01):�Ƿ���·����
    HPR_UINT8                   byBroadCast;                               //�����㲥��ʶ, �豸���յ�����ʶΪ1�󲻽�����Ƶ�ɼ����͸��Զ�
    HPR_UINT8                   byBroadLevel;                              //�����㲥���ȼ���ʶ,0~15���ȼ��ӵ͵���,������byBroadcastΪ1ʱ,0��ʶ������ȼ���������byBroadcastΪ0ʱ�����ڵ�������Ϊ�����ֽ�
    HPR_UINT8                   byBroadVolume;                             //�����㲥����,0~15�����ӵ͵���,������byBroadcastΪ1ʱ,0��ʶ���������������byBroadcastΪ0ʱ�����ڵ�������Ϊ�����ֽ�
    HPR_UINT8                   byProtocolType;                            //Э������  0-ISUP
    HPR_UINT8                   byRes[124];                                //Ԥ���ֶ�  

}NET_ESTREAM_VOICE_TALK_INFO, *LPNET_ESTREAM_VOICE_TALK_INFO;

/** @fn	NET_COM_API HPR_INT32 CALLBACK NET_ESTREAM_VOICETALK_CreateClient(LPNET_ESTREAM_VOICE_TALK_INFO lpVoiceTalkInfo)
 *  @brief  ���������Խ��ͻ���
 *  @param (in)	LPNET_ESTREAM_VOICE_TALK_INFO lpVoiceTalkInfo ����EHome�����Խ��ͻ����������
 *  @return	HPR_INT32  -1��ʾʧ�ܣ�����ֵ��ʾ���
 */
NET_COM_API HPR_INT32 CALLBACK NET_ESTREAM_VOICETALK_CreateClient(LPNET_ESTREAM_VOICE_TALK_INFO lpVoiceTalkInfo);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_VOICETALK_DestroyClient(HPR_INT32 dwHandle)
 *  @brief ���������Խ��ͻ���
 *  @param (in)	HPR_INT32 dwHandle  NET_ESTREAM_VOICETALK_CreateClient����ֵ
 *  @return HPR_BOOL  HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_VOICETALK_DestroyClient(HPR_INT32 iHandle);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_SendVoiceTalkData(HPR_INT32 dwHandle, LPNET_ESTREAM_VOICE_TALK_DATA lpVoicTalkData)
 *  @brief ���������Խ�����
 *  @param (in)	HPR_INT32 dwHandle  NET_ESTREAM_VOICETALK_CreateClient����ֵ
 *  @param (in)	LPNET_ESTREAM_VOICE_TALK_DATA lpVoicTalkData �����Խ�����
 *  @return HPR_BOOL  HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
 */
NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_SendVoiceTalkData(HPR_INT32 iHandle, LPNET_ESTREAM_VOICE_TALK_DATA lpVoicTalkData);

/************************************************************************/
/*                            �����ӿ�                                  */
/************************************************************************/
#define MAX_STREAM_SESSIONID_LEN 64       //sessionID�ĳ���
#define MAX_STREAM_HEART_ABILITY_LEN 64   //���������ṹ��ĳ���
#define MAX_STREAM_HEADER_LEN    40   //����ͷ����

typedef struct tagNET_ESTREAM_CLIENT_PARAM
{
    HPR_UINT8   byServerAdd[MAX_ADD_LEN/*256*/];            //[in]����˵�ַ��֧��IPv4��IPv6������
    HPR_UINT16  wServerPort;                                //[in]����˶˿�
    HPR_UINT8   byStreamType;                               //[in]�������� 0-Ԥ����1-�ط� 2-�����Խ�
    HPR_UINT8   byLinkMode;                                 //0��TCP��1��UDP��8-NPQ;
    HPR_UINT8   bySessionID[MAX_STREAM_SESSIONID_LEN/*64*/];//[in]����˷�Ԥ������ʱ��������һ��sessionID���豸���豸��Ҫ�����ֵ���ظ������
    HPR_UINT8   byStreamHeader[MAX_STREAM_HEADER_LEN/*40*/];//[in]����ͷ
    HPR_UINT16  wSDPLength;                                 //SDP��Ϣ���ȣ�byLinkModeΪ8ʱ��Ч��
    char*       pSDPBuffer;                                 //SDP��Ϣ��byLinkModeΪ8ʱ��Ч��
    HPR_UINT8   bySupport;                                  //bit0(bySupport&0x01==0x01):�Ƿ���·����,TCPͨ��TLS���䣬UDP(����NPQ)ʹ��DTLS����
}NET_ESTREAM_CLIENT_PARAM, *LPNET_ESTREAM_CLIENT_PARAM;

typedef struct tagNET_ESTREAM_STREAM_PARAM
{
    HPR_UINT16  wTimeSpan;                                  //[in]���ʱ�䣬ʱ���������Э��Ԥ����Ŀǰ������д
    HPR_UINT8   byFrameType;                                //[in]֡����,I,B,P֡������Э��Ԥ����Ŀǰ������д
    char*       pDataBuff;                                  //[in]�������ݣ������RTP����Ҫ����һ��������RTP��
    HPR_UINT32  dwDataLen;                                  //[in]�������ݳ���
    HPR_UINT8   byStreamEnd;                                //[in]�Ƿ������һ�����ݣ���������һ�����ݣ������ر�����
    HPR_UINT8   byType;                                     //[in]��������0-��������(Ĭ��) 15-HLS��������
    HPR_UINT8   byPackPos;
    HPR_UINT8   byRes[1];
}NET_ESTREAM_STREAM_PARAM, *LPNET_ESTREAM_STREAM_PARAM;

typedef enum enumEStreamCallBackType
{
    TYPE_CALLBACK_UNKNOW = -1,                 //δ֪����,           ClassType(pData) = NULL
    TYPE_EXCEPTION = 0,                        //�쳣�ص�            ClassType(pData) = HPR_UINT32,pOutBufferΪ������,����������ʱ�������жϣ��������ݴ���
    TYPE_NPQ_RTCP = 1,                         //NPQ RTCP���ݻص�,�ص���pOutBufferΪNET_ESTREAM_CALLBACK_DATA��
                                                                    //NET_ESTREAM_CALLBACK_DATA.pBufferΪ���յ���NPQ�����е�RTCP��,
                                                                    //NET_ESTREAM_CALLBACK_DATA.dwBufferLenΪ���յ���NPQ�����е�RTCP������
}EStreamCallBackType;

typedef struct tagNET_ESTREAM_CALLBACK_DATA
{
    HPR_UINT32 dwBufferLen;
    char* pBuffer;
}NET_ESTREAM_CALLBACK_DATA, *LPNET_ESTREAM_CALLBACK_DATA;

typedef void (CALLBACK *EStreamCallBack)(HPR_INT32 iHandle, EStreamCallBackType enumDataType, HPR_VOIDPTR pOutBuffer, HPR_VOIDPTR pInBuffer, HPR_VOIDPTR pUserData);
typedef struct tagNET_ESTREAM_CALLBACK_PARAM
{
    EStreamCallBack             fnCB;                                        //[in]���յ������ݻص�
    HPR_VOIDPTR                 pUserData;                                   //[in]�û�����
    HPR_UINT8                   byRes[128];
}NET_ESTREAM_CALLBACK_PARAM, *LPNET_ESTREAM_CALLBACK_PARAM;

typedef enum enumNET_ESTREAM_BSCON_TYPE
{
    ESTREAM_BSCON_TYPE_UNKNOW       = -1,                   //δ֪����
    ESTREAM_BSCON_TYPE_SENDTIMEOUT  = 0,                    //���ͳ�ʱʱ�䣬��ʱ��Ӧ��lpParamΪHPR_UINT32*���ͣ�size = sizeof(HPR_UINT32)
    ESTREAM_BSCON_TYPE_PLAYBACKCALLBACK = 1,                //���ûط���ػص���������Ӧ�ṹ��ΪNET_ESTREAM_CALLBACK_PARAM��
    ESTREAM_BSCON_TYPE_PLAYBACKHEARTABILITY = 2,            //����֧�ֻط�������������������ط���ͣ����һ��ʹ�ã�����ESTREAM_BSCON_TYPE_PLAYBACKCALLBACK�����ã��ṹ��ΪNYLL��
    ESTREAM_BSCON_TYPE_NPQ_CALLBACK = 3,                    //����NPQ���ݻص���������Ӧ�ṹ��ΪNET_ESTREAM_CALLBACK_PARAM
}NET_ESTREAM_BSCON_TYPE;

typedef enum {
    NET_OTAP_PREVIEW_ON_START_SEND_STREAM = 0,                  //��ʼԤ��ȡ��, �ο��ṹ�壺NET_OTAP_PREVIEW_START_SEND_STREAM
    NET_OTAP_PREVIEW_ON_STOP_SEND_STREAM,                       //ֹͣԤ��ȡ��, �ο��ṹ�壺NET_OTAP_PREVIEW_STOP_SEND_STREAM
    NET_OTAP_PREVIEW_ON_GET_STREAM_INFO,                        //��ȡԤ������Ϣ���ڿ�ʼԤ��ȡ��ǰ��ȡ���ο��ṹ�壺NET_OTAP_PREVIEW_GET_STREAM_INFO

    NET_OTAP_VOICE_ON_START_SEND_STREAM = 200,                        //��ʼ�����Խ�ȡ��, �ο��ṹ�壺NET_OTAP_VOICE_START_SEND_STREAM 
    NET_OTAP_VOICE_ON_STOP_SEND_STREAM,                         //ֹͣ�����Խ�ȡ��, �ο��ṹ�壺NET_OTAP_VOICE_STOP_SEND_STREAM 
    NET_OTAP_VOICE_ON_GET_STREAM_INFO,                    //��ȡ�����Խ�����Ϣ���ڿ�ʼ�����Խ�ȡ��ǰ��ȡ���ο��ṹ�壺NET_OTAP_VOICE_GET_STREAM_INFO


    NET_OTAP_PLAYBACK_ON_START_SEND_STREAM = 400,               //��ʼ�ط�ȡ��, �ο��ṹ�壺 NET_OTAP_START_SEND_STREAM 
    NET_OTAP_PLAYBACK_ON_STOP_SEND_STREAM,                      //ֹͣ�ط�ȡ��, �ο��ṹ�壺 NET_OTAP_STOP_SEND_STREAM 
    NET_OTAP_PLAYBACK_ON_START_DOWNLOAD_STREAM,                 ///<��ʼ¼������ �ο��ṹ�壺NET_OTAP_START_SEND_STREAM
    NET_OTAP_PLAYBACK_ON_STOP_DOWNLOAD_STREAM,                  ///<ֹͣ¼������ �ο��ṹ�壺NET_OTAP_STOP_SEND_STREAM
    NET_OTAP_PLAYBACK_ON_GET_STREAM_INFO                        //��ȡ�ط�����Ϣ����Ҫ�ڿ�ʼ�ط�ȡ��ǰ��ȡ���ο��ṹ�壺 NET_OTAP_PLAYBACK_GET_STREAM_INFO

    //NET_OTAP_PLAYBACK_ON_PAUSE_SEND_STREAM,                 ///< ��ͣȡ��, ��Ϣ��\c NET_OTAP_PAUSE_SEND_STREAM
    //NET_OTAP_PLAYBACK_ON_RESUME_SEND_STREAM,                 ///< �ָ�����¼������, NET_OTAP_PAUSE_SEND_STREAM
    //NET_OTAP_PLAYBACK_ON_SEEK_TIME_STREAM,                 ///< ¼��ط�������ת��ʱ���  NET_OTAP_SEEK_TIME_STREAM
    //NET_OTAP_PLAYBACK_ON_CONTINUE_SEND_STREAM,                 ///< ��ý��¼��ط���ת ǰһ�η�����ɺ��ٷ������������� NET_OTAP_CONTINUE_PLAYBACK
    //NET_OTAP_PLAYBACK_ON_MODIFY_SPEED_PLAY_STREAM,                 ///< ��ý���豸¼���ٻط� NET_OTAP_MODIFY_PLAYBACK_SPEED
    //NET_OTAP_PLAYBACK_ON_SEEK_SEGS_STREAM,                     ///<¼��ط���ת���϶�¼��� NET_OTAP_SEGS_PLAYBACK


} NET_OTAP_STREAM_MSG_TO_DEV_TYPE_E;

/**
* \brief \c NET_OTAP_PREVIEW_ON_START_SEND_STREAM
*/
typedef struct tagNET_OTAP_PREVIEW_START_SEND_STREAM
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID������ʱ��Ϊ�������
    HPR_UINT32 dwPreTime;                                       ///< ȡԤ¼�����ȣ���λ���룬0��ʾ��ȡԤ¼��
    HPR_UINT8  bySessionID[MAX_STREAM_SESSIONID_LEN/*64*/];        //[out]NET_OTAP_PREVIEW_GET_STREAM_INFOʱ�û������sessionID
    HPR_UINT8  byRes[32];
}  NET_OTAP_START_SEND_STREAM, *LPNET_OTAP_PREVIEW_START_SEND_STREAM;

/**
* \brief \c NET_OTAP_PREVIEW_ON_STOP_SEND_STREAM
*/
typedef struct tagNET_OTAP_PREVIEW_STOP_SEND_STREAM
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    HPR_UINT8  byRes[32];
}NET_OTAP_STOP_SEND_STREAM, *LPNET_OTAP_PREVIEW_STOP_SEND_STREAM;

typedef struct tagNET_OTAP_PAUSE_SEND_STREAM
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    HPR_UINT8  byRes[32];
}NET_OTAP_PAUSE_SEND_STREAM, *LPNET_OTAP_PAUSE_SEND_STREAM;

typedef struct tagNET_OTAP_PREVIEW_GET_STREAM_INFO
{
    HPR_UINT32  dwChannel;                                          //[out] ͨ��
    HPR_UINT8   byStreamType;                                       //[out] �������ͣ�1:������,2:������
    HPR_UINT8   byDataType;                                         //[out] �������ͣ���λ��ʾ��0x01-��Ƶ��0x02-��Ƶ��0x04-�ṹ�����ݣ�Ĭ�ϴ�����Ƶ����Ƶ���ݣ�0x00��
    HPR_UINT8   byRes1[2];
    HPR_UINT8   bySessionID[MAX_STREAM_SESSIONID_LEN/*64*/];        //[in]�豸sessionID
    HPR_UINT8   byStreamHeader[MAX_STREAM_HEADER_LEN/*40*/];        //[in]����ͷ
    HPR_UINT8   byRes[64];
}NET_OTAP_PREVIEW_GET_STREAM_INFO, *LPNET_OTAP_PREVIEW_GET_STREAM_INFO;

typedef struct tagOTAP_TIME
{
    HPR_UINT16    wYear;      //��
    HPR_UINT8     byMonth;    //��
    HPR_UINT8     byDay;      //��
    HPR_UINT8     byHour;     //ʱ
    HPR_UINT8     byMinute;   //��
    HPR_UINT8     bySecond;   //��
    HPR_UINT8     byTimeZone;  //1~12��ʾ��1����12��,13~24��ʾ��1����12��
    HPR_UINT16    wMSecond;   //����
    HPR_UINT8     byRes[6];
}OTAP_TIME;

typedef struct tagOTAP_PLAYBACK_TIME
{
    OTAP_TIME  struStartTime;  // ��ʱ��¼��ȡ���Ŀ�ʼʱ��
    OTAP_TIME  struStopTime;   // ��ʱ��¼��ȡ���Ľ���ʱ��
}OTAP_PLAYBACK_TIME, *LPOTAP_PLAYBACK_TIME;


typedef struct tagNET_OTAP_PLAYBACK_GET_STREAM_INFO
{
    HPR_UINT32  dwChannel;                                          //[out] ͨ��
    HPR_UINT8   byStreamType;                                       //[out] �������ͣ�1:������,2:������
    HPR_UINT8   byDataType;                                         //[out] �������ͣ���λ��ʾ��0x01-��Ƶ��0x02-��Ƶ��0x04-�ṹ�����ݣ�Ĭ�ϴ�����Ƶ����Ƶ���ݣ�0x00��
    HPR_UINT8   byRes1[2];
    HPR_UINT8   bySessionID[MAX_STREAM_SESSIONID_LEN/*64*/];        //[in]�豸sessionID
    HPR_UINT8   byStreamHeader[MAX_STREAM_HEADER_LEN/*40*/];        //[in]����ͷ
    OTAP_PLAYBACK_TIME struTime[20];                                //[out]
    HPR_UINT8   byRes[64];
}NET_OTAP_PLAYBACK_GET_STREAM_INFO, *LPNET_OTAP_PLAYBACK_GET_STREAM_INFO;

typedef struct tagNET_OTAP_SEEK_TIME_STREAM
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    OTAP_TIME  struTime;                                  ///<��תʱ���
    HPR_UINT8  byRes[32];
}NET_OTAP_SEEK_TIME_STREAM, *LPNET_OTAP_SEEK_TIME_STREAM;

typedef struct tagNET_OTAP_MODIFY_PLAY_SPEED
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    HPR_UINT8 byPlaybackType;                           ///<����ģʽ, �豸����������1:ȫ֡, 2����֡
    HPR_UINT8 bySpeed;                                          ///<�����ٶ�  1: �����ٶ�, 2��2��, 3��1/2��, 4��4��, 5��1/4��, 6��8��, 7��1/8��, 8��16��, 9��1/16��
    HPR_UINT8  byRes[128];
}NET_OTAP_MODIFY_PLAY_SPEED, *LPNET_OTAP_MODIFY_PLAY_SPEED;

typedef struct tagNET_OTAP_SEGS_PLAYBACK
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    HPR_UINT32 dwRecordNum;   //����¼��ȡ����¼��������μ�struRecordStreamingTime
    OTAP_PLAYBACK_TIME struRecordStreamingTime[20];                  ///<¼����ת��Ϣ�б�
    HPR_UINT8  byRes[128];
}NET_OTAP_SEGS_PLAYBACK, *LPNET_OTAP_SEGS_PLAYBACK;

typedef struct tagNET_OTAP_CONTINUE_PLAYBACK
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    HPR_UINT32 dwRecordNum;   //����¼��ȡ����¼��������μ�struRecordStreamingTime
    OTAP_PLAYBACK_TIME struRecordStreamingTime[20];                  ///<¼����ת��Ϣ�б�
    HPR_UINT8  byRes[128];
}NET_OTAP_CONTINUE_PLAYBACK, *LPNET_OTAP_CONTINUE_PLAYBACK;

typedef struct tagNET_OTAP_MODIFY_PLAYBACK_SPEED
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    HPR_UINT8 byPlaybackType;                           ///<����ģʽ, �豸����������1:ȫ֡, 2����֡
    HPR_UINT8 bySpeed;                                          ///<�����ٶ�  1: �����ٶ�, 2��2��, 3��1/2��, 4��4��, 5��1/4��, 6��8��, 7��1/8��, 8��16��, 9��1/16��
    HPR_UINT8  byRes[128];
}NET_OTAP_MODIFY_PLAYBACK_SPEED, *LPNET_OTAP_MODIFY_PLAYBACK_SPEED;

typedef struct tagNET_OTAP_DOWNLOAD_STREAM
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    OTAP_PLAYBACK_TIME strucTimesSpan;          ///����ʱ��
    HPR_UINT8  byRes[32];
}NET_OTAP_DOWNLOAD_STREAM, *LPNET_OTAP_DOWNLOAD_STREAM;
//-------------------------------------------------------------------------------

typedef struct tagNET_OTAP_VOICE_START_SEND_STREAM
{
    HPR_UINT32 dwChannel;                                       //[out]ͨ��
    HPR_UINT32 dwStreamIndex;                                   //[out]��������
    HPR_UINT32 dwSid;                                           //[out]�����ỰID������ʱ��Ϊ�������
    HPR_UINT8  byRes1[4];
    HPR_UINT8  bySessionID[MAX_STREAM_SESSIONID_LEN/*64*/];     //[out]NET_OTAP_PREVIEW_GET_STREAM_INFOʱ�û������sessionID
    HPR_UINT8  byRes[32];
} NET_OTAP_VOICE_START_SEND_STREAM;

typedef struct tagNET_OTAP_VOICE_STOP_SEND_STREAM
{
    HPR_UINT32 dwChannel;                                        ///< ͨ��
    HPR_UINT32 dwStreamIndex;                                   ///< ��������
    HPR_UINT32 dwSid;                                            ///< �����ỰID���Ự���ͷ�ʽ��Ч����Чֵ����0.
    HPR_UINT8  byRes[32];
}NET_OTAP_VOICE_STOP_SEND_STREAM;

typedef struct tagNET_OTAP_VOICE_GET_STREAM_INFO
{
    HPR_UINT32  dwChannel;                                          //[out]ͨ��
    HPR_UINT16  wPriority;                                          //[out]�Խ����ȼ�ȡֵ��ΧΪ[1,16],���ȼ�1��ߣ�2��֮���Դ����ƣ�16���
    HPR_UINT16  wVolume;                                            //[out]�����԰ٷֱȵķ�ʽ����,��Χ[0,100],��wVolume����[0,100]��Χ����ʾ���豸Ĭ������
    HPR_UINT16  wTransmissionMode;                                   //[out]0-˫��Խ� 1-����㲥
    HPR_UINT16  wAudioType;                                         //[outin]��Ƶ����0-G722_1��1-G711_MU��2-G711_A��3-G723��4-MP1L2��5-MP2L2��
                                                                               // 6-G726��7-AAC��8-G726A��9-G72616��10-G729��11-ADPCM��12-AMRNB��13-RAW8��14-RAW16��
                                                                               // 15 - MP2L232��16 - MP2L264��17 - AAC32��18 - AAC64��19 - OPUS8��20 - OPUS16��21 - OPUS48��
                                                                                // 22 - G729A��23 - G729B��24 - PCM��25 - MP3��26 - AC3��99 - RAW
    HPR_UINT32  dwAudioSamplingRate;                                //[outin]0-���豸Ĭ�ϲ�����
    HPR_UINT8   bySessionID[MAX_STREAM_SESSIONID_LEN];              //[in]�豸sessionID
    HPR_UINT8   byRes[64];
}NET_OTAP_VOICE_GET_STREAM_INFO;
/** @fn	NET_COM_API HPR_INT32 CALLBACK NET_ESTREAM_BITSTREAM_CreateClient(LPNET_ESTREAM_CLIENT_PARAM lpStruParam)
*  @brief ����һ·�����ͻ���
*  @param (in)	LPNET_ESTREAM_CLIENT_PARAM lpStruParam
*  @return	NET_COM_API HPR_INT32 CALLBACK ���ظ�·�����ľ��
*/
NET_COM_API HPR_INT32 CALLBACK NET_ESTREAM_BITSTREAM_CreateClient(LPNET_ESTREAM_CLIENT_PARAM lpStruParam);
/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_BITSTREAM_DestroyClient(HPR_INT32 iHandle)
*  @brief  �ͷ�һ·�����ͻ���
*  @param (in)	HPR_INT32 iHandle
*  @return	NET_COM_API HPR_BOOL CALLBACK HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL  CALLBACK NET_ESTREAM_BITSTREAM_DestroyClient(HPR_INT32 iHandle);
/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_BITSTREAM_SendData(HPR_INT32 iHandle, const char *pDataBuff, HPR_UINT32 dwDataLen)
*  @brief  ��������������lDwSendLenΪ0ʱ��ʾ�����ѱ���������Ҫ�ȴ�
*  @param (in)	HPR_INT32 iHandle ���������NET_ESTREAM_BITSTREAM_CreateClient����ֵ
*  @param (in)	const char * pDataBuff
*  @param (in)	HPR_UINT32 dwDataLen
*  @param (out) HPR_INT32* lDwSendLen  ������HPR_TRUEʱ��lDwSendLen��ʾpDataBuff�ѷ��͵ĳ���ֵ���´δ����lpStruParam.pDataBuff���ƫ��lDwSendLen
*  @return	NET_COM_API HPR_BOOL CALLBACK
*/
NET_COM_API HPR_BOOL  CALLBACK NET_ESTREAM_BITSTREAM_SendData(HPR_INT32 iHandle, LPNET_ESTREAM_STREAM_PARAM lpStruParam, HPR_INT32* lDwSendLen);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_ESTREAM_BITSTREAM_SetParam(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR lpParam, HPR_UINT32 dwSize)
 *  @brief
 *  @param (in)	HPR_INT32 iHandle    
 *  @param (in)	HPR_UINT32 dwType    �����õĲ������ͣ���NET_ESTREAM_BSCON_TYPE
 *  @param (in)	HPR_VOIDPTR lpParam  �����õĲ�������NET_ESTREAM_BSCON_TYPE
 *  @param (in)	HPR_UINT32 dwSize    lpParam��ռ���ڴ��С
 *  @return	NET_COM_API HPR_BOOL CALLBACK
 */
NET_COM_API HPR_BOOL  CALLBACK NET_ESTREAM_BITSTREAM_SetParam(HPR_INT32 iHandle, NET_ESTREAM_BSCON_TYPE enumType, HPR_VOIDPTR lpParam, HPR_UINT32 dwSize);

#endif //_ECOM_STREAMINTERFACE_H_
