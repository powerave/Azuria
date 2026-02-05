#pragma once

#include "../../Weapon.hpp"

class Enemy;

class Bow : public Weapon {
    public:
        Bow(std::string name, std::string type, int dmg, float range, int as, int hands);
        void attack(Enemy &target) override;
        ~Bow() override;
        Weapon* clone() const override;
};
