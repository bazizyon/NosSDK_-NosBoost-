#pragma once

namespace Packet {
    class RaidMbfPacket {
    public:
        static constexpr const char* Header = "raidmbf";

        int monsterTotal = 0;
        int monstersLeft = 0;
        int leverTotal = 0;
        int leversLeft = 0;
        int lives = 0;
        int maxLives = 0;
    };
}
