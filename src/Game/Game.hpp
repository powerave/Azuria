#pragma once

#include <SFML/Graphics.hpp>
#include "../Hero.hpp"
#include "Entities/Enemy.hpp"

class Game {
    private:
        sf::RenderWindow _window;
        bool _isRunning;
        int _animFrame = 0;

        Hero* _Player;
        std::vector<Enemy*> _enemies;

        // Graphismes du joueur
        sf::Texture _playerTexture;
        sf::Sprite _playerSprite;
        sf::IntRect _rectPlayer;
        sf::Clock _animClock;

        void processEvents();
        void update(); //Maj de la logique (physique, stats)
        void render();
        bool handleMovements(bool isMoving);

        void updateEnemies();
        void handleCombat();
        void removeDeadEnemies();
        void spawnEnemies();
    
    public:
        Game();
        ~Game();
        void run();
};
