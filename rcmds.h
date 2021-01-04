USERID GCCCMS
/* cmds.h - header for cmds.c */

#ifndef _cmds_h_
#define _cmds_h_

#include "rpilot.h"

void cmd_use( char *str );	/* use() implememnts PILOT's version of GOSUB */
void cmd_compute( char *str );	/* Handles variable assignment */
void cmd_accept( char *str );	/* Handles user input */
void cmd_type( char *str );		/* Displays data */
void cmd_end( char *str );		/* Marks the end of a subroutine */
void cmd_match( char *str );	/* Does string matching */
void cmd_jump( char *str );		/* PILOT's version of GOTO */
void cmd_yes( char *str );		/* Displays text if #matched equals YES */
void cmd_no( char *str );		/* Displays text if #matched equals NO */

/* The following are nonstandard functions available in rpilot programs */

void cmd_execute( char *str );	/* Executes a line of PILOT code */
void cmd_shell( char *str );	/* Allows access to the operating system */
void cmd_debug( char *str );	/* debugging from inside a PILOT programs */
void cmd_generate( char *str );	/* Puts random number in a given variable */

#endif

