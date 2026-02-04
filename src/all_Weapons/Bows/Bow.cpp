#include "Bow.hpp"
#include "../../Hero.hpp"

Bow::Bow(std::string name, std::string type, int dmg, int range, int as, int hands) : Weapon(name, type, dmg, range, as, hands) {}

void Bow::attack(Hero &target) {
    target.setHp(target.getHp() - this->_dmg);
    std::cout << target.getName() << " has taken " << this->_dmg << " damage!" << std::endl;
}

Bow::~Bow() {}

Weapon* Bow::clone() const {
    return new Bow(*this);
}