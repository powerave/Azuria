#include "Hero.hpp"

Hero::Hero(std::string name, const Bag &bag, int mana, int str, int intel, int dex,
    const std::map<std::string, Gear*> &equiped, const std::map<std::string, Weapon*> &W_equiped) : _name(name),
    _bag(bag), _mana(mana), _str(str), _int(intel), _dex(dex), _crit(0.05f), _equiped(equiped), _W_equiped(W_equiped) {
        this->_hp = str * 4;

        _levels[1] = 100;
        _levels[2] = 250;
        _levels[3] = 500;
        _levels[4] = 900;
        _levels[5] = 1500;
        _levels[6] = 2500;
        _levels[7] = 4000;
        _levels[8] = 7000;
        _levels[9] = 12000;
        _levels[10] = 20000;
    }

Hero::~Hero() {}

std::string Hero::getName() const {
    return _name;
}

Bag& Hero::getBag() {
    return _bag;
}

float Hero::getX() const {
    return _x;
}

float Hero::getY() const {
    return _y;
}

int Hero::getHp() const {
    return _hp;
}

int Hero::getMana() const {
    return _mana;
}

int Hero::getStr() const {
    return _str;
}

int Hero::getDex() const {
    return _dex;
}

float Hero::getCrit() const {
    return _crit;
}

int Hero::getLvl() const {
    return _lvl;
}

int Hero::getExp() const {
    return _exp;
}

float Hero::getMspeed() const {
    return _moveSpeed;
}

std::map<std::string, Gear*> &Hero::getEquiped() {
    return _equiped;
}

Weapon* Hero::getLeftWeapon() {
    if (_W_equiped["left"])
        return _W_equiped["left"];
    return nullptr;
}

Weapon* Hero::getRightWeapon() {
    if (_W_equiped["right"])
        return _W_equiped["right"];
    return nullptr;
}

void Hero::setHp(const int hp) {
    this->_hp = hp;
}

void Hero::setX(const float x) {
    _x = x;
}

void Hero::setY(const float y) {
    _y = y;
}

void Hero::setMana(const int mana) {
    this->_mana = mana;
}

void Hero::setStr(const int str) {
    this->_str = str;
}

void Hero::setDex(const int dex) {
    this->_dex = dex;
}

void Hero::setCrit(const float crit) {
    this->_crit = crit;
}

void Hero::setLvl(const int lvl) {
    this->_lvl = lvl;
}

void Hero::setExp(const int exp) {
    this->_exp = exp;
}

void Hero::setBag(const Bag &bag) {
    this->_bag = bag;
}

void Hero::setMspeed(const float Mspeed) {
    this->_moveSpeed = Mspeed;
}

bool Hero::gearTypeVerif(const Gear &testing) {
    if (testing.getType() != "Armor" && testing.getType() != "Cloak" && testing.getType() != "Gloves" && testing.getType() != "Helmet"
        && testing.getType() != "Pants" && testing.getType() != "Ring" && testing.getType() != "Earring" && testing.getType() != "Shoes") {
    
            std::cout << "Error: Invalid type of Gear." << std::endl;
            return false;
        }
    return true;
}

void Hero::equipGear(Gear* newGear) {
    if (!gearTypeVerif(*newGear))
        return;
    
    std::string type = newGear->getType();
    if (_equiped.find(type) != _equiped.end() && _equiped[type] != nullptr)
        this->_bag.add_gear(_equiped[type]);

    this->_equiped[type] = newGear;
    std::cout << "Equiped " << newGear->getName() << std::endl;
    _bag.remove_item(_bag.getAll_gears(), newGear);
}

void Hero::equipLeftHand(Weapon *newWeapon) {
    if (!_leftHand) {
        this->_W_equiped["left"] = newWeapon;
        _leftHand = true;
        _bag.remove_item(_bag.getAll_weapons(), newWeapon);
        return;
    }
    this->_bag.add_weapon(_W_equiped["left"]);
    this->_W_equiped["left"] = newWeapon;
    _bag.remove_item(_bag.getAll_weapons(), newWeapon);
}

void Hero::equipRightHand(Weapon *newWeapon) {
    if (!_rightHand) {
        this->_W_equiped["right"] = newWeapon;
        _rightHand = true;
        _bag.remove_item(_bag.getAll_weapons(), newWeapon);
        return;
    }
    this->_bag.add_weapon(_W_equiped["right"]);
    this->_W_equiped["right"] = newWeapon;
    _bag.remove_item(_bag.getAll_weapons(), newWeapon);
}

void Hero::equipTwoHands(Weapon *newWeapon) {
    if (!_leftHand && !_rightHand) {
        this->_W_equiped["left"] = newWeapon;
        _leftHand = true;
        _rightHand = true;
    }
    else if (!_leftHand && _rightHand) {
        this->_bag.add_weapon(this->_W_equiped["right"]);
        this->_W_equiped["left"] = newWeapon;
        this->_W_equiped["right"] = newWeapon;
        _leftHand = true;

    }
    else if (_leftHand && !_rightHand) {
        this->_bag.add_weapon(this->_W_equiped["left"]);
        this->_W_equiped["left"] = newWeapon;
        this->_W_equiped["right"] = newWeapon;
        _rightHand = true;

    }
    else if (_leftHand && _rightHand) {
        if (this->_W_equiped["left"]->getHands() == 2) {
            this->_bag.add_weapon(this->_W_equiped["left"]);
            this->_W_equiped["left"] = newWeapon;
            this->_W_equiped["right"] = newWeapon;
        }
        else {
            this->_bag.add_weapon(this->_W_equiped["left"]);
            this->_bag.add_weapon(this->_W_equiped["right"]);
            this->_W_equiped["left"] = newWeapon;
            this->_W_equiped["right"] = newWeapon;
        }
    }
    _bag.remove_item(_bag.getAll_weapons(), newWeapon);
}

void Hero::unequipLeftHand() {
    if (!_leftHand)
        return;
    this->_bag.add_weapon(this->_W_equiped["left"]);
    this->_W_equiped.erase("left");
    this->_leftHand = false;
}

void Hero::unequipRightHand() {
    if (!_rightHand)
        return;
    this->_bag.add_weapon(this->_W_equiped["right"]);
    this->_W_equiped.erase("right");
    this->_rightHand = false;
}

void Hero::unequipTwoHands() {
    if (!_rightHand && !_leftHand)
        return;
    this->_bag.add_weapon(this->_W_equiped["left"]);
    this->_W_equiped.erase("right");
    this->_W_equiped.erase("left");
    _rightHand = false;
    _leftHand = false;
}

void Hero::unequipGear(const std::string &type) {
    if (!this->_equiped[type])
        return;
    this->_bag.add_gear(this->_equiped[type]);
    this->_equiped.erase(type);
}

void Hero::levelUp() {
    while (this->_exp >= _levels[this->_lvl]) {
        std::cout << "Level up! " << this->_name << " is now lvl " << this->_lvl + 1 << std::endl;
        setLvl(_lvl + 1);
    }
}

void Hero::addExp(const int exp) {
    setExp(this->getExp() + exp);
    this->levelUp();
}
