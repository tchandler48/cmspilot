USERID GCCCMS
/*
  var.h - variable datatypes and prototypes for var.c
*/

#ifndef _var_h_
#define _var_h_

#include "rpilot.h"

/*  string variables */
typedef struct {
  char *name;
  char *val;
  struct strvar *next;
} strvar;

// numeric variables
typedef struct {
  char *name;
  int val;
  struct numvar *next;
} numvar;


// make new variables
strvar *new_strvar( char *name, char *val );
numvar *new_numvar( char *name, int val );

// Sets the value of a given variable 
void set_strvar( char *name, char *val );
void set_numvar( char *name, int val );

// Returns the value of a given variable 
int get_nr( char *name );
char *get_strvr( char *name );

void prt_strvar( strvar *var  );
void prt_numvar( numvar *var );
void prt_st_l( void );
void prt_nu_l( void );

#endif
