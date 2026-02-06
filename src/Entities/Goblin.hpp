#pragma once

#include <SFML/Graphics.hpp>
#include "../Hero.hpp"
#include "Enemy.hpp"

class Goblin : public Enemy {
    private:
        std::string _type = "goblin";
        sf::IntRect _rectGoblin;
        sf::Clock _animClock;
        float _x;
        float _y;
    
    public:
        Goblin(std::string name, std::string primaryWeapon, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp, float x, float y);
        ~Goblin();
        Goblin(const Goblin &other);
        
        void attack(Hero hero);
        void idleAnimation();

        std::string getType() const;
        Goblin* clone() const override;
        sf::Sprite &getSprite() override;
};
