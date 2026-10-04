#pragma once
#include "TNTIconWidget.h"
#pragma pack(push, 1)

struct TNTTimeAniIcon : TNTIconWidget {
    char pad_D4[0x30];          // 0xD4
    uint32_t overlayColor;      // 0x104
    uintptr_t textLabel;        // 0x108
    uint32_t elapsedMs;         // 0x10C
    uint32_t unknown_110;       // 0x110
    uint32_t cooldownMs;        // 0x114
    uint32_t startTick;         // 0x118
    uint32_t flags;             // 0x11C
    uint32_t unknown_120;       // 0x120

    explicit TNTTimeAniIcon(const uintptr_t vTable)
        : TNTIconWidget(vTable)
        , pad_D4{}
        , overlayColor(0)
        , textLabel(0)
        , elapsedMs(0)
        , unknown_110(0)
        , cooldownMs(0)
        , startTick(0)
        , flags(0)
        , unknown_120(0)
    {
    }

    static constexpr auto ClassName = "TNTTimeAniIcon";
    static constexpr uint32_t ExpectedSize = 0x124;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TNTTimeAniIcon) == TNTTimeAniIcon::ExpectedSize, "TNTTimeAniIcon size mismatch (see TNTTimeAniIcon::ExpectedSize)");

#pragma pack(pop)
