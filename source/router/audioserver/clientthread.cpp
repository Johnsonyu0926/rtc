#include "clientthread.h"
#include "json.hpp"
#include "utils.h"
#include "audiocfg.hpp"
#include "audioPlay.hpp"
#include "audioStop.hpp"
#include "audio_del.hpp"
#include "broadcast_plan.hpp"
#include "MqttConfig.hpp"
#include "Relay.hpp"
#include "Rs485.hpp"
#include "Rs485NoiseMange.hpp"

using json = nlohmann::json;

bool CClientThread::InitInstance() {
    // Initialization code.
    return true;
}

bool CClientThread::ExitInstance() {
    // Cleanup code.
    return true;
}

bool CClientThread::Check(const unsigned char *szBuf) {
    // Check the buffer.
    return true;
}

bool CClientThread::Gen(unsigned char *szBuf) {
    // Generate data for the buffer.
    return true;
}

int CClientThread::do_req(char *buf, CSocket *pClient) {
    try {
        json j = json::parse(buf);
        std::string cmd = j.at("cmd").get<std::string>();

        if (cmd == "AudioPlay") {
            asns::CAudioPlay audioPlay;
            audioPlay = j.get<asns::CAudioPlay>();
            return audioPlay.do_req(pClient);
        } else if (cmd == "AudioStop") {
            asns::CAudioStop audioStop;
            audioStop = j.get<asns::CAudioStop>();
            return audioStop.do_req(pClient);
        } else if (cmd == "AudioDelete") {
            asns::CDeleteAudio audioDel;
            audioDel = j.get<asns::CDeleteAudio>();
            return audioDel.do_req(pClient);
        } else if (cmd == "BroadcastPlan") {
            asns::BroadcastPlan broadcastPlan;
            broadcastPlan = j.get<asns::BroadcastPlan>();
            return broadcastPlan.do_req(pClient);
        }
        // Add more commands as needed.
    } catch (const json::exception &e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return -1;
    }
    return -1;
}

int CClientThread::do_verify(char *buf) {
    // Verification code.
    return 0;
}

int CClientThread::do_str_req(CSocket *pClient) {
    // String request handling code.
    return 0;
}

int CClientThread::do_str_verify(char *buf, CSocket *pClient) {
    // String verification code.
    return 0;
}
