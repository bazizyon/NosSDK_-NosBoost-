#pragma once
#include <cstdint>
#include <string>
#include "TObject.h"
#pragma pack(push, 1)

struct TStringItem {
    const char* string;
    void* object;
};

struct TStringList : TObject {
    char unknown_04[12];    // 0x04
    TStringItem* items;     // 0x10
    int32_t count;          // 0x14
    int32_t capacity;       // 0x18

    [[nodiscard]] std::string Get(const int32_t index) const {
        if (!items || index < 0 || index >= count || !items[index].string) return {};
        return items[index].string;
    }
};
#pragma pack(pop)
