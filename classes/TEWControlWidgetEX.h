#pragma once
#include "TEWControlWidget.h"
#pragma pack(push, 1)

struct TEWControlWidgetEX : TEWControlWidget {
    explicit TEWControlWidgetEX(const uintptr_t vTable) : TEWControlWidget(vTable) {}

    static constexpr auto ClassName = "TEWControlWidgetEX";
    static constexpr uint32_t ExpectedSize = 0x70;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWControlWidgetEX) == TEWControlWidgetEX::ExpectedSize, "TEWControlWidgetEX size mismatch (see TEWControlWidgetEX::ExpectedSize)");
#pragma pack(pop)