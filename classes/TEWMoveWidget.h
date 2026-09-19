#pragma once
#include "TEWControlWidgetEvent.h"
#pragma pack(push, 1)

struct TEWMoveWidget : TEWControlWidgetEvent {
    bool isBeingDragged;       // 0x78
    uint16_t clickPositionX;   // 0x79
    uint16_t clickPositionY;   // 0x7B
    bool isMoveable;           // 0x7D
    bool isRestrictedToScreen; // 0x7E
    char pad_7f;               // 0x7F
    int16_t leftMargin;        // 0x80
    int16_t topMargin;         // 0x82
    int16_t rightMargin;       // 0x84
    int16_t bottomMargin;      // 0x86

    explicit TEWMoveWidget(const uintptr_t vTable)
        : TEWControlWidgetEvent(vTable)
        , isBeingDragged(false)
        , clickPositionX(0)
        , clickPositionY(0)
        , isMoveable(false)
        , isRestrictedToScreen(false)
        , pad_7f(0)
        , leftMargin(0)
        , topMargin(0)
        , rightMargin(0)
        , bottomMargin(0) {}

    static constexpr auto ClassName = "TEWMoveWidget";
    static constexpr uint32_t ExpectedSize = 0x88;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWMoveWidget) == TEWMoveWidget::ExpectedSize, "TEWMoveWidget size mismatch (see TEWMoveWidget::ExpectedSize)");
#pragma pack(pop)