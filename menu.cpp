#include<menu.h>
//#include"windows.cpp"

void initcolor();

int main()
{	
	initscr();
	start_color();
	ITEM *menuitems[6];
	MENU *menubar;
	WINDOW *win,*sub_win;
	int i,rows,cols;
	//initcolor();
	menuitems[0]=new_item("File","");
	menuitems[1]=new_item("Edit","");
	menuitems[2]=new_item("Options","");
	menuitems[3]=new_item("Window","");
	menuitems[4]=new_item("Help","");
	menuitems[5]=NULL;
	//menu_opts_off(menubar,O_ROWMAJOR);
	menubar=new_menu(menuitems);
	scale_menu(menubar,&rows,&cols);
	win=newwin(rows+2,cols+2,2,5);
	box(win,179,196);
	sub_win=derwin(win,rows,cols,1,1);
	set_menu_win(menubar,win);
	set_menu_sub(menubar,sub_win);
	post_menu(menubar);
	wrefresh(win);

	wgetch(sub_win);
	unpost_menu(menubar);
	free_menu(menubar);
	for(i=0;i<6;i++)
		free_item(menuitems[i]);
	endwin();
}

void initcolor()
{	
	init_pair(COLOR_BLACK,COLOR_BLACK,COLOR_BLACK);
	init_pair(COLOR_GREEN,COLOR_GREEN,COLOR_BLACK);
	init_pair(COLOR_RED,COLOR_RED,COLOR_BLACK);
	init_pair(COLOR_CYAN,COLOR_CYAN,COLOR_BLACK);
	init_pair(COLOR_WHITE,COLOR_WHITE,COLOR_BLACK);
	init_pair(COLOR_MAGENTA,COLOR_MAGENTA,COLOR_BLACK);
	init_pair(COLOR_BLUE,COLOR_BLUE,COLOR_BLACK);
	init_pair(COLOR_YELLOW,COLOR_YELLOW,COLOR_BLACK);
}
