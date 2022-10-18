/*

 ORIGINAL FILE NAME : command.h

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



#ifndef FD_def_command_h_
#define FD_def_command_h_

extern void DM_com_cb(FL_OBJECT *, long);
extern void br_com_cb(FL_OBJECT *, long);
extern void OK_defcom_cb(FL_OBJECT *, long);
extern void CANCEL_defcom_cb(FL_OBJECT *, long);

typedef struct {
	FL_FORM   *defcom;
	FL_OBJECT *def_command;
	FL_OBJECT *command_input;
	FL_OBJECT *br_command;
	FL_OBJECT *defcom_ok_but;
	FL_OBJECT *defcom_cancel_but;
	void *vdata;
	long ldata;
} FD_def_command;

extern FD_def_command * create_form_def_command(void);

#endif /* FD_def_command_h_ */
