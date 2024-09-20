/**
 * \file ezDevSDK_ota_def.h
 * \author 
 * \brief 
 * \version 0.1
 * \date 2020-05-19
 * 
 * \copyright Copyright (c) 2019
 * 
 */

#ifndef _ezDevSDK_ota_DEF_H_
#define _ezDevSDK_ota_DEF_H_

#include "ezDevSDK_error.h"


typedef enum
{
    ota_down_no_err,     ///< no error
    ota_down_md5_err,    ///< md5 not match, data = NULL
    ota_down_failed,     ///< interface error
} ota_download_error_e;

/**
 * @brief ���ػص��ӿ�,cdoe 
 * 
 */

//���ص����ط�0ʱ�������˳���������,
typedef int (*ezDevSDK_ota_download_cb)(char* data, int data_len, ota_download_error_e error, int progress);


typedef enum
{
    ota_event_start,        ///< �����豸��������Ϣ��: \c ezDevSDK_ota_modules_t
    ota_evnet_upgrade_info, ///< �豸��������Ϣ����Ϣ��: \c ezDevSDK_ota_upgrade_info_t
} ezDevSDK_ota_event_e;

/**
 * \brief   �豸�Ļص��������壬�������ջ��������������Ϣ����Ϣ��ѯ
 * \warning ����������
 * \note    recv_msg ��������ƽ̨�·�����Ϣ���μ�
 */
typedef struct 
{
	int (*ota_event_handler)(ezDevSDK_ota_event_e event, void *data);     ///<ota�¼�֪ͨ�ӿ�
} ezDevSDK_ota_callback;


typedef struct
{
    int index;          ///< ģ��������ģ�����豸�ڲ��ı��;����豸��Ҫ�������豸�������ϱ�����������������Ĭ��0
    char identify[256]; ///< ģ��Ψһ��־��ͬ�豸�ͺţ�
    char fw_ver[64];    ///< ��ǰ�̼��汾��
} ezDevSDK_ota_module_info_t;

typedef struct
{
    int num;                                  ///< ����ģ�����������֧��16��
    ezDevSDK_ota_module_info_t *pmodule_info; ///< ����ģ����Ϣ�б�
} ezDevSDK_ota_modules_t;

/**
* \brief	������������ĳ�ʼ������
*/
typedef struct 
{
    ezDevSDK_ota_callback  cb;									///< �ص�����
    ezDevSDK_ota_modules_t modules;                             ///< �豸ģ����Ϣ
} ezDevSDK_ota_init_info;

typedef struct
{
    char identify[256]; ///< ģ��Ψһ��־��ͬ�豸�ͺţ�
    char fw_ver[64];    ///< ��ǰ�̼��汾��
    int  ota_type;       ///< �������ͣ�0֧������������1֧�ֲ������
} ezDevSDK_ota_query_info_t;

typedef struct
{
    int num;                                ///< ��ѯ��������ģ�����������֧��16��
    ezDevSDK_ota_query_info_t *pquery_info; ///< ����ģ����Ϣ�б�
} ezDevSDK_ota_query_infos_t;


/**
 * @brief ��ѯ������������
 * 
 */
typedef enum
{
    ezDevSDK_ota_code_query_succ = 0,                ///< û�д���
    ezDevSDK_ota_code_query_last_ver = 0xD1000060,  ///< �Ѿ������°汾������Ҫ����
    ezDevSDK_ota_code_query_reject = 0xD1000061,    ///< ��������ܾ���������
    ezDevSDK_ota_code_query_exception = 0xD1000062, ///< ���������ڲ��쳣
} ezDevSDK_ota_code_query_e;

/**
* \brief   ����ļ�����Ϣ
*/
typedef struct
{
    char http_url[270];   ///< ������ȫ·��http��
    char https_url[270];  ///< ������ȫ·��https��
    char fw_ver_src[64];  ///< ��ְ���Ӧ��ԭ�������汾�ţ�ֻ������汾�Ĺ̼�����ͨ����ְ�������fw_ver�汾�Ĺ̼�
    char degist[33];      ///< ��������ժҪֵ,����'\0'
    int size;             ///< �������С����λByte
} ezDevSDK_ota_file_diff_t;

/**
* \brief   �����ļ�����Ϣ
*/
typedef struct
{
    char identify[256];               ///< ģ��Ψһ��־��ͬ�豸�ͺţ�
    char http_url[270];               ///< ������ȫ·��http��
    char https_url[270];              ///< ������ȫ·��https��
    char fw_ver[64];                  ///< �������汾��
    char degist[33];                  ///< ��������ժҪֵ,����'\0'
    char dsc[256];                    ///< ����������Ϣ
    int size;                         ///< �������С����λByte
    int diff_num;                     ///< ��ְ�������ͬһ�ͺ�һ����෵�����飨ͳһ�ͺŵĲ�ͬ�汾ͬʱ��ѯ���������п��ܷ��ض����ְ��������
    ezDevSDK_ota_file_diff_t *pdiffs; ///< �������ð汾�Ĳ�ְ�
} ezDevSDK_ota_file_info_t;

/**
 * \brief   �豸��������Ϣ
 */
typedef struct
{
    ezDevSDK_ota_code_query_e code;       ///< ��ѯ������
    int retry_max;                        ///< ����������Դ���
    int report_interval;                  ///< �ϱ�������С���
    int file_num;                         ///< ��������Ϣ�����С
    ezDevSDK_ota_file_info_t *pota_files; ///< ������Ϣ����
} ezDevSDK_ota_upgrade_info_t;

/**
 * @brief өʯSDK OTA����Ľӿڴ����룬��SDK���ظ�������
 * @note ���ô����룬��ο�ezDevSDK_error.h
 */
typedef enum
{
    ezDevSDK_ota_code_succ = 0X00000000,                                                   ///< �ɹ�
    ezDevSDK_ota_code_fail = 0XD1000000 + EZDEVSDK_ERROR_FAIL,                             ///< ͨ�ô�����
    ezDevSDK_ota_code_not_inited = 0XD1000000 + EZDEVSDK_ERROR_NOT_INITED,                 ///< ģ��δ��ʼ��
    ezDevSDK_ota_code_invalid_param = 0XD1000000 + EZDEVSDK_ERROR_INVALID_PARAM,           ///< �Ƿ�����
    ezDevSDK_ota_code_not_enough_memory = 0XD1000000 + EZDEVSDK_ERROR_NOT_ENOUGH_MEMERY,   ///< �ڴ治��
    ezDevSDK_ota_code_init_fail = 0XD1000000 + EZDEVSDK_ERROR_INIT_FAIL,                   ///< �����ʼ��ʧ��
    ezDevSDK_ota_code_thread_create_fial = 0XD1000000 + EZDEVSDK_ERROR_THREAD_CREATE_FAIL, ///< �̴߳���ʧ��
    ezDevSDK_ota_code_already_inited = 0XD1000000 + EZDEVSDK_ERROR_ALREADY_INITED,         ///< �����ѳ�ʼ��
    ezDevSDK_ota_code_json_err= 0XD1000000 + EZDEVSDK_ERROR_JSON_ERROR,                    ///< JSON err
    ezDevSDK_ota_code_msg_send_err= 0XD1000000 + EZDEVSDK_ERROR_MSG_SEND_ERROR,                ///< ��Ϣ���ͳ���

    ezDevSDK_ota_code_device_upgrading = 0XD1000040, ///< ����������
    ezDevSDK_ota_code_device_on_busy = 0XD1000041, ///< �豸æ���ܾ�����
} ezDevSDK_ota_code_e;

/**
 * @brief �����ϱ�������
 * 
 */
typedef enum
{
    ota_report_no_err = 0,                    ///< û�д���
    ota_report_query_timeout = 0xD1000020, ///< ��ѯ��������ʱ
    ota_report_query_err = 0xD1000021,     ///< ��ѯ����������\����ܾ���������
    ota_report_size_mismatch = 0xD1000022, ///< �ļ���С�Ͳ�ѯ����Ϣ��ƥ��
    ota_report_size_range = 0xD1000023,    ///< �ļ���С����������С
    ota_report_connect = 0xD1000024,       ///< ��������ʧ�ܻ��޷���������������
    ota_report_download = 0xD1000025,      ///< ���س������粻�ȶ������س�ʱ������������Դ�����
    ota_report_digest = 0xD1000026,        ///< ժҪֵ��ƥ��
    ota_report_verify = 0xD1000027,        ///< ��֤�̼�ǩ��ʧ�ܣ�RSA\ECC��ǩ��
    ota_report_damaged = 0xD1000028,       ///< �������𻵣��ڲ���ʽ���ԣ�
    ota_report_memory = 0xD1000029,        ///< �ڴ治��
    ota_report_burn = 0xD100002a,          ///< ��¼�̼�����
    ota_report_genneral = 0xD100002b,      ///< δ֪����
    ota_report_cancel = 0xD100002c,        ///< �û�����ֹͣ/���ع��̱�ȡ��/��װ���̵���
    ota_report_recovery = 0xD100002d,      ///< ����ʧ�ܣ�ͨ������ϵͳ����Сϵͳ�ָ�
} ezDevSDK_ota_report_err_e;


/**
 * @brief ��������״̬�仯���豸ֻ����ota_state_upgradeable��ota_state_succ��ota_state_fail����״̬��,
 *        �ƶ˲����ж��豸�Ƿ��������
 */
typedef enum
{
    ota_state_upgradeable = 0,        ///< ������״̬�����������������״̬��
    ota_state_starting = 1,           ///< ��ʼ����
    ota_state_downloading = 2,        ///< ��������
    ota_state_download_completed = 3, ///< �������
    ota_state_burning = 4,            ///< ������¼
    ota_state_burning_completed = 5,  ///< ��¼���
    ota_state_rebooting = 6,          ///< ��������
    ota_state_succ = 7,               ///< �����ɹ�
    ota_state_fail = 8,               ///< ����ʧ��
} ezDevSDK_ota_state_e;

typedef enum
{
    ota_progress_min = 0,

    ota_progress_max = 100
} ezDevSDK_ota_progress_e;


//���صķ�ʽ,Ŀǰ��֧��http��ʽ
typedef enum
{
    ota_http = 0,
    ota_https,
} ezDevSDK_ota_http_type;

/**
 * \brief   ������������Ϣ
 */
typedef struct
{
    char url[270];                         ///< ��������url��Ϣ http://��ͷ
    char check_sum[33];                    ///< ��������md5 ֵ(����'\0')
    int http_type;                         ///< ����֧�ֵ�http����,Ŀǰ��֧��http��ʽ����
    int total_size;                        ///< ���������ܴ�С
    int recv_buf_size;                     ///< ���ջص����ݵĴ�С
    int timeout_s;                         ///< ��ʱʱ��
} ezDevSDK_ota_download_info_t;



#endif //_ezDevSDK_ota_DEF_H_