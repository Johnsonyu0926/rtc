/**  @file   EBaseInnerInterface.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief  ר���ڲ�ͷ�ļ�ʹ�� 
 *   
 *   @author shijianfengyf2
 *   @modify shijianfengyf2
 *   @date   2018/09/26
 *   
 *   @note:
 */

#include "HCEBase.h"
namespace DevEBase
{

    NET_COM_API HPR_VOID CALLBACK EBASE_INNER_Assert();
    NET_COM_API HPR_UINT32 CALLBACK EBASE_INNER_CheckInit();
    /** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_SetLastError(HPR_UINT32 uiError)
    *  @brief ���ô������ⲿ�ӿ�
    *  @return HPR_UINT32 ������ֵ��0���޴�������ֵΪ������
    */
    NET_COM_API HPR_BOOL CALLBACK EBASE_INNER_SetLastError(HPR_UINT32 uiError);
    /** @fn	NET_COM_API HPR_UINT32 CALLBACK NET_EBASE_WriteLog()
    *  @brief д��־
    *  @return	HPR_UINT32 �汾��
    */
    NET_COM_API HPR_BOOL   CALLBACK EBASE_INNER_WriteLog(HPR_UINT32 level, char const *pContent);

    /** @fn	NET_COM_API HPR_BOOL CALLBACK EBASE_INNER_GetMiddleString()
    *  @brief ��ȡĳһ���ַ���
    *  @return	HPR_BOOL
    */
    NET_COM_API HPR_BOOL   CALLBACK  EBASE_INNER_GetMiddleString(const char *pInBuff, HPR_UINT32 dwInLen, const char *pPreStr, const char *pSufStr, char *pOutBuf, HPR_UINT32 dwOutLen);
    
    NET_COM_API const char* CALLBACK EBASE_INNER_StrnStr(const char* pSrcBuff, const char* pDstBuff, HPR_UINT32 dwSrcBuffLen);

    /** @fn	NET_COM_API HPR_UINT32 CALLBACK EBASE_INNER_ModuleInit() EBASE_INNER_ModuleFini()
    *  @brief ģ���ʼ��/����ʼ���ڲ��ӿڣ���ֱֹ�ӵ���NET_EBASE_Init��NET_EBASE_Fini
    *  @return	HPR_BOOL
    */
    NET_COM_API HPR_BOOL CALLBACK EBASE_INNER_ModuleInit(const char *pModule);
    NET_COM_API HPR_BOOL CALLBACK EBASE_INNER_ModuleFini(const char *pModule);

    NET_COM_API HPR_BOOL CALLBACK NET_EBASE_GetLocalCfg(HPR_UINT32 dwType, HPR_VOIDPTR pParam);

    //NET_COM_API HPR_INT32   CALLBACK NET_EBASE_SetMessageCallBack(LPNET_EBASE_OBERSER lpMsgInfo);
    //NET_COM_API HPR_INT32   CALLBACK EBASE_INNER_SetMessageCallBack(LPNET_EBASE_OBERSER lpMsgInfo, HPR_UINT32* pDwEzvizError);
    //�������������ӿ�˵����
    //pDwEzvizErrorֻ��өʯ�������ܵ�model���ʹ�ã�����HCIoTstorage�ȿⲻ��ҪpDwEzvizError����
    //�����豸������������֧�ֽӿڶ���Ĭ�ϲ��������Ա��ӿ��޷�ֱ�Ӷ����Ĭ�ϲ���
    //���Է�װһ��ӿڣ��豸APPֻ��Ҫʹ��NET_EBASE_SetMessageCallBack��NET_EBASE_RemoveMsgCallBack
    NET_COM_API HPR_INT32   CALLBACK EBASE_INNER_SetMessageCallBack(LPNET_EBASE_OBERSER lpMsgInfo);
    NET_COM_API HPR_INT32   CALLBACK EBASE_INNER_RemoveMsgCallBack(LPNET_EBASE_REMOVE_OBERSER lpMsgInfo);


    NET_COM_API HPR_BOOL  CALLBACK EBASE_INNER_RegDomainCB(HPR_INT32 iHandle, const char* pModule);

    NET_COM_API HPR_UINT32 CALLBACK EBASE_INNER_CalculatePaddingLen(HPR_UINT32 dwLen);
    NET_COM_API HPR_UINT32 CALLBACK EBASE_INNER_AesCbc128Decrypt(const unsigned char Aeskey[16], const unsigned char *pInputBuf, HPR_UINT32 dwInputLen, unsigned char *pOutputBuf, HPR_UINT32 *pOutputLen, char* pAESIV = NULL);
    NET_COM_API void CALLBACK EBASE_INNER_BufPadding(unsigned char* pBuf, HPR_UINT32 dwPaddingLen, HPR_UINT32 dwLen);
    NET_COM_API HPR_UINT32 CALLBACK EBASE_INNER_AesCbc128Encrypt(const unsigned char Aeskey[16], unsigned char *pInputBuf, HPR_UINT32 dwInputLen, HPR_UINT32 dwInputLenPadding, unsigned char *pOutputBuf, HPR_UINT32 *pOutputLen, char* pAESIV = NULL);

    NET_COM_API HPR_VOID EBASE_INNER_HexDump(unsigned const char* pSrc, int iLen, int iUpper, unsigned char* pDst);
    NET_COM_API HPR_VOID EBASE_INNER_DelArray(HPR_VOIDPTR pAddress);
    NET_COM_API HPR_VOIDPTR EBASE_INNER_NewArray(HPR_UINT32 dwSize);
    NET_COM_API HPR_BOOL CALLBACK EBASE_INNER_GetMulKernelPtr(HPR_INT32 iHandle, HPR_VOIDPTR *pKernel);

    //NET_COM_API HPR_BOOL EBASE_INNER_OtapGetSessionKey(CEHomeSessionBase *pSession, LPNET_EALARM_IOT_REGINFO lpRegInfo, HPR_UINT8 szSessionKey[16], TOPICFILTER &mapTopicFilter);
}

