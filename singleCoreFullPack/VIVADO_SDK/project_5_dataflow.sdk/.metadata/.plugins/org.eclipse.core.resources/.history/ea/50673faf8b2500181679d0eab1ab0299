/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include "svm_data_type.h"
#include "testData.h"


#include <stdio.h>
#include "xil_printf.h"
// Add BSP header files
#include <stdlib.h>  // Standard C functions, e.g. exit()
// #include <stdbool.h> // Provides a Boolean data type for ANSI/ISO-C
#include <arm_neon.h>
#include "xparameters.h" // Parameter definitions for processor periperals
#include "xscugic.h"     // Processor interrupt controller device driver
#include "xsvm_classifier.h"   // Device driver for HLS HW block
#include "xtime_l.h"

#include "sw_tanh_classifier.h"

// HLS svm_classifier HW instance
XSvm_classifier classifier;
//Interrupt Controller Instance
XScuGic ScuGic;
// Global variable definitions - used by ISR
volatile static int classifier_run = 0;
volatile static int classifier_res_vld = 0;

// volatile int data_set_ctr = 0;
// volatile u32 res_hw[TESTDATA_SET_NUM] = {0};

// Setup and helper functions
int setup_interrupt();
int hls_classifier_init(XSvm_classifier *classifier_ptr);
void hls_classifier_start(void *classifier_ptr);
// The ISR prototype
void hls_classifier_isr(void *classifier_ptr);
// Software model of HLS hardware
void sw_cordic_classifier(data_t ip[DIMENSION], bool *op);

volatile static int data_set_ctr = 0;
volatile static u32 res_hw[TESTDATA_SET_NUM] = {0};
data_t *classifier_buffer = &testData[0];


int main()
{
	print("\r\nBuild @ " __DATE__ " " __TIME__ "\r\n");
	print("Program to test communication with HLS MACC block in PL\n\r");


	// int data_set_ctr = 0;
	XTime  start_time = 0;
	XTime  end_time = 0;
	int dt = 0;
	XTime t = 0;

   int status;

   //Setup the matrix mult
   status = hls_classifier_init(&classifier);
   if(status != XST_SUCCESS){
      print("HLS peripheral setup failed\n\r");
      exit(-1);
   }
   //Setup the interrupt
   status = setup_interrupt();
   if(status != XST_SUCCESS){
      print("Interrupt setup failed\n\r");
      exit(-1);
   }

   // Get timer offset
   XTime_SetTime(0);
   XTime_GetTime(&start_time);
   XTime_GetTime(&end_time);
   dt = end_time - start_time;
   printf("Precalculation: \n");
   printf("time test start: %llu \n", start_time);
   printf("time test end : %llu \n", end_time);
   printf("time offset : %d \n", dt);



   if (XSvm_classifier_IsReady(&classifier))
      print("HLS peripheral is ready.  Starting... ");
   else {
      print("!!! HLS peripheral is not ready! Exiting...\n\r");
      exit(-1);
   }

   if (0) {
	   	 print("\n\r---------------Interrupt test-------------- \n\r");

	     // use interrupt
	     //classifier_run = 1;
	     XTime_SetTime(0);
	     XTime_GetTime(&start_time);
	     XSvm_classifier_Set_in_V(&classifier, *((XSvm_classifier_In_v *)classifier_buffer));
	     hls_classifier_start(&classifier);
	     do{
	    	 classifier_buffer += 16;
	    	 XSvm_classifier_Set_in_V(&classifier, *((XSvm_classifier_In_v *)classifier_buffer));

	    	 while(!classifier_res_vld); // spin
	    	 classifier_res_vld = 0;

	    	 res_hw[data_set_ctr] = XSvm_classifier_Get_out_r(&classifier);
	    	 hls_classifier_start(&classifier);
	    	 data_set_ctr++;


         }while (data_set_ctr < TESTDATA_SET_NUM);

	     XTime_GetTime(&end_time);
	     printf("HW: \n");
	     printf("time test start: %llu \n", start_time);
	     printf("time test end : %llu \n", end_time);
	     t = end_time-start_time-dt;
	     printf("time difference : %llu \n", t);
	     printf("Actual hardware time: %f ms.\n", ((float)t)*3e-6);

      } else {
    	  	  print("\n\r---------------No interrupt test------------ \n\r");
    	  	  XTime_SetTime(0);
    	  	  XTime_GetTime(&start_time);
    	  	  XSvm_classifier_Set_in_V(&classifier, *((XSvm_classifier_In_v *)classifier_buffer));
    	  	  XSvm_classifier_Start(&classifier);
    	  	  do
    	  	  {
    	  		  classifier_buffer += 16;
    	  		  XSvm_classifier_Set_in_V(&classifier, *((XSvm_classifier_In_v *)classifier_buffer));
				  do {
					  res_hw[data_set_ctr] = XSvm_classifier_Get_out_r(&classifier);
				  } while (!XSvm_classifier_IsReady(&classifier));
				  res_hw[data_set_ctr] = XSvm_classifier_Get_out_r(&classifier);
				  XSvm_classifier_Start(&classifier);
				  data_set_ctr++;
    	  	  }while (data_set_ctr < TESTDATA_SET_NUM);
    	  	  XTime_GetTime(&end_time);
    	  	  printf("HW: \n");
    	  	  printf("time test start: %llu \n", start_time);
    	  	  printf("time test end : %llu \n", end_time);
    	  	  t = end_time-start_time-dt;
    	  	  printf("time difference : %llu \n", t);

    	  	  printf("Actual hardware time: %f ms.\n", ((float)t)*3e-6);

      }

   	   	 // quick look - deleted later
      	 int kk = 0;
         for (int i = 0; i < TESTDATA_SET_NUM; i++)
         {
         	   if (res_hw[i] != (u32) testDataLabel[i])
         		   kk++;
         }
         printf("HW error rate: %f\n\r", ((float)kk/2000.0));

   // Floating point SW verification process
   data_t *sw_ip = &testData[0];
   bool res_sw[TESTDATA_SET_NUM] = {0};
   bool *sw_op = res_sw;
   XTime_SetTime(0);
   XTime_GetTime(&start_time);
   for (int i = 0; i < TESTDATA_SET_NUM; i++)
   {
	   sw_tanh_classifier(sw_ip, sw_op);
	   sw_ip += 16;
	   sw_op ++;
   }
   XTime_GetTime(&end_time);
   printf("Floating point SW: \n");
   printf("time test start: %llu \n", start_time);
   printf("time test end : %llu \n", end_time);
   t = end_time-start_time-dt;
   printf("time difference : %llu \n", t);
   printf("Actual hardware time: %f s.\n", ((float)t)*3e-9);



   // Result correctness check
   int hw_error = 0;
   int sw_error = 0;
   for (int i = 0; i < TESTDATA_SET_NUM; i++)
   {
   	   if (res_hw[i] != (u32) testDataLabel[i])
   		   hw_error++;
   	   if (res_sw[i] != (u32) testDataLabel[i])
   		   sw_error++;
   }
   // printf("HW error rate: %f\n\r", ((float)hw_error/2000.0));
   // printf("SW error rate: %f\n\r", ((float)sw_error/2000.0));

   if (hw_error == sw_error) {
      printf("*** Results match: Error rate = %f %***\n\r", ((float)hw_error/20.0));
      status = 0;
   }
   else {
      printf("!!! MISMATCH !!!\n\r Error rate = %f %\n\r", ((float)hw_error/20.0));
      status = -1;
   }

   return status;
}

int hls_classifier_init(XSvm_classifier *classifier_ptr)
{
	XSvm_classifier_Config *cfgPtr;
   int status;

   cfgPtr = XSvm_classifier_LookupConfig(XPAR_SVM_CLASSIFIER_0_DEVICE_ID);
   if (!cfgPtr) {
      print("ERROR: Lookup of accelerator configuration failed.\n\r");
      return XST_FAILURE;
   }
   status = XSvm_classifier_CfgInitialize(classifier_ptr, cfgPtr);
   if (status != XST_SUCCESS) {
      print("ERROR: Could not initialize accelerator.\n\r");
      return XST_FAILURE;
   }
   return status;
}

void hls_classifier_start(void *classifier_ptr){
	XSvm_classifier *pAccelerator = (XSvm_classifier *)classifier_ptr;
	XSvm_classifier_InterruptEnable(pAccelerator,1);
	XSvm_classifier_InterruptGlobalEnable(pAccelerator);
	XSvm_classifier_Start(pAccelerator);
}

void hls_classifier_isr(void *classifier_ptr){

	XSvm_classifier *pAccelerator = (XSvm_classifier *)classifier_ptr;

   // clear the local interrupt
	XSvm_classifier_InterruptClear(pAccelerator,1);

	// res_hw[data_set_ctr] = XSvm_classifier_Get_out_r(pAccelerator);
	// data_set_ctr++;
    classifier_res_vld = 1;

   // restart the core if it should run again
    /*
   if(classifier_run){
	   input_sw = input_sw ? 0 : 1;
	   XSvm_classifier_Set_input_sw(pAccelerator, (u32) input_sw);
       hls_classifier_start(pAccelerator);
       classifier_buffer += 16;
       if (!input_sw)
       {
        	XSvm_classifier_Set_in_1_V(pAccelerator, *((XSvm_classifier_In_1_v *)classifier_buffer));
        }
        else
        {
          	XSvm_classifier_Set_in_2_V(pAccelerator, *((XSvm_classifier_In_2_v *)classifier_buffer));
        }
   }
   */
}

int setup_interrupt()
{
   //This functions sets up the interrupt on the ARM
   int result;
   XScuGic_Config *pCfg = XScuGic_LookupConfig(XPAR_SCUGIC_SINGLE_DEVICE_ID);
   if (pCfg == NULL){
      print("Interrupt Configuration Lookup Failed\n\r");
      return XST_FAILURE;
   }
   result = XScuGic_CfgInitialize(&ScuGic,pCfg,pCfg->CpuBaseAddress);
   if(result != XST_SUCCESS){
      return result;
   }
   // self test
   result = XScuGic_SelfTest(&ScuGic);
   if(result != XST_SUCCESS){
      return result;
   }
   // Initialize the exception handler
   Xil_ExceptionInit();
   // Register the exception handler
   //print("Register the exception handler\n\r");
   Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,(Xil_ExceptionHandler)XScuGic_InterruptHandler,&ScuGic);
   //Enable the exception handler
   Xil_ExceptionEnable();
   // Connect the Adder ISR to the exception table
   //print("Connect the Adder ISR to the Exception handler table\n\r");
   result = XScuGic_Connect(&ScuGic,XPAR_FABRIC_SVM_CLASSIFIER_0_INTERRUPT_INTR,(Xil_InterruptHandler)hls_classifier_isr,&classifier);
   if(result != XST_SUCCESS){
      return result;
   }
   //print("Enable the Adder ISR\n\r");
   XScuGic_Enable(&ScuGic,XPAR_FABRIC_SVM_CLASSIFIER_0_INTERRUPT_INTR);
   return XST_SUCCESS;
}


