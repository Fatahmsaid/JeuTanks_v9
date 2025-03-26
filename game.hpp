// game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

// Classe principale du menu qui gère la logique et les interaction
class Game {
public:
    Game(); // Constructeur : initialise la fenêtre et charge les ressources nécessaires
    void run(); // Lance la boucle principale du menu

    // Méthodes pour obtenir les sélections des personnages et de la carte
    std::string getSelectedCharacter1() const;
    std::string getSelectedCharacter2() const;
    std::string getSelectedMap() const;

private:
    // Enumération pour les différents états du jeu
    enum GameState { START, SELECT, SELECT_MAP, SHOW_MESSAGE };

    // Structure pour représenter un personnage avec ses caractéristiques
    struct Character {
        std::string name;
        int health;
        int attack;
        int defense;
        std::string spriteFile;
    };

    sf::RenderWindow window;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text startButton;
    sf::RectangleShape simpleRectangle;
    std::vector<sf::Sprite> characters;
    std::vector<sf::Text> characterStats;
    std::vector<sf::Text> MapStats;
    std::vector<sf::Texture> textures, textures2, textures3, mapTextures, mapTextures2;
    std::vector<sf::RectangleShape> backgrounds;
    std::vector<sf::Sprite> maps;
    GameState state;
    std::string selectedCharacter1, selectedCharacter2, selectedMap;
    sf::Clock messageClock;
    int selectedIndex1, selectedIndex2, selectedMapIndex, currentPlayer;
    sf::Text title, title2;

    void setupStartButton();
    void loadCharacters();
    void loadMaps();
    void handleEvents();
    void render();
};

#endif // GAME_HPP

