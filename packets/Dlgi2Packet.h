#pragma once
#include <string>

namespace Packet {
    class Dlgi2Packet {
    public:
        static constexpr const char* Header = "dlgi2";

        std::string command1;
        std::string command2;
        int messageType = 0; // 1505 group share, 233 group invite
        int unknown1 = 0;
        std::string sender;
    };
}
