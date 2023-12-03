#pragma once

#include "GameState.h"
#include "GameWorld.h"

class PlayingState : public GameState {
public:
    PlayingState(SpriteManager& spriteManager, sf::RenderWindow& window);

    void handleEvent(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    GameWorld gameWorld;
    Player player;
};