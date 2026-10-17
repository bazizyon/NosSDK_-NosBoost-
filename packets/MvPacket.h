#pragma once
#include "EntityType.h"

namespace Packet {
    class MvPacket {
    public:
        static constexpr const char* Header = "mv";

        EntityType entityType = EntityType::Monster;
        long entityID = 0;
        int xPos = 0;
        int yPos = 0;
        int speed = 0;
    };
}
