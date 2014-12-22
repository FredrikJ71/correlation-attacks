/*
 * lfsr64.c
 *
 *  Created on: Nov 13, 2014
 *      Author: fredrik
 */
#include "utils/lfsr64.h"
#include <stdio.h>

//test lfsr64

void testLFSR64(){
  //create a 4 bit lfsr
  //feedback 1+x 3+x 4
	int l=4;
	w64 output;
	lfsr64_ctx* lfsr=init_lfsr64(l);
	lfsr->s=1;
	lfsr->gx=3;
	output=step_64(lfsr);
	println_w(output);
}

int main(){
  printf("Testing lfsr\n");
  testLFSR64();
}
