/*
 * word64.h
 *
 *  Created on: Nov 5, 2014
 *      Author: fredrik
 */

#ifndef WORD64_H_
#define WORD64_H_

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

//64-bit word w64
typedef uint_fast64_t w64;

//print the word in hexadecimal
void print_w(w64 w);

//print the word in hexadecimal end with newline
void println_w(w64 w);

inline static int getBit_w(w64 w,int n){
  //return the value of bit n
  //bit0 is the least significant bit
  //it is assumed that the user checks that 0<=n<64
  return (w&(1uLL<<n))==0?0:1;
}

inline static void set_w(w64 *w,int n){
  //set bit n to 1
  //bit0 is the least significant bit
  //it is assumed that the user checks that 0<=n<64
  (*w)|=(1uLL<<n);
}

inline static void clear_w(w64 *w,int n){
  //set bit n to 0
  //bit0 is the least significant bit
  //it is assumed that the user checks that 0<=n<64
  (*w)&=~(1uLL<<n);
}

inline static void setVal_w(w64 *w,int n,int b){
  //set bit n to value specified in b
  //bit0 is the least significant bit
  //it is assumed that the user checks that 0<=n<64
  if(b==0){
	  clear_w(w,n);
  }
  else{
	  set_w(w,n);
  }
}

int weight_w(w64 w);
//returns the weight (number of bits=1) of w

void testWord64();

#endif /* WORD64_H_ */
