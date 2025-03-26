#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>
#include <string>

enum class ExplosionType {
    SmallMissile,
    AtomicBomb,
    VolcanoBomb
};

class Explosion {
public:
    Explosion(float x, float y, ExplosionType type);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isFinished() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect animationRect;
    float animationTimer = 0.0f;
    int currentFrame = 0;
    int totalFrames;
    float frameDuration;

    void loadExplosionSprite(ExplosionType type); //
};

#endif // EXPLOSION_H
