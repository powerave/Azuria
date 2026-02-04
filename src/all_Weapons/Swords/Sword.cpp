#include "Sword.hpp"
#include "../../Hero.hpp"

Sword::Sword(std::string name, std::string type, int dmg, int range, int as, int hands) : Weapon(name, type, dmg, range, as, hands) {}

void Sword::attack(Hero &target) {
    target.setHp(target.getHp() - _dmg);
    std::cout << target.getName() << " has taken " << this->_dmg << " damage!" << std::endl;
}

Sword::~Sword() {}

Weapon* Sword::clone() const {
    return new Sword(*this);
}