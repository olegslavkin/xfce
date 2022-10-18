/*

 ORIGINAL FILE NAME : fileutil.c

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
#include "constant.h"
#include "configfile.h"

int existfile(const char *s)
{
  FILE *f;
  if (f=fopen(s, "r"))
  {
  	fclose(f);
  	return(1);
  }
  return (0);
}

void exec_comm(char * comm)
{
    char * command;
    char * toexec;
    
    command = (char *) malloc((MAXSTRLEN+1) * sizeof(char));
    if ((comm)						/* Valid pointer ?   */
        && strlen(comm) 				/* Something to do ? */
        && strncasecmp(comm, "None", strlen("None"))) { /* Real command ?    */
      if(!fork()) {
          if (strncasecmp(comm, "exec", strlen("exec"))) {
              strcpy(command, "exec ");
              strcat(command, comm); }
          else {
              strcpy(command, comm); }
	  /* Clean up the command */
	  toexec = skiphead(command);
	  if(strlen(toexec)) skiptail(toexec);
	  /* Still got something to do ? */
	  if (strlen(toexec) && strncasecmp(toexec, "None", strlen("None")))
              execl(DEFAULT_SHELL, DEFAULT_SHELL, "-c", toexec, NULL);
          free(command); 
          exit(-1);
      }
    }
    free(command);
}
