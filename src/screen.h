/*

 ORIGINAL FILE NAME : screen.h

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



#ifndef FD_def_screen_h_
#define FD_def_screen_h_

extern void DM_screen_cb(FL_OBJECT *, long);
extern void OK_screen_cb(FL_OBJECT *, long);
extern void CANCEL_screen_cb(FL_OBJECT *, long);

typedef struct {
	FL_FORM *def_screen;
	FL_OBJECT *screen_input;
	FL_OBJECT *OKbutton;
	FL_OBJECT *Cancelbutton;
	void *vdata;
	long ldata;
} FD_def_screen;

extern FD_def_screen * create_form_def_screen(void);

#endif /* FD_def_screen_h_ */
