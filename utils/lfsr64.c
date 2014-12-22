/*
 * lfsr64.c
 *
 *  Created on: Dec 14, 2014
 *      Author: FredrikJ71
 *
 * linear feedback shift register
 * length l, maximum 64
 * output signal s[0], s[1], ...
 * new bits are generated as s[l]=s[l-1]g1+s[l-2]g2+...+s[0]gl
 * gx=1+g1x+g2x^2+...+glx^l
 * for efficient computation
 * gx is stored gx[0]=gl, gx[1]=gl-1, ... gx[l-1]=g1
 * since we assume feedback g0 does not need to be stored

 */

#include "utils/lfsr64.h"

lfsr64_ctx* init_lfsr64(int length){
//returns a struct that represents an lfsr with spec. length 
	lfsr64_ctx *lfsr=(lfsr64_ctx *)malloc(sizeof(lfsr64_ctx));
	lfsr->l=length;
	lfsr->mask=1uLL<<(length-1);
	lfsr->s=0;
	lfsr->gx=0;
	return lfsr;
}

int step_1(lfsr64_ctx* lfsr){
//return next bit and update lfsr
	int temp=(lfsr->s&1);
	w64 newB=(lfsr->s)&(lfsr->gx);
	lfsr->s>>=1;
	if(weight_w(newB)&1)
		lfsr->s|=lfsr->mask;
	return temp;
}

w64 step_64(lfsr64_ctx* lfsr){
//generate next 64 bits of lfsr output, including updating state
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


