#pragma once
#include "TLBSRotDamper.h"

#pragma pack(push, 1)

struct TLBSCamera : TObject {
    char pad_0004[736]; //0x0004
    uint32_t TLBSPosDamperPtr; //0x02E4
    TLBSRotDamper* HorizontalRotDamper; //0x02E8
    TLBSRotDamper* VerticalRotDamper; //0x02EC
    TLBSRotDamper* ZoomRotDamper; //0x02F0
    char pad_02F4[4]; //0x02F4

    static constexpr auto ClassName = "TLBSCamera";
    static constexpr uint32_t ExpectedSize = 0x2F8;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TLBSCamera) == TLBSCamera::ExpectedSize, "TLBSCamera size mismatch (see TLBSCamera::ExpectedSize)");

#pragma pack(pop)