###############################################################################
# Copyright (C) 2019 - 2020 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

# Source settings.sh before calling make

APP = aie-matrix-multiplication

CC := aarch64-linux-gnu-gcc
CXX := aarch64-linux-gnu-g++
VPP := v++

CFLAGS += --sysroot $(SYSROOT)
CFLAGS += -D__PS_ENABLE_AIE__
CFLAGS += -DXAIE_DEBUG

.SILENT: all
all: clean compile package cross-compile

.SILENT: compile
compile: src/xgemm_graph.cpp
	aiecompiler -v --target=hw --analyze-kernels=true	\
		    --constraints=graph_aie_constraints.aiecst	\
		    --dataflow $<
.SILENT: package
package: libadf.a package.cfg
	$(VPP) -s -p -t hw --platform $(PFM_XPFM)		\
	       --package.out_dir ./ --package.defer_aie_run	\
	       --config package.cfg -o $(APP).xclbin $<

.SILENT: cross-compile
cross-compile: src/xgemm.cpp Work/ps/c_rts/aie_control_xrt.cpp
	$(CXX) $(CFLAGS) $^ -I$(AIETOOLS_ROOT)/include		\
			    -I$(SYSROOT)/usr/include		\
			    -I$(SYSROOT)/usr/include/xrt	\
			    -L$(AIETOOLS_ROOT)/lib/aarch64.o/	\
			    -L$(SYSROOT)/usr/lib		\
			    -lstdc++ -ladf_api_xrt		\
			    -lxrt_coreutil -lxrt_core		\
			    -lxaiengine				\
			    -o $(APP)

%.o: %.cpp
	$(CXX) $(CFLAGS) -I$(INCLUDEDIR) $< -o $@

.PHONY: clean
clean:
	rm -rf xnwOut
	rm -rf Work
	rm -rf *.a
	rm -rf *.xpe
	rm -rf *.log
	rm -rf $(APP) BOOT.BIN *.bif
	rm -rf _x *_summary
	rm -rf *.xclbin package package.zip
	rm -rf *.cdo.bin
