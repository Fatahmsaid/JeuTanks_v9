#include "Tank.h"
#include "Terrain.h"
#include <iostream>

Tank::Tank(float x, float y, const std::string& textureFile) : x(x), y(y) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Erreur : Impossible de charger l'image \"" << textureFile << "\"\n";
    }
    body.setSize(sf::Vector2f(90, 60));
    body.setTexture(&texture); // Applique la texture
    body.setPosition(x, y);
}


// Tank::Tank(float x, float y) : x(x), y(y) {
//     body.setSize(sf::Vector2f(50, 20));
//     body.setPosition(x, y);
//     body.setFillColor(sf::Color::Green);
// }

void Tank::draw(sf::RenderWindow& window) {
    window.draw(body);
}

// void Tank::shoot(std::vector<Projectile>& projectiles) {
//     float angle = 45.0f; // Angle de tir par défaut
//     float speed = 200.0f; // Vitesse du projectile
//     projectiles.emplace_back(x + body.getSize().x / 2, y, angle, speed);
// }

// void Tank::shoot(std::vector<Projectile>& projectiles, float angle, float speed) {
//     projectiles.emplace_back(x + body.getSize().x / 2, y, angle, speed);
// }

void Tank::shoot(std::vector<std::unique_ptr<Projectile>>& projectiles, float angle, float speed) {
    projectiles.emplace_back(std::make_unique<SmallMissile>(x + body.getSize().x / 2, y, angle, speed));
}



void Tank::updatePosition(const Terrain& terrain) {
    float terrainHeight = terrain.getHeightAt(x + body.getSize().x / 2);
    y = terrainHeight - body.getSize().y; // Placer le tank juste au-dessus du terrain
    body.setPosition(x, y);
}

void Tank::move(float deltaX, const Terrain& terrain) {
    // Mettre à jour la position horizontale
    x += deltaX;

    // S'assurer que le tank reste dans les limites du terrain
    if (x < 0) x = 0;
    if (x + body.getSize().x > terrain.getWidth()) {
        x = terrain.getWidth() - body.getSize().x;
    }

    // Ajuster la position verticale pour que le tank reste au-dessus du terrain
    float terrainHeight = terrain.getHeightAt(x + body.getSize().x / 2);
    y = terrainHeight - body.getSize().y;

    // Mettre à jour la position graphique
    body.setPosition(x, y);
}

// Réduit la vie du tank
void Tank::reduceHealth(float damage) {
    health -= damage;
    if (health < 0) health = 0;
}

// Vérifie si le tank est mort
bool Tank::isDead() const {
    return health <= 0;
}

// Met à jour la barre de vie
void Tank::updateHealthBar(sf::Font& font) {
    healthBar.setSize(sf::Vector2f(50 * (health / 100.0f), 5)); // Largeur proportionnelle à la vie
    if (health <= 30) {
        healthBar.setFillColor(sf::Color::Red);
    } else {
        healthBar.setFillColor(sf::Color::Green);
    }
}

// Dessine la barre de vie
// void Tank::drawHealthBar(sf::RenderWindow& window, sf::Font& font) {
//     window.draw(healthBar);
//     healthText.setFont(font);
//     healthText.setString(std::to_string(static_cast<int>(health)) + "%");
//     healthText.setPosition(healthBar.getPosition().x, healthBar.getPosition().y - 20); 
//     healthText.setCharacterSize(12);

//     healthBar.setSize(sf::Vector2f(50 * (health / 100.0f), 5));
//     healthBar.setFillColor(sf::Color::Green);
//     healthBar.setPosition(body.getPosition().x, body.getPosition().y - 10);



//     window.draw(healthText);
// }

//void Tank::drawHealthBar(sf::RenderWindow& window, const sf::Font& font) {
void Tank::drawHealthBar(sf::RenderWindow& window, sf::Font& font) {
    // Position la barre de vie au-dessus du tank
    float healthBarWidth = 50.0f; // Largeur fixe de la barre
    float healthBarHeight = 10.0f; // Hauteur fixe de la barre

    // Calcul de la position de la barre (au-dessus du corps du tank)
    sf::Vector2f healthBarPos(25+body.getPosition().x - healthBarWidth / 2, body.getPosition().y - 20);

    // Ajuste la taille de la barre en fonction de la santé
    sf::RectangleShape healthBarBackground(sf::Vector2f(healthBarWidth, healthBarHeight));
    healthBarBackground.setPosition(healthBarPos);
    healthBarBackground.setFillColor(sf::Color::Red); // Arrière-plan rouge (vie perdue)

    sf::RectangleShape healthBarForeground(sf::Vector2f(healthBarWidth * (health / 100.0f), healthBarHeight));
    healthBarForeground.setPosition(healthBarPos);
    healthBarForeground.setFillColor(sf::Color::Green); // Barre verte (vie restante)

    // Dessine les éléments
    window.draw(healthBarBackground);
    window.draw(healthBarForeground);

    // Affichage du pourcentage de vie
    sf::Text healthText;
    healthText.setFont(font);
    healthText.setCharacterSize(10);
    healthText.setFillColor(sf::Color::White);
    healthText.setString(std::to_string(static_cast<int>(health)) + "%");
    healthText.setPosition(healthBarPos.x + healthBarWidth / 2 - healthText.getGlobalBounds().width / 2,
                           healthBarPos.y - 12); // Juste au-dessus de la barre de vie

    window.draw(healthText);
}

void Tank::drawTurnIndicator(sf::RenderWindow& window) {
    // Créer un triangle rouge
    sf::ConvexShape triangle;

    float triangleWidth = 50.0f; // Largeur fixe triangle

    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(body.getPosition().x + triangleWidth / 2 - 5, body.getPosition().y - 80)); // Base gauche
    triangle.setPoint(1, sf::Vector2f(body.getPosition().x + triangleWidth / 2 + 5, body.getPosition().y - 80)); // Base droite
    triangle.setPoint(2, sf::Vector2f(body.getPosition().x + triangleWidth / 2, body.getPosition().y - 60)); // Pointe
    triangle.setFillColor(sf::Color::Red);
    
    // Dessiner le triangle
    window.draw(triangle);
}

