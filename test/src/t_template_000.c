/******************************************************************************/
/* test c source template                                                     */
/*                                                                            */
/* testing file :                                                             */
/*                                                                            */
/* testing functions :                                                        */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*   I N C L U D E S                                                          */
/******************************************************************************/

// ---------------------------------------------------------
// std
// ---------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <errno.h>

// ---------------------------------------------------------
// own 
// ---------------------------------------------------------
#include "tutl.h"
#include "var/cmdl/src/cmdln.h"

/******************************************************************************/
/*   M A I N                                                 */
/******************************************************************************/
int main( int argc, const char** argv )
{
  int sysRc = NO_ERROR ;

  // -------------------------------------------------------
  // some test 
  // -------------------------------------------------------
  startTestStep(" some text ") ;
  sysRc = someFunc( a, b, c ) ;
  if( sysRc != 0 )
  {
    errTestStep( "some text" ) ;
    goto _door ;
  }
  okTestStep( "some text" ) ;

_door:
  return sysRc ;
}
