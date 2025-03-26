# Jeu de Robot Tanks

Ce projet est un jeu de Robot tank développé en C++ utilisant la bibliothèque SFML. Les joueurs peuvent sélectionner des personnages, des cartes, et s'affronter en tirant des projectiles avec différents types d'armes.

## Fonctionnalités

- Sélection de personnages avec des statistiques différentes
- Sélection de cartes avec des terrains variés
- Gestion du vent influençant la trajectoire des projectiles
- Différents types de projectiles avec des effets variés
- Barre de vie pour les tanks
- Indicateur de tour pour le joueur actif
- Musique de fond changeante

## Prérequis
- Ubuntu 22.04 (Fortement recommandé)
- SFML (Version: 2.5.1+dfsg-2)
- C++17 ou supérieur
- CMake (optionnel)

## Installation

1. Clonez le dépôt :
    ```sh
    cd ~/Téléchargements  
    git clone https://github.com/Fatahmsaid/jeu_tank_v9.git
    cd jeu_tank_v9
    ```

2. Compilez le projet (optionnel) :
    ```sh
    make
    ```
3. Mettre l'icoe de l'application sur votre Bureau
   a. Vos dossier sont en français :
   ```sh
   cp ~/Téléchargements/robot_tank.desktop ~/Bureau/
   ```
   b. Vos dossier sont en anglais :
   ```sh
   cp ~/Downloads/robot_tank.desktop ~/Desktop/
   ```

4. Dans tous les fichier .cpp, Changez le chemin des .png avec le chemin de votre racine système
   Exemple avec  "Wind.cpp"
   Remplacer :
   ```sh
   if (!windTexture.loadFromFile("/home/fatah/Téléchargements/JeuTanks_v9/wind_icon.png"))
   ```
   Par :
   ```sh
   if (!windTexture.loadFromFile("/home/votre_nom/Téléchargements/JeuTanks_v9/wind_icon.png"))
   ```
   => Promis : Une version arrive avec l'automatisation de cette tache

   

## Utilisation

1. Exécutez le jeu :
    ```sh
    ./tanks
    ```

2. Suivez les instructions à l'écran pour sélectionner vos personnages et la carte.

3. Utilisez les touches fléchées pour déplacer votre tank et la barre d'espace pour tirer.

## Structure du Projet

- `main.cpp` : Point d'entrée du jeu
- `Tank.h` et `Tank.cpp` : Gestion des tanks
- `Projectile.h` et `Projectile.cpp` : Gestion des projectiles
- `Terrain.h` et `Terrain.cpp` : Gestion du terrain
- `Background.h` et `Background.cpp` : Gestion de l'arrière-plan
- `Slider.h` et `Slider.cpp` : Gestion des sliders pour la puissance et l'angle
- `ProjectileSelector.h` et `ProjectileSelector.cpp` : Sélection des types de projectiles
- `Explosion.h` et `Explosion.cpp` : Gestion des explosions
- `Wind.h` et `Wind.cpp` : Gestion du vent
- `game.hpp` et `game.cpp` : Gestion de la logique de sélection des personnages et des cartes

## Auteurs

- Fatah

## Licence

Ce projet est sous licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

## Remerciements

- SFML pour la bibliothèque multimédia
- Toute personne ayant contribué à ce projet
