#pragma once

#include <SFML/Graphics.hpp>
#include "../Hero.hpp"
#include "../Entities/Goblin.hpp"
#include "../Entities/Skeleton.hpp"
#include "../Entities/Eye.hpp"
#include "../Entities/Enemy.hpp"
#include "../all_Weapons/Bows/Skills/Arrow.hpp"
#include <cmath>

class Game {
    private:
        sf::RenderWindow _window;
        bool _isRunning;
        int _animFrame = 0;

        Hero* _Player;
        std::vector<Enemy*> _enemies;
		std::vector<Projectile*> _projectiles;

        // Graphismes du joueur
        sf::Texture _playerTexture;
        sf::Sprite _playerSprite;
        sf::IntRect _rectPlayer;
        sf::Clock _animClock;
        sf::Clock _atkClock;

        void processEvents();
        void update(); //Maj de la logique (physique, stats)
        void render();
        bool handleMovements(bool isMoving);

        void updateEnemies();
        void updateProjectiles();
        void handleAttack();
        void handleCombat();
        void removeDeadEnemies();
        void spawnEnemies(float x, float y);
        void randomSpawnEnemies();
    
    public:
        Game();
        ~Game();
        void run();
};
