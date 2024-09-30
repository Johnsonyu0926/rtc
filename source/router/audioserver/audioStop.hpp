#pragma once

#include "json.hpp"
#include "utils.h"

namespace asns {
    class CAudioStopResult {
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CAudioStopResult, cmd, resultId, msg)

        void do_success() {
            cmd = "AudioStop";
            resultId = 1;
            msg = "stop play success";
        }

    private:
        std::string cmd;
        int resultId;
        std::string msg;
    };

    class CAudioStop {
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CAudioStop, cmd)

        int do_req(CSocket *pClient) {
            AudioPlayUtil::audio_stop();
            CAudioStopResult audioStopResult;
            audioStopResult.do_success();
            return send_response(pClient, audioStopResult);
        }

    private:
        std::string cmd;

        int send_response(CSocket *pClient, CAudioStopResult &audioStopResult) {
            json js = audioStopResult;
            std::string str = js.dump();
            return pClient->Send(str.c_str(), str.length());
        }
    };
}
