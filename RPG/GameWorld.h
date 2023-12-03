#pragma once

#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "Player.h"

class GameWorld {
public:
    GameWorld(SpriteManager& spriteManager, Player& player);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    SpriteManager& spriteManager;
    Player& player;
    std::vector<sf::Sprite> tiles;
    int tilesX = 0, tilesY = 0;
    sf::Sprite tileSprite;
    sf::View view;
};