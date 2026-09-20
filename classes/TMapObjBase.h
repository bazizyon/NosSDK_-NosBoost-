#pragma once
#include <cstdint>
#include "TObject.h"
#pragma pack(push, 1)

struct TMapObjBase : TObject {
    uint8_t objectType;         // 0x04
    char pad_0x05[3];           // 0x05
    uint32_t objectID;          // 0x08
    uint16_t xPosition;         // 0x0C
    uint16_t yPosition;         // 0x0E
    char pad_0x10[152];         // 0x10
    static constexpr auto ClassName = "TMapObjBase";
    static constexpr uint32_t ExpectedSize = 0xA8;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TMapObjBase) == TMapObjBase::ExpectedSize, "TMapObjBase size mismatch (see TMapObjBase::ExpectedSize)");

#pragma pack(pop)
