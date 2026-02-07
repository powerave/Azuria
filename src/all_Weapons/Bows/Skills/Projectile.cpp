#include "Projectile.hpp"
#include <cmath>
#include "../../../Entities/Enemy.hpp"

Projectile::Projectile(float speed, float startX, float startY, float targetX, float targetY, float range) 
	: _speed(speed), _x(startX), _y(startY), _startX(startX), _startY(startY), _targetX(targetX), _targetY(targetY), _range(range) {
		float dirX = targetX - startX;
		float dirY = targetY - startY;
		float length = std::sqrt(dirX * dirX + dirY * dirY);
		if (length > 0) {
			_dirX = dirX / length;
			_dirY = dirY / length;
		} else {
			_dirX = 0;
			_dirY = 0;
		}
		float angle = std::atan2(_dirY, _dirX) * 180 / 3.14159265f;
		sf::FloatRect bounds = _projectileSprite.getLocalBounds();
		_projectileSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
		_projectileSprite.setRotation(angle);
	}

Projectile::~Projectile() {}

Projectile::Projectile(const Projectile &other) : _speed(other._speed), _x(other._x), _y(other._y), _dirX(other._dirX), _dirY(other._dirY), _targetX(other._targetX), _targetY(other._targetY), _range(other._range) {}

float Projectile::getSpeed() const {
	return _speed;
}

float Projectile::getX() const {
	return _x;
}

float Projectile::getY() const {
	return _y;
}

sf::Sprite& Projectile::getSprite() {
	return _projectileSprite;
}

void Projectile::setX(const float x) {
	_x = x;
}

void Projectile::setY(const float y) {
	_y = y;
}

void Projectile::setTarget(float targetX, float targetY) {
	_targetX = targetX;
	_targetY = targetY;

	float dirX = targetX - _x;
	float dirY = targetY - _y;
	float length = std::sqrt(dirX * dirX + dirY * dirY);
	if (length > 0) {
		_dirX = dirX / length;
		_dirY = dirY / length;
	}
}

void Projectile::update(float deltaTime) {
	_x += _dirX * _speed * deltaTime;
	_y += _dirY * _speed * deltaTime;
	_projectileSprite.setPosition(_x, _y);
}

bool Projectile::exceedRange() const {
	float dx = _x - _startX;
	float dy = _y - _startY;
	float distanceTraveled = std::sqrt(dx * dx + dy * dy);
	return distanceTraveled >= _range;
}

bool Projectile::hasReachTarget(Enemy &target, Hero &hero) const {
	float thresholdSquared = 5.0f * 5.0f;
	int leftDmg, rightDmg;

	if (hero.getLeftWeapon()) {
		leftDmg = hero.getLeftWeapon()->getDmg();
	} else {
		leftDmg = 0;
	}
	if (hero.getRightWeapon()) {
		rightDmg = hero.getRightWeapon()->getDmg();
	} else {
		rightDmg = 0;
	}
	if (target.getHitbox().contains(_x, _y)) {
		int dmg = leftDmg + rightDmg;
	  	target.setHp(target.getHp() - (dmg));
	  	std::cout << target.getName() << " has taken " << dmg << " damage!" << std::endl;
    
		if (target.getHp() <= 0)
	        std::cout << target.getName() << " has died!" << std::endl;
		return true;
	}
	return false;
}
