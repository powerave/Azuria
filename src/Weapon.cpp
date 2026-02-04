#include "Weapon.hpp"

Weapon::~Weapon() {
    std::cout << "Dropped this useless sword" << std::endl;
}

Weapon::Weapon(const std::string &name, const std::string &type, int dmg, int range, int as, int hands) : _name(name), _dmg(dmg), _range(range), _atk_speed(as), _hands(hands) {}

std::string Weapon::getName() const {
    return _name;
}

std::string Weapon::getType() const {
    return _type;
}

int Weapon::getDmg() const {
    return _dmg;
}

int Weapon::getRange() const {
    return _range;
}

int Weapon::getAs() const {
    return _atk_speed;
}

int Weapon::getHands() const {
    return _hands;
}

void Weapon::setDmg(const int dmg) {
    this->_dmg = dmg;
}

void Weapon::setRange(const int range) {
    this->_range = range;
}

void Weapon::setAs(const int atk_speed) {
    this->_atk_speed = atk_speed;
}
