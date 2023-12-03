#include "Game.h"

Game::Game() : window(sf::VideoMode(800u, 600u), "RPG Game"), currentState(nullptr), event() {
    window.setFramerateLimit(FRAMERATE_LIMIT);
    states["menu"] = std::make_unique<MenuState>(*this);
    states["playing"] = std::make_unique<PlayingState>(spriteManager, window);
    states["paused"] = std::make_unique<PauseState>();

    currentState = states["menu"].get();
}

void Game::run() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            currentState->handleEvent(event);
        }
        sf::Time dt = clock.restart();
        currentState->update(dt.asSeconds());
        render();
    }
}

void Game::update(float deltaTime) {
    currentState->update(deltaTime);
}

void Game::render() {
    window.clear();
    currentState->render(window);  
    window.display();
}

void Game::switchState(const std::string& stateName) {
    auto it = states.find(stateName);
    if (it != states.end()) {
        currentState = it->second.get();
    }
}