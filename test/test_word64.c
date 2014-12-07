/*
 * word64.c
 *
 *  Created on: Nov 5, 2014
 *      Author: fredrik
 */

#include "word64.h"

void print_w(w64 w){
  printf("%016" PRIxFAST64,w);
}

void println_w(w64 w){
  printf("%016" PRIxFAST64 ,w);
  printf("\n");
}

int weight_w(w64 w){
	//returns the weight (number of bits=1) of w
	 w -= (w >> 1) & 0x5555555555555555uLL; //put count of each 2 bits into those 2 bits
	 w = (w & 0x3333333333333333uLL) + ((w >> 2) & 0x3333333333333333uLL); //put count of each 4 bits into those 4 bits
	 w = (w + (w >> 4)) & 0x0f0f0f0f0f0f0f0fuLL; //put count of each 8 bits into those 8 bits
	 w += w >>  8;  //put count of each 16 bits into their lowest 8 bits
	 w += w >> 16;  //put count of each 32 bits into their lowest 8 bits
	 w += w >> 32;  //put count of each 64 bits into their lowest 8 bits
	 return w & 0x7f;
}

void testWord64() {
	w64 test = 0x1234fde;
	print_w(test);
	printf("\n");
	printf("%d\n",weight_w(test));
	for (int i = 56; i < 64; i++) {
		set_w(&test, i);
		print_w(test);
		printf("\n");
	}
	printf("%d\n",weight_w(test));
	for (int i = 56; i < 64; i++) {
		clear_w(&test, i);
		println_w(test);
	}
}
