//main.cpp
#include "game.hpp"
#include <iostream>

int main() {
    Game game;
    game.run();

    std::cout << "Personnage 1 sélectionné : " << game.getSelectedCharacter1() << std::endl;
    std::cout << "Personnage 2 sélectionné : " << game.getSelectedCharacter2() << std::endl;
    std::cout << "Carte sélectionnée : " << game.getSelectedMap() << std::endl;

    return EXIT_SUCCESS;
}
