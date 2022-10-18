/*

 ORIGINAL FILE NAME : constant.h

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



#ifndef __CONSTANT_H__
#define __CONSTANT_H__

#include "X11/forms.h"

/* Some font sizes and styles */

#define XFCE_TINY_SIZE		10
#define XFCE_NORMAL_SIZE 	12
#define XFCE_MEDIUM_SIZE	14
#define XFCE_HUGE_SIZE		18

#define USE_SET_FONT_NAME 	1

#ifdef USE_SET_FONT_NAME
  #define XFTINY	FL_MAXFONTS - 1
  #define XFREG 	FL_MAXFONTS - 2
  #define XFBOLD	FL_MAXFONTS - 3
  #define XFBIG 	FL_MAXFONTS - 4
  #define XFTIT 	FL_MAXFONTS - 5
#else
  #define XFTINY	FL_NORMAL_STYLE
  #define XFREG 	FL_NORMAL_STYLE
  #define XFBOLD	FL_BOLD_STYLE
  #define XFBIG 	FL_NORMAL_STYLE
  #define XFTIT 	FL_BOLD_STYLE
#endif

#define XFCE_TINY	"-adobe-helvetica-medium-r-*-*-10-*-75-75-*-*-*-*"
#define XFCE_REGULAR	"-adobe-helvetica-medium-r-*-*-12-*-75-75-*-*-*-*"
#define XFCE_BOLD	"-adobe-helvetica-bold-r-*-*-12-*-75-75-*-*-*-*"
#define XFCE_BIG	"-adobe-helvetica-medium-r-*-*-14-*-75-75-*-*-*-*"
#define XFCE_TITLE	"-adobe-helvetica-bold-r-*-*-14-*-75-75-*-*-*-*"

#ifndef BACKUPEXT
#define BACKUPEXT 	".bak"
#endif
#ifndef DEFAULT_SHELL
#define DEFAULT_SHELL 	"/bin/sh"
#endif
#ifndef PAL_PATTERN
#define PAL_PATTERN 	"*"
#endif
#ifndef XFCE_PAL
#define XFCE_PAL 	"/var/XFCE/palettes"
#endif
#ifndef XFCE_DIR
#define XFCE_DIR        "/var/XFCE"
#endif
#ifndef XBINDIR
#define XBINDIR 	"/usr/X11/bin"
#endif
#ifndef XPIXMAPDIR
#define XPIXMAPDIR 	"/usr/include/X11/pixmaps"
#endif
#ifndef NBMAXITEMS
#define NBMAXITEMS 	10
#endif
#ifndef ICONHEIGHT
#define ICONHEIGHT 	50
#endif
#ifndef ICONWIDTH
#define ICONWIDTH  	50
#endif
#ifndef MAXSTRLEN
#define MAXSTRLEN 	1024
#endif
#ifndef BUTTONCHANGE
#define BUTTONCHANGE 	3
#endif
#ifndef BORDERWIDTH
#define BORDERWIDTH 	2
#endif
#define NBSCREENS   	4    		/* Don't change this */
#define NBMENUS   	6    		/* Don't change this */
#define NBSELECTS 	7    		/* Don't change this */
#define NB_XFCE_COLORS 	8    		/* Don't change this */
#define XFCE_COL1	FL_FREE_COL1	/* Don't change this */
#define XFCE_COL2	FL_FREE_COL2	/* Don't change this */
#define XFCE_COL3	FL_FREE_COL3	/* Don't change this */
#define XFCE_COL4	FL_FREE_COL4	/* Don't change this */
#define XFCE_COL5	FL_FREE_COL5	/* Don't change this */
#define XFCE_COL6	FL_FREE_COL6	/* Don't change this */
#define XFCE_COL7	FL_FREE_COL7	/* Don't change this */
#define XFCE_COL8	FL_FREE_COL8	/* Don't change this */
#define XFCE_COLB	FL_FREE_COL9	/* Don't change this */

#endif /* __CONSTANT_H__ */
