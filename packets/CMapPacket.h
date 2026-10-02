#pragma once

namespace Packet {
    class CMapPacket {
    public:
        static constexpr const char* Header = "c_map";

        int unknown = 0;
        int mapId = 0;
        bool isEntering = false;
    };
}
