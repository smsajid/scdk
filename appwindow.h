/* window.h */

#ifndef _APPWINDOW_H
#define _APPWINDOW_H

#include "object.h"

namespace scdk {

class Window;
Window* const FULLSCREEN = (Window*) 0;

class Window : public Object {
private:
	void _createWindow(Window *ptro,const char *title,int height,int width,int start_x,int start_y,border_t b);
	void refresh();

protected:
	Window      *_owner,*_child;
	WINDOW      *_bwin,*_win;
	std::string _title;
	int         _left,_top,_width,_height;
	int         _fgColor,_bgColor;		//foreground and background color of the window
	chtype      _bgChar;				//background character of the window
	border      _b_param;		        //border characters of the border
	border_t    _border;				//border type
	chtype      _origbg;				//attribute of the owner window
	bool        _hidden;
	bool        _canScroll;
	int         _cursorType;			//whether invisible=0,normal=1 or very visible=2

public:
	Window();
	Window(Window *ptro);
	Window(const char *title);
	Window(Window *ptro,const char *title);
	~Window();
	void show();
	void hide();
	void move(int x,int y);
	void resize(int x,int y);
	void setWidth(int x);
	void setHeight(int y);
	void setBG(int fg=-1,int bg=-1,chtype ch=' ');
	void setBorderStyle(border_t b,int ls=0,int rs=0,int ts=0,int bs=0,int tl=0,int tr=0,int bl=0,int br=0);
	void setCursorType(int c);
	void getCurPos(int x,int y);
	void setCurPos(int x,int y);
	void write(char *format,...);
	int  read(char *format,...);
	int  getChar();
};

}//namespace
#endif
