#pragma once
#include <cstdint>
#include "MapGrid.h"
#include "TLBSCamera.h"
#pragma pack(push, 1)

struct TSceneManager : TObject {
    uint32_t playerListPtr;     // 0x04
    uint32_t monsterListPtr;    // 0x08
    uint32_t npcListPtr;        // 0x0C
    uint32_t itemListPtr;       // 0x10
    uint32_t unknownPtr1;       // 0x14
    uint32_t unknownPtr2;       // 0x18
    uint32_t unknownPtr3;       // 0x1C
    MapGrid* mapGrid;           // 0x20
    uint32_t totalFrameCount;   // 0x24
    bool isPlayerLoaded;        // 0x28
    char pad_0025[3];           // 0x29
    int32_t playerID;           // 0x2C
    uint32_t mapPlayerObjPtr;   // 0x30
    char pad_0034[32];          // 0x34
    int16_t targetSkillX;       // 0x54
    int16_t targetSkillY;       // 0x56
    char pad_0058[20];          // 0x58
    TLBSCamera* camera;         // 0x6C
    char pad_0070[48];          // 0x70

    static constexpr auto ClassName = "TSceneManager";
    static constexpr uint32_t ExpectedSize = 0xA0;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TSceneManager) == TSceneManager::ExpectedSize, "TSceneManager size mismatch (see TSceneManager::ExpectedSize)");

#pragma pack(pop)
