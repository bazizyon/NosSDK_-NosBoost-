#pragma once
#include <string>

namespace Packet {
    class RpPacket {
    public:
        static constexpr const char* Header = "rp";

        int mapId = 0;
        int xPos = 0;
        int yPos = 0;
        std::string command;
    };
}
