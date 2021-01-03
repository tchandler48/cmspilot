USERID GCCCMS
#ifndef _stack_h_
#define _stack_h_

#include "rline.h" 
#include "rpilot.h"


typedef struct {
  line *item;
  struct stkitem *prev;
} stkitem;

typedef struct {
  stkitem *head, *tail;
} stack;

stkitem *new_stkitem( line *lne );
stack *new_stack( line *lne );
stack *stk_push( stack *stk, line *lne );
line *stk_pop( stack *stk );



#endif
