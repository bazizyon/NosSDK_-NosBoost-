#pragma once
#include "TEWControlWidget.h"
#include "TEWCustomButtonWidget.h"
#pragma pack(push, 1)

struct TEWGraphicButtonWidget : TEWCustomButtonWidget {
    char unknown_e0[4];        // 0xE0
    explicit TEWGraphicButtonWidget(const uintptr_t vTable)
        : TEWCustomButtonWidget(vTable)
    {
        memset(unknown_e0, 0, sizeof(unknown_e0));
    }

    static constexpr auto ClassName = "TEWGraphicButtonWidget";
    static constexpr uint32_t ExpectedSize = 0xE4;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWGraphicButtonWidget) == TEWGraphicButtonWidget::ExpectedSize, "TEWGraphicButtonWidget size mismatch (see TEWGraphicButtonWidget::ExpectedSize)");
#pragma pack(pop)
