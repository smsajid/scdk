/****************************************************************************
 * pad.cpp: Implementation functions for Pad class                    *
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

#include "pad.h"

/* protected function definitions */
void
scdk::SCPad::createWindow(int h,int w,int l,int t) {
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

	_win = newpad(_height,_width);
	
	wbkgd(_win,_bgChar | COLOR_PAIR(_color.getColorPair()));
	
	keypad(_win,TRUE);
}

void
scdk::SCPad::refresh() {
	if(_hidden)
		return;
		
	//setBG(_fgColor,_bgColor,_bgChar);
	prefresh(_win, 0, 0, _left, _top, _height, _width);
	//wrefresh(_bwin);
}

/* public function definitions */
scdk::SCPad::SCPad() {
	_name = "Window";
	createWindow(LINES,COLS,0,0);
}

scdk::SCPad::~SCPad() {
	setVisible(false);
	//if(Child!=NULL) Child->~Window();
	delwin(_win);
}

int
scdk::SCPad::readChar() {
	int ch = SCWindow::readChar();
	pechochar(_win,ch);
	//refresh();
	return ch;
}
