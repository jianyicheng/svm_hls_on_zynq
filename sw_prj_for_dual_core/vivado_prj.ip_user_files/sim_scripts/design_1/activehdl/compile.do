vlib work
vlib activehdl

vlib activehdl/processing_system7_bfm_v2_0_5
vlib activehdl/xil_defaultlib
vlib activehdl/lib_cdc_v1_0_2
vlib activehdl/proc_sys_reset_v5_0_9
vlib activehdl/generic_baseblocks_v2_1_0
vlib activehdl/fifo_generator_v13_1_1
vlib activehdl/axi_data_fifo_v2_1_8
vlib activehdl/axi_infrastructure_v1_1_0
vlib activehdl/axi_register_slice_v2_1_9
vlib activehdl/axi_protocol_converter_v2_1_9

vmap processing_system7_bfm_v2_0_5 activehdl/processing_system7_bfm_v2_0_5
vmap xil_defaultlib activehdl/xil_defaultlib
vmap lib_cdc_v1_0_2 activehdl/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_9 activehdl/proc_sys_reset_v5_0_9
vmap generic_baseblocks_v2_1_0 activehdl/generic_baseblocks_v2_1_0
vmap fifo_generator_v13_1_1 activehdl/fifo_generator_v13_1_1
vmap axi_data_fifo_v2_1_8 activehdl/axi_data_fifo_v2_1_8
vmap axi_infrastructure_v1_1_0 activehdl/axi_infrastructure_v1_1_0
vmap axi_register_slice_v2_1_9 activehdl/axi_register_slice_v2_1_9
vmap axi_protocol_converter_v2_1_9 activehdl/axi_protocol_converter_v2_1_9

vlog -work processing_system7_bfm_v2_0_5 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_wr.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_rd.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_wr_4.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_rd_4.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_hp2_3.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_hp0_1.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ssw_hp.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_sparse_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_reg_map.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ocm_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_intr_wr_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_intr_rd_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_fmsw_gp.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_regc.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ocmc.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_interconnect_model.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_gen_reset.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_gen_clock.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ddrc.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_axi_slave.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_axi_master.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_afi_slave.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_processing_system7_bfm.v" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_0_0_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_1_0_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_2_0_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_3_0_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_4_0_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_5_0_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_V_6_0_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_V_7_0_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_ch_sums_V_8_0_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_in_V_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_0_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_10_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_11_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_12_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_13_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_14_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_15_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_1_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_2_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_3_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_4_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_5_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_6_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_7_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_8_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/FIFO_svm_classifier_s_in_9_V_loc_channel.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_AXILiteS_s_axi.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Block_preheader_0_proc1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Block_proc.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_getTanh.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_getTanh_cosh_lut_V.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_getTanh_sinh_lut_V.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_0.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_2.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_3.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_4.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_5.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_6.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_7.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_alpha_V_8.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_0.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_2.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_3.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_4.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_5.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_6.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_7.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_Loop_Sum_loop_proc1_SVs_V_8.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_12s_8s_20_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_12s_9ns_21_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_13s_13s_26_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_13s_8s_21_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_14s_13s_27_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_15s_13s_28_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_mul_13s_15s_26_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_mul_mul_15s_13s_26_1.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_sdiv_13ns_8s_13_17.v" \
"../../../ipstatic/svm_classifier_v1_0/hdl/verilog/svm_classifier_svm_classifier_entry3.v" \
"../../../bd/design_1/ip/design_1_svm_classifier_0_0/sim/design_1_svm_classifier_0_0.v" \
"../../../bd/design_1/ip/design_1_svm_classifier_0_1/sim/design_1_svm_classifier_0_1.v" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../ipstatic/lib_cdc_v1_0/hdl/src/vhdl/cdc_sync.vhd" \

vcom -work proc_sys_reset_v5_0_9 -93 \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/upcnt_n.vhd" \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/sequence_psr.vhd" \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/lpf.vhd" \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/proc_sys_reset.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ip/design_1_rst_processing_system7_0_100M_0/sim/design_1_rst_processing_system7_0_100M_0.vhd" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../bd/design_1/ipshared/xilinx.com/xlconcat_v2_1/xlconcat.v" \
"../../../bd/design_1/ip/design_1_xlconcat_0_0/sim/design_1_xlconcat_0_0.v" \

vlog -work generic_baseblocks_v2_1_0 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_and.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_latch_and.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_latch_or.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_or.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_command_fifo.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_mask_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_mask.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel_mask_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel_mask.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_mux_enc.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_mux.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_nto1_mux.v" \

vlog -work fifo_generator_v13_1_1 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/fifo_generator_v13_1/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_1_1 -93 \
"../../../ipstatic/fifo_generator_v13_1/hdl/fifo_generator_v13_1_rfs.vhd" \

vlog -work fifo_generator_v13_1_1 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/fifo_generator_v13_1/hdl/fifo_generator_v13_1_rfs.v" \

vlog -work axi_data_fifo_v2_1_8 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axic_fifo.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_fifo_gen.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axic_srl_fifo.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axic_reg_srl_fifo.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_ndeep_srl.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axi_data_fifo.v" \

vlog -work axi_infrastructure_v1_1_0 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog/axi_infrastructure_v1_1_axi2vector.v" \
"../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog/axi_infrastructure_v1_1_axic_srl_fifo.v" \
"../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog/axi_infrastructure_v1_1_vector2axi.v" \

vlog -work axi_register_slice_v2_1_9 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_register_slice_v2_1/hdl/verilog/axi_register_slice_v2_1_axic_register_slice.v" \
"../../../ipstatic/axi_register_slice_v2_1/hdl/verilog/axi_register_slice_v2_1_axi_register_slice.v" \

vlog -work axi_protocol_converter_v2_1_9 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_a_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_axilite_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_r_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_w_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b_downsizer.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_decerr_slave.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_simple_fifo.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_wrap_cmd.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_incr_cmd.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_wr_cmd_fsm.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_rd_cmd_fsm.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_cmd_translator.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_b_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_r_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_aw_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_ar_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_axi_protocol_converter.v" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \
"../../../bd/design_1/ip/design_1_auto_pc_1/sim/design_1_auto_pc_1.v" \
"../../../bd/design_1/hdl/design_1.v" \

vlog -work xil_defaultlib "glbl.v"

