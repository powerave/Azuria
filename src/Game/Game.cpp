#include "Game.hpp"

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

void Game::update() {
    bool isMoving = false;

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
    _window.clear(sf::Color::Black);
    _window.draw(_playerSprite);
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
}

Game::~Game() {}

void Game::run() {
    while (_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}
