#pragma once
#include <stdexcept>

enum class EntityType : int {
    Map = 0,
    Player = 1,
    NPC = 2,  // mates and shit included
    Monster = 3,
    Object = 9
};

inline EntityType EntityTypeFromInt(const int value) {
    switch (value) {
        case 0: return EntityType::Map;
        case 1: return EntityType::Player;
        case 2: return EntityType::NPC;
        case 3: return EntityType::Monster;
        case 9: return EntityType::Object;
        default: throw std::invalid_argument("Invalid EntityType argument");
    }
}