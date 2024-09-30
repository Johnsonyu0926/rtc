#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/statfs.h>
#include <string>
#include <dirent.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <future>
#include <net/if.h>
#include <arpa/inet.h>
#include "public.hpp"
#include "audiocfg.hpp"
#include "doorsbase.h"
#include "easylogging++.h"

class Singleton {
public:
    ~Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    static Singleton &getInstance() {
        static Singleton instance;
        return instance;
    }
    std::string getConnIp() const { return m_connIp; }
private:
    Singleton() = default;
    std::string m_connIp;
};

class CUtils {
private:
    char m_lan[1024] = {0};
    std::map<std::string, std::string> m_month = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };

public:
    int get_file_size(const std::string &path) {
        struct stat st;
        if (stat(path.c_str(), &st) != 0) {
            LOG(ERROR) << "Failed to get file size for: " << path;
            return -1;
        }
        return st.st_size;
    }

    void get_dir_file_names(const std::string &path, std::vector<std::string> &files) {
        DIR *pDir;
        struct dirent *ptr;
        if (!(pDir = opendir(path.c_str()))) return;
        while ((ptr = readdir(pDir)) != nullptr) {
            if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0) {
                files.emplace_back(ptr->d_name);
            }
        }
        closedir(pDir);
    }

    bool find_dir_file_exists(const std::string &path, const std::string &name) {
        std::vector<std::string> files_name;
        get_dir_file_names(path, files_name);
        return std::find(files_name.begin(), files_name.end(), name) != files_name.end();
    }

    int isIpWL() {
        std::string connIp = Singleton::getInstance().getConnIp();
        if (connIp.empty()) return 1;
        connIp = connIp.substr(0, connIp.find_last_of('.'));

        std::string lanIp = is_ros_platform() ? get_by_cmd_res("cm get_val VLAN1 ipaddress | tail -1") : get_by_cmd_res("uci get network.lan.ipaddr");
        std::string wanIp = is_ros_platform() ? get_by_cmd_res("cm get_val WAN1 ipaddress | tail -1") : get_by_cmd_res("uci get network.wan.ipaddr");

        return (connIp == lanIp.substr(0, lanIp.find_last_of('.')) || connIp == wanIp.substr(0, wanIp.find_last_of('.'))) ? 0 : 1;
    }

    int is_ros_platform() {
        std::ifstream i("/bin/cm");
        return i.is_open();
    }

    std::string get_by_cmd_res(const std::string &cmd) {
        FILE* fp = popen(cmd.c_str(), "r");
        if (!fp) {
            LOG(ERROR) << "Failed to run command: " << cmd;
            return "";
        }
        char buffer[128];
        std::string result;
        while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
            result += buffer;
        }
        pclose(fp);
        return result;
    }

    std::string get_lan_ip() {
        return is_ros_platform() ? get_by_cmd_res("cm get_val VLAN1 ipaddress | tail -1") : get_by_cmd_res("uci get network.lan.ipaddr");
    }

    std::string get_lan_netmask() {
        return is_ros_platform() ? get_by_cmd_res("cm get_val VLAN1 ipmask | tail -1") : get_by_cmd_res("uci get network.lan.netmask");
    }

    std::string get_lan_gateway() {
        return is_ros_platform() ? get_by_cmd_res("cm get_val VLAN1 gateway | tail -1") : get_by_cmd_res("uci get network.lan.gateway");
    }

    std::string get_wan_ip() {
        return is_ros_platform() ? get_by_cmd_res("cm get_val WAN1 ipaddress | tail -1") : get_by_cmd_res("uci get network.wan.ipaddr");
    }

    std::string get_wan_netmask() {
        return is_ros_platform() ? get_by_cmd_res("cm get_val WAN1 ipmask | tail -1") : get_by_cmd_res("uci get network.wan.netmask");
    }

    std::string get_wan_gateway() {
        return is_ros_platform() ? get_by_cmd_res("cm get_val WAN1 gateway | tail -1") : get_by_cmd_res("uci get network.wan.gateway");
    }

    std::string get_upload_result(const std::string &url, const std::string &path, const std::string &name) {
        std::string cmd = "curl --location --request GET " + url + " -f --output " + path + name + " 2>&1";
        std::string res = get_by_cmd_res(cmd);
        LOG(INFO) << "cmd:" << cmd << " res:" << res;

        if (res.empty() || res.find("error") != std::string::npos || res.find("Connection refused") != std::string::npos ||
            res.find("No route to host") != std::string::npos || res.find("Host is unreachable") != std::string::npos ||
            res.find("Failed to connect") != std::string::npos || res.find("Couldn't connect to server") != std::string::npos) {
            return "file upload fail";
        }
        return get_file_size(path + name) > 0 ? "success" : "file upload fail";
    }

    void async_wait(int count, int after, int interval, auto &&f, auto &&... args) {
        std::function<typename std::result_of<decltype(f)(decltype(args)...)>::type()> task
            (std::bind(std::forward<decltype(f)>(f), std::forward<decltype(args)>(args)...));
        std::thread([after, task, count, interval]() {
            if (count == 0) {
                std::this_thread::sleep_for(std::chrono::seconds(after));
                while (true) {
                    task();
                    std::this_thread::sleep_for(std::chrono::seconds(interval));
                }
            } else {
                std::this_thread::sleep_for(std::chrono::seconds(after));
                for (int i = 0; i < count; ++i) {
                    task();
                    std::this_thread::sleep_for(std::chrono::seconds(interval));
                }
            }
        }).detach();
    }

    std::vector<std::string> string_split(const std::string &str_v, const std::string &del_ims = " ") {
        std::vector<std::string> output;
        size_t first = 0;
        while (first < str_v.size()) {
            const auto second = str_v.find_first_of(del_ims, first);
            if (first != second) {
                output.emplace_back(str_v.substr(first, second - first));
            }
            if (second == std::string::npos) {
                break;
            }
            first = second + 1;
        }
        return output;
    }

    int statistical_character_count(const std::string &str) {
        int LowerCase = 0, UpperCase = 0, space = 0, digit = 0, character = 0, chinese = 0;
        for (const char &c : str) {
            if (std::islower(c)) {
                LowerCase++;
            } else if (std::isupper(c)) {
                UpperCase++;
            } else if (std::isdigit(c)) {
                digit++;
            } else if (static_cast<unsigned char>(c) >= 0x80) {
                chinese++;
            } else if (std::isspace(c)) {
                space++;
            } else {
                character++;
            }
        }
        return UpperCase + LowerCase + digit + character + (chinese / 3) + space;
    }

    int change_password(const char *password) {
        if (is_ros_platform()) {
            std::string cmd = "webs -P " + std::string(password);
            system(cmd.c_str());
            cmd = "cm set_val sys serverpassword " + std::string(password);
            system(cmd.c_str());
        }
        return 1;
    }

    void bit_rate_32_to_48(const std::string &path) {
        // Implementation for bit rate conversion
    }

    void udp_multicast_send(const std::string &ip, uint16_t port, const std::string &msg) {
        struct sockaddr_in server{};
        struct ip_mreqn group{};

        int sock = socket(AF_INET, SOCK_DGRAM, 0);

        bzero(&server, sizeof(server));
        server.sin_family = AF_INET;
        inet_pton(AF_INET, get_lan_ip().c_str(), &server.sin_addr.s_addr);
        server.sin_port = htons(port);

        ::bind(sock, (struct sockaddr *) &server, sizeof(server));

        inet_pton(AF_INET, ip.c_str(), &group.imr_multiaddr.s_addr);
        inet_pton(AF_INET, "0.0.0.0", &group.imr_address);

        group.imr_ifindex = if_nametoindex(isIpWL() == 0 ? "br0" : "WAN1");
        setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, &group.imr_multiaddr.s_addr, sizeof(group.imr_multiaddr.s_addr));

        struct sockaddr_in client{};
        bzero(&client, sizeof(client));
        client.sin_family = AF_INET;
        inet_pton(AF_INET, ip.c_str(), &client.sin_addr.s_addr);
        client.sin_port = htons(port);

        sendto(sock, msg.c_str(), msg.length(), 0, (struct sockaddr *) &client, sizeof(client));
        LOG_EVERY_N(10, INFO) << "udp_multicast_send: " << ip << " " << port << " msg: " << msg;
        close(sock);
    }

    static void cmd_system(const std::string &cmd) {
        system(cmd.c_str());
    }
};
