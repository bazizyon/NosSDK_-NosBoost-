#pragma once
#include "sub/QuestEntry.h"
#include <vector>

namespace Packet {
    class QstlistPacket {
    public:
        static constexpr const char* Header = "qstlist";

        std::vector<QuestEntry> quests;
    };
}
