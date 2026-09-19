#pragma once
#include "IconProperties.h"
#include "TEWControlWidgetEvent.h"
#pragma pack(push, 1)

struct TNTIconWidget : TEWControlWidgetEvent {
    bool showEdgesInBlue;           // 0x78
    char unknown0[15];              // 0x79
    int16_t clickX;                 // 0x88
    int16_t clickY;                 // 0x8A
    bool keepTransparency;          // 0x8C
    bool resized;                   // 0x8D
    char unknown1[26];              // 0x8E callback here
    int8_t imageIf;                 // 0xA8
    bool showEdgesInOrange;         // 0xA9
    char unknown2;                  // 0xAA
    bool animate;                   // 0xAB
    char unknown3[4];               // 0xAC
    IconProperties* image;          // 0xB0
    char unknown4[4];               // 0xB4
    int16_t slot;                   // 0xB8
    char unknown5[26];              // 0xBA

    explicit TNTIconWidget(const uintptr_t vTable)
        : TEWControlWidgetEvent(vTable)
        , showEdgesInBlue(false)
        , unknown0{}
        , clickX(0)
        , clickY(0)
        , keepTransparency(true)
        , resized(true)
        , unknown1{}
        , imageIf(4)
        , showEdgesInOrange(false)
        , unknown2(0)
        , animate(false)
        , unknown3{}
        , image(new IconProperties())
        , unknown4{}
        , slot(0)
        , unknown5{}
    {

    }

    static constexpr auto ClassName = "TNTIconWidget";
    static constexpr uint32_t ExpectedSize = 0xD4;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TNTIconWidget) == TNTIconWidget::ExpectedSize, "TNTIconWidget size mismatch (see TNTIconWidget::ExpectedSize)");

#pragma pack(pop)