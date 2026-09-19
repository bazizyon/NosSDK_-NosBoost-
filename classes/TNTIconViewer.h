#pragma once
#include "TEWControlWidgetEX.h"
#pragma pack(push, 1)

struct TNTIconViewer : TEWControlWidgetEX {
    uint8_t morphType;          // 0x70 1 for specialist, 3 for mob, 4 for item
    bool transparentBG;         // 0x71
    char unknown0[2];           // 0x72
    float size;                 // 0x74
    bool verticallyAligned;     // 0x78 it aligns vertically but weird
    bool animated;              // 0x79
    char unknown1[1];           // 0x7A
    uint8_t morphAction;        // 0x7B sitting, sleeping, etc, for sp's, 8 is for running
    uint16_t morphVNUM;         // 0x7C
    char pad[44];               // 0x7E
    char unknown3[6];           // 0xAA
    uint16_t unknown;           // 0xB0
    uint8_t spGender;           // 0xB2 0 for female 128 for male
    uint8_t spIndex;            // 0xB3 its values for sp 11 for bers 12 for sader etc.
    uint8_t unknown4;           // 0xB4
    uint8_t unknown5;           // 0xB5
    uint16_t unknown6;          // 0xB6
    explicit TNTIconViewer(const uintptr_t vTable)
        : TEWControlWidgetEX(vTable)
        , morphType(1)
        , transparentBG(true)
        , size(1.0f)
        , animated(true)
        , verticallyAligned(false)
        , morphAction(0)
        , morphVNUM(11)
        , spGender(0)
        , spIndex(11)
    {
        std::memset(unknown0, 0, sizeof(unknown0));
        std::memset(unknown1, 0, sizeof(unknown1));
        std::memset(pad, 0, sizeof(pad));
        std::memset(unknown3, 0, sizeof(unknown3));

        unknown = 0;
        unknown4 = 0;
        unknown5 = 0;
        unknown6 = 0;
    }

    static constexpr auto ClassName = "TNTIconViewer";
    static constexpr uint32_t ExpectedSize = 0xB8;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TNTIconViewer) == TNTIconViewer::ExpectedSize, "TNTIconViewer size mismatch (see TNTIconViewer::ExpectedSize)");

#pragma pack(pop)
