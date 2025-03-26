#include "Background.h"

// Background::Background(const std::string& textureFile) {
//     if (!texture.loadFromFile(textureFile)) {
//         std::cerr << "Erreur : Impossible de charger l'image de fond \"" << textureFile << "\"\n";
//     } else {
//         sprite.setTexture(texture);
//         sprite.setScale(800.0f / texture.getSize().x, 600.0f / texture.getSize().y); // Adapter à la fenêtre
//     }
// }

// void Background::draw(sf::RenderWindow& window) {
//     window.draw(sprite);
// }

Background::Background(const std::string& textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Erreur : Impossible de charger l'image de fond \"" << textureFile << "\"\n";
    } else {
        sprite.setTexture(texture);
    }
}

void Background::draw(sf::RenderWindow& window) {
    // Ajuster la taille du sprite à celle de la fenêtre
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();
    sprite.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );

    window.draw(sprite);
    sprite.setPosition(0, 0);

}
