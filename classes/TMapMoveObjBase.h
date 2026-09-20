#pragma once
#include <cstdint>
#include "TMapObjBase.h"
#pragma pack(push, 1)

struct TMapMoveObjBase : TMapObjBase {
    char pad[272];
    static constexpr auto ClassName = "TMapMoveObjBase";
    static constexpr uint32_t ExpectedSize = 0x1B8;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TMapMoveObjBase) == TMapMoveObjBase::ExpectedSize, "TMapMoveObjBase size mismatch (see TMapMoveObjBase::ExpectedSize)");

#pragma pack(pop)
