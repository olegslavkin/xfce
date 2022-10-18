/*

 ORIGINAL FILE NAME : defcolor_cb.c

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
#include "defcolor.h"
#include "color.h"
#include "extern.h"

void create_rgb(FL_OBJECT *obj, long c)
{
    int r, g, b;

    fl_freeze_form(fd_def_color->defcolor);
    r = fl_get_slider_value(fd_def_color->rs);
    g = fl_get_slider_value(fd_def_color->gs);
    b = fl_get_slider_value(fd_def_color->bs);
    fl_mapcolor(palette->cm[current_col], r, g, b);
    palette->r[current_col] = r;
    palette->g[current_col] = g;
    palette->b[current_col] = b;
    fl_redraw_object(fd_def_color->color_button[current_col]);
    fl_unfreeze_form(fd_def_color->defcolor);
}

void select_color(FL_OBJECT *ob, long c)
{
    fl_freeze_form(fd_def_color->defcolor);
    fl_set_slider_value(fd_def_color->rs, palette->r[c]);
    fl_set_slider_value(fd_def_color->gs, palette->g[c]);
    fl_set_slider_value(fd_def_color->bs, palette->b[c]);
    fl_unfreeze_form(fd_def_color->defcolor);
    current_col = c;
}

void defcolor_load_cb(FL_OBJECT *ob, long data)
{
    const char *fselect;
    
    fl_freeze_form(fd_def_color->defcolor);
    fselect=fl_show_fselector("Palette to load :", XFCE_PAL, PAL_PATTERN,"");
    if (fselect) 
  	if(strlen(fselect)) {
   	    if(existfile(fselect)) {
                if (!loadnamepal(palette, fselect))
                    fl_show_alert("Error",fselect,"Couldn't load file !",1); }
   	    else { fl_show_alert("Error", fselect, "File not found !", 1); }
	    applypal(palette);
            select_color(fd_def_color->color_button[current_col], current_col);
   	    fl_redraw_form(fd_def_color->defcolor);
    	    fl_redraw_form(fd_XFCE->XFCE); }
    fl_unfreeze_form(fd_def_color->defcolor);
}

void defcolor_save_cb(FL_OBJECT *ob, long data)
{
    const char *fselect;
    int rep = 1;
    
    fl_freeze_form(fd_def_color->defcolor);
    fselect=fl_show_fselector("Palette to save :", XFCE_PAL, PAL_PATTERN,"");
    if (fselect) 
  	if(strlen(fselect)) {
   	    if(existfile(fselect))
#if FL_REVISION>=84
              rep=(fl_show_question("File exists : Overwrite ?",1)==1);
#else
              rep=(fl_show_question("File exists : Overwrite ?", " ", " ")==1);
#endif      
        if (rep) if (!savenamepal(palette, fselect))
            fl_show_alert("Error", fselect, "Could not write file !", 1);
        }
    fl_unfreeze_form(fd_def_color->defcolor);
}

void defcolor_default_cb(FL_OBJECT *ob, long data)
{
    fl_freeze_form(fd_def_color->defcolor);
    defpal(palette);
    applypal(palette);
    select_color(fd_def_color->color_button[current_col], current_col);
    fl_redraw_form(fd_def_color->defcolor);
    fl_redraw_form(fd_XFCE->XFCE);
    fl_unfreeze_form(fd_def_color->defcolor);
}

void defcolor_ok_cb(FL_OBJECT *ob, long data)
{
    applypal(palette);
    if (!savepal(palette)) fl_show_alert("Error","Couldn't save colors !","",1);
    fl_hide_form(fd_def_color->defcolor);
    fl_redraw_form(fd_XFCE->XFCE);
    fl_activate_all_forms();
}

void defcolor_apply_cb(FL_OBJECT *ob, long data)
{
    fl_freeze_form(fd_def_color->defcolor);
    applypal(palette);
    fl_redraw_form(fd_XFCE->XFCE);
    fl_redraw_form(fd_def_color->defcolor);
    fl_unfreeze_form(fd_def_color->defcolor);
}

void defcolor_cancel_cb(FL_OBJECT *ob, long data)
{
    if (!loadpal(palette)) fl_show_alert("Error","Couldn't load colors !","",1);
    applypal(palette);
    fl_hide_form(fd_def_color->defcolor);
    fl_redraw_form(fd_XFCE->XFCE);
    fl_activate_all_forms();
}



