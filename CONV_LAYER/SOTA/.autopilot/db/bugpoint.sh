export PATH=C:/Xilinx/Vitis/2020.1/tps/win64/msys64/usr/bin;C:/Xilinx/Vitis/2020.1/tps/win64/msys64/mingw64/bin;C:/Xilinx/Vitis/2020.1/bin;C:/Xilinx/Vitis/2020.1/win64/bin;C:/Xilinx/Vitis/2020.1/win64/tools/bin;C:/Xilinx/Vivado/2020.1\gnuwin\bin;C:/Xilinx/Vivado/2020.1\gnu\microblaze\nt\bin;C:/Xilinx/Vitis/2020.1/bin;C:/Xilinx/Vitis/2020.1/lib/win64.o;C:/Xilinx/Vitis/2020.1/tps/win64/jre9.0.4/bin/server;C:/Xilinx/Vitis/2020.1/tps/win64/jre9.0.4/bin;C:\Xilinx\Vitis\2020.1\bin\..\tps\win64\msys64\mingw64\bin;C:\Xilinx\Vitis\2020.1\bin\..\tps\win64\msys64\usr\bin;C:/Xilinx/Vitis/2020.1/tps/win64/msys64/usr/bin;C:/Xilinx/Vitis/2020.1/tps/win64/msys64/mingw64/bin;C:/Xilinx/Vitis/2020.1/win64/bin;C:/Xilinx/Vitis/2020.1/win64/tools/bin;C:\Python39\Scripts\;C:\Python39\;C:\Program Files\MATLAB\R2020a\bin\matlab.exe;C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.0\bin;C:\Windows\System32;C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.0\extras\CUPTI\lib64;C:\Program Files (x86)\EShare\;C:\Program Files\PuTTY\;C:\Program Files\nodejs\;C:\ProgramData\chocolatey\bin;C:\Program Files\Git\cmd;C:\opencv\build\include;C:\opencv\build\x64\vc15\bin;C:\Xilinx\Vivado\2020.1\tps\mingw\6.2.0\win64.o\nt\bin;C:\Users\RicNid\AppData\Local\Microsoft\WindowsApps;C:\Program Files\JetBrains\PyCharm 2020.1.1\bin;;C:\Users\RicNid\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\JetBrains\CLion 2020.1.2\bin;C:\Program Files (x86)\LLVM\bin;C:\questasim64_10.6c\win64;C:\intelFPGA_lite\20.1\modelsim_ase\win32aloem;C:\Users\RicNid\AppData\Roaming\npm;C:/Xilinx/Vivado/2020.1/bin;C:/Xilinx/Vitis/2020.1\tps\mingw\6.2.0\win64.o\nt\bin;C:/Xilinx/Vitis/2020.1\tps\mingw\6.2.0\win64.o\nt\libexec\gcc\x86_64-w64-mingw32\6.2.0;C:/Xilinx/Vitis/2020.1/win64/tools/fpo_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/fft_v9_1;C:/Xilinx/Vitis/2020.1/win64/tools/fir_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/dds_v6_0;C:/Xilinx/Vitis/2020.1/win64/lib/csim;C:/Xilinx/Vitis/2020.1/win64/tools/fpo_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/fft_v9_1;C:/Xilinx/Vitis/2020.1/win64/tools/fir_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/dds_v6_0;C:/Xilinx/Vitis/2020.1/win64/lib/csim
export LD_LIBRARY_PATH=C:/Xilinx/Vitis/2020.1/win64/tools/gdb_v7_2;C:/Xilinx/Vitis/2020.1/tps/win64/dot-2.28/lib;C:/Xilinx/Vitis/2020.1/win64/bin;C:/Xilinx/Vitis/2020.1/win64/tools/gdb_v7_2;C:/Xilinx/Vitis/2020.1/tps/win64/dot-2.28/lib;C:/Xilinx/Vitis/2020.1/win64/bin;C:/Xilinx/Vitis/2020.1/win64/tools/gdb_v7_2;C:/Xilinx/Vitis/2020.1/tps/win64/dot-2.28/lib;C:/Xilinx/Vitis/2020.1/win64/bin;C:/Xilinx/Vitis/2020.1/win64/tools/fpo_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/fft_v9_1;C:/Xilinx/Vitis/2020.1/win64/tools/fir_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/dds_v6_0;C:/Xilinx/Vitis/2020.1/win64/lib/csim;C:/Xilinx/Vitis/2020.1/win64/tools/fpo_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/fft_v9_1;C:/Xilinx/Vitis/2020.1/win64/tools/fir_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/dds_v6_0;C:/Xilinx/Vitis/2020.1/win64/lib/csim;C:/Xilinx/Vitis/2020.1/win64/tools/fpo_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/fft_v9_1;C:/Xilinx/Vitis/2020.1/win64/tools/fir_v7_0;C:/Xilinx/Vitis/2020.1/win64/tools/dds_v6_0;C:/Xilinx/Vitis/2020.1/win64/lib/csim
export HDI_APPROOT=C:/Xilinx/Vitis/2020.1
export XILINX_OPENCL_CLANG=C:/Xilinx/Vitis/2020.1/win64/tools/clang
export RDI_PLATFORM=win64
bugpoint -mlimit=32000  --load libhls_support.so  --load libhls_bugpoint.so  -hls -strip  -function-uniquify -auto-function-inline -globaldce  -ptrArgReplace -mem2reg -dce  -reset-lda  -loop-simplify -indvars -aggr-aa -licm -loop-dep  -loop-bound -licm -loop-simplify -flattenloopnest  -array-flatten -gvn -instcombine -dce  -array-map -dce -func-legal  -gvn -adce -instcombine -cfgopt -simplifycfg -loop-simplify   -array-burst -promote-global-argument -dce   -array-seg-normalize  -basicaa -aggrmodref-aa -globalsmodref-aa -aggr-aa -gvn -gvn  -basicaa -aggrmodref-aa -globalsmodref-aa -aggr-aa -dse -adse -adce -licm  -inst-simplify -dce  -globaldce -instcombine -array-stream -eliminate-keepreads -instcombine  -dce   -deadargelim -doublePtrSimplify  -doublePtrElim -dce -doublePtrSimplify -promote-dbg-pointer  -dce -scalarrepl -mem2reg -disaggr -norm-name -mem2reg  -instcombine  -dse -adse -adce -ptrLegalization -dce -auto-rom-infer -array-flatten -dce -instcombine -check-doubleptr  -loop-rot -constprop -cfgopt -simplifycfg -loop-simplify -indvars -pointer-simplify -dce -loop-bound  -loop-simplify -loop-preproc  -constprop -global-constprop -gvn -mem2reg -instcombine -dce  -loop-bound  -loop-merge -dce    -bitwidthmin2 -bitwidthmin2  -deadargelim -dce  -canonicalize-dataflow -dce  -scalar-propagation -deadargelim -globaldce -mem2reg  -read-loop-dep  -interface-preproc -directive-preproc -interface-gen  -bram-byte-enable  -deadargelim -inst-simplify -dce  -gvn -mem2reg -instcombine -dce -adse  -loop-bound  -instcombine -cfgopt -simplifycfg -loop-simplify  -clean-region -io-protocol  -find-region -mem2reg  -bitop-raise -complex-op-raise -inst-simplify -inst-rectify -instcombine -adce -deadargelim  -loop-simplify -phi-opt -bitop-raise  -cfgopt -simplifycfg -strip-dead-prototypes  -interface-lower -bitop-lower -intrinsic-lower -auto-function-inline  -basicaa -aggrmodref-aa -globalsmodref-aa -aggr-aa  -inst-simplify -simplifycfg   -loop-simplify  -mergereturn -inst-simplify -inst-rectify  -dce -load-elim -bitop-lower  -loop-rewind -pointer-simplify -dce -cfgopt  -dce -loop-bound -loop-dep -read-loop-dep -dce  -check-stream -norm-name -legalize  -validate-dataflow -inst-clarity -bitwidth -dump-loop-dep-to-ir -check-all-ssdm  E:/LtrProjects/SharedProjects/HLS/CONV_LAYER/SOTA/.autopilot/db/a.o.2.bc
llvm-dis bugpoint-reduced-simplified.bc 