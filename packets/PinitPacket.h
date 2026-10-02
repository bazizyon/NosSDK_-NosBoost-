#pragma once
#include <string>
#include <vector>

namespace Packet {
    struct PartyMember {
        int type = 0;
        long entityID = 0;
        int index = 0;
        int level = 0;
        std::string name;
    };

    class PinitPacket {
    public:
        static constexpr const char* Header = "pinit";

        std::vector<PartyMember> members;
    };
}
