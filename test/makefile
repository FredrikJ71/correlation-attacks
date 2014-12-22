# A makefile for creating the test programs for the utility functions
#
#

test_lfsr64: test_lfsr64.o ../utils/lfsr64.o ../utils/word64.o
	gcc -std=c11 -I ../include -o test_lfsr64 test_lfsr64.o ../utils/word64.o ../utils/lfsr64.o

test_lfsr64.o: test_lfsr64.c ../utils/lfsr64.c
	gcc -std=c11 -I ../include -c -o test_lfsr64.o test_lfsr64.c

test_vec64: test_vec64.o ../utils/vec64.o ../utils/word64.o
	gcc -std=c11 -I ../include -o test_vec64 test_vec64.o ../utils/word64.o ../utils/vec64.o

test_vec64.o: test_vec64.c
	gcc -std=c11 -I ../include -c -o test_vec64.o test_vec64.c

../utils/vec64.o: ../utils/vec64.c
	gcc -std=c11 -I ../include -c -o ../utils/vec64.o ../utils/vec64.c

test_word64: test_word64.o ../utils/word64.o
	gcc -std=c11 -I ../include -o test_word64 test_word64.o ../utils/word64.o

test_word64.o: test_word64.c
	gcc -std=c11 -I ../include -c -o test_word64.o test_word64.c

../utils/word64.o: ../utils/word64.c
	gcc -std=c11 -I ../include -c -o ../utils/word64.o ../utils/word64.c


