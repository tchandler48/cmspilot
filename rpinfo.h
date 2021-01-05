USERID GCCCMS
#ifndef _rpinfo_h_
#define _rpinfo_h_


/* contains info about the currently running interpreter */
typedef struct {
  struct line *currline;     /* line of code that currently being executed */
  struct line *linehead;     /* head of the line list */
  struct label *lblhead;     /* head of the label list */
  struct numvar *numhead;    
  struct strvar *strhead;
  struct stack *stk;
  int error;          /* the last error that occured */
  int status;         /* the status of the program (one of the STAT_ values) */
  char *lastacc;      /* the name of the last variable to be accepted */
  int strict;         /* should we be strict about undeclared variables? */
  char *filename;     /* name of file being run */
} rpinfo;

#endif
