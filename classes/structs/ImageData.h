#pragma once
#include <cstdint>
#include "AtlasFrame.h"
#pragma pack(push, 1)

struct ImageData {
    int16_t frameCount;
    int32_t imageName;
    int16_t imageWidth;
    int16_t imageHeight;
    AtlasFrame* atlasFrames;
};
#pragma pack(pop)
