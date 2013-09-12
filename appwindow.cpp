/* appwindow.cpp */

#include "appwindow.h"
//ide::FULLSCREEN = (ide::Window*) 0;
void
ide::Window::_createWindow(Window *ptro,const char *title,int h,int w,int l,int t,border_t b)
{	/* TO DO : Check for errors in the various parameters*/
	if(l<0) _left=0;
	else _left=l;

	if(t<0) _top=0;
	else _top=t;
	
	if(w>COLS) _width=COLS;
	else _width=w;
	
	if(h>LINES) _height=LINES;
	else _height=h;

	if(title!=NULL)
		_title = title;
	
	_owner=ptro;
	_child=NULL;
	
	//set this window as the child window of the owner window
	if(_owner!=FULLSCREEN)
		_owner->_child=this;

	//Left=l;Top=t;Width=w;Height=h;

	_border=b;
	_canScroll=false;
	_cursorType=0;
	_fgColor=COLOR_WHITE;_bgColor=COLOR_BLACK;
	_bgChar=' ';
	_hidden=false;
	_bwin=NULL;

	init_pair(_fgColor,_fgColor,_bgColor);

	if(_owner==FULLSCREEN || _owner==NULL) {	
		/*if(_border==NONE)
			_win=newwin(_height,_width,_top,_left);
		else {*/	
			_bwin=newwin(_height,_width,_top,_left);
			setBorderStyle(_border);
			_win=derwin(_bwin,_height-2,_width-2,1,1);
		//}				
	}
	else {
		/*if(_border==NONE)
			_win=derwin(_owner->_win,_height,_width,_top,_left);
		else {*/
			_bwin=derwin(_owner->_win,_height,_width,_top,_left);
			setBorderStyle(_border);
			_win=derwin(_bwin,_height-2,_width-2,1,1);
		//}
	}
	
	//if(_bwin!=NULL)
		wbkgd(_bwin,_bgChar | COLOR_PAIR(_fgColor));
	
	//wbkgd(_win,_bgChar | COLOR_PAIR(_fgColor));
	keypad(_win,TRUE);
}

void
ide::Window::refresh()
{
	if(_hidden==true)
		return;
		
	if(_border==SINGLE || _border==DOUBLE)
		setBorderStyle(_border);
	else if(_border==CUSTOM)
		setBorderStyle(_border,_b_param.ls,_b_param.rs,_b_param.ts,_b_param.bs,_b_param.tl,_b_param.tr,_b_param.bl,_b_param.br);

	setBG(_fgColor,_bgColor,_bgChar);
	wrefresh(_bwin);
}

ide::Window::Window()
{
	_createWindow(FULLSCREEN,"New Window",LINES,COLS,0,0,NONE);
}

ide::Window::Window(Window *ptro)
{
	_createWindow(ptro,"New Window",LINES,COLS,0,0,NONE);
}

ide::Window::Window(const char* title)
{
	_createWindow(FULLSCREEN,title,LINES,COLS,0,0,NONE);
}

ide::Window::Window(Window *ptro,const char *title)
{
	_createWindow(ptro,title,LINES,COLS,0,0,NONE);
}

ide::Window::~Window() {
	hide();
	//if(Child!=NULL) Child->~Window();
	if(_win!=NULL) delwin(_win);
	if(_bwin!=NULL) delwin(_bwin);
}

void 
ide::Window::show()
{
	_hidden=false;
	curs_set(_cursorType);
	refresh();

	if(_child!=NULL) {
		if(_child->_hidden==false)
			_child->show();
		else
			_child->hide();
	}

}

void
ide::Window::hide()
{
//get orig background for restoring when hiding or deleting the window

	if(_owner==FULLSCREEN) {
		_origbg=getbkgd(stdscr);
	}
	else {
		_origbg=getbkgd(_owner->_win);	
	}
	
	_hidden=true;
	
	if(_bwin!=NULL) {
		wclear(_bwin);
		wbkgd(_bwin,_origbg);
		wbkgd(_win,_origbg);
		wrefresh(_bwin);
	}
	else {
		wclear(_win);
		wbkgd(_win,_origbg);
		wrefresh(_win);
	}
}

void
ide::Window::move(int x,int y)
{
	_left = x;
	_top  = y;
	
	if(_hidden==true)
		return;
	
	hide();
	
	if(_owner==FULLSCREEN) {	
		if(_bwin!=NULL) {
			mvwin(_bwin,y,x);
			int err=mvderwin(_win,1,1);
			//wprintw(_win,"%d",err);
			touchwin(_bwin);
			wrefresh(_win);
		}
		else {
			mvwin(_win,y,x);
			//wrefresh(_win);
		}
	}
	else {
		if(_bwin!=NULL) {
			mvderwin(_bwin,y,x);
			//wrefresh(_bwin);
		}
		else {
			mvderwin(_win,y,x);
			//wrefresh(_win);
		}
	}
	show();
}

void
ide::Window::resize(int w,int h)
{
	_width=w;
	_height=h;
	
	if(_hidden==true)
		return;
		
	hide();
	wresize(_win,h-2,w-2);
	wresize(_bwin,h,w);

	show();
}

void
ide::Window::setWidth(int w)
{
	_width=w;
	
	if(_hidden==true)
		return;
		
	ide::Window::resize(w,_height);
}

void
ide::Window::setHeight(int h)
{
	_height=h;
	
	if(_hidden==true)
		return;
		
	ide::Window::resize(_width,h);
}

//void Window::setBG(int fg=-1,int bg=-1,chtype ch=' ')
void 
ide::Window::setBG(int fg,int bg,chtype ch)
{
	_bgChar=ch;
	
	if(fg>0)
		_fgColor=fg;
	
	if(bg>0)
		_bgColor=bg;
	
	init_pair(_fgColor,_fgColor,_bgColor);
	wbkgd(_win,_bgChar | COLOR_PAIR(_fgColor));
	
	if(_bwin!=NULL)
		wbkgd(_bwin,_bgChar | COLOR_PAIR(_fgColor));
	wrefresh(_bwin);
}
		
//void Window::setBorderStyle(border_t b,int ls=0,int rs=0,int ts=0,int bs=0,int tl=0,int tr=0,int bl=0,int br=0)
void 
ide::Window::setBorderStyle(border_t b,int ls,int rs,int ts,int bs,int tl,int tr,int bl,int br)
{
	//if(bwin==NULL) return;
	_border = b;
	if(b==NONE)
		return;
	else if(b==SINGLE) {
		_b_param.ls=_b_param.rs=179;
		_b_param.ts=_b_param.bs=196;
		_b_param.tl=218;_b_param.tr=191;
		_b_param.bl=192;_b_param.br=217;
	}
	else if(b==DOUBLE) {
		_b_param.ls=_b_param.rs=186;
		_b_param.ts=_b_param.bs=205;
		_b_param.tl=201;_b_param.tr=187;
		_b_param.bl=200;_b_param.br=188;
	}
	else if(b==CUSTOM) {
		_b_param.ls=ls;_b_param.rs=rs;
		_b_param.ts=ts;_b_param.bs=rs;
		_b_param.tl=tl;_b_param.tr=tr;
		_b_param.bl=bl;_b_param.br=br;
	}
	
	if(_hidden==true)
		return;

	wattron(_bwin,A_ALTCHARSET);
	wborder(_bwin,_b_param.ls,_b_param.rs,_b_param.ts,_b_param.bs,_b_param.tl,_b_param.tr,_b_param.bl,_b_param.br);
	wattroff(_bwin,A_ALTCHARSET);
	if(_title.length()>0)
		mvwprintw(_bwin,0,1," %s ",_title.data());
	wrefresh(_bwin);
}

void 
ide::Window::setCursorType(int c)
{
	_cursorType=c;
	curs_set(_cursorType);
}

void 
ide::Window::getCurPos(int x,int y)
{
	getyx(_win,x,y);
}

void
ide::Window::setCurPos(int x,int y)
{
	wmove(_win,y,x);			
}

void
ide::Window::write(char *format,...)
{
	curs_set(_cursorType);
	wprintw(_win,format);
	wrefresh(_win);
	//getyx(_win,y,x);
}

int
ide::Window::read(char *format,...)
{
	curs_set(_cursorType);
	wscanw(_win,format);
}

int
ide::Window::getChar()
{
	return wgetch(_win);
}
