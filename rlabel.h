USERID GCCCMS
/* label.h - header for label.c */

#ifndef _label_h_
#define _label_h_

#include "rline.h" 
#include "rpilot.h"

typedef struct
{
  char *name;
  line *stmnt;
  int linenum;
  struct label *next;
} label;

label *get_label( char *name );
label *new_label( char *name, line *lne, int linenum );
void prt_lb( label *l );
void prt_lb_l();

#endif
