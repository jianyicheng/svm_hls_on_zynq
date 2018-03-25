

/*
 * main.c: simple test application for Core 1
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

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"
#include "svm_data_type.h"
#include "testData.h"
#include "testData_int.h"

#include <stdbool.h>
#include "xil_printf.h"
// Add BSP header files
#include <stdlib.h>  // Standard C functions, e.g. exit()
// #include <stdbool.h> // Provides a Boolean data type for ANSI/ISO-C
// #include <arm_neon.h>
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
void sw_cordic_classifier(float ip[DIMENSION], bool *op);

volatile static int data_set_ctr = 0;
volatile static u32 res_hw[TESTDATA_SET_NUM] = {0};
short *classifier_buffer = &testData_int[16*TESTDATA_SET_NUM];


int main()
{
    init_platform();

    print("\r\nCore 1 Build \n");
    	// print("Core 1 Program to test communication with HLS MACC block in PL\n\r");
    	// int data_set_ctr = 0;
    		XTime  start_time = 0;
    		XTime  end_time = 0;
    		int dt = 0;
    		XTime t = 0;
    		int i = 0;

    	   int status;

    	   //Setup the matrix mult
    	   status = hls_classifier_init(&classifier);
    	   if(status != XST_SUCCESS){
    	      print("Core 1 HLS peripheral setup failed\n\r");
    	      exit(-1);
    	   }
    	   //Setup the interrupt
    	   status = setup_interrupt();
    	   if(status != XST_SUCCESS){
    	      print("Core 1 Interrupt setup failed\n\r");
    	      exit(-1);
    	   }

    	   // Get timer offset
    	   XTime_SetTime(0);
    	   XTime_GetTime(&start_time);
    	   XTime_GetTime(&end_time);
    	   dt = end_time - start_time;
    	   /*
    	   printf("Core 1 Precalculation: \n");
    	   printf("Core 1 time test start: %llu \n", start_time);
    	   printf("Core 1 time test end : %llu \n", end_time);
    	   */
    	   // printf("Core 1 time offset : %d \n", dt);



    	   if (XSvm_classifier_IsReady(&classifier))
    	      print("Core 1 HLS peripheral is ready.  Starting... \n");
    	   else {
    	      print("!!! Core 1 HLS peripheral is not ready! Exiting...\n\r");
    	      exit(-1);
    	   }

    	   if (0) {
    		   	 print("\n\r---------------Core 1 Interrupt test-------------- \n\r");

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
    		     printf("Core 1 HW: \n");
    		     printf("Core 1 time test start: %llu \n", start_time);
    		     printf("Core 1 time test end : %llu \n", end_time);
    		     t = end_time-start_time-dt;
    		     printf("Core 1 time difference : %llu \n", t);
    		     printf("Core 1 Actual hardware time: %f ms.\n", ((float)t)*3e-6);

    	      } else {
    	    	  	  // print("\n\r---------------No interrupt test------------ \n\r");
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
    	    	  	  /*
    	    	  	  printf("Core 1 HW: \n");
    	    	  	  printf("Core 1 time test start: %llu \n", start_time);
    	    	  	  printf("Core 1 time test end : %llu \n", end_time);
    	    	  	  */
    	    	  	  t = end_time-start_time-dt;
    	    	  	  // printf("Core 1 time difference : %llu \n", t);

    	    	  	  printf("Core 1 Actual hardware time: %f ms.\n", ((float)t)*3e-6);

    	      }

    	   	   	 // quick look - deleted later
    	      	 int kk = 0;
    	         for (i = 0; i < TESTDATA_SET_NUM; i++)
    	         {
    	         	   if (res_hw[i] != (u32) testDataLabel[i+TESTDATA_SET_NUM])
    	         		   kk++;
    	         }
    	         printf("Quick look: Core 1 HW error rate: %f\n\r", ((float)kk/1000.0));

    	   // Floating point SW verification process
    	   float *sw_ip = &testData[TESTDATA_SET_NUM*16];
    	   bool res_sw[TESTDATA_SET_NUM] = {0};
    	   bool *sw_op = res_sw;
    	   XTime_SetTime(0);
    	   XTime_GetTime(&start_time);
    	   for (i = 0; i < TESTDATA_SET_NUM; i++)
    	   {
    		   sw_tanh_classifier(sw_ip, sw_op);
    		   sw_ip += 16;
    		   sw_op ++;
    	   }
    	   XTime_GetTime(&end_time);
    	   //printf("Core 1 Floating point SW: \n");
    	   //printf("Core 1 time test start: %llu \n", start_time);
    	   //printf("Core 1 time test end : %llu \n", end_time);
    	   t = end_time-start_time-dt;
    	   //printf("Core 1 time difference : %llu \n", t);
    	   printf("Core 1 software hardware time: %f s.\n", ((float)t)*3e-9);



    	   // Result correctness check
    	   int hw_error = 0;
    	   int sw_error = 0;
    	   for (i = 0; i < TESTDATA_SET_NUM; i++)
    	   {
    	   	   if (res_hw[i] != (u32) testDataLabel[TESTDATA_SET_NUM+i])
    	   		   hw_error++;
    	   	   if (res_sw[i] != (u32) testDataLabel[TESTDATA_SET_NUM+i])
    	   		   sw_error++;
    	   }
    	   // printf("HW error rate: %f\n\r", ((float)hw_error/2000.0));
    	   // printf("SW error rate: %f\n\r", ((float)sw_error/2000.0));

    	   if (hw_error == sw_error) {
    	      printf("*** Core 1 Results match: Error rate = %f ***\n\r", ((float)hw_error/10.0));
    	      status = 0;
    	   }
    	   else {
    	      printf("!!! Core 1 MISMATCH !!!\n\r Error rate = %f \n\r", ((float)hw_error/10.0));
    	      status = -1;
    	   }

    cleanup_platform();
    return 0;
}

int hls_classifier_init(XSvm_classifier *classifier_ptr)
{
	XSvm_classifier_Config *cfgPtr;
   int status;

   cfgPtr = XSvm_classifier_LookupConfig(XPAR_SVM_CLASSIFIER_1_DEVICE_ID);
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
      print("Core 1 Interrupt Configuration Lookup Failed\n\r");
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
   result = XScuGic_Connect(&ScuGic,XPAR_FABRIC_SVM_CLASSIFIER_1_INTERRUPT_INTR,(Xil_InterruptHandler)hls_classifier_isr,&classifier);
   if(result != XST_SUCCESS){
      return result;
   }
   //print("Enable the Adder ISR\n\r");
   XScuGic_Enable(&ScuGic,XPAR_FABRIC_SVM_CLASSIFIER_1_INTERRUPT_INTR);
   return XST_SUCCESS;
}


