/*

 ORIGINAL FILE NAME : pulldown.c

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



#include "forms.h"
#include <stdlib.h>
#include "pulldown.h"
#include "addiconpix.h"
#include "defaulticon.h"
#include "XFCE.h"
#include "constant.h"

FD_pullmenu *create_form_menu(int no_menu)
{
  FL_OBJECT *obj;
  int i;
  
  FD_pullmenu *fdui = (FD_pullmenu *) fl_calloc(1, sizeof(*fdui));

  /* The size of the form depends on how many items are displayed */
  /* Since we create it empty, there is only 1 item displayed  */
  fdui->pullmenu = fl_bgn_form(FL_NO_BOX, 150+ICONWIDTH+2*BORDERWIDTH, 
				  ICONHEIGHT*(NBMAXITEMS+1)+2*BORDERWIDTH);
  fdui->botframe=obj=fl_add_box(FL_UP_BOX,0,0, 150+ICONWIDTH+2*BORDERWIDTH,
  				  ICONHEIGHT*(NBMAXITEMS+1)+2*BORDERWIDTH,"");
  fl_set_object_color(obj, XFCE_COL8, XFCE_COL8);
  /* The first object is allways AddIcon button */
  /* Extra bonus : A little frame around this first item */
  fl_add_box(FL_FRAME_BOX, 
  		BORDERWIDTH, BORDERWIDTH, 150+ICONWIDTH, ICONHEIGHT, "");
  fdui->addicon = obj = fl_add_pixmap(FL_NORMAL_PIXMAP,
		BORDERWIDTH+2,BORDERWIDTH+2, ICONWIDTH-2,ICONHEIGHT-4,"");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
    fl_set_pixmap_data(obj, addiconpix);
    fl_set_object_boxtype(obj,FL_DOWN_BOX);
  fdui->addbutton = obj = fl_add_button(FL_NORMAL_BUTTON, 
       ICONWIDTH+BORDERWIDTH,BORDERWIDTH+2,150-2, ICONHEIGHT-4,"Add icon...");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    fl_set_object_lsize(obj,XFCE_MEDIUM_SIZE);
    fl_set_object_lstyle(obj,XFTIT+FL_SHADOW_STYLE);
    fl_set_object_callback(obj, addicon_cb, no_menu);
  /* Create all buttons empty, that will be filled later */
  for(i=0; i<NBMAXITEMS; i++) {
    fdui->menuitem[i] = (ST_item *) malloc(sizeof(ST_item));
    fdui->menuitem[i]->label = (char *) malloc (sizeof(char)*256);
    strcpy(fdui->menuitem[i]->label, "Empty");
    fdui->menuitem[i]->pixfile = (char *) malloc (sizeof(char)*MAXSTRLEN + 1);
    strcpy(fdui->menuitem[i]->pixfile, "Default");
    fdui->menuitem[i]->command = (char *) malloc (sizeof(char)*MAXSTRLEN + 1);
    strcpy(fdui->menuitem[i]->command, "");
    fdui->menuitem[i]->icon = obj = fl_add_pixmap(FL_NORMAL_PIXMAP,
	BORDERWIDTH,ICONHEIGHT*(i+1)+2*BORDERWIDTH,ICONWIDTH,ICONHEIGHT, "");
      fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
      fl_set_object_boxtype(obj,FL_DOWN_BOX);
    fdui->menuitem[i]->button = obj = fl_add_button(FL_NORMAL_BUTTON,
	ICONWIDTH+BORDERWIDTH,ICONHEIGHT*(i+1)+2*BORDERWIDTH,150,ICONHEIGHT,"");
      fl_set_object_boxtype(obj,FL_FLAT_BOX);
      fl_set_object_lcol(obj,FL_WHITE);
      fl_set_object_lalign(obj,FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
      fl_set_object_lsize(obj,XFCE_MEDIUM_SIZE);
      fl_set_object_lstyle(obj,XFTIT+FL_SHADOW_STYLE);
      fl_set_object_callback(obj, pullmenu_cb, no_menu*NBMAXITEMS+i);
  }
  fl_end_form();
  fdui->nbitems = 0;
  return fdui;
}

void set_item_menu(FD_pullmenu * menu, int no_item, 
		   char * label, char * pixfile, char * command)  
{
  if (label) { 
    strcpy(menu->menuitem[no_item]->label, label);
    strcpy(menu->menuitem[no_item]->button->label, label); }
  if (command) strcpy(menu->menuitem[no_item]->command, command);
  if ((pixfile) && (existfile(pixfile))) {
    strcpy(menu->menuitem[no_item]->pixfile, pixfile);
    fl_set_pixmap_file(menu->menuitem[no_item]->icon,
    		       menu->menuitem[no_item]->pixfile ); }
  else {
    strcpy(menu->menuitem[no_item]->pixfile, "Default");
    fl_set_pixmap_data(menu->menuitem[no_item]->icon, defaulticon); }
}

void add_item_menu(FD_pullmenu * menu, char * label, char * pixfile,
		   char * command)
{
  if (menu->nbitems<NBMAXITEMS) {
    set_item_menu(menu, menu->nbitems, label, pixfile, command);
    /* Move the object so it does not overlap the border */
    fl_set_object_position(menu->menuitem[menu->nbitems]->icon,
    			BORDERWIDTH,ICONHEIGHT*(menu->nbitems+1)+BORDERWIDTH); 
    fl_set_object_position(menu->menuitem[menu->nbitems]->button,
    		ICONWIDTH+BORDERWIDTH,ICONHEIGHT*(menu->nbitems+1)+BORDERWIDTH);
    menu->nbitems++;
  }
}

void popup_pulldown(FD_pullmenu * menu, FL_Coord px, FL_Coord py)
{
  int n, w, h;
  n = ICONHEIGHT*(menu->nbitems+1);
  w = 150+ICONWIDTH+2*BORDERWIDTH;
  h = n+2*BORDERWIDTH;
  menu->pullmenu->x = px-(150+ICONWIDTH)/2-BORDERWIDTH;
  menu->pullmenu->y = py-n-2*BORDERWIDTH;
  menu->pullmenu->w = w;
  menu->pullmenu->h = h;
  fl_set_object_size(menu->botframe, w, h);
  fl_show_form(menu->pullmenu, FL_PLACE_POSITION, FL_NOBORDER,"");
  fl_do_forms();
}
 
/*---------------------------------------*/

