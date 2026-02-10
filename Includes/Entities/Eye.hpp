#pragma once

#include "Enemy.hpp"
#include "../Hero.hpp"

class Eye : public Enemy {
	private:
		std::string _type = "eye";
		sf::IntRect _rectEye;
		sf::Clock _animClock;

	public:
		Eye(std::string name, std::string primaryWeapon, float x, float y, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp);
		~Eye();
		Eye(const Eye &other);

		void attack(Hero hero);
		void idleAnimation();

		std::string getType() const;
		Eye* clone() const override;
		sf::Sprite &getSprite() override;
};
