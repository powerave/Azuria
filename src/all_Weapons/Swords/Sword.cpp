#include "../../../Includes/all_Weapons/Swords/Sword.hpp"
#include "../../../Includes/Hero.hpp"

Sword::Sword(std::string name, std::string type, int dmg, float range, int as, int hands) : Weapon(name, type, dmg, range, as, hands) {}

void Sword::attack(Enemy &target, Hero &hero) {
    target.setHp(target.getHp() - _dmg);
    std::cout << target.getName() << " has taken " << this->_dmg << " damage!" << std::endl;
    if (target.getHp() <= 0)
        std::cout << target.getName() << " has died!" << std::endl;
}

Sword::~Sword() {}

Weapon* Sword::clone() const {
    return new Sword(*this);
}