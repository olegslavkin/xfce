/*

 ORIGINAL FILE NAME : defcolor.c

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
#include "extern.h"
#include "defcolor.h"
#include "color.h"

int current_col;

FD_def_color *create_form_def_color(void)
{
  FL_OBJECT *obj;
  FD_def_color *fdui = (FD_def_color *) fl_calloc(1, sizeof(*fdui));

  fdui->defcolor = fl_bgn_form(FL_FLAT_BOX, 330, 330);
  obj = fl_add_box(FL_NO_BOX,0,0,330,330,"");
  fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,10,10,310,250,"");
  obj = fl_add_frame(FL_ENGRAVED_FRAME,20,20,290,80,"");
  obj = fl_add_frame(FL_ENGRAVED_FRAME,20,110,290,110,"");
  fdui->rs = obj = fl_add_valslider(FL_HOR_SLIDER,30,30,270,20,"");
    fl_set_object_color(obj,XFCE_COL5,FL_RED);
    fl_set_object_lsize(obj,FL_DEFAULT_SIZE);
    fl_set_object_lstyle(obj,FL_FIXED_STYLE);
    fl_set_slider_bounds(obj, 0, 255);
    fl_set_slider_precision(obj, 0);
    fl_set_object_callback(obj,create_rgb,0);
    fl_set_slider_return(obj, FL_RETURN_CHANGED);
  fdui->gs = obj = fl_add_valslider(FL_HOR_SLIDER,30,50,270,20,"");
    fl_set_object_color(obj,XFCE_COL5,FL_GREEN);
    fl_set_object_lsize(obj,FL_DEFAULT_SIZE);
    fl_set_object_lstyle(obj,FL_FIXED_STYLE);
    fl_set_slider_bounds(obj, 0, 255);
    fl_set_slider_precision(obj, 0);
    fl_set_object_callback(obj,create_rgb,1);
    fl_set_slider_return(obj, FL_RETURN_CHANGED);
  fdui->bs = obj = fl_add_valslider(FL_HOR_SLIDER,30,70,270,20,"");
    fl_set_object_color(obj,XFCE_COL5,FL_BLUE);
    fl_set_object_lsize(obj,FL_DEFAULT_SIZE);
    fl_set_object_lstyle(obj,FL_FIXED_STYLE);
    fl_set_slider_bounds(obj, 0, 255);
    fl_set_slider_precision(obj, 0);
    fl_set_object_callback(obj,create_rgb,2);
    fl_set_slider_return(obj, FL_RETURN_CHANGED);
  fdui->color_button[0] = obj = fl_add_button(FL_RADIO_BUTTON,30,120,60,40,"");
    fl_set_object_color(obj, palette->cm[0], palette->cm[0]);
    fl_set_object_callback(obj,select_color,0);
  fdui->color_button[1] = obj = fl_add_button(FL_RADIO_BUTTON,100,120,60,40,"");
    fl_set_object_color(obj, palette->cm[1], palette->cm[1]);
    fl_set_object_callback(obj,select_color,1);
  fdui->color_button[2] = obj = fl_add_button(FL_RADIO_BUTTON,170,120,60,40,"");
    fl_set_object_color(obj, palette->cm[2], palette->cm[2]);
    fl_set_object_callback(obj,select_color,2);
  fdui->color_button[3] = obj = fl_add_button(FL_RADIO_BUTTON,240,120,60,40,"");
    fl_set_object_color(obj, palette->cm[3], palette->cm[3]);
    fl_set_object_callback(obj,select_color,3);
  fdui->color_button[4] = obj = fl_add_button(FL_RADIO_BUTTON,30,170,60,40,"");
    fl_set_object_color(obj, palette->cm[4], palette->cm[4]);
    fl_set_object_callback(obj,select_color,4);
  fdui->color_button[5] = obj = fl_add_button(FL_RADIO_BUTTON,100,170,60,40,"");
    fl_set_object_color(obj, palette->cm[5], palette->cm[5]);
    fl_set_object_callback(obj,select_color,5);
  fdui->color_button[6] = obj = fl_add_button(FL_RADIO_BUTTON,170,170,60,40,"");
    fl_set_object_color(obj, palette->cm[6], palette->cm[6]);
    fl_set_object_callback(obj,select_color,6);
  fdui->color_button[7] = obj = fl_add_button(FL_RADIO_BUTTON,240,170,60,40,"");
    fl_set_object_color(obj, palette->cm[7], palette->cm[7]);
    fl_set_object_callback(obj,select_color,7);
  fdui->defcolor_load = obj = fl_add_button(FL_NORMAL_BUTTON,20,230,90,20,"Load...");
    fl_set_object_color(obj,XFCE_COLB,XFCE_COL3);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,defcolor_load_cb,0);
  fdui->defcolor_save = obj = fl_add_button(FL_NORMAL_BUTTON,130,230,80,20,"Save...");
    fl_set_object_color(obj,XFCE_COLB,XFCE_COL3);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,defcolor_save_cb,0);
  fdui->defcolor_default = obj = fl_add_button(FL_NORMAL_BUTTON,230,230,80,20,"Default");
    fl_set_object_color(obj,XFCE_COLB,XFCE_COL3);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,defcolor_default_cb,0);
  obj = fl_add_frame(FL_ENGRAVED_FRAME,10,270,310,50,"");
  fdui->defcolor_OK = obj = fl_add_button(FL_NORMAL_BUTTON,20,280,90,30,"Ok");
    fl_set_object_color(obj,XFCE_COLB,XFCE_COL3);
    fl_set_button_shortcut(obj,"^O^M#O",1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,defcolor_ok_cb,0);
  fdui->defcolor_apply = obj = fl_add_button(FL_NORMAL_BUTTON,130,280,80,30,"Apply");
    fl_set_object_color(obj,XFCE_COLB,XFCE_COL3);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,defcolor_apply_cb,0);
  fdui->defcolor_cancel = obj = fl_add_button(FL_NORMAL_BUTTON,230,280,80,30,"Cancel");
    fl_set_object_color(obj,XFCE_COLB,XFCE_COL3);
    fl_set_button_shortcut(obj,"^[^C#C",1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFBOLD+FL_ENGRAVED_STYLE);
    fl_set_object_callback(obj,defcolor_cancel_cb,0);
  fl_end_form();

  return fdui;
}


