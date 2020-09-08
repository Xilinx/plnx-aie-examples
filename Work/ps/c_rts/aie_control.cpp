/************************** Constants/Macros *****************************/
#define HW_GEN                   XAIE_DEV_GEN_AIE
#define XAIE_NUM_ROWS            9
#define XAIE_NUM_COLS            50
#define XAIE_BASE_ADDR           0x20000000000
#define XAIE_COL_SHIFT           23
#define XAIE_ROW_SHIFT           18
#define XAIE_SHIM_ROW            0
#define XAIE_MEM_TILE_ROW_START  0
#define XAIE_MEM_TILE_NUM_ROWS   0
#define XAIE_AIE_TILE_ROW_START  1
#define XAIE_AIE_TILE_NUM_ROWS   8
#define CTRL_PL_OFFSET           0x20100000000
#define CTRL_IP_STRIDE           0x20000
#define FOR_WRITE                0
#define FOR_READ                 1

/***************************** Includes *********************************/
#include <adf.h>
extern "C"
{
  #include <xaiengine.h>
}

#include "drivers/aiengine/xioutils.h"
#include "adf/adf_api/AIEControlConfig.h"

XAie_InstDeclare(DevInst, &ConfigPtr);   // Declare global device instance


/************************** Functions/APIs *****************************/
  void my_graph_load_elf(const std::string& proj_path)
  {
	std::string proj_dir = (proj_path == "" ?  "." : proj_path);
	XAieLib_print("Loading elfs of graph my_graph...\n");
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 1), (proj_dir + "/Work/aie/0_0/Release/0_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 2), (proj_dir + "/Work/aie/0_1/Release/0_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 3), (proj_dir + "/Work/aie/0_2/Release/0_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 4), (proj_dir + "/Work/aie/0_3/Release/0_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 5), (proj_dir + "/Work/aie/0_4/Release/0_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 6), (proj_dir + "/Work/aie/0_5/Release/0_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 7), (proj_dir + "/Work/aie/0_6/Release/0_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(0, 8), (proj_dir + "/Work/aie/0_7/Release/0_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(0,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 1), (proj_dir + "/Work/aie/1_0/Release/1_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 2), (proj_dir + "/Work/aie/1_1/Release/1_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 3), (proj_dir + "/Work/aie/1_2/Release/1_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 4), (proj_dir + "/Work/aie/1_3/Release/1_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 5), (proj_dir + "/Work/aie/1_4/Release/1_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 6), (proj_dir + "/Work/aie/1_5/Release/1_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 7), (proj_dir + "/Work/aie/1_6/Release/1_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(1, 8), (proj_dir + "/Work/aie/1_7/Release/1_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(1,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 1), (proj_dir + "/Work/aie/2_0/Release/2_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 2), (proj_dir + "/Work/aie/2_1/Release/2_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 3), (proj_dir + "/Work/aie/2_2/Release/2_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 4), (proj_dir + "/Work/aie/2_3/Release/2_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 5), (proj_dir + "/Work/aie/2_4/Release/2_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 6), (proj_dir + "/Work/aie/2_5/Release/2_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 7), (proj_dir + "/Work/aie/2_6/Release/2_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(2, 8), (proj_dir + "/Work/aie/2_7/Release/2_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(2,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 1), (proj_dir + "/Work/aie/3_0/Release/3_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 2), (proj_dir + "/Work/aie/3_1/Release/3_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 3), (proj_dir + "/Work/aie/3_2/Release/3_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 4), (proj_dir + "/Work/aie/3_3/Release/3_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 5), (proj_dir + "/Work/aie/3_4/Release/3_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 6), (proj_dir + "/Work/aie/3_5/Release/3_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 7), (proj_dir + "/Work/aie/3_6/Release/3_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(3, 8), (proj_dir + "/Work/aie/3_7/Release/3_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(3,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 1), (proj_dir + "/Work/aie/4_0/Release/4_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 2), (proj_dir + "/Work/aie/4_1/Release/4_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 3), (proj_dir + "/Work/aie/4_2/Release/4_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 4), (proj_dir + "/Work/aie/4_3/Release/4_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 5), (proj_dir + "/Work/aie/4_4/Release/4_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 6), (proj_dir + "/Work/aie/4_5/Release/4_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 7), (proj_dir + "/Work/aie/4_6/Release/4_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(4, 8), (proj_dir + "/Work/aie/4_7/Release/4_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(4,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 1), (proj_dir + "/Work/aie/5_0/Release/5_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 2), (proj_dir + "/Work/aie/5_1/Release/5_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 3), (proj_dir + "/Work/aie/5_2/Release/5_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 4), (proj_dir + "/Work/aie/5_3/Release/5_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 5), (proj_dir + "/Work/aie/5_4/Release/5_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 6), (proj_dir + "/Work/aie/5_5/Release/5_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 7), (proj_dir + "/Work/aie/5_6/Release/5_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(5, 8), (proj_dir + "/Work/aie/5_7/Release/5_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(5,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 1), (proj_dir + "/Work/aie/6_0/Release/6_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 2), (proj_dir + "/Work/aie/6_1/Release/6_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 3), (proj_dir + "/Work/aie/6_2/Release/6_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 4), (proj_dir + "/Work/aie/6_3/Release/6_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 5), (proj_dir + "/Work/aie/6_4/Release/6_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 6), (proj_dir + "/Work/aie/6_5/Release/6_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 7), (proj_dir + "/Work/aie/6_6/Release/6_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(6, 8), (proj_dir + "/Work/aie/6_7/Release/6_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(6,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 1), (proj_dir + "/Work/aie/7_0/Release/7_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 2), (proj_dir + "/Work/aie/7_1/Release/7_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 3), (proj_dir + "/Work/aie/7_2/Release/7_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 4), (proj_dir + "/Work/aie/7_3/Release/7_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 5), (proj_dir + "/Work/aie/7_4/Release/7_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 6), (proj_dir + "/Work/aie/7_5/Release/7_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 7), (proj_dir + "/Work/aie/7_6/Release/7_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(7, 8), (proj_dir + "/Work/aie/7_7/Release/7_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(7,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 1), (proj_dir + "/Work/aie/8_0/Release/8_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 2), (proj_dir + "/Work/aie/8_1/Release/8_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 3), (proj_dir + "/Work/aie/8_2/Release/8_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 4), (proj_dir + "/Work/aie/8_3/Release/8_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 5), (proj_dir + "/Work/aie/8_4/Release/8_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 6), (proj_dir + "/Work/aie/8_5/Release/8_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 7), (proj_dir + "/Work/aie/8_6/Release/8_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(8, 8), (proj_dir + "/Work/aie/8_7/Release/8_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(8,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 1), (proj_dir + "/Work/aie/9_0/Release/9_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 2), (proj_dir + "/Work/aie/9_1/Release/9_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 3), (proj_dir + "/Work/aie/9_2/Release/9_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 4), (proj_dir + "/Work/aie/9_3/Release/9_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 5), (proj_dir + "/Work/aie/9_4/Release/9_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 6), (proj_dir + "/Work/aie/9_5/Release/9_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 7), (proj_dir + "/Work/aie/9_6/Release/9_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(9, 8), (proj_dir + "/Work/aie/9_7/Release/9_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(9,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 1), (proj_dir + "/Work/aie/10_0/Release/10_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 2), (proj_dir + "/Work/aie/10_1/Release/10_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 3), (proj_dir + "/Work/aie/10_2/Release/10_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 4), (proj_dir + "/Work/aie/10_3/Release/10_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 5), (proj_dir + "/Work/aie/10_4/Release/10_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 6), (proj_dir + "/Work/aie/10_5/Release/10_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 7), (proj_dir + "/Work/aie/10_6/Release/10_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(10, 8), (proj_dir + "/Work/aie/10_7/Release/10_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(10,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 1), (proj_dir + "/Work/aie/11_0/Release/11_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 2), (proj_dir + "/Work/aie/11_1/Release/11_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 3), (proj_dir + "/Work/aie/11_2/Release/11_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 4), (proj_dir + "/Work/aie/11_3/Release/11_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 5), (proj_dir + "/Work/aie/11_4/Release/11_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 6), (proj_dir + "/Work/aie/11_5/Release/11_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 7), (proj_dir + "/Work/aie/11_6/Release/11_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(11, 8), (proj_dir + "/Work/aie/11_7/Release/11_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(11,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 1), (proj_dir + "/Work/aie/12_0/Release/12_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 2), (proj_dir + "/Work/aie/12_1/Release/12_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 3), (proj_dir + "/Work/aie/12_2/Release/12_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 4), (proj_dir + "/Work/aie/12_3/Release/12_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 5), (proj_dir + "/Work/aie/12_4/Release/12_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 6), (proj_dir + "/Work/aie/12_5/Release/12_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 7), (proj_dir + "/Work/aie/12_6/Release/12_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(12, 8), (proj_dir + "/Work/aie/12_7/Release/12_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(12,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 1), (proj_dir + "/Work/aie/13_0/Release/13_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 2), (proj_dir + "/Work/aie/13_1/Release/13_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 3), (proj_dir + "/Work/aie/13_2/Release/13_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 4), (proj_dir + "/Work/aie/13_3/Release/13_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 5), (proj_dir + "/Work/aie/13_4/Release/13_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 6), (proj_dir + "/Work/aie/13_5/Release/13_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 7), (proj_dir + "/Work/aie/13_6/Release/13_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(13, 8), (proj_dir + "/Work/aie/13_7/Release/13_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(13,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 1), (proj_dir + "/Work/aie/14_0/Release/14_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 2), (proj_dir + "/Work/aie/14_1/Release/14_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 3), (proj_dir + "/Work/aie/14_2/Release/14_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 4), (proj_dir + "/Work/aie/14_3/Release/14_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 5), (proj_dir + "/Work/aie/14_4/Release/14_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 6), (proj_dir + "/Work/aie/14_5/Release/14_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 7), (proj_dir + "/Work/aie/14_6/Release/14_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(14, 8), (proj_dir + "/Work/aie/14_7/Release/14_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(14,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 1), (proj_dir + "/Work/aie/15_0/Release/15_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 2), (proj_dir + "/Work/aie/15_1/Release/15_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 3), (proj_dir + "/Work/aie/15_2/Release/15_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 4), (proj_dir + "/Work/aie/15_3/Release/15_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 5), (proj_dir + "/Work/aie/15_4/Release/15_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 6), (proj_dir + "/Work/aie/15_5/Release/15_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 7), (proj_dir + "/Work/aie/15_6/Release/15_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(15, 8), (proj_dir + "/Work/aie/15_7/Release/15_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(15,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 1), (proj_dir + "/Work/aie/16_0/Release/16_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 2), (proj_dir + "/Work/aie/16_1/Release/16_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 3), (proj_dir + "/Work/aie/16_2/Release/16_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 4), (proj_dir + "/Work/aie/16_3/Release/16_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 5), (proj_dir + "/Work/aie/16_4/Release/16_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 6), (proj_dir + "/Work/aie/16_5/Release/16_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 7), (proj_dir + "/Work/aie/16_6/Release/16_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(16, 8), (proj_dir + "/Work/aie/16_7/Release/16_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(16,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 1), (proj_dir + "/Work/aie/17_0/Release/17_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 2), (proj_dir + "/Work/aie/17_1/Release/17_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 3), (proj_dir + "/Work/aie/17_2/Release/17_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 4), (proj_dir + "/Work/aie/17_3/Release/17_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 5), (proj_dir + "/Work/aie/17_4/Release/17_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 6), (proj_dir + "/Work/aie/17_5/Release/17_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 7), (proj_dir + "/Work/aie/17_6/Release/17_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(17, 8), (proj_dir + "/Work/aie/17_7/Release/17_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(17,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 1), (proj_dir + "/Work/aie/18_0/Release/18_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 2), (proj_dir + "/Work/aie/18_1/Release/18_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 3), (proj_dir + "/Work/aie/18_2/Release/18_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 4), (proj_dir + "/Work/aie/18_3/Release/18_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 5), (proj_dir + "/Work/aie/18_4/Release/18_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 6), (proj_dir + "/Work/aie/18_5/Release/18_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 7), (proj_dir + "/Work/aie/18_6/Release/18_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(18, 8), (proj_dir + "/Work/aie/18_7/Release/18_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(18,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 1), (proj_dir + "/Work/aie/19_0/Release/19_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 2), (proj_dir + "/Work/aie/19_1/Release/19_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 3), (proj_dir + "/Work/aie/19_2/Release/19_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 4), (proj_dir + "/Work/aie/19_3/Release/19_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 5), (proj_dir + "/Work/aie/19_4/Release/19_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 6), (proj_dir + "/Work/aie/19_5/Release/19_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 7), (proj_dir + "/Work/aie/19_6/Release/19_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(19, 8), (proj_dir + "/Work/aie/19_7/Release/19_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(19,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 1), (proj_dir + "/Work/aie/20_0/Release/20_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 2), (proj_dir + "/Work/aie/20_1/Release/20_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 3), (proj_dir + "/Work/aie/20_2/Release/20_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 4), (proj_dir + "/Work/aie/20_3/Release/20_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 5), (proj_dir + "/Work/aie/20_4/Release/20_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 6), (proj_dir + "/Work/aie/20_5/Release/20_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 7), (proj_dir + "/Work/aie/20_6/Release/20_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(20, 8), (proj_dir + "/Work/aie/20_7/Release/20_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(20,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 1), (proj_dir + "/Work/aie/21_0/Release/21_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 2), (proj_dir + "/Work/aie/21_1/Release/21_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 3), (proj_dir + "/Work/aie/21_2/Release/21_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 4), (proj_dir + "/Work/aie/21_3/Release/21_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 5), (proj_dir + "/Work/aie/21_4/Release/21_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 6), (proj_dir + "/Work/aie/21_5/Release/21_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 7), (proj_dir + "/Work/aie/21_6/Release/21_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(21, 8), (proj_dir + "/Work/aie/21_7/Release/21_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(21,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 1), (proj_dir + "/Work/aie/22_0/Release/22_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 2), (proj_dir + "/Work/aie/22_1/Release/22_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 3), (proj_dir + "/Work/aie/22_2/Release/22_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 4), (proj_dir + "/Work/aie/22_3/Release/22_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 5), (proj_dir + "/Work/aie/22_4/Release/22_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 6), (proj_dir + "/Work/aie/22_5/Release/22_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 7), (proj_dir + "/Work/aie/22_6/Release/22_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(22, 8), (proj_dir + "/Work/aie/22_7/Release/22_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(22,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 1), (proj_dir + "/Work/aie/23_0/Release/23_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 2), (proj_dir + "/Work/aie/23_1/Release/23_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 3), (proj_dir + "/Work/aie/23_2/Release/23_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 4), (proj_dir + "/Work/aie/23_3/Release/23_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 5), (proj_dir + "/Work/aie/23_4/Release/23_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 6), (proj_dir + "/Work/aie/23_5/Release/23_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 7), (proj_dir + "/Work/aie/23_6/Release/23_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(23, 8), (proj_dir + "/Work/aie/23_7/Release/23_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(23,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 1), (proj_dir + "/Work/aie/24_0/Release/24_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 2), (proj_dir + "/Work/aie/24_1/Release/24_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 3), (proj_dir + "/Work/aie/24_2/Release/24_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 4), (proj_dir + "/Work/aie/24_3/Release/24_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 5), (proj_dir + "/Work/aie/24_4/Release/24_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 6), (proj_dir + "/Work/aie/24_5/Release/24_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 7), (proj_dir + "/Work/aie/24_6/Release/24_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(24, 8), (proj_dir + "/Work/aie/24_7/Release/24_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(24,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 1), (proj_dir + "/Work/aie/25_0/Release/25_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 2), (proj_dir + "/Work/aie/25_1/Release/25_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 3), (proj_dir + "/Work/aie/25_2/Release/25_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 4), (proj_dir + "/Work/aie/25_3/Release/25_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 5), (proj_dir + "/Work/aie/25_4/Release/25_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 6), (proj_dir + "/Work/aie/25_5/Release/25_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 7), (proj_dir + "/Work/aie/25_6/Release/25_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(25, 8), (proj_dir + "/Work/aie/25_7/Release/25_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(25,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 1), (proj_dir + "/Work/aie/26_0/Release/26_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 2), (proj_dir + "/Work/aie/26_1/Release/26_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 3), (proj_dir + "/Work/aie/26_2/Release/26_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 4), (proj_dir + "/Work/aie/26_3/Release/26_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 5), (proj_dir + "/Work/aie/26_4/Release/26_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 6), (proj_dir + "/Work/aie/26_5/Release/26_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 7), (proj_dir + "/Work/aie/26_6/Release/26_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(26, 8), (proj_dir + "/Work/aie/26_7/Release/26_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(26,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 1), (proj_dir + "/Work/aie/27_0/Release/27_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 2), (proj_dir + "/Work/aie/27_1/Release/27_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 3), (proj_dir + "/Work/aie/27_2/Release/27_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 4), (proj_dir + "/Work/aie/27_3/Release/27_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 5), (proj_dir + "/Work/aie/27_4/Release/27_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 6), (proj_dir + "/Work/aie/27_5/Release/27_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 7), (proj_dir + "/Work/aie/27_6/Release/27_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(27, 8), (proj_dir + "/Work/aie/27_7/Release/27_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(27,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 1), (proj_dir + "/Work/aie/28_0/Release/28_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 2), (proj_dir + "/Work/aie/28_1/Release/28_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 3), (proj_dir + "/Work/aie/28_2/Release/28_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 4), (proj_dir + "/Work/aie/28_3/Release/28_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 5), (proj_dir + "/Work/aie/28_4/Release/28_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 6), (proj_dir + "/Work/aie/28_5/Release/28_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 7), (proj_dir + "/Work/aie/28_6/Release/28_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(28, 8), (proj_dir + "/Work/aie/28_7/Release/28_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(28,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 1), (proj_dir + "/Work/aie/29_0/Release/29_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 2), (proj_dir + "/Work/aie/29_1/Release/29_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 3), (proj_dir + "/Work/aie/29_2/Release/29_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 4), (proj_dir + "/Work/aie/29_3/Release/29_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 5), (proj_dir + "/Work/aie/29_4/Release/29_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 6), (proj_dir + "/Work/aie/29_5/Release/29_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 7), (proj_dir + "/Work/aie/29_6/Release/29_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(29, 8), (proj_dir + "/Work/aie/29_7/Release/29_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(29,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 1), (proj_dir + "/Work/aie/30_0/Release/30_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 2), (proj_dir + "/Work/aie/30_1/Release/30_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 3), (proj_dir + "/Work/aie/30_2/Release/30_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 4), (proj_dir + "/Work/aie/30_3/Release/30_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 5), (proj_dir + "/Work/aie/30_4/Release/30_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 6), (proj_dir + "/Work/aie/30_5/Release/30_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 7), (proj_dir + "/Work/aie/30_6/Release/30_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(30, 8), (proj_dir + "/Work/aie/30_7/Release/30_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(30,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 1), (proj_dir + "/Work/aie/31_0/Release/31_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 2), (proj_dir + "/Work/aie/31_1/Release/31_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 3), (proj_dir + "/Work/aie/31_2/Release/31_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 4), (proj_dir + "/Work/aie/31_3/Release/31_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 5), (proj_dir + "/Work/aie/31_4/Release/31_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 6), (proj_dir + "/Work/aie/31_5/Release/31_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 7), (proj_dir + "/Work/aie/31_6/Release/31_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(31, 8), (proj_dir + "/Work/aie/31_7/Release/31_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(31,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 1), (proj_dir + "/Work/aie/32_0/Release/32_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 2), (proj_dir + "/Work/aie/32_1/Release/32_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 3), (proj_dir + "/Work/aie/32_2/Release/32_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 4), (proj_dir + "/Work/aie/32_3/Release/32_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 5), (proj_dir + "/Work/aie/32_4/Release/32_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 6), (proj_dir + "/Work/aie/32_5/Release/32_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 7), (proj_dir + "/Work/aie/32_6/Release/32_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(32, 8), (proj_dir + "/Work/aie/32_7/Release/32_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(32,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 1), (proj_dir + "/Work/aie/33_0/Release/33_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 2), (proj_dir + "/Work/aie/33_1/Release/33_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 3), (proj_dir + "/Work/aie/33_2/Release/33_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 4), (proj_dir + "/Work/aie/33_3/Release/33_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 5), (proj_dir + "/Work/aie/33_4/Release/33_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 6), (proj_dir + "/Work/aie/33_5/Release/33_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 7), (proj_dir + "/Work/aie/33_6/Release/33_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(33, 8), (proj_dir + "/Work/aie/33_7/Release/33_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(33,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 1), (proj_dir + "/Work/aie/34_0/Release/34_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 2), (proj_dir + "/Work/aie/34_1/Release/34_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 3), (proj_dir + "/Work/aie/34_2/Release/34_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 4), (proj_dir + "/Work/aie/34_3/Release/34_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 5), (proj_dir + "/Work/aie/34_4/Release/34_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 6), (proj_dir + "/Work/aie/34_5/Release/34_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 7), (proj_dir + "/Work/aie/34_6/Release/34_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(34, 8), (proj_dir + "/Work/aie/34_7/Release/34_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(34,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 1), (proj_dir + "/Work/aie/35_0/Release/35_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 2), (proj_dir + "/Work/aie/35_1/Release/35_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 3), (proj_dir + "/Work/aie/35_2/Release/35_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 4), (proj_dir + "/Work/aie/35_3/Release/35_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 5), (proj_dir + "/Work/aie/35_4/Release/35_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 6), (proj_dir + "/Work/aie/35_5/Release/35_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 7), (proj_dir + "/Work/aie/35_6/Release/35_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(35, 8), (proj_dir + "/Work/aie/35_7/Release/35_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(35,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 1), (proj_dir + "/Work/aie/36_0/Release/36_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 2), (proj_dir + "/Work/aie/36_1/Release/36_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 3), (proj_dir + "/Work/aie/36_2/Release/36_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 4), (proj_dir + "/Work/aie/36_3/Release/36_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 5), (proj_dir + "/Work/aie/36_4/Release/36_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 6), (proj_dir + "/Work/aie/36_5/Release/36_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 7), (proj_dir + "/Work/aie/36_6/Release/36_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(36, 8), (proj_dir + "/Work/aie/36_7/Release/36_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(36,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 1), (proj_dir + "/Work/aie/37_0/Release/37_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 2), (proj_dir + "/Work/aie/37_1/Release/37_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 3), (proj_dir + "/Work/aie/37_2/Release/37_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 4), (proj_dir + "/Work/aie/37_3/Release/37_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 5), (proj_dir + "/Work/aie/37_4/Release/37_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 6), (proj_dir + "/Work/aie/37_5/Release/37_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 7), (proj_dir + "/Work/aie/37_6/Release/37_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(37, 8), (proj_dir + "/Work/aie/37_7/Release/37_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(37,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 1), (proj_dir + "/Work/aie/38_0/Release/38_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 2), (proj_dir + "/Work/aie/38_1/Release/38_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 3), (proj_dir + "/Work/aie/38_2/Release/38_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 4), (proj_dir + "/Work/aie/38_3/Release/38_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 5), (proj_dir + "/Work/aie/38_4/Release/38_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 6), (proj_dir + "/Work/aie/38_5/Release/38_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 7), (proj_dir + "/Work/aie/38_6/Release/38_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(38, 8), (proj_dir + "/Work/aie/38_7/Release/38_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(38,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 1), (proj_dir + "/Work/aie/39_0/Release/39_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 2), (proj_dir + "/Work/aie/39_1/Release/39_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 3), (proj_dir + "/Work/aie/39_2/Release/39_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 4), (proj_dir + "/Work/aie/39_3/Release/39_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 5), (proj_dir + "/Work/aie/39_4/Release/39_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 6), (proj_dir + "/Work/aie/39_5/Release/39_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 7), (proj_dir + "/Work/aie/39_6/Release/39_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(39, 8), (proj_dir + "/Work/aie/39_7/Release/39_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(39,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 1), (proj_dir + "/Work/aie/40_0/Release/40_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 2), (proj_dir + "/Work/aie/40_1/Release/40_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 3), (proj_dir + "/Work/aie/40_2/Release/40_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 4), (proj_dir + "/Work/aie/40_3/Release/40_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 5), (proj_dir + "/Work/aie/40_4/Release/40_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 6), (proj_dir + "/Work/aie/40_5/Release/40_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 7), (proj_dir + "/Work/aie/40_6/Release/40_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(40, 8), (proj_dir + "/Work/aie/40_7/Release/40_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(40,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 1), (proj_dir + "/Work/aie/41_0/Release/41_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 2), (proj_dir + "/Work/aie/41_1/Release/41_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 3), (proj_dir + "/Work/aie/41_2/Release/41_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 4), (proj_dir + "/Work/aie/41_3/Release/41_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 5), (proj_dir + "/Work/aie/41_4/Release/41_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 6), (proj_dir + "/Work/aie/41_5/Release/41_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 7), (proj_dir + "/Work/aie/41_6/Release/41_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(41, 8), (proj_dir + "/Work/aie/41_7/Release/41_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(41,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 1), (proj_dir + "/Work/aie/42_0/Release/42_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 2), (proj_dir + "/Work/aie/42_1/Release/42_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 3), (proj_dir + "/Work/aie/42_2/Release/42_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 4), (proj_dir + "/Work/aie/42_3/Release/42_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 5), (proj_dir + "/Work/aie/42_4/Release/42_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 6), (proj_dir + "/Work/aie/42_5/Release/42_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 7), (proj_dir + "/Work/aie/42_6/Release/42_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(42, 8), (proj_dir + "/Work/aie/42_7/Release/42_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(42,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 1), (proj_dir + "/Work/aie/43_0/Release/43_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 2), (proj_dir + "/Work/aie/43_1/Release/43_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 3), (proj_dir + "/Work/aie/43_2/Release/43_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 4), (proj_dir + "/Work/aie/43_3/Release/43_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 5), (proj_dir + "/Work/aie/43_4/Release/43_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 6), (proj_dir + "/Work/aie/43_5/Release/43_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 7), (proj_dir + "/Work/aie/43_6/Release/43_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(43, 8), (proj_dir + "/Work/aie/43_7/Release/43_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(43,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 1), (proj_dir + "/Work/aie/44_0/Release/44_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 2), (proj_dir + "/Work/aie/44_1/Release/44_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 3), (proj_dir + "/Work/aie/44_2/Release/44_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 4), (proj_dir + "/Work/aie/44_3/Release/44_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 5), (proj_dir + "/Work/aie/44_4/Release/44_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 6), (proj_dir + "/Work/aie/44_5/Release/44_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 7), (proj_dir + "/Work/aie/44_6/Release/44_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(44, 8), (proj_dir + "/Work/aie/44_7/Release/44_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(44,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 1), (proj_dir + "/Work/aie/45_0/Release/45_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 2), (proj_dir + "/Work/aie/45_1/Release/45_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 3), (proj_dir + "/Work/aie/45_2/Release/45_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 4), (proj_dir + "/Work/aie/45_3/Release/45_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 5), (proj_dir + "/Work/aie/45_4/Release/45_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 6), (proj_dir + "/Work/aie/45_5/Release/45_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 7), (proj_dir + "/Work/aie/45_6/Release/45_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(45, 8), (proj_dir + "/Work/aie/45_7/Release/45_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(45,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 1), (proj_dir + "/Work/aie/46_0/Release/46_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 2), (proj_dir + "/Work/aie/46_1/Release/46_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 3), (proj_dir + "/Work/aie/46_2/Release/46_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 4), (proj_dir + "/Work/aie/46_3/Release/46_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 5), (proj_dir + "/Work/aie/46_4/Release/46_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 6), (proj_dir + "/Work/aie/46_5/Release/46_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 7), (proj_dir + "/Work/aie/46_6/Release/46_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(46, 8), (proj_dir + "/Work/aie/46_7/Release/46_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(46,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 1), (proj_dir + "/Work/aie/47_0/Release/47_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 2), (proj_dir + "/Work/aie/47_1/Release/47_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 3), (proj_dir + "/Work/aie/47_2/Release/47_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 4), (proj_dir + "/Work/aie/47_3/Release/47_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 5), (proj_dir + "/Work/aie/47_4/Release/47_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 6), (proj_dir + "/Work/aie/47_5/Release/47_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 7), (proj_dir + "/Work/aie/47_6/Release/47_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(47, 8), (proj_dir + "/Work/aie/47_7/Release/47_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(47,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 1), (proj_dir + "/Work/aie/48_0/Release/48_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 2), (proj_dir + "/Work/aie/48_1/Release/48_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 3), (proj_dir + "/Work/aie/48_2/Release/48_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 4), (proj_dir + "/Work/aie/48_3/Release/48_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 5), (proj_dir + "/Work/aie/48_4/Release/48_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 6), (proj_dir + "/Work/aie/48_5/Release/48_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 7), (proj_dir + "/Work/aie/48_6/Release/48_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(48, 8), (proj_dir + "/Work/aie/48_7/Release/48_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(48,8)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 1), (proj_dir + "/Work/aie/49_0/Release/49_0").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,1)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 2), (proj_dir + "/Work/aie/49_1/Release/49_1").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,2)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 3), (proj_dir + "/Work/aie/49_2/Release/49_2").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,3)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 4), (proj_dir + "/Work/aie/49_3/Release/49_3").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,4)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 5), (proj_dir + "/Work/aie/49_4/Release/49_4").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,5)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 6), (proj_dir + "/Work/aie/49_5/Release/49_5").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,6)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 7), (proj_dir + "/Work/aie/49_6/Release/49_6").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,7)" << std::endl;
	if(XAie_LoadElf(&DevInst, XAie_TileLoc(49, 8), (proj_dir + "/Work/aie/49_7/Release/49_7").c_str(), XAIE_ENABLE)!=XAIE_OK)
		std::cerr << "ERROR: Failed to load elf for core(49,8)" << std::endl;
  }

  void my_graph_init()
  {

	XAieLib_print("Initializing graph my_graph...\n");
    #if defined(__PS_INIT_AIE__) || defined(PS_INIT_AIE)

	// S_EAST_ch0_C0_R0 M_NORTH_ch3_C0_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 1), EAST, 0, NORTH, 3);

	// S_EAST_ch0_C0_R2 M_NORTH_ch5_C0_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 3), EAST, 0, NORTH, 5);

	// S_EAST_ch0_C0_R3 M_S2MM_DMA_ch0_C0_R3 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 4), EAST, 0, DMA, 0);

	// S_EAST_ch0_C10_R0 M_SOUTH_ch0_C10_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 1), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C10_R2 M_WEST_ch0_C10_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C11_R0 M_WEST_ch0_C11_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C11_R2 M_WEST_ch0_C11_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C12_R0 M_WEST_ch0_C12_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(12, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C12_R2 M_WEST_ch0_C12_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(12, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C13_R0 M_WEST_ch0_C13_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(13, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C13_R2 M_WEST_ch0_C13_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(13, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C14_R0 M_WEST_ch0_C14_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(14, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C14_R2 M_WEST_ch0_C14_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(14, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C15_R0 M_WEST_ch0_C15_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(15, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C15_R2 M_WEST_ch0_C15_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(15, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C16_R0 M_WEST_ch0_C16_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C16_R2 M_WEST_ch0_C16_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C17_R0 M_WEST_ch0_C17_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C18_R0 M_WEST_ch0_C18_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(18, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C19_R0 M_WEST_ch0_C19_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(19, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C1_R0 M_WEST_ch0_C1_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C1_R2 M_WEST_ch0_C1_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C20_R0 M_WEST_ch0_C20_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(20, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C21_R0 M_WEST_ch0_C21_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(21, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C22_R0 M_WEST_ch0_C22_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C22_R1 M_SOUTH_ch0_C22_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 2), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C23_R0 M_WEST_ch0_C23_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C23_R1 M_WEST_ch0_C23_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C24_R0 M_WEST_ch0_C24_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C24_R1 M_WEST_ch0_C24_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C24_R6 M_SOUTH_ch0_C24_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 7), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C25_R0 M_WEST_ch0_C25_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(25, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C25_R1 M_WEST_ch0_C25_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(25, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C26_R0 M_WEST_ch0_C26_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(26, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C26_R1 M_WEST_ch0_C26_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(26, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C27_R0 M_WEST_ch0_C27_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(27, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C27_R1 M_WEST_ch0_C27_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(27, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C28_R0 M_WEST_ch1_C28_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 1), EAST, 0, WEST, 1);

	// S_EAST_ch0_C28_R1 M_WEST_ch0_C28_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C28_R6 M_SOUTH_ch0_C28_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 7), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C29_R0 M_WEST_ch0_C29_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C29_R1 M_WEST_ch0_C29_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C2_R0 M_WEST_ch0_C2_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C2_R2 M_WEST_ch0_C2_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C30_R0 M_WEST_ch0_C30_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(30, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C30_R1 M_WEST_ch0_C30_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(30, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C31_R0 M_WEST_ch0_C31_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(31, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C31_R1 M_WEST_ch0_C31_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(31, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C32_R0 M_WEST_ch0_C32_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(32, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C32_R1 M_WEST_ch0_C32_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(32, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C33_R0 M_WEST_ch0_C33_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(33, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C33_R1 M_WEST_ch0_C33_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(33, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C34_R0 M_SOUTH_ch0_C34_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 1), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C34_R1 M_WEST_ch0_C34_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C34_R4 M_SOUTH_ch0_C34_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 5), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C35_R0 M_WEST_ch0_C35_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C35_R1 M_WEST_ch0_C35_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C36_R0 M_WEST_ch0_C36_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(36, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C36_R1 M_WEST_ch0_C36_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(36, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C37_R0 M_WEST_ch0_C37_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(37, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C37_R1 M_WEST_ch0_C37_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(37, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C38_R0 M_WEST_ch0_C38_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(38, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C38_R1 M_WEST_ch0_C38_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(38, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C39_R0 M_WEST_ch0_C39_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(39, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C39_R1 M_WEST_ch0_C39_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(39, 2), EAST, 0, WEST, 0);

	// S_EAST_ch0_C3_R0 M_WEST_ch0_C3_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C3_R2 M_WEST_ch0_C3_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C40_R0 M_WEST_ch0_C40_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C40_R4 M_SOUTH_ch0_C40_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 5), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C41_R0 M_WEST_ch0_C41_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C42_R0 M_WEST_ch0_C42_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(42, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C43_R0 M_WEST_ch0_C43_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C44_R0 M_WEST_ch0_C44_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C45_R0 M_WEST_ch0_C45_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C46_R0 M_WEST_ch0_C46_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C46_R2 M_SOUTH_ch0_C46_R2 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 3), EAST, 0, SOUTH, 0);

	// S_EAST_ch0_C47_R0 M_WEST_ch0_C47_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C48_R0 M_WEST_ch0_C48_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C4_R0 M_WEST_ch0_C4_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C4_R2 M_WEST_ch0_C4_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C5_R0 M_WEST_ch0_C5_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C5_R2 M_WEST_ch0_C5_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C6_R0 M_WEST_ch0_C6_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C6_R2 M_WEST_ch0_C6_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C7_R0 M_WEST_ch0_C7_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C7_R2 M_WEST_ch0_C7_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C8_R0 M_WEST_ch0_C8_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(8, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C8_R2 M_WEST_ch0_C8_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(8, 3), EAST, 0, WEST, 0);

	// S_EAST_ch0_C9_R0 M_WEST_ch0_C9_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(9, 1), EAST, 0, WEST, 0);

	// S_EAST_ch0_C9_R2 M_WEST_ch0_C9_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(9, 3), EAST, 0, WEST, 0);

	// S_EAST_ch1_C0_R0 M_NORTH_ch4_C0_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 1), EAST, 1, NORTH, 4);

	// S_EAST_ch1_C10_R0 M_WEST_ch0_C10_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 1), EAST, 1, WEST, 0);

	// S_EAST_ch1_C11_R0 M_WEST_ch1_C11_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C12_R0 M_WEST_ch1_C12_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(12, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C13_R0 M_WEST_ch1_C13_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(13, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C14_R0 M_WEST_ch1_C14_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(14, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C15_R0 M_WEST_ch1_C15_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(15, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C16_R0 M_WEST_ch1_C16_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C17_R0 M_WEST_ch1_C17_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C18_R0 M_WEST_ch1_C18_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(18, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C19_R0 M_WEST_ch2_C19_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(19, 1), EAST, 1, WEST, 2);

	// S_EAST_ch1_C1_R0 M_WEST_ch1_C1_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C20_R0 M_WEST_ch1_C20_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(20, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C21_R0 M_WEST_ch1_C21_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(21, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C22_R0 M_WEST_ch1_C22_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C23_R0 M_WEST_ch1_C23_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C24_R0 M_WEST_ch1_C24_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C25_R0 M_WEST_ch1_C25_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(25, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C26_R0 M_WEST_ch1_C26_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(26, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C27_R0 M_WEST_ch1_C27_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(27, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C29_R6 M_WEST_ch0_C29_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 7), EAST, 1, WEST, 0);

	// S_EAST_ch1_C2_R0 M_WEST_ch1_C2_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C30_R6 M_WEST_ch1_C30_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(30, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C31_R6 M_WEST_ch1_C31_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(31, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C32_R6 M_WEST_ch1_C32_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(32, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C33_R6 M_WEST_ch1_C33_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(33, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C34_R6 M_WEST_ch1_C34_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C35_R6 M_WEST_ch1_C35_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C36_R6 M_WEST_ch1_C36_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(36, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C37_R6 M_WEST_ch1_C37_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(37, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C38_R6 M_WEST_ch1_C38_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(38, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C39_R6 M_WEST_ch1_C39_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(39, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C3_R0 M_WEST_ch1_C3_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C40_R6 M_WEST_ch1_C40_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C41_R4 M_WEST_ch0_C41_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 5), EAST, 1, WEST, 0);

	// S_EAST_ch1_C41_R6 M_WEST_ch1_C41_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C42_R4 M_WEST_ch1_C42_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(42, 5), EAST, 1, WEST, 1);

	// S_EAST_ch1_C42_R6 M_WEST_ch1_C42_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(42, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C43_R4 M_WEST_ch1_C43_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 5), EAST, 1, WEST, 1);

	// S_EAST_ch1_C43_R6 M_WEST_ch1_C43_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C44_R4 M_WEST_ch1_C44_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 5), EAST, 1, WEST, 1);

	// S_EAST_ch1_C44_R6 M_WEST_ch1_C44_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C45_R4 M_WEST_ch1_C45_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 5), EAST, 1, WEST, 1);

	// S_EAST_ch1_C45_R6 M_WEST_ch1_C45_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C46_R4 M_WEST_ch1_C46_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 5), EAST, 1, WEST, 1);

	// S_EAST_ch1_C46_R6 M_WEST_ch1_C46_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C47_R4 M_WEST_ch1_C47_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 5), EAST, 1, WEST, 1);

	// S_EAST_ch1_C47_R6 M_WEST_ch1_C47_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C48_R4 M_WEST_ch1_C48_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 5), EAST, 1, WEST, 1);

	// S_EAST_ch1_C48_R6 M_WEST_ch1_C48_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 7), EAST, 1, WEST, 1);

	// S_EAST_ch1_C4_R0 M_WEST_ch1_C4_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C5_R0 M_WEST_ch1_C5_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C6_R0 M_WEST_ch1_C6_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C7_R0 M_WEST_ch1_C7_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C8_R0 M_WEST_ch1_C8_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(8, 1), EAST, 1, WEST, 1);

	// S_EAST_ch1_C9_R0 M_WEST_ch1_C9_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(9, 1), EAST, 1, WEST, 1);

	// S_EAST_ch2_C10_R0 M_WEST_ch1_C10_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 1), EAST, 2, WEST, 1);

	// S_EAST_ch2_C11_R0 M_WEST_ch2_C11_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C12_R0 M_WEST_ch2_C12_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(12, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C13_R0 M_WEST_ch2_C13_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(13, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C14_R0 M_WEST_ch2_C14_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(14, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C15_R0 M_WEST_ch2_C15_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(15, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C16_R0 M_SOUTH_ch0_C16_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 1), EAST, 2, SOUTH, 0);

	// S_EAST_ch2_C17_R0 M_WEST_ch2_C17_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C18_R0 M_WEST_ch2_C18_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(18, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C19_R0 M_WEST_ch3_C19_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(19, 1), EAST, 2, WEST, 3);

	// S_EAST_ch2_C1_R0 M_NORTH_ch0_C1_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 1), EAST, 2, NORTH, 0);

	// S_EAST_ch2_C20_R0 M_WEST_ch2_C20_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(20, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C21_R0 M_WEST_ch2_C21_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(21, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C22_R0 M_WEST_ch2_C22_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C23_R0 M_WEST_ch2_C23_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C25_R6 M_WEST_ch0_C25_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(25, 7), EAST, 2, WEST, 0);

	// S_EAST_ch2_C26_R6 M_WEST_ch2_C26_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(26, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C27_R6 M_WEST_ch2_C27_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(27, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C28_R6 M_WEST_ch2_C28_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C29_R6 M_WEST_ch2_C29_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C2_R0 M_WEST_ch2_C2_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C30_R6 M_WEST_ch2_C30_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(30, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C31_R6 M_WEST_ch2_C31_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(31, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C32_R6 M_WEST_ch2_C32_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(32, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C33_R6 M_WEST_ch2_C33_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(33, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C34_R6 M_WEST_ch2_C34_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C35_R4 M_WEST_ch0_C35_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 5), EAST, 2, WEST, 0);

	// S_EAST_ch2_C35_R6 M_WEST_ch2_C35_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C36_R4 M_WEST_ch2_C36_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(36, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C36_R6 M_WEST_ch2_C36_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(36, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C37_R4 M_WEST_ch2_C37_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(37, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C37_R6 M_WEST_ch2_C37_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(37, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C38_R4 M_WEST_ch2_C38_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(38, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C38_R6 M_WEST_ch2_C38_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(38, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C39_R4 M_WEST_ch2_C39_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(39, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C39_R6 M_WEST_ch2_C39_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(39, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C3_R0 M_WEST_ch2_C3_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C40_R4 M_WEST_ch2_C40_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C40_R6 M_WEST_ch2_C40_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C41_R4 M_WEST_ch2_C41_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C41_R6 M_WEST_ch2_C41_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C42_R4 M_WEST_ch2_C42_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(42, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C42_R6 M_WEST_ch2_C42_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(42, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C43_R4 M_WEST_ch2_C43_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C43_R6 M_WEST_ch2_C43_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C44_R4 M_WEST_ch2_C44_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C44_R6 M_WEST_ch2_C44_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C45_R4 M_WEST_ch2_C45_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C45_R6 M_WEST_ch2_C45_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C46_R4 M_WEST_ch2_C46_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C46_R6 M_WEST_ch2_C46_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C47_R2 M_WEST_ch0_C47_R2 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 3), EAST, 2, WEST, 0);

	// S_EAST_ch2_C47_R4 M_WEST_ch2_C47_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C47_R6 M_WEST_ch2_C47_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C48_R2 M_WEST_ch2_C48_R2 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 3), EAST, 2, WEST, 2);

	// S_EAST_ch2_C48_R4 M_WEST_ch2_C48_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 5), EAST, 2, WEST, 2);

	// S_EAST_ch2_C48_R6 M_WEST_ch2_C48_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 7), EAST, 2, WEST, 2);

	// S_EAST_ch2_C4_R0 M_WEST_ch2_C4_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C5_R0 M_WEST_ch2_C5_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C6_R0 M_WEST_ch2_C6_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C7_R0 M_WEST_ch2_C7_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C8_R0 M_WEST_ch2_C8_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(8, 1), EAST, 2, WEST, 2);

	// S_EAST_ch2_C9_R0 M_WEST_ch2_C9_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(9, 1), EAST, 2, WEST, 2);

	// S_EAST_ch3_C10_R0 M_WEST_ch2_C10_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 1), EAST, 3, WEST, 2);

	// S_EAST_ch3_C16_R0 M_WEST_ch2_C16_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 1), EAST, 3, WEST, 2);

	// S_EAST_ch3_C17_R0 M_WEST_ch3_C17_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C18_R0 M_WEST_ch3_C18_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(18, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C19_R0 M_WEST_ch1_C19_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(19, 1), EAST, 3, WEST, 1);

	// S_EAST_ch3_C20_R0 M_WEST_ch3_C20_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(20, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C21_R0 M_WEST_ch3_C21_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(21, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C22_R0 M_WEST_ch3_C22_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C23_R0 M_WEST_ch3_C23_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C24_R0 M_WEST_ch2_C24_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 1), EAST, 3, WEST, 2);

	// S_EAST_ch3_C25_R0 M_WEST_ch3_C25_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(25, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C26_R0 M_WEST_ch3_C26_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(26, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C27_R0 M_WEST_ch3_C27_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(27, 1), EAST, 3, WEST, 3);

	// S_EAST_ch3_C28_R0 M_WEST_ch3_C28_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 1), EAST, 3, WEST, 3);

	// S_MM2S_DMA_ch0_C49_R0 M_SOUTH_ch0_C49_R0 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 1), DMA, 0, SOUTH, 0);

	// S_MM2S_DMA_ch0_C49_R2 M_SOUTH_ch1_C49_R2 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 3), DMA, 0, SOUTH, 1);

	// S_MM2S_DMA_ch0_C49_R4 M_WEST_ch1_C49_R4 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 5), DMA, 0, WEST, 1);

	// S_MM2S_DMA_ch0_C49_R6 M_WEST_ch1_C49_R6 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 7), DMA, 0, WEST, 1);

	// S_MM2S_DMA_ch1_C49_R0 M_SOUTH_ch1_C49_R0 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 1), DMA, 1, SOUTH, 1);

	// S_MM2S_DMA_ch1_C49_R2 M_WEST_ch2_C49_R2 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 3), DMA, 1, WEST, 2);

	// S_MM2S_DMA_ch1_C49_R4 M_WEST_ch2_C49_R4 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 5), DMA, 1, WEST, 2);

	// S_MM2S_DMA_ch1_C49_R6 M_WEST_ch2_C49_R6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 7), DMA, 1, WEST, 2);

	// S_NORTH_ch0_C22_R0 M_SOUTH_ch0_C22_R0 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 1), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C24_R0 M_SOUTH_ch0_C24_R0 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 1), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C24_R1 M_SOUTH_ch0_C24_R1 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 2), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C24_R2 M_SOUTH_ch0_C24_R2 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 3), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C24_R3 M_SOUTH_ch0_C24_R3 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 4), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C24_R4 M_SOUTH_ch0_C24_R4 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 5), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C24_R5 M_SOUTH_ch0_C24_R5 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 6), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C28_R0 M_WEST_ch0_C28_R0 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 1), NORTH, 0, WEST, 0);

	// S_NORTH_ch0_C28_R1 M_SOUTH_ch0_C28_R1 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 2), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C28_R2 M_SOUTH_ch0_C28_R2 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 3), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C28_R3 M_SOUTH_ch0_C28_R3 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 4), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C28_R4 M_SOUTH_ch0_C28_R4 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 5), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C28_R5 M_SOUTH_ch0_C28_R5 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 6), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C34_R0 M_WEST_ch0_C34_R0 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 1), NORTH, 0, WEST, 0);

	// S_NORTH_ch0_C34_R1 M_SOUTH_ch0_C34_R1 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 2), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C34_R2 M_SOUTH_ch0_C34_R2 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 3), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C34_R3 M_SOUTH_ch0_C34_R3 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 4), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C40_R1 M_WEST_ch0_C40_R1 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 2), NORTH, 0, WEST, 0);

	// S_NORTH_ch0_C40_R2 M_SOUTH_ch0_C40_R2 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 3), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C40_R3 M_SOUTH_ch0_C40_R3 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 4), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C46_R0 M_SOUTH_ch0_C46_R0 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 1), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch0_C46_R1 M_SOUTH_ch0_C46_R1 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 2), NORTH, 0, SOUTH, 0);

	// S_NORTH_ch1_C49_R0 M_WEST_ch0_C49_R0 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 1), NORTH, 1, WEST, 0);

	// S_NORTH_ch1_C49_R1 M_SOUTH_ch1_C49_R1 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 2), NORTH, 1, SOUTH, 1);

	// S_SHIM_EAST_ch0_C0 M_SHIM_NORTH_ch0_C0 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 0), EAST, 0, NORTH, 0);

	// S_SHIM_EAST_ch0_C1 M_SHIM_WEST_ch0_C1 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C17 M_SHIM_WEST_ch1_C17 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 0), EAST, 0, WEST, 1);

	// S_SHIM_EAST_ch0_C18 M_SHIM_WEST_ch0_C18 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(18, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C19 M_SHIM_WEST_ch0_C19 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(19, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C2 M_SHIM_WEST_ch0_C2 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C20 M_SHIM_WEST_ch0_C20 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(20, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C21 M_SHIM_WEST_ch0_C21 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(21, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C22 M_SHIM_WEST_ch0_C22 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C3 M_SHIM_WEST_ch0_C3 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C4 M_SHIM_WEST_ch0_C4 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C40 M_SHIM_SOUTH_ch0_C40 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 0), EAST, 0, SOUTH, 0);

	// S_SHIM_EAST_ch0_C41 M_SHIM_WEST_ch0_C41 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C42 M_SHIM_WEST_ch0_C42 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(42, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C43 M_SHIM_WEST_ch0_C43 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C44 M_SHIM_WEST_ch0_C44 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C45 M_SHIM_WEST_ch0_C45 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C46 M_SHIM_WEST_ch0_C46 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C47 M_SHIM_WEST_ch0_C47 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C48 M_SHIM_WEST_ch0_C48 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C5 M_SHIM_WEST_ch0_C5 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch0_C6 M_SHIM_WEST_ch0_C6 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 0), EAST, 0, WEST, 0);

	// S_SHIM_EAST_ch1_C0 M_SHIM_NORTH_ch1_C0 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 0), EAST, 1, NORTH, 1);

	// S_SHIM_EAST_ch1_C1 M_SHIM_WEST_ch1_C1 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C10 M_SHIM_WEST_ch3_C10 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 0), EAST, 1, WEST, 3);

	// S_SHIM_EAST_ch1_C11 M_SHIM_WEST_ch1_C11 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C12 M_SHIM_WEST_ch1_C12 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(12, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C13 M_SHIM_WEST_ch1_C13 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(13, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C14 M_SHIM_WEST_ch1_C14 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(14, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C15 M_SHIM_WEST_ch1_C15 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(15, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C16 M_SHIM_WEST_ch1_C16 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C17 M_SHIM_WEST_ch2_C17 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 0), EAST, 1, WEST, 2);

	// S_SHIM_EAST_ch1_C18 M_SHIM_WEST_ch1_C18 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(18, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C19 M_SHIM_WEST_ch1_C19 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(19, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C2 M_SHIM_WEST_ch1_C2 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C20 M_SHIM_WEST_ch1_C20 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(20, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C21 M_SHIM_WEST_ch1_C21 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(21, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C22 M_SHIM_WEST_ch1_C22 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C23 M_SHIM_WEST_ch1_C23 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C24 M_SHIM_NORTH_ch5_C24 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 0), EAST, 1, NORTH, 5);

	// S_SHIM_EAST_ch1_C25 M_SHIM_WEST_ch1_C25 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(25, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C26 M_SHIM_WEST_ch1_C26 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(26, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C27 M_SHIM_WEST_ch1_C27 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(27, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C28 M_SHIM_WEST_ch1_C28 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C29 M_SHIM_WEST_ch1_C29 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C3 M_SHIM_WEST_ch1_C3 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C30 M_SHIM_WEST_ch1_C30 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(30, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C31 M_SHIM_WEST_ch1_C31 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(31, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C32 M_SHIM_WEST_ch1_C32 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(32, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C33 M_SHIM_WEST_ch1_C33 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(33, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C34 M_SHIM_WEST_ch1_C34 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C35 M_SHIM_WEST_ch3_C35 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 0), EAST, 1, WEST, 3);

	// S_SHIM_EAST_ch1_C36 M_SHIM_WEST_ch1_C36 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(36, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C37 M_SHIM_WEST_ch1_C37 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(37, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C38 M_SHIM_WEST_ch1_C38 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(38, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C39 M_SHIM_WEST_ch1_C39 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(39, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C4 M_SHIM_WEST_ch1_C4 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C40 M_SHIM_WEST_ch1_C40 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C41 M_SHIM_WEST_ch1_C41 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C42 M_SHIM_WEST_ch1_C42 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(42, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C43 M_SHIM_SOUTH_ch0_C43 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 0), EAST, 1, SOUTH, 0);

	// S_SHIM_EAST_ch1_C44 M_SHIM_WEST_ch1_C44 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C45 M_SHIM_WEST_ch1_C45 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C46 M_SHIM_WEST_ch1_C46 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C47 M_SHIM_WEST_ch1_C47 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(47, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C48 M_SHIM_WEST_ch1_C48 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(48, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C5 M_SHIM_WEST_ch1_C5 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C6 M_SHIM_SOUTH_ch5_C6 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 0), EAST, 1, SOUTH, 5);

	// S_SHIM_EAST_ch1_C7 M_SHIM_WEST_ch1_C7 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C8 M_SHIM_WEST_ch1_C8 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(8, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch1_C9 M_SHIM_WEST_ch1_C9 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(9, 0), EAST, 1, WEST, 1);

	// S_SHIM_EAST_ch2_C0 M_SHIM_NORTH_ch2_C0 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 0), EAST, 2, NORTH, 2);

	// S_SHIM_EAST_ch2_C1 M_SHIM_WEST_ch2_C1 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C10 M_SHIM_WEST_ch1_C10 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 0), EAST, 2, WEST, 1);

	// S_SHIM_EAST_ch2_C11 M_SHIM_WEST_ch2_C11 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C12 M_SHIM_WEST_ch2_C12 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(12, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C13 M_SHIM_WEST_ch2_C13 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(13, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C14 M_SHIM_WEST_ch2_C14 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(14, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C15 M_SHIM_WEST_ch2_C15 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(15, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C16 M_SHIM_WEST_ch2_C16 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C17 M_SHIM_WEST_ch3_C17 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 0), EAST, 2, WEST, 3);

	// S_SHIM_EAST_ch2_C18 M_SHIM_WEST_ch2_C18 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(18, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C19 M_SHIM_WEST_ch2_C19 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(19, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C2 M_SHIM_WEST_ch2_C2 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C20 M_SHIM_WEST_ch2_C20 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(20, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C21 M_SHIM_WEST_ch2_C21 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(21, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C22 M_SHIM_WEST_ch2_C22 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C23 M_SHIM_WEST_ch2_C23 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C24 M_SHIM_WEST_ch2_C24 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C25 M_SHIM_WEST_ch2_C25 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(25, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C26 M_SHIM_WEST_ch2_C26 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(26, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C27 M_SHIM_WEST_ch2_C27 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(27, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C28 M_SHIM_WEST_ch2_C28 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C29 M_SHIM_WEST_ch2_C29 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C3 M_SHIM_WEST_ch2_C3 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C30 M_SHIM_WEST_ch2_C30 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(30, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C31 M_SHIM_WEST_ch2_C31 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(31, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C32 M_SHIM_WEST_ch2_C32 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(32, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C33 M_SHIM_WEST_ch2_C33 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(33, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C34 M_SHIM_WEST_ch2_C34 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C35 M_SHIM_WEST_ch2_C35 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C36 M_SHIM_WEST_ch2_C36 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(36, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C37 M_SHIM_WEST_ch2_C37 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(37, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C38 M_SHIM_WEST_ch2_C38 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(38, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C39 M_SHIM_WEST_ch2_C39 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(39, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C4 M_SHIM_WEST_ch2_C4 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C40 M_SHIM_WEST_ch2_C40 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(40, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C43 M_SHIM_WEST_ch1_C43 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(43, 0), EAST, 2, WEST, 1);

	// S_SHIM_EAST_ch2_C44 M_SHIM_WEST_ch2_C44 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(44, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C45 M_SHIM_WEST_ch2_C45 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(45, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C5 M_SHIM_WEST_ch2_C5 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C6 M_SHIM_WEST_ch2_C6 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C7 M_SHIM_WEST_ch2_C7 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C8 M_SHIM_WEST_ch2_C8 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(8, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch2_C9 M_SHIM_WEST_ch2_C9 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(9, 0), EAST, 2, WEST, 2);

	// S_SHIM_EAST_ch3_C0 M_SHIM_NORTH_ch3_C0 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 0), EAST, 3, NORTH, 3);

	// S_SHIM_EAST_ch3_C1 M_SHIM_WEST_ch3_C1 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C10 M_SHIM_WEST_ch2_C10 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 0), EAST, 3, WEST, 2);

	// S_SHIM_EAST_ch3_C11 M_SHIM_WEST_ch3_C11 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C12 M_SHIM_WEST_ch3_C12 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(12, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C13 M_SHIM_WEST_ch3_C13 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(13, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C14 M_SHIM_WEST_ch3_C14 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(14, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C15 M_SHIM_WEST_ch3_C15 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(15, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C16 M_SHIM_WEST_ch3_C16 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C2 M_SHIM_WEST_ch3_C2 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(2, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C28 M_SHIM_SOUTH_ch0_C28 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(28, 0), EAST, 3, SOUTH, 0);

	// S_SHIM_EAST_ch3_C29 M_SHIM_WEST_ch3_C29 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C3 M_SHIM_WEST_ch3_C3 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(3, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C30 M_SHIM_WEST_ch3_C30 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(30, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C31 M_SHIM_WEST_ch3_C31 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(31, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C32 M_SHIM_WEST_ch3_C32 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(32, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C33 M_SHIM_WEST_ch3_C33 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(33, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C34 M_SHIM_WEST_ch3_C34 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C4 M_SHIM_WEST_ch3_C4 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(4, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C5 M_SHIM_WEST_ch3_C5 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(5, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C6 M_SHIM_WEST_ch3_C6 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C7 M_SHIM_WEST_ch3_C7 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C8 M_SHIM_WEST_ch3_C8 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(8, 0), EAST, 3, WEST, 3);

	// S_SHIM_EAST_ch3_C9 M_SHIM_WEST_ch3_C9 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(9, 0), EAST, 3, WEST, 3);

	// S_SHIM_NORTH_ch0_C10 M_SHIM_SOUTH_ch0_C10 net699

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(10, 0), NORTH, 0, SOUTH, 0);

	// S_SHIM_NORTH_ch0_C16 M_SHIM_SOUTH_ch0_C16 net599

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(16, 0), NORTH, 0, SOUTH, 0);

	// S_SHIM_NORTH_ch0_C22 M_SHIM_SOUTH_ch0_C22 net499

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(22, 0), NORTH, 0, SOUTH, 0);

	// S_SHIM_NORTH_ch0_C24 M_SHIM_WEST_ch1_C24 net799

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 0), NORTH, 0, WEST, 1);

	// S_SHIM_NORTH_ch0_C34 M_SHIM_SOUTH_ch0_C34 net299

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(34, 0), NORTH, 0, SOUTH, 0);

	// S_SHIM_NORTH_ch0_C46 M_SHIM_WEST_ch2_C46 net399

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(46, 0), NORTH, 0, WEST, 2);

	// S_SHIM_NORTH_ch0_C49 M_SHIM_WEST_ch0_C49 net199

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 0), NORTH, 0, WEST, 0);

	// S_SHIM_NORTH_ch1_C49 M_SHIM_WEST_ch1_C49 net99

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(49, 0), NORTH, 1, WEST, 1);

	// S_SHIM_SOUTH_ch0_C11 M_SHIM_NORTH_ch0_C11 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 0), SOUTH, 0, NORTH, 0);

	// S_SHIM_SOUTH_ch0_C17 M_SHIM_NORTH_ch0_C17 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 0), SOUTH, 0, NORTH, 0);

	// S_SHIM_SOUTH_ch0_C23 M_SHIM_WEST_ch0_C23 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(23, 0), SOUTH, 0, WEST, 0);

	// S_SHIM_SOUTH_ch0_C29 M_SHIM_NORTH_ch5_C29 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 0), SOUTH, 0, NORTH, 5);

	// S_SHIM_SOUTH_ch0_C35 M_SHIM_WEST_ch1_C35 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(35, 0), SOUTH, 0, WEST, 1);

	// S_SHIM_SOUTH_ch0_C41 M_SHIM_WEST_ch2_C41 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(41, 0), SOUTH, 0, WEST, 2);

	// S_SHIM_SOUTH_ch0_C6 M_SHIM_WEST_ch1_C6 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(6, 0), SOUTH, 0, WEST, 1);

	// S_SHIM_SOUTH_ch0_C7 M_SHIM_WEST_ch0_C7 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(7, 0), SOUTH, 0, WEST, 0);

	// S_SOUTH_ch0_C0_R0 M_NORTH_ch0_C0_R0 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 1), SOUTH, 0, NORTH, 0);

	// S_SOUTH_ch0_C0_R1 M_S2MM_DMA_ch1_C0_R1 net100

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 2), SOUTH, 0, DMA, 1);

	// S_SOUTH_ch0_C11_R0 M_WEST_ch3_C11_R0 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(11, 1), SOUTH, 0, WEST, 3);

	// S_SOUTH_ch0_C17_R0 M_NORTH_ch0_C17_R0 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 1), SOUTH, 0, NORTH, 0);

	// S_SOUTH_ch0_C17_R1 M_NORTH_ch0_C17_R1 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 2), SOUTH, 0, NORTH, 0);

	// S_SOUTH_ch0_C17_R2 M_WEST_ch0_C17_R2 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(17, 3), SOUTH, 0, WEST, 0);

	// S_SOUTH_ch0_C1_R1 M_NORTH_ch0_C1_R1 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 2), SOUTH, 0, NORTH, 0);

	// S_SOUTH_ch0_C1_R2 M_NORTH_ch0_C1_R2 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 3), SOUTH, 0, NORTH, 0);

	// S_SOUTH_ch0_C1_R3 M_WEST_ch0_C1_R3 net200

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(1, 4), SOUTH, 0, WEST, 0);

	// S_SOUTH_ch1_C0_R0 M_NORTH_ch1_C0_R0 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 1), SOUTH, 1, NORTH, 1);

	// S_SOUTH_ch1_C0_R1 M_S2MM_DMA_ch0_C0_R1 net0

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 2), SOUTH, 1, DMA, 0);

	// S_SOUTH_ch1_C0_R2 M_NORTH_ch1_C0_R2 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 3), SOUTH, 1, NORTH, 1);

	// S_SOUTH_ch1_C0_R3 M_NORTH_ch1_C0_R3 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 4), SOUTH, 1, NORTH, 1);

	// S_SOUTH_ch1_C0_R4 M_NORTH_ch1_C0_R4 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 5), SOUTH, 1, NORTH, 1);

	// S_SOUTH_ch1_C0_R5 M_NORTH_ch1_C0_R5 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 6), SOUTH, 1, NORTH, 1);

	// S_SOUTH_ch1_C0_R6 M_NORTH_ch1_C0_R6 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 7), SOUTH, 1, NORTH, 1);

	// S_SOUTH_ch1_C0_R7 M_S2MM_DMA_ch1_C0_R7 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 8), SOUTH, 1, DMA, 1);

	// S_SOUTH_ch2_C0_R0 M_NORTH_ch2_C0_R0 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 1), SOUTH, 2, NORTH, 2);

	// S_SOUTH_ch2_C0_R1 M_NORTH_ch1_C0_R1 net700

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 2), SOUTH, 2, NORTH, 1);

	// S_SOUTH_ch2_C0_R2 M_NORTH_ch2_C0_R2 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 3), SOUTH, 2, NORTH, 2);

	// S_SOUTH_ch2_C0_R3 M_NORTH_ch2_C0_R3 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 4), SOUTH, 2, NORTH, 2);

	// S_SOUTH_ch2_C0_R4 M_NORTH_ch2_C0_R4 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 5), SOUTH, 2, NORTH, 2);

	// S_SOUTH_ch2_C0_R5 M_NORTH_ch2_C0_R5 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 6), SOUTH, 2, NORTH, 2);

	// S_SOUTH_ch2_C0_R6 M_NORTH_ch2_C0_R6 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 7), SOUTH, 2, NORTH, 2);

	// S_SOUTH_ch2_C0_R7 M_S2MM_DMA_ch0_C0_R7 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 8), SOUTH, 2, DMA, 0);

	// S_SOUTH_ch3_C0_R0 M_NORTH_ch5_C0_R0 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 1), SOUTH, 3, NORTH, 5);

	// S_SOUTH_ch3_C0_R1 M_NORTH_ch2_C0_R1 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 2), SOUTH, 3, NORTH, 2);

	// S_SOUTH_ch3_C0_R2 M_NORTH_ch3_C0_R2 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 3), SOUTH, 3, NORTH, 3);

	// S_SOUTH_ch3_C0_R3 M_NORTH_ch3_C0_R3 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 4), SOUTH, 3, NORTH, 3);

	// S_SOUTH_ch3_C0_R4 M_NORTH_ch3_C0_R4 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 5), SOUTH, 3, NORTH, 3);

	// S_SOUTH_ch3_C0_R5 M_S2MM_DMA_ch1_C0_R5 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 6), SOUTH, 3, DMA, 1);

	// S_SOUTH_ch4_C0_R1 M_NORTH_ch3_C0_R1 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 2), SOUTH, 4, NORTH, 3);

	// S_SOUTH_ch4_C0_R2 M_NORTH_ch4_C0_R2 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 3), SOUTH, 4, NORTH, 4);

	// S_SOUTH_ch4_C0_R3 M_NORTH_ch4_C0_R3 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 4), SOUTH, 4, NORTH, 4);

	// S_SOUTH_ch4_C0_R4 M_NORTH_ch4_C0_R4 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 5), SOUTH, 4, NORTH, 4);

	// S_SOUTH_ch4_C0_R5 M_S2MM_DMA_ch0_C0_R5 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 6), SOUTH, 4, DMA, 0);

	// S_SOUTH_ch5_C0_R1 M_NORTH_ch4_C0_R1 net400

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 2), SOUTH, 5, NORTH, 4);

	// S_SOUTH_ch5_C0_R3 M_S2MM_DMA_ch1_C0_R3 net300

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(0, 4), SOUTH, 5, DMA, 1);

	// S_SOUTH_ch5_C24_R0 M_WEST_ch3_C24_R0 net600

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(24, 1), SOUTH, 5, WEST, 3);

	// S_SOUTH_ch5_C29_R0 M_WEST_ch3_C29_R0 net500

	XAie_StrmConnCctEnable(&DevInst, XAie_TileLoc(29, 1), SOUTH, 5, WEST, 3);


	XAieLib_print("Resetting cores of graph my_graph...\n");
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(0, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(0, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(1, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(1, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(2, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(2, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(3, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(3, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(4, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(4, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(5, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(5, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(6, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(6, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(7, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(7, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(8, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(8, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(9, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(9, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(10, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(10, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(11, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(11, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(12, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(12, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(13, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(13, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(14, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(14, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(15, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(15, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(16, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(16, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(17, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(17, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(18, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(18, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(19, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(19, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(20, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(20, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(21, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(21, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(22, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(22, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(23, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(23, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(24, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(24, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(25, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(25, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(26, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(26, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(27, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(27, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(28, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(28, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(29, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(29, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(30, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(30, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(31, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(31, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(32, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(32, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(33, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(33, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(34, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(34, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(35, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(35, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(36, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(36, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(37, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(37, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(38, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(38, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(39, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(39, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(40, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(40, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(41, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(41, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(42, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(42, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(43, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(43, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(44, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(44, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(45, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(45, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(46, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(46, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(47, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(47, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(48, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(48, 8));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 1));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 1));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 2));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 2));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 3));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 3));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 4));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 4));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 5));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 5));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 6));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 6));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 7));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 7));
	XAie_CoreReset(&DevInst, XAie_TileLoc(49, 8));
	XAie_CoreUnreset(&DevInst, XAie_TileLoc(49, 8));

	XAieLib_print("Configuring DMAs of graph my_graph...\n");

	//Setting buffer buf0
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 2));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 0), XAie_LockInit(0, 1));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 2), 0);
	}

	//Setting buffer buf0d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 2));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 0), XAie_LockInit(1, 1));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 2), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 2), 0, DMA_S2MM, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 2), 0, DMA_S2MM);

	//Setting buffer buf100
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 2));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 0), XAie_LockInit(2, 1));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 2), 2);
	}

	//Setting buffer buf100d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 2));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 0), XAie_LockInit(3, 1));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 2), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 2), 1, DMA_S2MM, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 2), 1, DMA_S2MM);

	//Setting buffer buf200
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 4));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 0), XAie_LockInit(0, 1));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 4), 0);
	}

	//Setting buffer buf200d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 4));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 0), XAie_LockInit(1, 1));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 4), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 4), 0, DMA_S2MM, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 4), 0, DMA_S2MM);

	//Setting buffer buf300
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 4));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 0), XAie_LockInit(2, 1));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 4), 2);
	}

	//Setting buffer buf300d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 4));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 0), XAie_LockInit(3, 1));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 4), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 4), 1, DMA_S2MM, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 4), 1, DMA_S2MM);

	//Setting buffer buf400
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 6));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 0), XAie_LockInit(0, 1));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 6), 0);
	}

	//Setting buffer buf400d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 6));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 0), XAie_LockInit(1, 1));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 6), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 6), 0, DMA_S2MM, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 6), 0, DMA_S2MM);

	//Setting buffer buf500
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 6));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 0), XAie_LockInit(2, 1));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 6), 2);
	}

	//Setting buffer buf500d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 6));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 0), XAie_LockInit(3, 1));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 6), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 6), 1, DMA_S2MM, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 6), 1, DMA_S2MM);

	//Setting buffer buf600
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 8));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 0), XAie_LockInit(0, 1));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 8), 0);
	}

	//Setting buffer buf600d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 8));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 0), XAie_LockInit(1, 1));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 8), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 8), 0, DMA_S2MM, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 8), 0, DMA_S2MM);

	//Setting buffer buf700
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 8));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 0), XAie_LockInit(2, 1));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 8), 2);
	}

	//Setting buffer buf700d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(0, 8));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 0), XAie_LockInit(3, 1));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(0, 8), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(0, 8), 1, DMA_S2MM, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(0, 8), 1, DMA_S2MM);

	//Setting buffer buf99
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 1));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 1), XAie_LockInit(2, 0));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 1), 2);
	}

	//Setting buffer buf99d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 1));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 1), XAie_LockInit(3, 0));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 1), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 1), 1, DMA_MM2S, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 1), 1, DMA_MM2S);

	//Setting buffer buf199
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 1));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 1), XAie_LockInit(0, 0));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 1), 0);
	}

	//Setting buffer buf199d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 1));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 1), XAie_LockInit(1, 0));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 1), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 1), 0, DMA_MM2S, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 1), 0, DMA_MM2S);

	//Setting buffer buf299
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 3));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 1), XAie_LockInit(0, 0));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 3), 0);
	}

	//Setting buffer buf299d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 3));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 1), XAie_LockInit(1, 0));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 3), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 3), 0, DMA_MM2S, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 3), 0, DMA_MM2S);

	//Setting buffer buf399
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 3));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 1), XAie_LockInit(2, 0));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 3), 2);
	}

	//Setting buffer buf399d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 3));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 1), XAie_LockInit(3, 0));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 3), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 3), 1, DMA_MM2S, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 3), 1, DMA_MM2S);

	//Setting buffer buf499
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 5));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 1), XAie_LockInit(0, 0));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 5), 0);
	}

	//Setting buffer buf499d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 5));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 1), XAie_LockInit(1, 0));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 5), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 5), 0, DMA_MM2S, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 5), 0, DMA_MM2S);

	//Setting buffer buf599
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 5));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 1), XAie_LockInit(2, 0));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 5), 2);
	}

	//Setting buffer buf599d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 5));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 1), XAie_LockInit(3, 0));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 5), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 5), 1, DMA_MM2S, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 5), 1, DMA_MM2S);

	//Setting buffer buf699
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 7));
		XAie_DmaSetAddrLen(&DmaInst, 0x0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(0, 1), XAie_LockInit(0, 0));
		XAie_DmaSetNextBd(&DmaInst, 1, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 7), 0);
	}

	//Setting buffer buf699d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 7));
		XAie_DmaSetAddrLen(&DmaInst, 0x6bc0, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(1, 1), XAie_LockInit(1, 0));
		XAie_DmaSetNextBd(&DmaInst, 0, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 7), 1);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 7), 0, DMA_MM2S, 0);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 7), 0, DMA_MM2S);

	//Setting buffer buf799
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 7));
		XAie_DmaSetAddrLen(&DmaInst, 0x7520, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(2, 1), XAie_LockInit(2, 0));
		XAie_DmaSetNextBd(&DmaInst, 3, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 7), 2);
	}

	//Setting buffer buf799d
	{
		XAie_DmaDesc DmaInst;
		XAie_DmaDescInit(&DevInst, &DmaInst, XAie_TileLoc(49, 7));
		XAie_DmaSetAddrLen(&DmaInst, 0x960, 2400);
		XAie_DmaSetLock(&DmaInst, XAie_LockInit(3, 1), XAie_LockInit(3, 0));
		XAie_DmaSetNextBd(&DmaInst, 2, XAIE_ENABLE);
		XAie_DmaEnableBd(&DmaInst);
		XAie_DmaWriteBd(&DevInst, &DmaInst, XAie_TileLoc(49, 7), 3);
	}

	XAie_DmaChannelPushBdToQueue(&DevInst, XAie_TileLoc(49, 7), 1, DMA_MM2S, 2);
	XAie_DmaChannelEnable(&DevInst, XAie_TileLoc(49, 7), 1, DMA_MM2S);

	XAieLib_print("Configuring PL-Interface for graph my_graph...\n");
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(6, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(6, 0), 0, PLIF_WIDTH_64);
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(7, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(7, 0), 0, PLIF_WIDTH_64);
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(11, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(11, 0), 0, PLIF_WIDTH_64);
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(17, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(17, 0), 0, PLIF_WIDTH_64);
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(23, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(23, 0), 0, PLIF_WIDTH_64);
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(29, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(29, 0), 0, PLIF_WIDTH_64);
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(35, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(35, 0), 0, PLIF_WIDTH_64);
	XAie_PlIfBliBypassDisable(&DevInst, XAie_TileLoc(41, 0), 0);
	XAie_PlToAieIntfEnable (&DevInst, XAie_TileLoc(41, 0), 0, PLIF_WIDTH_64);
	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(43, 0), 0, PLIF_WIDTH_64);

	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(40, 0), 0, PLIF_WIDTH_64);

	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(34, 0), 0, PLIF_WIDTH_64);

	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(28, 0), 0, PLIF_WIDTH_64);

	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(22, 0), 0, PLIF_WIDTH_64);

	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(16, 0), 0, PLIF_WIDTH_64);

	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(10, 0), 0, PLIF_WIDTH_64);

	XAie_AieToPlIntfEnable (&DevInst, XAie_TileLoc(6, 0), 5, PLIF_WIDTH_64);



    #endif

	return;
  }

 void my_graph_core_debug_halt()
  {
	XAieLib_print("Putting core(s) of graph my_graph on halt state for debugging...\n");
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(0, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(1, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(2, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(3, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(4, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(5, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(6, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(7, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(8, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(9, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(10, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(11, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(12, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(13, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(14, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(15, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(16, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(17, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(18, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(19, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(20, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(21, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(22, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(23, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(24, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(25, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(26, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(27, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(28, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(29, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(30, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(31, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(32, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(33, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(34, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(35, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(36, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(37, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(38, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(39, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(40, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(41, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(42, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(43, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(44, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(45, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(46, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(47, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(48, 8));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 1));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 2));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 3));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 4));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 5));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 6));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 7));
	XAie_CoreDebugHalt(&DevInst, XAie_TileLoc(49, 8));
	return;
  }

  void my_graph_core_enable()
  {
	XAieLib_print("Enabling core(s) of graph my_graph...\n");
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(0,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(1,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(2,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(3,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(4,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(5,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(6,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(7,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(8,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(9,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(10,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(11,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(12,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(13,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(14,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(15,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(16,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(17,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(18,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(19,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(20,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(21,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(22,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(23,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(24,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(25,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(26,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(27,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(28,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(29,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(30,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(31,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(32,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(33,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(34,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(35,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(36,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(37,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(38,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(39,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(40,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(41,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(42,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(43,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(44,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(45,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(46,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(47,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(48,8 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,1 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,2 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,3 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,4 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,5 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,6 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,7 ));
	XAie_CoreEnable(&DevInst, XAie_TileLoc(49,8 ));
	return;
  }

/************************** Partition reset *****************************/

  void resetPartition()
  {
    XAie_ResetPartition(&DevInst);
  }


/************************** Error handling *****************************/

  void enableErrorHandling()
  {
    XAie_ErrorHandlingInit(&DevInst);
  }


/************************** Clock gating *****************************/

  void enableClockGating()
  {
    XAie_LocType locs[450] = {XAie_TileLoc(0, 0), XAie_TileLoc(0, 1), XAie_TileLoc(0, 2), XAie_TileLoc(0, 3), XAie_TileLoc(0, 4), XAie_TileLoc(0, 5), XAie_TileLoc(0, 6), XAie_TileLoc(0, 7), XAie_TileLoc(0, 8), XAie_TileLoc(1, 0), XAie_TileLoc(1, 1), XAie_TileLoc(1, 2), XAie_TileLoc(1, 3), XAie_TileLoc(1, 4), XAie_TileLoc(1, 5), XAie_TileLoc(1, 6), XAie_TileLoc(1, 7), XAie_TileLoc(1, 8), XAie_TileLoc(2, 0), XAie_TileLoc(2, 1), XAie_TileLoc(2, 2), XAie_TileLoc(2, 3), XAie_TileLoc(2, 4), XAie_TileLoc(2, 5), XAie_TileLoc(2, 6), XAie_TileLoc(2, 7), XAie_TileLoc(2, 8), XAie_TileLoc(3, 0), XAie_TileLoc(3, 1), XAie_TileLoc(3, 2), XAie_TileLoc(3, 3), XAie_TileLoc(3, 4), XAie_TileLoc(3, 5), XAie_TileLoc(3, 6), XAie_TileLoc(3, 7), XAie_TileLoc(3, 8), XAie_TileLoc(4, 0), XAie_TileLoc(4, 1), XAie_TileLoc(4, 2), XAie_TileLoc(4, 3), XAie_TileLoc(4, 4), XAie_TileLoc(4, 5), XAie_TileLoc(4, 6), XAie_TileLoc(4, 7), XAie_TileLoc(4, 8), XAie_TileLoc(5, 0), XAie_TileLoc(5, 1), XAie_TileLoc(5, 2), XAie_TileLoc(5, 3), XAie_TileLoc(5, 4), XAie_TileLoc(5, 5), XAie_TileLoc(5, 6), XAie_TileLoc(5, 7), XAie_TileLoc(5, 8), XAie_TileLoc(6, 0), XAie_TileLoc(6, 1), XAie_TileLoc(6, 2), XAie_TileLoc(6, 3), XAie_TileLoc(6, 4), XAie_TileLoc(6, 5), XAie_TileLoc(6, 6), XAie_TileLoc(6, 7), XAie_TileLoc(6, 8), XAie_TileLoc(7, 0), XAie_TileLoc(7, 1), XAie_TileLoc(7, 2), XAie_TileLoc(7, 3), XAie_TileLoc(7, 4), XAie_TileLoc(7, 5), XAie_TileLoc(7, 6), XAie_TileLoc(7, 7), XAie_TileLoc(7, 8), XAie_TileLoc(8, 0), XAie_TileLoc(8, 1), XAie_TileLoc(8, 2), XAie_TileLoc(8, 3), XAie_TileLoc(8, 4), XAie_TileLoc(8, 5), XAie_TileLoc(8, 6), XAie_TileLoc(8, 7), XAie_TileLoc(8, 8), XAie_TileLoc(9, 0), XAie_TileLoc(9, 1), XAie_TileLoc(9, 2), XAie_TileLoc(9, 3), XAie_TileLoc(9, 4), XAie_TileLoc(9, 5), XAie_TileLoc(9, 6), XAie_TileLoc(9, 7), XAie_TileLoc(9, 8), XAie_TileLoc(10, 0), XAie_TileLoc(10, 1), XAie_TileLoc(10, 2), XAie_TileLoc(10, 3), XAie_TileLoc(10, 4), XAie_TileLoc(10, 5), XAie_TileLoc(10, 6), XAie_TileLoc(10, 7), XAie_TileLoc(10, 8), XAie_TileLoc(11, 0), XAie_TileLoc(11, 1), XAie_TileLoc(11, 2), XAie_TileLoc(11, 3), XAie_TileLoc(11, 4), XAie_TileLoc(11, 5), XAie_TileLoc(11, 6), XAie_TileLoc(11, 7), XAie_TileLoc(11, 8), XAie_TileLoc(12, 0), XAie_TileLoc(12, 1), XAie_TileLoc(12, 2), XAie_TileLoc(12, 3), XAie_TileLoc(12, 4), XAie_TileLoc(12, 5), XAie_TileLoc(12, 6), XAie_TileLoc(12, 7), XAie_TileLoc(12, 8), XAie_TileLoc(13, 0), XAie_TileLoc(13, 1), XAie_TileLoc(13, 2), XAie_TileLoc(13, 3), XAie_TileLoc(13, 4), XAie_TileLoc(13, 5), XAie_TileLoc(13, 6), XAie_TileLoc(13, 7), XAie_TileLoc(13, 8), XAie_TileLoc(14, 0), XAie_TileLoc(14, 1), XAie_TileLoc(14, 2), XAie_TileLoc(14, 3), XAie_TileLoc(14, 4), XAie_TileLoc(14, 5), XAie_TileLoc(14, 6), XAie_TileLoc(14, 7), XAie_TileLoc(14, 8), XAie_TileLoc(15, 0), XAie_TileLoc(15, 1), XAie_TileLoc(15, 2), XAie_TileLoc(15, 3), XAie_TileLoc(15, 4), XAie_TileLoc(15, 5), XAie_TileLoc(15, 6), XAie_TileLoc(15, 7), XAie_TileLoc(15, 8), XAie_TileLoc(16, 0), XAie_TileLoc(16, 1), XAie_TileLoc(16, 2), XAie_TileLoc(16, 3), XAie_TileLoc(16, 4), XAie_TileLoc(16, 5), XAie_TileLoc(16, 6), XAie_TileLoc(16, 7), XAie_TileLoc(16, 8), XAie_TileLoc(17, 0), XAie_TileLoc(17, 1), XAie_TileLoc(17, 2), XAie_TileLoc(17, 3), XAie_TileLoc(17, 4), XAie_TileLoc(17, 5), XAie_TileLoc(17, 6), XAie_TileLoc(17, 7), XAie_TileLoc(17, 8), XAie_TileLoc(18, 0), XAie_TileLoc(18, 1), XAie_TileLoc(18, 2), XAie_TileLoc(18, 3), XAie_TileLoc(18, 4), XAie_TileLoc(18, 5), XAie_TileLoc(18, 6), XAie_TileLoc(18, 7), XAie_TileLoc(18, 8), XAie_TileLoc(19, 0), XAie_TileLoc(19, 1), XAie_TileLoc(19, 2), XAie_TileLoc(19, 3), XAie_TileLoc(19, 4), XAie_TileLoc(19, 5), XAie_TileLoc(19, 6), XAie_TileLoc(19, 7), XAie_TileLoc(19, 8), XAie_TileLoc(20, 0), XAie_TileLoc(20, 1), XAie_TileLoc(20, 2), XAie_TileLoc(20, 3), XAie_TileLoc(20, 4), XAie_TileLoc(20, 5), XAie_TileLoc(20, 6), XAie_TileLoc(20, 7), XAie_TileLoc(20, 8), XAie_TileLoc(21, 0), XAie_TileLoc(21, 1), XAie_TileLoc(21, 2), XAie_TileLoc(21, 3), XAie_TileLoc(21, 4), XAie_TileLoc(21, 5), XAie_TileLoc(21, 6), XAie_TileLoc(21, 7), XAie_TileLoc(21, 8), XAie_TileLoc(22, 0), XAie_TileLoc(22, 1), XAie_TileLoc(22, 2), XAie_TileLoc(22, 3), XAie_TileLoc(22, 4), XAie_TileLoc(22, 5), XAie_TileLoc(22, 6), XAie_TileLoc(22, 7), XAie_TileLoc(22, 8), XAie_TileLoc(23, 0), XAie_TileLoc(23, 1), XAie_TileLoc(23, 2), XAie_TileLoc(23, 3), XAie_TileLoc(23, 4), XAie_TileLoc(23, 5), XAie_TileLoc(23, 6), XAie_TileLoc(23, 7), XAie_TileLoc(23, 8), XAie_TileLoc(24, 0), XAie_TileLoc(24, 1), XAie_TileLoc(24, 2), XAie_TileLoc(24, 3), XAie_TileLoc(24, 4), XAie_TileLoc(24, 5), XAie_TileLoc(24, 6), XAie_TileLoc(24, 7), XAie_TileLoc(24, 8), XAie_TileLoc(25, 0), XAie_TileLoc(25, 1), XAie_TileLoc(25, 2), XAie_TileLoc(25, 3), XAie_TileLoc(25, 4), XAie_TileLoc(25, 5), XAie_TileLoc(25, 6), XAie_TileLoc(25, 7), XAie_TileLoc(25, 8), XAie_TileLoc(26, 0), XAie_TileLoc(26, 1), XAie_TileLoc(26, 2), XAie_TileLoc(26, 3), XAie_TileLoc(26, 4), XAie_TileLoc(26, 5), XAie_TileLoc(26, 6), XAie_TileLoc(26, 7), XAie_TileLoc(26, 8), XAie_TileLoc(27, 0), XAie_TileLoc(27, 1), XAie_TileLoc(27, 2), XAie_TileLoc(27, 3), XAie_TileLoc(27, 4), XAie_TileLoc(27, 5), XAie_TileLoc(27, 6), XAie_TileLoc(27, 7), XAie_TileLoc(27, 8), XAie_TileLoc(28, 0), XAie_TileLoc(28, 1), XAie_TileLoc(28, 2), XAie_TileLoc(28, 3), XAie_TileLoc(28, 4), XAie_TileLoc(28, 5), XAie_TileLoc(28, 6), XAie_TileLoc(28, 7), XAie_TileLoc(28, 8), XAie_TileLoc(29, 0), XAie_TileLoc(29, 1), XAie_TileLoc(29, 2), XAie_TileLoc(29, 3), XAie_TileLoc(29, 4), XAie_TileLoc(29, 5), XAie_TileLoc(29, 6), XAie_TileLoc(29, 7), XAie_TileLoc(29, 8), XAie_TileLoc(30, 0), XAie_TileLoc(30, 1), XAie_TileLoc(30, 2), XAie_TileLoc(30, 3), XAie_TileLoc(30, 4), XAie_TileLoc(30, 5), XAie_TileLoc(30, 6), XAie_TileLoc(30, 7), XAie_TileLoc(30, 8), XAie_TileLoc(31, 0), XAie_TileLoc(31, 1), XAie_TileLoc(31, 2), XAie_TileLoc(31, 3), XAie_TileLoc(31, 4), XAie_TileLoc(31, 5), XAie_TileLoc(31, 6), XAie_TileLoc(31, 7), XAie_TileLoc(31, 8), XAie_TileLoc(32, 0), XAie_TileLoc(32, 1), XAie_TileLoc(32, 2), XAie_TileLoc(32, 3), XAie_TileLoc(32, 4), XAie_TileLoc(32, 5), XAie_TileLoc(32, 6), XAie_TileLoc(32, 7), XAie_TileLoc(32, 8), XAie_TileLoc(33, 0), XAie_TileLoc(33, 1), XAie_TileLoc(33, 2), XAie_TileLoc(33, 3), XAie_TileLoc(33, 4), XAie_TileLoc(33, 5), XAie_TileLoc(33, 6), XAie_TileLoc(33, 7), XAie_TileLoc(33, 8), XAie_TileLoc(34, 0), XAie_TileLoc(34, 1), XAie_TileLoc(34, 2), XAie_TileLoc(34, 3), XAie_TileLoc(34, 4), XAie_TileLoc(34, 5), XAie_TileLoc(34, 6), XAie_TileLoc(34, 7), XAie_TileLoc(34, 8), XAie_TileLoc(35, 0), XAie_TileLoc(35, 1), XAie_TileLoc(35, 2), XAie_TileLoc(35, 3), XAie_TileLoc(35, 4), XAie_TileLoc(35, 5), XAie_TileLoc(35, 6), XAie_TileLoc(35, 7), XAie_TileLoc(35, 8), XAie_TileLoc(36, 0), XAie_TileLoc(36, 1), XAie_TileLoc(36, 2), XAie_TileLoc(36, 3), XAie_TileLoc(36, 4), XAie_TileLoc(36, 5), XAie_TileLoc(36, 6), XAie_TileLoc(36, 7), XAie_TileLoc(36, 8), XAie_TileLoc(37, 0), XAie_TileLoc(37, 1), XAie_TileLoc(37, 2), XAie_TileLoc(37, 3), XAie_TileLoc(37, 4), XAie_TileLoc(37, 5), XAie_TileLoc(37, 6), XAie_TileLoc(37, 7), XAie_TileLoc(37, 8), XAie_TileLoc(38, 0), XAie_TileLoc(38, 1), XAie_TileLoc(38, 2), XAie_TileLoc(38, 3), XAie_TileLoc(38, 4), XAie_TileLoc(38, 5), XAie_TileLoc(38, 6), XAie_TileLoc(38, 7), XAie_TileLoc(38, 8), XAie_TileLoc(39, 0), XAie_TileLoc(39, 1), XAie_TileLoc(39, 2), XAie_TileLoc(39, 3), XAie_TileLoc(39, 4), XAie_TileLoc(39, 5), XAie_TileLoc(39, 6), XAie_TileLoc(39, 7), XAie_TileLoc(39, 8), XAie_TileLoc(40, 0), XAie_TileLoc(40, 1), XAie_TileLoc(40, 2), XAie_TileLoc(40, 3), XAie_TileLoc(40, 4), XAie_TileLoc(40, 5), XAie_TileLoc(40, 6), XAie_TileLoc(40, 7), XAie_TileLoc(40, 8), XAie_TileLoc(41, 0), XAie_TileLoc(41, 1), XAie_TileLoc(41, 2), XAie_TileLoc(41, 3), XAie_TileLoc(41, 4), XAie_TileLoc(41, 5), XAie_TileLoc(41, 6), XAie_TileLoc(41, 7), XAie_TileLoc(41, 8), XAie_TileLoc(42, 0), XAie_TileLoc(42, 1), XAie_TileLoc(42, 2), XAie_TileLoc(42, 3), XAie_TileLoc(42, 4), XAie_TileLoc(42, 5), XAie_TileLoc(42, 6), XAie_TileLoc(42, 7), XAie_TileLoc(42, 8), XAie_TileLoc(43, 0), XAie_TileLoc(43, 1), XAie_TileLoc(43, 2), XAie_TileLoc(43, 3), XAie_TileLoc(43, 4), XAie_TileLoc(43, 5), XAie_TileLoc(43, 6), XAie_TileLoc(43, 7), XAie_TileLoc(43, 8), XAie_TileLoc(44, 0), XAie_TileLoc(44, 1), XAie_TileLoc(44, 2), XAie_TileLoc(44, 3), XAie_TileLoc(44, 4), XAie_TileLoc(44, 5), XAie_TileLoc(44, 6), XAie_TileLoc(44, 7), XAie_TileLoc(44, 8), XAie_TileLoc(45, 0), XAie_TileLoc(45, 1), XAie_TileLoc(45, 2), XAie_TileLoc(45, 3), XAie_TileLoc(45, 4), XAie_TileLoc(45, 5), XAie_TileLoc(45, 6), XAie_TileLoc(45, 7), XAie_TileLoc(45, 8), XAie_TileLoc(46, 0), XAie_TileLoc(46, 1), XAie_TileLoc(46, 2), XAie_TileLoc(46, 3), XAie_TileLoc(46, 4), XAie_TileLoc(46, 5), XAie_TileLoc(46, 6), XAie_TileLoc(46, 7), XAie_TileLoc(46, 8), XAie_TileLoc(47, 0), XAie_TileLoc(47, 1), XAie_TileLoc(47, 2), XAie_TileLoc(47, 3), XAie_TileLoc(47, 4), XAie_TileLoc(47, 5), XAie_TileLoc(47, 6), XAie_TileLoc(47, 7), XAie_TileLoc(47, 8), XAie_TileLoc(48, 0), XAie_TileLoc(48, 1), XAie_TileLoc(48, 2), XAie_TileLoc(48, 3), XAie_TileLoc(48, 4), XAie_TileLoc(48, 5), XAie_TileLoc(48, 6), XAie_TileLoc(48, 7), XAie_TileLoc(48, 8), XAie_TileLoc(49, 0), XAie_TileLoc(49, 1), XAie_TileLoc(49, 2), XAie_TileLoc(49, 3), XAie_TileLoc(49, 4), XAie_TileLoc(49, 5), XAie_TileLoc(49, 6), XAie_TileLoc(49, 7), XAie_TileLoc(49, 8), };
    XAie_PmRequestTiles(&DevInst, locs, 450);
  }


/************************** Clear Partition Memories *****************************/

  void clearPartitionMems()
  {
    XAie_ClearPartitionMems(&DevInst);
  }


/************************** Graph Configurations  *****************************/

  adf::GraphConfig GraphConfigurations[] = {
  //{id, name, graphLoadElfFunc, graphInitFunc, coreColumns, coreRows, iterMemColumns, iterMemRows, iterMemAddrs, triggered, plKernelInstanceNames, plAxiLiteModes, plDriverStartFuncs, plDriverCheckIPDoneFuncs}
    {0, "my_graph", &my_graph_load_elf, &my_graph_init, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31, 31, 32, 32, 32, 32, 32, 32, 32, 32, 33, 33, 33, 33, 33, 33, 33, 33, 34, 34, 34, 34, 34, 34, 34, 34, 35, 35, 35, 35, 35, 35, 35, 35, 36, 36, 36, 36, 36, 36, 36, 36, 37, 37, 37, 37, 37, 37, 37, 37, 38, 38, 38, 38, 38, 38, 38, 38, 39, 39, 39, 39, 39, 39, 39, 39, 40, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42, 42, 42, 42, 42, 43, 43, 43, 43, 43, 43, 43, 43, 44, 44, 44, 44, 44, 44, 44, 44, 45, 45, 45, 45, 45, 45, 45, 45, 46, 46, 46, 46, 46, 46, 46, 46, 47, 47, 47, 47, 47, 47, 47, 47, 48, 48, 48, 48, 48, 48, 48, 48, 49, 49, 49, 49, 49, 49, 49, 49}, {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 4, 4, 4, 4, 3, 5, 4, 5, 4, 5, 5, 5, 5, 6, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 7, 8, 8, 8, 8, 8, 7, 8, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 11, 10, 10, 10, 10, 11, 11, 11, 12, 11, 12, 10, 11, 12, 12, 12, 12, 11, 13, 11, 12, 13, 13, 13, 13, 13, 13, 12, 13, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 15, 17, 16, 18, 17, 17, 17, 17, 17, 18, 17, 18, 18, 18, 17, 18, 18, 19, 18, 19, 19, 19, 19, 19, 19, 20, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 20, 21, 21, 22, 22, 22, 22, 22, 22, 22, 21, 22, 23, 23, 23, 24, 23, 24, 23, 23, 24, 24, 23, 24, 23, 24, 24, 24, 25, 25, 25, 26, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 27, 28, 27, 27, 27, 27, 27, 27, 28, 28, 27, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31, 30, 31, 30, 31, 31, 31, 31, 31, 30, 32, 31, 32, 32, 32, 32, 32, 32, 33, 32, 33, 33, 33, 33, 33, 33, 34, 33, 34, 34, 34, 34, 34, 34, 35, 35, 35, 35, 35, 35, 35, 34, 35, 36, 36, 36, 36, 36, 37, 36, 36, 37, 37, 37, 37, 37, 37, 36, 37, 38, 38, 38, 38, 38, 39, 38, 38, 39, 39, 39, 39, 39, 39, 38, 39, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 41, 41, 41, 41, 40, 41, 42, 42, 42, 42, 42, 42, 42, 42, 43, 43, 43, 43, 43, 43, 43, 43, 44, 44, 44, 45, 44, 44, 44, 44, 44, 45, 45, 45, 45, 45, 45, 45, 46, 46, 46, 46, 46, 46, 46, 46, 47, 47, 47, 47, 47, 47, 47, 47, 48, 48, 48, 48, 48, 48, 48, 48, 49, 49, 49, 49, 49, 49, 49, 49}, {0, 1, 2, 4, 3, 6, 5, 7, 1, 0, 3, 2, 5, 5, 6, 7, 1, 0, 3, 2, 4, 4, 6, 7, 0, 2, 1, 3, 5, 4, 7, 7, 1, 1, 3, 4, 5, 6, 6, 7, 0, 2, 2, 4, 3, 5, 6, 7, 0, 0, 1, 2, 3, 4, 5, 6, 0, 2, 1, 3, 5, 5, 7, 7, 1, 0, 3, 2, 4, 4, 6, 6, 1, 0, 2, 4, 3, 5, 7, 6, 0, 2, 1, 3, 3, 4, 5, 7, 1, 0, 2, 3, 5, 5, 6, 7, 1, 0, 2, 4, 4, 5, 6, 7, 1, 0, 2, 4, 3, 6, 6, 7, 1, 0, 2, 3, 5, 4, 7, 6, 0, 2, 1, 3, 5, 4, 7, 7, 1, 2, 3, 4, 5, 6, 6, 7, 0, 1, 1, 2, 3, 5, 6, 7, 0, 2, 3, 4, 4, 6, 5, 7, 0, 2, 1, 4, 3, 6, 5, 7, 0, 0, 1, 2, 3, 6, 5, 7, 1, 0, 2, 3, 4, 4, 5, 7, 0, 2, 1, 3, 4, 5, 6, 6, 0, 1, 3, 3, 5, 5, 6, 7, 1, 0, 2, 2, 4, 4, 7, 6, 1, 2, 3, 3, 5, 4, 6, 7, 0, 0, 1, 2, 5, 4, 6, 7, 0, 1, 1, 4, 3, 5, 6, 7, 0, 2, 2, 3, 4, 6, 5, 7, 1, 0, 3, 2, 5, 4, 7, 6, 1, 2, 3, 4, 5, 5, 7, 7, 0, 1, 3, 2, 4, 6, 6, 7, 0, 1, 2, 4, 3, 6, 5, 7, 0, 1, 2, 4, 3, 6, 5, 7, 0, 0, 1, 2, 3, 4, 5, 7, 0, 2, 1, 3, 5, 4, 6, 6, 1, 0, 2, 3, 4, 5, 5, 7, 1, 0, 3, 2, 4, 6, 6, 7, 1, 0, 3, 2, 4, 5, 5, 7, 1, 0, 2, 4, 3, 6, 6, 7, 0, 1, 3, 2, 4, 5, 7, 7, 1, 0, 2, 4, 3, 5, 6, 6, 1, 0, 3, 2, 4, 6, 5, 7, 1, 0, 3, 2, 5, 4, 7, 6, 1, 2, 3, 3, 4, 6, 5, 7, 0, 0, 1, 2, 5, 4, 6, 7, 1, 0, 2, 3, 4, 6, 5, 7, 0, 2, 1, 4, 3, 6, 5, 7, 1, 0, 2, 3, 5, 4, 6, 7, 0, 1, 2, 4, 3, 6, 5, 7}, {0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4, 0x12c4}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {}, {}, {}, {}, },
  };
  const int NUM_GRAPH = 1;

/************************** PLIO Configurations  *****************************/

  adf::PLIOConfig PLIOConfigurations[] = {
  //{id, shim_column, slaveOrMaster, streamId}
    {0, 6, 0, 0}, //plin[0], i0
    {1, 7, 0, 0}, //plin[1], i1
    {2, 11, 0, 0}, //plin[2], i2
    {3, 17, 0, 0}, //plin[3], i3
    {4, 23, 0, 0}, //plin[4], i4
    {5, 29, 0, 0}, //plin[5], i5
    {6, 35, 0, 0}, //plin[6], i6
    {7, 41, 0, 0}, //plin[7], i7
    {8, 43, 1, 0}, //plout[0], i8
    {9, 40, 1, 0}, //plout[1], i9
    {10, 34, 1, 0}, //plout[2], i10
    {11, 28, 1, 0}, //plout[3], i11
    {12, 22, 1, 0}, //plout[4], i12
    {13, 16, 1, 0}, //plout[5], i13
    {14, 10, 1, 0}, //plout[6], i14
    {15, 6, 1, 5}, //plout[7], i15
  };
  const int NUM_PLIO = 16;


/************************** AIE driver and Cardano API initializer *****************************/

  class InitializeAIEControl
  {
  public:
    InitializeAIEControl()
    {
      XAieLib_print("Initializing AIE driver...\n");
      XAie_SetupConfig(ConfigPtr, HW_GEN, XAIE_BASE_ADDR, XAIE_COL_SHIFT,
                       XAIE_ROW_SHIFT, XAIE_NUM_COLS, XAIE_NUM_ROWS,
                       XAIE_SHIM_ROW, XAIE_MEM_TILE_ROW_START,
                       XAIE_MEM_TILE_NUM_ROWS, XAIE_AIE_TILE_ROW_START,
                       XAIE_AIE_TILE_NUM_ROWS);

      XAie_CfgInitialize(&(DevInst), &ConfigPtr);

      XAieLib_print("Initializing Cardano API...\n");

#if defined(__AIESIM__) && !defined(__CDO__)
      extern unsigned ess_debug;
#else
      unsigned ess_debug = false;
#endif

#if defined(__PS_ENABLE_AIE__) || defined(PS_ENABLE_AIE)
      bool ps_enable_aie = true;
#else
      bool ps_enable_aie = false;
#endif

#ifdef __EXCLUDE_PL_CONTROL__
      bool exclude_pl_control = true;
#else
      bool exclude_pl_control = false;
#endif

      adf::initializeConfigurations(&DevInst, XAIE_NUM_COLS, XAIE_AIE_TILE_NUM_ROWS, XAIE_MEM_TILE_NUM_ROWS,
                                        nullptr, 0,
                                        GraphConfigurations, NUM_GRAPH,
                                        nullptr, 0,
                                        nullptr, 0,
                                        nullptr, 0,
                                        nullptr, 0,
                                        PLIOConfigurations, NUM_PLIO,
                                        nullptr, 0, 0, nullptr,
                                        CTRL_PL_OFFSET, CTRL_IP_STRIDE, ps_enable_aie, ess_debug, exclude_pl_control, true);

#if defined(__AIESIM__) && !defined(__CDO__)
      XAie_TurnEccOff(&DevInst);
#else
      XAie_TurnEccOn(&DevInst);
#endif
    }
  } initAIEControl;



#if !defined(__CDO__)

// Kernel Stub Definition
  void OneInput(input_window<int> *,output_window<int> *,output_window<int> *) { /* Stub */ } 
  void OneOutput(input_window<int> *,input_window<int> *,output_window<int> *) { /* Stub */ } 
  void TwoInputs(input_window<int> *,input_window<int> *,output_window<int> *,output_window<int> *) { /* Stub */ } 
#endif
