#include "MenuState.h"
#include "Game.h"

MenuState::MenuState(Game& game) : game(game), selectedOption(0) {
    font.loadFromFile("assets/fonts/Roboto-Regular.ttf");

    options = { "Play", "Settings", "Exit" };

    for (const auto& option : options) {
        sf::Text text(option, font);
        text.setCharacterSize(30); 
        textOptions.push_back(text);
    }

    for (std::size_t i = 0; i < textOptions.size(); ++i) {
        textOptions[i].setPosition(100, 100 + i * 50);
    }
}

void MenuState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Up:
            selectedOption = (selectedOption + options.size() - 1) % options.size();
            break;
        case sf::Keyboard::Down:
            selectedOption = (selectedOption + 1) % options.size();
            break;
        case sf::Keyboard::Enter:
            if (selectedOption == 0) {
                game.switchState("playing");
            }
            else if (selectedOption == 2) {
                
            }
            break;
        case sf::Keyboard::Escape:
            
            break;
        default:
            break;
        }
    }
}


void MenuState::update(float deltaTime) {
}

void MenuState::render(sf::RenderWindow& window) {
    for (std::size_t i = 0; i < textOptions.size(); ++i) {
        if (i == selectedOption) {
            textOptions[i].setFillColor(sf::Color::Red);
        }
        else {
            textOptions[i].setFillColor(sf::Color::White);
        }
        window.draw(textOptions[i]);
    }
}