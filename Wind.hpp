#ifndef WIND_H
#define WIND_H

#include <SFML/Graphics.hpp>
#include <string>

// Génère un vent qui influence la trajectoire des projectiles
class Wind {
public:
    Wind(float x, float y, sf::Font& font); // Constructeur : initialisation de la position et du texte, chargement de l'icône

    void generateWind(); // Générer la vitesse et la direction du vent
    float getMultiplier() const; // Retourne l'effet du vent sur la vitesse
    void draw(sf::RenderWindow& window) const; // Affiche le vent à l'écran

private:
    float speed;       // Vitesse du vent (en km/h)
    bool direction;    // Direction : true = droite, false = gauche
    sf::Text windText; // Texte affichant la vitesse et direction
    sf::Sprite windIcon; // Icône du vent
    sf::Texture windTexture; // Texture pour l'icône
    sf::ConvexShape windArrow; // Flèche indiquant la direction
    float x, y;        // Position d'affichage
};

#endif // WIND_H
