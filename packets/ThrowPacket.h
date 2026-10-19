#pragma once

namespace Packet {
    class ThrowPacket {
    public:
        static constexpr const char* Header = "throw";

        int itemVNum = 0;
        long dropID = 0;
        int fromX = 0;
        int fromY = 0;
        int xPos = 0;
        int yPos = 0;
        int amount = 0;
    };
}
