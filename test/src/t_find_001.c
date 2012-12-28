/******************************************************************************/
/*  test cmdln find functions                                                 */
/*                                                                            */
/*  test: t_find_001                                                          */
/*                                                                            */
/*  tests:                                                                    */
/*    - testing                                       */
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
//#include "main.h"
#include "tutl.h"
#include "var/cmdl/src/cmdln.h"

/******************************************************************************/
/* prototypes                        */
/******************************************************************************/

/******************************************************************************/
/*  main                                                                      */
/******************************************************************************/
int main(int argc, const char** argv )
{
  int sysRc = NO_ERROR ;

  extern tCmdLnAttr *anchorAttr ;

  tCmdLnAttr *pAttr[10] ;
  tCmdLnAttr *rcAttr    ;

  anchorAttr = (tCmdLnAttr*) malloc(sizeof(tCmdLnAttr)) ;

  pAttr[0]     = (tCmdLnAttr*) malloc(sizeof(tCmdLnAttr)) ;
  anchorAttr->next = pAttr[0] ;
  pAttr[0]->shortAttr = 'i' ;
  pAttr[0]->type      = CMDL_TYPE_INT ;
  pAttr[0]->element   = 1 ;
  pAttr[0]->intValue  = (int*) malloc(sizeof(int)*pAttr[0]->element) ;
  pAttr[0]->chrValue  = NULL ;
  pAttr[0]->strValue  = NULL ;
  pAttr[0]->next = NULL ;
  
  pAttr[1]     = (tCmdLnAttr*) malloc(sizeof(tCmdLnAttr)) ;
  pAttr[1]->shortAttr = 'j' ;
  pAttr[1]->type      = CMDL_TYPE_INT ;
  pAttr[1]->element   = 1 ;
  pAttr[1]->intValue  = (int*) malloc(sizeof(int)*pAttr[1]->element) ;
  pAttr[1]->chrValue  = NULL ;
  pAttr[1]->strValue  = NULL ;
  pAttr[1]->next = NULL ;
  pAttr[0]->next = pAttr[1] ;

  pAttr[2]     = (tCmdLnAttr*) malloc(sizeof(tCmdLnAttr)) ;
  pAttr[2]->shortAttr = 'k' ;
  pAttr[2]->type      = CMDL_TYPE_INT ;
  pAttr[2]->element   = 1 ;
  pAttr[2]->intValue  = (int*) malloc(sizeof(int)*pAttr[2]->element) ;
  pAttr[2]->chrValue  = NULL ;
  pAttr[2]->strValue  = NULL ;
  pAttr[2]->next = NULL ;
  pAttr[1]->next = pAttr[2] ;

#if(1)
  pAttr[9]     = (tCmdLnAttr*) malloc(sizeof(tCmdLnAttr)) ;
  pAttr[9]->shortAttr = 'l' ;
  pAttr[9]->type      = CMDL_TYPE_INT ;
  pAttr[9]->element   = 1 ;
  pAttr[9]->intValue  = (int*) malloc(sizeof(int)*pAttr[9]->element) ;
  pAttr[9]->chrValue  = NULL ;
  pAttr[9]->strValue  = NULL ;
  pAttr[9]->next = NULL ;
#endif

  // -------------------------------------------------------
  // find first
  // -------------------------------------------------------
  startTestStep( "find short name - 1st " );

  rcAttr = findAttr( 'i' ) ;
  if( rcAttr != pAttr[0] )
  {
    errTestStep( "find short name - 1st " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find short name - 1st " );

  // -------------------------------------------------------
  // find middle
  // -------------------------------------------------------
  startTestStep( "find short name - 2nd " );

  rcAttr = findAttr( 'j' ) ;
  if( rcAttr != pAttr[1] )
  {
    errTestStep( "find short name - 2nd " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find short name - 2nd " );

  // -------------------------------------------------------
  // find last
  // -------------------------------------------------------
  startTestStep( "find short name - last " );

  rcAttr = findAttr( 'k' ) ;
  if( rcAttr != pAttr[2] )
  {
    errTestStep( "find short name - last " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find short name - last " );

  // -------------------------------------------------------
  // find last
  // -------------------------------------------------------
  startTestStep( "find short name - none " );

  rcAttr = findAttr( 'a' ) ;
  if( rcAttr != NULL )
  {
    errTestStep( "find short name - none " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find short name - none " );

  // -------------------------------------------------------
  // find in empty list
  // -------------------------------------------------------
  startTestStep( "find short name - empty list " );

  anchorAttr->next = NULL ;

  rcAttr = findAttr( 'i' ) ;
  if( rcAttr != NULL )
  {
    errTestStep( "find short name - empty list " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find short name - empty list " );

  anchorAttr->next = pAttr[0] ;

#if(0)
  // -------------------------------------------------------
  // find first
  // -------------------------------------------------------
  startTestStep( "find long name - 1st " );

  rcAttr = findLongNameAttr( "int" ) ;
  if( rcAttr != pAttr[0] )
  {
    errTestStep( "find long name - 1st " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find long name - 1st " );

  // -------------------------------------------------------
  // find middle
  // -------------------------------------------------------
  startTestStep( "find long name - 2nd " );

  rcAttr = findLongNameAttr( "jod" ) ;
  if( rcAttr != pAttr[1] )
  {
    errTestStep( "find long name - 2nd " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find long name - 2nd " );

  // -------------------------------------------------------
  // find last
  // -------------------------------------------------------
  startTestStep( "find long name - last " );

  rcAttr = findLongNameAttr( "ka" ) ;
  if( rcAttr != pAttr[2] )
  {
    errTestStep( "find long name - last " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find long name - last " );

  // -------------------------------------------------------
  // find last
  // -------------------------------------------------------
  startTestStep( "find long name - none " );

  rcAttr = findLongNameAttr( "notexist" ) ;
  if( rcAttr != NULL )
  {
    errTestStep( "find long name - none " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find long name - none " );

  // -------------------------------------------------------
  // find in empty list
  // -------------------------------------------------------
  startTestStep( "find long name - empty list " );

  anchorAttr->next = NULL ;

  rcAttr = findLongNameAttr( "int" ) ;
  if( rcAttr != NULL )
  {
    errTestStep( "find long name - empty list " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find long name - empty list " );

  anchorAttr->next = pAttr[0] ;

  // -------------------------------------------------------
  // find in empty list
  // -------------------------------------------------------
  startTestStep( "find long name - cfg NULL " );

  pAttr[2]->next = pAttr[9] ;

  rcAttr = findLongNameAttr( "notexist" ) ;
  if( rcAttr != NULL )
  {
    errTestStep( "find long name - cfg NULL " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find long name - cfg NULL " );
#endif

_door :
  return sysRc ;
}
