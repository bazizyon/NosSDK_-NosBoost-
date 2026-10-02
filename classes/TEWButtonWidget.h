#pragma once
#include "TEWGraphicButtonWidget.h"
#include "TEWLabel.h"
#pragma pack(push, 1)

struct ButtonTextStyle {
    uint8_t fontStyle;
    uint8_t shadowStyle;
    Color textColor;
    Color shadowColor;
    uint8_t unknown;
};
static_assert(sizeof(ButtonTextStyle) == 11, "ButtonTextStyle size mismatch");

struct TEWButtonWidget : TEWGraphicButtonWidget {
    char unknown_e4[8];             // 0xE4
    ButtonTextStyle styles[3];      // 0xEC
    char pad_10d[3];                // 0x10D
    int16_t textX;                  // 0x110
    int16_t textY;                  // 0x112
    int16_t textWidth;              // 0x114
    int16_t textHeight;             // 0x116
    wchar_t* caption;               // 0x118
    uint32_t unknown_11c;           // 0x11C

    static constexpr int32_t RowImageName = 1593835568;
    static constexpr int16_t RowHeight = 17;

    explicit TEWButtonWidget(const uintptr_t vTable)
        : TEWGraphicButtonWidget(vTable)
        , styles{
            {1, 4, Color(255, 0xB1, 0xF2, 0x04), Color(255, 0, 0, 0), 1},
            {1, 4, Color(255, 255, 255, 255), Color(255, 0, 0, 0), 3},
            {1, 4, Color(255, 255, 255, 255), Color(255, 0, 0, 0), 3},
        }
        , textX(3)
        , textY(1)
        , textWidth(138)
        , textHeight(RowHeight)
        , caption(nullptr)
        , unknown_11c(1)
    {
        std::memset(unknown_e4, 0, sizeof(unknown_e4));
        std::memset(pad_10d, 0, sizeof(pad_10d));
        delete[] imageData.atlasFrames;
        imageData.imageName = RowImageName;
        imageData.imageWidth = 512;
        imageData.imageHeight = 512;
        imageData.frameCount = 9;
        imageData.atlasFrames = new AtlasFrame[9]{
            {269, 272, 9, 17}, {278, 272, 4, 17}, {265, 272, 4, 17},
            {287, 272, 9, 17}, {296, 272, 4, 17}, {283, 272, 4, 17},
            {305, 272, 9, 17}, {314, 272, 4, 17}, {301, 272, 4, 17},
        };
        drawMode = 4;
        sliceCount = 3;
        SetWidth(140);
    }

    void UseHeaderLook() {
        imageData.frameCount = 3;
        sliceCount = 1;
    }

    void SetWidth(const int16_t width) {
        rect.right = static_cast<int16_t>(rect.left + width);
        rect.bottom = static_cast<int16_t>(rect.top + RowHeight);
        const uint16_t middle = static_cast<uint16_t>(width - 8);
        nineSliceInfo = {middle, RowHeight, static_cast<uint16_t>(middle + 4), RowHeight, 4, 0, 4, 0};
        textWidth = static_cast<int16_t>(width - 2);
    }

    void SetCaption(const wchar_t* text) {
        if (!text) return;
        SetWideString(&caption, text);
    }

    static constexpr auto ClassName = "TEWButtonWidget";
    static constexpr uint32_t ExpectedSize = 0x120;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWButtonWidget) == TEWButtonWidget::ExpectedSize, "TEWButtonWidget size mismatch (see TEWButtonWidget::ExpectedSize)");
#pragma pack(pop)
