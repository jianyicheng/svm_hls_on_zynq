// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _svm_classifier_svm_classifier_entry3_HH_
#define _svm_classifier_svm_classifier_entry3_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct svm_classifier_svm_classifier_entry3 : public sc_module {
    // Port declarations 11
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_in< sc_logic > ap_continue;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_in< sc_lv<256> > in_V;
    sc_out< sc_lv<256> > in_V_out_din;
    sc_in< sc_logic > in_V_out_full_n;
    sc_out< sc_logic > in_V_out_write;


    // Module declarations
    svm_classifier_svm_classifier_entry3(sc_module_name name);
    SC_HAS_PROCESS(svm_classifier_svm_classifier_entry3);

    ~svm_classifier_svm_classifier_entry3();

    sc_trace_file* mVcdFile;

    sc_signal< sc_logic > ap_done_reg;
    sc_signal< sc_lv<1> > ap_CS_fsm;
    sc_signal< sc_logic > ap_sig_cseq_ST_st1_fsm_0;
    sc_signal< bool > ap_sig_19;
    sc_signal< sc_logic > in_V_out_blk_n;
    sc_signal< bool > ap_sig_38;
    sc_signal< sc_lv<1> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<1> ap_ST_st1_fsm_0;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<1> ap_const_lv1_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_sig_19();
    void thread_ap_sig_38();
    void thread_ap_sig_cseq_ST_st1_fsm_0();
    void thread_in_V_out_blk_n();
    void thread_in_V_out_din();
    void thread_in_V_out_write();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif