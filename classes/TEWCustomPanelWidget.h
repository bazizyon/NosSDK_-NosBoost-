#pragma once
#include <string>

#include "NineSliceInfo.h"
#include "TEWMoveWidget.h"
#pragma pack(push, 1)

struct TEWCustomPanelWidget : TEWMoveWidget {
    int8_t drawMode;                // 0x88 is like render mode or sum, ctrlwidget sets to 5, graph but sets 4,
                                    // see FUN_004a4858 under TEWCustomPanelWidget
    uint32_t unknown_0x89;          // 0x89
    uint32_t unknown_0x8c;          // 0x8C
    NineSliceInfo nineSliceInfo;    // 0x91
    char unknown_a1[8];             // 0xA1
    char pad_a9;                    // 0xA9
    uint8_t sliceCount;             // 0xAA
    char pad_ab;                    // 0xAB

    explicit TEWCustomPanelWidget(const uintptr_t vTable)
        : TEWMoveWidget(vTable)
        , drawMode(0)
        , unknown_0x89(0xFFF0F0F0)
        , unknown_0x8c(0xFF5F5F5F)
        , nineSliceInfo{0, 0, 0, 0, 0, 0, 0, 0}
        , sliceCount(1)
        , pad_a9(0)
        , pad_ab(0)
    {
        memset(unknown_a1, 0, sizeof(unknown_a1)); // initializes to weird numbers
    }

    static constexpr auto ClassName = "TEWCustomPanelWidget";
    static constexpr uint32_t ExpectedSize = 0xAC;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWCustomPanelWidget) == TEWCustomPanelWidget::ExpectedSize, "TEWCustomPanelWidget size mismatch (see TEWCustomPanelWidget::ExpectedSize)");
#pragma pack(pop)