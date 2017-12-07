#include <curses.h>
#include <unistd.h>
#include "Gameplay.h"


#define ALIVE_MARKER 'O'
#define TICK_USEC (100000)

void load(const gol::Gameplay& g, WINDOW *win, int h, int w)
{
	werase(win);
	for(int line=0; line < h; ++line) {
		for(int col=0; col < w; ++col) {
			if(g.isAlive(line, col)) mvwaddch( win, line, col, ALIVE_MARKER);
		}
	}
	wrefresh(win);
}

int main(int argc, const char *argv[])
{
	bool wantQuit = false;
	gol::Gameplay gameplay{};
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	
	int h, w;
	getmaxyx(stdscr, h, w);
	gameplay.init(h, w);
	do {
		load(gameplay, stdscr, h, w);
		gameplay.tick();
		int c = getch();

		if (KEY_RESIZE == c) {
			getmaxyx(stdscr, h, w);
			gameplay.init(h, w);
		}
		wantQuit = ('q' == c);
		usleep(wantQuit ? 0 : TICK_USEC);
	} while(!wantQuit);

	endwin();
}
