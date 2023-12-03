#pragma once

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Game;

class MenuState : public GameState {
public:
    MenuState(Game& game);

    void handleEvent(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    MenuState& operator=(const MenuState&) = delete;
private:
    Game& game;
    int selectedOption;
    std::vector<std::string> options;
    sf::Font font;
    std::vector<sf::Text> textOptions;
};