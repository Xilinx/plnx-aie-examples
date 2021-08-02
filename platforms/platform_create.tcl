set description "A base platform targeting VCK190 which is the first Versal AI Core series evaluation kit, enabling designers to develop solutions using AI and DSP engines capable of delivering over 100X greater compute performance compared to current server class CPUs."
platform create -name base_vck190 -desc $description -hw base.xsa -out ./ -no-boot-bsp
domain create -name linux -os linux -proc psv_cortexa72
domain config -generate-bif
platform generate
