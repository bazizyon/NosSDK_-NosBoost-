#pragma once
#include <vector>

namespace Packet {
    struct SkiEntry {
        int skillVNUM = 0;
        int level = 0;
    };

    class SkiPacket {
    public:
        static constexpr const char* Header = "ski";

        int unknown0 = 0;
        int primarySkill = 0;
        int secondarySkill = 0;
        std::vector<SkiEntry> skills;
    };
}
