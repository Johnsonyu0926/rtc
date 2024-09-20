#pragma once

#include "json.hpp"
#include "add_custom_audio_file.hpp"
#include "add_column_custom_audio_file.hpp"
#include "audiocfg.hpp"
#include "utils.h"
#include "getaudiolist.hpp"
//{"cmd":"AudioDelete","deleteName":"23.mp3","storageType":1}
namespace asns {

    class CDeleteAudioResult {
    private:
        string cmd;
        int resultId;
        string msg;
        vector <CGetAudioData> data;

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CDeleteAudioResult, cmd, resultId, data, msg)

    public:
        void do_success() {
            cmd = "AudioDelete";
            resultId = 1;
            msg = "AudioDelete handle success";

            CAddCustomAudioFileBusiness audios;
            audios.load();
            for (auto & busines : audios.business) {
                CGetAudioData v;
                v.storageType = 0;
                v.type = 32;
                busines.parseFile();
                v.fileName = busines.customAudioName;
                CAudioCfgBusiness cfg;
                cfg.load();
                CUtils utils;
                v.size = utils.get_size(cfg.getAudioFilePath().c_str(), busines.filename);
                v.audioId = busines.customAudioID;
                data.push_back(v);
            }
        }
    };

    class CDeleteAudio {
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CDeleteAudio, cmd, deleteName, storageType)

        int do_del(std::string &name, int type) {
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