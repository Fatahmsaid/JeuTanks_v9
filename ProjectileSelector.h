#ifndef PROJECTILESELECTOR_H
#define PROJECTILESELECTOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ProjectileSelector {
public:
    ProjectileSelector(float x, float y, sf::Font& font);

    void update(sf::Event& event);
    void draw(sf::RenderWindow& window);

    int getSelectedProjectile() const { return selectedProjectile; }
    void decrementQuantity(int player, int projectileType);
    int getPlayerQuantity(int player, int projectileType) const { return playerQuantities[player][projectileType]; }


private:
    struct ProjectileInfo {
        std::string name;
        int maxQuantity;
        sf::RectangleShape icon;
        sf::Texture texture;      // Ajouter une texture pour l'image PNG
    };

    float x, y; // Position du sélecteur
    int selectedProjectile; // Index du projectile actuellement sélectionné
    std::vector<ProjectileInfo> projectiles;
    std::vector<int> playerQuantities[2]; // Quantités pour chaque joueur (0 = joueur 1, 1 = joueur 2)
    sf::Text nameText;
    sf::Text quantityText[2];
    // sf::RectangleShape leftArrow;
    // sf::RectangleShape rightArrow;
    sf::ConvexShape leftArrow;  // Triangle pour flèche gauche
    sf::ConvexShape rightArrow; // Triangle pour flèche droite


    void updateTexts();
};

#endif // PROJECTILESELECTOR_H

