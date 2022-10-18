/*

 ORIGINAL FILE NAME : screen_cb.c

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
#include "fileutil.h"
#include "configfile.h"
#include "extern.h"

void DM_screen_cb(FL_OBJECT *ob, long data)
{
	;
}

void OK_screen_cb(FL_OBJECT *ob, long data)
{
    char *r, *s, *t;
    int w, mw;

    r = skiphead((char *) fl_get_input(fd_def_screen->screen_input));
    s = (char *) malloc(256);
    t = (char *) malloc(256);
    if (strlen(r)) skiptail(r);
    strcpy(s, r);
    /* Avoid empty names or readconfig will fail on next run */
    if (!strlen(s)) {
        sprintf(t, "Screen %i", data + 1);
        strcpy(s, t);
    }
    w = fl_get_string_width(ob->lstyle, ob->lsize, s, strlen(s));
    if (w > fd_XFCE->screen[data]->w) {
      fl_show_alert("This name is too long to fit in button...","","",1); }
    else {
      strcpy(fd_XFCE->screen[data]->label, s);
      fl_redraw_object(fd_XFCE->screen[data]);
      fl_activate_all_forms();
      fl_hide_form((FL_FORM *)fd_def_screen->def_screen); 
      #ifdef ALLWAYS_SAVE
          writetoconfig();
      #endif
    }
    free(s);
    free(t);
}

void CANCEL_screen_cb(FL_OBJECT *ob, long data)
{
    fl_activate_all_forms();
    fl_hide_form((FL_FORM *)fd_def_screen->def_screen);
}
