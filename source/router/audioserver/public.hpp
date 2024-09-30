#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <chrono>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <cerrno>
#include <csignal>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <linux/sockios.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <linux/if_tun.h>
#include <linux/if.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace asns {

class Utils {
public:
    static std::string exec(const char* cmd) {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }

    static std::string hex_to_string(const std::string& input) {
        static const char* const lut = "0123456789ABCDEF";
        size_t len = input.length();
        if (len & 1) throw std::invalid_argument("odd length");

        std::string output;
        output.reserve(len / 2);
        for (size_t i = 0; i < len; i += 2) {
            char a = input[i];
            const char* p = std::lower_bound(lut, lut + 16, a);
            if (*p != a) throw std::invalid_argument("not a hex digit");

            char b = input[i + 1];
            const char* q = std::lower_bound(lut, lut + 16, b);
            if (*q != b) throw std::invalid_argument("not a hex digit");

            output.push_back(((p - lut) << 4) | (q - lut));
        }
        return output;
    }

    static void network_set(const std::string& gateway, const std::string& ipAddress, const std::string& netMask) {
        std::ostringstream oss;
        oss << "ifconfig eth0 " << ipAddress << " netmask " << netMask;
        exec(oss.str().c_str());
        oss.str("");
        oss << "route add default gw " << gateway;
        exec(oss.str().c_str());
    }
};

} // namespace asns
