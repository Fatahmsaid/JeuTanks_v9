#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"
#include "Terrain.h"

class Tank {
public:
    Tank(float x, float y, const std::string& textureFile);
    void draw(sf::RenderWindow& window);
    //void shoot(std::vector<Projectile>& projectiles, float angle, float speed);
    void shoot(std::vector<std::unique_ptr<Projectile>>& projectiles, float angle, float speed);
    void updatePosition(const Terrain& terrain); // Met à jour la position en fonction du terrain
    void move(float deltaX, const Terrain& terrain);
    void reduceHealth(float damage);
    bool isDead() const;
    void updateHealthBar(sf::Font& font);
    void drawHealthBar(sf::RenderWindow& window, sf::Font& font); 
    void drawTurnIndicator(sf::RenderWindow& window);



    float getX() const { return x; }
    float getY() const { return y; }



private:
    float x, y;
    float health = 100.0f; // Points de vie du tank
    sf::RectangleShape body;
    sf::Texture texture; // Ajout d'une texture pour le tank
    sf::RectangleShape healthBar; // Barre de vie graphique
    sf::Text healthText; // Texte pour afficher le pourcentage de vie
    sf::ConvexShape triangle; // Indicateur du joueur actif 
};

#endif

