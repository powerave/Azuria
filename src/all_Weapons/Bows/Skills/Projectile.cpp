#pragma once

#include "Projectile.hpp"
#include <cmath>

Projectile::Projectile(float speed, float startX, float startY, float targetX, float targetY) 
	: _speed(speed), _x(startX), _y(startY), _targetX(targetX), _targetY(targetY) {
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
	}

Projectile::~Projectile() {}

Projectile::Projectile(const Projectile &other) : _speed(other._speed), _x(other._x), _y(other._y), _dirX(other._dirX), _dirY(other._dirY), _targetX(other._targetX), _targetY(other._targetY) {}

float Projectile::getSpeed() const {
	return _speed;
}

float Projectile::getX() const {
	return _x;
}

float Projectile::getY() const {
	return _y;
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
	_x = _dirX * _speed * deltaTime;
	_y = _dirY * _speed * deltaTime;
}

bool Projectile::hasReachTarget() const {
	float dx = _targetX - _x;
	float dy = _targetY - _y;
	float distanceSquared = dx * dx + dy * dy;

	float thresholdSquared = 5.0f * 5.0f;
	return distanceSquared < thresholdSquared;
}