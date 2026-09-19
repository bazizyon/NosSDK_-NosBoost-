#pragma once
#include "Color.h"
#include "ImageData.h"
#include "TLBSWidget.h"
#pragma pack(push, 1)

struct TEWControlWidget : TLBSWidget {
    char pad_24[29];        // 0x24 is always 0 and at the end a 3
    Color color;            // 0x41
    uint32_t unknown_45;    // 0x45 gets set to parent left, and top upon construction
    uint32_t unknown_49;    // 0x49 gets set to parent right and bottom upon construction
    uint16_t currentImage;  // 0x4D is always 0
    ImageData imageData;    // 0x4F
    char pad_5d[19];        // 0x5D is always 0 also 0x60 is something like isLoadedFully for NBWidget

    explicit TEWControlWidget(const uintptr_t vTable)
        : TLBSWidget(vTable)
        , color(255, 255, 255, 255)
        , unknown_45(0)
        , unknown_49(0)
        , currentImage(0)
        , imageData{
            1,
            1593835577,
            512,
            512,
            new AtlasFrame[1]{470, 113, 42, 42}}
    {
        std::memset(pad_24, 0, sizeof(pad_24));
        pad_24[sizeof(pad_24) - 1] = 3;
        std::memset(pad_5d, 0, sizeof(pad_5d));
    }

    static constexpr auto ClassName = "TEWControlWidget";
    static constexpr uint32_t ExpectedSize = 0x70;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWControlWidget) == TEWControlWidget::ExpectedSize, "TEWControlWidget size mismatch (see TEWControlWidget::ExpectedSize)");

#pragma pack(pop)