/*

 ORIGINAL FILE NAME : command.c

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
#include "command.h"
#include "constant.h"

FD_def_command *create_form_def_command(void)
{
  FL_OBJECT *obj;
  FD_def_command *fdui = (FD_def_command *) fl_calloc(1, sizeof(*fdui));

  fdui->defcom = fl_bgn_form(FL_NO_BOX, 490, 130);
  fdui->def_command = obj = fl_add_box(FL_BORDER_BOX,0,0,490,130,"");
  obj = fl_add_frame(FL_ENGRAVED_FRAME,10,10,470,50,"");
  fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
  fdui->command_input = obj = fl_add_input(FL_NORMAL_INPUT,110,20,270,30,"New command ");
    fl_set_object_color(obj,XFCE_COL5,XFCE_COL5);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,DM_com_cb,0);
  fdui->br_command = obj = fl_add_button(FL_NORMAL_BUTTON,390,20,80,30,"Browse");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,br_com_cb,0);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,240,70,240,50,"");
  fdui->defcom_ok_but = obj = fl_add_button(FL_NORMAL_BUTTON,250,80,100,30,"OK");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_button_shortcut(obj,"^O^M#O",1);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,OK_defcom_cb,0);
  fdui->defcom_cancel_but = obj = fl_add_button(FL_NORMAL_BUTTON,370,80,100,30,"Cancel");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_button_shortcut(obj,"^[^C#C",1);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,CANCEL_defcom_cb,0);
  fl_end_form();

  return fdui;
}
/*---------------------------------------*/

