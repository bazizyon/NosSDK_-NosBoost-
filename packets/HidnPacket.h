#pragma once

namespace Packet {
    class HidnPacket {
    public:
        static constexpr const char* Header = "hidn";

        int unknown_null = 0;
        float degrees = 0.0f;
        int x = 0;
        int y = 0;
    };
}
