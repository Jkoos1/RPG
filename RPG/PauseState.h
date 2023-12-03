#pragma once

#include "GameState.h"

class PauseState : public GameState {
public:
    void handleEvent(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};