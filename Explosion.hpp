#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>
#include <string>

// Enumération pour définir les types d'explosions, correspondant aux différents projectiles
enum class ExplosionType {
    SmallMissile,
    AtomicBomb,
    VolcanoBomb
};

// Classe qui gère les animations d'explosion
class Explosion {
public:
    // Constructeur : initialise une explosion à une position donnée et pour un type spécifique
    Explosion(float x, float y, ExplosionType type);

    // Met à jour l'animation de l'explosion en fonction du temps écoulé
    void update(float deltaTime);
    
    // Affiche l'explosion dans la fenêtre.
    void draw(sf::RenderWindow& window);
    
    // Indique si l'animation de l'explosion est terminée
    bool isFinished() const;

private:

    sf::Sprite sprite;      // Sprite utilisé pour afficher l'explosion
    sf::Texture texture;    // Texture associée au sprite
    sf::IntRect animationRect; // Rect définissant la portion de texture affichée à chaque frame
    float animationTimer = 0.0f; // Chronomètre pour gérer les frames de l'animation
    int currentFrame = 0;      // Frame actuelle de l'animation
    int totalFrames;           // Nombre total de frames dans l'animation
    float frameDuration;       // Durée d'affichage de chaque frame

    // Charge la feuille de sprites et configure l'animation pour un type d'explosion donné
    void loadExplosionSprite(ExplosionType type);
};

#endif // EXPLOSION_H
