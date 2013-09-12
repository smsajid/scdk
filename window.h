/****************************************************************************
 * window.h: Provides Interface for Window class                            *
 * Version : 0.1                                                            *
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

#ifndef _WINDOW_H
#define _WINDOW_H

#include "object.h"
#include "exception.h"
#include "color.h"

namespace scdk {

class SCWindow: public SCObject {
protected:
	WINDOW      *_win;
	int         _left,_top,_width,_height;
	SCColor       _color;        //foreground and background color of the window
	chtype      _bgChar;		 //background character of the window
	bool        _hidden;
	bool        _canScroll;
	int         _cursorType;	//whether invisible=0,normal=1 or very visible=2

	virtual void createWindow(int height,int width,int start_x,int start_y);
	virtual void refresh();

public:
	SCWindow();
	virtual ~SCWindow();
	void setVisible(bool makeVisible = true);
	void move(int x,int y);
	void getSize(int& x,int& y);
	void resize(int x,int y);

	int getTop() {
		return _top;
	}

	void setTop(int t) {
		move(_left,t);
	}

	int getLeft() {
		return _left;
	}

	void setLeft(int l) {
		move(l,_top);
	}

	int  getWidth() {
		return _width;
	}

	void setWidth(int w);

	int  getHeight() {
		return _height;
	}

	void setHeight(int h);

	int  getForeColor() {
		return _color.getForeColor();
	}

	void setForeColor(int fg);

	int  getBackColor() {
		return _color.getBackColor();
	}

	void setBackColor(int bg);

	void setCursorType(int c);

	void getCurPos(int &x,int &y) {
		getyx(_win,y,x);
	}

	void setCurPos(int x,int y) {
		wmove(_win,y,x);			
	}
	
	void print(char *format,...);
	int  read(char *format,...);
	int  readChar();
};

}//namespace
#endif
