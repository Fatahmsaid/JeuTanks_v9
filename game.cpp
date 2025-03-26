#include "game.hpp"
#include <iostream>
#include <stdexcept>

Game::Game() : window(sf::VideoMode(800, 600), "ROBOTS WAR"), state(START), selectedIndex1(0), selectedIndex2(0), selectedMapIndex(0), currentPlayer(1) {
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        throw std::runtime_error("Impossible de charger la police.");
    }
    if (!backgroundTexture.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/fond_decran.png")) {
        throw std::runtime_error("Impossible de charger l'image de fond.");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setColor(sf::Color(255, 255, 255, 130)); // alpha = 178 (255 * 0.3)
    setupStartButton();
    loadCharacters();
    loadMaps();
}

void Game::setupStartButton() {
    startButton.setFont(font);
    startButton.setString("Start");
    startButton.setCharacterSize(70);
    startButton.setFillColor(sf::Color::Black);
    startButton.setPosition(300, 250);

    simpleRectangle.setSize(sf::Vector2f(300, 80));
    simpleRectangle.setPosition(250, 256);  // Positionner le rectangle juste en dessous du bouton
    simpleRectangle.setFillColor(sf::Color(255, 255, 255, 200)); // Semi-transparente
}

void Game::loadCharacters() {
    
      
    int spacingX = 200;
    int startY = 250;
    
    title.setFont(font);
    title.setString("Selection de personnages");
    title.setCharacterSize(35);
    title.setFillColor(sf::Color::White);
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition((800 - titleBounds.width) / 2, 20);
    
    // Charger et définir les informations pour chaque personnage manuellement
    // Personnage 1
    sf::Texture texture1;
    if (!texture1.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/personnage1.png")) {
        throw std::runtime_error("Impossible de charger l'image personnage1.png");
    }
    textures.push_back(texture1);
    sf::Sprite sprite1(textures.back());
    sprite1.setPosition(160, startY);
    characters.push_back(sprite1);

    sf::Text stats1;
    stats1.setFont(font);
    stats1.setCharacterSize(15);
    stats1.setFillColor(sf::Color::White);
    stats1.setString("Nom: E-Lyes\nVie: 100\nAttaque: 20\nDefense: 10");
    stats1.setPosition(150, startY + 100);
    characterStats.push_back(stats1);

     // Ajouter un rectangle semi-transparent derrière le personnage 1
sf::RectangleShape background1(sf::Vector2f(texture1.getSize().x +20, 20 +texture1.getSize().y));
background1.setPosition(160-10, startY -10);
background1.setFillColor(sf::Color(255, 255, 255, 50)); // Carré noir semi-transparent (alpha = 128)
backgrounds.push_back(background1);

    // Personnage 2
    sf::Texture texture2;
    if (!texture2.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/personnage2.png")) {
        throw std::runtime_error("Impossible de charger l'image personnage2.png");
    }
    textures2.push_back(texture2);
    sf::Sprite sprite2(textures2.back());
    sprite2.setPosition(360, startY);
    characters.push_back(sprite2);

    sf::Text stats2;
    stats2.setFont(font);
    stats2.setCharacterSize(15);
    stats2.setFillColor(sf::Color::White);
    stats2.setString("Nom: Fatator \nVie: 90\nAttaque: 25\nDefense: 13");
    stats2.setPosition(350, startY + 100);
    characterStats.push_back(stats2);


    sf::RectangleShape background2(sf::Vector2f(texture2.getSize().x +20, 20 +texture2.getSize().y));
    background2.setPosition(360-10, startY -10);
    background2.setFillColor(sf::Color(255, 255, 255, 50)); // Carré noir semi-transparent (alpha = 128)
    backgrounds.push_back(background2);

    // Personnage 3
    sf::Texture texture3;
    if (!texture3.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/personnage3.png")) {
        throw std::runtime_error("Impossible de charger l'image personnage3.png");
    }
    textures3.push_back(texture3);
    sf::Sprite sprite3(textures3.back());
    sprite3.setPosition(560, startY);
    characters.push_back(sprite3);

    sf::Text stats3;
    stats3.setFont(font);
    stats3.setCharacterSize(15);
    stats3.setFillColor(sf::Color::White);
    stats3.setString("Nom: Nacimus Prime\nVie: 80\nAttaque: 30\nDefense: 15");
    stats3.setPosition(550, startY + 100);
    characterStats.push_back(stats3);



    sf::RectangleShape background3(sf::Vector2f(texture3.getSize().x +20, 20 +texture3.getSize().y));
    background3.setPosition(560-10, startY -10);
    background3.setFillColor(sf::Color(255, 255, 255, 50)); // Carré noir semi-transparent (alpha = 128)
    backgrounds.push_back(background3);
}

void Game::loadMaps() {
    
    

        
    title2.setFont(font);
    title2.setString("Selection des maps");
    title2.setCharacterSize(35);
    title2.setFillColor(sf::Color::White);
    sf::FloatRect title2Bounds = title2.getLocalBounds();
    title2.setPosition((800 - title2Bounds.width) / 2, 20);


    sf::Text stats4;
    stats4.setFont(font);
    stats4.setCharacterSize(15);
    stats4.setFillColor(sf::Color::White);
    stats4.setString("MAP 1 : Montagne\nPaysage vallonne et enneige\nDifficulte : * * * *"); 
    stats4.setPosition(60,410);
    MapStats.push_back(stats4);

    sf::Text stats5;
    stats5.setFont(font);
    stats5.setCharacterSize(15);
    stats5.setFillColor(sf::Color::White);
    stats5.setString("MAP 2 : Desert\nPaysage plat et aride\nDifficulte : * *"); 
    stats5.setPosition(450,410);
    MapStats.push_back(stats5);

    sf::Texture texture6;
        if (!texture6.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/map1.png")) {
            throw std::runtime_error("Impossible de charger l'image map2.png");
        }
        mapTextures.push_back(texture6);
        sf::Sprite sprite6(mapTextures.back());
        sprite6.setPosition(60, 230);  // Position de la deuxième carte (décalée par rapport à la première)
        maps.push_back(sprite6);

        // Charger la première carte
        sf::Texture texture4;
        if (!texture4.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/map2.png")) {
            throw std::runtime_error("Impossible de charger l'image map1.png");
        }
        mapTextures2.push_back(texture4);
        sf::Sprite sprite3(mapTextures2.back());
        sprite3.setPosition(450, 230);  // Position de la première carte
        maps.push_back(sprite3);
    

}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (state == START && event.key.code == sf::Keyboard::Enter) {
                state = SELECT;
            } else if (state == SELECT) {
                int& selectedIndex = (currentPlayer == 1) ? selectedIndex1 : selectedIndex2;
                if (event.key.code == sf::Keyboard::Left) {
                    selectedIndex = (selectedIndex - 1 + characters.size()) % characters.size();
                } else if (event.key.code == sf::Keyboard::Right) {
                    selectedIndex = (selectedIndex + 1) % characters.size();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    if (currentPlayer == 1) {
                        selectedCharacter1 = "Joueur 1: Personnage " + std::to_string(selectedIndex1 + 1);
                        currentPlayer = 2;
                    } else {
                        selectedCharacter2 = "Joueur 2: Personnage " + std::to_string(selectedIndex2 + 1);
                        state = SELECT_MAP;
                    }
                }
            } else if (state == SELECT_MAP) {
                if (event.key.code == sf::Keyboard::Left) {
                    selectedMapIndex = (selectedMapIndex - 1 + maps.size()) % maps.size();
                } else if (event.key.code == sf::Keyboard::Right) {
                    selectedMapIndex = (selectedMapIndex + 1) % maps.size();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    selectedMap = "Carte: Map " + std::to_string(selectedMapIndex + 1);
                    state = SHOW_MESSAGE;
                }
            }
        }
    }
}

void Game::render() {
    window.clear();
    window.draw(backgroundSprite);

    if (state == START) {
        window.draw(simpleRectangle);
        window.draw(startButton);
    } else if (state == SELECT) {
        window.draw(title);
        for (size_t i = 0; i < characters.size(); ++i) {
            if (i == selectedIndex1) {
                characters[i].setColor(sf::Color::Red);
            } else if (i == selectedIndex2) {
                characters[i].setColor(sf::Color::Blue);
            } else {
                characters[i].setColor(sf::Color::White);
            }
            window.draw(backgrounds[i]);
            window.draw(characters[i]);
            window.draw(characterStats[i]);
        }
    } else if (state == SELECT_MAP) {
        window.draw(title2);
        for (size_t i = 0; i < maps.size(); ++i) {
            if (i == selectedMapIndex) {
                maps[i].setColor(sf::Color::Red);
            } else {
                maps[i].setColor(sf::Color::White);
            }
            window.draw(maps[i]);
            window.draw(MapStats[i]);
        }
    } else if (state == SHOW_MESSAGE) {
        sf::Text message(selectedCharacter1 + "\n" + selectedCharacter2 + "\n" + selectedMap, font, 30);
        message.setFillColor(sf::Color::White);
        message.setPosition(200, 250);
        window.draw(message);
        if (messageClock.getElapsedTime().asSeconds() > 6) {
            window.close();
        }
    }

    window.display();
}

std::string Game::getSelectedCharacter1() const {
    return selectedCharacter1;
}

std::string Game::getSelectedCharacter2() const {
    return selectedCharacter2;
}

std::string Game::getSelectedMap() const {
    return selectedMap;
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}
