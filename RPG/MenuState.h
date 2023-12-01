#pragma once

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Game;

class MenuState : public GameState {
public:
    MenuState(Game& game);

    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    Game& game;
    std::vector<std::string> options;
    int selectedOption;
    sf::Font font;
    std::vector<sf::Text> textOptions;
};