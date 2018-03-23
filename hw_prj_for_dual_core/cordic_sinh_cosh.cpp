#include "getTanh.h"

void cordic_sinh_cosh(data16_7t theta_in, data_t *sinh, data_t *cosh)
{
	
#pragma HLS INLINE

	data_t x = K_RECIPROCAL, y = 0;

	Iteration_loop:	for(char i = 0; i < ITER_NUM; i++) 
		{
			
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
