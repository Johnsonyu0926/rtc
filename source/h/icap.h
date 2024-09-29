#ifndef LOG_H
#define LOG_H

#include <string>
#include <fstream>
#include <memory>
#include <iostream>
#include <mutex>
#include <ctime>
#include <sstream>

class CLogger {
public:
    enum class LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    static CLogger& getInstance() {
        static CLogger instance;
        return instance;
    }

    void setLogFile(const std::string& filename) {
        std::lock_guard<std::mutex> guard(m_mutex);
        m_logFile = std::make_shared<std::ofstream>(filename, std::ios::app);
    }

    void log(LogLevel level, const std::string& message) {
        std::lock_guard<std::mutex> guard(m_mutex);

        if (m_logFile && m_logFile->is_open()) {
            *m_logFile << getTimestamp() << " [" << logLevelToString(level) << "] " << message << std::endl;
        } else {
            std::cerr << getTimestamp() << " [" << logLevelToString(level) << "] " << message << std::endl;
        }
    }

    void debug(const std::string& message) { log(LogLevel::DEBUG, message); }
    void info(const std::string& message) { log(LogLevel::INFO, message); }
    void warning(const std::string& message) { log(LogLevel::WARNING, message); }
    void error(const std::string& message) { log(LogLevel::ERROR, message); }

private:
    CLogger() = default;
    ~CLogger() = default;
    CLogger(const CLogger&) = delete;
    CLogger& operator=(const CLogger&) = delete;

    std::string getTimestamp() {
        auto now = std::time(nullptr);
        std::tm tm;
#ifdef _WIN32
        localtime_s(&tm, &now);
#else
        localtime_r(&now, &tm);
#endif
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    std::string logLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::DEBUG: return "DEBUG";
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }

    std::shared_ptr<std::ofstream> m_logFile;
    std::mutex m_mutex;
};

#endif // LOG_H
