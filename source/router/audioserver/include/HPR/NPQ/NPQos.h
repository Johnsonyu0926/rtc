/**	@NPQos.h
*	@note HangZhou Hikvision Technology Co., Ltd. All Right Reserved.
*	@brief NPQ��ӿڶ���
*
*	@author		wangxinghe
*	@date		2016/11/14
*
*	@note
*
*	@warning 
*/
#ifndef _NPQOS_H_
#define _NPQOS_H_

#if defined(WIN32)
#if defined(NPQOS_EXPORTS)
#define NPQ_API extern "C" __declspec(dllexport)
#else
#define NPQ_API extern "C" __declspec(dllimport)
#endif
#else

#ifndef __stdcall
#define __stdcall
#endif

#ifndef NPQ_API
#define NPQ_API extern "C"
#endif

#endif

#include "IMuxDefine.h"
#include "NPQosAudioDec.h"
#define NPQ_OK              0x00000000  //�ɹ�
#define NPQERR_PARA         0x80000001  //��������
#define NPQERR_SYSTEM       0x80000002  //����ϵͳ���ô���(������Դ����ʧ�ܻ��ڲ�����ȣ���
#define NPQERR_GENRAL       0x80000003  //�ڲ�ͨ�ô���
#define NPQERR_PRECONDITION 0x80000004  //����˳�����
#define NPQERR_NOTSUPPORT   0x80000005  //���ܲ�֧��
#define NPQERR_DATAFORMAT   0x80000006  //rtp����rtcp���ݴ���

/**	@enum	 NPQ_QOS_TYPE 
 *	@brief   Qos��������
 *	@note	 
 */
enum NPQ_QOS_TYPE
{
	QOS_TYPE_NACK = (1<<0),          //Nack		
	QOS_TYPE_FEC = (1<<1),			 //FEC
	QOS_TYPE_DEJITTER = (1<<2),		 //ȥ����
	QOS_TYPE_BW = (1<<3),			 //ӵ������
	QOS_TYPE_PLI = (1<<4),			 //PLI
	QOS_TYPE_SYNCHRONOUS = (1<<5),	 //����Ƶͬ��
	QOS_TYPE_ALL = 0xff,
};

/**	@enum	 NPQ_QOS_ROLE 
 *	@brief   Qos��ɫ���ֽ��ն˺ͷ��Ͷ�
 *	@note	 
 */
enum NPQ_QOS_ROLE
{
	NPQ_QOS_RECEIVER,	//���ն�
	NPQ_QOS_SENDER,		//���Ͷ�
};

/**	@enum	 NPQ_MAIN_TYPE 
 *	@brief   Qos������
 *	@note	 
 */
enum NPQ_MAIN_TYPE
{
	NPQ_MAIN_VEDIO,		//��ƵQos
	NPQ_MAIN_AUDIO,		//��ƵQos
	NPQ_MAIN_PRIVATE,	//˽������Qos
    NPQ_MAIN_ALL = 0xFF,//��������
};

/**	@enum	 NPQ_DATA_TYPE 
 *	@brief   ��������
 *	@note	 
 */
enum NPQ_DATA_TYPE
{
	NPQ_DATA_RTP_VIDEO,			//��ƵRTP����
	NPQ_DATA_RTP_AUDIO,			//��ƵRTP����
	NPQ_DATA_RTP_PRIVATE,		//˽�а�RTP����
	NPQ_DATA_RTCP_VIDEO,		//��ƵRTCP
	NPQ_DATA_RTCP_AUDIO,		//��ƵRTCP
	NPQ_DATA_MULITIPLEX,	    //δ֪�������ݣ��ⲿ��ȷ���������ͣ���NPQ�ڲ�ʶ��,��Ҫ���sdp��
	NPQ_DATA_CMD,				//����ص�����ӦNPQ_CMD_TYPE ��Ҫ�ⲿ����Ӧ����
    NPQ_DATA_MEDIA_INFO,        //ý�������Ϣ�ص�����ӦNPQ_MEDIA_INFO ��Ҫ�ⲿ����Ӧ����
    NPQ_DATA_STATE,             //״̬��Ϣ�ص�����ӦNPQ_STAT
    NPQ_DATA_RTCP_PRIVATE,		//˽��RTCP
    NPQ_DATA_HIKINFO		    //����ͷ
};


/**	@enum	 NPQ_MEDIA_VIDEO_ENCODE_TYPE 
 *	@brief   ��Ƶ��������
 *	@note	 
 */
enum NPQ_MEDIA_VIDEO_ENCODE_TYPE
{
	NPQ_VIDEO_H264,
	NPQ_VIDEO_H265,
	NPQ_VIDEO_MPEG4,
    NPQ_VIDEO_SVAC,
	NPQ_VIDEO_UNKNOWN = 0xff,
};




/** @struct  NPQ_VIDEO_INFO
 *  @brief ��Ƶ������Ϣ��
 *  @note
*/
struct NPQ_VIDEO_INFO
{
    NPQ_MEDIA_VIDEO_ENCODE_TYPE enVideoCodeType;      //��Ƶ��������
    unsigned char               res[252];
};


/** @struct NPQ_AUDIO_INFO
 *  @brief ��Ƶ������Ϣ
 *  @note
*/
struct NPQ_AUDIO_INFO
{
    NPQ_AUDIO_ENCODE_TYPE        enAudioCodeType;     //��Ƶ��������
    unsigned int                 uSampleRate;         //������
    unsigned int                 uBitRate;            //��������
    unsigned char                res[244];             

};


/** @struct NPQ_MEDIA_INFO
 *  @brief NPQý����Ϣ��
 *  @note
*/
struct NPQ_MEDIA_INFO
{
    int iVersion;                                     //�ṹ��汾�������Ժ����
    NPQ_MAIN_TYPE enMediaType;                        //ý������
    union MEDIA_INFO
    {
        NPQ_VIDEO_INFO struVideoInfo;                 //��Ƶ������Ϣ
        NPQ_AUDIO_INFO struAudioInfo;                 //��Ƶ������Ϣ
        unsigned char  res[256];
    }unMediaInfo;
};

/**	@enum	 NPQ_CMD_TYPE 
 *	@brief   ��������
 *	@note	 
 */
enum NPQ_CMD_TYPE
{
	NPQ_CMD_ENCODE,			//����Ƶ�������
	NPQ_CMD_FORCE_I_FRAME,	//ǿ��I֡
};

/**	@struct	 NPQ_ECODE_PARAM 
 *	@brief   �����������
 *	@note	 
 */
struct NPQ_ECODE_PARAM
{
	int iVersion;				//�ṹ��汾�������Ժ����
	int iMaxBitRate;			//�������   ��λ bps�����ø���������ֵ
	int iResolution;			//�ֱ���  ��������SDKЭ�鶨�������ֵ
    int iEstimatedBW;           //���Ƴ������ܴ��� ��λbps
	unsigned char res[240]; 
};

/**	@struct	 NPQ_CMD 
 *	@brief   Qos����ص�, ֻ�����ڷ��Ͷ�
 *	@note	 
 */
struct NPQ_CMD
{
	int iVersion;					//�ṹ��汾�������Ժ����
	NPQ_CMD_TYPE enInfoType;		//��������
	union INFO_U
	{
		NPQ_ECODE_PARAM struEncode;
		unsigned char res[256]; 
	}unCmd;
};

/**	@struct	 NPQ_STAT 
 *	@brief   Qos״̬
 *	@note	 
 */
struct NPQ_STAT
{
	int iVersion;					//�ṹ��汾�������Ժ����
	unsigned int nRttUs;			//rtt����λus
	unsigned int nRealRttUs;		//ʵʱrtt����λus
	unsigned int nBitRate;			//��ǰ��������ʵ������,��λ bps
	unsigned char cLossFraction;	//�����ʣ���λ1/256
	unsigned char cLossFraction2;	//�����ָ�֮��Ķ����ʣ�ֻ���ڽ��ն˻�ȡ����λ1/256
    unsigned char nVideoPicQ;       //��Ƶ����      :0,�ã�1������2���
    unsigned char nVideoRTQ;        //��Ƶʵʱ������:0,�ã�1������2���
    unsigned char nVideoFluQ;       //��Ƶ����������:0,�ã�1������2���    
    unsigned char nAudioTonQ;       //��Ƶ����      :0,�ã�1������2���
    unsigned char nAudioRTQ;        //��Ƶʵʱ������:0,�ã�1������2���
    unsigned char nAudioFluQ;       //��Ƶ����������:0,�ã�1������2���
    unsigned int nFrameRate;        //��ȡͳ��֡��
	unsigned int nBitRateFec;       //��ǰFEC����ʵ������,��λ bps
	unsigned char res[232];
};

/**	@enum	 NPQ_PARAM_VALUE_TYPE 
 *	@brief   ��������
 *	@note	 
 */
enum NPQ_PARAM_VALUE_TYPE
{
	NPQ_PARAM_NULL,		//�ղ�������˽����Ϣ�н���
	NPQ_PARAM_SDP,		//sdp��Ϣ
};

/**	@struct	 NPQ_SENDER_PARAM 
 *	@brief   ���Ͷ�Qos���ò���
 *	@note	�ܴ�С128�ֽڹ̶�
 */
struct NPQ_SENDER_PARAM
{
	int bVaild;	        //�ṹ���Ƿ���Ч
	int iMinBitrate;	//��С���� ��λbps
	int iMaxBitrate;	//������� ��λbps
    int iStartBitrate;  //��ʼ���� ��λbps,�û���������һ����ʼ����
    char bStopBWProbe;  //�رմ���̽�⹦��
    char nREDr;         //��Ƶ�����
    char res[110];		//Ԥ���ֶ�
};

/**	@struct	 NPQ_RECEIVER_PARAM 
 *	@brief   ���ն�Qos���ò���
 *	@note	�ܴ�С128�ֽڹ̶�
 */
struct NPQ_RECEIVER_PARAM
{
	int  bVaild;	       //�ṹ���Ƿ���Ч
    int  bG7221BigEndian;  //����G722.1��˽���ģʽ
	char res[120];	       //Ԥ���ֶ�
};

/**	@struct	 NPQ_PARAM 
 *	@brief   Qos���ò���
 *	@note	 
 */
struct NPQ_PARAM
{
	int iVersion;				//�ṹ��汾�������Ժ����
	int m_type;					//Qos�������� NPQ_QOS_TYPE
	int bVideo;					//�Ƿ�����ƵQos
	int bAudio;					//�Ƿ�����ƵQos
	NPQ_PARAM_VALUE_TYPE enValueType;	//��������
	void*  pValue;						//����ֵ
	union DIF_PARAM
	{
		NPQ_SENDER_PARAM struSender;	//���Ͷ˲���
		NPQ_RECEIVER_PARAM struReceiver;//���ն˲���
		unsigned char res[128];	
	}unDifParam;
    unsigned char cVideoQosSet;  //��Ƶ��0�����棻1��ʵʱ�����ȡ�
    unsigned char cAudioQosSet;  //��Ƶ��0�����棻1��ʵʱ�����ȡ�

    char          bEnableCpuSet;  //����cpuָ������
    unsigned int  uCpuSet;        //ָ����CPU��
    unsigned int  uBytesAlign;    //�ֽڶ��붨�壬��ʽ�����ݼ��·�ע�͡�
    int bPrivate;                //�Ƿ���˽��Qos, ��iVersion >=1����
    unsigned char res[105];	                      
}; 

//�ֽڶ��붨��
/* 0                    1                       2                       3	                    ��λ
   0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1 
   +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
   |RTP  |RED  |RTCP |FEC  |
   +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
   ÿ�ַ�װ��ʽռ2bit����װ��ʽĿǰ����˳��Ϊ��RTP��RED��RTCP��FEC�� ������������ʽ��FEC֮����Ӽ��ɡ�
   �ֶ�ֵ��00--���ö��룻 01--4�ֽڶ��룻  10--8�ֽڶ��룻  11--16�ֽڶ��롣    Ŀǰ֧��4�ֽڣ�8�ֽڣ�16�ֽ����ֶ��뷽ʽ��
*/




/**	@struct	 NPQ_SET_NOTIFY_PARAM 
 *	@brief   ����֪ͨ������ֻ���ڽ��նˣ�����ʱ����
 *	@note	 
 */
struct NPQ_SET_NOTIFY_PARAM
{
	int iVersion;				//�ṹ��汾�������Ժ����
	unsigned int nBitRate;		//���� ��λbps
	bool bHaveBitrate;			//�����ֶ��Ƿ���Ч��־
	bool bHaveForceIframe;		//ǿ��I֡�ֶ��Ƿ���Ч��־
	bool bForceIframe;			//ǿ��I֡
	bool bHaveScale;			//scale�ֶ��Ƿ���Ч��־
	float fScale;				//scale��Ϣ  1��2��4��8
	unsigned char res[240];		
};

/**	@enum	 NPQ_STATE 
 *	@brief   NPQ״̬
 *	@note	 
 */
enum NPQ_STATE
{
    NPQ_STATE_INIT = 0,            //NPQ��ʼ��״̬
    NPQ_STATE_PLAY,                //NPQ ����״̬��NPQ��Ӧ�������ݻص����������RTP��RTCP��
    NPQ_STATE_PAUSE,              //NPQ ��ͣ״̬��NPQ��Ӧ��������ֹͣ�ص�������RTP��RTCP��
};

/**	@enum	 NPQ_DATA_INFO_CODE 
 *	@brief   NPQ��Ϣ��
 *	@note	 
 */
enum NPQ_DATA_INFO_CODE
{
    NPQ_DATA_OK = 0,              //����֡
    NPQ_FRAME_INCOMPLETE          //������֡����ǰDATA_TYPE��Ӧ��֡��
};

/**	@enum	 NPQ_DATA_FRAME_TYPE 
 *	@brief   NPQ֡��Ϣ
 *	@note	 
 */
enum NPQ_DATA_FRAME_TYPE
{
    NPQ_DATA_FRAME_UNKNOWN = 0,    //δ֪֡����
    NPQ_DATA_FRAME_VIDEO_I,        //��ƵI֡
    NPQ_DATA_FRAME_VIDEO_P,        //��ƵP֡
    NPQ_DATA_FRAME_AUDIO,          //��Ƶ֡
    NPQ_DATA_FRAME_PRIVAT,         //˽��֡
};

/**	@struct	 NPQ_DATA_INFO 
 *	@brief   NPQ������Ϣ
 *	@note	 
 */
struct NPQ_DATA_INFO
{
    int             iVersion;	   //�ṹ��汾�������Ժ����
    int             iDataType;     //��NPQ_DATA_TYPE����   
    unsigned int    nBuffLen;      //���泤��
    unsigned char*  pBuff;         //����ָ��
    int             iTimeStamp;    //ʱ���
    int             iDataInfoCode; //������Ϣ����NPQ_DATA_INFO_CODE
    int             iFrameType;    //֡���ͣ���NPQ_DATA_FRAME_TYPE
    int             iMainType;     //ý�����ͣ���NPQ_MAIN_TYPE
    char            res[96];       //�����ֶ�
};

/**	@enum	 NPQ_LOG_LEVEL 
 *	@brief   NPQ��־��������ȼ�
 *	@note	 
 */
enum NPQ_LOG_LEVEL
{
    NPQ_LOG_LEVEL_TRACE = 0,
    NPQ_LOG_LEVEL_DEBUG,
    NPQ_LOG_LEVEL_INFO,
    NPQ_LOG_LEVEL_WARN,
    NPQ_LOG_LEVEL_STAT,
    NPQ_LOG_LEVEL_ERROR,
    NPQ_LOG_LEVEL_UNKNOWN
};

/**	@enum	 NPQ_SUB_MOUDLE 
 *	@brief   NPQ��ģ�飬�����ڿ�����־���
 *	@note	 
 */
enum NPQ_SUB_MOUDLE
{
    NPQ_SUB_MODULE_ALL = 0,
    NPQ_SUB_MODULE_JITTER,
    NPQ_SUB_MODULE_NACK,
    NPQ_SUB_MODULE_FEC,
    NPQ_SUB_MODULE_BW,
    NPQ_SUB_MODULE_PACING,
    NPQ_SUB_MODULE_PLI,
    NPQ_SUB_MODULE_NETEQ,
    NPQ_SUB_MODULE_SYN
};




/**	@fn NPQCb
*	@brief �ص�����
*	@param  int id  id��
*	@param  int iDataType  ��������  ��NPQ_DATA_TYPE����
*	@param  unsigned char* pData  ���ݵ�ַ
*	@param  unsigned int uDataLen ���ݳ���
*	@param  void* pUser �ص��û�����
*	@return void
*/
typedef void  (__stdcall *NPQCb)( int id , int iDataType, unsigned char* pData, unsigned int nDataLen, void* pUser);

/**	@fn NPQDataInfoCb
*	@brief ������Ϣ�ص�����
*	@param  int id  id��
*	@param  unsigned char* pData  ���ݵ�ַ��ʹ��NPQ_DATA_INFO�����ݽṹ
*	@param  unsigned int uDataLen ���ݳ��ȣ�NPQ_DATA_INFO�Ĵ�С
*	@param  void* pUser �ص��û�����
*	@return void
*/
typedef void  (__stdcall *NPQDataInfoCb)( int id , void* pDataInfo, unsigned int nDataInfoLen, void* pUser);

/**	@fn NPQLogCb
*	@brief NPQ��־����ص�����
*	@param  iLogLevel           NPQ��־����ȼ�,��NPQ_LOG_LEVEL
*   @param  iNPQSubModule       NPQ��ģ�飬��NPQ_SUB_MOUDLE
*	@param  const char* format  NPQ��־�����ʽ
*	@param  void* varlist       NPQ��־���������varlistָ��Ϊva_list*���û������ٵ���va_start��va_end
*	@param  void* pUser �ص��û�����
*   @param  int id �������ֲ�ͬ������ɵ���־
*	@return void
*/
typedef void  (__stdcall *NPQLogCb)( int iLogLevel, int iNPQSubModule, const char* format, void* varlist, void* pUser, int id);

/**	@fn NPQ_Create
*	@brief ����һ·Qos����
*	@param  NPQ_QOS_ROLE enType  ����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_Create(NPQ_QOS_ROLE enType);

/**	@fn NPQ_Destroy
*	@brief ����һ·Qos����
*	@param  int id  id��
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_Destroy(int id);

/**	@fn NPQ_Start
*	@brief ����һ·Qos����
*	@param  int id  id��
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_Start(int id);

/**	@fn NPQ_Stop
*	@brief ֹͣһ·Qos����
*	@param  int id  id��
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_Stop(int id);

/**	@fn NPQ_RegisterDataCallBack
*	@brief ע�����ݻص�
*	@param  int id  id��
*	@param  NPQCb pCallback �ص�����ָ��
*	@param  void* pUser �û�����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_RegisterDataCallBack(int id, NPQCb pCallback, void* pUser);

/**	@fn NPQ_RegisterDataInfoCallBack
*	@brief ע��������Ϣ�ص�,����NPQ_RegisterDataCallBack�ص���Χ���ص���Ϣ������ϸ
*   @brief �����NPQ_RegisterDataCallBack������ʹ�øú���ע��Ļص�
*	@param  int id  id��
*	@param  NPQDataInfoCb pCallback �ص�����ָ��
*	@param  void* pUser �û�����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_RegisterDataInfoCallBack(int id, NPQDataInfoCb pCallback, void* pUser);

/**	@fn NPQ_RegisterRecoveriedDataCallBack
*	@brief ע�Ό�����ָ������ݻص�
*	@param  int id  id��
*	@param  NPQCb pCallback �ص�����ָ��
*	@param  void* pUser �û�����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_RegisterRecoveriedDataCallBack(int id, NPQCb pCallback, void* pUser);

/**	@fn NPQ_RegisterAudioDecFun
*	@brief ע����Ƶ������غ���
*	@param  int id  id��
*	@param  NPQ_AUDIO_DECODE_FUN* pDecFuns ��Ƶ������غ���
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_RegisterAudioDecFun(int id, NPQ_AUDIO_DECODE_FUN *pRegisterFun);

/**	@fn NPQ_InputData
*	@brief ����RTP��RTCP����
*	@param  int id  id��
*	@param  int iDataType  ��������  ͬNPQ_DATA_TYPE
*	@param  unsigned char* pData  ���ݵ�ַ
*	@param  unsigned int uDataLen ���ݳ���
*	@param  void* pUser �ص��û�����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_InputData(int id, int iDataType, unsigned char* pData, unsigned int nDataLen);

/**	@fn NPQ_InputRawData
*	@brief ���������ݣ��ڲ�����RTP���������֡����
*	@param  int id  id��
*	@param  MUX_PARAM* pMuxParam  �������
*	@param  INPUT_BUF* pstInputData �������ݵ�ַ�ͳ���
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_InputRawData(int id, MUX_PARAM* pMuxParam, INPUT_BUF* pstInputData);

/**	@fn NPQ_SetParam
*	@brief ���ò���
*	@param  int id  id��
*	@param  void* pParam   ��������NPQ_PARAM
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetParam(int id, void* pParam);

/**	@fn NPQ_SetMediaSrcID
*	@brief  ��������ԴID��֧�ֵ���NPQ_Start֮ǰ��֮����øýӿڡ�
*   @       ��������������ԴID������ͬNPQ_MAIN_TYPE������ԴĬ������Դ��һ����
*	@param  int id  id��
*	@param  NPQ_MAIN_TYPE enMainType  Qos������
*	@param  unsigned int nSrcID       ����ԴID����ͬ������ԴIDֵһ��������һ����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetMediaSrcID(int id, NPQ_MAIN_TYPE enMainType, unsigned int nSrcID);

/**	@fn NPQ_SetMinMaxBitrate
*	@brief  ������С������ʣ�֧�ֵ���NPQ_Start֮ǰ��֮����øýӿڡ�
*   @       NPQ�ص�������NPQ_CMD_ENCODE������ֵ���ᳬ����������ʡ�
*   @       ���Ͷ�����NPQ��ƽ�����ʲ��ܳ���ͨ��NPQ_CMD_ENCODE�ص����������ʡ�
*	@param  int id  id��
*	@param  unsigned int nMinBitRate  ��С����
*	@param  unsigned int nMaxBitRate  �������
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetMinMaxBitrate(int id, NPQ_MAIN_TYPE enMainType, unsigned int nMinBitRate, unsigned int nMaxBitRate);

/**	@fn NPQ_SetMediaDelay
*	@brief  ����ý����ʱʱ�䣬֧�ֵ���NPQ_Start֮ǰ��֮����øýӿڡ�
*   @       ��ʱʱ��Ϊ��NPQ�ص������һ�̵���Ⱦ��һ�̵���ʱʱ�䡣
*	@param  int id  id��
*	@param  NPQ_MAIN_TYPE enMainType  Qos������
*	@param  unsigned int nDelayMs     ��NPQ�������Ⱦ����ʱʱ�䣬��λΪms
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetMediaDelay(int id, NPQ_MAIN_TYPE enMainType, unsigned int nDelayMs);

/**	@fn NPQ_SetMediaNTPTimeAndTimeStamp
*	@brief  ����ý��ɼ�ʱ�̵�ʱ���ʱ���������ͨ��RTCP�ӷ��Ͷ˷������նˣ���������Ƶͬ����
*	@param  int id  id��
*	@param  NPQ_MAIN_TYPE enMainType  Qos������
*	@param  long long nCaptureTime    ��1970��1��1����ý�����ݲɼ�ʱ�̵�us������λΪus��
*   @param  unsigned int nTimeStamp   ý�����ݲɼ�ʱ�̵�ʱ�������λ���װ��ʽ�еı���һ��
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetMediaNTPTimeAndTimeStamp(int id, NPQ_MAIN_TYPE enMainType, long long nCaptureTime, unsigned int nTimeStamp);

/**	@fn NPQ_SetNotifyParam
*	@brief ����֪ͨ����
*	@param  int id  id��
*	@param  void* pNotifyParam   ��������NPQ_SET_NOTIFY_PARAM
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetNotifyParam(int id,  NPQ_SET_NOTIFY_PARAM* pNotifyParam);

/**	@fn NPQ_SetState
*	@brief ����NPQ��״̬
*	@param  int id  id��
*	@param  NPQ_MAIN_TYPE enMainType  Qos������
*	@param  NPQ_STATE enState         ��NPQ״̬����Ϊ��״̬
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetState(int id, NPQ_MAIN_TYPE enMainType, NPQ_STATE enState);

/**	@fn NPQ_GetStat
*	@brief ��ȡ״̬
*	@param  int id  id��
*	@param  NPQ_MAIN_TYPE enMainType  Qos������
*	@param  void* pStat  ״̬��Ϣ����NPQ_STAT
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_GetStat(int id,NPQ_MAIN_TYPE enMainType, void* pStat);

/**	@fn NPQ_GetData
*	@brief ��ȡ��Ƶ���ݽӿ�
*	@param  int iDataType  ��������  ��NPQ_DATA_TYPE����
*	@param  unsigned char* pData  ���ݵ�ַ
*	@param  unsigned int* pDataLen ���ݳ���,����ʱΪpData���ȣ����ʱΪ��ȡ�����ݳ���
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_GetData(int id, int iDataType, unsigned char* pData, unsigned int* pDataLen);

/**	@fn NPQ_SetLogFile
*	@brief ������־�ļ�·������֧��hlog��ƽ̨��
*	@param  char* szAbsFileName  ��־�ļ�·���������ļ�����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_SetLogFile(char* szAbsFileName);

/**	@fn NPQ_RegisterLogCallBack
*	@brief ע����־����ص�,��ע���˸ú���������ʹ�øûص���
*   @brief �����NPQ_SetLogFile������ʹ�øú���ע��Ļص�
*	@param  NPQLogCb pCallback �ص�����ָ��
*	@param  void* pUser �û�����
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_RegisterLogCallBack(NPQLogCb pCallback, void* pUser);

/**	@fn NPQ_GetVersion
*	@brief ��ȡ�汾��
*	@param  char* szVersion �汾��Ϣ ��ʽ��Vx.x.x build20xxxxxx
*	@return NPQ������
*/
NPQ_API int __stdcall NPQ_GetVersion(char* szVersion,int nLen);







#endif

