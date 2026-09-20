#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

struct TEWCustomButtonWidget : TEWCustomPanelWidget {
    char pad_ac[4];                 // 0xAC
    bool pressed;                   // 0xB0
    bool hovered;                   // 0xB1
    char pad_b2[6];                 // 0xB2
    uint32_t callbackFunction;      // 0xB8
    uint32_t callbackArgument;      // 0xBC is loaded to EAX
    uint32_t callback1;             // 0xC0
    uint32_t arguments1;            // 0xC4
    bool unknown_c8;                // 0xC8
    bool unknown_c9;                // 0xC9
    bool unknown_ca;                // 0xCA
    char pad_cb[5];                 // 0xCB
    uint32_t callback2;             // 0xD0
    uint32_t arguments2;            // 0xD4
    uint32_t callback3;             // 0xD8
    uint32_t arguments3;            // 0xDC
    explicit TEWCustomButtonWidget(const uintptr_t vTable)
        : TEWCustomPanelWidget(vTable)
        , pressed(false)
        , hovered(false)
        , callbackFunction(0)
        , callbackArgument(0)
        , callback1(0)
        , arguments1(0)
        , unknown_c8(false)
        , unknown_c9(false)
        , unknown_ca(true)
        , callback2(0)
        , arguments2(0)
        , callback3(0)
        , arguments3(0)
    {
        drawMode = 0;
        memset(pad_ac, 0, sizeof(pad_ac));
        memset(pad_b2, 0, sizeof(pad_b2));
        memset(pad_cb, 0, sizeof(pad_cb));
    }

    static constexpr auto ClassName = "TEWCustomButtonWidget";
    static constexpr uint32_t ExpectedSize = 0xE0;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWCustomButtonWidget) == TEWCustomButtonWidget::ExpectedSize, "TEWCustomButtonWidget size mismatch (see TEWCustomButtonWidget::ExpectedSize)");
#pragma pack(pop)