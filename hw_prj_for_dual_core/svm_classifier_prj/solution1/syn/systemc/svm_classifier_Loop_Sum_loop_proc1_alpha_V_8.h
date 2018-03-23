// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __svm_classifier_Loop_Sum_loop_proc1_alpha_V_8_H__
#define __svm_classifier_Loop_Sum_loop_proc1_alpha_V_8_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct svm_classifier_Loop_Sum_loop_proc1_alpha_V_8_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 12;
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


   SC_CTOR(svm_classifier_Loop_Sum_loop_proc1_alpha_V_8_ram) {
        for (unsigned i = 0; i < 5 ; i = i + 1) {
            ram[i] = "0b000010000101";
        }
        ram[5] = "0b111101111010";
        ram[6] = "0b000010000101";
        ram[7] = "0b000010000101";
        ram[8] = "0b110001011100";
        for (unsigned i = 9; i < 14 ; i = i + 1) {
            ram[i] = "0b000010000101";
        }
        ram[14] = "0b111001110000";
        for (unsigned i = 15; i < 23 ; i = i + 1) {
            ram[i] = "0b000010000101";
        }
        ram[23] = "0b111001110000";
        ram[24] = "0b000010000101";
        ram[25] = "0b000010000101";
        ram[26] = "0b000010000101";
        ram[27] = "0b111101111010";
        ram[28] = "0b110101100110";
        for (unsigned i = 29; i < 58 ; i = i + 1) {
            ram[i] = "0b000010000101";
        }
        ram[58] = "0b111101111010";
        for (unsigned i = 59; i < 64 ; i = i + 1) {
            ram[i] = "0b000010000101";
        }
        ram[64] = "0b111011110101";
        ram[65] = "0b000010000101";
        ram[66] = "0b111011110101";
        ram[67] = "0b000010000101";
        ram[68] = "0b111101111010";
        for (unsigned i = 69; i < 76 ; i = i + 1) {
            ram[i] = "0b000010000101";
        }
        ram[76] = "0b101111010111";
        ram[77] = "0b111101111010";
        for (unsigned i = 78; i < 87 ; i = i + 1) {
            ram[i] = "0b000010000101";
        }
        ram[87] = "0b111101111010";
        ram[88] = "0b000010000101";
        ram[89] = "0b000010000101";
        ram[90] = "0b111101111010";
        for (unsigned i = 91; i < 116 ; i = i + 1) {
            ram[i] = "0b000010000101";
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


SC_MODULE(svm_classifier_Loop_Sum_loop_proc1_alpha_V_8) {


static const unsigned DataWidth = 12;
static const unsigned AddressRange = 116;
static const unsigned AddressWidth = 7;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


svm_classifier_Loop_Sum_loop_proc1_alpha_V_8_ram* meminst;


SC_CTOR(svm_classifier_Loop_Sum_loop_proc1_alpha_V_8) {
meminst = new svm_classifier_Loop_Sum_loop_proc1_alpha_V_8_ram("svm_classifier_Loop_Sum_loop_proc1_alpha_V_8_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~svm_classifier_Loop_Sum_loop_proc1_alpha_V_8() {
    delete meminst;
}


};//endmodule
#endif