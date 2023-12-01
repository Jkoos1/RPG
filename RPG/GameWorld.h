#pragma once

#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "Player.h"

class GameWorld {
public:
    GameWorld(SpriteManager& spriteManager, Player& player);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    void updatePlayer(float deltaTime);

private:
    SpriteManager& spriteManager;
    std::vector<sf::Sprite> tiles;
    // Additional world elements like entities, obstacles, etc.
    sf::Sprite playerSprite;
    Player player;
};