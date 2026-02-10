#include "../../../Includes/all_Gears/Armors/Armors.hpp"

Armor::Armor(const std::string &name, const std::string &type, int armor, int str, int dex, int intel, int mana) : Gear(name, type, armor, str, dex, intel, mana) {}

Armor::~Armor() {}

Armor* Armor::clone() const {
    return new Armor(*this);
}