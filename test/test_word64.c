/*
 * test_word64.c
 *
 *  Created on: Dec 6, 2014
 *      Author: FredrikJ71
 *
 * Implements functions for testing 64-bit words
 * It is assumed that the 64-bit functions are defined in utils/word64.h
 */

#include "utils/word64.h"
#include <stdio.h>

int test_bit_w64(){
  //test bit manipulations of 64-bit words
  w64 w1=0xffffcccc88883333ULL;
  w64 w2=0;
  w64 w3=0x777755553333ccccULL;
  w64 w4=0;
  w64 w5=0xaaaaaaaaaaaaaaaaULL;
  w64 w6=0x5555555555555555ULL;
  for(int i=0;i<64;i++){
    int val=getBit_w(w1,i);
    setVal_w(&w2,63-i,val);
    val=getBit_w(w3,i);
    setVal_w(&w4,63-i,val);
    clear_w(&w5,i);
    clear_w(&w6,i);
  }
  if((w2==0xcccc11113333ffffULL)&&(w4==0x3333ccccaaaaeeeeULL)
     &&(w5==0)&&(w6==0)){
    printf("Test bit manipulations ok\n");
    return 0;
  }
  else{
    println_w(w2);
    println_w(w4);
    println_w(w5);
    println_w(w6);
    return 1;
  }
}

int test_weight_w(){
  //create 2 words with known value
  //calculate weight and compare with precomputed value
  w64 w1=0xffeeddccbbaa9988ULL;
  w64 w2=0x0011223344556677ULL;
  if((weight_w(w1)==40)&&(weight_w(w2)==24)){
    printf("Test weight ok\n");
    return 0;
  }
  else{
    printf("%d\t",weight_w(w1));
    println_w(w1);
    printf("%d\t",weight_w(w2));
    println_w(w2);
    return 1;
  }

}



int main(){
  int res=0;
  int temp=0;
  printf("Testing word64\n");
  temp=test_bit_w64();
  if(temp==1)
    res=1;
  temp=test_weight_w();
  if(temp==1)
    res=1;
  if(res==0){
    printf("Passed testing word64\n");
  }
  return res;
}
