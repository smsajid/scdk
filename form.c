#include<form.h>
#include<assert.h>

typedef void (*HOOK)();
char *ptr;
void getbuf()
{ 
	ptr=field_buffer(f1[0],0);
}

int main()
{	FIELD *f1[2];
	FORM  *frm1;
	chtype ch;
	int error;
	HOOK fptr=getbuf;
	
	initscr();
	f1[0]=new_field(24,80,0,0,1,1);
	assert(f1[0]!=NULL);
	f1[1]=NULL;
	frm1=new_form(f1);
	assert(frm1!=NULL);
	set_field_fore(f1[0],A_REVERSE);
	field_opts_off(f1[0],O_STATIC);
	//set_field_buffer(f1[0],0,"Sajid");
	set_field_type(f1[0],TYPE_ALPHA,80);
	set_field_term(f1[0],fptr);
	
	post_form(frm1);
	wrefresh(stdscr);
	keypad(stdscr,TRUE);
	
	while((ch=getch())!=KEY_F(3))
	{	switch(ch)
		{	case KEY_LEFT:
				error=form_driver(frm1,REQ_PREV_CHAR);
				if(error==E_REQUEST_DENIED)
					form_driver(frm1,REQ_SCR_BCHAR);
				break;
			case KEY_RIGHT:
				form_driver(frm1,REQ_NEXT_CHAR);
				break;
			default:
				form_driver(frm1,ch);
				break;
		}
	}
	unpost_form(frm1);
	free_form(frm1);
	free_field(f1[0]);
	getch();
	printw(ptr);
	endwin();
}
