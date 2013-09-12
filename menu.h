//menu
#ifndef _MENU_H
#define _MENU_H

#include <form.h>
#include<menu.h>
#include "object.h"
#include "window.h"

namespace scdk {

class Menu: public Object {
protected:
	ITEM ***items;
	MENU **menubar;
	WINDOW *Owner;

public:
	Menu(Window *ptro,...);
};

}//namespace

#endif
