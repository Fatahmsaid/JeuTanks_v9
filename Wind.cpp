#include "Wind.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Wind::Wind(float x, float y, sf::Font& font) : x(x), y(y) {
    // Charger l'icône du vent
    if (!windTexture.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/wind_icon.png")) {
        std::cerr << "Erreur : Impossible de charger l'icône du vent\n";
    }
    windIcon.setTexture(windTexture);
    windIcon.setPosition(x + 990, y+70);
    windIcon.setScale(0.1f, 0.1f); // Ajuster la taille de l'icône

    // Initialiser le texte du vent
    windText.setFont(font);
    windText.setCharacterSize(16);
    windText.setFillColor(sf::Color::White);
    windText.setPosition(x + 950, y+10);

    // Initialiser la flèche de direction
    windArrow.setPointCount(3);
    windArrow.setPoint(0, sf::Vector2f(0, 10));   // Pointe
    windArrow.setPoint(1, sf::Vector2f(20, 0));  // Bas-gauche
    windArrow.setPoint(2, sf::Vector2f(20, 20)); // Bas-droite
    windArrow.setFillColor(sf::Color::White);
    windArrow.setPosition(x + 990, y + 40);

    generateWind();
}

void Wind::generateWind() {
    // Générer une vitesse entre 10 et 100 km/h
    speed = static_cast<float>((10 + rand() % 91)/100);
    // Générer une direction : true = droite, false = gauche
    direction = rand() % 2;

    // Mettre à jour le texte
    windText.setString("Vent: " + std::to_string(static_cast<int>(speed)) + " km/h");

    // Mettre à jour la direction de la flèche
    if (direction) {
        windArrow.setPoint(0, sf::Vector2f(0, 10));  // Pointe vers la droite
        windArrow.setPoint(1, sf::Vector2f(20, 0));  // Bas-gauche
        windArrow.setPoint(2, sf::Vector2f(20, 20)); // Bas-droite
    } else {
        windArrow.setPoint(0, sf::Vector2f(20, 10));  // Pointe vers la gauche
        windArrow.setPoint(1, sf::Vector2f(0, 0));    // Bas-gauche
        windArrow.setPoint(2, sf::Vector2f(0, 20));   // Bas-droite
    }
}

float Wind::getMultiplier() const {
    return direction ? 1.0f + (speed / 100.0f) : 1.0f - (speed / 100.0f);
}

void Wind::draw(sf::RenderWindow& window) const {
    window.draw(windIcon);
    window.draw(windText);
    window.draw(windArrow);
}
