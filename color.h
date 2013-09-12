/****************************************************************************
 * color.h: Contains Interface for Color     *
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

#ifndef _COLOR_H
#define _COLOR_H

#include "object.h"
#include "exception.h"

namespace scdk {

class SCColor: public SCObject {
private:
	static unsigned int color_lookup[8][8];

protected:
	int _foreColor;
	int _backColor;

public:
	static void initColor();
	
	SCColor() {
		_foreColor = COLOR_WHITE;
		_backColor = COLOR_BLACK;
	}
	
	SCColor(int fg,int bg) {
		if((fg < COLOR_BLACK || fg > COLOR_WHITE) ||
		   (bg < COLOR_BLACK || bg > COLOR_WHITE))
		   throw SCInvalidColorException();
		   
		_foreColor = fg;
		_backColor = bg;
	}

	SCColor getColor() {
		SCColor *c = new SCColor();
		c->setColor(_foreColor,_backColor);
		return *c;
	}

	int getColorPair() {
		return color_lookup[_foreColor][_backColor];
	}

	void setColor(int fg, int bg) {
		if((fg < COLOR_BLACK || fg > COLOR_WHITE) ||
		   (bg < COLOR_BLACK || bg > COLOR_WHITE))
		   throw SCInvalidColorException();

		_foreColor = fg;
		_backColor = bg;
	}
	
	int getForeColor() {
		return _foreColor;
	}

	void setForeColor(int fg) {
		if((fg < COLOR_BLACK || fg > COLOR_WHITE))
		   throw SCInvalidColorException();

		_foreColor = fg;
	}
	
	int getBackColor() {
		return _backColor;
	}

	void setBackColor(int bg) {
		if((bg < COLOR_BLACK || bg > COLOR_WHITE))
		   throw SCInvalidColorException();

		_backColor = bg;
	}
};

}

#endif
