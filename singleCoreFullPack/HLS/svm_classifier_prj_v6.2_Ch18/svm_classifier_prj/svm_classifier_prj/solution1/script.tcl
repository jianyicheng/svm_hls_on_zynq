############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project svm_classifier_prj
set_top svm_classifier
add_files SV.h
add_files alpha.h
add_files getTanh.cpp
add_files getTanh.h
add_files svm_classifier.cpp
add_files svm_classifier.h
add_files svm_data_type.h
add_files -tb classifier.golden.out
add_files -tb classifier_test.cpp
add_files -tb testData.h
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
source "./svm_classifier_prj/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
