USERID GCCCMS
/* math.c - mathematical functions for RPilot
 * 
 * major update - aug.11.2000
 *  - remove all garbage, express() remains only as a wrapper to calc()
 */

#include <string.h>

#include "rpilot.h"
#include "rcalc.h"

int express( char *form )
{
  int result, status;

  result = calc( form, &status );

  if( status != 0 )	
  { 
    err( EXP_MATH, "" );
  }

  return result;

}

