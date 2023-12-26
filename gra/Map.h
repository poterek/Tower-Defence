// Map.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"  // Dodaj nag��wek Enemy.h

class Map {
public:
    Map();
    void update(float deltaTime);  // Dodaj funkcj� update
    void draw(sf::RenderWindow& window);

private:
    sf::VertexArray pathLine;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    // Dodaj nowe zmienne
    std::vector<Enemy> enemies;
    float enemySpawnTimer;
    const float enemySpawnInterval = 1.f;

    // Dodaj now� funkcj�
    void spawnEnemy();
};
