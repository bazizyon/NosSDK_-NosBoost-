#pragma once
#include <cstdint>

#include "TEWLabel.h"
#pragma pack(push, 1)
struct TextData  {
    uint16_t xOffset;
    uint16_t yOffset;
    uint16_t pxPerLine;         // ?
    uint16_t lineSpacing;
    wchar_t* text;
    bool isVisible;
    char pad[3];

    TextData()
        : xOffset(0)
        , yOffset(0)
        , pxPerLine(0)
        , lineSpacing(0)
        , text(nullptr)
        , isVisible(true)
        , pad{0,0,0}
    {
        SetText(L"Test");
    }

    explicit TextData(const wchar_t* txt)
        : xOffset(0)
        , yOffset(0)
        , pxPerLine(0)
        , lineSpacing(0)
        , isVisible(true)
        , pad{0,0,0}
    {
        SetText(txt);
    }
    void SetText(const wchar_t* newText) {
        if (!newText) {
            return;
        }
        SetWideString(&text, newText);
    }
};
#pragma pack(pop)
