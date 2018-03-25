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
/*
			data10_4t sinh_int, cosh_int;

			if(theta_int == 0)
			{
				sinh_int = 0.0;
				cosh_int = 1.0;
			} else if(theta_int == 1){
				sinh_int = 0.1175048828;
				cosh_int = 0.154296875;
			} else if(theta_int == 2){
				sinh_int = 0.3626708984;
				cosh_int = 0.3761962891;
			} else if(theta_int == 3){
				sinh_int = 1.001782227;
				cosh_int = 1.006762695;
			} else if(theta_int == 4){
				sinh_int = 2.728979492;
				cosh_int = 2.730810547;
			} else {
				sinh_int = 7.4203125;
				cosh_int = 7.42097168;
			}
*/
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

/*			data_t sinh_out, cosh_out;

			data_t mul_lut_temp[2][2] = {0, cosh_frac, sinh_frac, sinh_frac+cosh_frac};

						// sinh_out = sinh_lut[theta_int] * cosh_frac + cosh_lut[theta_int] * sinh_frac;
			sinh_out = -(mul_lut_temp[cosh_lut[theta_int].get_bit(6)][sinh_lut[theta_int].get_bit(6)] << 3)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(5)][sinh_lut[theta_int].get_bit(5)] << 2)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(4)][sinh_lut[theta_int].get_bit(4)] << 1)
					   +mul_lut_temp[cosh_lut[theta_int].get_bit(3)][sinh_lut[theta_int].get_bit(3)]
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(2)][sinh_lut[theta_int].get_bit(2)] >> 1)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(1)][sinh_lut[theta_int].get_bit(1)] >> 2)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(0)][sinh_lut[theta_int].get_bit(0)] >> 3)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-1)][sinh_lut[theta_int].get_bit(-1)] >> 4)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-2)][sinh_lut[theta_int].get_bit(-2)] >> 5)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-3)][sinh_lut[theta_int].get_bit(-3)] >> 6)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-4)][sinh_lut[theta_int].get_bit(-4)] >> 7)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-5)][sinh_lut[theta_int].get_bit(-5)] >> 8)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-6)][sinh_lut[theta_int].get_bit(-6)] >> 9)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-7)][sinh_lut[theta_int].get_bit(-7)] >> 10)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-8)][sinh_lut[theta_int].get_bit(-8)] >> 11)
					   +(mul_lut_temp[cosh_lut[theta_int].get_bit(-9)][sinh_lut[theta_int].get_bit(-9)] >> 12);

			cosh_out = -(mul_lut_temp[sinh_lut[theta_int].get_bit(6)][cosh_lut[theta_int].get_bit(6)] << 3)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(5)][cosh_lut[theta_int].get_bit(5)] << 2)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(4)][cosh_lut[theta_int].get_bit(4)] << 1)
					   +mul_lut_temp[sinh_lut[theta_int].get_bit(3)][cosh_lut[theta_int].get_bit(3)]
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(2)][cosh_lut[theta_int].get_bit(2)] >> 1)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(1)][cosh_lut[theta_int].get_bit(1)] >> 2)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(0)][cosh_lut[theta_int].get_bit(0)] >> 3)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-1)][cosh_lut[theta_int].get_bit(-1)] >> 4)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-2)][cosh_lut[theta_int].get_bit(-2)] >> 5)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-3)][cosh_lut[theta_int].get_bit(-3)] >> 6)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-4)][cosh_lut[theta_int].get_bit(-4)] >> 7)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-5)][cosh_lut[theta_int].get_bit(-5)] >> 8)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-6)][cosh_lut[theta_int].get_bit(-6)] >> 9)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-7)][cosh_lut[theta_int].get_bit(-7)] >> 10)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-8)][cosh_lut[theta_int].get_bit(-8)] >> 11)
					   +(mul_lut_temp[sinh_lut[theta_int].get_bit(-9)][cosh_lut[theta_int].get_bit(-9)] >> 12);

			data9_3t sinh_final, cosh_final;
			sinh_final = sinh_out;
			cosh_final = cosh_out;
*/

//#pragma HLS RESOURCE variable=pro core=HDiv
			// cannot convert from ap_fixed to half-precision float directly.
			pro = sinh_out / cosh_out;
			temp = pro;

//			temp = sinh_out / cosh_out;
			
		}

	// Correct the sign of the final output
	*out = neg ? (data8_3t)-temp : temp;
}

void cordic_sinh_cosh(data16_7t theta_in, data_t *sinh, data_t *cosh)
{
	
#pragma HLS INLINE

	data_t x = K_RECIPROCAL, y = 0;

	Iteration_loop:	for(char i = 0; i < ITER_NUM; i++) 
		{
			
//#pragma HLS PIPELINE
#pragma HLS UNROLL

			int it = iter[i];
			
			int d = theta_in.is_neg() ? -1 : 1;
				
			data_t x_next = x + ((d * y) >> it);
			y = y + ((d * x) >> it);
			x = x_next;
			
			theta_in = theta_in - (d * pow_lut[it - 1u]);
			
		}
	
	*sinh = y;
	*cosh = x;

}
