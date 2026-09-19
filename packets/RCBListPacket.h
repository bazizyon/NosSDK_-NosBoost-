#pragma once
#include <cstdint>
#include <string>
#include <variant>
#include <vector>

namespace Packet {
    enum class ItemType : uint32_t {
        AmmoWeapon = 0,             // bow, xbow, gun
        AmmolessWeapon = 1,         // sword, dagger
        Armor = 2,
        ConcentrationWeapon = 5,    // wand
        SP = 7,
        Fairy = 12,
        PSP = 13,
    };

    struct RCBListShellOption {
        int tier = 0;                       // C-B-A-S purple and pvp C-B-A-S
        int id = 0;
        int value = 0;
        int shellUpgradeCount = 0;          // server doesn't say how much is added, client knows
    };

    struct RCBListWeaponInfo {
        ItemType itemType = ItemType::AmmoWeapon;
        int itemVNUM = 0;
        int rarity = 0;
        int upgradeLevel = 0;
        bool levelFixed = false;
        int requiredLevel = 0;              // same field for c level and regular level
        int minDamage = 0;
        int maxDamage = 0;
        int hitRate = 0;                    // same is used for concentration
        int critChance = 0;
        int critDamage = 0;
        int ammoLeft = 0;                   // exists for ammoless weapons aswell and is 0
        int ammoMax = 0;                    // 100 for ammoless weapon too
        int sellPrice = 0;
        int baseWeaponID = -1;              // -1 = original weapon, otherwise ID of source weapon (partner weapon)
        int rarityOfTheEffects = 0;         // is there when shell is added manually
        int soulboundOwner = 0;
        int shellAmount = 0;
        int shellType = 0;                  // unsure, 82 and 84 I believe these are pvp shell perfect shell etc
        std::vector<RCBListShellOption> shellOptions;
        int pityGaugeProgress = 0;          // out of 1000, so 100 = 10.0%
    };

    struct RCBListArmorInfo {
        ItemType itemType = ItemType::Armor;
        int itemVNUM = 0;
        int rarity = 0;
        int upgradeLevel = 0;
        bool levelFixed = false;
        int requiredLevel = 0;
        int meleeDefence = 0;
        int rangedDefence = 0;
        int magicDefence = 0;
        int dodge = 0;
        int sellPrice = 0;
        int baseWeaponID = -1;
        int rarityOfTheEffects = 0;
        int soulboundOwner = 0;
        int shellAmount = 0;
        int shellType = 0;
        std::vector<RCBListShellOption> shellOptions;
        int pityGaugeProgress = 0;
    };

    struct RCBListFairyInfo {
        ItemType itemType = ItemType::Fairy;
        int itemVNUM = 0;
        bool isEmpty = false;
        int fairyID = 0;
        int percentage = 0;
        bool canUseRestoration = false;
        bool overcharged = false;
        int shellAmount = 0;
        std::vector<RCBListShellOption> shellOptions;
        int nullTerminator = 0;
    };

    struct RCBListPSPInfo {
        ItemType itemType = ItemType::PSP;
        int itemVNUM = 0;
        bool isEmpty = false;
        int PSPID = 0;                      // partner sp id
        int element = 0;
        int skill1 = 0;
        int skill1tier = 0;
        int skill2 = 0;
        int skill2tier = 0;
        int skill3 = 0;
        int skill3tier = 0;
        int upgradeLevel = 0;
        int attackLevel = 0;
        int defenceLevel = 0;
        int critDamageReductionLevel = 0;
        int HPMPLevel = 0;
        int fireResistanceLevel = 0;
        int waterResistanceLevel = 0;
        int lightResistanceLevel = 0;
        int shadowResistanceLevel = 0;
        int nullTerminator = 0;             // not sure
    };

    struct RCBListSPInfo {
        ItemType itemType = ItemType::SP;
        int itemVNUM = 0;
        bool isEmpty = false;
        int SPID = 0;
        int level = 0;
        int currentEXP = 0;
        int maxEXP = 0;
        int upgradingGrade = 0;
        int attackPoints = 0;
        int defencePoints = 0;
        int elementPoints = 0;
        int hpmpPoints = 0;
        int remainingPoints = 0;
        int perfectionLevel = 0;
        int unknown0 = 0;
        int unknown1 = 0;
        int unknown2 = 0;
        int unknown3 = 0;
        int attackPerf = 0;
        int defencePerf = 0;
        int elementPerf = 0;
        int hpmpPerf = 0;
        int fireResPerf = 0;
        int waterResPerf = 0;
        int lightResPerf = 0;
        int shadowResPerf = 0;
        int unknown4 = 0;
    };

    using RCBListItemInfo = std::variant<std::monostate, RCBListWeaponInfo, RCBListArmorInfo,
                                          RCBListSPInfo, RCBListPSPInfo, RCBListFairyInfo>;

    struct RCBListEntry {
        int itemID = 0;
        int sellerID = 0;
        std::string sellerName;
        int itemVNUM = 0;
        int unknown1 = 0;
        int unknown2 = 0;
        int salePrice = 0;
        int minutesLeft = 0;
        int unknown3 = 0;
        int unknown4 = 0;
        int unknown5 = 0;
        int unknown6 = 0;
        int unknown7 = 0;
        int unknown8 = 0;
        RCBListItemInfo itemInfo;
    };

    class RCBListPacket {
    public:
        static constexpr auto Header = "rc_blist";

        std::vector<RCBListEntry> entries;
    };
}
