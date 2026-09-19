#pragma once
#include <stdexcept>

enum class PlayerClass : int {
    Adventurer = 0,
    Swordsman = 1,
    Archer = 2,
    Mage = 3,
    MartialArtist = 4
};

inline PlayerClass PlayerClassFromInt(const int value) {
    switch (value) {
        case 0: return PlayerClass::Adventurer;
        case 1: return PlayerClass::Swordsman;
        case 2: return PlayerClass::Archer;
        case 3: return PlayerClass::Mage;
        case 4: return PlayerClass::MartialArtist;
        default: throw std::invalid_argument("Invalid PlayerClass argument");
    }
}
