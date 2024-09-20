/**  @file   CtrlBase.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief  ��������� 
 *   
 *   @author shijianfengyf2
 *   @modify shijianfengyf2
 *   @date   2018/08/21
 *   
 *   @note:
 */

#ifndef _EBASE_EXPORTCLASS_CTRLBASE_H_
#define _EBASE_EXPORTCLASS_CTRLBASE_H_

#include "DevComPublicDef.h"

namespace DevEBase
{
#define MAX_SESSION_MGR_NUM  32

    //ǰ������
    class CCtrlBasePrivate;

    /**   @class CCtrlBase
    *    @brief ȫ�ֿ��ƻ��ࡣ��������඼�ǵ�һʵ��
    */
    class NET_COM_CLASS CCtrlBase
    {
    public:
        CCtrlBase();
        virtual ~CCtrlBase();

        HPR_BOOL Init();                                //���������ܣ���ʼ�������Դ
        HPR_BOOL Fini();                                //���������ܣ�����ʼ�������Դ

        HPR_BOOL CheckInit();                           //�����Դ: �ɹ�ʱ��ʹ�ü�����+1

    protected:
        virtual HPR_BOOL InitAllResource() = 0;         //��ʼ��������Ҫ��Դ
        virtual HPR_VOID CleanupAllResource() = 0;      //�����������Դ
        virtual HPR_BOOL CheckConstructResource() const;//��鹹�캯������Ҫ��̬��������Դ�Ƿ񴴽��ɹ���

        HPR_BOOL Lock();
        HPR_BOOL UnLock();

        CCtrlBasePrivate* m_pPrivate;
    };
}

#endif //_EBASE_EXPORTCLASS_CTRLBASE_H_

