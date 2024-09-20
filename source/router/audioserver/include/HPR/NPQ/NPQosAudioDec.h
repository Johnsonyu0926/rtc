/**	@NPQosAudioDec.h
*	@note HangZhou Hikvision Technology Co., Ltd. All Right Reserved.
*	@brief NPQ��ӿڶ���
*   @apa_common.h��datatypedef.h��mem_tab.h�Ķ������о�Ժ��Ƶ�����Ķ��屣��һ��
*   @��Ƶ��غ����ӿڵ����߼����о�Ժ��Ƶ�����ı���һ�£�Ψһ��ͬ���ǣ�������һ����Դ�ͷŽӿ�
*   @��Ƶ��غ����ӿڷ���ֵ�������о�Ժ��Ƶ�����ı���һ��
*
*	@author		huangfanfu
*	@date		2019/03/07
*
*	@note
*
*	@warning 
*/
#ifndef _NPQOSAUDIODEC_H_
#define _NPQOSAUDIODEC_H_

#if defined(WIN32)
#if defined(NPQOS_EXPORTS)
#define NPQ_API extern "C" __declspec(dllexport)
#else
#define NPQ_API extern "C" __declspec(dllimport)
#endif
#else

#ifndef __stdcall
#define __stdcall
#endif

#ifndef NPQ_API
#define NPQ_API extern "C"
#endif

#endif

#include "apa_common.h"
#include "datatypedef.h"
#include "HikCrypt/mem_tab.h"
#include "audio_codec_common.h"

/**	@enum	 NPQ_AUDIO_ENCODE_TYPE 
 *	@brief   ��Ƶ��������
 *	@note	 
 */
enum NPQ_AUDIO_ENCODE_TYPE
{
	NPQ_I_AUDIO_G711A,
	NPQ_I_AUDIO_G711U,
	NPQ_I_AUDIO_G7221,              
	NPQ_I_AUDIO_G726,				
	NPQ_I_AUDIO_AAC,
    NPQ_I_AUDIO_AAC_LC,                 //�ݲ�֧�ָ�����
    NPQ_I_AUDIO_AAC_LD,
	NPQ_I_AUDIO_MPA,
	NPQ_I_AUDIO_OPUS,
	NPQ_I_AUDIO_PCM,
    NPQ_I_AUDIO_G7221C,                 //�ݲ�֧�ָ�����
    NPQ_I_AUDIO_MP3,                    //�ݲ�֧�ָ�����
    NPQ_I_AUDIO_G728,                   //�ݲ�֧�ָ�����
    NPQ_I_AUDIO_G729,                   //�ݲ�֧�ָ�����
	NPQ_I_AUDIO_UNKNOW = 0xff,
};

/**	@fn NPQAudioDec_GetMemSize
*	@brief  ��ȡ��Ƶ���������ڴ��С
*	@param  NPQ_AUDIO_ENCODE_TYPE audio_type  ��Ƶ�����ʽ
*   @param  AUDIODEC_PARAM *param             �����ṹָ��
*   @param  MEM_TAB *mem_tab                  �ڴ������
*	@param  void *pusr                        �û�ָ��
*	@return ����״̬��
*/
typedef HRESULT(__stdcall* NPQAudioDec_GetMemSize)(NPQ_AUDIO_ENCODE_TYPE audio_type, AUDIODEC_PARAM *param, MEM_TAB *mem_tab, void *pusr);

/**	@fn NPQAudioDec_Create
*	@brief  ������Ƶ����ģ��
*	@param  NPQ_AUDIO_ENCODE_TYPE audio_type  ��Ƶ�����ʽ
*   @param  AUDIODEC_PARAM *param             �����ṹָ��
*   @param  MEM_TAB *mem_tab                  �ڴ������
*   @param  void **handle                     ������
*	@param  void *pusr                        �û�ָ��
*	@return ����״̬��
*/
typedef HRESULT(__stdcall* NPQAudioDec_Create)(NPQ_AUDIO_ENCODE_TYPE audio_type, AUDIODEC_PARAM *param, MEM_TAB *mem_tab, void **handle, void *pusr);

/**	@fn NPQAudioDec_Decode
*	@brief  ��Ƶ����
*   @param  void *handle                       ������
*	@param  NPQ_AUDIO_ENCODE_TYPE audio_type   ��Ƶ�����ʽ
*   @param  AUDIODEC_PROCESS_PARAM *proc_param �������
*	@param  void *pusr                         �û�ָ��
*	@return ����״̬��
*/
typedef HRESULT(__stdcall* NPQAudioDec_Decode)(void *handle, NPQ_AUDIO_ENCODE_TYPE audio_type, AUDIODEC_PROCESS_PARAM *proc_param, void *pusr);

/**	@fn NPQAudioDec_Release
*	@brief  �ͷ���Ƶ����ģ����Դ
*   @param  void *handle                       ������
*	@param  NPQ_AUDIO_ENCODE_TYPE audio_type   ��Ƶ�����ʽ
*	@param  void *pusr                         �û�ָ��
*	@return ����״̬��
*/
typedef HRESULT(__stdcall* NPQAudioDec_Release)(void *handle, NPQ_AUDIO_ENCODE_TYPE audio_type, void *pusr);


/**	@enum	 NPQ_AUDIO_DECODE_FUN 
 *	@brief   ��Ƶ������غ���ָ��
 *	@note	 
 */
struct NPQ_AUDIO_DECODE_FUN
{
	NPQAudioDec_GetMemSize        pAudioDecGetMemSize;      //��ȡ��Ƶ���������ڴ��С����ָ��
	NPQAudioDec_Create            pAudioDecCreate;          //������Ƶ����ģ�麯��ָ��
	NPQAudioDec_Decode            pAudioDecDecode;          //��Ƶ���뺯��ָ��
	NPQAudioDec_Release           pAudioDecRelease;         //�ͷ���Ƶ����ģ����Դ����ָ��
	void*                         pAudioDecUsr;             //��Ƶ�����û�ָ��
	char                          res[128];                 //�����ֶ�
};

#endif//_NPQOSAUDIODEC_H_