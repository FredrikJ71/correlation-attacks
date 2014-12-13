/*
 * vec64.c
 *
 *  Created on: Dec 13, 2014
 *      Author: FredrikJ71
 * 
 * Methods for handling a vector(array) of bits 
 *
*/

#include "utils/vec64.h"


void print_v(w64 *vec,int n){
//print a vector of 64-bit words
//n number of words to print in w
  int i;
  for(i=0;i<n;i++){
    print_w(vec[i]);
    printf(" ");
  }
}


void println_v(w64 *vec,int n){
//print a vector of 64-bit words
//n number of words to print in w
//end with newline
  print_v(vec,n);
  printf("\n");
}


int weight_v(w64 *vec,int n){
//returns the weight (number of bits=1) of vec
//it is assumed that the user checks
//that vec contains at least n 64-bit words
  int i=0;
  int w=0;
  for(i=0;i<n;i++)
    w+=weight_w(vec[i]);
  return w;
}

