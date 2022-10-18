/*

 ORIGINAL FILE NAME : select.c

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



#include <stdio.h>
#include <signal.h>
#include "forms.h"
#include "constant.h"

FL_OBJECT * last_ob = NULL;

void ToggleSelectUp(FL_OBJECT *ob)
{
  fl_set_object_boxtype(ob,FL_FLAT_BOX);
  fl_set_object_color(ob,XFCE_COL8,XFCE_COL1);
  fl_redraw_object(ob);
}

void ToggleSelectDn(FL_OBJECT *ob)
{
  fl_set_object_boxtype(ob,FL_DOWN_BOX);
  fl_set_object_color(ob,XFCE_COL3,XFCE_COL1);
  fl_redraw_object(ob);
}

void wakeup(int SIG) 
{
    if (last_ob) ToggleSelectUp(last_ob);
    last_ob = NULL;
}

void press(FL_OBJECT * ob, unsigned l)
{
   if (l) {
     if (alarm(0)) wakeup(0);
     ToggleSelectDn(ob);
     last_ob = ob;
     signal(SIGALRM, wakeup);
     alarm(l);
   }
}
