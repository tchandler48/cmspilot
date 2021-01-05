USERID GCCCMS

#ifndef _line_h_
#define _line_h_

#include "rcondex.h"
#include "rpilot.h"
#include <stdio.h>

typedef struct 
{
  char cmd;           /* name of the command (C,A,M, etc) */
  condex *cond;       /* Conditional expression, w/o the outer parens */
  char *args;         /* argument to the command */
  int linenum;        /* line number (from the source file) */
  struct line *next;  /* next line */
} line;

line *new_line( char *str, char lastcmd, int linenum );
void prt_ln_t( line *curr, FILE *stream );
void prt_ln( line *curr );
void prt_ln_l( line *head );
char *get_line( line *curr );

#endif
