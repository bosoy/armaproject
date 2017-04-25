//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC_Config_Camps      //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

private [
			"_CampTyp","_campBasic","_campAmmo","_campStatic","_campWall","_campObjInit",
			"_campUserObj","_campAddUnit","_campRandomObj","_Unit_Pool_C","_array"
		];

			_CampTyp = _this select 0;_array = [];

switch (_CampTyp) do
{
//-------------------------------------------------------------------------------------------------------------------------
	case 0:
	{
		_campBasic     = ["FlagCarrierRU",["Land_Fire_burning",8,5,0],["CampEAST",5,0,0],["Logic",10,15,0],0];
		_campAmmo      = [["RUBasicWeaponsBox",10,2,0],["RULaunchersBox",10,0,0],["RUSpecialWeaponsBox",10,-2,0],["RUBasicAmmunitionBox",10,-4,0]];
		_campStatic    = [["D30_RU",-7,25,0,"RU_Soldier_GL"],["D30_RU",25,25,0,"RU_Soldier_GL"],["D30_RU",25,-20,180,"RU_Soldier_GL"],["D30_RU",-7,-20,180,"RU_Soldier_GL"]];
		_campAddUnit   = [];
		_campUserObj   = [["Land_Antenna",5,-5,45]];
		_campRandomObj = [];
		_campWall      = ["Land_BagFenceLong",[-10,30],[40,56,0],[5,5,5,5],[1,0.2],[0,0]];
		_campObjInit   = [[],[],[],[],[],[],[]];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 1:
	{
		_campBasic     = ["FlagCarrierUSA",["Land_Fire_burning",8,5,0],["Camp",5,0,0],["Logic",10,15,0],0];
		_campAmmo      = [["USLaunchersBox",10,2,0],["USSpecialWeaponsBox",10,0,0],["USBasicAmmunitionBox",10,-2,0],["USBasicWeaponsBox",10,-4,0]];
		_campStatic    = [["M119",-7,25,0,"USMC_Soldier_GL"],["M119",25,25,0,"USMC_Soldier_GL"],["M119",25,-20,180,"USMC_Soldier_GL"],["M119",-7,-20,180,"USMC_Soldier_GL"]];
		_campAddUnit   = [];
		_campUserObj   = [["Land_Antenna",5,-5,45]];
		_campRandomObj = [];
		_campWall      = ["Land_BagFenceLong",[-10,30],[40,56,0],[5,5,5,5],[1,0.2],[0,0]];
		_campObjInit   = [[],[],[],[],[],[],[]];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 2:
	{
		_campBasic     = ["FlagCarrierINS",["Land_Fire_burning",8,5,0],["Camp",5,0,0],["Logic",10,15,0],0];
		_campAmmo      = [["GuerillaCacheBox",10,2,0],["LocalBasicAmmunitionBox",10,0,0],["LocalBasicWeaponsBox",10,-2,0]];
		_campStatic    = [["DSHKM_Gue",-7,25,0,"GUE_Soldier_1"],["DSHKM_Gue",25,25,0,"GUE_Soldier_1"],["DSHKM_Gue",25,-20,180,"GUE_Soldier_1"],["DSHKM_Gue",-7,-20,180,"GUE_Soldier_1"]];
		_campAddUnit   = [];
		_campUserObj   = [["Land_Antenna",5,-5,45]];
		_campRandomObj = [];
		_campWall      = ["Land_BagFenceLong",[-10,30],[40,56,0],[5,5,5,5],[1,0.2],[0,0]];
		_campObjInit   = [[],[],[],[],[],[],[]];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 3:
	{
		_campBasic     = ["FlagCarrierOPFOR_EP1",["Land_Fire_burning",8,5,0],["CampEAST_EP1",5,0,180],["Logic",10,15,0],0];
		_campAmmo      = [["TKSpecialWeapons_EP1",10,2,0],["TKBasicAmmunitionBox_EP1",10,0,0],["TKBasicAmmunitionBox_EP1",10,-2,0],["TKBasicWeapons_EP1",10,-4,0]];
		_campStatic    = [["D30_TK_GUE_EP1",-7,25,0,"TK_Soldier_EP1"],["D30_TK_GUE_EP1",25,25,0,"TK_Soldier_EP1"],["D30_TK_GUE_EP1",25,-20,180,"TK_Soldier_EP1"],["D30_TK_GUE_EP1",-7,-20,180,"TK_Soldier_EP1"]];
		_campAddUnit   = [];
		_campUserObj   = [["Land_Antenna",5,-5,45]];
		_campRandomObj = [];
		_campWall      = ["Land_BagFenceLong",[-10,30],[40,56,0],[5,5,5,5],[1,0.2],[0,0]];
		_campObjInit   = [[],[],[],[],[],[],[]];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 4:
	{
		_campBasic     = ["FlagCarrierBLUFOR_EP1",["Land_Fire_burning",8,5,0],["Camp_EP1",5,0,0],["Logic",10,15,0],0];
		_campAmmo      = [["USLaunchers_EP1",10,2,0],["USSpecialWeapons_EP1",10,0,0],["USBasicAmmunitionBox_EP1",10,-2,0],["USBasicWeapons_EP1",10,-4,0]];
		_campStatic    = [["M119_US_EP1",-7,25,0,"US_Soldier_SL_EP1"],["M119_US_EP1",25,25,0,"US_Soldier_SL_EP1"],["M119_US_EP1",25,-20,180,"US_Soldier_SL_EP1"],["M119_US_EP1",-7,-20,180,"US_Soldier_SL_EP1"]];
		_campAddUnit   = [];
		_campUserObj   = [["Land_Antenna",5,-5,45]];
		_campRandomObj = [];
		_campWall      = ["Land_BagFenceLong",[-10,30],[40,56,0],[5,5,5,5],[1,0.2],[0,0]];
		_campObjInit   = [[],[],[],[],[],[],[]];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 5:
	{
		_campBasic     = ["FlagCarrierINDFOR_EP1",["Land_Fire_burning",8,5,0],["Camp_EP1",5,0,0],["Logic",10,15,0],0];
		_campAmmo      = [["TKSpecialWeapons_EP1",10,2,0],["TKBasicAmmunitionBox_EP1",10,0,0],["TKBasicAmmunitionBox_EP1",10,-2,0],["TKBasicWeapons_EP1",10,-4,0]];
		_campStatic    = [["DSHKM_TK_GUE_EP1",-7,25,0,"TK_INS_Soldier_EP1"],["DSHKM_TK_GUE_EP1",25,25,0,"TK_INS_Soldier_EP1"],["DSHKM_TK_GUE_EP1",25,-20,180,"TK_INS_Soldier_EP1"],["DSHKM_TK_GUE_EP1",-7,-20,180,"TK_INS_Soldier_EP1"]];
		_campAddUnit   = [];
		_campUserObj   = [["Land_Antenna",5,-5,45]];
		_campRandomObj = [];
		_campWall      = ["Land_BagFenceLong",[-10,30],[40,56,0],[5,5,5,5],[1,0.2],[0,0]];
		_campObjInit   = [[],[],[],[],[],[],[]];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 11:
	{
		_campBasic     = ["NULL"];
		_campAmmo      = [];
		_campStatic    = [];
		_campAddUnit   = [];
		_campUserObj   = [];
		_campRandomObj = [];
		_campWall      = [];
		_campObjInit   = [[],[],[],[],[],[],[]];
	};
//-------------------------------------------------------------------------------------------------------------------------
	Default {
				if(DAC_Basic_Value != 5) then
				{
					DAC_Basic_Value = 5;publicvariable "DAC_Basic_Value";
					hintc "Error: DAC_Config_Camps > No valid config number";
				};
				if(true) exitwith {};
			};
};

_array = [_campBasic,_campAmmo,_campStatic,_campAddUnit,_campUserObj,_campRandomObj,_campWall,_campObjInit];
_array