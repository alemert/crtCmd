#!/bin/ksh

bin/clo.pl -i test/a00.cml -o test/srca00.c
gcc -Wall -c test/srca00.c -o test/srca00.o
