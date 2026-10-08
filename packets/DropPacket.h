#pragma once

namespace Packet {
    class DropPacket {
    public:
        static constexpr const char* Header = "drop";

        int itemVNum = 0;
        long dropID = 0;
        int xPos = 0;
        int yPos = 0;
        int amount = 0;
        int isQuestItem = 0;
        long ownerID = -1;
    };
}
