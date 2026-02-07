#include "Game.hpp"
#include "all_Weapons/Bows/Bow.hpp"

void Game::processEvents() {
    sf::Event event;
    while(_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            _window.close();
    }
}

bool Game::handleMovements(bool isMoving) {
    float speed = _Player->getMspeed();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        _playerSprite.move(0, -speed);
        _rectPlayer.top = 0;
        _rectPlayer.left = 5 * 64;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _playerSprite.move(0, speed);
        _rectPlayer.top = 0;
        _rectPlayer.left = 5 * 64;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        _playerSprite.move(-speed, 0);
        _playerSprite.setScale(-1.f, 1.f);
        _rectPlayer.top = 0;
        _rectPlayer.left = 5 * 64;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _playerSprite.move(speed, 0);
        _playerSprite.setScale(1.f, 1.f);
        _rectPlayer.top = 0;
        _rectPlayer.left = 5 * 64;
        isMoving = true;
    }
    return isMoving;
}

void Game::spawnEnemies(float x, float y) {
    _enemies.push_back(new Goblin("Goblin", "Stick", 3, 1.0f, 2.0f, 12, 5, 2.0f, 5.0f, 1, 5, x, y));
	_enemies.push_back(new Skeleton("Skeleton", "Bone Club", 5, 1.5f, 2.5f, 20, 10, 1.5f, 10.0f, 2, 10, x + 100.0f, y + 100.0f));
	_enemies.push_back(new Eye("Eye", "Bite", 4, 1.2f, 3.0f, 15, 20, 2.5f, 7.5f, 1, 8, x - 100.0f, y - 100.0f));
}

void Game::randomSpawnEnemies() {
    float randomX = static_cast<float>(rand() % 2560);
    float randomY = static_cast<float>(rand() % 1440);
    _enemies.push_back(new Goblin("Goblin", "Stick", 3, 1.0f, 2.0f, 12, 5, 2.0f, 5.0f, 1, 5, randomX, randomY));
}

void Game::updateEnemies() {
    for (Enemy* enemy : _enemies) {
        if (Goblin *goblin = dynamic_cast<Goblin*>(enemy))
            goblin->idleAnimation();
		if (Skeleton *skeleton = dynamic_cast<Skeleton*>(enemy))
			skeleton->idleAnimation();
		if (Eye *eye = dynamic_cast<Eye*>(enemy))
			eye->idleAnimation();
    }
}

void Game::updateProjectiles() {
    static sf::Clock deltaClock;
    float deltaTime = deltaClock.restart().asSeconds();
    for (auto it = _projectiles.begin(); it != _projectiles.end();) {
        Projectile* proj = *it;
        proj->update(deltaTime);
        
        bool shouldRemove = false;
        for (Enemy *enemy : _enemies) {
            if (proj->hasReachTarget(*enemy, *_Player)) {
                shouldRemove = true;
                break;
            }
        }
        if (!shouldRemove && proj->exceedRange())
            shouldRemove = true;
        if (shouldRemove) {
            delete proj;
            it = _projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

void Game::handleAttack() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Weapon *leftWeapon = _Player->getLeftWeapon();
        Weapon *rightWeapon = _Player->getRightWeapon();
        if (!rightWeapon && !leftWeapon)
            return;
        float range;
        float atkSpeed;
        if (rightWeapon) {
            range = rightWeapon->getRange();
            atkSpeed = rightWeapon->getAs();
        } else {
            range = leftWeapon->getRange();
            atkSpeed = leftWeapon->getAs();
        }
        if (_atkClock.getElapsedTime().asSeconds() < atkSpeed)
            return;
        sf::Vector2i mousePixel = sf::Mouse::getPosition(_window);
        sf::Vector2f mousePos(static_cast<float>(mousePixel.x), static_cast<float>(mousePixel.y));
        sf::Vector2f heroPos = _playerSprite.getPosition();
        sf::Vector2f direction = mousePos - heroPos;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0) {
            direction /= length; // vitesse fixe de projectile quelle que soit la distance

            Arrow *arrow = new Arrow(2.0f, heroPos.x, heroPos.y, mousePos.x, mousePos.y, range);
            _projectiles.push_back(arrow);
        }
    }
}

void Game::handleCombat() {
    
}

void Game::removeDeadEnemies() {
    for (auto it = _enemies.begin(); it != _enemies.end();) {
        if ((*it)->getHp() <= 0) {
            delete *it;
            it = _enemies.erase(it);
        } else {
            ++it;
        }
    }
}

void Game::update() {
    bool isMoving = false;
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);

    if (_enemies.empty())
        randomSpawnEnemies();
    handleAttack();
    handleCombat();
    updateProjectiles();
    updateEnemies();
    removeDeadEnemies();
    isMoving = handleMovements(isMoving);
    if (isMoving) {
        if (_animClock.getElapsedTime().asSeconds() > 0.1f) {
            _animFrame = (_animFrame + 1) % 8;
            _animClock.restart();
        }
        _rectPlayer.left = _animFrame * 64;
    } else {
        if (_animClock.getElapsedTime().asSeconds() > 0.3f) {
            _animFrame = (_animFrame + 1) % 4;
            _animClock.restart();
        }
        _rectPlayer.left = _animFrame * 64;
        _rectPlayer.top = 5 * 64;
    }
    _playerSprite.setTextureRect(_rectPlayer);
}

void Game::render() {
    sf::Color kaki(60, 80, 40);
    _window.clear(kaki);
    _window.draw(_playerSprite);
    for (Enemy* enemy : _enemies)
        _window.draw(enemy->getSprite());
    for (Projectile *projectile : _projectiles)
        _window.draw(projectile->getSprite());
    _window.display();
}

Game::Game() {
    _window.create(sf::VideoMode(2560, 1440), "Azuria");
    _window.setFramerateLimit(144);
    _isRunning = true;

    Bag AdvanturerBag;
    std::map<std::string, Gear*> Gears;
    std::map<std::string, Weapon*> Weapons;

    _Player = new Hero("Sylvana", AdvanturerBag, 50, 16, 13, 18, Gears, Weapons);

    Bow* startingBow = new Bow("Shortbow", "Bow", 10, 500.0f, 2, 2);
    _Player->equipTwoHands(startingBow);
    if (!_playerTexture.loadFromFile("src/Sprites/Arcane archer/spritesheet.png")) {
        std::cout << "ERREUR: Impossible de charger l'image du heros !" << std::endl;
        // Fallback: carré vert si image pas trouvée
        // Mais pour l'instant on garde le sprite vide ou on verra
    }
    _playerSprite.setTexture(_playerTexture);
    _playerSprite.setOrigin(32, 32);
    _playerSprite.setPosition(400, 300); // Au milieu
    _rectPlayer = sf::IntRect(0, 320, 64, 64);
    _playerSprite.setTextureRect(_rectPlayer);
    spawnEnemies(500, 300);
    spawnEnemies(700, 400);
    spawnEnemies(900, 500);
}

Game::~Game() {}

void Game::run() {
    while (_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}
