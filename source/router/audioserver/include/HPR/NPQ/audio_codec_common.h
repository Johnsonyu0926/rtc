#ifndef _AUDIO_CODEC_COMMON_H_
#define _AUDIO_CODEC_COMMON_H_

#ifdef _cplusplus
extern "C" {
#endif

#include "datatypedef.h"
#include "HikCrypt/mem_tab.h"

constexpr int AUDIO_CODEC_BUF_SIZE = 8192;
constexpr int AUDIO_DEC_DATA_SIZE = 2048;

enum class BITCTRLLEVEL {
    LEVEL1 = 1,
    LEVEL2 = 2,
    LEVEL3 = 3
};

enum class AUDIO_ENC_MODE {
    AMR_MR475 = 0,
    AMR_MR515,
    AMR_MR59,
    AMR_MR67,
    AMR_MR74,
    AMR_MR795,
    AMR_MR102,
    AMR_MR122,
    AMR_MRDTX,
    AMR_N_MODES
};

struct AUDIOENC_INFO {
    U32 in_frame_size;
    S32 reserved[16];
};

struct AUDIOENC_PARAM {
    U32 sample_rate;
    U32 num_channels;
    U32 bitrate;
    U32 vad_dtx_enable;
    BITCTRLLEVEL bit_ctrl_level;
    S32 reserved[16];
};

struct AUDIOENC_PROCESS_PARAM {
    U08 *in_buf;
    U08 *out_buf;
    U32 out_frame_size;
    S32 g726enc_reset;
    S32 g711_type;
    AUDIO_ENC_MODE enc_mode;
    S32 reserved[16];
};

// 定义其他宏和枚举
constexpr int HIK_AUDIOCODEC_LIB_S_OK = 1;
constexpr int HIK_AUDIOCODEC_LIB_S_FAIL = 0;
constexpr int HIK_AUDIOCODEC_LIB_E_PARAM_NULL = 0x80000000;
constexpr int HIK_AUDIOCODEC_LIB_E_HANDLE_NULL = 0x80000001;
constexpr int HIK_AUDIOCODEC_LIB_E_MEMORY_NULL = 0x80000002;
constexpr int HIK_AUDIOCODEC_LIB_E_CHANNEL_ERR = 0x80000003;
constexpr int HIK_AUDIOCODEC_LIB_E_SAMPLERATE_ERR = 0x80000004;
constexpr int HIK_AUDIOCODEC_LIB_E_MAXBITS_ERR = 0x80000005;
constexpr int HIK_AUDIOCODEC_LIB_E_BITSCTRL_ERR = 0x80000006;
constexpr int HIK_AUDIOCODEC_LIB_E_BITRATE_ERR = 0x80000007;
constexpr int HIK_AUDIOCODEC_LIB_E_INPUT_SIZE_ERR = 0x80000008;
constexpr int HIK_AUDIOCODEC_LIB_E_MEMTAB_SIZE_ERR = 0x80000009;
constexpr int HIK_AUDIOCODEC_LIB_E_BUF_TOO_SMALL = 0x8000000a;

#ifdef _cplusplus
}
#endif

#endif // _AUDIO_CODEC_COMMON_H_
