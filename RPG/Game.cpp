#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "RPG Game"), currentState(nullptr) {
    states["menu"] = std::make_unique<MenuState>(*this);
    states["playing"] = std::make_unique<PlayingState>(spriteManager);
    states["paused"] = std::make_unique<PauseState>();

    currentState = states["menu"].get();
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        currentState->handleInput(window);
        currentState->update(dt.asSeconds());
        currentState->render(window);
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else {
            currentState->handleInput(window);
        }
    }
}

void Game::update(float deltaTime) {
    currentState->update(deltaTime);
}

void Game::render() {
    window.clear();
    window.display();
    currentState->render(window);  
}

void Game::switchState(const std::string& stateName) {
    auto it = states.find(stateName);
    if (it != states.end()) {
        currentState = it->second.get();
    }
}