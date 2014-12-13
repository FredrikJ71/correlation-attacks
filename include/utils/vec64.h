/*
 * vec64.h
 *
 *  Created on: Dec 13, 2014
 *      Author: FredrikJ71
 * 
 * Methods for handling a vector(array) of bits 
 * The methods can be divided into three classes
 * Manipulate individual bits, print vector, calculate weight
 *
*/
#ifndef VEC64_H_
#define VEC64_H_

#include "utils/word64.h"
#include <stdio.h>

void print_v(w64 *vec,int n);
//print a vector of 64-bit words
//n number of words to print in w

void println_v(w64 *vec,int n);
//print a vector of 64-bit words
//n number of words to print in w
//end with newline

inline static int getBit_v(w64 *vec,unsigned n){
//return the value of bit n in the vector
//bit0 is the least significant bit
//it is assumed that the user checks '
//that vec contains at least n bits
  return ((vec[n>>6])&(1uLL<<(n%0x3f)))==0?0:1;
}

inline static void set_v(w64 *vec,unsigned n){
//set bit n of the vector to 1
//bit0 is the least significant bit
//it is assumed that the user checks
//that vec contains at least n bits
  (vec[n>>6])|=(1uLL<<(n%0x3f));
}

inline static void clear_v(w64 *vec,unsigned n){
//set bit n of the vector to 0
//bit0 is the least significant bit
//it is assumed that the user checks
//that vec contains at least n bits
  (vec[n>>6])&=~(1uLL<<(n%0x3f));
}

inline static void setVal_v(w64 *vec,unsigned n,int b){
//set bit n of vector to value specified in b
//bit0 is the least significant bit
//it is assumed that the user checks
//that vec contains at least n bits
  if(b==0){
    clear_v(vec,n);
  }
  else{
    set_v(vec,n);
  }
}

int weight_v(w64 *vec,int n);
//returns the weight (number of bits=1) of vec
//it is assumed that the user checks
//that vec contains at least n 64-bit words


#endif /* VEC64_H_ */
