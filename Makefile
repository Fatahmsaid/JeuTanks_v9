all: tanks

tanks: main.cpp Tank.cpp Projectile.cpp Terrain.cpp Background.cpp Slider.cpp ProjectileSelector.cpp Explosion.cpp Wind.cpp game.cpp
	g++ -o tanks main.cpp Tank.cpp Projectile.cpp Terrain.cpp Background.cpp Slider.cpp ProjectileSelector.cpp Explosion.cpp Wind.cpp game.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	
# Cible de test : compilation des tests avec Boost.Test
test: test_main.cpp Tank.cpp Projectile.cpp Terrain.cpp Background.cpp Slider.cpp ProjectileSelector.cpp Explosion.cpp Wind.cpp game.cpp
	g++ -o test_main test_main.cpp Tank.cpp Projectile.cpp Terrain.cpp Background.cpp Slider.cpp ProjectileSelector.cpp Explosion.cpp Wind.cpp game.cpp -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	
	
valgrind: test
	valgrind ./tanks


clean:
	rm -f tanks
