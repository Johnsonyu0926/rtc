/** @file HCChildDev.h
 *  @note HangZhou Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief 
 *
 *  @author liuchuanlong
 *  @modify by liuchuanlong
 *
 *  @date 7/13/2021 
 *
 *  @note
*/

#ifndef _HC_CHILDDEV_H_
#define _HC_CHILDDEV_H_


#include "HCEBase.h"
#include "HPR_Config.h"
#include "HPR_Types.h"

#define MAX_CHILDDEV_MANAGE_TAGS_KEY_LEN 16
#define MAX_CHILDDEV_MANAGE_TAGS_VALUE_LEN 16
#define MAX_CHILDDEV_MANAGE_CHILDDEVID_LEN 40
#define MAX_CHILDDEV_MANAGE_VERSION_LEN 72
#define MAX_CHILDDEV_MANAGE_DEVTYPE_LEN 72
#define MAX_CHILDDEV_MANAGE_IP_LEN 40
#define MAX_CHILDDEV_MANAGE_FIRMWAREIDCODE_LEN 136
#define MAX_CHILDDEV_MANAGE_ENDPOINT_LEN 264

#define MAX_OTAP_MSG_RSP_CODE_LEN 16
#define MAX_OTAP_MSG_RSP_ERRMSG_LEN 128

typedef enum enumIOT_CHILDDEV_MANAGE_MSG_TYPE
{
    CHILDMANAGE_METHOD_UNKNOW = 0,           //δ֪����
    CHILDMANAGE_METHOD_FULLCHILD = 1,        //���豸ȫ���ϱ�,pBodyDataָ��ṹ��:(1)�豸����IOT_CHILDDEV_REPORT_FULLCHILD��2��ƽ̨��Ӧ:IOT_CHILDDEV_REPOERT_REPLY
    CHILDMANAGE_METHOD_FULLCHILDPAGE = 2,    //���豸ȫ���ϱ�(��ҳ)��pBodyDataָ��ṹ��:(1)�豸����IOT_CHILDDEV_REPORT_FULLCHILDPAGE��2��ƽ̨��Ӧ:IOT_CHILDDEV_REPOERT_REPLY
    CHILDMANAGE_METHOD_CHANGECHILD = 3,      //���豸����ϱ���pBodyDataָ��ṹ��:(1)�豸����IOT_CHILDDEV_REPORT_CHANGECHILD��2��ƽ̨��Ӧ:IOT_CHILDDEV_REPOERT_REPLY
    CHILDMANAGE_METHOD_SEARCHDEVICE = 4,     //�����������ܷ��ֵ��豸��pBodyDataָ��ṹ��:(1)ƽ̨����IOT_CHILDDEV_SEARCH_OPERATE_DATA��2���豸��Ӧ:IOT_CHILDDEV_GENERAL_OPERATE_REPLY
    CHILDMANAGE_METHOD_ADDCHILD = 5,         //���豸��ӣ�pBodyDataָ��ṹ��:(1)ƽ̨����IOT_CHILDDEV_ADD_OPERATE_DATA��2���豸��Ӧ:IOT_CHILDDEV_GENERAL_OPERATE_REPLY
    CHILDMANAGE_METHOD_REMOVECHILD = 6,      //���豸ɾ����pBodyDataָ��ṹ��:(1)ƽ̨����IOT_CHILDDEV_REMOVE_OPERATE_DATA��2���豸��Ӧ:IOT_CHILDDEV_GENERAL_OPERATE_REPLY
    CHILDMANAGE_METHOD_SEARCHCHILD = 7,   //��ѯ���豸��Ϣ, pBodyDataָ��ṹ��:(1)ƽ̨����IOT_CHILDDEV_SEARCH_CHILD_OPERATE_DATA��2���豸��Ӧ:IOT_CHILDDEV_GENERAL_OPERATE_REPLY
}IOT_CHILDDEV_MANAGE_MSG_TYPE;

typedef struct struIOT_CHILDDEV_REPOERT_REPLY
{
    HPR_UINT32 dwStatus;                                  
    char       szCode[MAX_OTAP_MSG_RSP_CODE_LEN];
    char       szErrMsg[MAX_OTAP_MSG_RSP_ERRMSG_LEN];
    HPR_UINT8  byRes[128];
}IOT_CHILDDEV_REPOERT_REPLY;

typedef struct struIOT_CHILDDEV_SEARCH_DEVICE_OPERATE
{
    HPR_UINT32 dwPageSize;
    HPR_UINT32 dwPageIndex;
    HPR_UINT8  byRes[128];
}IOT_CHILDDEV_SEARCH_OPERATE_DATA;

typedef struct struIOT_CHILDDEV_ADD_OPERATE_DEV_INFO
{
    char szChildDevID[MAX_CHILDDEV_MANAGE_CHILDDEVID_LEN]; //���豸�ֲ���ʶ��32�ֽڵ�����+��ĸ
    char szEndPoint[MAX_CHILDDEV_MANAGE_ENDPOINT_LEN];     //ͨ��URI��ʽ����
    char byRes[256];
}IOT_CHILDDEV_ADD_OPERATE_DEV_INFO;

typedef struct struIOT_CHILDDEV_ADD_OPERATE_DATA
{
    IOT_CHILDDEV_ADD_OPERATE_DEV_INFO*      pDevInfo;                 
    HPR_UINT32                              dwDevNum;                  
    char byRes[128];
}IOT_CHILDDEV_ADD_OPERATE_DATA; 

typedef struct struIOT_CHILDDEV_REMOVE_OPERATE_DEV_INFO
{
    char szChildDevID[MAX_CHILDDEV_MANAGE_CHILDDEVID_LEN]; //���豸�ֲ���ʶ��32�ֽڵ�����+��ĸ
    char byRes[256];
}IOT_CHILDDEV_REMOVE_OPERATE_DEV_INFO;

typedef struct struIOT_CHILDDEV_REMOVE_OPERATE_DATA
{
    IOT_CHILDDEV_REMOVE_OPERATE_DEV_INFO*      pDevInfo;                  
    HPR_UINT32                                 dwDevNum;              
    char byRes[128];
}IOT_CHILDDEV_REMOVE_OPERATE_DATA; 

typedef struct struIOT_CHILDDEV_SEARCH_CHILD_OPERATE
{
    HPR_UINT32 dwPageSize;
    HPR_UINT32 dwPageIndex;
    HPR_UINT8  byRes[128];
}IOT_CHILDDEV_SEARCH_CHILD_OPERATE_DATA;

typedef struct struIOT_CHILDDEV_MANAGE_SERVER_DATA
{
    HPR_UINT8                        byChildID[MAX_IOT_CHILDID_LEN];             //[out]���豸���к�
    HPR_UINT8                        byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[out]��Դid
    HPR_UINT8                        byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[out]��Դ����
    enumIOT_CHILDDEV_MANAGE_MSG_TYPE enumMsgType;                                //[out]���豸ҵ����Ϣ���ͣ��μ�ö��enumIOT_CHILDDEV_MANAGE_MSG_TYPE 
    HPR_VOIDPTR                      pData;                                      //[out][readonly]���������ݣ������ڻص�֮��ʹ�ø�ָ��
    HPR_UINT32                       dwSequence;                                 //[out]���кţ��豸����Ӧ������ʱ���轫���ֵԭֵ���ø��ӿ�
    HPR_UINT8                        byRes[256];
}IOT_CHILDDEV_MANAGE_SERVER_DATA; 

typedef struct struIOT_CHILDDEV_MANAGE_CLIENT_DATA
{
    HPR_UINT8                        byChildID[MAX_IOT_CHILDID_LEN];             //[in]���豸���к�
    HPR_UINT8                        byResourceID[MAX_IOT_RESOURCE_ID_LEN];      //[in]��Դid
    HPR_UINT8                        byResourceType[MAX_IOT_RESOURCE_TYPE_LEN];  //[in]��Դ����
    enumIOT_CHILDDEV_MANAGE_MSG_TYPE enumMsgType;                                //[in]���豸ҵ����Ϣ���ͣ��μ�ö��enumIOT_CHILDDEV_MANAGE_MSG_TYPE 
    HPR_VOIDPTR                      pBodyData;                                  //[in]���������ݣ��μ�ö��enumIOT_CHILDDEV_MANAGE_MSG_TYPE
    HPR_UINT32                       dwSequence;                                 //[inout]1.�ýṹ�屻NET_EBASE_ChildDevPublishʹ�ã��ñ���Ϊ���Σ�����������Ӧ��Ϣ��2.��NET_EBASE_ChildDevResponseʹ��ʱ��Ϊ���,����ص���dwSequence
    HPR_UINT8                        byRes[256];
}IOT_CHILDDEV_MANAGE_CLIENT_DATA;  


typedef struct struIOT_CHILDDEV_REPORT_ADD_TAGS
{
    HPR_UINT8 szKey[MAX_CHILDDEV_MANAGE_TAGS_KEY_LEN];
    HPR_UINT8 szValue[MAX_CHILDDEV_MANAGE_TAGS_VALUE_LEN];
    HPR_UINT8 byRes[32];
}IOT_CHILDDEV_REPORT_ADD_TAGS; 

typedef struct struIOT_CHILDDEV_COMMEN_CHILDLIST
{  
    char                                    szChildDevID[MAX_CHILDDEV_MANAGE_CHILDDEVID_LEN];            //���豸�ֲ���ʶ��32�ֽڵ�����+��ĸ
    char                                    szVersion[MAX_CHILDDEV_MANAGE_VERSION_LEN];                  //�豸�汾
    char                                    szType[MAX_CHILDDEV_MANAGE_DEVTYPE_LEN];                     //�豸�ͺ�
    char                                    szFirmwareIdCode[MAX_CHILDDEV_MANAGE_FIRMWAREIDCODE_LEN];    //�豸�̼���ʶ��
    HPR_BOOL                                bConnected;                                                  //��ͨ״̬
    IOT_CHILDDEV_REPORT_ADD_TAGS*           pTags;                                                       //Ԫ���ݱ�ǩ���ڲ�Ϊkey-value���飬�ο��ṹ�� IOT_CHILDDEV_REPORT_ADD_TAGS������
    HPR_UINT32                              dwTagsNum;                                                   //Tags����Ŀ
    char                                    byRes[128];
}IOT_CHILDDEV_COMMEN_CHILDLIST;  

typedef struct struIOT_CHILDDEV_REPORT_DELETE_CHILDLIST
{
    char       szChildDevID[MAX_CHILDDEV_MANAGE_CHILDDEVID_LEN];  //���豸�ֲ���ʶ��32�ֽڵ�����+��ĸ
    HPR_UINT32 dwDevIdLen;
    char       byRes[124];
}IOT_CHILDDEV_REPORT_DELETE_CHILDLIST;  


typedef struct struIOT_CHILDDEV_REPORT_FULLCHILD{
    HPR_UINT32                               dwVersion;		        //���version=0ȫ���ϱ�
    IOT_CHILDDEV_COMMEN_CHILDLIST*           pChildList;			
    HPR_UINT32                               dwChildListNum;	    //ChildList����Ŀ
    char                                     byRes[128];
}IOT_CHILDDEV_REPORT_FULLCHILD; 


typedef struct struIOT_CHILDDEV_REPORT_FULLCHILDPAGE
{
    HPR_UINT32                               dwVersion;          //�汾�ţ����version=0ȫ���ϱ�
    HPR_UINT32                               dwPageSize;         //��ҳ��С�����ݷ�ҳ��С���ö�ʱ���Է�ҳ�ϱ����м�أ�һҳ10��
    HPR_UINT32                               dwPageIndex;        //��ҳ����
    IOT_CHILDDEV_COMMEN_CHILDLIST*           pChildList;         //�ο��ṹ��
    HPR_UINT32                               dwChildListNum;     // childList����Ŀ
    char                                     byRes[128];
}IOT_CHILDDEV_REPORT_FULLCHILDPAGE; 


typedef struct struIOT_CHILDDEV_REPORT_CHANGECHILD
{
    HPR_UINT32                              dwDiffVersion; //�Ƚϵİ汾��
    HPR_UINT32                              dwVersion;     //�汾��
    IOT_CHILDDEV_COMMEN_CHILDLIST*          pAddChildList; //�������豸�б�
    HPR_UINT32                              dwAddListNum;
    IOT_CHILDDEV_REPORT_DELETE_CHILDLIST *  pDelChildList; //ɾ�����豸�б�
    HPR_UINT32                              dwDelListNum; 
    IOT_CHILDDEV_COMMEN_CHILDLIST*          pModChildList; //�޸����豸�б�
    HPR_UINT32                              dwModListNum;
    char                                    byRes[128];
}IOT_CHILDDEV_REPORT_CHANGECHILD; 

typedef struct struIOT_CHILDDEV_SEARCH_CHILDLIST_OPERATE_REPLY
{
    char           szChildDevID[MAX_CHILDDEV_MANAGE_CHILDDEVID_LEN];   //���豸�ֲ���ʶ��32�ֽڵ�����+��ĸ
    char           szVersion[MAX_CHILDDEV_MANAGE_VERSION_LEN];         //�豸�汾
    char           szType[MAX_CHILDDEV_MANAGE_DEVTYPE_LEN];            //�豸�ͺ�
    char           szIP[MAX_CHILDDEV_MANAGE_IP_LEN];                   //���ṩ��Ե��HUB�豸���ʵ�IP
    HPR_UINT32     dwPort;                                             //���ṩ��Ե��HUB�豸���ʵĶ˿�
    char           byRes[128];
}IOT_CHILDDEV_SEARCH_CHILDLIST_OPERATE_REPLY;  

typedef struct struIOT_CHILDDEV_GENERAL_OPERATE_REPLY
{
    char        szCode[MAX_OTAP_MSG_RSP_CODE_LEN];
    char        szErrMsg[MAX_OTAP_MSG_RSP_ERRMSG_LEN];
    HPR_UINT32  dwStatus;
    HPR_UINT32  dwPageCount;                                          // ��response ���� CHILDMANAGE_METHOD_SEARCHDEVICE��CHILDMANAGE_METHOD_SEARCHCHILD ʹ��
    IOT_CHILDDEV_SEARCH_CHILDLIST_OPERATE_REPLY * pSearchDevList;     // ��response ���� CHILDMANAGE_METHOD_SEARCHDEVICE  ʹ�� IOT_CHILDDEV_SEARCH_CHILDLIST_OPERATE_REPLY  
    IOT_CHILDDEV_COMMEN_CHILDLIST * pSearchChildList;                 // ��response ���� CHILDMANAGE_METHOD_SEARCHCHILD   ʹ�� IOT_CHILDDEV_COMMEN_CHILDLIST  
    HPR_UINT32  dwDevListNum;                                         // pSearchDevList�������
    HPR_UINT32  dwChildListNum;                                       // pSearchChildList�������
    HPR_UINT8   byRes[116];
}IOT_CHILDDEV_GENERAL_OPERATE_REPLY; 


typedef void (CALLBACK* ChildDevManageMsgCB)(HPR_INT32 iHandle, IOT_CHILDDEV_MANAGE_SERVER_DATA* pData, HPR_VOIDPTR pUserData);

typedef struct struIOT_CHILDDEV_MANAGE_MSG_CB_PARAM{
    ChildDevManageMsgCB   fnCB;                  
    HPR_VOIDPTR           pUser;                
    HPR_UINT8             byRes[128];
}IOT_CHILDDEV_MANAGE_MSG_CB_PARAM;

typedef struct struIOT_CHILDDEV_MANAGE_INIT_PARAM{
    IOT_CHILDDEV_MANAGE_MSG_CB_PARAM struMsgCB;
    HPR_UINT8 byRes[256];
}IOT_CHILDDEV_MANAGE_INIT_PARAM;

NET_COM_API HPR_BOOL   CALLBACK IOT_CHILDDEV_MANAGE_Init(IOT_CHILDDEV_MANAGE_INIT_PARAM *pParam);
NET_COM_API HPR_BOOL   CALLBACK IOT_CHILDDEV_MANAGE_Fini();
NET_COM_API HPR_BOOL   CALLBACK IOT_CHILDDEV_MANAGE_ReponseMsg(HPR_INT32 iHandle, IOT_CHILDDEV_MANAGE_CLIENT_DATA* pParam);
NET_COM_API HPR_BOOL   CALLBACK IOT_CHILDDEV_MANAGE_PublishMsg(HPR_INT32 iHandle, IOT_CHILDDEV_MANAGE_CLIENT_DATA* pParam);


#endif // _HCCHILDDEV_H_
