/**
 * \file ez_model.h
 * \author shenhongyin
 * \brief 
 * \version v3.0
 * \date 2020-11-24
 * 
 * \copyright ezviz Copyright (c) 2020
 * 
 */

#ifndef EZ_MODEL_H_
#define EZ_MODEL_H_

#include "ezDevSDK_domain_def.h"
#include "ez_model_def.h"


/**
 * @addtogroup  SDK
 * SDK v3 通道协议封装
 *  
 */

#ifdef __cplusplus
extern "C"
{
#endif



/** 
 *  \brief	向model模块注册领域,用于das消息的路由
 *  \method		ez_model_domain_reg
 *  \param[out] 
 *  \return  当前封装版本号，非空
 */
GLOBAL_API int ez_model_domain_reg(const ez_domain_reg* domain_reg);

/** 
 *  \brief	   领域反注册
 *  \method	   ez_model_domain_dereg
 *  \param[in] domain ,注册的domian标识
 *  \return  当前封装版本号，非空
 */
GLOBAL_API int ez_model_domain_dereg(const char* domain, const char* identifier);

/** 
 *  \brief		设备回复das下发的请求
 *  \method		ez_model_reply_to_das
 *  \param[in]  basic_info 通用消息参数
 *  \param[in]  msg 用户定义响应消息协议内容, json类型
 *  \param[in]  status 消息处理结果
 *  \param[in]  msg_attr 发送消息属性
 *  \return  0成功 非0 失败
 */
GLOBAL_API int ez_model_reply_to_das(ez_basic_info* basic_info, ez_model_msg* msg, ez_err_info* status, ez_msg_attr* msg_attr);

/** 
 *  \brief	发送消息接口,可以通过该接口实现事件/属性的上报/操作查询等
 *  \method		ez_model_send_msg
 *  \param[in]  basic_info 通用消息参数
 *  \param[in]  msg 用户定义协议内容, json类型
 *  \param[in]  msg_attr     发送消息属性
 *  \return  0成功 非0 失败
 */
GLOBAL_API int ez_model_send_msg(ez_basic_info* basic_info, ez_model_msg* msg, ez_msg_attr* msg_attr);

/** 
 *  \brief	发送消息给das,
 *  \method		ez_model_send_to_platform
 *  \param[in]  basic_info 通用消息参数
 *  \param[in]  msg 具体协议内容,必须是可解析为json的字符串
 *  \param[in]  msg_len 消息长度
 *  \param[in]  msg_response 请求或者响应消息标识 请求消息填 0  响应消息填 1
 *  \param[in]  msg_attr     发送消息属性
 *  \return  0成功 非0 失败
 */
GLOBAL_API int ez_model_send_to_platform(ez_basic_info* basic_info, const char* msg, unsigned int msg_len, int msg_response, ez_msg_attr* msg_attr);
/** 
 *  \brief	获取当前封装版本号
 *  \method		ez_model_get_current_version
 *  \param[out] 
 *  \return  当前封装版本号,未初始化时返回NULL
 */
GLOBAL_API const char* ez_model_get_current_version();

/** 
 *  \brief	设置默认回调函数,用于未注册的领域消息的接收
 *  \method		ez_model_set_default_call_back
 *  \param[in]  ez_data_router消息回调
 *  \return  0成功 非0 失败
 */
GLOBAL_API int ez_model_reg_default_cb(ez_model_default_cb* ez_data_router);


/** 
 *  \brief	    清除默认回调信息及模块反初始化
 *  \method		ez_model_dereg_default_cb
 *  \param[in]  ez_data_router
 *  \return  0成功 
 */
GLOBAL_API int ez_model_dereg_default_cb(ez_model_default_cb* ez_data_router);



#ifdef __cplusplus
}
#endif

#endif //