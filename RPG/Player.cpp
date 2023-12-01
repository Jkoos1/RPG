#include "Player.h"

Player::Player() : x(0), y(0) {
}

void Player::update(float deltaTime) {
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}

void Player::moveUp() {
    y -= 1;
}

void Player::moveDown() {
    y += 1; 
}

void Player::moveLeft() {
    x -= 1;
}

void Player::moveRight() {
    x += 1; 
}

sf::Sprite& Player::getSprite() {
    return sprite;
}