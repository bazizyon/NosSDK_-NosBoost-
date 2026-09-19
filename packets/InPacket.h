#pragma once
#include "EntityType.h"
#include "sub/InPlayerSubPacket.h"
#include <string>

namespace Packet {
    class InPacket {
    public:
        static constexpr const char* Header = "in";

        EntityType entityType = EntityType::Monster;
        std::string entityName;
        int entityVNum = 0;
        long entityID = 0;
        int xPos = 0;
        int yPos = 0;
        int direction = 0;
        InPlayerSubPacket inPlayerSubPacket;
        // InItemSubPacket
        // InNonPlayerSubPacket inNonPlayerSubPacket;
    };
}
