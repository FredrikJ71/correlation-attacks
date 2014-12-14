/*
 * lfsr64.c
 *
 *  Created on: Nov 13, 2014
 *      Author: fredrik
 */
#include "lfsr64.h"

lfsr64_ctx* init_lfsr64(int length){
	lfsr64_ctx *lfsr=(lfsr64_ctx *)malloc(sizeof(lfsr64_ctx));
	lfsr->l=length;
	lfsr->mask=1uLL<<(length-1);
	lfsr->s=0;
	lfsr->gx=0;
	return lfsr;
}

int step_1(lfsr64_ctx* lfsr){
	int temp=(lfsr->s&1);
	w64 newB=(lfsr->s)&(lfsr->gx);
	lfsr->s>>=1;
	if(weight_w(newB)&1)
		lfsr->s|=lfsr->mask;
	return temp;
}

w64 step_64(lfsr64_ctx* lfsr){
	w64 temp=0;
	int i;
	w64 newB;
	for(i=0;i<64;i++){
		if(lfsr->s&1)
			temp|=1uLL<<i;
		newB=(lfsr->s)&(lfsr->gx);
		lfsr->s>>=1;
		if(weight_w(newB)&1)
			lfsr->s|=lfsr->mask;
	}
	return temp;
}

void testLFSR64(){
	int l=4;
	w64 output;
	lfsr64_ctx* lfsr=init_lfsr64(l);
	lfsr->s=1;
	lfsr->gx=3;
	output=step_64(lfsr);
	println_w(output);
}

