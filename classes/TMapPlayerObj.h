#pragma once
#include <cstdint>
#include "TMapMoveObjBase.h"
#pragma pack(push, 1)

struct TMapPlayerObj : TMapMoveObjBase {
    char pad[112];
    static constexpr auto ClassName = "TMapPlayerObj";
    static constexpr uint32_t ExpectedSize = 0x228;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TMapPlayerObj) == TMapPlayerObj::ExpectedSize, "TMapPlayerObj size mismatch (see TMapPlayerObj::ExpectedSize)");

#pragma pack(pop)
