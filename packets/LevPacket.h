#pragma once
#include "Packet.h"
#include <cstdint>
#include <string>

namespace Packet {
    class LevPacket {
    public:
        static constexpr const char* Header = "lev";

        uint8_t battleLevel = 0;
        long battleLevelXP = 0;

        uint8_t jobLevel = 0;
        long jobLevelXP = 0;

        long battleLevelXPMax = 0;
        long jobLevelXPMax = 0;

        long reputation = 0;
        uint8_t skillCP = 0;

        long heroLevelXP = 0;
        uint8_t heroLevel = 0;
        long heroLevelXPMax = 0;
        uint8_t unknown = 0;
    };
}
