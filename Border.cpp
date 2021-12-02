#include <ncurses.h>
using namespace std;

int main()
{
	int x = 1, y = 1;
	initscr();
	
	WINDOW * win = newwin (20, 30, 1, 1);
	refresh();
	
	box(win, 0, 0);
	wmove(win, x, y);
	wprintw(win, "@");
	wrefresh(win);
	
	getch();
	endwin();
}
