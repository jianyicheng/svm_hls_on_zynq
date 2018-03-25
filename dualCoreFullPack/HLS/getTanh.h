#ifndef _GETTANH_H_
#define _GETTANH_H_

#include "svm_data_type.h"

#define K_RECIPROCAL	1.207497067763f
#define ITER_NUM	6u
#define BOUND		5.0

static const data10_4t sinh_lut[6] = {0.0, 0.1175048828, 0.3626708984, 1.001782227, 2.728979492, 7.4203125};
static const data10_4t cosh_lut[6] = {1.0, 0.154296875, 0.3761962891, 1.006762695, 2.730810547, 7.42097168};

static const int iter[ITER_NUM] = {1, 2, 3, 4, 4, 5};

static const data_t pow_lut[] = {
		0.549306, 0.255413, 0.125657, 0.0625816, 0.0312602, 0.0156263, 0.00781266,
		0.00390627, 0.00195313, 0.000976563, 0.000488281, 0.000244141, 0.00012207, 6.10352e-05
	};

void cordic_sinh_cosh(data16_7t theta_in, data_t *sinh, data_t *cosh);
void getTanh(data16_7t theta, data8_3t *output);

//data10_4t sinh_transfer(int theta_int);
//data10_4t cosh_transfer(int theta_int);

#endif
