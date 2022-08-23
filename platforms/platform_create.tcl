# © Copyright 2019 - 2022 Xilinx, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set description "A base platform targeting Versal AI Core and edge series evaluation kit, enabling designers to develop solutions using AI and DSP engines capable of delivering over 100X greater compute performance compared to current server class CPUs."

platform create -name base -desc $description -hw base.xsa -out ./ -no-boot-bsp

## Create the Linux domain
domain create -name linux -os linux -proc psv_cortexa72
domain config -generate-bif

## Create the aie domain
domain create -name aiengine -os aie_runtime -proc {ai_engine}

platform generate
