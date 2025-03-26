#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
#include <iostream>
#include "Tank.h"
#include "Projectile.h"
#include "Terrain.h"
#include "Background.h"
#include "Slider.h"
#include "ProjectileSelector.h" 
#include "Explosion.h"
#include "Wind.h"
#include "game.hpp"
#include <filesystem>



int main() {
    sf::Music music1;
    if (!music1.openFromFile("/home/fatah/Téléchargements/JeuTanks_v9/Gran_Turismo_4_1.ogg")) { // Remplacez par le chemin de votre premier fichier audio
        std::cerr << "Erreur lors du chargement du premier fichier audio." << std::endl;
        return -1;
    }

    sf::Music music2;
    if (!music2.openFromFile("/home/fatah/Téléchargements/JeuTanks_v9/gow.ogg")) { // Remplacez par le chemin de votre premier fichier audio
        std::cerr << "Erreur lors du chargement du premier fichier audio." << std::endl;
        return -1;
    }

    // Démarrer la première musique
    music1.play();
    std::cout << "Première musique en cours de lecture... Appuyez sur Enter pour arrêter et charger une nouvelle musique." << std::endl;


    Game game;
    game.run();

    

    std::cout << "Personnage 1 sélectionné : " << game.getSelectedCharacter1() << std::endl;
    std::cout << "Personnage 2 sélectionné : " << game.getSelectedCharacter2() << std::endl;
    std::cout << "Carte sélectionnée : " << game.getSelectedMap() << std::endl;

    music1.stop();

    music2.play();
    std::cout << "Deuxième musique en cours de lecture... Appuyez sur Enter pour arrêter et charger une nouvelle musique." << std::endl;


    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Tanks Game", sf::Style::Close);
    window.setFramerateLimit(60);

    // Déterminer l'image de fond en fonction de la sélection du joueur
    std::string selectedMap = game.getSelectedMap();
    std::string backgroundFile;

    if (selectedMap == "Carte: Map 1") {
        backgroundFile = "/home/fatah/Téléchargements/JeuTanks_v9/map11.png";  // Fichier correspondant à la Map 1
    } else if (selectedMap == "Carte: Map 2") {
        backgroundFile = "/home/fatah/Téléchargements/JeuTanks_v9/map22.png";  // Fichier correspondant à la Map 2
    } else {
        backgroundFile = "/home/fatah/Téléchargements/JeuTanks_v9/background.png";  // Valeur par défaut au cas où
    }

    // Charger l'arrière-plan en fonction de la sélection
    Background background(backgroundFile);
    if (!background.isLoaded()) {
        std::cerr << "Erreur : L'image de fond " << backgroundFile << " n'a pas pu être chargée." << std::endl;
        return -1;
    }


    // Charger la police pour les sliders, les barres de vie et le sélecteur
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police." << std::endl;
        return -1;
    }

    Wind wind(50, 10, font); //Charger le vent

    // Créer les sliders pour la vitesse et l'angle
    Slider speedSlider(50, 50, 200, 100, 800, "Power", font); // Speed MinValue = 100 MaxValue = 800
    Slider angleSlider(50, 100, 200, 180, 0, "Angle", font);

    // Ajouter le sélecteur de type de projectile
    ProjectileSelector selector(10, 10, font);

    // Déterminer l'image du tank en fonction du personnage sélectionné
    std::string selectedCharacter1 = game.getSelectedCharacter1();
    std::string selectedCharacter2 = game.getSelectedCharacter2();

    std::string playerTankFile;
    std::string enemyTankFile;

    if (selectedCharacter1 == "Joueur 1: Personnage 1") {
        playerTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/tank_elyes.png";  // Tank correspondant à E-Lyes
    } else if (selectedCharacter1 == "Joueur 1: Personnage 2") {
        playerTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/tank_fatator.png";  // Tank correspondant à Fatator
    } else if (selectedCharacter1 == "Joueur 1: Personnage 3") {
        playerTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/tank_nacimus.png";  // Tank correspondant à Nacimus Prime
    } else {
        playerTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/player_tank.png";  // Valeur par défaut
    }

    if (selectedCharacter2 == "Joueur 2: Personnage 1") {
        enemyTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/tank_elyes.png";  
    } else if (selectedCharacter2 == "Joueur 2: Personnage 2") {
        enemyTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/tank_fatator.png";  
    } else if (selectedCharacter2 == "Joueur 2: Personnage 3") {
        enemyTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/tank_nacimus.png";  
    } else {
        enemyTankFile = "/home/fatah/Téléchargements/JeuTanks_v9/enemy_tank.png";  // Valeur par défaut
    }

    // Charger les tanks avec les textures sélectionnées
    Tank playerTank(100, 500, playerTankFile);
    Tank enemyTank(500, 500, enemyTankFile);


    // Initialiser le terrain et les projectiles
    Terrain terrain(1600, 1000, 800, game.getSelectedMap());

    sf::View gameView(sf::FloatRect(0, 0, terrain.getWidth(), terrain.getHeight()));
    window.setView(gameView);

    std::vector<std::unique_ptr<Projectile>> projectiles; // Utilisation de pointeurs polymorphiques
    std::vector<Explosion> explosions;


    // Initialiser les barres de vie
    playerTank.reduceHealth(0); // Initialise la vie à 100%
    playerTank.updateHealthBar(font);
    enemyTank.reduceHealth(0);
    enemyTank.updateHealthBar(font);

    bool playerTurn = true;
    int currentPlayer = 1; // 1 pour Player 1, 2 pour Player 2

    //std::cout << "Répertoire de travail actuel : " << std::filesystem::current_path() << std::endl; //Debug sprites



    // Charger la texture de la flèche
    sf::Texture arrowTexture;
    if (!arrowTexture.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/fleche.png")) {
    std::cerr << "Erreur : Impossible de charger la texture de la flèche." << std::endl;
    return -1;
    }

    // Créer le sprite de la flèche
    sf::Sprite arrowSprite;
    arrowSprite.setTexture(arrowTexture);
    arrowSprite.setOrigin(arrowTexture.getSize().x / 2, arrowTexture.getSize().y / 2); // Origine au centre de la flèche

    // Définir la position fixe de la flèche
    arrowSprite.setPosition(160, 200); 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            speedSlider.update(event);
            angleSlider.update(event);
            selector.update(event);

            // Tirer un projectile
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                float angle = angleSlider.value;
                float speed = speedSlider.value;

                // Vérifier le type de projectile sélectionné et sa quantité
                int projectileType = selector.getSelectedProjectile();
                int playerIndex = playerTurn ? 0 : 1;

                if (projectileType >= 0 && selector.getPlayerQuantity(playerIndex, projectileType) > 0) {
                    if (projectileType == 0) {
                        // Small Missile
                        projectiles.emplace_back(std::make_unique<SmallMissile>(
                            playerTurn ? playerTank.getX() : enemyTank.getX(),
                            playerTurn ? playerTank.getY() : enemyTank.getY(),
                            angle, speed));
                    } else if (projectileType == 1) {
                        // Atomic Bomb
                        projectiles.emplace_back(std::make_unique<AtomicBomb>(
                            playerTurn ? playerTank.getX() : enemyTank.getX(),
                            playerTurn ? playerTank.getY() : enemyTank.getY(),
                            angle, speed));
                    } else if (projectileType == 2) {
                        // Volcano Bomb
                        projectiles.emplace_back(std::make_unique<VolcanoBomb>(
                            playerTurn ? playerTank.getX() : enemyTank.getX(),
                            playerTurn ? playerTank.getY() : enemyTank.getY(),
                            angle, speed));
                    }

                    // Réduire la quantité de projectiles disponibles
                    selector.decrementQuantity(playerIndex, projectileType);

                    // Changer de joueur
                    currentPlayer = playerTurn ? 2 : 1;
                    playerTurn = !playerTurn;
                } else {
                    // Si la quantité est insuffisante, afficher un message ou ignorer l'action
                    std::cout << "Pas assez de projectiles disponibles pour ce type !" << std::endl;
                }
            }

        }

        // Mettre à jour la rotation de la flèche en fonction de l'angle sélectionné
        float angle = angleSlider.value;
        arrowSprite.setRotation(-angle);

        // Gérer le déplacement des tanks
        if (playerTurn) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                playerTank.move(5.0f, terrain);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                playerTank.move(-5.0f, terrain);
            }
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                enemyTank.move(5.0f, terrain);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                enemyTank.move(-5.0f, terrain);
            }
        }

        float deltaTime = 1.0f / 60.0f;
        for (auto it = projectiles.begin(); it != projectiles.end();) {
            (*it)->update(deltaTime);

            // Appliquer l'effet du vent sur vx
            (*it)->applyWindEffect(wind.getMultiplier());

            // Collision avec le terrain
            if (terrain.checkCollision((*it)->getX(), (*it)->getY())) {
                // Créer une explosion à l'impact
                explosions.emplace_back(
                    (*it)->getX(),
                    (*it)->getY(),
                    (*it)->getExplosionType() // Utilisation de getExplosionType
                );
                terrain.destroyAround((*it)->getX(), (*it)->getY(), (*it)->getExplosionRadius());
                it = projectiles.erase(it);
                continue;
            }

            // Collision avec les tanks
            if ((*it)->getX() >= playerTank.getX() && (*it)->getX() <= playerTank.getX() + 90 &&
                (*it)->getY() >= playerTank.getY() && (*it)->getY() <= playerTank.getY() + 60) {
                // Créer une explosion à l'impact
                explosions.emplace_back(
                    (*it)->getX(),
                    (*it)->getY(),
                    (*it)->getExplosionType() // Utilisation de getExplosionType
                );
                playerTank.reduceHealth((*it)->getDamage());
                playerTank.updateHealthBar(font);
                it = projectiles.erase(it);
                continue;
            }

            if ((*it)->getX() >= enemyTank.getX() && (*it)->getX() <= enemyTank.getX() + 90 &&
                (*it)->getY() >= enemyTank.getY() && (*it)->getY() <= enemyTank.getY() + 60) {
                // Créer une explosion à l'impact
                explosions.emplace_back(
                    (*it)->getX(),
                    (*it)->getY(),
                    (*it)->getExplosionType() // Utilisation de getExplosionType
                );
                enemyTank.reduceHealth((*it)->getDamage());
                enemyTank.updateHealthBar(font);
                it = projectiles.erase(it);
                continue;
            }

            ++it;
        }

        // Mettre à jour les explosions
        for (auto it = explosions.begin(); it != explosions.end();) {
            it->update(deltaTime);
            if (it->isFinished()) {
                it = explosions.erase(it);
            } else {
                ++it;
            }
        }

        // Dessiner les explosions
        for (auto& explosion : explosions) {
            explosion.draw(window);
        }
        


        // Vérifier la fin du jeu
        if (playerTank.isDead() || enemyTank.isDead()) {
            sf::Text resultText;
            resultText.setFont(font);
            resultText.setCharacterSize(30);
            resultText.setFillColor(sf::Color::White);
            resultText.setString(playerTank.isDead() ? "GAME OVER : Enemy Tank Wins!" : "Player Tank Wins!");
            resultText.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 20);

            window.clear();
            window.draw(resultText);
            window.display();
            sf::sleep(sf::seconds(3)); // Pause pour afficher le résultat
            window.close();
        }

        playerTank.updatePosition(terrain);
        enemyTank.updatePosition(terrain);

        window.clear();
        background.draw(window);           // Dessiner l'arrière-plan
        terrain.draw(window);              // Dessiner le terrain
        playerTank.draw(window);           // Dessiner le tank du joueur
        enemyTank.draw(window);            // Dessiner le tank ennemi
        wind.draw(window);                 // DEssiner le vent


        // Dessiner la flèche rouge pour le joueur actif
        if (currentPlayer == 1) {
            playerTank.drawTurnIndicator(window);
        } else {
            enemyTank.drawTurnIndicator(window);
        }


        // Dessiner le sprite de la flèche
        window.draw(arrowSprite);

        // Dessiner les projectiles
        for (auto& projectile : projectiles) {
            projectile->draw(window);
        }

        // Dessiner les explosions
        for (auto& explosion : explosions) {
            explosion.draw(window);
        }

        playerTank.drawHealthBar(window, font); // Barre de vie du joueur au-dessus du tank
        enemyTank.drawHealthBar(window, font);  // Barre de vie de l'ennemi au-dessus du tank
        speedSlider.draw(window);               // Dessiner les sliders
        angleSlider.draw(window);               // Dessiner les sliders
        selector.draw(window);                  // Dessiner le sélecteur de projectiles
        window.display();
    }



    music2.stop();
    return 0;
}

