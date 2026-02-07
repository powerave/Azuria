#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Enemy {
    protected:
        const std::string _name;
        const std::string _primaryWeapon;
        float _x;
        float _y;
        int _dmg;
        float _atkSpeed;
        float _range;
        int _hp;
        int _mana;
        float _moveSpeed = 2.0f;
        float _crit = 5.0f;
        int _lvl;
        int _exp;
        sf::FloatRect _hitbox;
        sf::Texture _enemyTexture;
        sf::Sprite _enemySprite;
    
    public:
        Enemy(std::string name, std::string primaryWeapon, float x, float y, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp);
        virtual ~Enemy();
        Enemy(const Enemy& other);

        std::string getName() const;
        std::string getWeaponName() const;
        float getX() const;
        float getY() const;
        int getDmg() const;
        float getAtkSpeed() const;
        float getRange() const;
        int getHp() const;
        int getMana() const;
        float getMspeed() const;
        float getCrit() const;
        int getExp() const;
        sf::FloatRect getHitbox() const;

        void setX(const float x);
        void setY(const float y);
        void setHp(const int hp);
        void setMana(const int mana);
        void setMspeed(const float speed);
        void setCrit(const float crit);

        virtual Enemy* clone() const = 0;
        virtual sf::Sprite &getSprite();
};
