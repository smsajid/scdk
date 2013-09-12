/****************************************************************************
 * window.cpp: Implementation functions for Window class                    *
 * Version   : 0.1                                                          *
 ***************************************************************************/

/****************************************************************************
 * Copyright (c) 2005 Sheikh Mohammad Sajid                                 *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                          *
 * Except as contained in this notice, the name(s) of the above copyright   *
 * holders shall not be used in advertising or otherwise to promote the     *
 * sale, use or other dealings in this Software without prior written       *
 * authorization.                                                           *
 ****************************************************************************/

/****************************************************************************
 *  Author: Sheikh Mohammad Sajid<smsajid786@yahoo.com> 2005                *
 ****************************************************************************/

#include "window.h"

/* protected function definitions */
void
scdk::SCWindow::createWindow(int h,int w,int l,int t) {
	/* TODO : Check for errors in the various parameters*/
	if(l<0) _left=0;
	else _left=l;

	if(t<0) _top=0;
	else _top=t;
	
	if(w>COLS) _width=COLS;
	else _width=w;
	
	if(h>LINES) _height=LINES;
	else _height=h;

	_canScroll=false;
	_cursorType=1;
	_bgChar=' ';
	_hidden=true;

	_win = newwin(_height,_width,_top,_left);
	
	wbkgd(_win,_bgChar | COLOR_PAIR(_color.getColorPair()));
	
	keypad(_win,TRUE);
}

void
scdk::SCWindow::refresh() {
	if(_hidden)
		return;
		
	//setBG(_fgColor,_bgColor,_bgChar);
	wrefresh(_win);
	//wrefresh(_bwin);
}

/* public function definitions */
scdk::SCWindow::SCWindow() {
	_name = "Window";
	createWindow(LINES,COLS,0,0);
}

scdk::SCWindow::~SCWindow() {
	setVisible(false);
	//if(Child!=NULL) Child->~Window();
	delwin(_win);
}

void 
scdk::SCWindow::setVisible(bool makeVisible = true) {
	if(_hidden && makeVisible) { //show it
		_hidden = false;
		curs_set(_cursorType);
		wbkgd(_win,_bgChar | COLOR_PAIR(_color.getColorPair()));
	} else if(!_hidden && !makeVisible) { //hide it
		chtype origbg=getbkgd(stdscr);

		_hidden=true;

		wclear(_win);
		wbkgd(_win,origbg);
	}
	refresh();
}

void
scdk::SCWindow::move(int x,int y) {
	_left = x;
	_top  = y;
	int err;

	//setVisible(false);
	err = mvwin(_win,y,x);
	refresh();
	//setVisible();
	//setCurPos(_left,_top);
}

void
scdk::SCWindow::resize(int w,int h) {
	_width=w;
	_height=h;
	
	wresize(_win,h,w);
	refresh();
}

void
scdk::SCWindow::setWidth(int w) {
	_width=w;
	
	scdk::SCWindow::resize(w,_height);
}

void
scdk::SCWindow::setHeight(int h) {
	_height=h;
	
	scdk::SCWindow::resize(_width,h);
}

void 
scdk::SCWindow::setForeColor(int fc) {
	_color.setForeColor(fc);
	
	wbkgd(_win,_bgChar | COLOR_PAIR(_color.getColorPair()));
	refresh();
}

void 
scdk::SCWindow::setBackColor(int bc) {
	_color.setBackColor(bc);

	wbkgd(_win,_bgChar | COLOR_PAIR(_color.getColorPair()));
	refresh();
}

void 
scdk::SCWindow::setCursorType(int c) {
	_cursorType=c;
	curs_set(_cursorType);
}

void
scdk::SCWindow::print(char *format, ...) {
	va_list ap = 0;
	va_start(ap,format);
	vwprintw(_win,format,ap);
	va_end(ap);
	refresh();
	//getyx(_win,y,x);
}

int 
scdk::SCWindow::read(char *format,...) {
	va_list ap = 0;
	va_start(ap,format);
	int ret = vwscanw(_win,format,ap);
	va_end(ap);
	return ret;
}

int
scdk::SCWindow::readChar() {
	if(_hidden)
		return -1; //appropiate exception should be thrown
	return wgetch(_win);
}
