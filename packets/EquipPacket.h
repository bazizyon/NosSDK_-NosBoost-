#pragma once
#include <vector>

namespace Packet {
    struct EquipSlot {
        int slot = 0;
        int itemVNUM = 0;
        int rarity = 0;
        int upgradeLevel = 0;
        int unknown0 = 0;
        int runeUpgrade = 0;
        int shellType = 0;
    };

    class EquipPacket {
    public:
        static constexpr const char* Header = "equip";

        int weaponUpgradeRarity = 0;    // upgrade times 10 plus rarity
        int armorUpgradeRarity = 0;
        std::vector<EquipSlot> slots;
    };
}
