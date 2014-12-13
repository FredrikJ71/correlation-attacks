/*
 * vec64.c
 *
 *  Created on: Nov 6, 2014
 *      Author: fredrik
 */


#include "vec64.h"

//print a vector of 64-bit words
//n number of words to print in w
void print_v(w64 *vec,int n){
	int i;
	for(i=0;i<n;i++){
		print_w(vec[i]);
		printf(" ");
	}
}

//print a vector of 64-bit words
//n number of words to print in w
//end with newline
void println_v(w64 *vec,int n){
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
void testVec64(){
	w64 vector[4];
	vector[0]=0x1122334455667788uLL;
	vector[1]=0x9900AABBCCDDEEFFuLL;
	vector[2]=0x2468ACE13579BDFuLL;
	vector[3]=0x123456789ABCDEFuLL;
	println_v(vector,4);
	printf("%d\n",weight_v(&vector[1],2));
}
