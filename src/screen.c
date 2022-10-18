/*

 ORIGINAL FILE NAME : screen.c

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
#include "screen.h"
#include "constant.h"

FD_def_screen *create_form_def_screen(void)
{
  FL_OBJECT *obj;
  FD_def_screen *fdui = (FD_def_screen *) fl_calloc(1, sizeof(*fdui));

  fdui->def_screen = fl_bgn_form(FL_NO_BOX, 320, 130);
  obj = fl_add_box(FL_BORDER_BOX,0,0,320,130,"");
  fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,10,10,300,50,"");
  fdui->screen_input = obj = fl_add_input(FL_NORMAL_INPUT,130,20,170,30,"Enter new name :");
    fl_set_object_color(obj, XFCE_COL5,XFCE_COL5);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,DM_screen_cb,0);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,120,70,190,50,"");
  fdui->OKbutton = obj = fl_add_button(FL_NORMAL_BUTTON,130,80,80,30,"OK");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_button_shortcut(obj,"^O^M#O",1);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,OK_screen_cb,0);
  fdui->Cancelbutton = obj = fl_add_button(FL_NORMAL_BUTTON,220,80,80,30,"Cancel");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_button_shortcut(obj,"^[^C#C",1);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,CANCEL_screen_cb,0);
  fl_end_form();

  return fdui;
}
/*---------------------------------------*/

