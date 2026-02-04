#pragma once

#include "Bag.hpp"
#include "Gear.hpp"
#include "Weapon.hpp"
#include <map>
#include <string>

class Hero {
    private:
        const std::string _name;
        Bag _bag;
        int _hp = 0;
        int _mana = 0;
        int _str = 0;
        int _int = 0;
        int _dex = 0;
        float _moveSpeed = 5.0f;
        float _crit = 5.0f;
        int _lvl = 1;
        int _exp = 0;
        bool _leftHand = false; // false = empty
        bool _rightHand = false;
        std::map<int, int> _levels;
        std::map<std::string, Gear*> _equiped;
        std::map<std::string, Weapon*> _W_equiped;

    public:
        ~Hero();
        Hero(std::string name, const Bag &bag, int mana, int str, int intel, int dex,
            const std::map<std::string, Gear*> &equiped, const std::map<std::string, Weapon*> &W_equiped);

        std::string getName() const;
        Bag& getBag();
        int getHp() const;
        int getMana() const;
        int getStr() const;
        int getDex() const;
        float getCrit() const;
        int getLvl() const;
        int getExp() const;
        float getMspeed() const;
        std::map<std::string, Gear*> &getEquiped();
        
        void setHp(const int hp);
        void setMana(const int mana);
        void setStr(const int str);
        void setDex(const int dex);
        void setCrit(const float crit);
        void setLvl(const int lvl);
        void setExp(const int exp);
        void setBag(const Bag& bag);
        void setMspeed(const float Mspeed);
        
        void equipGear(Gear* newGear);
        void equipLeftHand(Weapon* newWeapon);
        void equipRightHand(Weapon *newWeapon);
        void equipTwoHands(Weapon *newWeapon);
        
        void unequipLeftHand();
        void unequipRightHand();
        void unequipTwoHands();
        void unequipGear(const std::string &type);
        
        bool gearTypeVerif(const Gear &testing);
        void levelUp();
        void addExp(const int exp);
    };
