#pragma once
#include <cstdint>
#pragma pack(push, 1)

struct NineSliceInfo {
    uint16_t widthMiddle;	    // 0x00
    uint16_t heightMiddle;	    // 0x02
    uint16_t posRight;		    // 0x04
    uint16_t posBot;			// 0x06
    uint16_t widthLeft;		    // 0x08
    uint16_t heightTop;		    // 0x0A
    uint16_t widthRight;		// 0x0C
    uint16_t heightBot;		    // 0x0E
};
#pragma pack(pop)
