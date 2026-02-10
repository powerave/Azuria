#pragma once

#include "../../Gear.hpp"

class Armor : public Gear {
    public:
        Armor(const std::string &name, const std::string &type, int armor, int str, int dex, int intel, int mana);
        ~Armor() override;
        Armor* clone() const override;
};
