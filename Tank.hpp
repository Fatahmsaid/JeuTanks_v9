#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"
#include "Terrain.hpp"

// Classe représentant un tank dans le jeu
class Tank {
public:
    // Constructeur du tank : position (x, y) et texture
    Tank(float x, float y, const std::string& textureFile);

    // Dessine le tank dans la fenêtre
    void draw(sf::RenderWindow& window);

    // Tire un projectile, passé sous forme de vecteur de projectiles uniques
    void shoot(std::vector<std::unique_ptr<Projectile>>& projectiles, float angle, float speed);

    // Met à jour la position du tank en fonction du terrain
    void updatePosition(const Terrain& terrain);

    // Déplace le tank horizontalement en prenant en compte les limites du terrain
    void move(float deltaX, const Terrain& terrain);

    // Réduit la vie du tank en fonction des dégâts subis
    void reduceHealth(float damage);

    // Vérifie si le tank est mort (vie <= 0)
    bool isDead() const;

    // Met à jour la barre de vie graphique
    void updateHealthBar(sf::Font& font);

    // Dessine la barre de vie et le pourcentage de vie à l'écran
    void drawHealthBar(sf::RenderWindow& window, sf::Font& font);

    // Dessine l'indicateur de rotation du tank (triangle rouge)
    void drawTurnIndicator(sf::RenderWindow& window);

    // Accesseurs pour récupérer la position du tank
    float getX() const { return x; }
    float getY() const { return y; }

private:
    float x, y; // Position du tank
    float health = 100.0f; // Points de vie du tank
    sf::RectangleShape body; // Forme du corps du tank
    sf::Texture texture; // Ajout d'une texture pour le tank
    sf::RectangleShape healthBar; // Barre de vie graphique
    sf::Text healthText; // Texte pour afficher le pourcentage de vie
    sf::ConvexShape triangle; // Indicateur du joueur actif 
};

#endif
