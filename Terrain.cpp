#include "Terrain.h"
#include <cmath>

Terrain::Terrain(int width, int height, int groundHeight, const std::string& mapType)
    : width(width), height(height), groundHeight(groundHeight), mapType(mapType) {
    terrainHeights.resize(width, groundHeight);
    terrainImage.create(width, height, sf::Color::Blue); // Initialiser avec le ciel (bleu)
    generateTerrain();
    updateTexture();
}


void Terrain::generateTerrain() {
    sf::Color terrainColor; 

    if (mapType == "Carte: Map 1") {
        terrainColor = sf::Color::White; // Neige
    } else {
        terrainColor = sf::Color(194, 178, 128); // Sable (marron clair)
    }

    for (int x = 0; x < width; ++x) {
        int hillHeight = 0;

        if (mapType == "Carte: Map 1") {
            // Ajout de nombreuses collines (plus de variations)
            hillHeight = static_cast<int>(80 * std::sin(4 * 3.14159 * x / width)); 
        } else {
            // Terrain avec une colline plus douce (désert)
            hillHeight = static_cast<int>(50 * std::sin(2 * 3.14159 * x / width)); 
        }

        terrainHeights[x] = groundHeight - hillHeight;

        for (int y = 0; y < height; ++y) {
            if (y >= terrainHeights[x]) {
                terrainImage.setPixel(x, y, terrainColor); // Sol
            } else {
                terrainImage.setPixel(x, y, sf::Color(0, 0, 0, 0)); // Ciel
            }
        }
    }
}


float Terrain::getHeightAt(float x) const {
    if (x < 0 || x >= width) return height; // En dehors des limites
    return terrainHeights[static_cast<int>(x)];
}

void Terrain::draw(sf::RenderWindow& window) {
    window.draw(terrainSprite);
}

bool Terrain::checkCollision(float x, float y) const {
    // Vérifie si le point est dans les limites du terrain
    if (x < 0 || x >= width || y < 0 || y >= height) return false;

    // Collision seulement si le point est au-dessus de la hauteur actuelle du terrain
    return y >= terrainHeights[static_cast<int>(x)];
}


void Terrain::destroyAround(float x, float y, float radius) {
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            int px = static_cast<int>(x) + i;
            int py = static_cast<int>(y) + j;

            // Vérifie que le point est dans les limites et dans le rayon
            if (px >= 0 && px < width && py >= 0 && py < height &&
                std::sqrt(i * i + j * j) <= radius) {
                // Détruire le terrain seulement si py est en dessous de la hauteur actuelle
                if (py >= terrainHeights[px]) {
                    terrainImage.setPixel(px, py, sf::Color(0, 0, 0, 0)); // Remplacer par le ciel
                    terrainHeights[px] = py; // Met à jour la hauteur du terrain
                }
            }
        }
    }
    updateTexture();
}


void Terrain::updateTexture() {
    terrainTexture.loadFromImage(terrainImage);
    terrainSprite.setTexture(terrainTexture);
}

