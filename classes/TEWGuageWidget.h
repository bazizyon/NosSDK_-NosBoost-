#pragma once
#include "TEWMoveWidget.h"
#pragma pack(push, 1)

struct TEWGuageWidget : TEWMoveWidget {
    Color gaugeColor;       // 0x88
    char pad_0x8C[8];       // 0x8C scratch var: divider and dividee
    float fillPercent;  // 0x94 0-1 not 0-100
    char pad_0x98[44];      // all zeroes and useless values somehow
    explicit TEWGuageWidget(const uintptr_t vTable)
        : TEWMoveWidget(vTable)
        , gaugeColor(255, 255, 255, 255)
        , fillPercent(1.0f)
    {
        memset(pad_0x8C, 0, sizeof(pad_0x8C));
        memset(pad_0x98, 0, sizeof(pad_0x98));
    }

    static constexpr auto ClassName = "TEWGuageWidget";
    static constexpr uint32_t ExpectedSize = 0xC4;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWGuageWidget) == TEWGuageWidget::ExpectedSize, "TEWGuageWidget size mismatch (see TEWGuageWidget::ExpectedSize)");
#pragma pack(pop)