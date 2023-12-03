#include "GameWorld.h"

GameWorld::GameWorld(SpriteManager& spriteManager, Player& player)
    : spriteManager(spriteManager), player(player) {
    spriteManager.loadSpriteSheet("ground", "assets/sprites/titles.png", 32, 32);

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            sf::Sprite tile = spriteManager.getTile("ground", x % 3, y % 3);
            tile.setPosition(static_cast<float>(x * 32), static_cast<float>(y * 32));
            tiles.push_back(tile);
        }
    }

    view.setSize(sf::Vector2f(800, 600));
}

void GameWorld::update(float deltaTime) {
    player.update(deltaTime);
    view.setCenter(player.getSprite().getPosition());
}

void GameWorld::render(sf::RenderWindow& window) {
    window.setView(view);
    sf::Vector2u windowSize = window.getSize();

    sf::FloatRect tileBounds = tiles[0].getLocalBounds();
    sf::Vector2f tileSize(tileBounds.width, tileBounds.height);

    int tilesX = windowSize.x / tileSize.x;
    int tilesY = windowSize.y / tileSize.y;

    for (int y = 0; y <= tilesY; ++y) {
        for (int x = 0; x <= tilesX; ++x) {
            tiles[0].setPosition(x * tileSize.x, y * tileSize.y);
            window.draw(tiles[0]);
        }
    }
    window.draw(player.getSprite());
    window.setView(window.getDefaultView());
}