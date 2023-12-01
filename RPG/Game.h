#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "PauseState.h"
#include <map>
#include <memory>

class Game {
public:
    Game();
    void run();
    void switchState(const std::string& stateName);

private:
    sf::RenderWindow window;
    std::map<std::string, std::unique_ptr<GameState>> states;
    GameState* currentState;
    SpriteManager spriteManager;

    void processEvents();
    void update(float deltaTime);
    void render();
};