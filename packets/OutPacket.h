#pragma once
#include "EntityType.h"

namespace Packet {
    class OutPacket {
    public:
        static constexpr const char* Header = "out";

        EntityType entityType = EntityType::Monster;
        long entityID = 0;
    };
}
