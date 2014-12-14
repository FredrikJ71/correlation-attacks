/*
 * vec64.c
 *
 *  Created on: Nov 6, 2014
 *      Author: FredrikJ71
 */


#include "utils/vec64.h"

int test_bit(){
  int test=0;
  w64 v1[4];
  w64 v2[4];
  v1[0]=0x1234567812345678uLL;
  v1[1]=0x9abcdef09abcdef0uLL;
  v1[2]=0x0123456789abcdefuLL;
  v1[3]=0xaabbccddeeff1337uLL;
  for(int i=0;i<256;i++){
    int val=getBit_v(v1,i);
    setVal_v(v2,i,val);
    //printf("%d\t%d\n",i,val);
  }
  //println_v(v1,4);
  //println_v(v2,4);
  if(v1[0]!=v2[0])
    test=1;
  if(v1[1]!=v2[1])
    test=1;
  if(v1[2]!=v2[2])
    test=1;
  if(v1[3]!=v2[3])
    test=1;
  return test;
}

int test_weight(){
  w64 v1[4];
  v1[0]=0x1234567812345678uLL; //w=26
  v1[1]=0x9abcdef09abcdef0uLL; //w=38
  v1[2]=0x0123456789abcdefuLL; //w=32
  v1[3]=0xaabbccddeeff1337uLL; //w=42
  int weight=weight_v(v1,4);
  if(weight==138)
    return 0;
  return 1;
}

int testVec64(){
	w64 vector[4];
	printf("Testing vec64:\n");
	int test=test_bit();
	printf("Bit functions:\n");
	if(test==1)
	  printf("Bit functions failed\n");
	printf("Testing weight\n");
	int temp=test_weight();
	if(temp==1){
	  test=1;
	  printf("Weight vector failed\n");
	}
	if(test==0)
	  printf("Vector test passed\n");
	if(test==1)
	  printf("Vector test failed\n");
	return test;
	
}

int main(){
  testVec64();
  return 0;
}
