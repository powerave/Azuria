#pragma once

#include <string>
#include <iostream>

class Hero;

class Weapon  {
    protected:
        const std::string _name;
        const std::string _type;
        int _dmg = 0;
        //int _dmg_type = -1;
        int _range = 0;
        int _atk_speed = 0;
        int _hands; // 1 ou 2
    
    public:
        virtual ~Weapon();
        Weapon(const std::string &name, const std::string &type, int dmg, int range, int as, int hands);

        std::string getName() const;
        std::string getType() const;
        int getDmg() const;
        int getRange() const;
        int getAs() const;
        int getHands() const;

        void setDmg(const int dmg);
        void setRange(const int range);
        void setAs(const int as);

        virtual void attack(Hero &target) = 0;
        virtual Weapon* clone() const = 0;
};
