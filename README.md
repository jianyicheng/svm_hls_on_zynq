# svm_hls_on_zynq

Advanced Digital System Design Coursework
Acceleration of Supporting Vector Machine (SVM) Classifcations on Zynq7000 SoC

1. Single core system (1 ARM core + 1 IP core), total execution of 5 ms for 2000 test data sets. IP core latency = 90.
2. Dual core system (2 ARM core + 2 IP core), total execution of 2.5 ms for 2000 test data sets. IP core latency = 146.
3. Cascade IP core, maximum latency 121, minimum latency 62. Average latency of 72 for 2000 test data sets.
4. Matlab SVM coefficient generation code.

Future improvements:
1. DMA & FIFO implementations to maximize transmission data rate.
2. NEON instruction to carry out SIMD processing on ARM cores.
3. Cascade precision analysis (details see report).
