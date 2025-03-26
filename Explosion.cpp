#include "Explosion.h"
#include <iostream>

Explosion::Explosion(float x, float y, ExplosionType type)
    : totalFrames(12), frameDuration(0.05f) { // Par défaut, 6 frames et 0.1s par frame
    loadExplosionSprite(type);
    sprite.setPosition(x - animationRect.width / 2, y - animationRect.height / 2); // Centrer l'explosion
}

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



// void Explosion::draw(sf::RenderWindow& window) {
//     window.draw(sprite);
// }

void Explosion::draw(sf::RenderWindow& window) {
    std::cout << "Dessiner l'explosion à la position (" 
              << sprite.getPosition().x << ", " << sprite.getPosition().y << ")" << std::endl;
    window.draw(sprite);
}


bool Explosion::isFinished() const {
    return currentFrame >= totalFrames;
}
