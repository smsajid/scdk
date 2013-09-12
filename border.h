/****************************************************************************
 * boder.h: Contains Classes for creating borders                           *
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
 
#ifndef _BORDER_H
#define _BORDER_H

#include "object.h"
#include "dimension.h"

namespace scdk {

//Border Interface
class SCBorder: public SCObject {
public:
	virtual void drawBorder() = 0;
};

//Styled Border Interface
class SCStyledBorder: public SCBorder {
protected:
	int _ls,   //left side
	    _rs,   //right side
		_ts,   //top side
		_bs,   //bottom side
		_tl,   //top left corner
		_tr,   //top right corner
		_bl,   //bottom left corner
		_br;   //bottom right corner
	int _borderStyle;
	SCDimension<int> begin,//beginning co-ordinates for the border
				   end;  //ending co-ordinates for the border

public:
	const static int NONE;
	const static int EMPTY;
	const static int SINGLE;
	const static int DOUBLE;
	const static int CUSTOM;
	
	SCStyledBorder() {
		setBorderStyle(EMPTY);
	}
	
	SCStyledBorder(int l, int t, int r, int b):begin(l,t), end(r,b) {
		setBorderStyle(EMPTY);
	}
	
	SCStyledBorder(const SCDimension<int>& b, const SCDimension<int>& e):
												begin(b), end(e) {
		setBorderStyle(EMPTY);
	}

	const SCDimension<int>& getBegin() {
		return begin;
	}

	const SCDimension<int>& getEnd() {
		return end;
	}

	void setBoundary(int l, int t, int r, int b) {
		begin.setX(l);	begin.setY(t);
		end.setX(r);    end.setY(b);
	}

	int getBorderStyle() {
		return _borderStyle;
	}
	
	void setBorderStyle(const int s);
	void setBorderStyleCustom(int ls, int rs, int ts, int bs, 
							  int tl, int tr, int bl, int br);
};

}

#endif
