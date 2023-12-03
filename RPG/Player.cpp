#include "Player.h"

Player::Player(SpriteManager& spriteManager) : x(0), y(0) {
    spriteManager.loadSpriteSheet("player", "assets/sprites/player.png", 32, 32);
    sf::Sprite playerSprite = spriteManager.getTile("player", 0, 0);
    this->sprite = playerSprite;
}

void Player::update(float deltaTime) {
    sprite.setPosition(x, y);
}

void Player::moveUp() {
    y -= moveDistance;
}

void Player::moveDown() {
    y += moveDistance;
}

void Player::moveLeft() {
    x -= moveDistance;
}

void Player::moveRight() {
    x += moveDistance;
}

sf::Sprite& Player::getSprite() {
    return sprite;
}
