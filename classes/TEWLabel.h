#pragma once
#include "DelphiShortString.h"
#include "TEWControlWidgetEX.h"
#define NOMINMAX
#include <windows.h>
#include <oleauto.h> // BSTR / SysAllocString -- link oleaut32 (see NosBoostRuntime/CMakeLists.txt)
#pragma pack(push, 1)

inline void WStrAsg_call(void* dest, void* src) {
    __asm {
        mov eax, dest
        mov edx, src
        mov ecx, 0x00405980   // load address into register
        call ecx              // call via register
    }
}

// TODO: dont call a fixed adress but find it in runtime

inline void SetWideString(void* destVar, const wchar_t* text)
{
    BSTR b = SysAllocString(text);
    if (!b) return;

    WStrAsg_call(destVar, b);
}

struct TEWLabel : TEWControlWidgetEX {
    char unknown1;          // 0x70
    char unknown2;          // 0x71
    uint8_t fontStyle;      // 0x72
    uint8_t shadowStyle;    // 0x73
    Color textColor;        // 0x74
    Color shadowColor;      // 0x78
    uint8_t textAlignment;  // 0x7C
    char pad1[3];           // 0x7D
    int16_t x;              // 0X80
    int16_t y;              // 0X82
    int16_t pxPerLine;      // 0X84
    int16_t lineSpacing;    // 0X86
    wchar_t* labelText;     // 0x88
    bool isVisible;         // 0x8C
    char pad2[3];           // 0x8D
    uint32_t unknown7;      // 0x90
    uint32_t unknown8;      // 0x94
    explicit TEWLabel(const uintptr_t vTable)
        : TEWControlWidgetEX(vTable)
        , unknown1(1)
        , unknown2(0)
        , fontStyle(1)
        , shadowStyle(255)
        , textColor(255, 255, 255, 255)
        , shadowColor(255, 0, 0, 0)
        , textAlignment(3)
        , x(1)
        , y(6)
        , pxPerLine(98)
        , lineSpacing(0)
        , labelText(nullptr)
        , isVisible(true)
        , unknown7(0)
        , unknown8(0)
    {
        isInteractable = false;
        someFlags |= 0x20;
        std::memset(pad1, 0, sizeof(pad1));
        std::memset(pad2, 0, sizeof(pad2));
        SetText(L"Label");
    }
    void SetText(const wchar_t* text) {
        if (!text) {
            return;
        }
        SetWideString(&labelText, text);
    }

    static constexpr auto ClassName = "TEWLabel";
    static constexpr uint32_t ExpectedSize = 0x98;
    static constexpr uint32_t Version = 1;
};

static_assert(sizeof(TEWLabel) == TEWLabel::ExpectedSize, "TEWLabel size mismatch (see TEWLabel::ExpectedSize)");
#pragma pack(pop)
