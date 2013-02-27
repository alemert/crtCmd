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
  // getFlagAttr empty list
  // -------------------------------------------------------
  doIntTest( "empty cmdln list",
             1 ,
             getFlagAttr,
             "task" ) ;

  // -------------------------------------------------------
  // getStrArrayAttr
  // -------------------------------------------------------
  doPointTest( "some attribute will be found " , \
               RC_IS_NULL                      , \
               getStrArrayAttr                 , \
               "output"                        ) ;

  initCmdLnCfg() ;

  // -------------------------------------------------------
  // getFlagAttr empty list
  // -------------------------------------------------------
  {
    const char *cmdln[] = { "program", "--task", NULL } ;
    getCmdLnAttr( 2, cmdln ) ;

    doIntTest( "empty attr found", 
               0 ,
               getFlagAttr,
               "task" ) ;
  }

  // -------------------------------------------------------
  // getStrArrayAttr
  // -------------------------------------------------------
#if(1)
  {
    const char *cmdln[] = { "program", "--output", "some/text", NULL } ;
    getCmdLnAttr( 3, cmdln ) ;
    doPointTest( "some attribute will be found " , \
                 RC_NOT_NULL                     , \
                 getStrArrayAttr                 , \
                 "output"                        ) ;
  }
#endif
_door:
  return sysRc ;
}
