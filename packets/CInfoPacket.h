#pragma once
#include <string>
#include "PlayerClass.h"

namespace Packet {
    class CInfoPacket {
    public:
        static constexpr const char* Header = "c_info";

        std::string name;
        std::string temp0;
        int groupId = 0;
        int familyId = 0;
        std::string familyName;
        long characterID = 0;
        int authority = 0;
        int sex = 0;
        int hairStyle = 0;
        int hairColor = 0;
        PlayerClass characterClass = PlayerClass::Adventurer;
        int icon = 0;
        int compliment = 0;
        long morphVNum = 0;
        bool invisible = false;
        int familyLevel = 0;
        int morphUpgrade = 0;
        bool arenaWinner = false;
    };
}
