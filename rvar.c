USERID GCCCMS
/*
  var.c - RPilot variable support
*/

#include <string.h>
#include "rpilot.h"
  
strvar *new_strvar( char *name, char *val )
{
  strvar *ret;
  
  if( (ret = (strvar *)malloc(sizeof(strvar))) == NULL ) {
    err( NO_MEM, "" );
  }
  
  ret->name = new_str( name );
  ret->val = new_str( val );
  ret->next = NULL;

  return ret;
}

numvar *new_numvar( char *name, int val )
{
  numvar *ret;

  if( (ret = (numvar *)malloc(sizeof(numvar))) == NULL ) {
    err( NO_MEM, "" );
  }  

  ret->name = new_strf( name, 0, strlen(name) );
  ret->val = val;
  ret->next = NULL;
  return ret;
}

void set_strvar( char *name, char *val )
{
  strvar *s = (strvar *)rpi->strhead;
  strvar *prev;

  while( s != NULL ) {
    if( !strcasecmp(s->name, name) ) {
      free( s->val );
      s->val = new_str( val );
      return;
    }
    prev = s;
    s = (strvar *)s->next;
  }

  // if we can't find the variable, make a new one
  (strvar *)prev->next = new_strvar( name, val );
}

void set_numvar( char *name, int val )
{
  numvar *n = (numvar *)rpi->numhead;
  numvar *prev;

  while( n != NULL ) {
    if( !strcasecmp(n->name, name) ) {
      n->val = val;
      return;
    }
    prev = n;
    n = (numvar *)n->next;
  }

  (numvar *)prev->next = new_numvar( name, val );
}

char *get_stvr( char *name )
{
  strvar *s = (strvar *)rpi->strhead;

  while( s != NULL ) {
    if( !strcasecmp(s->name, name) ) {
      return s->val;
    } else {
      s = (strvar *)s->next;
    }
  }
  
  if( rpi->strict == TRUE ) {
    err( BAD_VAR, name );
  } else {
    set_strvar( name, "" );
    return "";
  }

  return NULL;
}

int get_nr( char *name )
{
  numvar *n = (numvar *)rpi->numhead;

  while( n != NULL ) {
    if( !strcasecmp(n->name, name) ) {
      return n->val;
    } else {
      n = (numvar *)n->next;
    }
  }

  if( rpi->strict == TRUE ) {
    err( BAD_VAR, name );
  } else {
    set_numvar( name, 0 );
    return 0;
  }

}

void prt_strvar( strvar *var )
{
  printf( "%s = \"%s\"\n", var->name, var->val );
}

void prt_numvar( numvar *var )
{
  printf( "%s = %d\n", var->name, var->val );
}

void prt_st_l( void )
{
  strvar *var = (strvar *)rpi->strhead;
  
  while( var != NULL ) {
    prt_strvar( var );
    var = (strvar *)var->next;
  }
}

void prt_nu_l( void )
{
  numvar *var = (numvar *)rpi->numhead;

  while( var != NULL ) {
    prt_numvar( var );
    var = (numvar *)var->next;
  }
}
