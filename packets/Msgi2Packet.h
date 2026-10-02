#pragma once
#include <string>
#include <vector>

namespace Packet {
    class Msgi2Packet {
    public:
        static constexpr const char* Header = "msgi2";

        int type = 0;
        int messageId = 0;
        std::vector<std::string> arguments;
    };
}
