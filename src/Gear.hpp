#pragma once

#include <iostream>
#include <string>

class Gear {
    protected:
        std::string _name;
        std::string _type;
        //int _weight = -1; // 0 = light, 1 = medium, 2 = heavy, 3 = magic
        int _armor = 0;
        int _str = 0;
        int _int = 0;
        int _dex = 0;
        int _intel = 0;
        int _mana = 0;
        float _moveSpeed = 0.0f;
    
    public:
        virtual ~Gear();
        Gear(const std::string &name, const std::string &type, int armor, int str, int dex, int intel, int mana);

        std::string getName() const;
        std::string getType() const;
        int getArmor() const;
        int getStr() const;
        int getInt() const;
        int getDex() const;
        int getMana() const;
        float getMspeed() const;

        void setArmor(const int armor);
        void setStr(const int str);
        void setInt(const int intel);
        void setDex(const int dex);
        void setMspeed(const float Mspeed);
        void setMana(const int mana);

        virtual Gear* clone() const = 0;
};
