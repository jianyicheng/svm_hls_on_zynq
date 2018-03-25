############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project svm_classifier_cascade_prj
set_top svm_classifier
add_files svm_classifier_prj/SV.h
add_files svm_classifier_prj/alpha.h
add_files svm_classifier_prj/getTanh.cpp
add_files svm_classifier_prj/getTanh.h
add_files svm_classifier_prj/svm_classifier.cpp
add_files svm_classifier_prj/svm_classifier.h
add_files svm_classifier_prj/svm_data_type.h
add_files -tb svm_classifier_prj/classifier.golden.out
add_files -tb svm_classifier_prj/classifier_test.cpp
add_files -tb svm_classifier_prj/testData.h
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
#source "./svm_classifier_cascade_prj/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
