USERID GCCCMS
/* pilot.c - main() function for RPilot   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


#include "rpilot.h"
#include "pmain.h"
#include "rline.h"
#include "rstack.h"
#include "rlabel.h"
#include "rcondex.h"
#include "rvar.h"
#include "rcmds.h"
#include "rdebug.h"
#include "rerr.h"
#include "rstring.h"
#include "rpinfo.h"
#include "rbind.h"
#include "rinter.h"
#include "rmath.h"
#include "rcalc.h"

typedef struct rpinfo 
{
  struct line *currline;  	/* code that is currently being executed */
  struct line *linehead;  	/* the head of the line list */
  struct label *lblhead;  	/* head of the label list */
  struct numvar *numhead;    
  struct strvar *strhead;
  struct stack *stk;
  int error;          	/* the last error that occured */
  int status;         /* the status of the program (one of the STAT_ values) */
  char *lastacc;      /* the name of the last variable to be accepted */
  int strict;         /* should we be strict about undeclared variables? */
  char *filename;     /* name of file being run */
};

struct rpinfo *rpi;

  int showban  = TRUE;
  int inter 	 = FALSE;
  int bind 	 = FALSE;
  int mainfunc = FALSE;
  int showhelp = FALSE;
  char *filename=NULL, *outfile=NULL, *dataname=NULL, *funcname=NULL;

#define NO_INTER 0

#include "strcasecmp.c"
#include "rline.c"
#include "rstack.c"
#include "rlabel.c"
#include "rcondex.c"
#include "rvar.c"
#include "rcmds.c"
#include "rdebug.c"
#include "rerr.c"
#include "rstring.c"
#include "rpinfo.c"
#include "rbind.c"
#include "rinter.c"
#include "rmath.c"
#include "rcalc.c"
#include "rpilot.c"


int main(int argc, char *argv[])
{
  int i;

  for( i=1; i < argc; i++ ) 
  {

   /* printf("argv[%d] = %s\n", i, argv[i] ); */

    if( !strcasecmp(argv[i], "-b") ) 
    {
      showban = FALSE;
    } else if( !strcasecmp(argv[i], "-i") ) {
      inter = TRUE;
    } else if( !strcasecmp(argv[i], "-?") ) {
      showhelp = TRUE;
    } else if( !strcasecmp(argv[i], "-c") ) {
      bind = TRUE;
    } else if( !strcasecmp(argv[i], "-o") ) {

      if( argc == i+1 ) 
      {
	err( NO_CLARGS, "-o" );
      } else {
	outfile = new_str( argv[i+1] );
	i++;
      }
    } else if( !strcasecmp(argv[i], "-d") ) {
      if( argc == i+1 ) {
	err( NO_CLARGS, "-d" );
      } else {
	dataname = new_str( argv[i+1] );
	i++;
      }
    } else if( !strcasecmp(argv[i], "-f") ) {
      if( argc == i+1 ) {
	err( NO_CLARGS, "-f" );
      } else {
	funcname = new_str( argv[i+1] );
	i++;
      }
    } else if( !strcasecmp(argv[i], "-m") ) {
      mainfunc = TRUE;
    } else {
      filename = new_str( argv[i] );
    }
  }

/*
printf("filename=\"%s\", outfile=\"%s\", dataname=\"%s\", funcname=\"%s\"\n", 
                     filename, outfile, dataname, funcname ); 
printf("showban=%d, inter=%d, mainfunc=%d\n", showban, inter, mainfunc ); 
*/

  if( argc == 1 )   			/* no arguments */
  {
    banner();
  } else {  				/* there were arguments */
    if( showhelp == TRUE ) {
      if( showban == TRUE ) { banner(); }
      help(); 
    } else if( inter == TRUE ) {
      if( showban == TRUE ) { banner(); }
      interact();
    } else if( filename == NULL ) {
      if( showban == TRUE ) { banner(); }
      err( NO_FILE, "" );
    } else if( bind == TRUE ) {
      bindfile( filename, outfile, dataname, funcname, mainfunc );
    } else {
      run( filename );
    }
  }

  return 0;
}


void help() 
{
  printf( "Usage: rpilot [switch] filename\n" );
  printf( "Switch \t Action\n" );
  printf( "-b \t Suppress banner printing on startup\n" );
  printf( "-i \t Enter interactive mode when no file names are given\n");
  /*  printf( "-c \t Bind a file as a C program\n" ); */
  printf( "-? \t Print this help message, then exit\n\n" );

}

void banner()
{
  printf( "RPilot: Rob's PILOT Interpreter, version %s\n", VERSION );
  printf( "Copyright 1998,2002 Rob Linwood (rcl211@nyu.edu)\n" );
  printf( "RPilot is Free Software. Please see http://rpilot.sf.net/\n" );
  printf( "For help, try `rpilot -?'\n\n" );
}
  

