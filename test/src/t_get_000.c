/******************************************************************************/
/*  test cmdln find functions                                                 */
/*                                                                            */
/*  test: t_init_002                                                          */
/*                                                                            */
/*  tests:                                                                    */
/*    - getCmdLnAttr                                                          */
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
/* prototypes                                                      */
/******************************************************************************/

/******************************************************************************/
/*  main                                                                      */
/******************************************************************************/
int main(int argc, const char** argv )
{
  int sysRc = NO_ERROR ;

  char **attr ;
  int i;

  attr = (char**) malloc( sizeof(char*) * 16 ) ;
  for(i=0;i<16;i++)
  {
    attr[i] = (char*) malloc( sizeof(char) * 32 );
    memset(attr[i],'\0',32);
  }
  memcpy(attr[0],"programname",sizeof("programname"));

  // -------------------------------------------------------
  // empty cmdln 
  // -------------------------------------------------------
  startTestStep( "get attr - no attr " );

  sysRc = getCmdLnAttr(0,NULL) ;
  if( sysRc != 0 )
  {
    errTestStep( "get attr - no attr" );
    goto _door ;
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "get cmdln attr - no attr" );

  // -------------------------------------------------------
  // only -
  // -------------------------------------------------------
  startTestStep( "get attr - minus " );
  attr[1][0] = '-' ;

  sysRc = getCmdLnAttr(2,(const char**)attr) ;
  if( sysRc == 0 )
  {
    errTestStep( "get attr - minus " );
    goto _door ;
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "get cmdln attr - no attr" );

  // -------------------------------------------------------
  // only --
  // -------------------------------------------------------
  startTestStep( "get attr - minus minus " );
  attr[1][1] = '-' ;

  sysRc = getCmdLnAttr(2,(const char**)attr) ;
  if( sysRc == 0 )
  {
    errTestStep( "get attr - minus minus" );
    goto _door ;
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "get cmdln attr - minus minus" );

  // -------------------------------------------------------
  // only one empty attr short
  // -------------------------------------------------------
  startTestStep( "get attr - one empty short" );
  attr[1][1] = 'a' ;  // "-a"

  sysRc = getCmdLnAttr(2,(const char**)attr) ;
  if( sysRc == 0 )
  {
    errTestStep( "get attr - one empty short" );
    goto _door ;
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "get attr - one empty short" );

  // -------------------------------------------------------
  // only one empty attr long
  // -------------------------------------------------------
  startTestStep( "get attr - one empty long" );
  attr[1][1] = '-' ;  // "--"
  attr[1][2] = 'b' ;  // "--b"
  attr[1][3] = 'c' ;  // "--bc"

  sysRc = getCmdLnAttr(2,(const char**)attr) ;
  if( sysRc == 0 )
  {
    errTestStep( "get attr - one empty long" );
    goto _door ;
  }
  else
  {
    sysRc = 0 ;
  }

  okTestStep( "get attr - one empty long" );


_door :
  return sysRc ;
}

