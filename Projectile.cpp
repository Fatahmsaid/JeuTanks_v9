#include "Projectile.hpp"
#include <cmath>
#include <iostream>

// Constantes globales
const float GRAVITY = 500.0f; // Gravité, à modifier selon ressenti du gameplay

// Classe de base Projectile
Projectile::Projectile(float x, float y, float angle, float speed)
    : x(x), y(y) {
    float radians = angle * 3.14159f / 180.0f;
    vx = speed * cos(radians);
    vy = -speed * sin(radians);
    shape.setRadius(5.0f);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
}

// Met à jour la trajectoire du projectile
void Projectile::update(float deltaTime) {
    x += vx * deltaTime * 2;
    y += vy * deltaTime * 2;
    vy += GRAVITY * deltaTime;
    shape.setPosition(x, y);
}

// Dessine le projectile
void Projectile::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

// Détermine si le projectile sors de l'écran
bool Projectile::isOffScreen(int screenWidth, int screenHeight) const {
    return x < 0 || x > screenWidth || y > screenHeight;
}

// Applique l'effet du vent
void Projectile::applyWindEffect(float multiplier) {
    vx *= multiplier;
}

// Classes dérivées de Projectile:

// SmallMissile
SmallMissile::SmallMissile(float x, float y, float angle, float speed)
    : Projectile(x, y, angle, speed) {
    shape.setFillColor(sf::Color::Red);
}

// AtomicBomb
AtomicBomb::AtomicBomb(float x, float y, float angle, float speed)
    : Projectile(x, y, angle, speed) {
    shape.setFillColor(sf::Color::Yellow);
    shape.setRadius(10.0f);
}

// VolcanoBomb
VolcanoBomb::VolcanoBomb(float x, float y, float angle, float speed)
    : Projectile(x, y, angle, speed) {
    shape.setFillColor(sf::Color::Blue);
}

