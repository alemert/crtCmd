/******************************************************************************/
/* test t_get_001.c                                                           */
/*                                                                            */
/* testing file :  cmdln.c                                                    */
/*                                                                            */
/* testing functions : getAttrSize                                            */
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
  // getAttrSize
  // -------------------------------------------------------
  #if( 0 )
  startTestStep("getAttr size - no attributes nodes");
  sysRc = getAttrSize( "output" ) ;
  if( sysRc != -1 )
  {
    errTestStep( "getAttr size - no attributes nodes" ) ;
    goto _door ;
  }
  okTestStep( "getAttr size - no attributes nodes" ) ;
  #endif

  doTest( "getAttr size - no attributes nodes",
          -1, getAttrSize, "output" ) ;

_door:
  return sysRc ;
}
