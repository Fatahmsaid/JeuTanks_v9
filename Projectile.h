#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Explosion.h"

class Projectile {
public:
    Projectile(float x, float y, float angle, float speed);
    virtual ~Projectile() = default;

    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window);
    virtual bool isOffScreen(int screenWidth, int screenHeight) const;

    virtual float getDamage() const = 0;
    virtual float getExplosionRadius() const = 0;
    virtual ExplosionType getExplosionType() const = 0; // polymorphisme

    virtual void applyWindEffect(float multiplier); // Appliquer l'effet du vent


    float getX() const { return x; }
    float getY() const { return y; }

protected:
    float x, y;          // Position
    float vx, vy;        // Vitesse
    sf::CircleShape shape; // Représentation graphique
};

class SmallMissile : public Projectile {
public:
    SmallMissile(float x, float y, float angle, float speed);
    float getDamage() const override { return 35.0f; }
    float getExplosionRadius() const override { return 20.0f; }
    ExplosionType getExplosionType() const override { return ExplosionType::SmallMissile; }
};

class AtomicBomb : public Projectile {
public:
    AtomicBomb(float x, float y, float angle, float speed);
    float getDamage() const override { return 100.0f; }
    float getExplosionRadius() const override { return 50.0f; }
    ExplosionType getExplosionType() const override { return ExplosionType::AtomicBomb; }
};

class VolcanoBomb : public Projectile {
public:
    VolcanoBomb(float x, float y, float angle, float speed);
    float getDamage() const override { return 50.0f; }
    float getExplosionRadius() const override { return 30.0f; }
    ExplosionType getExplosionType() const override { return ExplosionType::VolcanoBomb; }
};

#endif // PROJECTILE_H
