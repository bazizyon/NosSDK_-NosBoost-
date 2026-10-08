#pragma once
#include "EntityType.h"

namespace Packet {
    class GetPacket {
    public:
        static constexpr const char* Header = "get";

        EntityType pickerType = EntityType::Player;
        long pickerID = 0;
        long dropID = 0;
        int unknown = 0;
    };
}
