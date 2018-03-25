

#ifndef _SVM_CLASSIFIER_H_
#define _SVM_CLASSIFIER_H_

#include "svm_data_type.h"
#define DIMENSION 16
#define CH_NUM 18
#define ALPHA_NUM 1050

void dotProduct(data15_4t x[DIMENSION], data13_4t y[DIMENSION], data16_7t *out);
void getKernel(data15_4t x[DIMENSION], data13_4t y[DIMENSION], data8_3t *out);
void svm_classifier(data_t in[DIMENSION], bool *out);

#endif

