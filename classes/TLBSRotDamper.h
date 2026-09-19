#pragma once
#pragma pack(push, 1)
#include "TObject.h"

struct TLBSRotDamper : TObject{
    char pad_0004[84]; //0x04
    float min; //0x58
    float max; //0x5C
    float def; //0x60

    static constexpr auto ClassName = "TLBSRotDamper";
    static constexpr uint32_t ExpectedSize = 0x64;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TLBSRotDamper) == TLBSRotDamper::ExpectedSize, "TLBSRotDamper size mismatch (see TLBSRotDamper::ExpectedSize)");

#pragma pack(pop)