#ifndef _HIK_APA_COMMON_H_
#define _HIK_APA_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
typedef unsigned int HRESULT;
#endif

enum class APA_MEM_ALIGNMENT {
    ALIGN_4BYTE = 4,
    ALIGN_8BYTE = 8,
    ALIGN_16BYTE = 16,
    ALIGN_32BYTE = 32,
    ALIGN_64BYTE = 64,
    ALIGN_128BYTE = 128,
    ALIGN_256BYTE = 256,
    ALIGN_END = 0x0FFFFF
};

enum class APA_MEM_ATTRS {
    SCRATCH,
    PERSIST,
    ATTRS_END = 0x0FFFFF
};

enum class APA_MEM_PLAT {
    CPU,
    GPU,
    PLAT_END = 0x0FFFFF
};

enum class APA_MEM_SPACE {
    EXTERNAL_PROG,
    INTERNAL_PROG,
    EXTERNAL_TILERED_DATA,
    EXTERNAL_CACHED_DATA,
    EXTERNAL_UNCACHED_DATA,
    INTERNAL_DATA,
    EXTERNAL_TILERED8,
    EXTERNAL_TILERED16,
    EXTERNAL_TILERED32,
    EXTERNAL_TILEREDPAGE,
    EXTERNAL_END = 0x0FFFFF
};

struct APA_MEM_TAB {
    unsigned int size;
    APA_MEM_ALIGNMENT alignment;
    APA_MEM_SPACE space;
    APA_MEM_ATTRS attrs;
    void* base;
    APA_MEM_PLAT plat;
};

struct APA_AUDIO_INFO {
    unsigned int channel_num;
    unsigned int sample_rate;
    unsigned int bits_per_sample;
    unsigned int data_len;
    int reserved[4];
};

enum class APA_SET_CFG_TYPE {
    SINGLE_PARAM = 0x0001,
    PARAM_LIST = 0x0002,
    DEFAULT_PARAM = 0x0003,
    RESTART_LIB = 0x0004,
    END = 0x0FFFFF
};

enum class APA_GET_CFG_TYPE {
    SINGLE_PARAM = 0x0001,
    PARAM_LIST = 0x0002,
    DEFAULT_PARAM = 0x0003,
    VERSION = 0x0004,
    END = 0x0FFFFF
};

struct APA_KEY_PARAM {
    int index;
    int value;
};

struct APA_KEY_PARAM_LIST {
    unsigned int param_num;
    APA_KEY_PARAM param[50];
};

#ifdef __cplusplus
}
#endif 

#endif // _HIK_APA_COMMON_H_
