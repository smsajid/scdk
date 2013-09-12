/****************************************************************************
 * color.cpp: Contains Implementation for Color class                       *
 * Version  : 0.1                                                           *
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

#include "color.h"

unsigned int scdk::SCColor::color_lookup[8][8] = {
//background->	BLACK   RED	  GREEN  YELLOW	  BLUE  MAGENTA	 CYAN   WHITE
/*BLACK*/		1,		2,	  3,	 4,		  5,	6,		 7,		8,
/*RED*/			9,		10,	  11,	 12,	  13,   14,		 15,	16,
/*GREEN*/		17,	    18,	  19,	 20,	  21,	22,		 23,	24,
/*YELLOW*/		25,		26,	  27,	 28,	  29,	30,		 31,	32,
/*BLUE*/		33,		34,	  35,	 36,	  37,	38,		 39,	40,
/*MAGENTA*/		41,		42,	  43,    44,	  45,	46,		 47,	48,
/*CYAN*/		49,		50,	  51,	 52,	  53,	54,		 55,	56,
/*WHITE*/		0,		57,	  58,	 59,	  60,	61,		 62,	63
};

void
scdk::SCColor::initColor() {
	if(has_colors()) {
		start_color();
		//black background
		//init_pair(0, COLOR_WHITE,   COLOR_RED);//not required, it is default
		init_pair(1,  COLOR_BLACK,   COLOR_BLACK);
		init_pair(9,  COLOR_RED,     COLOR_BLACK);
		init_pair(17, COLOR_GREEN,   COLOR_BLACK);
		init_pair(25, COLOR_YELLOW,  COLOR_BLACK);
		init_pair(33, COLOR_BLUE,    COLOR_BLACK);
		init_pair(41, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(49, COLOR_CYAN,    COLOR_BLACK);
		//red background
		init_pair(2,  COLOR_BLACK,   COLOR_RED);
		init_pair(10, COLOR_RED,     COLOR_RED);
		init_pair(17, COLOR_GREEN,   COLOR_RED);
		init_pair(23, COLOR_YELLOW,  COLOR_RED);
		init_pair(22, COLOR_BLUE,    COLOR_RED);
		init_pair(21, COLOR_MAGENTA, COLOR_RED);
		init_pair(19, COLOR_CYAN,    COLOR_RED);
		init_pair(20, COLOR_WHITE,   COLOR_RED);
		//green background
		init_pair(3,  COLOR_BLACK,   COLOR_GREEN);
		init_pair(11, COLOR_RED,     COLOR_GREEN);
		init_pair(19, COLOR_GREEN,   COLOR_GREEN);
		init_pair(27, COLOR_YELLOW,  COLOR_GREEN);
		init_pair(35, COLOR_BLUE,    COLOR_GREEN);
		init_pair(43, COLOR_MAGENTA, COLOR_GREEN);
		init_pair(51, COLOR_CYAN,    COLOR_GREEN);
		init_pair(58, COLOR_WHITE,   COLOR_GREEN);
		//yellow background
		init_pair(4,  COLOR_BLACK,   COLOR_YELLOW);
		init_pair(12, COLOR_RED,     COLOR_YELLOW);
		init_pair(20, COLOR_GREEN,   COLOR_YELLOW);
		init_pair(28, COLOR_YELLOW,  COLOR_YELLOW);
		init_pair(36, COLOR_BLUE,    COLOR_YELLOW);
		init_pair(44, COLOR_MAGENTA, COLOR_YELLOW);
		init_pair(52, COLOR_CYAN,    COLOR_YELLOW);
		init_pair(59, COLOR_WHITE,   COLOR_YELLOW);
		//blue background
		init_pair(5,  COLOR_BLACK,   COLOR_BLUE);
		init_pair(13, COLOR_RED,     COLOR_BLUE);
		init_pair(21, COLOR_GREEN,   COLOR_BLUE);
		init_pair(29, COLOR_YELLOW,  COLOR_BLUE);
		init_pair(37, COLOR_BLUE,    COLOR_BLUE);
		init_pair(45, COLOR_MAGENTA, COLOR_BLUE);
		init_pair(53, COLOR_CYAN,    COLOR_BLUE);
		init_pair(60, COLOR_WHITE,   COLOR_BLUE);
		//magenta background
		init_pair(6,  COLOR_BLACK,   COLOR_MAGENTA);
		init_pair(14, COLOR_RED,     COLOR_MAGENTA);
		init_pair(22, COLOR_GREEN,   COLOR_MAGENTA);
		init_pair(30, COLOR_YELLOW,  COLOR_MAGENTA);
		init_pair(38, COLOR_BLUE,    COLOR_MAGENTA);
		init_pair(46, COLOR_MAGENTA, COLOR_MAGENTA);
		init_pair(54, COLOR_CYAN,    COLOR_MAGENTA);
		init_pair(61, COLOR_WHITE,   COLOR_MAGENTA);
		//cyan background
		init_pair(7,  COLOR_BLACK,   COLOR_CYAN);
		init_pair(15, COLOR_RED,     COLOR_CYAN);
		init_pair(23, COLOR_GREEN,   COLOR_CYAN);
		init_pair(31, COLOR_YELLOW,  COLOR_CYAN);
		init_pair(39, COLOR_BLUE,    COLOR_CYAN);
		init_pair(47, COLOR_MAGENTA, COLOR_CYAN);
		init_pair(55, COLOR_CYAN,    COLOR_CYAN);
		init_pair(62, COLOR_WHITE,   COLOR_CYAN);
		//white background
		init_pair(8,  COLOR_BLACK,   COLOR_WHITE);
		init_pair(16, COLOR_RED,     COLOR_WHITE);
		init_pair(24, COLOR_GREEN,   COLOR_WHITE);
		init_pair(32, COLOR_YELLOW,  COLOR_WHITE);
		init_pair(40, COLOR_BLUE,    COLOR_WHITE);
		init_pair(48, COLOR_MAGENTA, COLOR_WHITE);
		init_pair(56, COLOR_CYAN,    COLOR_WHITE);
		init_pair(63, COLOR_WHITE,   COLOR_WHITE);
	}
}
