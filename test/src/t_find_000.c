/******************************************************************************/
/*  test cmdln find functions                                                 */
/*                                                                            */
/*  test: t_find_000                                                          */
/*                                                                            */
/*  tests:                                                                    */
/*    - testing                     */
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
/* prototypes                  */
/******************************************************************************/

/******************************************************************************/
/*  main                                                                      */
/******************************************************************************/
int main(int argc, const char** argv )
{
  int sysRc = NO_ERROR ;

  extern tCmdLnCfg *anchorCfg ;

  tCmdLnCfg *pCfg[10] ;
  tCmdLnCfg *rcCfg    ;

  anchorCfg = (tCmdLnCfg*) malloc(sizeof(tCmdLnCfg)) ;

  pCfg[0]     = (tCmdLnCfg*) malloc(sizeof(tCmdLnCfg)) ;
  anchorCfg->next = pCfg[0] ;
  pCfg[0]->longAttr = (char*) malloc( sizeof(char)*4);
  memcpy(pCfg[0]->longAttr,"int\0",4);
  pCfg[0]->shortAttr = 'i' ;
  pCfg[0]->appliance = CMDL_APPL_OBL ;
  pCfg[0]->type      = CMDL_TYPE_INT ;
  pCfg[0]->element   = 1 ;
  pCfg[0]->intValue  = (int*) malloc(sizeof(int)*pCfg[0]->element) ;
  pCfg[0]->chrValue  = NULL ;
  pCfg[0]->strValue  = NULL ;
  pCfg[0]->help      = (char*) malloc(sizeof(char)*10);
  memcpy(pCfg[0]->help,"single int",10);
  pCfg[0]->next = NULL ;
  
  pCfg[1]     = (tCmdLnCfg*) malloc(sizeof(tCmdLnCfg)) ;
  pCfg[1]->longAttr = (char*) malloc( sizeof(char)*4);
  memcpy(pCfg[1]->longAttr,"jod\0",4);
  pCfg[1]->shortAttr = 'j' ;
  pCfg[1]->appliance = CMDL_APPL_OBL ;
  pCfg[1]->type      = CMDL_TYPE_INT ;
  pCfg[1]->element   = 1 ;
  pCfg[1]->intValue  = (int*) malloc(sizeof(int)*pCfg[1]->element) ;
  pCfg[1]->chrValue  = NULL ;
  pCfg[1]->strValue  = NULL ;
  pCfg[1]->help      = (char*) malloc(sizeof(char)*10);
  memcpy(pCfg[1]->help,"single int",10);
  pCfg[1]->next = NULL ;
  pCfg[0]->next = pCfg[1] ;

  pCfg[2]     = (tCmdLnCfg*) malloc(sizeof(tCmdLnCfg)) ;
  pCfg[2]->longAttr = (char*) malloc( sizeof(char)*3);
  memcpy(pCfg[2]->longAttr,"ka\0",3);
  pCfg[2]->shortAttr = 'k' ;
  pCfg[2]->appliance = CMDL_APPL_OBL ;
  pCfg[2]->type      = CMDL_TYPE_INT ;
  pCfg[2]->element   = 1 ;
  pCfg[2]->intValue  = (int*) malloc(sizeof(int)*pCfg[2]->element) ;
  pCfg[2]->chrValue  = NULL ;
  pCfg[2]->strValue  = NULL ;
  pCfg[2]->help      = (char*) malloc(sizeof(char)*10);
  memcpy(pCfg[2]->help,"single int",10);
  pCfg[2]->next = NULL ;
  pCfg[1]->next = pCfg[2] ;

#if(1)
  pCfg[9]     = (tCmdLnCfg*) malloc(sizeof(tCmdLnCfg)) ;
  pCfg[9]->longAttr  = (char*) NULL ;
  pCfg[9]->shortAttr = 'l' ;
  pCfg[9]->appliance = CMDL_APPL_OBL ;
  pCfg[9]->type      = CMDL_TYPE_INT ;
  pCfg[9]->element   = 1 ;
  pCfg[9]->intValue  = (int*) malloc(sizeof(int)*pCfg[9]->element) ;
  pCfg[9]->chrValue  = NULL ;
  pCfg[9]->strValue  = NULL ;
  pCfg[9]->help      = (char*) malloc(sizeof(char)*10);
  memcpy(pCfg[9]->help,"single int",10);
  pCfg[9]->next = NULL ;
#endif

  // -------------------------------------------------------
  // find first
  // -------------------------------------------------------
  startTestStep( "find short name - 1st " );

  rcCfg = findShortNameCfg( 'i' ) ;
  if( rcCfg != pCfg[0] )
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

  rcCfg = findShortNameCfg( 'j' ) ;
  if( rcCfg != pCfg[1] )
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

  rcCfg = findShortNameCfg( 'k' ) ;
  if( rcCfg != pCfg[2] )
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

  rcCfg = findShortNameCfg( 'a' ) ;
  if( rcCfg != NULL )
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

  anchorCfg->next = NULL ;

  rcCfg = findShortNameCfg( 'i' ) ;
  if( rcCfg != NULL )
  {
    errTestStep( "find short name - empty list " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find short name - empty list " );

  anchorCfg->next = pCfg[0] ;

  // -------------------------------------------------------
  // find first
  // -------------------------------------------------------
  startTestStep( "find long name - 1st " );

  rcCfg = findLongNameCfg( "int" ) ;
  if( rcCfg != pCfg[0] )
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

  rcCfg = findLongNameCfg( "jod" ) ;
  if( rcCfg != pCfg[1] )
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

  rcCfg = findLongNameCfg( "ka" ) ;
  if( rcCfg != pCfg[2] )
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

  rcCfg = findLongNameCfg( "notexist" ) ;
  if( rcCfg != NULL )
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

  anchorCfg->next = NULL ;

  rcCfg = findLongNameCfg( "int" ) ;
  if( rcCfg != NULL )
  {
    errTestStep( "find long name - empty list " );
    goto _door ; 
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "find long name - empty list " );

  anchorCfg->next = pCfg[0] ;

#if(1)
  // -------------------------------------------------------
  // find in empty list
  // -------------------------------------------------------
  startTestStep( "find long name - cfg NULL " );

  pCfg[2]->next = pCfg[9] ;

  rcCfg = findLongNameCfg( "notexist" ) ;
  if( rcCfg != NULL )
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
