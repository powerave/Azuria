#include "../Includes/Gear.hpp"

Gear::~Gear() {}

Gear::Gear(const std::string &name, const std::string &type, int armor, int str, int dex, int intel, int mana) : _name(name), _type(type), _armor(armor), _str(str), _int(intel), _dex(dex), _mana(mana) {}

std::string Gear::getName() const {
    return _name;
}

std::string Gear::getType() const {
    return _type;
}

int Gear::getArmor() const {
    return _armor;
}

int Gear::getStr() const {
    return _str;
}

int Gear::getInt() const {
    return _int;
}

int Gear::getDex() const {
    return _dex;
}

int Gear::getMana() const {
    return _mana;
}

float Gear::getMspeed() const {
    return _moveSpeed;
}

void Gear::setArmor(const int armor) {
    this->_armor = armor;
}

void Gear::setStr(const int str) {
    this->_str = str;
}

void Gear::setInt(const int intel) {
    this->_int = intel;
}

void Gear::setDex(const int dex) {
    this->_dex = dex;
}

void Gear::setMana(const int mana) {
    this->_mana = mana;
}

void Gear::setMspeed(const float Mspeed) {
    this->_moveSpeed = Mspeed;
}
