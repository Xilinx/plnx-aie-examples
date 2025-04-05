#******************************************************************************
# Copyright (C) 2020-2022 Xilinx, Inc. All rights reserved.
# Copyright (C) 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: MIT
#******************************************************************************
import vitis
import argparse
import os

print("Platform generation")
parser = argparse.ArgumentParser()
parser.add_argument("--xsa_path", type=str, dest="xsa_path")
parser.add_argument("--platform_name", type=str, dest="platform_name")
parser.add_argument("--platform_out", type=str, dest="platform_out")

args = parser.parse_args()
xsa_path=args.xsa_path
platform_name=args.platform_name
platform_out=args.platform_out
print('args',args)


client = vitis.create_client()
client.update_workspace(path=platform_out)

advanced_options = client.create_advanced_options_dict(dt_overlay="1",dt_zocl="1")

#platform = client.create_platform_component(name = "vek280_base",hw_design = xsa_path, generate_dtb = False, advanced_options = advanced_options,architecture = "64-bit")

platform = client.create_platform_component(name = platform_name, hw_design = xsa_path, no_boot_bsp = True, generate_dtb = False,
 desc = " Update for vek385 later, A base platform targeting VCK190 which is the first Versal AI Core series evaluation kit, enabling designers to develop solutions using AI and DSP engines capable of delivering over 100X greater compute performance compared to current server class CPUs. This board includes 8GB of DDR4 UDIMM, 8GB LPDDR4 component, 400 AI engines, 1968 DSP engines, Dual-Core Arm® Cortex®-A72 and Dual-Core Cortex-R5. More information at https://www.xilinx.com/products/boards-and-kits/vck190.html" )

platform = client.get_component(name=platform_name)

#aie domain
domain = platform.add_domain(cpu = "ai_engine",os = "aie_runtime",name = "aiengine",display_name = "aiengine")
domain = platform.get_domain(name="aiengine")
#linux domain
#domain = platform.add_domain(os = "linux",cpu = "cortexa78",name = "xrt",display_name = "xrt")
#domain = platform.add_domain(cpu = "psv_cortexa72",os = "linux",name = "xrt",display_name = "xrt")
#status = domain.generate_bif()    uncomment for system.dtb/pl.dtbo

#status = domain.set_dtb(path=dtb) # used to bypass sdtgen from generate platform

status = platform.build()

