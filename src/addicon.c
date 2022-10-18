/*

 ORIGINAL FILE NAME : addicon.c

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
#include "addicon.h"
#include "pulldown.h"
#include "constant.h"
#include "defaulticon.h"
#include "empty.h"
#include "extern.h"

FD_addiconform *create_form_addiconform(void)
{
  FL_OBJECT *obj;
  FD_addiconform *fdui = (FD_addiconform *) fl_calloc(1, sizeof(*fdui));

  fdui->addiconform = fl_bgn_form(FL_NO_BOX, 570, 210);
  obj = fl_add_box(FL_BORDER_BOX,0,0,570,210,"");
  fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
  fdui->iconframe  = obj = fl_add_frame(FL_ENGRAVED_FRAME,20,20,90,90,"");
  fdui->previewpix = obj = fl_add_pixmap(FL_NORMAL_PIXMAP,40,40,50,50,"");
  fdui->comline_input = obj = fl_add_input(FL_NORMAL_INPUT,220,20,250,30,"Command line");
    fl_set_object_color(obj, XFCE_COL5,XFCE_COL5);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_SHADOW_STYLE);
    fl_set_object_callback(obj, dummy_callback, 0);
  fdui->pixfile_input = obj = fl_add_input(FL_NORMAL_INPUT,220,60,250,30,"Icon file");
    fl_set_object_color(obj,XFCE_COL5,XFCE_COL5);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_SHADOW_STYLE);
    fl_set_object_callback(obj, update_pixfile, 0);
  fdui->label_input = obj = fl_add_input(FL_NORMAL_INPUT,220,100,250,30,"Label");
    fl_set_object_color(obj,XFCE_COL5,XFCE_COL5);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_SHADOW_STYLE);
    fl_set_object_callback(obj, dummy_callback, 0);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,130,10,430,130,"");
  obj = fl_add_text(FL_NORMAL_TEXT,10,120,110,20,"Preview Icon");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
  fdui->br_comline = obj = fl_add_button(FL_NORMAL_BUTTON,480,20,70,30,"Browse...");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,br_comline_cb,0);
  fdui->br_iconpix = obj = fl_add_button(FL_NORMAL_BUTTON,480,60,70,30,"Browse...");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,br_iconpix_cb,0);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,150,150,390,50,"");
  fdui->OK = obj = fl_add_button(FL_NORMAL_BUTTON,160,160,110,30,"OK");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_button_shortcut(obj,"^O^M#O",1);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,ai_ok_cb,0);
  fdui->ai_cancel = obj = fl_add_button(FL_NORMAL_BUTTON,290,160,110,30,"Cancel");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_button_shortcut(obj,"^[^C#C",1);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,ai_cancel_cb,0);
  fdui->ai_remove = obj = fl_add_button(FL_NORMAL_BUTTON,420,160,110,30,"Remove");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,ai_remove_cb,0);
  fl_end_form();

  return fdui;
}

void set_addicon_cb(FD_addiconform *f, int no_menu, int pos)
{
  fl_set_object_callback(f->OK,ai_ok_cb, no_menu*NBMAXITEMS+pos);
  fl_set_object_callback(f->ai_remove,ai_remove_cb, no_menu*NBMAXITEMS+pos);
}

void set_addiconform(FD_addiconform *f, int no_menu, int pos)
{
  char *pixfile = menus[no_menu]->menuitem[pos]->pixfile;
  char *label   = menus[no_menu]->menuitem[pos]->label;
  char *command = menus[no_menu]->menuitem[pos]->command;
  
  if (pos < 0) {
    fl_set_pixmap_data(f->previewpix, empty);
    fl_set_input(f->pixfile_input, "");
    fl_set_input(f->label_input, "");
    fl_set_input(f->comline_input, ""); }
  else {
    if(existfile(pixfile)) {
        fl_set_pixmap_file(fd_addiconform->previewpix, pixfile); }
    else {
  	fl_set_pixmap_data(fd_addiconform->previewpix, defaulticon); }
    fl_set_input(f->pixfile_input, pixfile);
    fl_set_input(f->label_input, label);
    fl_set_input(f->comline_input, command); }
}

/*---------------------------------------*/

