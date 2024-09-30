#pragma once

#include "json.hpp"
#include "add_custom_audio_file.hpp"
#include "add_column_custom_audio_file.hpp"
#include "audiocfg.hpp"
#include "utils.h"
#include "getaudiolist.hpp"

namespace asns {

class CDeleteAudioResult {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CDeleteAudioResult, cmd, resultId, data, msg)

    void do_success() {
        cmd = "AudioDelete";
        resultId = 1;
        msg = "AudioDelete handle success";
        CAddCustomAudioFileBusiness audios;
        audios.load();
        CAudioCfgBusiness cfg;
        cfg.load();
        CUtils utils;
        for (auto &busines : audios.business) {
            CGetAudioData v;
            v.storageType = 0;
            v.type = 32;
            busines.parseFile();
            v.fileName = busines.customAudioName;
            v.size = utils.get_size(cfg.getAudioFilePath().c_str(), busines.filename);
            v.audioId = busines.customAudioID;
            data.push_back(v);
        }
    }

private:
    std::string cmd;
    int resultId;
    std::string msg;
    std::vector<CGetAudioData> data;
};

class CDeleteAudio {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CDeleteAudio, cmd, deleteName, storageType)

    int do_del(const std::string &name, int type) {
        CAddCustomAudioFileBusiness audios;
        CAddColumnCustomAudioFileBusiness business;
        audios.deleteAudio(name);
        business.deleteAudio(name);
        return 0;
    }

    int do_req(CSocket *pClient) {
        do_del(deleteName, storageType);
        CDeleteAudioResult res;
        res.do_success();
        json j = res;
        std::string s = j.dump();
        pClient->Send(s.c_str(), s.length());
        return 1;
    }

private:
    std::string cmd;
    std::string deleteName;
    int storageType;
};
}
