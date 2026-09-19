#pragma once
#include <cstdint>
#pragma pack(push, 1)

struct Color {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t alpha;
    explicit Color(const uint8_t a, const uint8_t r, const uint8_t g, const uint8_t b)
    :   blue(b),
        green(g),
        red(r),
        alpha(a) {}
};
#pragma pack(pop)
