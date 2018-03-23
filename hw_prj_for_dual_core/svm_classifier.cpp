#include "svm_data_type.h"
#include "svm_classifier.h"
#include "SV.h"
#include "alpha.h"

#define MULT_LUT_NUM 0

void svm_classifier(data_t in[DIMENSION], bool *out)
{

#pragma HLS DATAFLOW
#pragma HLS ARRAY_RESHAPE variable=in cyclic factor=16 dim=1  //For Dimension
#pragma HLS ARRAY_PARTITION variable=SVs cyclic factor=9 dim=1  //For Channel
#pragma HLS ARRAY_RESHAPE variable=SVs cyclic factor=16 dim=2  //For Dimension
#pragma HLS ARRAY_PARTITION variable=alpha cyclic factor=9 dim=1  //For Channel
#pragma HLS INTERFACE s_axilite port=out
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite port=in

	data18_10t sum = 0, ch_sums[9] = {0,0,0,0,0,0,0,0,0};
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


#pragma HLS ARRAY_PARTITION variable=ch_sums cyclic factor=9 dim=1  //For Channel
	Sum_loop:	for (int i = 0; i < ALPHA_NUM; i++)
		{
			
#pragma HLS PIPELINE
#pragma HLS UNROLL factor=9  //For Channel

			data8_3t parameter_k;
			
			getKernel(SVs[i], s_in, &parameter_k);


			data18_10t temp = parameter_k * alpha[i];
			#pragma HLS RESOURCE variable=temp core=Mul_LUT

			ch_sums[i % CH_NUM] += temp;
			
		}
		
	Channel_Sum_loop: for(int i = 0; i < CH_NUM; i++)
		{
			
#pragma HLS PIPELINE
#pragma HLS UNROLL

			sum += ch_sums[i];
			
		}
	
	*out = (sum + bias).is_neg();
}

