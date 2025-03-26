all: tanks

tanks: main.cpp Tank.cpp Projectile.cpp Terrain.cpp Background.cpp Slider.cpp ProjectileSelector.cpp Explosion.cpp Wind.cpp game.cpp
	g++ -o tanks main.cpp Tank.cpp Projectile.cpp Terrain.cpp Background.cpp Slider.cpp ProjectileSelector.cpp Explosion.cpp Wind.cpp game.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f tanks
