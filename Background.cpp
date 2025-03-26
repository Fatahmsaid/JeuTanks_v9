#include "Background.hpp"


// Constructeur de la classe Background, charge l'image de fond à partir d'un fichier
Background::Background(const std::string& textureFile) {
    // Tente de charger la texture à partir du fichier donné
    if (!texture.loadFromFile(textureFile)) {
        // Affiche une erreur si le fichier ne peut pas être chargé
        std::cerr << "Erreur : Impossible de charger l'image de fond \"" << textureFile << "\"\n";
    } else {
        // Associe la texture au sprite si le chargement a réussi
        sprite.setTexture(texture);
    }
}

// Dessine l'arrière-plan dans la fenêtre
void Background::draw(sf::RenderWindow& window) {
    // Récupère les dimensions de la fenêtre et de la texture
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();
    
    // Ajuste l'échelle du sprite pour qu'il remplisse toute la fenêtre
    sprite.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );

    // Positionne le sprite en haut à gauche de la fenêtre et le dessine
    window.draw(sprite);
    sprite.setPosition(0, 0);

}

