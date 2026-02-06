#pragma once

#include <string>
#include <iostream>

class Hero;
class Enemy;

class Weapon  {
    protected:
        const std::string _name;
        const std::string _type;
        int _dmg = 0;
        //int _dmg_type = -1;
        float _range = 0;
        int _atk_speed = 0;
        int _hands; // 1 ou 2
    
    public:
        virtual ~Weapon();
        Weapon(const std::string &name, const std::string &type, int dmg, float range, int as, int hands);
        std::string getName() const;
        std::string getType() const;
        int getDmg() const;
        float getRange() const;
        int getAs() const;
        int getHands() const;

        void setDmg(const int dmg);
        void setRange(const float range);
        void setAs(const int as);

        virtual void attack(Enemy &target) = 0;
        virtual Weapon* clone() const = 0;
};
