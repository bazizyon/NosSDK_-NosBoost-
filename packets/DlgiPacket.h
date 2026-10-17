#pragma once
#include <string>

namespace Packet {
    class DlgiPacket {
    public:
        static constexpr const char* Header = "dlgi";

        std::string command1;
        std::string command2;
        int messageId = 0;
    };
}
