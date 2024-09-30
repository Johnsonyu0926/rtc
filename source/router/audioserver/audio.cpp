#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "audio.hpp"
#include "AudioPlayUtils.hpp"
#include "MqttConfig.hpp"

class AudioServer {
public:
    AudioServer() = default;
    ~AudioServer() = default;

    void start() {
        loadConfig();
        // Additional initialization can be placed here
        
        running = true;
        server_thread = std::thread(&AudioServer::run, this);
    }

    void stop() {
        running = false;
        if (server_thread.joinable()) {
            server_thread.join();
        }
    }

private:
    void loadConfig() {
        MqttConfig config;
        if (!config.load_file()) {
            std::cerr << "Failed to load MQTT config" << std::endl;
        } else {
            request_topic = config.get_request_topic();
            publish_topic = config.get_publish_topic();
        }
    }

    void run() {
        while (running) {
            // Main server loop
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    std::string request_topic;
    std::string publish_topic;
    std::thread server_thread;
    bool running = false;
};

int main() {
    AudioServer server;
    server.start();

    std::this_thread::sleep_for(std::chrono::seconds(10));  // Run for 10 seconds

    server.stop();
    return 0;
}
