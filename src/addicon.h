/*

 ORIGINAL FILE NAME : addicon.h

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



#ifndef FD_addiconform_h_
#define FD_addiconform_h_

extern void dummy_callback(FL_OBJECT *, long);
extern void br_comline_cb(FL_OBJECT *, long);
extern void br_iconpix_cb(FL_OBJECT *, long);
extern void update_pixfile(FL_OBJECT *, long);
extern void ai_ok_cb(FL_OBJECT *, long);
extern void ai_cancel_cb(FL_OBJECT *, long);
extern void ai_remove_cb(FL_OBJECT *, long);

typedef struct {
	FL_FORM *addiconform;
	FL_OBJECT *previewpix;
	FL_OBJECT *iconframe;
	FL_OBJECT *comline_input;
	FL_OBJECT *pixfile_input;
	FL_OBJECT *label_input;
	FL_OBJECT *br_comline;
	FL_OBJECT *br_iconpix;
	FL_OBJECT *OK;
	FL_OBJECT *ai_cancel;
	FL_OBJECT *ai_remove;
	void *vdata;
	long ldata;
} FD_addiconform;

extern FD_addiconform * create_form_addiconform(void);
extern void set_addicon_cb(FD_addiconform *, int, int);
extern void set_addiconform(FD_addiconform *, int, int);

#endif /* FD_addiconform_h_ */
