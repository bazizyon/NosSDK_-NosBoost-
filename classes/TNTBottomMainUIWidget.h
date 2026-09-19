#pragma once
#pragma pack(push, 1)
#include "TEWCustomPanelWidget.h"

struct TNTBottomMainUIWidget : TEWCustomPanelWidget {
    char pad0[4];                           // 0x0AC
    TLBSWidget* expGaugeWidget;             // 0x0B0
    TLBSWidget* trayWidget;                 // 0x0B4
    TLBSWidget* settingsWidget;             // 0x0B8
    TLBSWidget* alternateSettingsWidget;    // 0x0BC        is at left bottom idk when its used
    TLBSWidget* nosmallWidget;              // 0x0C0
    TLBSWidget* eventWidget;                // 0x0C4
    TLBSWidget* battlePassWidget;           // 0x0C8
    TLBSWidget* someBackgroundWidget;       // 0x0CC its just a random gray box in the middle of the screen
    TLBSWidget* someListView;               // 0x0D0 no clue
    char pad1[108];                         // 0x0D4
    uint32_t someDword;                     // 0x140
    uint32_t someDword2;                    // 0x144

    static constexpr auto ClassName = "TNTBottomMainUIWidget";
    static constexpr uint32_t ExpectedSize = 0x148;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TNTBottomMainUIWidget) == TNTBottomMainUIWidget::ExpectedSize, "TNTBottomMainUIWidget size mismatch (see TNTBottomMainUIWidget::ExpectedSize)");
#pragma pack(pop)