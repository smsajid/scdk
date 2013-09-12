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
 
#include "border.h"

const int scdk::SCStyledBorder::NONE   = 0;
const int scdk::SCStyledBorder::EMPTY  = 1;
const int scdk::SCStyledBorder::SINGLE = 2;
const int scdk::SCStyledBorder::DOUBLE = 3;
const int scdk::SCStyledBorder::CUSTOM = 4;

void scdk::SCStyledBorder::setBorderStyle(const int s) {
	if(s == scdk::SCStyledBorder::EMPTY) {
		_borderStyle = NONE;
	} else if(s == scdk::SCStyledBorder::EMPTY) {
		_borderStyle = EMPTY;
		_ls = _rs = _ts = _bs = _tl = _tr = _bl = _br = ' ';
	} else if(s == scdk::SCStyledBorder::SINGLE) {
		_borderStyle = SINGLE;
		_ls = _rs = 179;//'|';
		_ts = _bs = 205;//'-';
		_tl = 218; _tr = 191;
		_bl = 192; _br = 217;
	} else if(s == scdk::SCStyledBorder::DOUBLE) {
		_borderStyle = DOUBLE;
		_ls = _rs = 186;//'||';
		_ts = _bs = 205;//'=';
		_tl = 201; _tr = 187;
		_bl = 200; _br = 188;
	}

	drawBorder();
}

void scdk::SCStyledBorder::setBorderStyleCustom(int ls, int rs, int ts, int bs, 
						int tl, int tr, int bl, int br) {
	_borderStyle = CUSTOM;
	_ls = ls; _rs = rs;
	_ts = ts; _bs = bs;
	_tl = tl; _tr = tr;
	_bl = bl; _br = br;
	drawBorder();
}
