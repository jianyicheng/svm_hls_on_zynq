#include "getTanh.h"

void getTanh(data16_7t theta_in, data8_3t *out)
{
	
#pragma HLS PIPELINE

	data8_3t temp;
	data8_3t pro;

	bool neg = theta_in < 0;
	if (neg)
		theta_in = -theta_in;

	// Optimize the range of the cordic
	if (theta_in >= (data16_7t)BOUND)
		{
			
			temp = 1.0;
			
		} else {
			
			// Trigo index to extend range
			int theta_int = theta_in;
			theta_in = theta_in - theta_int;
			
			// Call Cordic function
			data_t sinh_frac, cosh_frac;
			cordic_sinh_cosh(theta_in, &sinh_frac, &cosh_frac);
			
			// Trigo rules
			data_t sincos, sinsin, cossin, coscos;

			sincos = sinh_lut[theta_int] * ((data12_2t)cosh_frac);
			sinsin = sinh_lut[theta_int] * ((data12_2t)sinh_frac);
			cossin = cosh_lut[theta_int] * ((data12_2t)sinh_frac);
			coscos = cosh_lut[theta_int] * ((data12_2t)cosh_frac);
#pragma HLS RESOURCE variable=coscos core=Mul_LUT
#pragma HLS RESOURCE variable=cossin core=Mul_LUT
#pragma HLS RESOURCE variable=sinsin core=Mul_LUT
#pragma HLS RESOURCE variable=sincos core=Mul_LUT

			data8_3t sinh_out, cosh_out;
			sinh_out = sincos + cossin;
			cosh_out = coscos + sinsin;

			// cannot convert from ap_fixed to half-precision float directly.
			pro = sinh_out / cosh_out;
			temp = pro;
			
		}

	// Correct the sign of the final output
	*out = neg ? (data8_3t)-temp : temp;
}
