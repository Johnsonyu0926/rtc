/**  @file   Singleton.h
 *   @note   HangZhou Hikvision System Technology Co., Ltd. All Right Reserved. 
 *   @brief  ����ģ�壬ȫ�������
 *   
 *   @author shijianfengyf2
 *   @modify shijianfengyf2
 *   @date   2018/08/09
 *   
 *   @note:
 */

#include "HPR/HPR_Config.h"
#include "HPR/HPR_Types.h"

namespace DevComUtils
{
    template <typename T>
    class CSingleton
    {
    public:
        static T* GetInstance();
        virtual ~CSingleton();
    protected:
        CSingleton(){}; //��ֹ���˽��й��캯��
    };

    template <typename T>
    T* CSingleton<T>::GetInstance()
    {
        static T instance;  //���ﲻ�����̰߳�ȫ���⣬������
                            //��Ϊ��EHome������������ȫ�ֵ�globalctrl��
                            //���������init��ʱ��ͻ���ã���ʱһ����ֻ��һ���߳�
        return &instance;
    }

}