/*

 ORIGINAL FILE NAME : extern.h

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



#ifndef __EXTERNALS_H__
#define __EXTERNALS_H__

#include "XFCE.h"
#include "pulldown.h"
#include "addicon.h"
#include "info.h"
#include "screen.h"
#include "command.h"
#include "constant.h"
#include "color.h"
#include "defcolor.h"

  extern int			FVWM;
  extern int			fd[2];
  extern FD_XFCE *		fd_XFCE;
  extern FD_pullmenu *		menus[NBMENUS];
  extern ST_select 		selects[NBSELECTS];
  extern FD_addiconform *	fd_addiconform;
  extern FD_info *		fd_info;
  extern FD_def_command *	fd_def_command;
  extern FD_def_screen *	fd_def_screen;
  extern FD_def_color *		fd_def_color;

  extern XFCE_palette *		palette;
 
#endif
