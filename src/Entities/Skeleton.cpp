#include "Skeleton.hpp"

Skeleton::Skeleton(std::string name, std::string primaryWeapon, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp, float x, float y)
	: Enemy(name, primaryWeapon, dmg, as, range, hp, mana, ms, crit, lvl, exp), _type("Skeleton"), _x(x), _y(y) {
	if (!_enemyTexture.loadFromFile("src/Sprites/Monsters_Creatures_Fantasy/Skeleton/Idle.png")) {
		std::cout << "Error: failed to load Skeleton texture" << std::endl;
	} else {
		std::cout << "Skeleton texture loaded successfully" << std::endl;
	}
	_enemySprite.setTexture(_enemyTexture);
	_rectSkeleton = sf::IntRect(0, 0, 60, 150);
	_enemySprite.setTextureRect(_rectSkeleton);
	_enemySprite.setPosition(x, y);
}

Skeleton::Skeleton(const Skeleton &other) : Enemy(other) {}

Skeleton::~Skeleton() {}

std::string Skeleton::getType() const {
	return _type;
}

Skeleton *Skeleton::clone () const {
	return new Skeleton(*this);
}

void Skeleton::attack(Hero hero) {
	hero.setHp(hero.getHp() - getDmg());
	std::cout << getName() << " attacked " << hero.getName() << " for " << getDmg() << std::endl;
}

void Skeleton::idleAnimation() {
	if (_animClock.getElapsedTime().asSeconds() > 0.15f) {
		int frameCount = 4;
		int spriteWidth = 150;
		int spriteHeight = 150;
		int currentFrame = (_rectSkeleton.left / spriteWidth);
		currentFrame = (currentFrame + 1) % frameCount;
		_rectSkeleton.left = currentFrame * spriteWidth;
		_rectSkeleton.width = spriteWidth;
		_rectSkeleton.height = spriteHeight;
		_rectSkeleton.top = 0;
		_enemySprite.setTextureRect(_rectSkeleton);
		_animClock.restart();
	}
}

sf::Sprite &Skeleton::getSprite() {
	return _enemySprite;
}