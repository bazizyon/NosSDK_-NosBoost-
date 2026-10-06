#pragma once

namespace Packet {
    // sent when you right click an item, the answer is e_info or slinfo
    class EqInfoPacket {
    public:
        static constexpr const char* Header = "eqinfo";

        int type = 0;   // 0 is your equipment, 1 is the inventory
        int slot = 0;
    };
}
