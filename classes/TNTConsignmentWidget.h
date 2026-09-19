#pragma once
#include "NBTab.h"
#include "TEWCustomFormWidget.h"
#include "TNTIconWidget.h"
#include <vector>

#include "TEWLabel.h"
#pragma pack(push, 1)

// NosBazaar Widget
struct TNTConsignmentWidget : TEWCustomFormWidget {
    char alignmentPadding[4];                   // 0x0C4 TODO: decide if this padding should go to custom form widget
    TLBSWidget* buyTab;                         // 0x0C8
    TLBSWidget* listTab;                        // 0x0CC
    TLBSWidget* administrationTab;              // 0x0D0
    NBTab currentTab;                           // 0x0D4
    TLBSWidget* buyTabButton;                   // 0x0D8
    TLBSWidget* listTabButton;                  // 0x0DC
    TLBSWidget* administrationTabButton;        // 0x0E0
    TLBSWidget* buyTabButtonText;               // 0x0E4 TEWLabel
    TLBSWidget* listTabButtonText;              // 0x0E8
    TLBSWidget* administrationTabButtonText;    // 0x0EC
    char pad1[8];                               // 0x0F0
    uint32_t goldAmount;                        // 0x0F8
    TLBSWidget* goldText;                       // 0x0FC
    TLBSWidget* noItemFoundText;                // 0x100
    uint16_t categoryFilter;                    // 0x104
    uint16_t secondaryFilter;                   // 0x106
    uint16_t levelFilter;                       // 0x108
    uint16_t rarityFilter;                      // 0x10A
    uint16_t upgradeFilter;                     // 0x10C
    uint16_t sortFilter;                        // 0x10E
    char pad2[12];                              // 0x110 ///------------------//////// 4
    TLBSWidget* categoryArrowButton;            // 0x11C There's just a bunch of arrow buttons that are useless so im not listing them
    char pad3[556];                             // 0x120
    TLBSWidget* nameInputText;                  // 0x34C
    TLBSWidget* nameInputBox;                   // 0x350 Again a bunch of buttons, ui doesn't concern me so im skippin.
    char pad4[32];                              // 0x354 //----------------/////////// 4
    uint32_t threeBaseTimer;                    // 0x374 It goes 0 -> 1 -> 2 -> 0
    uint32_t currentTime;                       // 0x378 in miliseconds since game start
    uint32_t lastEnableTime;                    // 0x37C last time button was enabled for click, not when last clicked
    bool isSearchDisabled;                      // 0x380
    bool isLoading;                             // 0x381 loading search
    char pad5[2];                               // 0x382
    TLBSWidget* searchingLabel;                 // 0x384
    uint32_t lastSearchTime;                    // 0x388
    char pad6[96];                              // 0x38C
    // what's in this pad: search failed label, buy buttons & text, highlight rect, item icon buttons
    TNTIconWidget* iconWidget1;
    TNTIconWidget* iconWidget2;
    TNTIconWidget* iconWidget3;
    TNTIconWidget* iconWidget4;
    TNTIconWidget* iconWidget5;
    TNTIconWidget* iconWidget6;
    TNTIconWidget* iconWidget7;
    TNTIconWidget* iconWidget8;
    TNTIconWidget* iconWidget9;
    TNTIconWidget* iconWidget10;
    uintptr_t shownItemsList;                   // 0x414 TODO: TNTItemList
    TEWCustomPanelWidget* resultBar1;           // 0x418
    TEWCustomPanelWidget* resultBar2;           // 0x41C
    TEWCustomPanelWidget* resultBar3;           // 0x420
    TEWCustomPanelWidget* resultBar4;           // 0x424
    TEWCustomPanelWidget* resultBar5;           // 0x42C
    TEWCustomPanelWidget* resultBar6;           // 0x430
    TEWCustomPanelWidget* resultBar7;           // 0x434
    TEWCustomPanelWidget* resultBar8;           // 0x438
    TEWCustomPanelWidget* resultBar9;           // 0x43C
    TEWCustomPanelWidget* resultBar10;          // 0x440
    uintptr_t resultItemList;                   // 0x444 this is all 30 while shown items is only 10
    uintptr_t unknownList;                      // 0x44C
    char pad7[60];                              // 0x448
    // what's in this pad: bundle hint icons, column labels, column list views FIXME: not only this pad
    TLBSWidget* itemNameColumn;                 // 0x484
    TLBSWidget* amountColumn;                   // 0x488
    TLBSWidget* pricePerUnitColumn;             // 0x48C
    TLBSWidget* timePeriodColumn;               // 0x490
    TLBSWidget* sellerColumn;                   // 0x494
    char pad7_2[4];                             // 0x498
    TLBSWidget* prevPageGroupButton;            // 0x49C
    TLBSWidget* prevPageButton;                 // 0x4A0
    uint32_t currentPage;                       // 0x4A4
    TLBSWidget* nextPageButton;                 // 0x4A8
    TLBSWidget* nextPageGroupButton;            // 0x4AC
    TLBSWidget* firstPageButton;                // 0x4B0
    TLBSWidget* secondPageButton;               // 0x4B4
    TLBSWidget* thirdPageButton;                // 0x4B8
    uint32_t anotherCurrentPage;                // 0x4BC this one is weird use 0x49C
    uint32_t currentPageGroup;                  // 0x4C0 0 when page 1,2,3. 1 when page 4,5,6. 5 when page 16,17,18.
    char pad[760];                              // 0x4C4

    [[nodiscard]] TEWCustomPanelWidget* GetResultBar(const int i) const {
        const auto* base = &resultBar1;
        return i >= 0 && i < 10 ? base[i] : nullptr;
    }

    [[nodiscard]] TNTIconWidget* GetIconWidget(const int i) const {
        const auto* base = &iconWidget1;
        return i >= 0 && i < 10 ? base[i] : nullptr;
    }

    static constexpr auto ClassName = "TNTConsignmentWidget";
    static constexpr uint32_t ExpectedSize = 0x7BC;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TNTConsignmentWidget) == TNTConsignmentWidget::ExpectedSize, "TNTConsignmentWidget size mismatch (see TNTConsignmentWidget::ExpectedSize)");
#pragma pack(pop)