#pragma once
#include "EntityType.h"
#include "HitMode.h"

namespace Packet {
    class SuPacket {
    public:
        static constexpr const char* Header = "su";

        EntityType userEntityType = EntityType::Monster;
        long userEntityID = 0;
        EntityType targetEntityType = EntityType::Monster;
        long targetEntityID = 0;
        int skillVNum = 0;
        int skillCooldown = 0;
        long attackAnimation = 0;
        long skillEffect = 0;
        int xPos = 0;
        int yPos = 0;
        bool targetAlive = false;
        int hpPercentage = 0;
        int damage = 0;
        HitMode hitMode = HitMode::Miss;
        int skillType = 0;
        int hp = 0;
        int maxHP = 0;
    };
}
