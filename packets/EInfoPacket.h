#pragma once
#include <string>
#include <variant>
#include <vector>

namespace Packet {
    struct EInfoShellOption {
        int tier = 0;
        int id = 0;
        int value = 0;
        int extra = 0;
    };

    struct EInfoRune {
        int type = 0;
        int subType = 0;
        int value = 0;          // negative means the decreased version
        int secondValue = 0;
        int level = 0;
    };

    struct EInfoWeapon {
        int rarity = 0;
        int upgradeLevel = 0;
        bool levelFixed = false;
        int requiredLevel = 0;
        int minDamage = 0;
        int maxDamage = 0;
        int hitRate = 0;
        int critChance = 0;
        int critDamage = 0;
        int ammoLeft = 0;
        int ammoMax = 0;
        int sellPrice = 0;
        int baseWeaponID = -1;
        int rarityOfTheEffects = 0;
        int soulboundOwner = 0;
        int shellType = 0;
        std::vector<EInfoShellOption> shellOptions;
        int runeUpgrade = 0;
        bool runesBroken = false;
        std::vector<EInfoRune> runes;
    };

    struct EInfoArmor {
        int rarity = 0;
        int upgradeLevel = 0;
        bool levelFixed = false;
        int requiredLevel = 0;
        int meleeDefence = 0;
        int rangedDefence = 0;
        int magicDefence = 0;
        int dodge = 0;
        int sellPrice = 0;
        int baseItemID = -1;
        int rarityOfTheEffects = 0;
        int soulboundOwner = 0;
        int shellType = 0;
        std::vector<EInfoShellOption> shellOptions;
        int runeUpgrade = 0;
        bool runesBroken = false;
        std::vector<EInfoRune> runes;
    };

    struct EInfoFairy {
        int element = 0;        // 0 none, 1 fire, 2 water, 3 light, 4 shadow
        int elementRate = 0;    // already includes what your gear adds
        int unknown0 = 0;
        int unknown1 = 0;
        int unknown2 = 0;
        int unknown3 = 0;
        int unknown4 = 0;
        int unknown5 = 0;
        int soulboundOwner = 0;
        int unknown6 = 0;
        int unknown7 = 0;
        std::vector<EInfoShellOption> options;
    };

    using EInfoDetails = std::variant<std::monostate, EInfoWeapon, EInfoArmor, EInfoFairy>;

    class EInfoPacket {
    public:
        static constexpr const char* Header = "e_info";

        int itemType = 0;       // 0 bow or gun, 1 sword or dagger, 2 armor, 3 jewelry, 4 fairy, 5 wand, 7 SP, 13 partner SP
        int itemVNUM = 0;
        EInfoDetails details;
        std::vector<std::string> fields;    // raw values after the vnum, for item types that are not parsed yet
    };
}
