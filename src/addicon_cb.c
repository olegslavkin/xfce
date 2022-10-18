/*

 ORIGINAL FILE NAME : addicon_cb.c

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
#include "addicon.h"
#include "defaulticon.h"
#include "empty.h"
#include "fileutil.h"
#include "pulldown.h"
#include "constant.h"
#include "extern.h"

extern FD_addiconform *fd_addiconform;

void define_icondata(FD_addiconform *f, int no_menu, int pos)
{
  set_item_menu(menus[no_menu], pos, (char *) fl_get_input(f->label_input),
  				     (char *) fl_get_input(f->pixfile_input),
  				     (char *) fl_get_input(f->comline_input));
}

void add_icondata(FD_addiconform *f, int no_menu)
{
  add_item_menu(menus[no_menu], (char *) fl_get_input(f->label_input),
  				(char *) fl_get_input(f->pixfile_input),
  				(char *) fl_get_input(f->comline_input));
}

void remove_icondata(FD_addiconform *f, int no_menu, int pos)
{ int i, last;
  if(menus[no_menu]->nbitems > 0)
  {
    last = --menus[no_menu]->nbitems;
    for(i=pos; i<menus[no_menu]->nbitems; i++)
      set_item_menu(menus[no_menu], i, menus[no_menu]->menuitem[i+1]->label,
  				       menus[no_menu]->menuitem[i+1]->pixfile,
  				       menus[no_menu]->menuitem[i+1]->command);
  /* Move the last object so it does not overlap the border */
  fl_set_object_position(menus[no_menu]->menuitem[last]->icon,
    		  	BORDERWIDTH,ICONHEIGHT*(last+1)+2*BORDERWIDTH); 
  fl_set_object_position(menus[no_menu]->menuitem[last]->button,
  		ICONWIDTH+BORDERWIDTH,ICONHEIGHT*(last+1)+2*BORDERWIDTH);
  strcpy(menus[no_menu]->menuitem[last]->label, "Empty");
  strcpy(menus[no_menu]->menuitem[last]->pixfile, "Default");
  strcpy(menus[no_menu]->menuitem[last]->command, "");
  }
}

void redraw_pixmap(const char * pixfile)
{
   fl_set_pixmap_data(fd_addiconform->previewpix, empty);
   if(existfile(pixfile)) {
        fl_set_pixmap_file(fd_addiconform->previewpix, pixfile); }
   else {
        fl_set_pixmap_data(fd_addiconform->previewpix, defaulticon); }
   fl_redraw_form(fd_addiconform->addiconform);
   fl_redraw_object(fd_addiconform->iconframe);
}

/* callbacks for form addiconform */

void dummy_callback(FL_OBJECT *ob, long data)
{
  ;
}

void br_comline_cb(FL_OBJECT *ob, long data)
{
  const char * fselect;
  fselect=fl_show_fselector("Choose file to execute :", XBINDIR, "*","");
  if (fselect)
  	if(strlen(fselect)) 
  	    fl_set_input(fd_addiconform->comline_input, fselect);
}

void br_iconpix_cb(FL_OBJECT *ob, long data)
{
  const char * fselect;
  fselect=fl_show_fselector("Choose your icon :", XPIXMAPDIR, "*.xpm","");
  if (fselect) 
  	if(strlen(fselect)) {
  	    redraw_pixmap(fselect);
   	    if(existfile(fselect)) {
                fl_set_input(fd_addiconform->pixfile_input, fselect); }
   	    else {
                fl_set_input(fd_addiconform->pixfile_input, "Default"); }
   	    fl_redraw_form(fd_addiconform->addiconform); }
}

void update_pixfile(FL_OBJECT *ob, long data)
{
    const char *s;
    s = fl_get_input(fd_addiconform->pixfile_input);
    redraw_pixmap(s);
}

void ai_ok_cb(FL_OBJECT *ob, long data)
{
  const char * s1, * s2;
  int x1, x2;
  
  s1 = (char *) skiphead(fl_get_input(fd_addiconform->comline_input));
  if (strlen(s1)) skiptail(s1);
  s2 = (char *) skiphead(fl_get_input(fd_addiconform->label_input));
  if (strlen(s2)) skiptail(s2);
  x1 = strlen(s1);
  x2 = strlen(s2);
  if (x1 && x2) {
      if(data < 0) {
        add_icondata(fd_addiconform, -data/NBMAXITEMS); }
      else {
        define_icondata(fd_addiconform, data / NBMAXITEMS, 
      				        data % NBMAXITEMS); }
      fl_activate_all_forms();
      fl_hide_form((FL_FORM *)fd_addiconform->addiconform);
  } else {
      fl_show_alert("Please fill out command \nand label fields...","","",1);
  }
}

void ai_cancel_cb(FL_OBJECT *ob, long data)
{
  fl_activate_all_forms();
  fl_hide_form((FL_FORM *)fd_addiconform->addiconform);
}

void ai_remove_cb(FL_OBJECT *ob, long data)
{
  if(data >= 0)
#if FL_REVISION>=84
    if(fl_show_question("Are you sure you want to remove\nthis entry ?",1) == 1) {
#else
    if(fl_show_question("Are you sure you want to remove", 
    			"this entry ?",
                  	" ") == 1) {
#endif

        remove_icondata(fd_addiconform, data / NBMAXITEMS, 
  			                data % NBMAXITEMS); }
    fl_activate_all_forms();
    fl_hide_form((FL_FORM *)fd_addiconform->addiconform);
}
