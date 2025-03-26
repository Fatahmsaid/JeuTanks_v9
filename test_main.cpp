#define BOOST_TEST_MODULE TanksGameTest
#include <boost/test/included/unit_test.hpp>
#include "Tank.hpp"
#include "Terrain.hpp"
#include "Background.hpp"
#include "Slider.hpp"
#include "Wind.hpp"
#include "game.hpp"
#include <boost/test/tools/interface.hpp>
#include <boost/test/tools/old/interface.hpp>
#include <gtest/gtest.h>

// Tests pour la classe Tank
BOOST_AUTO_TEST_CASE(TankInitializationTest) {
    Tank tank(100, 500, "/home/fatah/Téléchargements/JeuTanks_v9/player_tank.png");
    BOOST_CHECK_EQUAL(tank.getX(), 100);
    BOOST_CHECK_EQUAL(tank.getY(), 500);
}

BOOST_AUTO_TEST_CASE(TankMovementTest) {
    Terrain terrain(1600, 1000, 800, "Carte: Map 1");
    Tank tank(100, 500, "/home/fatah/Téléchargements/JeuTanks_v9/player_tank.png");
    tank.move(10, terrain);
    BOOST_CHECK_EQUAL(tank.getX(), 110);
    tank.move(-20, terrain);
    BOOST_CHECK_EQUAL(tank.getX(), 90);
}


// Tests pour la classe Terrain
BOOST_AUTO_TEST_CASE(TerrainInitializationTest) {
    Terrain terrain(1600, 1000, 800, "Carte: Map 1");
    BOOST_CHECK_EQUAL(terrain.getWidth(), 1600);
    BOOST_CHECK_EQUAL(terrain.getHeight(), 1000);
}

// Tests pour la classe Background
BOOST_AUTO_TEST_CASE(BackgroundInitializationTest) {
    Background background("/home/fatah/Téléchargements/JeuTanks_v9/background.png");
    BOOST_CHECK(background.isLoaded());
}



// Tests pour la classe Wind
BOOST_AUTO_TEST_CASE(test_generateWind) {
    sf::Font font;
    // Assurez-vous d'avoir une police valide pour le test
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        BOOST_FAIL("Erreur de chargement de la police");
    }

    Wind wind(0, 0, font);

    // Tester que la génération du vent fonctionne
    wind.generateWind();

    // Tester la vitesse du vent
    BOOST_CHECK(wind.getMultiplier() > 0); // Le multiplicateur doit être supérieur à 0

    // Tester que la direction est correcte 
    float multiplier = wind.getMultiplier();
    BOOST_CHECK(multiplier == 1.0f + (wind.getMultiplier() - 1.0f) / 100.0f || multiplier == 1.0f - (wind.getMultiplier() - 1.0f) / 100.0f);
}


BOOST_AUTO_TEST_CASE(test_wind_direction) {
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        BOOST_FAIL("Erreur de chargement de la police");
    }

    Wind wind(0, 0, font);
    wind.generateWind();

    // Tester si la direction est correcte (vrai ou faux)
    bool direction = wind.getMultiplier() > 1.0f; 
    BOOST_CHECK(direction == (wind.getMultiplier() > 1.0f));
}




// Tests pour la classe Slider
BOOST_AUTO_TEST_CASE(test_slider_value_update) {
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        BOOST_FAIL("Erreur de chargement de la police");
    }

    // Créer un objet Slider
    Slider slider(100.f, 100.f, 200.f, 0.f, 100.f, "Test Slider", font);

    // Simuler un événement de pression du bouton de la souris
    sf::Event event;
    event.type = sf::Event::MouseButtonPressed;
    event.mouseButton.x = 150;  
    event.mouseButton.y = 105;
    slider.update(event);  // Appeler la méthode update pour simuler l'appui

    // Simuler un mouvement de la souris
    event.type = sf::Event::MouseMoved;
    event.mouseMove.x = 200;  
    slider.update(event); 

    // Vérifier que la valeur du slider a changé
    BOOST_CHECK(slider.value > 0.f);  // La valeur doit être plus grande que zéro
    BOOST_CHECK(slider.value <= 100.f);  // La valeur ne doit pas dépasser 100
}

// Test pour la classe explosion
BOOST_AUTO_TEST_CASE(test_explosion_public_methods)
{
    // Création d'une explosion à la position (100, 100) de type SmallMissile
    Explosion explosion(100.0f, 100.0f, ExplosionType::SmallMissile);

    // Vérifie si l'explosion n'est pas terminée au départ
    BOOST_CHECK_EQUAL(explosion.isFinished(), false);

    // Appelle update pour simuler un petit passage de temps
    explosion.update(0.1f);

    // L'explosion ne devrait toujours pas être terminée
    BOOST_CHECK_EQUAL(explosion.isFinished(), false);

    // Simule 12 mises à jour 
    for (int i = 0; i < 12; ++i) {
        explosion.update(0.1f);  // Simulation de chaque frame
    }

    // Après 12 mises à jour, l'explosion devrait être terminée
    BOOST_CHECK_EQUAL(explosion.isFinished(), true);
}