#pragma once
#include "EntityType.h"

namespace Packet {
    class PairyPacket {
    public:
        static constexpr const char* Header = "pairy";

        EntityType entityType = EntityType::Player;
        long entityID = 0;
        int unknown0 = 0;
        int element = 0;        // 0 none, 1 fire, 2 water, 3 light, 4 shadow
        int elementRate = 0;
        int morph = 0;
    };
}
