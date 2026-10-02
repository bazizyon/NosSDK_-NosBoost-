#pragma once

namespace Packet {
    class GoldPacket {
    public:
        static constexpr const char* Header = "gold";

        long long gold = 0;
        long long bankGold = 0;
    };
}
