#include "Eye.hpp"

Eye::Eye(std::string name, std::string primaryWeapon, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp, float x, float y)
	: Enemy(name, primaryWeapon, dmg, as, range, hp, mana, ms, crit, lvl, exp), _type("eye"), _x(x), _y(y) {
	if (!_enemyTexture.loadFromFile("src/Sprites/Monsters_Creatures_Fantasy/Flying eye/Flight.png")) {
		std::cout << "Error: failed to load Eye texture" << std::endl;
	} else {
		std::cout << "Eye texture loaded successfully" << std::endl;
	}
	_enemySprite.setTexture(_enemyTexture);
	_rectEye = sf::IntRect(0, 0, 60, 150);
	_enemySprite.setTextureRect(_rectEye);
	_enemySprite.setPosition(x, y);
}

Eye::Eye(const Eye &other) : Enemy(other) {}

Eye::~Eye() {}

std::string Eye::getType() const {
	return _type;
}

Eye *Eye::clone() const {
	return new Eye(*this);
}

void Eye::attack(Hero hero) {
	hero.setHp(hero.getHp() - getDmg());
	std::cout << getName() << " attacked " << hero.getName() << " for " << getDmg() << std::endl;
}

void Eye::idleAnimation() {
	if (_animClock.getElapsedTime().asSeconds() > 0.15f) {
		int frameCount = 4;
		int spriteWidth = 150;
		int spriteHeight = 150;
		int currentFrame = (_rectEye.left / spriteWidth);
		currentFrame = (currentFrame + 1) % frameCount;
		_rectEye.left = currentFrame * spriteWidth;
		_rectEye.width = spriteWidth;
		_rectEye.height = spriteHeight;
		_rectEye.top = 0;
		_enemySprite.setTextureRect(_rectEye);
		_animClock.restart();
	}
}

sf::Sprite &Eye::getSprite() {
	return _enemySprite;
}
