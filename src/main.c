/*

 ORIGINAL FILE NAME : main.c

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



#include <signal.h>
#include "forms.h"
#include "XFCE.h"
#include "startup.h"
#include "pulldown.h"
#include "addicon.h"
#include "info.h"
#include "screen.h"
#include "command.h"
#include "defcolor.h"
#include "color.h"
#include "configfile.h"
#include "constant.h"
#include "XFCE_icon.h"

/**** Main window ****/

int 			FVWM; /* 0 means no FVWM, 1 means FVWM Ok */
int			fd[2];
FD_XFCE * 		fd_XFCE;
FD_addiconform * 	fd_addiconform;
FD_pullmenu * 		menus[NBMENUS];
ST_select 		selects[NBSELECTS];
FD_info *		fd_info;
FD_def_command *	fd_def_command;
FD_def_screen *		fd_def_screen;
FD_def_color *		fd_def_color;
XFCE_palette *		palette;

char * logo = "/XFCE.logo";

void initmenus(void)
{
   int i;
   for(i=0; i<NBMENUS; i++) menus[i] = create_form_menu(i);
}

void handlesignal(int dummy)
{
  writetoconfig();
  exit(0);
}

int Atclose_cb(FL_FORM * F, void * p)
{
  handlesignal(0);
}

int initforfvwm(int argc, char *argv[])
{
  char *temp, *s, *cptr;
  char *display_name = NULL;
  int itemp,i;
  char line[100];
  char mask_mesg[50];

  if(argc  < 6)
    {   /* XFCE has not been lauched as an FVWM module */
	return 0;
    }
  
  /* Load pipe */
  fd[0] = atoi(argv[1]);
  fd[1] = atoi(argv[2]);

  /* Switch to screen 0 by default */
  sendinfo(fd,"Desk 0 0",0);
  /* We're are probably using FVWM */
  return 1;
}

int main(int argc, char *argv[])
{
   FL_IOPT flopt;
   Pixmap icon, mask;
   unsigned w, h;  
   
   fl_initialize(&argc, argv, 0, 0, 0);
   flopt.borderWidth=-BORDERWIDTH;
   fl_set_defaults(FL_PDBorderWidth, &flopt);

#ifdef USE_SET_FONT_NAME
   fl_set_font_name(XFTINY, XFCE_TINY);  
   fl_set_font_name(XFREG,  XFCE_REGULAR);  
   fl_set_font_name(XFBOLD, XFCE_BOLD);  
   fl_set_font_name(XFBIG,  XFCE_BIG);  
   fl_set_font_name(XFTIT,  XFCE_TITLE);
#endif
   palette=newpal();
   initpal(palette);
   defpal(palette);
   loadpal(palette);
   applypal(palette);

   open_startup();
   fl_set_goodies_font(FL_BOLD_STYLE,FL_NORMAL_SIZE);
   icon = fl_create_from_pixmapdata(fl_root, XFCE_icon, &w, &h, &mask, 0, 0, 0);
   FVWM = initforfvwm(argc, argv);
   initmenus();
   fd_XFCE 	  = create_form_XFCE();
   readconfig();
   fd_addiconform = create_form_addiconform();
   fd_info        = create_form_info();
   fd_def_command = create_form_def_command();
   fd_def_screen  = create_form_def_screen();
   fd_def_color   = create_form_def_color();
   fl_set_form_icon(fd_XFCE->XFCE,               icon, mask);
   fl_set_form_icon(fd_addiconform->addiconform, icon, mask);
   fl_set_form_icon(fd_info->info,               icon, mask);
   fl_set_form_icon(fd_def_command->defcom,      icon, mask);
   fl_set_form_icon(fd_def_screen->def_screen,   icon, mask);
   fl_set_form_icon(fd_def_color->defcolor,      icon, mask);
   close_startup();

   /* Hanldle system signals */
   signal(SIGPIPE, handlesignal);  
   signal(SIGINT,  handlesignal);  
   signal(SIGTERM, handlesignal);  
   signal(SIGQUIT, handlesignal);  
   signal(SIGABRT, handlesignal);
   signal(SIGBUS , handlesignal);  
   signal(SIGUSR1, handlesignal);  
   signal(SIGUSR2, handlesignal);  
   fl_set_form_atclose(fd_XFCE->XFCE, 		    Atclose_cb, NULL);
   fl_set_form_atclose(fd_addiconform->addiconform, Atclose_cb, NULL);
   fl_set_form_atclose(fd_info->info, 		    Atclose_cb, NULL);
   fl_set_form_atclose(fd_def_command->defcom, 	    Atclose_cb, NULL);
   fl_set_form_atclose(fd_def_screen->def_screen,   Atclose_cb, NULL);
   fl_set_form_atclose(fd_def_color->defcolor, 	    Atclose_cb, NULL);
   

   /* show the first form */
   fl_show_form(fd_XFCE->XFCE,FL_PLACE_POSITION+FL_FIX_SIZE,
   					FL_TRANSIENT, "XFCE");
   fl_do_forms();
   writetoconfig();
   return 0;
}
