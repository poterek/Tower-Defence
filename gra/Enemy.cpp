// Enemy.cpp
#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& spawnPoint) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(spawnPoint);

    // Ustaw domyœln¹ prêdkoœæ
    velocity = sf::Vector2f(50.f, 0.f);
}


void Enemy::update(float deltaTime) {
    // Aktualizacja pozycji przeciwnika
    shape.move(velocity * deltaTime);
}
void Enemy::render(sf::RenderWindow& window) {
    window.draw(shape);
}