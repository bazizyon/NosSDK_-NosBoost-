#pragma once
#pragma pack(push, 1)

struct TMapOptions {
    bool showPlayer;
    bool showPetsOuterRing; // pet marker has an outer ring
    bool unknown1;
    bool showPetsInnerRing; // yes inner ring IDK why?
    bool showShops;
    bool unknown2; // this gets set every frame
    bool showTS;
    bool unknown3;
    bool showOtherPlayers;
    bool showNPC;
    bool showMobs;
    bool showItems;
    char unknowns[6]; // 6 unknowns
};

static_assert(sizeof(TMapOptions) == 0x12, " test");

#pragma pack(pop)