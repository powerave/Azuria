#include "../../../../Includes/all_Weapons/Bows/Skills/Arrow.hpp"

Arrow::Arrow(float speed, float startX, float startY, float targetX, float targetY, float range)
	: Projectile(speed, startX, startY, targetX, targetY, range) {
		if (!_projectileTexture.loadFromFile("Sprites/Arcane archer/arrow.png"))
			std::cout << "Error: failed to load arrow.png" << std::endl;
		_projectileSprite.setTexture(_projectileTexture);
		_projectileSprite.setTextureRect(sf::IntRect(0, 0, 100, 20));
		_projectileSprite.setOrigin(10.F, 10.f);
		_projectileSprite.setPosition(_x, _y);
		std::cout << "Arrow" << std::endl;
	}

Arrow::~Arrow() {}
        
Arrow* Arrow::clone() const {
	return new Arrow(*this);
}
        
std::string Arrow::getName() const {
	return _name;
}