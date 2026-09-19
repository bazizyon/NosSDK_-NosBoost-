#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

struct TEWCustomFormWidget : TEWCustomPanelWidget {
    char pad[4];                    // 0xAC TODO: find if this padding is alignment in here or in custom panel widget
    TLBSWidget* captionBar;         // 0xB0
    bool isBeingResize;             // 0xB4
    uint8_t resizeMode;             // 0xB5 TODO: ENUM
    uint8_t cornerSize;             // 0xB6
    uint16_t dragClickX;            // 0xB7
    uint16_t dragClickY;            // 0xB9
    uint16_t widthMinusDragClickX;  // 0xBB I guess this exists to make scaling logic easier?
    uint16_t heightMinusDragClickY; // 0xBD
    char pad2;                      // 0xBF
    TLBSWidget* freakyPointer;      // 0xC0 If you set this to non-zero it breaks itself , if it points to a widget it breaks the widget

    static constexpr auto ClassName = "TEWCustomFormWidget";
    static constexpr uint32_t ExpectedSize = 0xC4;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWCustomFormWidget) == TEWCustomFormWidget::ExpectedSize, "TEWCustomFormWidget size mismatch (see TEWCustomFormWidget::ExpectedSize)");
#pragma pack(pop)