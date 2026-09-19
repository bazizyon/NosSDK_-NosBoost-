#pragma once
#include "TEWControlWidget.h"
#pragma pack(push, 1)

struct TEWControlWidgetEvent : TEWControlWidget {
    uintptr_t unknownVoid;        // is a callback for catacombs list widget
    uintptr_t unknownArgs;        // points to itself sometimes but why?

    explicit TEWControlWidgetEvent(const uintptr_t vTable)
        : TEWControlWidget(vTable)
        , unknownVoid(0)
        , unknownArgs(0) {}

    static constexpr auto ClassName = "TEWControlWidgetEvent";
    static constexpr uint32_t ExpectedSize = 0x78;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWControlWidgetEvent) == TEWControlWidgetEvent::ExpectedSize, "TEWControlWidgetEvent size mismatch (see TEWControlWidgetEvent::ExpectedSize)");
#pragma pack(pop)