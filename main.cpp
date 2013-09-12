#include "window.h"
#include "color.h"
#include "system.h"
#include "pad.h"

using namespace scdk;

//void scdk::before_endwin(){}
//void scdk::after_endwin(){printf("fsdf\n");}

int main()
{	
	//(void) signal(SIGINT, finish);      /* arrange interrupts to terminate */
	//initialisation
	//initscr();

	try {/*this scope is necessary since endwin() will be called before any
		destructor is called, which create problems as the ncurses window is
		destroyed in the destructor after endwin() is called. */
		
		//SCColor::initColor();
		SCSystem::start();

		SCPad w;
		//w.resize(40,10);
		w.setVisible();
//		w.setForeColor(COLOR_WHITE);
		w.setBackColor(COLOR_BLUE);
		w.print("Test %d",w.getForeColor());
		
		
		int x = 0, y = 0;
		w.getCurPos(x,y);
		w.print("%d,%d\n",COLORS,COLOR_PAIRS);
		//w.move(4,3);
//		w.setBackColor(COLOR_RED);
		w.getCurPos(x,y);
		//w.print("%d,%d",x,y);

		while(w.readChar()!='q');
	} catch(SCException e) {
		printw("%s in %d", e.getMessage());
		refresh();
		wgetch(stdscr);
	}

	SCSystem::stop();
}
