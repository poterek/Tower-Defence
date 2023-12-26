#include "Map.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense Game");

    Map gameMap;

    // G³ówna pêtla gry
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        // Wywo³aj funkcjê do rysowania mapy
        gameMap.draw(window);
        window.display();
    }

    return 0;
}
