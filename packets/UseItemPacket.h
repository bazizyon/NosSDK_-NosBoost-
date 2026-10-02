#pragma once

namespace Packet {
    class UseItemPacket {
    public:
        static constexpr const char* Header = "u_i";

        int type = 1;
        long characterID = 0;
        int inventoryType = 0;
        int slot = 0;
        int unknown1 = 0;
        int unknown2 = 0;
    };
}
