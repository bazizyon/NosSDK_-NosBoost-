#pragma once
#include "PlayerClass.h"

namespace Packet {
    class InPlayerSubPacket {
    public:
        int sex = 0;
        PlayerClass playerClass = PlayerClass::Adventurer;
        long morphVNum = 0;
    };
}
