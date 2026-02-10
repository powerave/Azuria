#include "../../../Includes/all_Weapons/Bows/Bow.hpp"
#include "../../../Includes/Hero.hpp"
#include "../../../Includes/Entities/Enemy.hpp"
#include <cmath>

Bow::Bow(std::string name, std::string type, int dmg, float range, float as, int hands) : Weapon(name, type, dmg, range, as, hands) {}

void Bow::attack(Enemy &target, Hero &hero) {
    sf::Vector2f heroPos = sf::Vector2f(hero.getX(), hero.getY());
    sf::Vector2f enemyPos = sf::Vector2f(target.getX(), target.getY());
    float distance = std::sqrt(std::pow(enemyPos.x - heroPos.y, 2) + std::pow(enemyPos.y - heroPos.y, 2));
    
    
}

Bow::~Bow() {}

Weapon* Bow::clone() const {
    return new Bow(*this);
}