#pragma once

#include "Enemy.hpp"
#include "../Hero.hpp"

class Skeleton :public Enemy {
	private:
		std::string _type = "skeleton";
		sf::IntRect _rectSkeleton;
		sf::Clock _animClock;
	
	public:
		Skeleton(std::string name, std::string primaryWeapon, float x, float y, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp);
		~Skeleton();
		Skeleton(const Skeleton &other);

		void attack(Hero hero);
		void idleAnimation();

		std::string getType() const;
		Skeleton* clone() const override;
		sf::Sprite &getSprite() override;
};
