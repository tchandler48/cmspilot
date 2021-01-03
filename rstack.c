USERID GCCCMS
/* #include "stack.h" */
/* #include "line.h" */
#include "rpilot.h"

#include <stdlib.h>

stkitem *new_stkitem( line *lne )
{
  stkitem *si;

  si = (stkitem *)malloc( sizeof(stkitem) );
  si->item = lne;
  si->prev = NULL;

}


stack *new_stack( line *lne )
{
  stack *s;
  stkitem *si;

  s = (stack *)malloc( sizeof(stack) );
  si = new_stkitem( lne );

  s->head = si;
  s->tail = si;

  return s;
}


// returns the new tail of the list
stack *stk_push( stack *stk, line *lne )
{
  stkitem *si;

  si = new_stkitem( lne );
  (stkitem *)si->prev = stk->tail;  // worthless cast
  stk->tail = si;
  
  return stk;
}


line *stk_pop( stack *stk )
{
  stkitem *si;
  line *lne;

  si = stk->tail;

  stk->tail = (stkitem *)stk->tail->prev;  // worthless cast
  lne = si->item;
  free( si );

  return lne;
}
