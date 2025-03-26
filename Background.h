#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Background {
public:
    Background(const std::string& textureFile);
    void draw(sf::RenderWindow& window);
    bool isLoaded() const { return texture.getSize().x > 0; } // Vérifie si la texture est chargée

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
