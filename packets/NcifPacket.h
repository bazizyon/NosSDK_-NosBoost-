#pragma once

namespace Packet {
    class NcifPacket {
    public:
        static constexpr const char* Header = "ncif";

        int entityType = 0;
        long entityID = 0;
    };
}
