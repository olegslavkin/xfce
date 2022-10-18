/*

 ORIGINAL FILE NAME : command_cb.c

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

void DM_com_cb(FL_OBJECT *ob, long data)
{
    ;
}

void br_com_cb(FL_OBJECT *ob, long data)
{
  char * fselect;
  fselect=skiphead((char *) fl_show_fselector("Choose command :",
  			    XBINDIR, "*",""));
  if (fselect) {
    if (strlen(fselect)) skiptail(fselect);
    if (!strlen(fselect) || !strncasecmp(fselect, "None", strlen("None"))) {
      strcpy(selects[data].command, "None"); }
    else {
      strcpy(selects[data].command, fselect); }
    fl_set_input(fd_def_command->command_input, selects[data].command);
    fl_redraw_form(fd_def_command->defcom);
  }
}

void OK_defcom_cb(FL_OBJECT *ob, long data)
{
    char *s;

    s = skiphead((char *) fl_get_input(fd_def_command->command_input));
    if (strlen(s)) skiptail(s);
    if (!strlen(s) || !strncasecmp(s, "None", strlen("None"))) {
      strcpy(selects[data].command, "None"); }
    else {
      strcpy(selects[data].command, s); }
    fl_activate_all_forms();
    fl_hide_form(fd_def_command->defcom);
    #ifdef ALLWAYS_SAVE
        writetoconfig();
    #endif
}

void CANCEL_defcom_cb(FL_OBJECT *ob, long data)
{
    fl_activate_all_forms();
    fl_hide_form(fd_def_command->defcom);
}



