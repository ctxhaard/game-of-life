all: main.cpp Gameplay.cpp Gameplay.h
	g++ -std=c++14 main.cpp Gameplay.cpp -o game-of-life -L/usr/lib/i386-linux-gnu -lncurses

