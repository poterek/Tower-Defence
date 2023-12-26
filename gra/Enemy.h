// Enemy.h
#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(const sf::Vector2f& spawnPoint);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};
