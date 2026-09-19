#pragma once
#include <cstdint>
#pragma pack(push, 1)

typedef uintptr_t ItemInfo;
struct NosBazaarListing {
    ItemInfo* itemInfo; // 0x00
    uint32_t weirdBit; // 0x08  1 for main 2 for consume items 0 for everything else, makes item price not be written to 0x0C
    uint32_t itemPriceReadOnce; // 0x0C read once, changing does not affect what is rendered.
};

static_assert(sizeof(NosBazaarListing)== 0x28, "Item does not have a size of 0x28.");
#pragma pack(pop)