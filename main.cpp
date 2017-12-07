#include <curses.h>
#include <unistd.h>
#include "Gameplay.h"


#define ALIVE_MARKER 'O'

void load(const gol::Gameplay& g, WINDOW *win, int h, int w)
{
	int line, col;
	wrefresh(win);
	for(line=0; line < h; ++line) {
		for(col=0; col < w; ++col) {
			if(g.isAlive(line, col)) mvwaddch( win, line, col, ALIVE_MARKER);
		}
	}
}

int main(int argc, const char *argv[])
{
	int ch;
	int h, w;
	bool wantQuit = false;
	gol::Gameplay gameplay{};
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, true);
	
	getmaxyx(stdscr, h, w);
	gameplay.init(h, w);
	do {
		load(gameplay, stdscr, h, w);
		gameplay.tick();
		ch = getch();
		wantQuit = ('q' == ch);
		sleep(wantQuit ? 0 : 1);
	} while(!wantQuit);

	endwin();
}
