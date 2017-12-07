all: main.cpp Gameplay.cpp Gameplay.h
	clang++ -std=c++14 -Og -ggdb main.cpp Gameplay.cpp -o game-of-life -L/usr/lib/i386-linux-gnu -lncurses

