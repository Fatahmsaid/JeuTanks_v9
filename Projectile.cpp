#include "Projectile.h"
#include <cmath>
#include <iostream>

// Constantes globales
const float GRAVITY = 500.0f;

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

void Projectile::update(float deltaTime) {
    x += vx * deltaTime * 2;
    y += vy * deltaTime * 2;
    vy += GRAVITY * deltaTime;
    shape.setPosition(x, y);
}

void Projectile::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Projectile::isOffScreen(int screenWidth, int screenHeight) const {
    return x < 0 || x > screenWidth || y > screenHeight;
}

void Projectile::applyWindEffect(float multiplier) {
    vx *= multiplier;
}


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

