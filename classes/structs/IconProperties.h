#pragma once
#pragma pack(push, 1)
#include <cstdint>

struct IconProperties {
    int32_t unknown0;                   // 0x00
    int32_t unknown1;                   // 0x04
    uintptr_t itemProperties = 0x0;     // 0x08
    int16_t imageID;                    // 0x0C
    int16_t unknown2 = 0;               // 0x0E
    int8_t type = 0;                    // 0x10 0 or 3 for no text;
    // 0x20 is count 2bytes
};
#pragma pack(pop)
