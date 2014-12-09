# A makefile for creating the test programs for the utility functions
#
#
test_word64: test_word64.o ../utils/word64.o
	gcc -std=c11 -I ../include -o test_word64 test_word64.o ../utils/word64.o
test_word64.o: test_word64.c
	gcc -std=c11 -I ../include -c -o test_word64.o test_word64.c
../utils/word64.o: ../utils/word64.c
	gcc -std=c11 -I ../include -c -o ../utils/word64.o ../utils/word64.c


