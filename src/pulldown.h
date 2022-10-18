/*

 ORIGINAL FILE NAME : pulldown.h

 ********************************************************************
 *                                                                  *
 *           X F C E  - Written by O. Fourdan (c) 1997              *
 *                                                                  *
 *           This software is absolutely free of charge             *
 *                                                                  *
 ********************************************************************

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHOR (O. FOURDAN) BE 
  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN 
  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/



#ifndef FD_pullmenu_h_
#define FD_pullmenu_h_

#include <forms.h>
#include "constant.h"


extern void pullmenu_cb(FL_OBJECT *, long);
extern void addicon_cb(FL_OBJECT *, long);

typedef struct {
	FL_OBJECT * button;
	FL_OBJECT * icon;
	char 	  * label;
	char      * pixfile;
	char      * command;
} ST_item;

typedef struct {
	FL_FORM *pullmenu;
	ST_item    *menuitem[NBMAXITEMS];
	FL_OBJECT * botframe;
	FL_OBJECT * addbutton;
	FL_OBJECT * addicon;
	void *vdata;
	long ldata;
	int nbitems;
} FD_pullmenu;

typedef struct {
	char *command;
} ST_select;

extern FD_pullmenu *create_form_menu(int no_menu);
extern void set_item_menu(FD_pullmenu *, int, char *, char *, char *);
extern void add_item_menu(FD_pullmenu *, char *, char *, char *);
extern void popup_pulldown(FD_pullmenu *, FL_Coord, FL_Coord);

#endif /* FD_pullmenu_h_ */
