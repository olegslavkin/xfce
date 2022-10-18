/*

 ORIGINAL FILE NAME : color.h

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



#ifndef __COLOR_H__
#define __COLOR_H__

#include "constant.h"

typedef struct {
	int cm[NB_XFCE_COLORS];
	int r[NB_XFCE_COLORS];
	int g[NB_XFCE_COLORS];
	int b[NB_XFCE_COLORS];
} XFCE_palette;

extern int  lo(int);
extern int  hi(int);
extern XFCE_palette * newpal(void);
extern void freepal(XFCE_palette *);
extern XFCE_palette * copypal(XFCE_palette * , const XFCE_palette * );
extern void initpal(XFCE_palette *);
extern void applypal(XFCE_palette *);
extern void defpal(XFCE_palette *);
extern int  savenamepal(XFCE_palette *, const char *);
extern int  loadnamepal(XFCE_palette *, const char *);
extern int  savepal(XFCE_palette *);
extern int  loadpal(XFCE_palette *);

#endif
