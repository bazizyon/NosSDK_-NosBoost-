#pragma once
#include "NBTab.h"
#include "TEWCustomFormWidget.h"
#include "TEWEditWidget.h"
#include "TEWGraphicButtonWidget.h"
#include "TEWStringListViewCore.h"
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
    char pad3[572];                             // 0x120
    TEWEditWidget* nameInputText;               // 0x35C
    TLBSWidget* nameInputBox;                   // 0x360 Again a bunch of buttons, ui doesn't concern me so im skippin.
    char pad4[32];                              // 0x364 //----------------/////////// 4
    uint32_t threeBaseTimer;                    // 0x384 It goes 0 -> 1 -> 2 -> 0
    uint32_t currentTime;                       // 0x388 in miliseconds since game start
    uint32_t lastEnableTime;                    // 0x38C last time button was enabled for click, not when last clicked
    bool isSearchDisabled;                      // 0x390
    bool isLoading;                             // 0x391 loading search
    char pad5[2];                               // 0x392
    TLBSWidget* searchingLabel;                 // 0x394
    uint32_t lastSearchTime;                    // 0x398
    char pad6[8];                               // 0x39C
    TEWGraphicButtonWidget* buyButtons[10];     // 0x3A4
    TEWLabel* buyButtonLabels[10];              // 0x3CC
    char padd[8];                               // 0x3F4
    TNTIconWidget* iconWidget1;                 // 0x3FC
    TNTIconWidget* iconWidget2;
    TNTIconWidget* iconWidget3;
    TNTIconWidget* iconWidget4;
    TNTIconWidget* iconWidget5;
    TNTIconWidget* iconWidget6;
    TNTIconWidget* iconWidget7;
    TNTIconWidget* iconWidget8;
    TNTIconWidget* iconWidget9;
    TNTIconWidget* iconWidget10;                // 0x420
    uintptr_t shownItemsList;                   // 0x424 TODO: TNTItemList
    TEWCustomPanelWidget* resultBar1;           // 0x428
    TEWCustomPanelWidget* resultBar2;           // 0x42C
    TEWCustomPanelWidget* resultBar3;           // 0x430
    TEWCustomPanelWidget* resultBar4;           // 0x434
    TEWCustomPanelWidget* resultBar5;           // 0x438
    TEWCustomPanelWidget* resultBar6;           // 0x43C
    TEWCustomPanelWidget* resultBar7;           // 0x440
    TEWCustomPanelWidget* resultBar8;           // 0x444
    TEWCustomPanelWidget* resultBar9;           // 0x448
    TEWCustomPanelWidget* resultBar10;          // 0x44C
    uintptr_t resultItemList;                   // 0x450 this is all 30 while shown items is only 10
    uintptr_t unknownList;                      // 0x454
    TLBSWidget* bundleHintButtons[10];          // 0x458
    TEWLabel* columnHeaders[5];                 // 0x480
    TEWStringListViewCore* itemNameColumn;      // 0x494
    TEWStringListViewCore* amountColumn;        // 0x498
    TEWStringListViewCore* pricePerUnitColumn;  // 0x49C
    TEWStringListViewCore* timePeriodColumn;    // 0x4A0
    TEWStringListViewCore* sellerColumn;        // 0x4A4
    char pad7_2[4];                             // 0x4A8
    TLBSWidget* prevPageGroupButton;            // 0x4AC
    TLBSWidget* prevPageButton;                 // 0x4B0
    uint32_t currentPage;                       // 0x4B4
    TLBSWidget* nextPageButton;                 // 0x4B8
    TLBSWidget* nextPageGroupButton;            // 0x4BC
    TLBSWidget* firstPageButton;                // 0x4C0
    TLBSWidget* secondPageButton;               // 0x4C4
    TLBSWidget* thirdPageButton;                // 0x4C8
    uint32_t anotherCurrentPage;                // 0x4CC
    uint32_t currentPageGroup;                  // 0x4D0 0 when page 1,2,3. 1 when page 4,5,6. 5 when page 16,17,18.
    char pad[760];                              // 0x4D4
    [[nodiscard]] TEWCustomPanelWidget* GetResultBar(const int i) const {
        const auto* base = &resultBar1;
        return i >= 0 && i < 10 ? base[i] : nullptr;
    }

    [[nodiscard]] TNTIconWidget* GetIconWidget(const int i) const {
        const auto* base = &iconWidget1;
        return i >= 0 && i < 10 ? base[i] : nullptr;
    }

    static constexpr auto ClassName = "TNTConsignmentWidget";
    static constexpr uint32_t ExpectedSize = 0x7CC;
    static constexpr uint32_t Version = 2;
};

static_assert(sizeof(TNTConsignmentWidget) == TNTConsignmentWidget::ExpectedSize, "TNTConsignmentWidget size mismatch (see TNTConsignmentWidget::ExpectedSize)");
#pragma pack(pop)