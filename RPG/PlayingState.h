#pragma once

#include "GameState.h"
#include "GameWorld.h"

class PlayingState : public GameState {
public:
    PlayingState(SpriteManager& spriteManager);

    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    GameWorld gameWorld;
    Player player;
};