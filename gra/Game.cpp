// Game.cpp
#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Tower Defense Game"), enemy(sf::Vector2f(-100.f, 100.f)) {
    // Inicjalizacja obiektów, tak jak w Twoim kodzie
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    // Obs³uga zdarzeñ, tak jak w Twoim kodzie
}

void Game::update() {
    float deltaTime = clock.restart().asSeconds();  // Dodaj tê liniê, aby obliczyæ deltaTime
    enemy.update(deltaTime);  // Przekazuj deltaTime do funkcji update przeciwnika
    map.update(deltaTime);    // Dodaj to, aby aktualizowaæ mapê
}

void Game::render() {
    window.clear();
    // Renderowanie elementów gry, tak jak w Twoim kodzie
    map.draw(window);
    // Narysuj inne elementy
    window.display();
}
