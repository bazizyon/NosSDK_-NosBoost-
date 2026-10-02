#pragma once

namespace Packet {
    class GpPacket {
    public:
        static constexpr const char* Header = "gp";

        int xPos = 0;
        int yPos = 0;
        int destinationMapId = 0;
        int portalType = 0;
        int portalId = 0;
        bool isDisabled = false;
    };
}
