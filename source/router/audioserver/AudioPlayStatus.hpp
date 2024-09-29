#pragma once

#include <string>
#include "public.hpp"

class PlayStatus {
public:
    static PlayStatus& getInstance() {
        static PlayStatus instance;
        return instance;
    }

    PlayStatus(const PlayStatus&) = delete;
    PlayStatus& operator=(const PlayStatus&) = delete;

    void init() {
        m_mqttPlayStatus = asns::STOP_TASK_PLAYING;
        m_playId = asns::STOP_TASK_PLAYING;
        m_priority = asns::STOP_TASK_PLAYING;
        m_pId = asns::STOP_TASK_PLAYING;
        playContent.clear();
    }

    int getPlayState() const { return m_playId != asns::STOP_TASK_PLAYING; }
    int getPlayId() const { return m_playId; }
    void setPlayId(int id) { m_playId = id; }
    int getPriority() const { return m_priority; }
    void setPriority(int id) { m_priority = id; }
    pid_t getProcessId() const { return m_pId; }
    void setProcessId(pid_t id) { m_pId = id; }
    std::string getPlayContent() const { return playContent; }
    void setPlayContent(const std::string& content) { playContent = content; }
    int getMqttPlayStatus() const { return m_mqttPlayStatus; }
    void setMqttPlayStatus(int status) { m_mqttPlayStatus = status; }

private:
    PlayStatus() = default;

    int m_mqttPlayStatus{-1};
    int m_playId{-1};
    int m_priority{-1};
    pid_t m_pId{-1};
    std::string playContent;
};
