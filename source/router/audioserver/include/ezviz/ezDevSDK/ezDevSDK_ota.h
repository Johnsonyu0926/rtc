/**\filename  ezDevSDK_ota.h 
*  \copyright HangZhou Hikvision System Technology Co.,Ltd. All Right Reserved.
*  \brief     ota�������ӿ�ʵ��
*  \author    shenhongyin
*  \date      2020/06/02
*/

#ifndef H_EZDEVSDK_OTA_H_
#define H_EZDEVSDK_OTA_H_

#include "ezDevSDK_domain_def.h"
#include "ezDevSDK_ota_def.h"

/**
 * \addtogroup ota_Module �豸����ģ��
 * \{
 */

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief ota�����ʼ���ӿ�
     * 
     * @param pmodules ����ģ�����Ϣ
     * @param pehandler  ��������֪ͨ�ص�
     * @return  ezDevSDK_ota_code_e
     */
    GLOBAL_API ezDevSDK_ota_code_e ezDevSDK_ota_init(ezDevSDK_ota_init_info *ota_init_info);

    /**
     * @brief ��ѯ��������Ϣ�ӿ�,��ѯ��ʱʱ��10s
     * 
     * @param pinfos ����ģ����Ϣ
     * @return  ezDevSDK_ota_code_e
     */
    GLOBAL_API ezDevSDK_ota_code_e ezDevSDK_ota_query(const ezDevSDK_ota_query_infos_t *pinfos);

    /**
     * @brief ���������ϱ��ӿ�
     * 
     * @param state 
     * @param progress 
     * @param code 
     * @return ezDevSDK_ota_code_e
     */
    GLOBAL_API ezDevSDK_ota_code_e ezDevSDK_ota_report(ezDevSDK_ota_state_e state, int progress, ezDevSDK_ota_report_err_e code);

    /**
     * @brief ���������ؽӿ�,�첽�ӿ�
     * 
     * @param ezDevSDK_ota_download_info_t ,������������Ĳ����ṹ��
     * @param download_cb    ���ذ��ص�
     * @return  �������-1,  ��ʾʧ��
     */
GLOBAL_API int ezDevSDK_ota_file_download(ezDevSDK_ota_download_info_t* download_info, ezDevSDK_ota_download_cb download_cb);

    /**
     * @brief ota����ʼ���ӿ�
     * 
     * @return ezDevSDK_ota_code_e 
     */
    GLOBAL_API ezDevSDK_ota_code_e ezDevSDK_ota_fini();

#ifdef __cplusplus
}
#endif

/*! \} */

#endif // H_EZDEVSDK_OTA_H_