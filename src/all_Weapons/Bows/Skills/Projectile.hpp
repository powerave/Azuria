#pragma once

#include <string>

class Projectile {
	private:
		float _speed;
		float _x;
		float _y;
		float _dirX;
		float _dirY;
		float _targetX;
		float _targetY;

	public:
		Projectile(float speed, float startX, float startY, float targetX, float targetY);
		virtual ~Projectile();
		Projectile(const Projectile &other);

		float getSpeed() const;
		float getX() const;
		float getY() const;

		void setX(const float x);
		void setY(const float y);
		void setTarget(float targetX, float targetY);

		void update(float deltaTime);
		bool hasReachTarget() const;
		virtual Projectile* clone() const = 0;;
};
