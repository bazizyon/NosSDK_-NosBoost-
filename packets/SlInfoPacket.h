#pragma once
#include <string>
#include <vector>

namespace Packet {
    class SlInfoPacket {
    public:
        static constexpr const char* Header = "slinfo";

        int type = 0;
        int itemVNUM = 0;
        int morph = 0;
        int level = 0;
        int requiredJobLevel = 0;
        int requiredReputation = 0;
        int spType = 0;
        int fireResistance = 0;
        int waterResistance = 0;
        int lightResistance = 0;
        int shadowResistance = 0;
        long long xp = 0;
        long long xpMax = 0;
        std::vector<int> skills;
        long transportID = 0;
        int freePoints = 0;
        int attackPoints = 0;
        int defencePoints = 0;
        int elementPoints = 0;
        int hpmpPoints = 0;
        int upgradeLevel = 0;
        int attackBonus = 0;        // added by your gear, not part of the card
        int defenceBonus = 0;
        int elementBonus = 0;
        int hpmpBonus = 0;
        int perfectionCount = 0;
        int attackPerf = 0;
        int defencePerf = 0;
        int elementPerf = 0;
        int hpmpPerf = 0;
        int fireResPerf = 0;
        int waterResPerf = 0;
        int lightResPerf = 0;
        int shadowResPerf = 0;
        std::vector<std::string> fields;
    };
}
