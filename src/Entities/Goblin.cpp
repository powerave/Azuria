#include "../../Includes/Entities/Goblin.hpp"

Goblin::Goblin(std::string name, std::string primaryWeapon, float x, float y, int dmg, float as, float range, int hp, int mana, float ms, float crit, int lvl, int exp) 
    : Enemy(name, primaryWeapon, x, y, dmg, as, range, hp, mana, ms, crit, lvl, exp) {
        _x = x;
        _y = y;
        _hitboxOffset = {60.f, 50.f};
        if (!_enemyTexture.loadFromFile("Sprites/Monsters_Creatures_Fantasy/Goblin/Idle.png")) {
            std::cout << "Error: failed to load Goblin texture" << std::endl;
        } else {
            std::cout << "Goblin texture loaded successfully" << std::endl;
        }
        _enemySprite.setTexture(_enemyTexture);
        _rectGoblin = sf::IntRect(0, 0, 150, 150);
        _enemySprite.setTextureRect(_rectGoblin);
        _enemySprite.setPosition(x, y);
        _hitbox = sf::FloatRect(x, y, 40, 60);
}

Goblin::Goblin(const Goblin &other) : Enemy(other) {}

Goblin::~Goblin() {}

std::string Goblin::getType() const {
    return _type;
}

Goblin* Goblin::clone() const {
    return new Goblin(*this);
}

void Goblin::attack(Hero hero) {
    hero.setHp(hero.getHp() - getDmg());
    std::cout << getName() << " attacked " << hero.getName() << " for " << getDmg() << std::endl;
}

void Goblin::idleAnimation() {
    if (_animClock.getElapsedTime().asSeconds() > 0.15f) {
        int frameCount = 4;
        int spriteWidth = 150;
        int spriteHeight = 150;
        int currentFrame = (_rectGoblin.left / spriteWidth);
        currentFrame = (currentFrame + 1) % frameCount;
        _rectGoblin.left = currentFrame * spriteWidth;
        _rectGoblin.width = spriteWidth;
        _rectGoblin.height = spriteHeight;
        _rectGoblin.top = 0;
        _enemySprite.setTextureRect(_rectGoblin);
        _animClock.restart();
    }
}

sf::Sprite& Goblin::getSprite() {
    return _enemySprite;
}
