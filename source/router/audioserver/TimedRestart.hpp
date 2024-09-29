#pragma once

#include <chrono>
#include <thread>
#include <functional>

class TimedRestart {
public:
    TimedRestart() = default;
    ~TimedRestart() = default;

    void start(int interval_seconds, const std::function<void()>& task) {
        running = true;
        worker_thread = std::thread([this, interval_seconds, task]() {
            while (running) {
                std::this_thread::sleep_for(std::chrono::seconds(interval_seconds));
                if (running) {
                    task();
                }
            }
        });
    }

    void stop() {
        running = false;
        if (worker_thread.joinable()) {
            worker_thread.join();
        }
    }

private:
    bool running = false;
    std::thread worker_thread;
};
