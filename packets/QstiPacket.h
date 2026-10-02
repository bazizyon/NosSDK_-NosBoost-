#pragma once
#include "sub/QuestEntry.h"

namespace Packet {
    class QstiPacket {
    public:
        static constexpr const char* Header = "qsti";

        QuestEntry quest;
    };
}
