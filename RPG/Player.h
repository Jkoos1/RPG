#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();

    void update(float deltaTime);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    sf::Sprite& getSprite();

private:
    int x, y; 
    sf::Sprite sprite;
};