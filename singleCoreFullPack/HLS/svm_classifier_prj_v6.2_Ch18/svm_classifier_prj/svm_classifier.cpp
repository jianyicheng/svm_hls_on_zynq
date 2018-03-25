#include "svm_data_type.h"
#include "svm_classifier.h"
#include "SV.h"
#include "alpha.h"
#include "getTanh.h"

#define MULT_LUT_NUM 0

void svm_classifier(data_t in[DIMENSION], bool *out)
{
#pragma HLS DATAFLOW

#pragma HLS ARRAY_RESHAPE variable=in cyclic factor=16 dim=1  //For Dimension
#pragma HLS ARRAY_PARTITION variable=SVs cyclic factor=18 dim=1  //For Channel
#pragma HLS ARRAY_RESHAPE variable=SVs cyclic factor=16 dim=2  //For Dimension
#pragma HLS ARRAY_PARTITION variable=alpha cyclic factor=18 dim=1  //For Channel
#pragma HLS INTERFACE s_axilite port=out
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite port=in

	data18_10t sum = 0, ch_sums[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	data13_4t s_in[DIMENSION];
	s_in[0] = in[0];
	s_in[1] = in[1];
	s_in[2] = in[2];
	s_in[3] = in[3];
	s_in[4] = in[4];
	s_in[5] = in[5];
	s_in[6] = in[6];
	s_in[7] = in[7];
	s_in[8] = in[8];
	s_in[9] = in[9];
	s_in[10] = in[10];
	s_in[11] = in[11];
	s_in[12] = in[12];
	s_in[13] = in[13];
	s_in[14] = in[14];
	s_in[15] = in[15];


#pragma HLS ARRAY_PARTITION variable=ch_sums cyclic factor=18 dim=1  //For Channel
	Sum_loop:	for (int i = 0; i < ALPHA_NUM; i++)
		{
			
#pragma HLS PIPELINE
#pragma HLS UNROLL factor=18  //For Channel

			data8_3t parameter_k;
			
			getKernel(SVs[i], s_in, &parameter_k);


			data18_10t temp = parameter_k * alpha[i];
			#pragma HLS RESOURCE variable=temp core=Mul_LUT
/*
			data32_16t mul_temp_lut[2] = {0, parameter_k};
    		data18_10t temp =   -(mul_temp_lut[alpha[i].get_bit(6)] << 6)
    					+(mul_temp_lut[alpha[i].get_bit(5)] << 5)
    					+(mul_temp_lut[alpha[i].get_bit(4)] << 4)
						+(mul_temp_lut[alpha[i].get_bit(3)] << 3)
						+(mul_temp_lut[alpha[i].get_bit(2)] << 2)
						+(mul_temp_lut[alpha[i].get_bit(1)] << 1)
						+(mul_temp_lut[alpha[i].get_bit(0)])
						+(mul_temp_lut[alpha[i].get_bit(-1)] >> 1)
						+(mul_temp_lut[alpha[i].get_bit(-2)] >> 2)
						+(mul_temp_lut[alpha[i].get_bit(-3)] >> 3)
						+(mul_temp_lut[alpha[i].get_bit(-4)] >> 4)
						+(mul_temp_lut[alpha[i].get_bit(-5)] >> 5)
						+(mul_temp_lut[alpha[i].get_bit(-6)] >> 6)
						+(mul_temp_lut[alpha[i].get_bit(-7)] >> 7)
						+(mul_temp_lut[alpha[i].get_bit(-8)] >> 8)
						+(mul_temp_lut[alpha[i].get_bit(-9)] >> 9);
*/
/*
	// This one can be adjusted
	data32_16t mul_temp_lut[2] = {0, alpha[i]};

	data18_10t temp =   -(mul_temp_lut[parameter_k.get_bit(3)] << 3)
						+(mul_temp_lut[parameter_k.get_bit(2)] << 2)
						+(mul_temp_lut[parameter_k.get_bit(1)] << 1)
						+(mul_temp_lut[parameter_k.get_bit(0)])
						+(mul_temp_lut[parameter_k.get_bit(-1)] >> 1)
						+(mul_temp_lut[parameter_k.get_bit(-2)] >> 2)
						+(mul_temp_lut[parameter_k.get_bit(-3)] >> 3)
						+(mul_temp_lut[parameter_k.get_bit(-4)] >> 4)
						+(mul_temp_lut[parameter_k.get_bit(-5)] >> 5)
						+(mul_temp_lut[parameter_k.get_bit(-6)] >> 6)
						+(mul_temp_lut[parameter_k.get_bit(-7)] >> 7)
						+(mul_temp_lut[parameter_k.get_bit(-8)] >> 8)
						+(mul_temp_lut[parameter_k.get_bit(-9)] >> 9)
						+(mul_temp_lut[parameter_k.get_bit(-10)] >> 10)
						+(mul_temp_lut[parameter_k.get_bit(-11)] >> 11)
						+(mul_temp_lut[parameter_k.get_bit(-12)] >> 12);
*/

			ch_sums[i % CH_NUM] += temp;

//			ch_sums[i % CH_NUM] += parameter_k * alpha[i];
			
		}
		
	Channel_Sum_loop: for(int i = 0; i < CH_NUM; i++)
		{
			
#pragma HLS PIPELINE
#pragma HLS UNROLL

			sum += ch_sums[i];
			
		}
	
	// *out = sum + bias >= 0 ? 0 : 1;
	*out = (sum + bias).is_neg();
}

void getKernel(data15_4t x[DIMENSION], data13_4t y[DIMENSION], data8_3t *out)
{
	
#pragma HLS INLINE

	data16_7t dotPro;
	
	dotProduct(x, y, &dotPro);
//	dotPro = dotPro << 1u;
	getTanh(dotPro, out);
	
}

// This might be improved; static might be added
void dotProduct(data15_4t x[DIMENSION], data13_4t y[DIMENSION], data16_7t *out)
{


#pragma HLS INLINE

	data16_7t pro = 0; //, pro_temp[MULT_LUT_NUM];
// #pragma HLS ARRAY_PARTITION variable=pro_temp cyclic factor=16 dim=1

	// Change DSP into MUL_LUT (which is successful to decrease the amount of DSP resources)
/*
	dotProduct_loop: for (int i = 0; i < DIMENSION; i++) 
		{
			
#pragma HLS UNROLL

		pro_temp[i] = x[i] * y[i];
#pragma HLS RESOURCE variable=pro_temp core=Mul_LUT
			
		}
*/

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
//#pragma HLS RESOURCE variable=pro_temp_12 core=Mul_LUT
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


/*	data16_7t pro_temp_0, pro_temp_1, pro_temp_2, pro_temp_3;

	dotPro_loop: for(int i = 0; i < 16; i += 4)
		{

			pro_temp_0 = x[0+i] * y[0+i];
			pro_temp_1 = x[1+i] * y[1+i];
			pro_temp_2 = x[2+i] * y[2+i];
			pro_temp_3 = x[3+i] * y[3+i];
#pragma HLS RESOURCE variable=pro_temp_2 core=Mul_LUT
#pragma HLS RESOURCE variable=pro_temp_3 core=Mul_LUT

			pro += 	 pro_temp_0
					+pro_temp_1
					+pro_temp_2
					+pro_temp_3;

		}
*/

/*
	dotSum_loop: for (int i = 0; i < DIMENSION; i++) 
		{
			
#pragma HLS UNROLL

			pro += pro_temp[i];
			
		}
*/
	*out = pro << 1u;
}
