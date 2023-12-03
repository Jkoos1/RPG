#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"

class Player {
public:
    Player(SpriteManager& spriteManager);

    void update(float deltaTime);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    sf::Sprite& getSprite();

private:
    float x, y; 
    float moveDistance = 32.0f;
    sf::Sprite sprite;
};