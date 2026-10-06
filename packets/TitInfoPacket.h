#pragma once
#include "EntityType.h"

namespace Packet {
    class TitInfoPacket {
    public:
        static constexpr const char* Header = "titinfo";

        EntityType entityType = EntityType::Player;
        long entityID = 0;
        int visibleTitle = 0;   // item vnum of the title, 0 when there is none
        int effectTitle = 0;
    };
}
