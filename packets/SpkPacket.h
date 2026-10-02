#pragma once
#include "EntityType.h"
#include <string>

namespace Packet {
    class SpkPacket {
    public:
        static constexpr const char* Header = "spk";
        static constexpr int WhisperType = 5;

        EntityType entityType = EntityType::Player;
        long entityID = 0;
        int speakType = 0;
        std::string name;
        std::string message;
    };
}
