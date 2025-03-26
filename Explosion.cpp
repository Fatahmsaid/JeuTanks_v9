#include "Explosion.hpp"
#include <iostream>

// Constructeur de la classe Explosion
// Initialise une explosion à une position donnée et configure les frames d'animation
Explosion::Explosion(float x, float y, ExplosionType type)
    : totalFrames(12), frameDuration(0.05f) { // Selon l'image trouvée, ici 12 frames et 0.05s par frame
    loadExplosionSprite(type);
    sprite.setPosition(x - animationRect.width / 2, y - animationRect.height / 2); // Centrer l'explosion
}

// Charge la feuille de sprites pour le type d'explosion spécifié
void Explosion::loadExplosionSprite(ExplosionType type) {
    std::string spriteSheet;
    switch (type) {
        case ExplosionType::SmallMissile:
            spriteSheet = "/home/fatah/Téléchargements/JeuTanks_v9/small_missile_explosion.png";
            break;
        case ExplosionType::AtomicBomb:
            spriteSheet = "/home/fatah/Téléchargements/JeuTanks_v9/atomic_bomb_explosion.png";
            break;
        case ExplosionType::VolcanoBomb:
            spriteSheet = "/home/fatah/Téléchargements/JeuTanks_v9/volcano_bomb_explosion.png";
            break;
    }

    if (!texture.loadFromFile(spriteSheet)) {
        std::cerr << "Erreur : Impossible de charger la feuille de sprites pour l'explosion\n";
        std::cerr << "Chemin utilisé : " << spriteSheet << std::endl;
    }
    sprite.setTexture(texture);

    // Configurer l'animation
    animationRect = sf::IntRect(
    currentFrame * (texture.getSize().x / totalFrames), // Décalage horizontal
    0,                                                 // Pas de décalage vertical
    texture.getSize().x / totalFrames,                 // Largeur d'une frame
    texture.getSize().y                                 // Hauteur totale de l'image
    );

    
    sprite.setTextureRect(animationRect);
}

// Met à jour l'animation en fonction du temps écoulé
void Explosion::update(float deltaTime) {
    animationTimer += deltaTime;

    // Passe à la frame suivante après `frameDuration`
    if (animationTimer >= frameDuration) {
        animationTimer = 0.0f; // Réinitialise le timer
        currentFrame++;

        // Boucle ou arrête l'animation après la dernière frame
        if (currentFrame < totalFrames) {
            animationRect.left = currentFrame * animationRect.width; // Si horizontal
            // animationRect.top = currentFrame * animationRect.height; // Si vertical
            sprite.setTextureRect(animationRect);
        }
    }
}

// Dessine l'explosion sur la fenêtre
void Explosion::draw(sf::RenderWindow& window) {
    std::cout << "Dessiner l'explosion à la position (" 
              << sprite.getPosition().x << ", " << sprite.getPosition().y << ")" << std::endl;
    window.draw(sprite);
}

// Vérifie si l'animation est terminée (toutes les frames ont été jouées)
bool Explosion::isFinished() const {
    return currentFrame >= totalFrames;
}
