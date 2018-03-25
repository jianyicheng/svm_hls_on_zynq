#include "svm_classifier.h"

void dotProduct(data15_4t x[DIMENSION], data13_4t y[DIMENSION], data16_7t *out)
{


#pragma HLS INLINE

	data16_7t pro = 0;

	data16_7t pro_temp_0 = x[0] * y[0];
	data16_7t pro_temp_1 = x[1] * y[1];
	data16_7t pro_temp_2 = x[2] * y[2];
	data16_7t pro_temp_3 = x[3] * y[3];
	data16_7t pro_temp_4 = x[4] * y[4];
	data16_7t pro_temp_5 = x[5] * y[5];
	data16_7t pro_temp_6 = x[6] * y[6];
	data16_7t pro_temp_7 = x[7] * y[7];
	data16_7t pro_temp_8 = x[8] * y[8];
	data16_7t pro_temp_9 = x[9] * y[9];
	data16_7t pro_temp_10 = x[10] * y[10];
	data16_7t pro_temp_11 = x[11] * y[11];
	data16_7t pro_temp_12 = x[12] * y[12];
#pragma HLS RESOURCE variable=pro_temp_12 core=Mul_LUT
	data16_7t pro_temp_13 = x[13] * y[13];
#pragma HLS RESOURCE variable=pro_temp_13 core=Mul_LUT
	data16_7t pro_temp_14 = x[14] * y[14];
#pragma HLS RESOURCE variable=pro_temp_14 core=Mul_LUT
	data16_7t pro_temp_15 = x[15] * y[15];
#pragma HLS RESOURCE variable=pro_temp_15 core=Mul_LUT

	pro = 	 pro_temp_0
			+pro_temp_1
			+pro_temp_2
			+pro_temp_3
			+pro_temp_4
			+pro_temp_5
			+pro_temp_6
			+pro_temp_7
			+pro_temp_8
			+pro_temp_9
			+pro_temp_10
			+pro_temp_11
			+pro_temp_12
			+pro_temp_13
			+pro_temp_14
			+pro_temp_15;

	*out = pro << 1u;
}
