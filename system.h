/****************************************************************************
 * system.h: Contains Interface for base class System for other classes     *
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
 *  Author: Sheikh Mohammad Sajid<smsajid786@yahoo.com> 2006                *
 ****************************************************************************/

#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <ncurses.h>
#include <signal.h>
#include <cstdlib>

namespace scdk {

/*extern void before_endwin();
extern void after_endwin();

//callback function in case of errors
static void finish(int sig) {
	// do your curses wrapup here
	before_endwin();
	
	endwin();

    // do your non-curses wrapup here
    after_endwin();

    exit(0);
}
*/
class SCSystem: public SCObject {
private:
	//Is the ncurses system up?
	static bool _nc_loaded;
	static bool _has_color;

public:
	static int start() {
		int ret = OK;

		if(!_nc_loaded) { //if it's not already started, start it
			WINDOW* w = initscr();

			if(w == NULL)
				ret = ERR;
			else {
				ret = OK;

				if(_has_color) {
					SCColor::initColor();
				}
				_nc_loaded = true;
			}

			//signal to shutdown curses
			(void) signal(SIGINT, stop);
		}
		
		return ret;
	}

	static void stop(int sig = SIGINT) {
		if(_nc_loaded) {
			/* do your curses wrapup here */
			before_stop();

			endwin();

			/* do your non-curses wrapup here */
			after_stop();

			exit(0);
		}
	}

	static void setColorSupport(bool c) {
		_has_color = c;
	}

	static bool getColorSupport() {
		return _has_color;
	}
	
	static void before_stop() {
	
	}
	
	static void after_stop() {
	
	}
};

/*Initialise static member fields*/
bool scdk::SCSystem::_nc_loaded = false;
bool scdk::SCSystem::_has_color = true;

}

#endif
