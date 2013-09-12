/****************************************************************************
 * dimension.h: Contains Classes for creating 2D co-ordinates               *
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
 
#ifndef _DIMENSION_H
#define _DIMENSION_H

#include "object.h"

namespace scdk {

//Dimension Template
template<class T>
class SCDimension: public SCObject {
protected:
	T _x;
	T _y;

public:
	SCDimension() {
		_x = 0;
		_y = 0;
	}

	SCDimension(T x, T y) {
		_x = x;
		_y = y;
	}
	
	T getX() {
		return _x;
	}
	
	void setX(T x) {
		_x = x;
	}
	
	T getY() {
		return _y;
	}
	
	void setY(T y) {
		_y = y;
	}
};

}

#endif
