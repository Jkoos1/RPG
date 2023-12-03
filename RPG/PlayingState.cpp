#include "PlayingState.h"

PlayingState::PlayingState(SpriteManager& spriteManager, sf::RenderWindow& window)
    : gameWorld(spriteManager, player), player(spriteManager) {
}

void PlayingState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Up:
            player.moveUp();
            break;
        case sf::Keyboard::Down:
            player.moveDown();
            break;
        case sf::Keyboard::Left:
            player.moveLeft();
            break;
        case sf::Keyboard::Right:
            player.moveRight();
            break;
        default:
            break;
        }
    }
}

void PlayingState::update(float deltaTime) {
    gameWorld.update(deltaTime); 
}

void PlayingState::render(sf::RenderWindow& window) {
    gameWorld.render(window); 
}