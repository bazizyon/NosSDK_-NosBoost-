#pragma once

namespace Packet {
    class RBossPacket {
    public:
        static constexpr const char* Header = "rboss";

        int entityType = 0;
        long entityID = 0;
        int HP = 0;
        int maxHP = 0;
        int VNum = 0;
    };
}
