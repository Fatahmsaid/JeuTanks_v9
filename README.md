# Jeu de Robot Tanks

Ce projet est un jeu de Robot tank développé en C++ utilisant la bibliothèque SFML. Les joueurs peuvent sélectionner des personnages, des cartes, et s'affronter en tirant des projectiles avec différents types d'armes.

## Lien GitHub : 
https://github.com/Fatahmsaid/JeuTanks_v9


## Fonctionnalités

- Sélection de personnages avec des statistiques différentes
- Sélection de cartes avec des terrains variés
- Gestion du vent influençant la trajectoire des projectiles
- Différents types de projectiles avec des effets variés
- Prise en compte des efforts mécaniques (gravité, vent).
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


## Si vous voulez jouer avec l'application
3. Mettre l'icoe de l'application sur votre Bureau
   1. Si vos dossiers sont en français :
   ```sh
   cp ~/Téléchargements/robot_tank.desktop ~/Bureau/
   ```
   2. Si vos dossiers sont en anglais :
      
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


1. Avec l'application :
   Double cliquer simplement sur l'icône :
![Screenshot from 2025-03-26 02-00-40](https://github.com/user-attachments/assets/5fba8078-17c2-405b-8a44-b2ae752a02be)

2. A l'ancienne :
    ```sh
    cd ~/Téléchargements/jeu_tank_v9
    ./tanks
    ```

2. Comment jouer :
   1. Menu de sélection des personnages ![Screenshot from 2025-03-26 02-04-36](https://github.com/user-attachments/assets/ab29c188-e02b-4d1e-95af-1550b422d4f8)

   2. Sélectionner les personnages avec les flèches directionnelles et entrer : Joueur 1 en rouge, Joueur 2 en bleu
   ![Screenshot from 2025-03-26 02-05-05](https://github.com/user-attachments/assets/da431650-fe20-48c7-86d2-b21059b21204)

   3. Sélectionner la map souhaitée
   ![Screenshot from 2025-03-26 02-06-07](https://github.com/user-attachments/assets/0a929bf2-4e41-4ed0-9631-eb4fe773d5cf)


    4. JOUER !!!
      - Déplacer votre robot tireur avec les flèches directionnelles
      - Selectionner votre missile en haut à droite
      - Configurer la puissance de projection et l'angle de tir en haut à gauche
      - Attention : faut prenre en compte la vitesse du vent
      - Quand vous être prêt, appuyer sur "Space" pour exploser votre adversaire"
   ![Screenshot from 2025-03-26 02-06-45](https://github.com/user-attachments/assets/359ccf6a-a426-45bd-925e-e74a0985d949)








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

## Diagramme UML
![diagramme](https://github.com/user-attachments/assets/16757ec2-372a-4b3a-b84f-0c3fc9475713)


## Tests
1. Boost.Test (ok)
2. Valgrind : Pas d'erreurs majeurs (donc conforme au CdC).

## Auteurs

- Fatah, Ilyes et Nacim

## Licence

Libre d'accès à tout le monde.

## Remerciements

- Dédicace à personne fallait être là

