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
    char pad2[8];                               // 0x110 ///------------------//////// 4
    TLBSWidget* categoryArrowButton;            // 0x118 There's just a bunch of arrow buttons that are useless so im not listing them
    char pad3[572];                             // 0x11C
    TEWEditWidget* nameInputText;               // 0x358
    TLBSWidget* nameInputBox;                   // 0x35C Again a bunch of buttons, ui doesn't concern me so im skippin.
    char pad4[32];                              // 0x360 //----------------/////////// 4
    uint32_t currentTime;                       // 0x380 in miliseconds since game start
    uint32_t lastEnableTime;                    // 0x384 last time button was enabled for click, not when last clicked
    bool isSearchDisabled;                      // 0x388
    bool isLoading;                             // 0x389 loading search
    char pad5[2];                               // 0x38A
    TLBSWidget* searchingLabel;                 // 0x38C
    uint32_t lastSearchTime;                    // 0x390
    char pad6[8];                               // 0x394
    TEWGraphicButtonWidget* buyButtons[10];     // 0x39C
    TEWLabel* buyButtonLabels[10];              // 0x3C4
    char padd[8];                               // 0x3EC
    TNTIconWidget* iconWidget1;                 // 0x3F4
    TNTIconWidget* iconWidget2;
    TNTIconWidget* iconWidget3;
    TNTIconWidget* iconWidget4;
    TNTIconWidget* iconWidget5;
    TNTIconWidget* iconWidget6;
    TNTIconWidget* iconWidget7;
    TNTIconWidget* iconWidget8;
    TNTIconWidget* iconWidget9;
    TNTIconWidget* iconWidget10;                // 0x418
    uintptr_t shownItemsList;                   // 0x41C TODO: TNTItemList
    TEWCustomPanelWidget* resultBar1;           // 0x420
    TEWCustomPanelWidget* resultBar2;           // 0x424
    TEWCustomPanelWidget* resultBar3;           // 0x428
    TEWCustomPanelWidget* resultBar4;           // 0x42C
    TEWCustomPanelWidget* resultBar5;           // 0x430
    TEWCustomPanelWidget* resultBar6;           // 0x434
    TEWCustomPanelWidget* resultBar7;           // 0x438
    TEWCustomPanelWidget* resultBar8;           // 0x43C
    TEWCustomPanelWidget* resultBar9;           // 0x440
    TEWCustomPanelWidget* resultBar10;          // 0x444
    uintptr_t resultItemList;                   // 0x448 this is all 30 while shown items is only 10
    uintptr_t unknownList;                      // 0x44C
    TLBSWidget* bundleHintButtons[10];          // 0x450
    TEWLabel* columnHeaders[5];                 // 0x478
    TEWStringListViewCore* itemNameColumn;      // 0x48C
    TEWStringListViewCore* amountColumn;        // 0x490
    TEWStringListViewCore* pricePerUnitColumn;  // 0x494
    TEWStringListViewCore* timePeriodColumn;    // 0x498
    TEWStringListViewCore* sellerColumn;        // 0x49C
    char pad7_2[4];                             // 0x4A0
    TLBSWidget* prevPageGroupButton;            // 0x4A4
    TLBSWidget* prevPageButton;                 // 0x4A8
    uint32_t currentPage;                       // 0x4AC
    TLBSWidget* nextPageButton;                 // 0x4B0
    TLBSWidget* nextPageGroupButton;            // 0x4B4
    TLBSWidget* firstPageButton;                // 0x4B8
    TLBSWidget* secondPageButton;               // 0x4BC
    TLBSWidget* thirdPageButton;                // 0x4C0
    uint32_t anotherCurrentPage;                // 0x4C4
    uint32_t currentPageGroup;                  // 0x4C8 0 when page 1,2,3. 1 when page 4,5,6. 5 when page 16,17,18.
    char pad[760];                              // 0x4CC
    [[nodiscard]] TEWCustomPanelWidget* GetResultBar(const int i) const {
        const auto* base = &resultBar1;
        return i >= 0 && i < 10 ? base[i] : nullptr;
    }

    [[nodiscard]] TNTIconWidget* GetIconWidget(const int i) const {
        const auto* base = &iconWidget1;
        return i >= 0 && i < 10 ? base[i] : nullptr;
    }

    static constexpr auto ClassName = "TNTConsignmentWidget";
    static constexpr uint32_t ExpectedSize = 0x7C4;
    static constexpr uint32_t Version = 2;
};

static_assert(sizeof(TNTConsignmentWidget) == TNTConsignmentWidget::ExpectedSize, "TNTConsignmentWidget size mismatch (see TNTConsignmentWidget::ExpectedSize)");
#pragma pack(pop)