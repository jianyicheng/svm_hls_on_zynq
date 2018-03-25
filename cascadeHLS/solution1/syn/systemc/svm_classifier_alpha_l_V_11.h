// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __svm_classifier_alpha_l_V_11_H__
#define __svm_classifier_alpha_l_V_11_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct svm_classifier_alpha_l_V_11_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 13;
  static const unsigned AddressRange = 29;
  static const unsigned AddressWidth = 5;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(svm_classifier_alpha_l_V_11_ram) {
        for (unsigned i = 0; i < 7 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[7] = "0b1111101111010";
        for (unsigned i = 8; i < 15 ; i = i + 1) {
            ram[i] = "0b0000010000101";
        }
        ram[15] = "0b1111101111010";
        ram[16] = "0b0000010000101";
        ram[17] = "0b0000010000101";
        ram[18] = "0b0000010000101";
        ram[19] = "0b0000010000101";
        ram[20] = "0b1110101100110";
        ram[21] = "0b0000010000101";
        ram[22] = "0b0000010000101";
        ram[23] = "0b0000010000101";
        ram[24] = "0b0000010000101";
        ram[25] = "0b1111101111010";
        ram[26] = "0b0000010000101";
        ram[27] = "0b0000010000101";
        ram[28] = "0b0000010000101";


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


SC_MODULE(svm_classifier_alpha_l_V_11) {


static const unsigned DataWidth = 13;
static const unsigned AddressRange = 29;
static const unsigned AddressWidth = 5;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


svm_classifier_alpha_l_V_11_ram* meminst;


SC_CTOR(svm_classifier_alpha_l_V_11) {
meminst = new svm_classifier_alpha_l_V_11_ram("svm_classifier_alpha_l_V_11_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);


meminst->reset(reset);
meminst->clk(clk);
}
~svm_classifier_alpha_l_V_11() {
    delete meminst;
}


};//endmodule
#endif