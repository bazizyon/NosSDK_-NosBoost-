#pragma once
#include "TEWLabels.h"
#pragma pack(push, 1)

struct TEWStringListViewCore : TEWLabels {
    uintptr_t stringList1;              // 0x90
    uintptr_t stringList2;              // 0x94
    uintptr_t stringList3;              // 0x98
    uintptr_t stringList4;              // 0x9C
    uint32_t stringIndex;               // 0xA0
    uint32_t unknown0;                  // 0xA4 ? left lines
    uint32_t unknown1;                  // 0xA8 ? total lines?
    uintptr_t unknown2;                 // 0xAC some list
    uintptr_t unknown3;                 // 0xB0 some list
    uint32_t unknown4;                  // 0xB4

    static constexpr auto ClassName = "TEWStringListViewCore";
    static constexpr uint32_t ExpectedSize = 0xB8;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWStringListViewCore) == TEWStringListViewCore::ExpectedSize, "TEWStringListViewCore size mismatch (see TEWStringListViewCore::ExpectedSize)");
#pragma pack(pop)