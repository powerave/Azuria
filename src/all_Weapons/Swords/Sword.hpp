#pragma once

#include "../../Weapon.hpp"
#include "../../Entities/Enemy.hpp"


class Sword : public Weapon {
    public:
        Sword(std::string name, std::string type, int dmg, float range, int as, int hands);
        void attack(Enemy &target) override;
        ~Sword() override;
        Weapon* clone() const override;
};
