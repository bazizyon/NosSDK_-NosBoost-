#pragma once
#include <string>
#include "TEWControlWidget.h"
#include "TEWLabel.h"
#pragma pack(push, 1)

struct DelphiMethod {
    uint32_t code;
    uint32_t data;
};

struct TEWEditWidget : TEWControlWidget {
    wchar_t* text;              // 0x70
    wchar_t* compositionText;   // 0x74
    char unknown_78[8];         // 0x78
    int32_t caretIndex;         // 0x80
    int32_t caretX;             // 0x84
    int32_t scrollX;            // 0x88
    uint32_t unknown_8c;        // 0x8C
    uint32_t unknown_90;        // 0x90
    uint32_t unknown_94;        // 0x94
    DelphiMethod events[9];     // 0x98
    uint8_t font;               // 0xE0
    uint8_t unknown_e1;         // 0xE1
    Color textColor;            // 0xE2
    Color unknown_e6;           // 0xE6
    uint8_t unknown_ea;         // 0xEA
    uint8_t pad_eb;             // 0xEB

    explicit TEWEditWidget(const uintptr_t vTable)
        : TEWControlWidget(vTable)
        , text(nullptr)
        , compositionText(nullptr)
        , caretIndex(0)
        , caretX(0)
        , scrollX(0)
        , unknown_8c(0)
        , unknown_90(0)
        , unknown_94(0)
        , font(2)
        , unknown_e1(0)
        , textColor(255, 255, 255, 255)
        , unknown_e6(255, 0x6F, 0x94, 0xF3)
        , unknown_ea(3)
        , pad_eb(0)
    {
        someFlags = 0x39;
        color = Color(255, 0x6F, 0x94, 0xF3);
        delete[] imageData.atlasFrames;
        imageData.frameCount = 0;
        imageData.imageName = 1593835568;
        imageData.atlasFrames = nullptr;
        std::memset(unknown_78, 0, sizeof(unknown_78));
        std::memset(events, 0, sizeof(events));
    }

    [[nodiscard]] bool HasFocus() const {
        return isLastInteracted;
    }

    [[nodiscard]] std::wstring GetText() const {
        if (!text) return {};
        const uint32_t Bytes = *reinterpret_cast<const uint32_t*>(reinterpret_cast<uintptr_t>(text) - 4);
        return {text, Bytes / sizeof(wchar_t)};
    }

    void SetText(const wchar_t* newText) {
        if (!newText) return;
        SetWideString(&text, newText);
    }

    static constexpr auto ClassName = "TEWEditWidget";
    static constexpr uint32_t ExpectedSize = 0xEC;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWEditWidget) == TEWEditWidget::ExpectedSize, "TEWEditWidget size mismatch (see TEWEditWidget::ExpectedSize)");
#pragma pack(pop)
