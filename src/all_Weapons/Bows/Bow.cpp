#include "Bow.hpp"
#include "../../Hero.hpp"
#include "../../Entities/Enemy.hpp"

Bow::Bow(std::string name, std::string type, int dmg, float range, int as, int hands) : Weapon(name, type, dmg, range, as, hands) {}

void Bow::attack(Enemy &target) {
    target.setHp(target.getHp() - this->_dmg);
    std::cout << target.getName() << " has taken " << this->_dmg << " damage!" << std::endl;
    if (target.getHp() <= 0)
        std::cout << target.getName() << " has died!" << std::endl;
}

Bow::~Bow() {}

Weapon* Bow::clone() const {
    return new Bow(*this);
}