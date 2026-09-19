#pragma once
#include <cstdint>
enum class Cursor : int8_t {
    Windows = 0x00,
    Nostale = 0x01,
    Blocked = 0x02,
    Pickable = 0x03,
    Picking = 0x04,
    Finger = 0x05,
    Dialog = 0x06,
    AttackSword = 0x07,
    ExpandArrows = 0x08,
    NosmateFight = 0x09,
    NosmateMove = 0x0A
};