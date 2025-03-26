#ifndef PROJECTILESELECTOR_H
#define PROJECTILESELECTOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Classe permettant de gérer la sélection des types de projectiles
class ProjectileSelector {
public:
    // Constructeur : initialise la position, les textes et les icônes du sélecteur
    ProjectileSelector(float x, float y, sf::Font& font);

    // Met à jour l'état du sélecteur en fonction des événements (clics sur les flèches)
    void update(sf::Event& event);

    // Affiche le sélecteur à l'écran (flèches, icônes, textes)
    void draw(sf::RenderWindow& window);

    // Renvoie l'index du projectile actuellement sélectionné
    int getSelectedProjectile() const { return selectedProjectile; }

    // Diminue la quantité d'un type de projectile pour un joueur spécifique
    void decrementQuantity(int player, int projectileType);

    // Renvoie la quantité restante d'un type de projectile pour un joueur spécifique
    int getPlayerQuantity(int player, int projectileType) const { return playerQuantities[player][projectileType]; }


private:
    struct ProjectileInfo {
        std::string name; // Nom du projectile
        int maxQuantity; // Quantité max disponible
        sf::RectangleShape icon; // Icone du projectile
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


    void updateTexts(); // Met à jour les textes affichés (nom et quantités)
};

#endif // PROJECTILESELECTOR_H
