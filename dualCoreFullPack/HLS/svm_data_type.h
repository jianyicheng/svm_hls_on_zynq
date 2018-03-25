#ifndef _SVM_DATA_TYPE_H_
#define _SVM_DATA_TYPE_H_

#include <ap_fixed.h>

typedef ap_fixed<18, 10> data18_10t;// Used in the summation
typedef ap_fixed<16, 7> data16_7t;	// Used in CORDIC and dotProduct to get higher precision result
typedef ap_fixed<16, 4> data_t;		// Used in in (the entry of testData)
typedef ap_fixed<15, 4> data15_4t;	// Used in SVs
typedef ap_fixed<13, 4> data13_4t;	// Used in input data (since "in" must be data_t in svm_classifier funciton)
typedef ap_fixed<10, 4> data10_4t;	// Used in sinh_int & cosh_int
typedef ap_fixed< 8, 3> data8_3t;	// Used in CORDIC and parameter_k
typedef ap_fixed<12, 2> data12_2t;	// For sinh_frac & cosh_frac
typedef ap_fixed<13, 5> data13_5t;	// Used in alpha

#endif
