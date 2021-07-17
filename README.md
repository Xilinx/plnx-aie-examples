# Petalinux AIE Examples

This repository contains the source code needed to recreate, modify, and extend the [Xilinx-provided Vitis embedded platforms][1]. 

[1]: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-platforms.html

To build sample AIE designs from source code in this repository, you will need to have the following tools installed and follow the [build instructions](#build-instructions):

- A Linux-based host OS supported by Vitis and PetaLinux
- [Vitis][1] 2021.2
- [PetaLinux][2] 2021.2

[1]: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis.html
[2]: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-design-tools.html

## Build Instructions

Vitis and PetaLinux tools need to be installed before building any design.

```bash
source <Vitis_install_path>/Vitis/2021.2/settings64.sh
source <PetaLinux_install_path>/settings.sh

export BASE_XSA="<Base_XSA_path>"
export PTLNX_BSP="<PetaLinux_BSP_path>"
```

- Source settings.sh in a shell session.
- Navigate in the design directory.
- Run make to,
  - Create base platform design.
  - Compile AI Engine dataflow graphs.
  - Compile application XCLBIN.
  - Recreate hardware design with application-specific connections to AI Engine.
  - Create a Petalinux project to generate boot images and SDK.
  - Cross-compile PS application.
  - Package application as part of boot images.
 
## Directory Structure

```
plnx-aie-examples/
├── designs
│   └── xgemm-gmio - GMIO based AIE GeMM application
│       ├── aie_app
│       │   ├── kernels
│       │   │   ├── config.h - user defined parameters
│       │   │   ├── one_input.cc - first AIE compute kernel within an AIE row that reads data from input stream
│       │   │   ├── one_output.cc - last AIE compute kernel within an AIE row that sends data to input stream
│       │   │   └── two_inputs.cc - subsequent compute kernels that circulate input data and output
│       │   ├── kernels.h - kernels declaration
│       │   ├── Makefile
│       │   ├── xgemm.cpp- PS main application
│       │   └── xgemm.h - dataflow graph definition
│       ├── hw
│       │   ├── system.cfg - defines connections to and from PL to AIE
│       │   └── Makefile
│       ├── images
│       │   ├── build_flow.png
│       │   ├── data_movement.png
│       │   ├── data_slicing.png
│       │   └── runtime.png
│       ├── Makefile
│       ├── ps_app_hw
│       │   └── linux
│       │       ├── Makefile
│       │       └── xrt.ini - XRT configuration file
│       ├── README
│       └── sw
│           └── Makefile
├── LICENSE-BINARIES
├── LICENSE-MIT
├── platforms
│   ├── Makefile
│   └── platform_create.tcl
└── settings.sh
```
