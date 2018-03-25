#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>


#include "alpha.h"
#include "testData.h"
#include "SV.h"

#define Nsv 1050

int classify(double x[16]);

int main(){
	int i;
	double x[16];

	int ClassResult[2000];

	for (i=0; i<2000; i++){
		int j;
		
		// form input vector x
		for (j=0; j<16; j++)
			x[j] = testData[i*16+j];

		// call the function
		ClassResult[i] = classify(x);

		if (i<20)
			printf("Label: %d, Predicted: %d\n",testDataLabel[i], ClassResult[i]);
	}

	// Summary statistics
	double error_rate = 0.0;
	int error = 0;
	for (i=0; i<2000; i++){
		if (ClassResult[i] != testDataLabel[i])
			error++;
	}
	error_rate = error/2000.0;

	printf("Classification Error Rate: %f\n", error_rate);
}


int classify(double x[16]){
	int i, j;
	double sum = 0.0;

	for (i=0; i<Nsv; i++){
		// calculate the dot product
		double temp;
		temp = 0.0;
		for (j=0; j<16; j++)
			temp = temp + x[j]*SVs[i*16+j];

		sum = sum + alpha[i]*tanh(2*temp);
	}
	sum = sum + bias;

	if (sum>=0)
		return 0;
	else
		return 1;
}