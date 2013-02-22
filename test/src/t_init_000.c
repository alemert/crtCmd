/******************************************************************************/
/*  test cmdln find functions                                                 */
/*                                                                            */
/*  test: t_init_001                                                          */
/*                                                                            */
/*  tests:                                                                    */
/*    - testing                                                               */
/******************************************************************************/

/******************************************************************************/
/*  includes                                                                  */
/******************************************************************************/

// ---------------------------------------------------------
// std
// ---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// ---------------------------------------------------------
// own
// ---------------------------------------------------------
#include "tutl.h"
#include "var/cmdl/src/cmdln.h"

/******************************************************************************/
/* prototypes                                                                 */
/******************************************************************************/

/******************************************************************************/
/*  main                                                                      */
/******************************************************************************/
int main(int argc, const char** argv )
{
  int sysRc = NO_ERROR ;


  doTest( "general err test" , \
          1                  , \
          initCmdLnCfg ) ;


_door :
  return sysRc ;
}
