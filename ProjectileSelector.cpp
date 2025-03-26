#include "ProjectileSelector.h"
#include <iostream>

ProjectileSelector::ProjectileSelector(float x, float y, sf::Font& font)
    : x(x), y(y), selectedProjectile(0) {
    // Définition des projectiles
    projectiles = {
        {"Small Missile", 99, sf::RectangleShape(sf::Vector2f(40, 40))},
        {"Atomic Bomb", 1, sf::RectangleShape(sf::Vector2f(40, 40))},
        {"Volcano Bomb", 5, sf::RectangleShape(sf::Vector2f(40, 40))}
    };

    if (!projectiles[0].texture.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/small_missile.png")) {
        std::cerr << "Erreur : Impossible de charger l'icône du Small Missile\n";
    }
    projectiles[0].icon.setTexture(&projectiles[0].texture);

    if (!projectiles[1].texture.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/atomic_bomb.png")) {
        std::cerr << "Erreur : Impossible de charger l'icône de l'Atomic Bomb\n";
    }
    projectiles[1].icon.setTexture(&projectiles[1].texture);

    if (!projectiles[2].texture.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/volcano_bomb.png")) {
        std::cerr << "Erreur : Impossible de charger l'icône du Volcano Bomb\n";
    }
    projectiles[2].icon.setTexture(&projectiles[2].texture);


    // Initialisation des quantités pour chaque joueur
    for (int i = 0; i < 2; ++i) {
        for (const auto& proj : projectiles) {
            playerQuantities[i].push_back(proj.maxQuantity);
        }
    }

    // Initialisation des textes
    nameText.setFont(font);
    nameText.setCharacterSize(18);
    nameText.setFillColor(sf::Color::White);
    nameText.setPosition(x + 1300, y + 10);

    for (int i = 0; i < 2; ++i) {
        quantityText[i].setFont(font);
        quantityText[i].setCharacterSize(14);
        quantityText[i].setFillColor(sf::Color::White);
        quantityText[i].setPosition(x + 1320, y + 80 + i * 20);
    }

    // Initialisation des flèches
    // leftArrow.setSize(sf::Vector2f(20, 20));
    // leftArrow.setFillColor(sf::Color::White);
    // leftArrow.setPosition(x + 1250 , y + 10);

    // rightArrow.setSize(sf::Vector2f(20, 20));
    // rightArrow.setFillColor(sf::Color::White);
    // rightArrow.setPosition(x + 1450, y + 10);

    // Flèche gauche (triangle noir)
    leftArrow.setPointCount(3);
    leftArrow.setPoint(0, sf::Vector2f(0, 10));   // Pointe
    leftArrow.setPoint(1, sf::Vector2f(20, 0));  // Bas-gauche
    leftArrow.setPoint(2, sf::Vector2f(20, 20)); // Bas-droite
    leftArrow.setFillColor(sf::Color::Black);
    leftArrow.setPosition(x + 1250, y + 10);

    // Flèche droite (triangle noir)
    rightArrow.setPointCount(3);
    rightArrow.setPoint(0, sf::Vector2f(20, 10));   // Pointe
    rightArrow.setPoint(1, sf::Vector2f(0, 0));    // Bas-gauche
    rightArrow.setPoint(2, sf::Vector2f(0, 20));   // Bas-droite
    rightArrow.setFillColor(sf::Color::Black);
    rightArrow.setPosition(x + 1450, y + 10);


    // Mise à jour des textes
    updateTexts();
}

void ProjectileSelector::update(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        float mouseX = static_cast<float>(event.mouseButton.x);
        float mouseY = static_cast<float>(event.mouseButton.y);

        // Gestion des flèches
        if (leftArrow.getGlobalBounds().contains(mouseX, mouseY)) {
            selectedProjectile = (selectedProjectile - 1 + projectiles.size()) % projectiles.size();
            updateTexts();
        } else if (rightArrow.getGlobalBounds().contains(mouseX, mouseY)) {
            selectedProjectile = (selectedProjectile + 1) % projectiles.size();
            updateTexts();
        }
        
    }
}

void ProjectileSelector::draw(sf::RenderWindow& window) {
    // Dessiner les flèches
    window.draw(leftArrow);
    window.draw(rightArrow);

    // Dessiner le nom du projectile
    window.draw(nameText);

    // Dessiner les quantités pour chaque joueur
    for (int i = 0; i < 2; ++i) {
        window.draw(quantityText[i]);
    }

    // Dessiner l'icône du projectile
    auto& icon = projectiles[selectedProjectile].icon;
    icon.setPosition(x + 1350, y + 40);
    window.draw(icon);
}


void ProjectileSelector::decrementQuantity(int player, int projectileType) {
    if (playerQuantities[player][projectileType] > 0) {
        playerQuantities[player][projectileType]--;
        updateTexts();
    }
}

void ProjectileSelector::updateTexts() {
    // Mettre à jour le nom
    nameText.setString(projectiles[selectedProjectile].name);

    // Mettre à jour les quantités
    for (int i = 0; i < 2; ++i) {
        quantityText[i].setString("Player " + std::to_string(i + 1) + ": " +
                                  std::to_string(playerQuantities[i][selectedProjectile]));
    }
}
