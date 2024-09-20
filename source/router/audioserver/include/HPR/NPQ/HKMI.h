/** @file       HKMI.h
 *  @note       Hikvision Digital Technology Co., Ltd. All Right Reserved.
 *  @brief      ����ý����Ϣ����
 *
 *  @version    V1.0.1
 *  @author     ������
 *  @date       2015/08/13
 *  @note       NEW
 *
 */
#ifndef _HKMI_H_
#define _HKMI_H_


// ϵͳ��װ�㶨��
#define MI_SYSTEM_NULL         0x0000            // ��֧�ֵķ�ת��ʽ
#define MI_SYSTEM_HIK          0x0001            // ������װ��
#define MI_SYSTEM_MPEG2_PS     0x0002            // PS��װ��Program Stream
#define MI_SYSTEM_MPEG2_TS     0x0003            // TS��װ��Transport Stream
#define MI_SYSTEM_RTP          0x0004            // RTP��װ
#define MI_SYSTEM_MPEG4        0x0005            // ISO Base Media Format and Extension��.MP4, .AVC, .MOV, .3GP
#define MI_SYSTEM_ASF          0x0006            // ASF
#define MI_SYSTEM_AVI          0x0007            // AVI
#define MI_SYSTEM_FLV          0x0008            // FLV
#define MI_SYSTEM_RTMP         0x0009            // RTMP

// ��Ƶ�������Ͷ���
#define MI_VIDEO_NULL          0x0000            // ����Ƶ����
#define MI_VIDEO_HIK264        0x0001            // ����H.264�Ͳ��ֽ����עH264���������������
#define MI_VIDEO_MPEG2         0x0002            // ��׼MPEG2
#define MI_VIDEO_MPEG4         0x0003            // ��׼MPEG4
#define MI_VIDEO_MJPEG         0x0004            // Motion Jpeg
#define MI_VIDEO_AVC264        0x0100            // ��׼H264/AVC
#define MI_VIDEO_AVC265        0x0005            // ��׼H.265����
#define MI_VIDEO_SVAC          0x0006            // ��׼SVAC����
#define MI_VIDEO_SVC264        0x0110            // SVC����
#define MI_VIDEO_WMV9          0x0200            // WMV9
#define MI_VIDEO_VC1           0x0201            // VC1
#define MI_VIDEO_REAL          0x0300            // REAL����
#define MI_VIDEO_MSMPEG4V1     0x0811            // ΢�����mpeg�����ʽversion1
#define MI_VIDEO_MSMPEG4V2     0x0812            // ΢�����mpeg�����ʽversion2
#define MI_VIDEO_MSMPEG4V3     0x0813            // ΢�����mpeg�����ʽversion3
#define MI_VIDEO_WMV1          0x0821            // ΢�����WMV�����ʽversion1
#define MI_VIDEO_WMV2          0x0822            // ΢�����WMV�����ʽversion2

// ��Ƶ�������Ͷ���
#define MI_AUDIO_NULL          0x0000            // û����Ƶ
#define MI_AUDIO_ADPCM         0x1000            // ADPCM
#define MI_AUDIO_MPEG          0x2000            // MPEGϵ����Ƶ��������������Ӧ����MPEG��Ƶ
#define MI_AUDIO_AAC           0x2001            // AAC����
#define MI_AUDIO_RAW_DATA8     0x7000            // ������Ϊ8k��ԭʼ����
#define MI_AUDIO_RAW_UDATA16   0x7001            // ������Ϊ16k��ԭʼ���ݣ���L16
#define MI_AUDIO_G711_U        0x7110            // G711 U Law
#define MI_AUDIO_G711_A        0x7111            // G711 A Law
#define MI_AUDIO_G722_1        0x7221            // G722.1
#define MI_AUDIO_G723_1        0x7231            // G723.1
#define MI_AUDIO_G726_U        0x7260            // G726 U Law
#define MI_AUDIO_G726_A        0x7261            // G726 A Law
#define MI_AUDIO_G726_16       0x7262
#define MI_AUDIO_G729          0x7290            // G729
#define MI_AUDIO_AMR_NB        0x3000
#define MI_AUDIO_WMA_V2        0x8011            // WMA_V2

// ˽������
#define MI_PRIVT_IVS_INFO      0x0003
#define MI_PRIVT_ITS_INFO      0x0004
#define MI_PRIVT_IAS_INFO      0x0005
#define MI_PRIVT_MD_INFO       0x0008
#define MI_INTER_DECODER       0xBDBF            // ��������

#endif  // _HKMI_H_
