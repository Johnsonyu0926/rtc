/** @file       IMuxDefine.h
 *  @note       Hikvision Digital Technology Co., Ltd. All Right Reserved.
 *  @brief      IO��ؽṹ����
 *
 *  @version    V1.0.1
 *  @author     ������
 *  @date       2015/10/13
 *  @note       NEW
 *
 */
#ifndef _IMUX_DEFINE_H_
#define _IMUX_DEFINE_H_

#include "HKMI.h"

// ���������
#define MAX_TRACK_COUNT             8

// ���������
#define UNKNOW_PACKET               0
#define VIDEO_PACKET                1
#ifndef AUDIO_PACKET
    #define AUDIO_PACKET            2
#endif
#ifndef PRIVT_PACKET
    #define PRIVT_PACKET            3
#endif
#define HIK_FILE_HEADER             4
#define HIK_FILE_INDEX              5

// ��Ƶ��Ϣ����
#define MIN_FRAMERATE               (1.0 / 16)      // ��С֡��
#define COMMON_FRAMERATE            25              // Ĭ��֡��
#define MAX_FRAMERATE               480             // ���֡��480

// ���涨��
#define DEFAULT_BUF_SIZE            (1024*1024*2)   // ͨ�õĻ����С
#define MAX_VALID_BUFSIZE           (1024*1024*32)  // ���Ļ��泤�ȣ������ж����ݳ����Ƿ�Ϸ�

// ������Ч�Լ��
#define ARG_CHECK(arg)\
{\
    if(0 == (arg))\
    {\
        return IMUX_E_PARAMETER;\
    }\
}

// ��������ֵ���
#define ERR_CHECK(err)\
{\
    int ret = (err);\
    if(IMUX_OK != (ret))\
    {\
        return ret;\
    }\
}

// ʱ��
typedef struct _HK_SYSTEMTIME
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
}HK_SYSTEMTIME;

// ����������
typedef struct
{
    // �̶��Ĳ���
    unsigned int        pack_size;             // PS��TS��RTP������������0ΪĬ�ϳ���
    unsigned int        track_index;           // �����
    unsigned int        syc_video_track;       // ��������Ƶ�����

    unsigned int        system_format;         // Ŀ���װ��ʽ
    unsigned int        system_format_subtype; // Ŀ�����͵��Ӹ�ʽ��Ŀǰֻʹ����MP4��������װ������

    unsigned int        video_format;          // ��Ƶ����
    unsigned int        audio_format;          // ��Ƶ����
    unsigned int        privt_format;          // ˽����������

    // �ο�֡��Ϣ���ǹ̶�����
    unsigned int        is_hik_stream;         // �Ƿ���Ϻ�������
    unsigned int        encrypt_type;          // ��������
    unsigned int        frame_type;            // ��ǰ֡���� I/P/B/audio/privt
    unsigned int        time_stamp;            // ʱ���
    float               duration;              // ֡ʱ��
    unsigned int        frame_num;             // ֡��
    HK_SYSTEMTIME       global_time;           // ȫ��ʱ�䣨�����������У�

    // ��Ƶ����
    struct
    {
        unsigned short  width_orig;            // �ֱ��ʣ�ԭʼ��
        unsigned short  height_orig;           // �ֱ��ʣ�ԭʼ��
        unsigned short  width_play;            // �ֱ��ʣ��ü���
        unsigned short  height_play;           // �ֱ��ʣ��ü���
        float           frame_rate;            // ֡��
        unsigned short  interlace;             // �Ƿ񳡱���
        unsigned short  b_frame_num;           // ��ģʽ�У�B֡�ĸ���
        unsigned int    is_svc_stream;         // �Ƿ�SVC����
    }video;

    // ��Ƶ����
    struct
    {
        unsigned short  channels;              // ����
        unsigned short  bits_per_sample;       // ��λ
        unsigned int    samples_rate;          // ������
        unsigned int    bit_rate;              // ������
    }audio;

    // ˽�в���
    struct
    {
        unsigned int    privt_type;            // ˽������
        unsigned int    data_type;             // ������
    }privt;
}MUX_PARAM;

// �������ݽṹ��
typedef struct INPUT_BUF
{
    unsigned char*      pData;                 // ���ݵ�ַ
    unsigned int        nDataLen;              // ���ݳ���
}INPUT_BUF;

// ������ݽṹ��
typedef struct OUT_BUF
{
    unsigned char*      pData;                 // ���ݵ�ַ
    unsigned int        nDataLen;              // ���ݳ���
}OUT_BUF;

// ��������Ϣ
typedef struct
{
    unsigned int        target_id;             // Ŀ���������
    unsigned int        packet_type;           // ������
    unsigned int        is_key_frame;          // 0���ǹؼ�֡��1���ؼ�֡
    unsigned int        time_stamp;            // ʱ���
}MUX_INFO;

#endif  // _IDEMUX_DEFINE_H_
