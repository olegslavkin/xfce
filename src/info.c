/*

 ORIGINAL FILE NAME : info.c

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
#include "info.h"
#include "constant.h"
#include "version.h"

extern char * logo;


FD_info *create_form_info(void)
{
  FL_OBJECT *obj;
  FD_info *fdui = (FD_info *) fl_calloc(1, sizeof(*fdui));
  char * xfcedir;

  xfcedir = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
  strcpy(xfcedir, XFCE_DIR);
  strcat(xfcedir, logo);

  fdui->info = fl_bgn_form(FL_NO_BOX, 270, 370);
  obj = fl_add_box(FL_BORDER_BOX,0,0,270,370,"");
  fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
  if (fl_get_visual_depth()>4) {
    obj = fl_add_pixmap(FL_NORMAL_PIXMAP,10,10,250,120,XFCE_VERNUM);
      fl_set_object_boxtype(obj, FL_FRAME_BOX);
      fl_set_object_lalign(obj,FL_ALIGN_BOTTOM_RIGHT|FL_ALIGN_INSIDE);
      fl_set_object_lsize(obj,XFCE_TINY_SIZE);
      fl_set_pixmap_file(obj, xfcedir); }
  else {
    obj = fl_add_text(FL_NORMAL_TEXT,10,10,230,83,"XFCE");
      fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
      fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
      fl_set_object_lsize(obj,XFCE_HUGE_SIZE);
      fl_set_object_lstyle(obj,XFTIT+FL_ENGRAVED_STYLE); }  
  obj = fl_add_text(FL_NORMAL_TEXT,10,140,250,30,"Written by Olivier FOURDAN (c) 1997");
    fl_set_object_boxtype(obj,FL_DOWN_BOX);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lstyle(obj,XFREG+FL_EMBOSSED_STYLE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,180,230,20,"This software is distributed \"as is\" without");
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,200,230,20,"expressed or implied warranty of any kind.");
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,220,230,20,"The author disclaims all waranties with regard");
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,240,230,20,"to this software. In no event, the author will be");
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,260,230,20,"liable for any special, indirect or consequential");
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,280,230,20,"damages resulting from loss of use, data or");
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,300,230,20,"profits in connection with this software.");
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,10,180,250,140,"");
  fdui->OK_info = obj = fl_add_button(FL_NORMAL_BUTTON,60,330,140,30,"Agreement");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_button_shortcut(obj,"^O^M#O",1);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,OK_info_cb,0);
  fl_end_form();

  free(xfcedir);
  return fdui;
}
/*---------------------------------------*/

