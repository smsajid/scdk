#include <ncurses.h>

int main()
{
	initscr();
	WINDOW *w,*sw;
	w=newpad(10,20);
	//sw=subwin(w,8,18,1,1);
	//mvwin(w,2,3);
	//box(w,'+','+');
	prefresh(w,0,0,4,10,9,19);
	//mvwin(w,3,4);
	int ch;
	while((ch=wgetch(w))!='q')
		pechochar(w,ch);//prefresh(w,2,3,2,3,9,19);
	//delwin(sw);
	delwin(w);
	endwin();
}
