#pragma once
#include <cstdint>
#pragma pack(push, 1)

struct AtlasFrame {
    int16_t topLeftX;
    int16_t topLeftY;
    int16_t width;
    int16_t height;
};
#pragma pack(pop)
