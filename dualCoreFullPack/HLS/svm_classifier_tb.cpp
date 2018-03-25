#include "testData.h"
#include "svm_classifier.h"
#include "svm_data_type.h"
#include <math.h>
#include <iostream>
#define DATA_NUM 2000
#define PRED_ERROR 170
#define DIMENSION 16
#define HW_COSIM

int main(void)
{

    bool output = false;
    bool *op;
    int err_cnt = 0;
    bool op_buffer[DATA_NUM] = {0};
    op = &output;

#ifdef HW_COSIM
    // Run the matrix multiply block
    for (int i = 0; i < DATA_NUM; i++)
    {
    	svm_classifier(&testData[DIMENSION*i], op);
        op_buffer[i] = *op;
    }
#endif


#ifdef HW_COSIM
    for (int i = 0; i < DATA_NUM; i++)
    {
        // Check HW result against SW
        if (op_buffer[i] != testDataLabel[i]) {
            err_cnt += 1;
        }
    }
#else
    // cout << *op;
#endif
/*
    // DA test
    int i = 2;
    data16_7t alpha[3] = {0, 0, 1.619991};
    data_t parameter_k = 0.3786;
    data18_10t print_temp = alpha[i]*parameter_k;
    std::cout << "idea temp = " << print_temp << std::endl;

    std::cout << "alpha range = " << alpha[3].width << std::endl;
    std::cout << "parameter_k range = " << parameter_k.width << std::endl;

    for (int j = -9; j < alpha[3].width-9; j++){
    	std::cout << "alpha[" << j << "] = " << alpha[i].get_bit(j) << std::endl;
    }
    for (int j = -12; j < parameter_k.width-12; j++){
        	std::cout << "parameter_k[" << j << "] = " << parameter_k.get_bit(j) << std::endl;
        }

if (1)
{
    data_t mul_temp_lut[2] = {0, parameter_k};
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
    std::cout << "actual temp = " << temp << std::endl;
}
else
{


  data16_7t mul_temp_lut[2] = {0, alpha[i]};

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
	std::cout << "actual temp = " << temp << std::endl;
}

*/
#ifdef HW_COSIM
    if (err_cnt != PRED_ERROR)
    	std::cout << "ERROR: " << (float)err_cnt/20.0 << "% mismatches detected!" << std::endl
        << "Expected mismatches: " << PRED_ERROR/20.0 << "%." << std::endl;
    else
    	std::cout << "Test passes." << std::endl;
#endif
    return (err_cnt-PRED_ERROR);
}
