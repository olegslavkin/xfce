/*

 ORIGINAL FILE NAME : color.c

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



#include "color.h"
#include "constant.h"

char * rccolor = "/.xfcolors";

int hi(int col)
{
  return ((((col * 130) /100) < 255) ? ((col * 130) /100) : 255);
}

int lo(int col)
{ 
  return(col * 65 / 100);
}

XFCE_palette * newpal(void)
{
    return ((XFCE_palette *) malloc (sizeof(XFCE_palette)));
}

void freepal(XFCE_palette * p)
{
    free(p);
}

XFCE_palette * copypal(XFCE_palette * d, const XFCE_palette * s)
{
   int i;
   
   if (d && s) { 
       for(i=0; i<NB_XFCE_COLORS; i++) {
         d->cm[i]=s->cm[i];d->r[i]=s->r[i]; d->g[i]=s->g[i]; d->b[i]=s->b[i]; }
       return d; }
   return NULL;
}
  
void initpal(XFCE_palette * p)
{
    p->cm[0] = XFCE_COL1;
    p->cm[1] = XFCE_COL2;
    p->cm[2] = XFCE_COL3;
    p->cm[3] = XFCE_COL4;
    p->cm[4] = XFCE_COL5;
    p->cm[5] = XFCE_COL6;
    p->cm[6] = XFCE_COL7;
    p->cm[7] = XFCE_COL8;
}

void applypal(XFCE_palette * p)
{
   fl_mapcolor(p->cm[0],   p->r[0], p->g[0], p->b[0]);
   fl_mapcolor(p->cm[1],   p->r[1], p->g[1], p->b[1]);
   fl_mapcolor(p->cm[2],   p->r[2], p->g[2], p->b[2]);
   fl_mapcolor(p->cm[3],   p->r[3], p->g[3], p->b[3]);
   fl_mapcolor(p->cm[4],   p->r[4], p->g[4], p->b[4]);
   fl_mapcolor(p->cm[5],   p->r[5], p->g[5], p->b[5]);
   fl_mapcolor(p->cm[6],   p->r[6], p->g[6], p->b[6]);
   fl_mapcolor(p->cm[7],   p->r[7], p->g[7], p->b[7]);
   fl_mapcolor(FL_MCOL,    p->r[2], p->g[2], p->b[2]);
   fl_mapcolor(FL_COL1,    p->r[7], p->g[7], p->b[7]);
   fl_mapcolor(XFCE_COLB,  p->r[7], p->g[7], p->b[7]);
   fl_mapcolor(FL_TOP_BCOL,   hi(p->r[7]),hi(p->g[7]),hi(p->b[7]));
   fl_mapcolor(FL_LEFT_BCOL,  hi(p->r[7]),hi(p->g[7]),hi(p->b[7]));   
   fl_mapcolor(FL_RIGHT_BCOL, lo(p->r[7]),lo(p->g[7]),lo(p->b[7]));
   fl_mapcolor(FL_BOTTOM_BCOL,lo(p->r[7]),lo(p->g[7]),lo(p->b[7]));
}

void defpal(XFCE_palette * p)
{
    initpal(p);
    p->r[0] = 255; p->g[0] = 100; p->b[0] =   0;
    p->r[1] = 152; p->g[1] = 160; p->b[1] = 168;
    p->r[2] = 128; p->g[2] = 145; p->b[2] = 164;
    p->r[3] = 104; p->g[3] = 111; p->b[3] = 135;
    p->r[4] = 188; p->g[4] = 168; p->b[4] = 158;
    p->r[5] =  73; p->g[5] = 146; p->b[5] = 167;
    p->r[6] = 193; p->g[6] = 135; p->b[6] = 141;
    p->r[7] = 174; p->g[7] = 178; p->b[7] = 195;
}

int savenamepal(XFCE_palette * p, const char * name)
{
    FILE * f;
    int i;
    
    if (f=fopen(name, "w")) {
        for(i=0; i<NB_XFCE_COLORS; i++)
            fprintf(f,"%i %i %i\n", p->r[i], p->g[i], p->b[i]);
        fclose(f);
    }
    return (f != NULL);   
}

int loadnamepal(XFCE_palette * p, const char * name)
{
    char * lineread, * a;
    FILE * f;
    int i, err = 0;
    XFCE_palette * backup_pal;
    
    backup_pal = newpal();
    if (!copypal(backup_pal, p)) defpal(backup_pal);
    
    lineread = (char *) malloc((80) * sizeof(char));
    
    if (f=fopen(name, "r")) {
        for(i=0; i<NB_XFCE_COLORS; i++) {
            fgets(lineread, 79, f);
            if (strlen(lineread)) {
              lineread[strlen(lineread) - 1] = 0;
              if (a=strtok(lineread, " ")) p->r[i]=atoi(a); else err = 1;
              if (a=strtok(NULL," "))      p->g[i]=atoi(a); else err = 1;
              if (a=strtok(NULL," "))      p->b[i]=atoi(a); else err = 1; }
        }
        fclose(f);
    }
    free(lineread);
   if (err) copypal(p, backup_pal);
    freepal(backup_pal);
    return (!err && (f != NULL));   
}

int savepal(XFCE_palette * p)
{
    char * homedir;
    int x;
    
    homedir = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    strcpy(homedir, (char *)getenv("HOME"));
    strcat(homedir, rccolor);
    x = savenamepal(p, homedir);
    free(homedir);
    return x;
}

int loadpal(XFCE_palette * p)
{
    char * homedir;
    int x;
    
    homedir = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    strcpy(homedir, (char *)getenv("HOME"));
    strcat(homedir, rccolor);
    x = loadnamepal(p, homedir);
    free(homedir);
    return x;
}

