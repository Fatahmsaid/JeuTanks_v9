#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

// Classe qui gère l'arrière-plan du jeu
class Background {
public:
    // Constructeur : charge une image à partir d'un fichier pour l'utiliser comme arrière-plan
    Background(const std::string& textureFile);
    // Affiche l'arrière-plan dans la fenêtre donnée
    void draw(sf::RenderWindow& window);
    // Vérifie si la texture a été correctement chargée
    bool isLoaded() const { return texture.getSize().x > 0; } // Vérifie si la texture est chargée

private:
    sf::Texture texture; // Texture pour l'image de fond
    sf::Sprite sprite; // Sprite associé à la texture
};

#endif
