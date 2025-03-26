#ifndef TERRAIN_H
#define TERRAIN_H

#include <SFML/Graphics.hpp>
#include <vector>

// Génère un terrain 
class Terrain {
public:
    // Constructeur : initialise la taille et le type de terrain, puis génère le terrain
    Terrain(int width, int height, int groundHeight, const std::string& mapType);

    // Dessine le terrain sur la fenêtre
    void draw(sf::RenderWindow& window);

    // Vérifie s'il y a une collision avec le terrain aux coordonnées (x, y)
    bool checkCollision(float x, float y) const;

    // Détruit une partie du terrain autour d'un point (x, y) avec un rayon donné
    void destroyAround(float x, float y, float radius);

    // Renvoie la hauteur du terrain à une position donnée (sur l'axe x)
    float getHeightAt(float x) const;

    // Retourne la largeur du terrain
    int getWidth() const { return width; }

    // Retourne la hauteur totale du terrain
    int getHeight() const { return height; }

private:
    int width;                      // Largeur totale du terrain
    int height;                     // Hauteur totale du terrain
    int groundHeight;               // Hauteur initiale du sol
    std::vector<int> terrainHeights; // Hauteur du terrain pour chaque colonne

    sf::Image terrainImage;         // Image représentant le terrain
    sf::Texture terrainTexture;     // Textur associée au terrain
    sf::Sprite terrainSprite;       // Sprite associé à la texture du terrain

    // Génère la forme initiale du terrain
    void generateTerrain();

    // Met à jour la texture SFML du terrain après une modification
    void updateTexture();

    std::string mapType;

};

#endif
