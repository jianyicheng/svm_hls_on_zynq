#include "svm_classifier.h"
#include "getTanh.h"

void getKernel(data15_4t x[DIMENSION], data13_4t y[DIMENSION], data8_3t *out)
{
	
#pragma HLS INLINE

	data16_7t dotPro;
	
	dotProduct(x, y, &dotPro);

	getTanh(dotPro, out);
	
}
