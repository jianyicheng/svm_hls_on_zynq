// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __svm_classifier_Loop_Sum_loop_proc1_alpha_V_6_H__
#define __svm_classifier_Loop_Sum_loop_proc1_alpha_V_6_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct svm_classifier_Loop_Sum_loop_proc1_alpha_V_6_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 13;
  static const unsigned AddressRange = 116;
  static const unsigned AddressWidth = 7;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(svm_classifier_Loop_Sum_loop_proc1_alpha_V_6_ram) {
        ram[0] = "0b1001011111110";
        ram[1] = "0b1010110011001";
        ram[2] = "0b0000010000101";
        ram[3] = "0b0000010000101";
        ram[4] = "0b1001011111110";
        ram[5] = "0b0000010000101";
        ram[6] = "0b1101111010111";
        for (unsigned i = 7; i < 22 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[22] = "0b1111101111010";
        ram[23] = "0b1111011110101";
        for (unsigned i = 24; i < 33 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[33] = "0b1111101111010";
        for (unsigned i = 34; i < 42 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[42] = "0b1111011110101";
        for (unsigned i = 43; i < 51 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[51] = "0b1001011111110";
        ram[52] = "0b1111011110101";
        ram[53] = "0b1111101111010";
        ram[54] = "0b0000010000101";
        ram[55] = "0b0000010000101";
        ram[56] = "0b0000010000101";
        ram[57] = "0b0000010000101";
        ram[58] = "0b1110001011100";
        for (unsigned i = 59; i < 67 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[67] = "0b1111101111010";
        for (unsigned i = 68; i < 79 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[79] = "0b1100010111000";
        for (unsigned i = 80; i < 88 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[88] = "0b1111101111010";
        ram[89] = "0b0000010000101";
        ram[90] = "0b0000010000101";
        ram[91] = "0b0000010000101";
        ram[92] = "0b1111011110101";
        for (unsigned i = 93; i < 100 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[100] = "0b1111001110000";
        for (unsigned i = 101; i < 107 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[107] = "0b1111101111010";
        for (unsigned i = 108; i < 116 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(svm_classifier_Loop_Sum_loop_proc1_alpha_V_6) {


static const unsigned DataWidth = 13;
static const unsigned AddressRange = 116;
static const unsigned AddressWidth = 7;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


svm_classifier_Loop_Sum_loop_proc1_alpha_V_6_ram* meminst;


SC_CTOR(svm_classifier_Loop_Sum_loop_proc1_alpha_V_6) {
meminst = new svm_classifier_Loop_Sum_loop_proc1_alpha_V_6_ram("svm_classifier_Loop_Sum_loop_proc1_alpha_V_6_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~svm_classifier_Loop_Sum_loop_proc1_alpha_V_6() {
    delete meminst;
}


};//endmodule
#endif