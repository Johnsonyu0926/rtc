/**  @file   LongLinkCtrl.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief 
 *   
 *   @author shijianfengyf2
 *   @modify shijianfengyf2
 *   @date   2018/09/06
 *   
 *   @note:
 */
#ifndef _DEVCOM_EBASE_TRANMIT_LONGLINKCTRL_H_
#define _DEVCOM_EBASE_TRANMIT_LONGLINKCTRL_H_

#include "DevComPublicDef.h"

namespace DevEBase
{
  //  class CLinkBase;
    class CLongLinkCtrlPrivate;

    typedef HPR_BOOL(*LongCfgRecvDataCB)(HPR_VOIDPTR pUserdata, void const *pRecvdata, HPR_UINT32 nDatalen, HPR_UINT32 nStatus);

    //����࣬�����ӷ�װ��ֻ�漰���̲߳����������շ��ӿڵĶ���
    class NET_COM_CLASS CLongLinkCtrl
    {
    public:
        CLongLinkCtrl();
        virtual ~CLongLinkCtrl();

        //---------------������ز���-----------------
        virtual HPR_BOOL CreateLink(const CONNECT_COND *pConnectCond);
        virtual HPR_BOOL Stop();
        HPR_BOOL HasCreateLink() const;

        //---------------�߳���ز���-----------------
        HPR_BOOL StartRecvThread(LongCfgRecvDataCB fRecvCallBack, HPR_VOIDPTR pParam);
        //ֹͣ�߳�
        HPR_VOID StopRecvThread();
        //�������ֻ��m_bExitRecvThread���и�ֵ������ȴ������߳��˳���ʹ�û��������ϲ�ص������з��ֵײ���������д���ʱ�����øýӿ������������̡߳���ΪStopRecvThread
        //�����л�ȴ������߳��˳���������ϲ�Ļص������������ã��ᵼ������������������ExitRecvThread�������
        HPR_VOID ExitRecvThread();
        //�ص�����ʹ��
        HPR_BOOL EnableRecvCallBack(HPR_BOOL bRecvCallBack);
        HPR_BOOL ResumeRecvThread();
        HPR_VOID SuspendRecvThread();

        HPR_INT32 SendData(const HPR_UINT8* pBuff, HPR_UINT32 dwBuffLen, HPR_UINT32 dwTimeOut);
        HPR_BOOL GetLocalIP(void *pStru, HPR_UINT32 dwSize) const;
        HPR_BOOL GetSocket(void *pStru, HPR_UINT32 dwSize) const;

    protected:
        HPR_VOID CheckFreezeThread(HPR_VOID);
        HPR_BOOL NeedAllocRecvBuffer(HPR_VOID) const;
        HPR_VOID FreezeThread(HPR_VOID);
        HPR_VOID UnfreezeThread(HPR_VOID);

        //���������߳�
        static HPR_VOIDPTR CALLBACK RecvThreadCallbackStatic(HPR_VOIDPTR pParam);
        virtual void RecvThreadCallback();
        HPR_BOOL CloseLink();
        HPR_VOID DestroyLink();

        HPR_BOOL CheckResource() const;

        CLongLinkCtrlPrivate *m_pPrivate;
    };
}

#endif // !_DEVCOM_EBASE_TRANMIT_LONGLINKCTRL_H_
