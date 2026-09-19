#pragma once
#include "Packet.h"
#include "EntityType.h"

namespace Packet {
    class CModePacket {
    public:
        static constexpr const char* Header = "c_mode";

        EntityType entityType = EntityType::Monster;
        int entityID = 0;
        int morphVNum = 0;
        int wingLevel = 0;
        int wingType = 0;
        int morphBonus = 0;
        int characterSize = 0;
        int morphSkin = 0;

        bool spMode = false;
        bool vehicleMode = false;
    };
}
