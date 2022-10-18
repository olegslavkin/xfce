/*

 ORIGINAL FILE NAME : XFCE.c

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
#include "XFCE.h"
#include "extern.h"

/* Load pixmap files */
#include "file1.h"
#include "file2.h"
#include "mail.h"
#include "term.h"
#include "man.h"
#include "paint.h"
#include "print.h"
#include "minbutup.h"
#include "minbutdn.h"
#include "minipnt.h"
#include "mininf.h"

void ToggleButtonUp(FD_XFCE *fdui,   FL_OBJECT *obj)
{
  fl_set_pixmap_data(obj, minbutup);
  fl_set_button(obj, 0);
  fl_redraw_object(obj);
}

void ToggleButtonDn(FD_XFCE * fdui,   FL_OBJECT *obj)
{
  fl_set_pixmap_data(obj, minbutdn);
  fl_set_button(obj, 1);
  fl_redraw_object(obj);
}

FD_XFCE *create_form_XFCE(void)
{
  int i;
  FL_OBJECT *obj;
  FD_XFCE *fdui = (FD_XFCE *) fl_calloc(1, sizeof(*fdui));

  fdui->XFCE = fl_bgn_form(FL_FLAT_BOX, 784, 76);
  obj = fl_add_box(FL_FLAT_BOX,0,0,784,76,"");
  fl_set_object_color(obj, XFCE_COL8, XFCE_COL8);

  fdui->noneL = obj = fl_add_box(FL_UP_BOX,0,0,70,16,"");
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL2);
    fl_set_object_callback(obj, move_cb, 0);
  fdui->noneR = obj = fl_add_box(FL_UP_BOX,714,0,70,16,"");
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL2);
    fl_set_object_callback(obj, move_cb, 0);
  fdui->clock = obj = fl_add_clock(FL_ANALOG_CLOCK,15,26,40,40,"");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,XFCE_COL3,XFCE_COL3);
  obj = fl_add_box(FL_UP_BOX,0,16,784,60,"");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
  obj = fl_add_box(FL_FLAT_BOX,250,0,284,16,"");
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL2);


  fdui->select[0] = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,73,19,54,54,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_callback(obj, select_cb, 0);
  fdui->select[1] = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,133,19,54,54,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_callback(obj, select_cb, 1);
  fdui->select[2] = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,193,19,54,54,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_callback(obj, select_cb, 2);
  fdui->select[3] = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,537,19,54,54,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_callback(obj, select_cb, 3);
  fdui->select[4] = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,597,19,54,54,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_callback(obj, select_cb, 4);
  fdui->select[5] = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,657,19,54,54,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_callback(obj, select_cb, 5);
  fdui->select[6] = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,717,19,54,54,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_callback(obj, select_cb, 6);

  fdui->popup[0] = obj = fl_add_pixmapbutton(FL_PUSH_BUTTON,70,0,60,16,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL1);
    fl_set_object_callback(obj, popup_cb, 0);
  fdui->popup[1] = obj = fl_add_pixmapbutton(FL_PUSH_BUTTON,130,0,60,16,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL1);
    fl_set_object_callback(obj, popup_cb, 1);
  fdui->popup[2] = obj = fl_add_pixmapbutton(FL_PUSH_BUTTON,190,0,60,16,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL1);
    fl_set_object_callback(obj, popup_cb, 2);
  fdui->popup[3] = obj = fl_add_pixmapbutton(FL_PUSH_BUTTON,534,0,60,16,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL1);
    fl_set_object_callback(obj, popup_cb, 3);
  fdui->popup[4] = obj = fl_add_pixmapbutton(FL_PUSH_BUTTON,594,0,60,16,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL1);
    fl_set_object_callback(obj, popup_cb, 4);
  fdui->popup[5] = obj = fl_add_pixmapbutton(FL_PUSH_BUTTON,654,0,60,16,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL2,XFCE_COL1);
    fl_set_object_callback(obj, popup_cb, 5);

  fdui->centralframe = obj = fl_add_box(FL_UP_BOX,252,0,280,76,"");
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL8);
  obj = fl_add_box(FL_DOWN_BOX,295,10,94,24,"");
  fdui->screen[0] = obj = fl_add_button(FL_RADIO_BUTTON,297,12,90,20,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL3,XFCE_COL3);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFREG+FL_SHADOW_STYLE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_callback(obj, screen_cb, 0);
    fl_set_button(obj, 1);
  obj = fl_add_box(FL_DOWN_BOX,395,10,94,24,"");
  fdui->screen[1] = obj = fl_add_button(FL_RADIO_BUTTON,397,12,90,20,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL6,XFCE_COL6);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFREG+FL_SHADOW_STYLE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_callback(obj, screen_cb, 1);
  obj = fl_add_box(FL_DOWN_BOX,295,42,94,24,"");
  fdui->screen[2] = obj = fl_add_button(FL_RADIO_BUTTON,297,44,90,20,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL5,XFCE_COL5);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFREG+FL_SHADOW_STYLE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_callback(obj, screen_cb, 2);
  obj = fl_add_box(FL_DOWN_BOX,395,42,94,24,"");
  fdui->screen[3] = obj = fl_add_button(FL_RADIO_BUTTON,397,44,90,20,"");
    fl_set_object_boxtype(obj,FL_UP_BOX);
    fl_set_object_color(obj,XFCE_COL7,XFCE_COL7);
    fl_set_object_lcol(obj,FL_WHITE);
    fl_set_object_lsize(obj,XFCE_NORMAL_SIZE);
    fl_set_object_lstyle(obj,XFREG+FL_SHADOW_STYLE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_callback(obj, screen_cb, 3);
  fdui->INFO = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,257,8,35,28,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_callback(obj, info_cb, 0);
  fdui->SAVE = obj = fl_add_button(FL_NORMAL_BUTTON,257,44,35,20,"SAVE");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_callback(obj, save_cb, 0);
  fdui->SETUP = obj = fl_add_pixmapbutton(FL_NORMAL_BUTTON,492,8,35,28,"");
    fl_set_object_boxtype(obj,FL_FLAT_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL1);
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_callback(obj, setup_cb, 0);
  fdui->QUIT = obj = fl_add_button(FL_NORMAL_BUTTON,492,44,35,20,"QUIT");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,XFCE_COL8,XFCE_COL3);
    fl_set_object_lsize(obj,XFCE_TINY_SIZE);
    fl_set_object_lstyle(obj,XFTINY);
    fl_set_object_callback(obj, quit_cb, 0);

  fl_end_form();

  fl_set_pixmap_data(fdui->select[0], file1);
  fl_set_pixmap_data(fdui->select[1], term);
  fl_set_pixmap_data(fdui->select[2], mail);
  fl_set_pixmap_data(fdui->select[3], print);
  fl_set_pixmap_data(fdui->select[4], paint);
  fl_set_pixmap_data(fdui->select[5], file2);
  fl_set_pixmap_data(fdui->select[6], man);
  fl_set_pixmap_data(fdui->INFO, mininf);
  fl_set_pixmap_data(fdui->SETUP, minipnt);

  for(i = 0; i< NBMENUS; i++) {
    ToggleButtonUp(fdui, fdui->popup[i]);
    fl_set_pixmap_data(fdui->popup[i], minbutup);
  }
  
  return fdui;
}

/*---------------------------------------*/

