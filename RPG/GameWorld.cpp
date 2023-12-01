#include "GameWorld.h"

GameWorld::GameWorld(SpriteManager& spriteManager, Player& player)
    : spriteManager(spriteManager), player(player) {
    spriteManager.loadSpriteSheet("ground", "assets/sprites/titles.png", 32, 32);

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Sprite tile = spriteManager.getTile("ground", x % 3, y % 3);
            tile.setPosition(x * 32, y * 32);
            tiles.push_back(tile);
        }
    }

    spriteManager.loadSpriteSheet("player", "assets/sprites/player.png", 32, 32);
    sf::Sprite playerSprite = spriteManager.getTile("player", 0, 0);
    playerSprite.setPosition(100, 100);
    this->playerSprite = playerSprite;
}

void GameWorld::update(float deltaTime) {

}

void GameWorld::render(sf::RenderWindow& window) {
    window.clear();
    for (const auto& tile : tiles) {
        window.draw(tile);
    }
    window.draw(player.getSprite());
}

void GameWorld::updatePlayer(float deltaTime) {
    player.update(deltaTime);
}