#pragma once
#include <cstdint>
#include <string>
#pragma pack(push, 1)

// TODO: turn network one into this
struct DelphiShortString {
    uint8_t length;
    char data[255];

    std::string ToString() const {
        return std::string(data, length);
    }
};
static_assert(sizeof(DelphiShortString) == 0x100);
#pragma pack(pop)