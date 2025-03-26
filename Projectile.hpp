#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Explosion.hpp"

// Classe de base abstraite pour représenter un projectile générique
class Projectile {
public:
    // Constructeur : initialise les paramètres de position, d'angle et de vitesse
    Projectile(float x, float y, float angle, float speed);

    // Destructeur virtuel pour garantir une destruction correcte des sous-classes
    virtual ~Projectile() = default;

    virtual void update(float deltaTime); // Met à jour la position du projectile en fonction du temps écoulé
    virtual void draw(sf::RenderWindow& window); // Affiche le projectile dans la fenêtre
    virtual bool isOffScreen(int screenWidth, int screenHeight) const; // Vérifie si le projectile est sorti de l'écran

    // Méthodes virtuelles pures pour les caractéristiques spécifiques des projectiles
    virtual float getDamage() const = 0;              // Renvoie les dégâts infligés
    virtual float getExplosionRadius() const = 0;     // Renvoie le rayon d'explosion
    virtual ExplosionType getExplosionType() const = 0; // Renvoie le type d'explosion (polymorphisme)

    virtual void applyWindEffect(float multiplier); // Appliquer l'effet du vent

    // Accesseurs pour la position du projectile
    float getX() const { return x; }
    float getY() const { return y; }

protected:
    float x, y;          // Position aactuelle du projectile
    float vx, vy;        // Vitesse
    sf::CircleShape shape; // Représentation graphique du projectile (cercle)
};

// Sous-classe représentant un projectile de type "Small Missile"
class SmallMissile : public Projectile {
public:
    SmallMissile(float x, float y, float angle, float speed);
    float getDamage() const override { return 35.0f; } // Dégâts
    float getExplosionRadius() const override { return 20.0f; } // Rayon d'explosion
    ExplosionType getExplosionType() const override { return ExplosionType::SmallMissile; }
};

// Sous-classe représentant un projectile de type "Atomic Bomb"
class AtomicBomb : public Projectile {
public:
    AtomicBomb(float x, float y, float angle, float speed);
    float getDamage() const override { return 100.0f; } // Dégâts
    float getExplosionRadius() const override { return 50.0f; } // Rayon d'explosion
    ExplosionType getExplosionType() const override { return ExplosionType::AtomicBomb; }
};

// Sous-classe représentant un projectile de type "Volcano Bomb"
class VolcanoBomb : public Projectile {
public:
    VolcanoBomb(float x, float y, float angle, float speed);
    float getDamage() const override { return 50.0f; } // Dégâts
    float getExplosionRadius() const override { return 30.0f; } // Rayon d'explosion
    ExplosionType getExplosionType() const override { return ExplosionType::VolcanoBomb; }
};

#endif // PROJECTILE_H


