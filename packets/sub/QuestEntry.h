#pragma once

namespace Packet {
    struct QuestObjective {
        int current = 0;
        int target = 0;
    };

    struct QuestEntry {
        int slot = 0;
        int questId = 0;
        int questId2 = 0;
        int questType = 0;
        QuestObjective objectives[5];
        bool finished = false;
        int unknownLast = 0;

        bool IsObjectiveMet() const {
            return finished;
        }
    };
}
