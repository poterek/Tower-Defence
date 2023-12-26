// Game.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Enemy.h"

class Game {
public:
    Game();
    void run();

private:
    sf::Clock clock;
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    Map map;
    Enemy enemy;
    // Dodaj inne zmienne i metody, jeœli s¹ potrzebne
};
