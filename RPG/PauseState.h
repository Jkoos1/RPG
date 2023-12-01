#pragma once

#include "GameState.h"

class PauseState : public GameState {
public:
    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};