int handleCmdLn(int argc, const char* argv[]) ;

int main(int argc, const char* argv[] )
{
  int sysRc ;

  sysRc = handleCmdLn(argc,argv) ;

  return sysRc ;
}
