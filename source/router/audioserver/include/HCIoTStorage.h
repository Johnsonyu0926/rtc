/**  @file   HCIoTStorage.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief  �ⲿ�ӿ�
 *   
 *   @author zhangqing2
 *   @modify 
 *   @date   2020/10/27
 *   
 *   @note:
 */

#ifndef _IOT_CLIENT_STORAGE_INTERFACE_H_
#define _IOT_CLIENT_STORAGE_INTERFACE_H_


#include "HCEBase.h"


#define MAX_IOT_STORAGE_ID_LEN  128
#define MAX_IOT_KEYWORD_LEN     256
#define MAX_IOT_FILE_PATH_LEN   260
#define MAX_IOT_SOTR_URL_LEN    1024
#define MAX_IOT_ALGORITHM_LEN   64
#define MAX_IOT_STORAGE_ENCRYPTION_KEY_LEN   32
#define MAX_IOT_STORAGE_EVENT_TIME_LEN       32

typedef struct tagNET_IOT_STOR_ABILITY_CFG
{
    HPR_UINT32  dwSize;             //[in]�ṹ���С
    HPR_UINT32  dwUploadCount;      //[in]�ϴ��ļ��ܹ�֧�ֵ�·����Ĭ��1,���128
    HPR_UINT32  dwDownloadCount;    //[in]�����ļ��ܹ�֧�ֵ�·����Ĭ��1,���128
    HPR_UINT8   byRes[512];
}NET_IOT_STOR_ABILITY_CFG, *LPNET_IOT_STOR_ABILITY_CFG;

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_Init(LPNET_IOT_STOR_ABILITY_CFG lpStruAbility)
*  @brief  ��ʼ����
*  @param (in)	LPNET_IOT_STOR_ABILITY_CFG lpStruAbility
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_Init(LPNET_IOT_STOR_ABILITY_CFG lpStruAbility);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_Fini()
*  @brief  ����ʼ����
*  @param (in)
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_Fini();

/** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_IOT_STOR_GetBuildVersion()
*  @brief ��ȡ�汾��
*  @return	HPR_UINT32 �汾��
*/
NET_COM_API HPR_UINT32 CALLBACK NET_IOT_STOR_GetBuildVersion();


typedef struct tagNET_IOT_STOR_UPLOAD_RET
{
    HPR_UINT32  dwSize;                         //[out]�ṹ�峤��
    HPR_UINT8   byStorageId[MAX_IOT_STORAGE_ID_LEN];//[out]�洢�����ʶ
    HPR_UINT32  dwExpireAfterDays;              //[out]�ļ�����ʱ�䣬��λ��
    HPR_UINT8   byRes[128];                     //[Res]�����������ֽڶ���
}NET_IOT_STOR_UPLOAD_RET, *LPNET_IOT_STOR_UPLOAD_RET;


typedef struct tagNET_IOT_STOR_UPLOAD_SUCC_INFO
{
    HPR_UINT32  dwSize;                         //[out]�ṹ�峤��
    HPR_UINT32  dwProcess;                      //[out]�ϴ�����ֵ
    HPR_UINT8   byStorageId[MAX_IOT_STORAGE_ID_LEN];//[out]�洢�����ʶ
    HPR_UINT8   byEncryptionKey[MAX_IOT_STORAGE_ENCRYPTION_KEY_LEN];  //[out]ͼƬ������Կ����ͼƬδ���ܣ�����Ϊ��
    HPR_UINT8   byEventTime[MAX_IOT_STORAGE_EVENT_TIME_LEN];          //[out]ͼƬ����ʱ�䣬��ͼƬδ���ܣ�����Ϊ��
    HPR_UINT8   byRes[64];                     //[Res]�����������ֽڶ���
}NET_IOT_STOR_UPLOAD_SUCC_INFO, *LPNET_IOT_STOR_UPLOAD_SUCC_INFO;


typedef enum enumIoTStorUploadStatus
{
    UPLOAD_STATUS_UNKNOW = -1,          //δ֪���ͣ� ClassType(pData) = NULL
    UPLOAD_STATUS_EXPECTION = 0,        //�����쳣�� ClassType(pData) = NET_IOT_STOR_EXCEPTION *����ʾ����
    UPLOAD_STATUS_GET_STOR_INFO = 1,    //           ClassType(pData) = LPNET_IOT_STOR_UPLOAD_RET����ʾƽ̨�����ϴ���Ϣ
    UPLOAD_STATUS_PROCESSING = 2,       //�ϴ��У�   ClassType(pData) = HPR_UINT32 *����ʾ���ȣ�0-100��
    UPLOAD_STATUS_SUCC = 3,             //�ϴ���ɣ� ClassType(pData) = LPNET_IOT_STOR_UPLOAD_SUCC_INFO����ʾ�ϴ��ɹ���Ϣ
}IoTStorUploadStatus;

typedef enum enumIoTStorUploadBizType
{
    UPLOAD_BIZ_TYPE_UNKNOW = -1,          //δ֪���ͣ� ClassType(pData) = NULL
    UPLOAD_BIZ_TYPE_ISAPI = 0,            //ͼƬ������ҵ���¼�����isapiЭ���ϴ�
}IoTStorUploadBizType;

typedef enum enumNET_IOT_STOR_PARAM_TYPE
{
    IOT_STOR_DOWNLOAD_INFO = 0,     //����storageID��ȡ����url��ַ��handle����ע��������������ṹ��NET_IOT_STOR_DOWNLOAD_PARAM����������ṹ��NET_IOT_STOR_DOWNLOAD_INFO
}NET_IOT_STOR_PARAM_TYPE;

typedef struct tagNET_IOT_STOR_EXCEPTION
{
    HPR_UINT32 dwErrorCode;     //��������룬�ο�HCEBase.hȫ�ִ�����
    HPR_UINT32 dwHttpState;    //http״̬��Ϊ0����200��ʾû�д���������ο�http��׼�����룬dwErrorCode = DEV_COM_ERROR_HTTP_ERRORʱ��Ч
}NET_IOT_STOR_EXCEPTION, *LPNET_IOT_STOR_EXCEPTION;

typedef void (CALLBACK *IoTStorUploadClientCB)(HPR_INT32 lUploadHandle, IoTStorUploadStatus dwStatus, HPR_UINT32 dwLen, HPR_VOIDPTR pData, HPR_VOIDPTR pUserData);
typedef struct tagNET_IOT_STOR_UPLOAD_PARAM
{
    HPR_UINT32  dwSize;                                     //[in]�ṹ�峤��
    HPR_UINT8   bySubSerial[MAX_IOT_SERIAL_LEN];            //[in]���豸���к�,�����ã��ɲ���
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[in]��Դid,�����ã��ɲ���
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[in]��Դ����,�����ã��ɲ���
    HPR_UINT8   byDomainID[MAX_IOT_DOMAIN_ID_LEN];          //[in]��Ϣ����id,��1���¼�ͨ��OTAPЭ���ϱ�ʱ�����ֶ�Ϊ�����¼�����Ϣ����ID��2��enumBizType=UPLOAD_BIZ_TYPE_ISAPIʱ����ʾ�¼�ͨ��OTAP͸��ISAPIЭ���ϱ������ֶ�Ϊ�ַ���"ISAPIDataOverOTAP"
    HPR_UINT8   byIdentifier[MAX_IOT_IDENTIFIER_LEN];       //[in]ҵ���ʶ��1���¼�ͨ��OTAPЭ���ϱ�ʱ�����ֶ�Ϊ�����¼���ҵ���ʶ��2��enumBizType=UPLOAD_BIZ_TYPE_ISAPIʱ����ʾ�¼�ͨ��OTAP͸��ISAPIЭ���ϱ������ֶ�Ϊ�ַ���"ISAPIDataOnEvent"
    HPR_UINT8   byKeyword[MAX_IOT_KEYWORD_LEN];             //[in]��1���¼�ͨ��OTAPЭ���ϱ�ʱ�����ֶ�Ϊ�洢�������¼��е�·��������JSON PATH����$.payload.alarmPic��2��enumBizType=UPLOAD_BIZ_TYPE_ISAPIʱ����ʾ�¼�ͨ��OTAP͸��ISAPIЭ���ϱ������ֶ�Ϊ�ַ���"ISAPIDataOnPicture"
    HPR_UINT8   byReadFileMethod;                           //[in]��ȡ�ļ���ʽ��0-�ļ�·����1-�����ļ�buff��2-�ص��з��������ļ�buff�������ڴ��ļ�����������δʵ�֣�
    char        sFileName[MAX_IOT_FILE_PATH_LEN];           //[in]byReadFileMethod = 0���ļ�·����ʱ��Ч������Ϊ�ļ�·����SDK�ڲ���ȡ�ļ�
    char*       pFileBuffer;                                //[in]byReadFileMethod = 1���ļ�buff��ʱ��Ч������Ϊ�ļ�buffer
    HPR_UINT32  dwFileBufLen;                               //[in]byReadFileMethod = 1���ļ�buff��ʱ��Ч������Ϊ�ļ�buffer����
    HPR_UINT32  dwFileType;                                 //[in]�ļ����ͣ�0-ͼƬ��1-�������ļ�
    HPR_VOIDPTR fnCBRes;                                    //[in]byReadFileMethod = 2���ص������ļ�buff��ʱ��Ч�������ڴ��ļ�����������δʵ�֣�
    HPR_VOIDPTR pUserDataRes;                               //[in]�û����ݣ������ڴ��ļ�����������δʵ�֣�
    IoTStorUploadClientCB fnCallBack;                       //[out]�ص��ϴ����ȡ�״̬�����
    HPR_VOIDPTR pUserData;                                  //[in]�û�����
    HPR_UINT8   byEncrypt;                                  //[in]���ݼ���, 0-�����ܣ�1-����
    IoTStorUploadBizType   enumBizType;                     //[in]�μ�ö��IoTStorUploadBizType
    HPR_UINT8   byRes[507];                                 //[Res]�����������ֽڶ���
}NET_IOT_STOR_UPLOAD_PARAM, *LPNET_IOT_STOR_UPLOAD_PARAM;

typedef struct tagNET_IOT_STOR_UPLOAD_SYN_PARAM
{
    HPR_UINT8   bySubSerial[MAX_IOT_SERIAL_LEN];            //[in]���豸���к�,�����ã��ɲ���
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[in]��Դid,�����ã��ɲ���
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[in]��Դ����,�����ã��ɲ���
    HPR_UINT8   byDomainID[MAX_IOT_DOMAIN_ID_LEN];          //[in]��Ϣ����id,��1���¼�ͨ��OTAPЭ���ϱ�ʱ�����ֶ�Ϊ�����¼�����Ϣ����ID��2��enumBizType=UPLOAD_BIZ_TYPE_ISAPIʱ����ʾ�¼�ͨ��OTAP͸��ISAPIЭ���ϱ������ֶ�Ϊ�ַ���"ISAPIDataOverOTAP"
    HPR_UINT8   byIdentifier[MAX_IOT_IDENTIFIER_LEN];       //[in]ҵ���ʶ��1���¼�ͨ��OTAPЭ���ϱ�ʱ�����ֶ�Ϊ�����¼���ҵ���ʶ��2��enumBizType=UPLOAD_BIZ_TYPE_ISAPIʱ����ʾ�¼�ͨ��OTAP͸��ISAPIЭ���ϱ������ֶ�Ϊ�ַ���"ISAPIDataOnEvent"
    HPR_UINT8   byKeyword[MAX_IOT_KEYWORD_LEN];             //[in]��1���¼�ͨ��OTAPЭ���ϱ�ʱ�����ֶ�Ϊ�洢�������¼��е�·��������JSON PATH����$.payload.alarmPic��2��enumBizType=UPLOAD_BIZ_TYPE_ISAPIʱ����ʾ�¼�ͨ��OTAP͸��ISAPIЭ���ϱ������ֶ�Ϊ�ַ���"ISAPIDataOnPicture"
    HPR_UINT8   byEncrypt;                                  //[in]���ݼ���, 0-�����ܣ�1-����
    HPR_UINT8   byRes1[2];                                   //[Res]
    HPR_UINT8   byReadFileMethod;                           //[in]��ȡ�ļ���ʽ��0-�ļ�·����1-�����ļ�buf
    char        sFileName[MAX_IOT_FILE_PATH_LEN];           //[in]byReadFileMethod = 0���ļ�·����ʱ��Ч������Ϊ�ļ�·����SDK�ڲ���ȡ�ļ�
    char*       pFileBuffer;                                //[in]byReadFileMethod = 1���ļ�buf��ʱ��Ч������Ϊ�ļ�buffer
    HPR_UINT32  dwFileBufLen;                               //[in]byReadFileMethod = 1���ļ�buf��ʱ��Ч������Ϊ�ļ�buffer����
    HPR_UINT32  dwFileType;                                 //[in]�ļ����ͣ�0-ͼƬ��1-�������ļ�
    HPR_UINT8   byStorageId[MAX_IOT_STORAGE_ID_LEN];        //[out]�洢�����ʶ
    HPR_UINT32  dwExpireAfterDays;                          //[out]�ļ�����ʱ�䣬��λ��
    HPR_UINT8   byRes2[4];                                   //[Res]]
    HPR_UINT8   byEncryptionKey[MAX_IOT_STORAGE_ENCRYPTION_KEY_LEN];  //[out]������Կ��byEncrypt=1ʱ��Ч
    HPR_UINT8   byEventTime[MAX_IOT_STORAGE_EVENT_TIME_LEN];          //[out]����ʱ�䣬byEncrypt=1ʱ��Ч
    IoTStorUploadBizType   enumBizType;                     //[in] �μ�ö��IoTStorUploadBizType
    HPR_UINT8   byRes[508];                                 //[Res]�����������ֽڶ���
}NET_IOT_STOR_UPLOAD_SYN_PARAM, *LPNET_IOT_STOR_UPLOAD_SYN_PARAM;
/** @fn	NET_COM_API HPR_INT32 CALLBACK NET_IOT_STOR_CreateUploadClient()
*  @brief  �����ϴ��ͻ��˶���
*  @param (in) HPR_INT32 iLoginHandle ע�᷵�ؾ��
*  @return	HPR_INT32 ����/-1 �ɹ�/ʧ��
*/
NET_COM_API HPR_INT32   CALLBACK NET_IOT_STOR_CreateUploadClient(HPR_INT32 iLoginHandle);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_UploadFile()
*  @brief  �ϴ��ļ�
*  @param (in) HPR_INT32 iUploadHandle �ϴ����
*  @param (in) LPNET_IOT_STOR_UPLOAD_PARAM lpUploadParam �ϴ�����
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_IOT_STOR_UploadFile(HPR_INT32 iUploadHandle, LPNET_IOT_STOR_UPLOAD_PARAM lpUploadParam);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_UploadFileSyn()
*  @brief  �ϴ��ļ�ͬ���ӿ�
*  @param (in) HPR_INT32 iUploadHandle �ϴ����
*  @param (in) LPNET_IOT_STOR_UPLOAD_SYN_PARAM lpUploadSynParam �ϴ�����
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_IOT_STOR_UploadFileSyn(HPR_INT32 iUploadHandle, LPNET_IOT_STOR_UPLOAD_SYN_PARAM lpUploadSynParam);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_UploadClose()
*  @brief  �����ϴ��ͻ��˶���
*  @param (in) HPR_INT32 iUploadHandle �ϴ����
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_IOT_STOR_UploadClose(HPR_INT32 iUploadHandle);




typedef enum enumIoTStorDownloadStatus
{
    DOWNLOAD_STATUS_UNKNOW = -1,          //δ֪���ͣ� ClassType(pData) = NULL
    DOWNLOAD_STATUS_EXPECTION = 0,        //�����쳣�� ClassType(pData) = NET_IOT_STOR_EXCEPTION *����ʾ����
    DOWNLOAD_STATUS_DATA_SIZE = 1,       //���ص��ļ���С��ClassType(pData) = HPR_UINT32 *����ʾ�ļ���С����λByte
    DOWNLOAD_STATUS_DATA = 2,             //���ص����ݣ�ClassType(pData) = HPR_VOIDPTR����ʾ���ص��ļ�buff
    DOWNLOAD_STATUS_SUCC = 3,             //������ɣ� ClassType(pData) = HPR_UINT32 *����ʾ���ȣ�ֵΪ100��
}IoTStorDownloadStatus;

typedef void (CALLBACK *IoTStorDownloadClientCB)(HPR_INT32 lDownloadHandle, IoTStorDownloadStatus dwStatus, HPR_UINT32 dwLen, HPR_VOIDPTR pData, HPR_VOIDPTR pUserData);

typedef struct tagNET_IOT_STOR_DOWNLOAD_PARAM
{
    HPR_UINT32  dwSize;                                     //[in]�ṹ�峤��
    HPR_UINT8   bySubSerial[MAX_IOT_SERIAL_LEN];            //[in]���豸���к�
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[in]��Դid
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[in]��Դ����
    HPR_UINT8   byStorageId[MAX_IOT_STORAGE_ID_LEN];              //[in]�洢�����ʶ
    IoTStorDownloadClientCB fnCallBack;                     //[out]�ص����ص����ݣ�����ȡURLʱ�ɲ�����
    HPR_VOIDPTR pUserData;                                  //[in]�û�����
    HPR_UINT8   byEncryptionKey[MAX_IOT_STORAGE_ENCRYPTION_KEY_LEN];  //[in]ͼƬ������Կ����ͼƬδ���ܣ�����
    HPR_UINT8   byEventTime[MAX_IOT_STORAGE_EVENT_TIME_LEN];          //[in]ͼƬ����ʱ�䣬��ͼƬδ���ܣ�����
    HPR_UINT8   byRes[448];                                 //[Res]�����������ֽڶ���
}NET_IOT_STOR_DOWNLOAD_PARAM, *LPNET_IOT_STOR_DOWNLOAD_PARAM;

typedef struct tagNET_IOT_STOR_DOWNLOAD_SYN_PARAM
{
    HPR_UINT32  dwSize;                                     //[in]�ṹ�峤��
    HPR_UINT8   bySubSerial[MAX_IOT_SERIAL_LEN];            //[in]���豸���к�
    HPR_UINT8   byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[in]��Դid
    HPR_UINT8   byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[in]��Դ����
    HPR_UINT8   byStorageId[MAX_IOT_STORAGE_ID_LEN];              //[in]�洢�����ʶ
    HPR_UINT32   dwBufferSize;              //[in]�û�����ģ����ڽ����������ݵ�buffer��С
    HPR_VOIDPTR pDataBuffer;            //[out]��������
    HPR_UINT32 dwDownloadSize;      //[out]�������ݵ�ʵ�ʴ�С
    HPR_UINT8   byEncryptionKey[MAX_IOT_STORAGE_ENCRYPTION_KEY_LEN];  //[in]ͼƬ������Կ����ͼƬδ���ܣ�����
    HPR_UINT8   byEventTime[MAX_IOT_STORAGE_EVENT_TIME_LEN];          //[in]ͼƬ����ʱ�䣬��ͼƬδ���ܣ�����
    HPR_UINT8   byRes[480];                                 //[Res]�����������ֽڶ���
}NET_IOT_STOR_DOWNLOAD_SYN_PARAM, *LPNET_IOT_STOR_DOWNLOAD_SYN_PARAM;

typedef struct tagNET_IOT_STOR_DOWNLOAD_INFO
{
    HPR_UINT8   byUrl[MAX_IOT_SOTR_URL_LEN];
    HPR_BOOL    bEncrypt;
    HPR_UINT8   byAlgorithm[MAX_IOT_ALGORITHM_LEN];
    HPR_UINT8   byRes[256];
}NET_IOT_STOR_DOWNLOAD_INFO, *LPNET_IOT_STOR_DOWNLOAD_INFO;

/** @fn	NET_COM_API HPR_INT32 CALLBACK NET_IOT_STOR_CreateDownloadClient()
*  @brief  �������ؿͻ��˶���
*  @param (in) HPR_INT32 iLoginHandle ע�᷵�ؾ��
*  @return	HPR_INT32 ����/-1 �ɹ�/ʧ��
*/
NET_COM_API HPR_INT32   CALLBACK NET_IOT_STOR_CreateDownloadClient(HPR_INT32 iLoginHandle);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_DownloadFile()
*  @brief  �����ļ�
*  @param (in) HPR_INT32 iDownloadHandle ���ؾ��
*  @param (in) LPNET_IOT_STOR_DOWNLOAD_PARAM lpDownloadParam ���ز���
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_IOT_STOR_DownloadFile(HPR_INT32 iDownloadHandle, LPNET_IOT_STOR_DOWNLOAD_PARAM lpDownloadParam);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_DownloadFile()
*  @brief  �����ļ�ͬ���ӿ�
*  @param (in) HPR_INT32 iDownloadHandle ���ؾ��
*  @param (in) LPNET_IOT_STOR_DOWNLOAD_SYN_PARAM lpDownloadParam ���ز���
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_IOT_STOR_DownloadFileSyn(HPR_INT32 iDownloadHandle, LPNET_IOT_STOR_DOWNLOAD_SYN_PARAM lpDownloadParam);

/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_DownloadClose()
*  @brief  �������ؿͻ��˶���
*  @param (in) HPR_INT32 iUploadHandle ���ؾ��
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_IOT_STOR_DownloadClose(HPR_INT32 iDownloadHandle);


/** @fn	NET_COM_API HPR_BOOL CALLBACK NET_IOT_STOR_GetParam()
*  @brief  �洢ģ���ȡ�����ӿ�
*  @param (in) HPR_INT32 iHandle ע�������ߴ洢���������������й�
*  @param (in) HPR_UINT32 dwType �������ͣ��ο�NET_IOT_STOR_PARAM_TYPEö��
*  @param (in) HPR_VOIDPTR pParamIn �������ָ��
*  @param (in) HPR_UINT32 dwInLen ���������С
*  @param (out) HPR_VOIDPTR pParamOut �������ָ��
*  @param (in) HPR_UINT32 dwOutLen ���������С
*  @return	HPR_BOOL HPR_TRUE/HPR_FALSE �ɹ�/ʧ��
*/
NET_COM_API HPR_BOOL   CALLBACK NET_IOT_STOR_GetParam(HPR_INT32 iHandle, HPR_UINT32 dwType, HPR_VOIDPTR pParamIn, HPR_UINT32 dwInLen, HPR_VOIDPTR pParamOut, HPR_UINT32 dwOutLen);


#endif //_IOT_CLIENT_STORAGE_INTERFACE_H_
