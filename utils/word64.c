/*
 * word64.c
 *
 *  Created on: Dec 6, 2014
 *      Author: FredrikJ71
 *
 * Implements the functions defined in utils/word64.h
 */

#include "utils/word64.h"

void print_w(w64 w){
//print a 64-bit word in hexadecimal
  printf("%016" PRIxFAST64,w);
}

void println_w(w64 w){
//print a 64-bit word in hexadecimal, end with new line
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


