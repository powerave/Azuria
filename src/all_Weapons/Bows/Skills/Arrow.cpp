#include "Arrow.hpp"

Arrow::Arrow(float speed, float startX, float startY, float targetX, float targetY)
	: Projectile(speed, startX, startY, targetX, targetY) {}

Arrow::~Arrow() {}
        
Arrow* Arrow::clone() const {
	return new Arrow(*this);
}
        
std::string Arrow::getName() const {
	return _name;
}