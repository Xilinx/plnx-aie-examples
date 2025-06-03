#!/bin/bash

XSA="$1"
SDT_OUT="sdt_output"
BOARD_DTS="$2"
SDTGEN_TCL="sdtgen.tcl"
PROCESSOR="$3"
LOP_DTS="$4"

touch ${SDTGEN_TCL}
cat > ${SDTGEN_TCL} << EOL

 for { set i 0 } { \$i < \$argc } { incr i } {
  # xsa path
  if { [lindex \$argv \$i] == "-xsa_path" } {
    incr i
    set xsa_path [lindex \$argv \$i]
  }
  # SDT path
  if { [lindex \$argv \$i] == "-sdt_path" } {
    incr i
    set sdt_path [lindex \$argv \$i]
  }
  #board dts name
  if { [lindex \$argv \$i] == "-board_dts" } {
    incr i
    set board_dts [lindex \$argv \$i]
  }
}

set_dt_param -debug enable
set_dt_param -dir \$sdt_path -zocl "enable"
set_dt_param -xsa \$xsa_path
set_dt_param -board_dts \$board_dts
generate_sdt
EOL

#create sdt_gen output
sdtgen ${SDTGEN_TCL} -xsa_path ${XSA} -sdt_path ${SDT_OUT} -board_dts ${BOARD_DTS}

#create the system.dts
export LOPPER_DTC_FLAGS="-b 0 -@"
lopper -O output/ -f --enhance ./${SDT_OUT}/system-top.dts system.dts -- xlnx_overlay_pl_dt ${PROCESSOR} full ./${SDT_OUT}/pl.dtsi

#convert dtsi to dtb
cp ./output/pl.dtsi .
dtc -O dtb -o pl.dtbo -b 0 -@ pl.dtsi
