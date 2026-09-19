#pragma once
#include "TEWControlWidgetEX.h"
#include "TextData.h"
#include "TextStyle.h"
#pragma pack(push, 1)

struct TEWLabels : TEWControlWidgetEX {
    bool transparentBG;             // 0x70
    uint8_t unknown0;               // 0x71
    uint16_t lineCount;             // 0x72
    uint8_t unknown1;               // 0x74
    bool visible;                   // 0x75 when false it doesnt show after update, might be visible
    uint8_t unknown2;               // 0x76
    uint16_t unknown3;              // 0x77
    uint16_t unknown4;              // 0x79
    uint16_t unknown5;              // 0x7B
    uint16_t unknown6;              // 0x7D
    uint8_t alignment;              // 0x7F
    uint32_t unknown7;              // 0x80
    uint16_t maxTextWidthPx;        // 0x84
    uint16_t unknown8;              // 0x86
    TextStyle* textStyles;          // 0x88
    TextData* textDatas;            // 0x8C
    explicit TEWLabels(const uintptr_t vTable)
        : TEWControlWidgetEX(vTable)
        , transparentBG(false)
        , lineCount(1)
        , visible(true)
        , alignment(3)
        , maxTextWidthPx(50)
    {
        unknown0 = 0;
        unknown1 = 0;
        unknown2 = 0;
        unknown3 = 0;
        unknown4 = 0;
        unknown5 = 0;
        unknown6 = 0;
        unknown7 = 0;
        unknown8 = 0;
        textDatas  = new TextData[1]();
        textStyles = new TextStyle[1]();
        rect = Rect(0, 0, 100, 100);

        // Default placeholder text so a freshly created label isn't blank.
        // Mods can overwrite textDatas[0] (or re-allocate more lines and
        // bump lineCount) once they set their own content.
        textDatas[0].SetText(L"TEWLabel");
        textDatas[0].yOffset = 20;
        textDatas[0].pxPerLine = 100;
    }

    static constexpr auto ClassName = "TEWLabels";
    static constexpr uint32_t ExpectedSize = 0x90;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWLabels) == TEWLabels::ExpectedSize, "TEWLabels size mismatch (see TEWLabels::ExpectedSize)");
#pragma pack(pop)