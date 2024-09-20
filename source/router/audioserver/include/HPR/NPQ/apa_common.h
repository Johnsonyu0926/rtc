/***********************************************************************************************************************
* 
* ��Ȩ��Ϣ����Ȩ����(c) 2017-2020, ���ݺ��������о�Ժ, ��������Ȩ��
*
* �ļ����ƣ�apa_common.h
* �ļ���ʶ��_HIK_APA_COMMON_H_
* ժ    Ҫ�����������о�Ժ��Ƶ�����������ͷ�ļ�

* ��ǰ�汾��0.9.0
* ��    �ߣ�������
* ��    �ڣ�2017��03��21��
* ��    ע���ƶ���Ƶ�����������ͷ�ļ�            
***********************************************************************************************************************/
#ifndef _HIK_APA_COMMON_H_
#define _HIK_APA_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
typedef unsigned int HRESULT;
#endif /* _HRESULT_DEFINED */

/***********************************************************************************************************************
* ������
***********************************************************************************************************************/
#define HIK_APA_LIB_S_OK                     1           // �ɹ�	  
#define HIK_APA_LIB_S_FAIL                   0           // ʧ��
#define HIK_APA_LIB_E_MEM_OUT                0x81F00001  // �ڴ治��
#define HIK_APA_LIB_E_PTR_NULL	             0x81F00002  // ����ָ��Ϊ��  
#define HIK_APA_LIB_KEY_PARAM_ERR            0x81F00003  // �߼��������ô���
#define HIK_APA_LIB_PARAM_VAL_ERR            0x81F00004  // ��������ֵ����
#define HIK_APA_LIB_E_BITS_PER_SAMP_ERR      0x81F00005  // ÿ��������bit��������
#define HIK_APA_LIB_E_CHANNEL_ERR            0x81F00006  // ����������
#define	HIK_APA_LIB_E_SAMPLERATE_ERR         0x81F00007  // �����ʴ���
#define HIK_APA_LIB_E_INPUT_SIZE_ERR         0x81F00008  // �������ݴ�С����
#define HIK_APA_LIB_E_MEMTAB_SIZE_ERR        0x81F00009  // �ڴ���С����
#define HIK_APA_LIB_E_AUDIO_UNSUPPORT        0x81F0000a  // ��Ƶ������Ϣ����
#define HIK_APA_LIB_E_ERRCODE_UNSUPPORT      0x81F0000b  // ��Ƶ�����벻֧��
#define HIK_APA_LIB_E_UNKNOW                 0x81FFFFFF  // δ֪����

/***********************************************************************************************************************
* �ڴ������APA_MEM_TAB�ṹ�嶨��
***********************************************************************************************************************/
#define APA_ENUM_END          0x0FFFFF                   // ����ö�ٽ���ֵ�����ڶ���
#define APA_MAX_PARAM_NUM     50                         // ���ؼ���������
#define APA_MAX_CHN_N         64                         // �����Ƶͨ����

/*�ڴ��������*/
typedef enum _APA_MEM_ALIGNMENT_
{
    APA_MEM_ALIGN_4BYTE    = 4,
    APA_MEM_ALIGN_8BYTE    = 8,
    APA_MEM_ALIGN_16BYTE   = 16,
    APA_MEM_ALIGN_32BYTE   = 32,
    APA_MEM_ALIGN_64BYTE   = 64,
    APA_MEM_ALIGN_128BYTE  = 128,
    APA_MEM_ALIGN_256BYTE  = 256,
    APA_MEM_ALIGN_END      = APA_ENUM_END
}APA_MEM_ALIGNMENT;

/* �ڴ����� */
typedef enum _APA_MEM_ATTRS_
{
    APA_MEM_SCRATCH,                    // �ɸ����ڴ棬���ڶ�·�л�ʱ����������
    APA_MEM_PERSIST,                    // ���ɸ����ڴ�
    APA_MEM_ATTRS_END = APA_ENUM_END
}APA_MEM_ATTRS;

typedef enum _APA_MEM_PLAT_
{
	APA_MEM_PLAT_CPU,                   // CPU�ڴ� 
	APA_MEM_PLAT_GPU,                   // GPU�ڴ�
	APA_MEM_PLAT_END = APA_ENUM_END
}APA_MEM_PLAT;

/* �ڴ����ռ� */
typedef enum _APA_MEM_SPACE_ 
{
    APA_MEM_EXTERNAL_PROG,              // �ⲿ����洢��           
    APA_MEM_INTERNAL_PROG,              // �ڲ�����洢��         
    APA_MEM_EXTERNAL_TILERED_DATA,      // �ⲿTilered���ݴ洢��  
    APA_MEM_EXTERNAL_CACHED_DATA,       // �ⲿ��Cache�洢��      
    APA_MEM_EXTERNAL_UNCACHED_DATA,     // �ⲿ����Cache�洢��    
    APA_MEM_INTERNAL_DATA,              // �ڲ��洢��
    APA_MEM_EXTERNAL_TILERED8 ,         // �ⲿTilered���ݴ洢��8bit��Netra/Centaurus���� 
    APA_MEM_EXTERNAL_TILERED16,         // �ⲿTilered���ݴ洢��16bit��Netra/Centaurus����
    APA_MEM_EXTERNAL_TILERED32 ,        // �ⲿTilered���ݴ洢��32bit��Netra/Centaurus����
    APA_MEM_EXTERNAL_TILEREDPAGE,       // �ⲿTilered���ݴ洢��page��ʽ��Netra/Centaurus����
    APA_MEM_EXTERNAL_END = APA_ENUM_END
}APA_MEM_SPACE;


typedef struct _APA_MEM_TAB_
{
	unsigned int        size;           // ��BYTEΪ��λ���ڴ��С
	APA_MEM_ALIGNMENT   alignment;      // �ڴ��������, ����Ϊ128
	APA_MEM_SPACE       space;          // �ڴ����ռ� 
	APA_MEM_ATTRS       attrs;          // �ڴ����� 
	void                *base;          // ��������ڴ�ָ�� 
	APA_MEM_PLAT        plat;           // ƽ̨
} APA_MEM_TAB;

/***********************************************************************************************************************
*������Ƶ֡�ṹ��
***********************************************************************************************************************/

//��Ƶ֡ͷ��Ϣ
typedef struct _APA_AUDIO_INFO_
{    
    unsigned int   channel_num;         // ������
    unsigned int   sample_rate;         // ������
    unsigned int   bits_per_sample;     // ÿ���������bit������˾���е���Ƶ���ݶ���16bit
    unsigned int   data_len;            // ÿͨ�����ݲ�����������ͨ����ÿ��ͨ�����ݳ��ȱ���һ��
    int            reserved[4];         // �����ֽ�    
}APA_AUDIO_INFO;

/***********************************************************************************************************************
*������Ϣ�и߼����������Ϣ�ṹ�嶨��
***********************************************************************************************************************/

//�㷨��������������ö��
typedef enum _APA_SET_CFG_TYPE_
{
	APA_SET_CFG_SINGLE_PARAM      = 0x0001,         // ��������
	APA_SET_CFG_PARAM_LIST        = 0x0002,         // ������
	APA_SET_CFG_DEFAULT_PARAM     = 0x0003,         // Ĭ�ϲ���
	APA_SET_CFG_RESTART_LIB       = 0x0004,         // �����㷨��	
    APA_SET_CFG_END               = APA_ENUM_END
}APA_SET_CFG_TYPE;

//���ò�������
typedef enum _APA_GET_CFG_TYPE_
{
	APA_GET_CFG_SINGLE_PARAM      = 0x0001,         // ��������
	APA_GET_CFG_PARAM_LIST        = 0x0002,         // ������
    APA_GET_CFG_DEFAULT_PARAM     = 0x0003,         // Ĭ�ϲ���
	APA_GET_CFG_VERSION           = 0x0004,         // �汾��Ϣ
    APA_GET_CFG_END               = APA_ENUM_END
}APA_GET_CFG_TYPE;


// �㷨������ṹ��
typedef struct _APA_KEY_PARAM_
{
    int  index;
    int  value; 
}APA_KEY_PARAM;

// ��������
typedef struct _APA_KEY_PARAM_LIST_
{
    unsigned int   param_num;
    APA_KEY_PARAM  param[APA_MAX_PARAM_NUM];
}APA_KEY_PARAM_LIST;


#ifdef __cplusplus
}
#endif 

#endif /* _HIK_APA_BASE_H_ */

