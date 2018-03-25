/*
 * sw_tanh_classifier.cpp
 *
 *  Created on: 6 Mar 2018
 *      Author: jc9016
 */

#include "svm_data_type.h"
#include "sw_tanh_classifier.h"
#include <math.h>
#include "alpha.h"
#include "SV.h"

void sw_tanh_classifier(data_t ip[DIMENSION], bool *op)
{
	float kernel_result = 0;
	    Loop_1050: for (int i = 0; i < SV_SET_NUM; i++)
	    {
	    	float temp = 0;
	    	Loop_16: for (int j = 0; j < DIMENSION; j++)
	    	{
	    	    temp += 2.0*(float)ip[j]*SVs[i*DIMENSION+j];
	    	}
	    	kernel_result += alpha[i]*tanh(temp);
	    }

	    kernel_result += bias;
	    if (kernel_result > 0)
	        *op = 0;
	    else
	        *op = 1;
}
