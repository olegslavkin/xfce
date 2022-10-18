/*

 ORIGINAL FILE NAME : XFCE_cb.c

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
#include "XFCE.h"
#include "pulldown.h"
#include "addicon.h"
#include "configfile.h"
#include "fileutil.h"
#include "sendinfo.h"
#include "constant.h"
#include "extern.h"

void move_cb(FL_OBJECT *ob, long data)
{
      if (FVWM) sendinfo(fd,"Move",0);
}

void popup_cb(FL_OBJECT *ob, long data)
{
   FL_Coord x, y, w, h;
   int n;
   
   /* change callback function so it closes popup when button pressed */
   fl_set_object_callback(ob, close_popup, data);
   /* Then show menu and wait for events */
   /* Display down arrow in button */
   ToggleButtonDn(fd_XFCE, ob);
   /* Then displays items of menu */
   fl_get_object_geometry(ob, &x, &y, &w ,&h);
   popup_pulldown(menus[data], fd_XFCE->XFCE->x+x+w/2, 
   				fd_XFCE->XFCE->y+y);
}

void select_cb(FL_OBJECT *ob, long data)
{
   if((((FL_BUTTON_STRUCT *)ob->spec)->mousebut) == BUTTONCHANGE) {   
      fl_set_object_callback(fd_def_command->defcom_ok_but, OK_defcom_cb, data);
      fl_set_input(fd_def_command->command_input, selects[data].command);
      fl_deactivate_all_forms();
      fl_show_form(fd_def_command->defcom,FL_PLACE_CENTER,
      		   FL_TRANSIENT,"Define command..."); }
    else {
      if ((strncasecmp(selects[data].command, "None", strlen("None")))
       && (strncasecmp(selects[data].command, "Nothing", strlen("Nothing"))))
        exec_comm(selects[data].command); }
}

void screen_cb(FL_OBJECT *ob, long data)
{
   char command[256];

   if (FVWM) {
     sprintf(command,"Desk 0 %d\n",data);
     sendinfo(fd,command,0); }
   else {
     fl_show_alert("Sorry, this function only works with FVWM !", 
                 "You have to launch XFCE as a FVWM module to make this work.",
                 "Type \"man fvwm\" for more info about FVWM.", 0); }
   if((((FL_BUTTON_STRUCT *)ob->spec)->mousebut) == BUTTONCHANGE) {
       fl_set_input(fd_def_screen->screen_input, fd_XFCE->screen[data]->label);
       fl_set_object_callback(fd_def_screen->OKbutton, OK_screen_cb, data);
       fl_deactivate_all_forms();
       fl_show_form(fd_def_screen->def_screen, FL_PLACE_CENTER,FL_TRANSIENT,"Name screen..."); }
}

void info_cb(FL_OBJECT *ob, long data)
{
   fl_deactivate_all_forms();
   fl_show_form(fd_info->info,FL_PLACE_CENTER, FL_TRANSIENT,"Info...");
}

void save_cb(FL_OBJECT *ob, long data)
{
   writetoconfig();
}

void quit_cb(FL_OBJECT *ob, long data)
{
#if FL_REVISION>=84
    if(fl_show_question("Are you sure you want to quit ?\nThis might log you off",1) == 1) {
#else
    if(fl_show_question("Are you sure you want to quit ?", 
    			"This might log you off",
                  	" ") == 1) {
#endif
      writetoconfig();
      if (FVWM) sendinfo(fd,"Quit\n",0);
      exit(0); }
}

void setup_cb(FL_OBJECT *ob, long data)
{
   fl_deactivate_all_forms();
   fl_set_button(fd_def_color->color_button[0], 1);
   select_color(fd_def_color->color_button[0], 0);
   fl_show_form(fd_def_color->defcolor,FL_PLACE_CENTER, FL_TRANSIENT,"Define colors...");
}

void close_popup(FL_OBJECT *ob, long data)
{
   int n;
   
   ToggleButtonUp(fd_XFCE, fd_XFCE->popup[data]); 
   fl_set_object_callback(fd_XFCE->popup[data], popup_cb, data);
   fl_hide_form(menus[data]->pullmenu);
}

/* callbacks for form pullmenu */

void pullmenu_cb(FL_OBJECT *ob, long data)
{
    int menucol, menulig;
    
    menucol = data / NBMAXITEMS;
    menulig = data % NBMAXITEMS;
    close_popup(ob, menucol);
    if((((FL_BUTTON_STRUCT *)ob->spec)->mousebut) == BUTTONCHANGE) {   
       set_addiconform(fd_addiconform, menucol, menulig);
       set_addicon_cb(fd_addiconform, menucol, menulig);
       fl_deactivate_all_forms();
       fl_show_form(fd_addiconform->addiconform,
                    FL_PLACE_CENTER,FL_TRANSIENT,"Modify item..."); }
    else exec_comm(menus[menucol]->menuitem[menulig]->command);
}

void addicon_cb(FL_OBJECT *ob, long data)
{
   int menucol;
   
   menucol = data % NBMAXITEMS;
   close_popup(ob, menucol);
   if (menus[menucol]->nbitems<NBMAXITEMS) {
     set_addiconform(fd_addiconform, menucol, -1);
     /* That's a convention : If the parameter is negative, we add an icon */
     set_addicon_cb(fd_addiconform, -menucol, -1);
     fl_deactivate_all_forms();
     fl_show_form(fd_addiconform->addiconform,
                  FL_PLACE_CENTER,FL_TRANSIENT,"Add item..."); }
   else {
     fl_show_alert("Sorry, this menu is full !", 
                   "Try to add items to another one", "", 0); }
}
