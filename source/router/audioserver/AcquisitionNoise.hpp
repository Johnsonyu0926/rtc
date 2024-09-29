#pragma once

#include <deque>
#include <numeric>
#include <cmath>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "utils.h"

class AcquisitionNoise {
public:
    static AcquisitionNoise& getInstance() {
        static AcquisitionNoise instance;
        return instance;
    }

    AcquisitionNoise(const AcquisitionNoise&) = delete;
    AcquisitionNoise& operator=(const AcquisitionNoise&) = delete;

    void updateNoise(const std::deque<double>& noiseDeque) {
        std::lock_guard<std::mutex> lock(mutex_);
        this->noiseDeque = noiseDeque;
    }

    std::deque<double> getNoiseDeque() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return noiseDeque;
    }

    void setMonitorStatus(bool status) {
        std::lock_guard<std::mutex> lock(mutex_);
        monitorStatus = status;
    }

    bool getMonitorStatus() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return monitorStatus;
    }

    void setFrequency(int freq) {
        std::lock_guard<std::mutex> lock(mutex_);
        frequency = freq;
    }

    int getFrequency() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return frequency;
    }

    void setCalcCycle(int cycle) {
        std::lock_guard<std::mutex> lock(mutex_);
        calcCycle = cycle;
    }

    int getCalcCycle() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return calcCycle;
    }

    void setDecibel(double dec) {
        std::lock_guard<std::mutex> lock(mutex_);
        decibel = dec;
    }

    double getDecibel() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return decibel;
    }

    void file_update() {
        std::lock_guard<std::mutex> lock(mutex_);
        std::ofstream ofs("/mnt/cfg/noise.json");
        json j = {{"noiseDeque", noiseDeque}, {"monitorStatus", monitorStatus}, {"frequency", frequency}, {"calcCycle", calcCycle}, {"decibel", decibel}};
        ofs << j.dump(4);
    }

private:
    AcquisitionNoise() : monitorStatus(false), frequency(0), calcCycle(0), decibel(0.0) {}

    mutable std::mutex mutex_;
    std::deque<double> noiseDeque;
    bool monitorStatus;
    int frequency;
    int calcCycle;
    double decibel;
};
