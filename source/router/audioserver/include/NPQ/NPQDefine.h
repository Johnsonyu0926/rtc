/**  @file    NPQDefine.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief     ����NPQ���õ��ĺ꣬�ṹ�壬ö�ٶ���
 *   
 *   @author zhaolin
 *   @modify zhaolin
 *   @date   2016/12/16
 *   
 *   @note:
 */

#ifndef _NPQ_DEFINE_H_
#define _NPQ_DEFINE_H_

#include "HPR_Config.h"
#include "HPR_Types.h"
#include "NPQos.h"

typedef enum
{
    NPQ_MODE_DIRECT_CONNECT = 0, //ֱ��
    NPQ_MODE_BY_SMS = 1          //����ý��
}PROTO_NPQ_MODE;

//������
#define NET_ERR_NPQ_BASE_INDEX      8000                                //NPQ�������
#define NET_ERR_NPQ_PARAM           (NET_ERR_NPQ_BASE_INDEX + 1)        //NPQ���������
#define NET_ERR_NPQ_SYSTEM          (NET_ERR_NPQ_BASE_INDEX + 2)        //NPQ�����ϵͳ���ô���(������Դ����ʧ�ܻ��ڲ�����ȣ�
#define NET_ERR_NPQ_GENRAL          (NET_ERR_NPQ_BASE_INDEX + 3)        //NPQ���ڲ�ͨ�ô���
#define NET_ERR_NPQ_PRECONDITION    (NET_ERR_NPQ_BASE_INDEX + 4)        //NPQ�����˳�����
#define NET_ERR_NPQ_NOTSUPPORT      (NET_ERR_NPQ_BASE_INDEX + 5)        //NPQ�⹦�ܲ�֧��

#define NET_ERR_NPQ_NOTCALLBACK     (NET_ERR_NPQ_BASE_INDEX + 100)      //����û�лص�����
#define NET_ERR_NPQ_LOADLIB         (NET_ERR_NPQ_BASE_INDEX + 101)      //NPQ�����ʧ��
#define NET_ERR_NPQ_STEAM_CLOSE (NET_ERR_NPQ_BASE_INDEX + 104) //��·����NPQ����δ����
#define NET_ERR_NPQ_MAX_LINK (NET_ERR_NPQ_BASE_INDEX + 110) //NPQȡ��·���ﵽ����
#define NET_ERR_NPQ_STREAM_CFG (NET_ERR_NPQ_BASE_INDEX + 111) //����������ڳ�ͻ����

typedef HPR_INT32(CALLBACK *HC_NPQ_Create)(NPQ_QOS_ROLE enType);
typedef HPR_INT32(CALLBACK *HC_NPQ_Destroy)(HPR_INT32 id);
typedef HPR_INT32(CALLBACK *HC_NPQ_Start)(HPR_INT32 id);
typedef HPR_INT32(CALLBACK *HC_NPQ_Stop)(HPR_INT32 id);
typedef HPR_INT32(CALLBACK *HC_NPQ_RegisterDataCallBack)(HPR_INT32 id, HPR_VOID(CALLBACK *fnRegisterDataCallBack)(HPR_INT32 id, HPR_INT32 iDataType, unsigned char* pData, HPR_UINT32 nDataLen, HPR_VOIDPTR pUser), HPR_VOIDPTR pUser);
typedef HPR_INT32(CALLBACK *HC_NPQ_InputData)(HPR_INT32 id, HPR_INT32 iDataType, unsigned char* pData, HPR_UINT32 nDataLen);
typedef HPR_INT32(CALLBACK *HC_NPQ_InputRawData)(HPR_INT32 id, MUX_PARAM* pMuxParam, INPUT_BUF* pstInputData);
typedef HPR_INT32(CALLBACK *HC_NPQ_SetParam)(HPR_INT32 id, HPR_VOIDPTR pParam);
typedef HPR_INT32(CALLBACK *HC_NPQ_GetStat)(HPR_INT32 id, NPQ_MAIN_TYPE enMainType, HPR_VOIDPTR pStat);
typedef HPR_INT32(CALLBACK *HC_NPQ_SetNotifyParam)(HPR_INT32 id, NPQ_SET_NOTIFY_PARAM* pNotifyParam);
typedef HPR_INT32(CALLBACK *HC_NPQ_GetVersion)(char* szVersion, int nLen);


typedef struct tagNET_UTILS_NPQ_PACK_PARAM
{
    // �̶��Ĳ���
    HPR_UINT32        pack_size;             // PS��TS��RTP������������0ΪĬ�ϳ���
    HPR_UINT32        track_index;           // �����
    HPR_UINT32        syc_video_track;       // ��������Ƶ�����

    HPR_UINT32        system_format;         // Ŀ���װ��ʽ
    HPR_UINT32        system_format_subtype; // Ŀ�����͵��Ӹ�ʽ��Ŀǰֻʹ����MP4��������װ������

    HPR_UINT32        video_format;          // ��Ƶ����
    HPR_UINT32        audio_format;          // ��Ƶ����
    HPR_UINT32        privt_format;          // ˽����������

    // �ο�֡��Ϣ���ǹ̶�����
    HPR_UINT32        is_hik_stream;         // �Ƿ���Ϻ�������
    HPR_UINT32        encrypt_type;          // ��������
    HPR_UINT32        frame_type;            // ��ǰ֡���� I/P/B/audio/privt
    HPR_UINT32        time_stamp;            // ʱ���
    float               duration;              // ֡ʱ��
    HPR_UINT32        frame_num;             // ֡��
    HK_SYSTEMTIME       global_time;           // ȫ��ʱ�䣨�����������У�

    // ��Ƶ����
    struct
    {
        HPR_UINT16  width_orig;            // �ֱ��ʣ�ԭʼ��
        HPR_UINT16  height_orig;           // �ֱ��ʣ�ԭʼ��
        HPR_UINT16  width_play;            // �ֱ��ʣ��ü���
        HPR_UINT16  height_play;           // �ֱ��ʣ��ü���
        float           frame_rate;            // ֡��
        HPR_UINT16  interlace;             // �Ƿ񳡱���
        HPR_UINT16  b_frame_num;           // ��ģʽ�У�B֡�ĸ���
        HPR_UINT32    is_svc_stream;         // �Ƿ�SVC����
    }video;

    // ��Ƶ����
    struct
    {
        HPR_UINT16  channels;              // ����
        HPR_UINT16  bits_per_sample;       // ��λ
        HPR_UINT32    samples_rate;          // ������
        HPR_UINT32    bit_rate;              // ������
    }audio;

    // ˽�в���
    struct
    {
        HPR_UINT32    privt_type;            // ˽������
        HPR_UINT32    data_type;             // ������
    }privt;

}NET_UTILS_NPQ_PACK_PARAM, *LPNET_UTILS_NPQ_PACK_PARAM;



typedef void (CALLBACK *NPQ_TRANS_CB)(HPR_INT32 id, HPR_INT32 iDataType, unsigned char* pData, HPR_UINT32 nDataLen, HPR_VOIDPTR pUser);



typedef struct tagNET_UTILS_NPQ_STATE_SINGLE
{
    HPR_UINT32 dwRttUs;			//rtt����λus
    HPR_UINT32 dwRealRttUs;		//ʵʱrtt����λus
    HPR_UINT32 dwBitRate;       //����
    HPR_UINT8 byLossFraction;	//�����ʣ���λ1/256
    HPR_UINT8 byLossFraction2;	//�����ָ�֮��Ķ����ʣ�ֻ���ڽ��ն˻�ȡ����λ1/256
    HPR_UINT8 byRes[126];
}NET_UTILS_NPQ_STATE_SINGLE, *LPNET_UTILS_NPQ_STATE_SINGLE;


typedef struct tagNET_UTILS_NPQ_STATE
{
    HPR_UINT32 dwSize;
    NET_UTILS_NPQ_STATE_SINGLE struAudioState;  //��Ƶ����״̬
    NET_UTILS_NPQ_STATE_SINGLE struVideoState;  //��Ƶ����״̬
    HPR_UINT8 byRes[256];
}NET_UTILS_NPQ_STATE, *LPNET_UTILS_NPQ_STATE;

// typedef struct tagNET_UTILS_NPQ_CONNECT_PARAM
// {
//     NET_UTILS_NPQ_LINK_COND struLinkRemote;  //�Զ�����Ƶ�����Ӻ�RTCP���ӵ�ַ��Ϣ
//     char *sSdp; //�Զ�SDP��Ϣ
//     HPR_UINT8 byRes[64];
// }NET_UTILS_NPQ_CONNECT_PARAM, *LPNET_UTILS_NPQ_CONNECT_PARAM;

typedef struct tagNET_UTILS_NPQ_COMPRESSINFO
{
    HPR_UINT32 dwSize;
    HPR_UINT32 dwMaxBitRate; //�������
    HPR_UINT8 byRes[64];
}NET_UTILS_NPQ_COMPRESSINFO, *LPNET_UTILS_NPQ_COMPRESSINFO;

typedef struct rtp_hdr//rtp header
{
    unsigned char count : 4;
    unsigned char extension : 1;
    unsigned char padding : 1;
    unsigned char version : 2;
    unsigned char payload : 7;
    unsigned char marker : 1;
    unsigned short sequence;
    unsigned int timestamp;
    unsigned int ssrc;
}RTP_HEADER;

#define COMMON_VIDEO_PT     96      //ͨ����Ƶpayload����

#endif //_NPQ_DEFINE_H_
