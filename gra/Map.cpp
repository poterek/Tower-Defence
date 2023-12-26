// Map.cpp
#include "Map.h"

// Dodaj do sekcji private w Map.h
std::vector<Enemy> enemies;
float enemySpawnTimer;
const float enemySpawnInterval = 1.f; // Interwa³ pojawiania siê przeciwników (1 sekunda)

Map::Map() {
    // Inicjalizacja tekstury dla t³a
    if (!backgroundTexture.loadFromFile("background.jpg")) {
        // Obs³u¿ b³¹d ³adowania tekstury t³a
        return;
    }

    // Ustaw sprite t³a
    backgroundSprite.setTexture(backgroundTexture);

    // Wspó³rzêdne punktów trasy
    sf::Vector2f point1(-100.f, 100.f);
    sf::Vector2f point2(400.f, 100.f);
    sf::Vector2f point3(400.f, 300.f);
    sf::Vector2f point4(200.f, 300.f);
    sf::Vector2f point5(200.f, 500.f);
    sf::Vector2f point6(600.f, 500.f);
    sf::Vector2f point7(600.f, 100.f);
    sf::Vector2f point8(700.f, 100.f);

    // Linia reprezentuj¹ca trasê
    pathLine.setPrimitiveType(sf::LineStrip);
    pathLine.resize(8);
    pathLine[0].position = point1;
    pathLine[1].position = point2;
    pathLine[2].position = point3;
    pathLine[3].position = point4;
    pathLine[4].position = point5;
    pathLine[5].position = point6;
    pathLine[6].position = point7;
    pathLine[7].position = point8;

    for (std::size_t i = 0; i < pathLine.getVertexCount(); ++i) {
        pathLine[i].color = sf::Color::Blue;
    }
}

void Map::draw(sf::RenderWindow& window) {
    // Narysuj t³o
    window.draw(backgroundSprite);
    // Narysuj trasê
    window.draw(pathLine);

    // Narysuj przeciwników
    for (auto& enemy : enemies) {
        enemy.render(window);
    }
}

void Map::update(float deltaTime) {
    // Aktualizuj timer dla pojawiania siê przeciwników
    enemySpawnTimer += deltaTime;
    if (enemySpawnTimer >= enemySpawnInterval) {
        spawnEnemy();
        enemySpawnTimer = 0.f; // Zresetuj timer
    }

    // Aktualizuj przeciwników
    for (auto& enemy : enemies) {
        enemy.update(deltaTime);
    }
}

void Map::spawnEnemy() {
    // Dodaj przeciwnika na pocz¹tku trasy (punkt1)
    enemies.push_back(Enemy(pathLine[0].position));
}
