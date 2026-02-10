#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../../Hero.hpp"
#include "../../../Weapon.hpp"

class Enemy;

class Projectile {
	protected:
		float _speed;
		float _x, _y;
		float _startX, _startY;
		float _dirX, _dirY;
		float _targetX, _targetY;
		float _range;
		sf::Texture _projectileTexture;
		sf::Sprite _projectileSprite;
		float angle;

	public:
		Projectile(float speed, float startX, float startY, float targetX, float targetY, float range);
		virtual ~Projectile();
		Projectile(const Projectile &other);

		float getSpeed() const;
		float getX() const;
		float getY() const;
		sf::Sprite& getSprite();

		void setX(const float x);
		void setY(const float y);
		void setTarget(float targetX, float targetY);
		sf::Vector2f getTipPosition() const;
		
		void update(float deltaTime);
		bool hasReachTarget(Enemy &target, Hero &hero) const;
		bool exceedRange() const;
		virtual Projectile* clone() const = 0;;
};
