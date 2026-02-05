#include "Enemy.hpp"

Enemy::Enemy( std::string name, std::string primaryWeapon, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp)
    : _name(name), _primaryWeapon(primaryWeapon), _dmg(dmg), _atkSpeed(as), _range(range), _hp(hp), _mana(mana), _lvl(lvl), _exp(exp) {}

Enemy::~Enemy() {}

Enemy::Enemy(const Enemy &other) : _name(other._name), _primaryWeapon(other._primaryWeapon), _dmg(other._dmg), _atkSpeed(other._atkSpeed), _range(other._range), _hp(other._hp), _mana(other._mana), _lvl(other._lvl), _exp(other._exp) {}

std::string Enemy::getName() const {
    return _name;
}

std::string Enemy::getWeaponName() const {
    return _primaryWeapon;
}

int Enemy::getDmg() const {
    return _dmg;
}

float Enemy::getAtkSpeed() const {
    return _atkSpeed;
}

float Enemy::getRange() const {
    return _range;
}

int Enemy::getHp() const {
    return _hp;
}

int Enemy::getMana() const {
    return _mana;
}

float Enemy::getMspeed() const {
    return _moveSpeed;
}

float Enemy::getCrit() const {
    return _crit;
}

int Enemy::getExp() const {
    return _exp;
}

void Enemy::setHp(const int hp) {
    this->_hp = hp;
}

void Enemy::setMana(const int mana) {
    this->_mana = mana;
}

void Enemy::setMspeed(const float speed) {
    this->_moveSpeed = speed;
}

void Enemy::setCrit(const float crit) {
    this->_crit = crit;
}
