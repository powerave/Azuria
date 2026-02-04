#include "Bag.hpp"
#include "Weapon.hpp"
#include "Gear.hpp"

Bag::Bag(const std::vector<Weapon*> &all_weapons, const std::vector<Gear*> &all_gears) : _all_weapons(all_weapons), _all_gears(all_gears) {}

Bag::~Bag() {}

Bag::Bag(const Bag &other) {
    for (size_t i = 0; i < other._all_weapons.size(); i++)
        this->_all_weapons.push_back(other._all_weapons[i]->clone());

    for (size_t i = 0; i < other._all_gears.size(); i++)
        this->_all_gears.push_back(other._all_gears[i]->clone());
}

const std::vector<Weapon*>& Bag::getAll_weapons() const {
    return _all_weapons;
}

const std::vector<Gear*>& Bag::getAll_gears() const {
    return _all_gears;
}

std::vector<Weapon*>& Bag::getAll_weapons() {
    return _all_weapons;
}

std::vector<Gear*>& Bag::getAll_gears() {
    return _all_gears;
}

void Bag::add_weapon(Weapon *new_weapon) {
    std::cout << "Picked up " << new_weapon->getName() << std::endl;
    _all_weapons.push_back(new_weapon);
}

void Bag::add_gear(Gear *new_gear) {
    std::cout << "Picked up " << new_gear->getName() << std::endl;
    _all_gears.push_back(new_gear);
}

void Bag::remove_weapon(Weapon *rm_weapon) {
    std::vector<Weapon*>::iterator it = std::find(_all_weapons.begin(), _all_weapons.end(), rm_weapon);
    if (it != _all_weapons.end())
        _all_weapons.erase(it);
    std::cout << "Dropped " << rm_weapon->getName() << std::endl;
}

void Bag::remove_gear(Gear *rm_gear) {
    std::vector<Gear*>::iterator it = std::find(_all_gears.begin(), _all_gears.end(), rm_gear);
    if (it != _all_gears.end())
        _all_gears.erase(it);
    std::cout << "Dropped " << rm_gear->getName() << std::endl;
}