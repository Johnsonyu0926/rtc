#pragma once

#include "json.hpp"
#include "audiocfg.hpp"
#include "utils.h"
#include "add_custom_audio_file.hpp"

namespace asns {
    class CAudioPlayResult {
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CAudioPlayResult, cmd, resultId, msg)

        void do_success() {
            cmd = "AudioPlay";
            resultId = 1;
            msg = "play success";
        }

        void do_fail(const std::string& str) {
            cmd = "AudioPlay";
            resultId = 2;
            msg = str;
        }

    private:
        std::string cmd;
        int resultId;
        std::string msg;

    };

    class CAudioPlay {
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CAudioPlay, cmd, audioName, playType, duration)

        int do_req(CSocket *pClient) {
            CAudioCfgBusiness cfg;
            cfg.load();
            CAudioPlayResult audioPlayResult;
            audioPlayResult.do_success();
            CUtils utils;
            if (CUtils::get_process_status("madplay")) {
                audioPlayResult.do_fail("Existing playback task");
                json js = audioPlayResult;
                std::string str = js.dump();
                pClient->Send(str.c_str(), str.length());
                return 1;
            }
            CAddCustomAudioFileBusiness business;
            if (business.exist(audioName) && utils.find_dir_file_exists(cfg.getAudioFilePath(), audioName) == false) {
                audioPlayResult.do_fail("no file");
            } else if (business.exist(audioName) == false &&
                       utils.find_dir_file_exists(cfg.getAudioFilePath(), audioName)) {
                audioPlayResult.do_fail("no file");
            } else if (business.exist(audioName) == false &&
                       utils.find_dir_file_exists(cfg.getAudioFilePath(), audioName) == false) {
                audioPlayResult.do_fail("no file");
            } else if (business.exist(audioName) && utils.find_dir_file_exists(cfg.getAudioFilePath(), audioName)) {
                if (CUtils::get_process_status("ffplay")) {
                    AudioPlayUtil::audio_stop();
                }
                switch (playType) {
                    case 0:
                        AudioPlayUtil::audio_loop_play(cfg.getAudioFilePath() + audioName, ASYNC_START);
                        break;
                    case 1: {
                        if (duration < 1) {
                            audioPlayResult.do_fail("parameter cannot be less than 1");
                            break;
                        }
                        AudioPlayUtil::audio_num_play(duration, cfg.getAudioFilePath() + audioName, ASYNC_START);
                        break;
                    }
                    case 2: {
                        if (duration < 1) {
                            audioPlayResult.do_fail("parameter cannot be less than 1");
                            break;
                        }
                        AudioPlayUtil::audio_time_play(duration, cfg.getAudioFilePath() + audioName, ASYNC_START);
                        break;
                    }
                }
            }
            json js = audioPlayResult;
            std::string str = js.dump();
            return pClient->Send(str.c_str(), str.length());
        }

    private:
        std::string cmd;
        std::string audioName;
        int playType;
        int duration;
    };
}