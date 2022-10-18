/*

 ORIGINAL FILE NAME : XFCE.h

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



#ifndef FD_XFCE_h_
#define FD_XFCE_h_

#include "forms.h"
#include "constant.h"

/**** Callback routines ****/

extern void move_cb(FL_OBJECT *, long);
extern void popup_cb(FL_OBJECT *, long);
extern void select_cb(FL_OBJECT *, long);
extern void screen_cb(FL_OBJECT *, long);
extern void info_cb(FL_OBJECT *, long);
extern void save_cb(FL_OBJECT *, long);
extern void setup_cb(FL_OBJECT *, long);
extern void quit_cb(FL_OBJECT *, long);
extern void close_popup(FL_OBJECT *, long);

/**** Forms and Objects ****/

typedef struct {
	FL_FORM *XFCE;
	FL_OBJECT *select[NBSELECTS];
	FL_OBJECT *popup[NBMENUS];
	FL_OBJECT *screen[NBSCREENS];
	FL_OBJECT *clock;
	FL_OBJECT *noneL;
	FL_OBJECT *noneR;
	FL_OBJECT *centralframe;
	FL_OBJECT *INFO;
	FL_OBJECT *SAVE;
	FL_OBJECT *SETUP;
	FL_OBJECT *QUIT;
	void *vdata;
	long ldata;
} FD_XFCE;

extern void ToggleButtonUp(FD_XFCE *,   FL_OBJECT *);
extern void ToggleButtonDn(FD_XFCE *,   FL_OBJECT *);
extern FD_XFCE * create_form_XFCE(void);

#endif /* FD_XFCE_h_ */
