#!/bin/bash

#Fix build fail cause by HOME or tmp disk not enough issue
source ./home_tmp_set.sh
#Fix vek280 part not found in 2023.1 issue
#source ./enable_beta_part.sh

export XILINXD_LICENSE_FILE=2100@aiengine-eng

source /proj/xbuilds/2023.2_daily_latest/installs/lin64/Vitis/2023.2/settings64.sh

source /proj/petalinux/2023.2/petalinux-v2023.2_daily_latest/tool/petalinux-v2023.2-final/settings.sh

export BASE_XSA=/proj/xbuilds/2023.2_daily_latest/internal_platforms/xilinx_vck190_base_202320_1/hw/hw.xsa

#export SYSROOT=/proj/xbuilds/2023.1_daily_latest/internal_platforms/sw/versal/xilinx-versal-common-v2023.1/sysroots/cortexa72-cortexa53-xilinx-linux/

#There is a petalinux minal build bug which add vdu patcket for all board that may have on vdo in part
#This issue happen after CR-1152465, and 0131 and before build is still work
export PTLNX_BSP=/proj/petalinux/2023.2/petalinux-v2023.2_stable_latest/bsp/release/xilinx-vck190-v2023.2-final.bsp

cd ../

source ./settings.sh

cd ./designs/xgemm-gmio
LINUX="linux"
#make AIEARCH=aie OS=$LINUX
make clean
make AIEARCH=aie OS=baremetal
