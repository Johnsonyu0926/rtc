/**  @file   MemberMgrBase.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief 
 *   
 *   @author shijianfengyf2
 *   @modify shijianfengyf2
 *   @date   2018/09/12
 *   
 *   @note:
 */
#ifndef _EBASE_BASE_HANDLEMGR_MEMBERMGRBASE_H_
#define _EBASE_BASE_HANDLEMGR_MEMBERMGRBASE_H_

#include "DevComPublicDef.h"

namespace DevEBase
{
    class CMemberBase;
    class CMemberMgrBasePrivate;
    /**    @class CMemberMgrBase
    *     @brief ����������
    *     1.Ϊ�������Ӧ�ٶȣ�������Ա�໥Ӱ�������С��ÿ����Ա��ӵ��һ�������Ҵ����Ժ����SDK cleanup���������١���㣬��4.0����һ�¡�
    *     2.���ͷų�Աʱ������Ҫ�а���ȫ�����ϡ�
    *     3.!!!������������������������CModuleMgrBase����
    */
    class NET_COM_CLASS CMemberMgrBase
    {
    public:
        CMemberMgrBase(HPR_UINT32 uiTotalNum);
        virtual ~CMemberMgrBase();
        virtual HPR_BOOL CheckResource() const;      //��ÿ��ģ��dll�ĳ�ʼ������������֤��ÿ���ⲿ�ӿڶ�Ҫ��֤�Ƿ��ʼ��

        CMemberBase* GetMember(HPR_INT32 iIndex);
        HPR_BOOL IsFull();

        //д������
        HPR_BOOL LockMember(HPR_INT32 iIndex) const;
        HPR_BOOL UnlockMember(HPR_INT32 iIndex) const;
        HPR_BOOL TryLockMember(HPR_INT32 iIndex) const;
        //��������
        HPR_BOOL ReadLockMember(HPR_INT32 iIndex) const;
        HPR_BOOL ReadUnlockMember(HPR_INT32 iIndex) const;

        HPR_UINT32 GetMemberNum();//��ȡ���г�Ա��Ŀ
        HPR_UINT32 GetMaxMemberNum();//��ȡ�Դ��Ա��Ŀ

        virtual void* NewMemoryObject(const void *pCond) = 0;
    protected:

        HPR_INT32 AllocIndex(CMemberBase *pMember);
        //pCond����New��Ա��������pParams���ڿ�ʼʱ����ڲ���
        HPR_INT32 AllocIndex(const void *pCond, void * pParams);
        HPR_BOOL  FreeIndex(HPR_INT32 iIndex, HPR_BOOL bCallStop = HPR_TRUE);

    private:
        CMemberMgrBasePrivate* m_pPrivate;
    };
}
#endif //_EBASE_BASE_HANDLEMGR_MEMBERMGRBASE_H_
