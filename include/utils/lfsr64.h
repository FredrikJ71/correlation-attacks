/*
 * lfsr64.h
 *
 *  Created on: Dec 14, 2014
 *      Author: FredrikJ71
 *
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

#ifndef LFSR64_H_
#define LFSR64_H_

#include "utils/word64.h"
#include <stdlib.h>

typedef struct {
  //the representation of lfsr
	w64 s; //state
	w64 gx; //feedback polynomial
	int l;
	w64 mask;//1<<(l-1), used to calculate next bit
} lfsr64_ctx ;

lfsr64_ctx* init_lfsr64(int length);
//returns a struct that represents an lfsr with spec. length 

int step_1(lfsr64_ctx* lfsr);
//return next bit and update lfsr

w64 step_64(lfsr64_ctx* lfsr);
//generate next 64 bits of lfsr output, including updating state

#endif /* LFSR64_H_ */
