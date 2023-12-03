#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "PauseState.h"

class Game {
public:
    Game();
    void run();
    void switchState(const std::string& stateName);
    Game& operator=(const Game&) = delete;

private:
    sf::RenderWindow window;
    std::map<std::string, std::unique_ptr<GameState>> states;
    GameState* currentState;

    const int FRAMERATE_LIMIT = 60;

    sf::Clock clock;
    sf::Event event;

    SpriteManager spriteManager;

    void update(float deltaTime);
    void render();
};