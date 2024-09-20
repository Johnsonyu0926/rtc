/*******************************************************************************************************************************
* 
* ��Ȩ��Ϣ����Ȩ���� (c) 2010, ���ݺ�������������޹�˾, ��������Ȩ��
* 
* �ļ����ƣ�audio_codec_common.h
* ժ    Ҫ������������Ƶ����빲�ýṹ�弰�궨�������ļ�

* ��ǰ�汾��0.9
* ��    �ߣ�������
* ��    �ڣ�2011��9��25��
* ��    ע��
*******************************************************************************************************************************/

#ifndef _AUDIO_CODEC_COMMON_H_
#define _AUDIO_CODEC_COMMON_H_

#ifdef _cplusplus
extern "C"{
#endif

#include "datatypedef.h"
#include "HikCrypt/mem_tab.h"

#define			HIK_AUDIOCODEC_LIB_S_OK                        1              /* �ɹ�		               */
#define			HIK_AUDIOCODEC_LIB_S_FAIL                      0              /* ʧ��		               */

#define			HIK_AUDIOCODEC_LIB_E_PARAM_NULL                0x80000000     /* ����ָ��Ϊ��              */
#define			HIK_AUDIOCODEC_LIB_E_HANDLE_NULL			   0x80000001     /* ����handleΪ��            */
#define			HIK_AUDIOCODEC_LIB_E_MEMORY_NULL    		   0x80000002     /* �ڴ�Ϊ��                  */
#define         HIK_AUDIOCODEC_LIB_E_CHANNEL_ERR               0x80000003     /* ��������                  */
#define			HIK_AUDIOCODEC_LIB_E_SAMPLERATE_ERR			   0x80000004     /* �����ʴ���                */
#define         HIK_AUDIOCODEC_LIB_E_MAXBITS_ERR			   0x80000005     /* ������������            */
#define         HIK_AUDIOCODEC_LIB_E_BITSCTRL_ERR			   0x80000006     /* ���ʿ��Ƽ������          */
#define         HIK_AUDIOCODEC_LIB_E_BITRATE_ERR               0x80000007     /* ���ʴ���                  */
#define         HIK_AUDIOCODEC_LIB_E_INPUT_SIZE_ERR            0x80000008     /* �������ݴ�С����          */
#define         HIK_AUDIOCODEC_LIB_E_MEMTAB_SIZE_ERR           0x80000009     /* �ڴ���С����            */
#define         HIK_AUDIOCODEC_LIB_E_BUF_TOO_SMALL             0x8000000a     /* ����̫С                  */

#define         AUDIO_CODEC_BUF_SIZE                           8192           /* ������������С          */
#define         AUDIO_DEC_DATA_SIZE                            2048           /* �������������Ҫ���ݴ�С  */

/* ���ʿ��Ƽ��� */
typedef enum _BITCTRLLEVEL_
{
    LEVEL1  = 1,
    LEVEL2  = 2,
    LEVEL3  = 3
}BITCTRLLEVEL;

/* ����ģʽ */
typedef enum _ENC_MODE_
{ 
    AMR_MR475 = 0,		/* 4.75 kb/s */ 
    AMR_MR515,          /* 5.15 kb/s */  
    AMR_MR59,			/* 5.90 kb/s */
    AMR_MR67,			/* 6.70 kb/s */
    AMR_MR74,			/* 7.40 kb/s */
    AMR_MR795,			/* 7.95 kb/s */
    AMR_MR102,			/* 10.2 kb/s */
    AMR_MR122,          /* 12.2 kb/s */   

    AMR_MRDTX,			/* ����֡    */
    AMR_N_MODES

}AUDIO_ENC_MODE;

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
    typedef S32 HRESULT;
#endif 

/*******************************************************************************************************************************
*����ṹ��
*******************************************************************************************************************************/

typedef struct _AUDIOENCInfo                     /* ��Ϣ                                                    */
{    
    U32            in_frame_size;                /* ����һ֡���ݴ�С(BYTES)����GetInfoParam��������         */    
    S32            reserved[16];                 /* ����                                                    */
} AUDIOENC_INFO;

typedef struct _AUDIOENC_PARAM_
{
    U32            sample_rate;                  /* ������-I                                                */
    U32            num_channels;                 /* ������-I                                                */    
    U32            bitrate;                      /* ����  -I                                                */
    
    U32            vad_dtx_enable;               /* 0��ʾ�ر�,1��ʾ����, G7231, G729ab, AMR����ʱ����       */ 
    BITCTRLLEVEL   bit_ctrl_level;               /* ���ʿ��Ƽ��𣬼���Խ�ͣ����ʿ���Խ������AAC����ʱ����   */    
    S32            reserved[16];                 /* ����                                                    */
}AUDIOENC_PARAM;

typedef struct _AUDIOENC_PROCESS_PARAM_
{
    U08            *in_buf;                      /* ����buf	                                                */
    U08            *out_buf;                     /* ���buf                                                 */
    U32            out_frame_size;               /* ����һ֡���BYTE��                                      */

    S32			   g726enc_reset;                /* ���ÿ���                                                */
    S32            g711_type;                    /* g711��������,0 - U law, 1- A law                        */
    AUDIO_ENC_MODE enc_mode;                     /* ��Ƶ����ģʽ��AMR��������                               */
    S32            reserved[16];                 /* ����                                                    */
}AUDIOENC_PROCESS_PARAM;

/*******************************************************************************************************************************
*����ṹ��
*******************************************************************************************************************************/

typedef struct _AUDIODECInfo                     /* ��Ϣ                                                    */
{
    S32            nchans;					     /* ������                                                  */
    S32            sample_rate;                  /* ������                                                  */
    S32            aacdec_profile;               /* �����õĿ��                                            */
    S32            reserved[16];                 /* ����                                                    */
} AUDIODEC_INFO;

typedef struct _AUDIODEC_PARAM
{
    S32            gdec_bitrate;                 /* Gϵ�н�������������                                     */    
    S32            reserved[16];                 /* ����                                                    */
}AUDIODEC_PARAM;

typedef struct _AUDIODEC_PROCESS_PARAM
{
    U08            *in_buf;                      /* ��������buf                                             */   
    U08			   *out_buf;                     /* �������buf                                             */
    U32            in_data_size;                 /* ����in_buf������byte��                                  */ 
    U32            proc_data_size;               /* �������⴦��in_buf�����ݴ�Сbytes                     */
    U32            out_frame_size;               /* ����һ֡������BYTE��                                    */
    AUDIODEC_INFO  dec_info;                     /* ���������Ϣ                                            */
    
    S32			   g726dec_reset;                /* ���ÿ���                                                */ 
    S32            g711_type;                    /* g711��������,0 - U law, 1- A law                        */
    S32            reserved[16];                 /* ����                                                    */
}AUDIODEC_PROCESS_PARAM;




#ifdef _cplusplus
}
#endif


#endif

