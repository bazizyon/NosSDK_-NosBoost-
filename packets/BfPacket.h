#pragma once
#include "EntityType.h"

namespace Packet {
    class BfPacket {
    public:
        static constexpr const char* Header = "bf";

        EntityType entityType = EntityType::Player;
        long entityID = 0;
        int charge = 0;
        int cardID = 0;
        int duration = 0;   // in tenths of a second, 0 means the buff ended
        int level = 0;
    };
}
