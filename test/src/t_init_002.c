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
/*   M A I N                                                                  */
/******************************************************************************/
int main( int argc, const char** argv )
{
  int sysRc = NO_ERROR ;

  // -------------------------------------------------------
  // no args -> usage
  // -------------------------------------------------------
  doTest( "no arguments -> usage()" , \
          0                         , \
          handleCmdLn              ,  \
          1, argv                   ) ;

  // -------------------------------------------------------
  // usage()
  // -------------------------------------------------------
  {
  const char *cmdln[] = { "program", "--help", NULL } ;
  doTest( "--help -> usage()"    , \
          0                      , \
          handleCmdLn            , \
          2, cmdln ) ;
  }
_door:
  return sysRc ;
}
