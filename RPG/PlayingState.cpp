#include "PlayingState.h"

PlayingState::PlayingState(SpriteManager& spriteManager)
    : gameWorld(spriteManager, player) {
}

void PlayingState::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void PlayingState::update(float deltaTime) {
    gameWorld.update(deltaTime); 
}

void PlayingState::render(sf::RenderWindow& window) {
    gameWorld.render(window); 
}