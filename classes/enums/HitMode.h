#pragma once
#include <stdexcept>

enum class HitMode : int {
    SuccessfulAttack = 0,
    Miss = 1,
    CriticalAttack = 3,
    LongRangeMiss = 4,
    SuccessfulBuff = 5,
    UnknownCriticalAttack = 6,
    UnknownMiss = 7,
    Unknown = -2
};

inline HitMode HitModeFromInt(const int value) {
    switch (value) {
        case 0: return HitMode::SuccessfulAttack;
        case 1: return HitMode::Miss;
        case 3: return HitMode::CriticalAttack;
        case 4: return HitMode::LongRangeMiss;
        case 5: return HitMode::SuccessfulBuff;
        case 6: return HitMode::UnknownCriticalAttack;
        case 7: return HitMode::UnknownMiss;
        case 2:
        case -1:
        case -2: return HitMode::Unknown;
        default: throw std::invalid_argument("Invalid HitMode argument");
    }
}

