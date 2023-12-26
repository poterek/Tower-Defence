// Map.cpp
#include "Map.h"

// Dodaj do sekcji private w Map.h
std::vector<Enemy> enemies;
float enemySpawnTimer;
const float enemySpawnInterval = 1.f; // Interwa� pojawiania si� przeciwnik�w (1 sekunda)

Map::Map() {
    // Inicjalizacja tekstury dla t�a
    if (!backgroundTexture.loadFromFile("background.jpg")) {
        // Obs�u� b��d �adowania tekstury t�a
        return;
    }

    // Ustaw sprite t�a
    backgroundSprite.setTexture(backgroundTexture);

    // Wsp�rz�dne punkt�w trasy
    sf::Vector2f point1(-100.f, 100.f);
    sf::Vector2f point2(400.f, 100.f);
    sf::Vector2f point3(400.f, 300.f);
    sf::Vector2f point4(200.f, 300.f);
    sf::Vector2f point5(200.f, 500.f);
    sf::Vector2f point6(600.f, 500.f);
    sf::Vector2f point7(600.f, 100.f);
    sf::Vector2f point8(700.f, 100.f);

    // Linia reprezentuj�ca tras�
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
    // Narysuj t�o
    window.draw(backgroundSprite);
    // Narysuj tras�
    window.draw(pathLine);

    // Narysuj przeciwnik�w
    for (auto& enemy : enemies) {
        enemy.render(window);
    }
}

void Map::update(float deltaTime) {
    // Aktualizuj timer dla pojawiania si� przeciwnik�w
    enemySpawnTimer += deltaTime;
    if (enemySpawnTimer >= enemySpawnInterval) {
        spawnEnemy();
        enemySpawnTimer = 0.f; // Zresetuj timer
    }

    // Aktualizuj przeciwnik�w
    for (auto& enemy : enemies) {
        enemy.update(deltaTime);
    }
}

void Map::spawnEnemy() {
    // Dodaj przeciwnika na pocz�tku trasy (punkt1)
    enemies.push_back(Enemy(pathLine[0].position));
}
