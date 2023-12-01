#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class SpriteManager {
public:
    SpriteManager();
    bool loadSpriteSheet(const std::string& id, const std::string& filepath, int tileWidth, int tileHeight);
    sf::Sprite getTile(const std::string& sheetId, int x, int y);

private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, std::vector<sf::Sprite>> spriteSheets;
    int tileWidth, tileHeight;
};