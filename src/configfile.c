/*

 ORIGINAL FILE NAME : configfile.c

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
#include <X11/Xutil.h>
#include "XFCE.h"
#include "pulldown.h"
#include "addicon.h"
#include "constant.h"
#include "extern.h"

char * rcfile = "/.xfcerc";
int    nl = 0;
int buffersize = 256;

void syntax_error(char *s)
{
    char * errmsg;
    
    errmsg = (char *) malloc (256);
    sprintf(errmsg,"Line %u", nl); 
    fprintf(stderr,"XFCE :\nSyntax error in config file\n%s\n<%s>\n",
            errmsg, s);
    fl_show_alert("Syntax error in config file !",errmsg,s,1);
    free(errmsg);
    exit(2);
}

void data_error(char *s)
{
    char * errmsg;
    
    errmsg = (char *) malloc (256);
    sprintf(errmsg,"Line %u",nl); 
    fprintf(stderr,"XFCE :\nData mismatch error in config file\n%s\n<%s>\n",
            errmsg, s);
    fl_show_alert("Data mismatch error in config file !", errmsg,s,1);
    free(errmsg);
    exit(3);
}

char * skiphead(char * s)
{
    char * res = s;
    if (res) while(((*res == ' ')||(*res == '\t'))&&(*res != 0)) res++;
    return res;
}

char * skiptail(char * s)
{
    char * res;
    int i, j;
    if (s) {
        i = 0;
        j = strlen(s);
        res = (char *) (s + (strlen(s) - 1) * sizeof(char));
        while(((*res == ' ')||(*res == '\t')||(*res == '&'))&&(i++<j)) res--;
        *(++res) = 0; }
    return s;
}

char * nextline(FILE * f, char * lineread)
{
    char *p, *n;
    do {    
    	nl++;
    	fgets(lineread, MAXSTRLEN+1, f);
    	lineread[strlen(lineread)-1] = 0;
    	p = skiphead(lineread);
    }
    while (!strlen(p) && !feof(f));
    if (strlen(p)) skiptail(p);
    if (feof(f)) syntax_error("File truncated");
    return ((strlen(p)) ? p : NULL);
}

void writetoconfig(void)
{
    char * homedir;
    char * buffer;
    char * backname;
    FILE * configfile;
    FILE * copyfile;
    FILE * backfile;
    int i, j;
    int nb_read;

    Window par,wj;
    Window * wpj;
    unsigned int ij;
    FL_Coord x, y, w, h;

        
    homedir = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    strcpy(homedir, (char *)getenv("HOME"));
    strcat(homedir, rcfile);
    /* Backup any existing config file before creating a new one */
    if (existfile(homedir)) {
        backname = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
	buffer = (char *) malloc((buffersize + 1) * sizeof(char));
        strcpy(backname, homedir);
        strcat(backname, BACKUPEXT);
        backfile = fopen(backname, "w");
        copyfile = fopen(homedir, "r");
        if ((configfile) && (copyfile)) {
            while((nb_read = fread(buffer, 1, buffersize, copyfile)) > 0) {
                fwrite(buffer, 1, nb_read, backfile); }
	    fflush(backfile);
            fclose(backfile);
            fclose(copyfile);
        }
        free(backname);
        free(buffer);
    }
    configfile = fopen(homedir, "w");
    
    if (!configfile) { fl_show_alert("Unable to create config file !","","",1);
    }
    else {
        fprintf(configfile, "[Coords]\n");
        XQueryTree( fl_get_display(), fd_XFCE->XFCE->window, &wj, &par, &wpj, &ij);
        XQueryTree( fl_get_display(), par, &wj, &par, &wpj, &ij);
        fl_get_wingeometry(par, &x, &y, &w,&h);
        fprintf(configfile, "\t%i\n", x);
        fprintf(configfile, "\t%i\n", y);
        fprintf(configfile, "[ButtonLabels]\n");
        for(i=0; i<NBSCREENS; i++)
          fprintf(configfile, "\t%s\n", fd_XFCE->screen[i]->label);
        fprintf(configfile, "[Commands]\n");
	for(i=0; i<NBSELECTS; i++)
	    if (strlen(selects[i].command)) { 
	        fprintf(configfile, "\t%s\n", selects[i].command); }
	    else {
	        fprintf(configfile, "\tNone\n"); }
	for(i=0; i<NBMENUS; i++) {
	    fprintf(configfile, "[Menu%u]\n", i+1);
	    fprintf(configfile, "%u\n", menus[i]->nbitems);
	    for(j=0; j<menus[i]->nbitems; j++) {
	        fprintf(configfile, "\t%s\n", 
	        			menus[i]->menuitem[j]->label);
	        fprintf(configfile, "\t%s\n", 
	        			menus[i]->menuitem[j]->pixfile);
	        fprintf(configfile, "\t%s\n", 
	        			menus[i]->menuitem[j]->command);
	    }
    
	}
    fclose(configfile);
    }
    free(homedir);
}

void resetconfig(void)
{
    char * homedir;
    FILE * configfile;
    int i, j;
        
    homedir = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    strcpy(homedir, (char *)getenv("HOME"));
    strcat(homedir, rcfile);
    configfile = fopen(homedir, "w");
    if (!configfile) { fl_show_alert("Unable to reset config file !","","",1);
    }
    else {
	fprintf(stdout, "Creating new config file...");
    	fprintf(configfile, "[Coords]\n");
    	fprintf(configfile, "\t%u\n", (fl_scrw - fd_XFCE->XFCE->w) / 2);
    	fprintf(configfile, "\t%u\n",  fl_scrh - fd_XFCE->XFCE->h - 20);
    	fprintf(configfile, "[ButtonLabels]\n");
    	fprintf(configfile, "\t%s\n", "Screen 1");
    	fprintf(configfile, "\t%s\n", "Screen 2");
    	fprintf(configfile, "\t%s\n", "Screen 3");
    	fprintf(configfile, "\t%s\n", "Screen 4");
    	fprintf(configfile, "[Commands]\n");
	for(i=0; i<NBSELECTS; i++) fprintf(configfile, "\tNone\n");
    	for(i=0; i<NBMENUS; i++) {
	        fprintf(configfile, "[Menu%u]\n", i+1);
	        fprintf(configfile, "%u\n", 0);
	}
        fflush(configfile);
    	fclose(configfile);
    }
    free(homedir);
}

    
void readconfig(void)
{
    char * homedir;
    char * lineread;
    char * p;
    FILE * configfile;
    char * dummy;
    char * label;
    char * pixfile;
    char * command;
    
    
    int i,j, ni, px, py;
        
    nl = 0;
    homedir = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    lineread = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    label = (char *) malloc(256 * sizeof(char));
    pixfile = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    command = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    dummy = (char *) malloc(16 * sizeof(char));
    strcpy(homedir, (char *) getenv("HOME"));
    strcat(homedir, rcfile);
    configfile = fopen(homedir, "r");
    if(!configfile) {
        fl_show_alert("Unable to open config file !\nCreating new one.",
        		"","",1);
        resetconfig();
        configfile = fopen(homedir, "r");
    }
    if(!configfile) {
        fl_show_alert("Still unable to open config file !\nAborting.",
        		"","",1);
    }
    else {
        p = nextline(configfile, lineread);
        if (strncasecmp(p, "[Coords]", strlen("[Coords]"))) syntax_error(p);
        p = nextline(configfile, lineread);
        px = atoi(p);
        p = nextline(configfile, lineread);
        py = atoi(p);
	fl_set_form_position(fd_XFCE->XFCE, (px > 0) ? px:0, (py > 0) ? py:0);
        p = nextline(configfile, lineread);
        if (strncasecmp(p, "[ButtonLabels]", strlen("[ButtonLabels]"))) syntax_error(p);
	for(i=0; i<NBSCREENS; i++) {
          p = nextline(configfile, lineread);
          strcpy(fd_XFCE->screen[i]->label, p); }
        p = nextline(configfile, lineread);
        if (strncasecmp(p, "[Commands]", strlen("[Commands]"))) syntax_error(p);
	for(i=0; i<NBSELECTS; i++) {
            p = nextline(configfile, lineread);
	    selects[i].command = (char *) malloc ((MAXSTRLEN+1) * sizeof(char));
	    strcpy(selects[i].command, p); }
        for(i=0; i<NBMENUS; i++) {
            p = nextline(configfile, lineread);
  	    sprintf(dummy, "[Menu%u]", i+1);
            if (strncasecmp(p, dummy, strlen("dummy"))) syntax_error(p);
            p = nextline(configfile, lineread);
            ni = atoi(p);
            if (ni>NBMAXITEMS) data_error("Too many items in menu.");
	    for(j=0; j<ni; j++) {
                p = nextline(configfile, lineread);
                strcpy(label, p);
                p = nextline(configfile, lineread);
                strcpy(pixfile, p);
                p = nextline(configfile, lineread);
                strcpy(command, p);
                add_item_menu(menus[i], label, pixfile, command); }
	}
        fclose(configfile);
    }
    free(homedir);
    free(lineread);
    free(label);
    free(pixfile);
    free(command);
    free(dummy);
}
