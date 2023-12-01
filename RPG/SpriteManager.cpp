#include "SpriteManager.h"

SpriteManager::SpriteManager() : tileWidth(0), tileHeight(0) {}

bool SpriteManager::loadSpriteSheet(const std::string& id, const std::string& filepath, int tileWidth, int tileHeight) {
    sf::Texture texture;
    if (!texture.loadFromFile(filepath)) {
        return false;
    }

    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    textures[id] = texture; // Store the texture

    // Calculate rows and columns
    int rows = texture.getSize().y / tileHeight;
    int columns = texture.getSize().x / tileWidth;

    // Create sprites for each tile
    std::vector<sf::Sprite> tiles;
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            sf::Sprite sprite;
            sprite.setTexture(textures[id]);
            sprite.setTextureRect(sf::IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight));
            tiles.push_back(sprite);
        }
    }

    spriteSheets[id] = tiles;
    return true;
}

sf::Sprite SpriteManager::getTile(const std::string& sheetId, int x, int y) {
    if (spriteSheets.find(sheetId) != spriteSheets.end() && x >= 0 && y >= 0) {
        int columns = textures[sheetId].getSize().x / tileWidth;
        return spriteSheets[sheetId][y * columns + x];
    }
    else {
        throw std::runtime_error("Tile or sprite sheet not found: " + sheetId);
    }
}