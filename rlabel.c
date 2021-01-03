USERID GCCCMS
/*
 * label.c - label handling code
 */

#include "rpilot.h"

#include <string.h>

label *new_label( char *name, line *lne, int linenum )
{
  label *l;

  l = (label *)malloc( sizeof(label) );
  l->linenum = linenum;
  l->stmnt = lne;
  l->name = new_str( name );
  l->next = NULL;

  return l;
}


label *get_label( char *name )
{
  label *l = (label *)rpi->lblhead;

  while( l != NULL ) {
    if( !strcasecmp(l->name, name) ) {
      return l; 
    }
    l = (label *)l->next;
  }
  
  err( BAD_LABEL, name );
}


void prt_lb( label *l )
{
    printf( "[line %d] %s: ", l->linenum, l->name );
    prt_ln( l->stmnt );
    printf( "\n" );
}

void prt_lb_l()
{
  label *l = (label *)rpi->lblhead;

  while( l != NULL ) {
    prt_lb( l );
    l = (label *)l->next;
  }

}



