#pragma once
#include <cstdint>
#pragma pack(push, 1)
struct TextStyle  {
    uint8_t font;
    uint8_t shadowOrientation;
    uint32_t textColor;
    uint32_t shadowColor;
    uint8_t textAlignment;

    TextStyle()
        : font(1)
        , shadowOrientation(0)
        , textColor(0xFFFFFFFF)
        , shadowColor(0xFFFFFFFF)
        , textAlignment(3)
    {}
};
#pragma pack(pop)
