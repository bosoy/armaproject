////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:07:29 2013 : Created on Sat Jun 08 13:07:29 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_sight_adjustment_gl : config.bin{
class CfgPatches
{
	class ace_sys_sight_adjustment_gl
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.593";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_sight_adjustment_gl
	{
		clientInit = "call ('\x\ace\addons\sys_sight_adjustment_gl\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class cfgMagazines
{
	class CA_Magazine;
	class 1Rnd_HE_M203: CA_Magazine
	{
		ace_gl_table[] = {{50,37},{100,80},{150,132},{200,183},{250,237},{300,300},{350,358},{400,450}};
	};
	class FlareWhite_M203: CA_Magazine
	{
		ace_gl_table[] = {{50,37},{100,80},{150,132},{200,183},{250,237},{300,300},{350,358},{400,450}};
	};
	class 1Rnd_HE_GP25: CA_Magazine
	{
		ace_gl_table[] = {{50,37},{100,80},{150,132},{200,183},{250,237},{300,300},{350,358},{400,450}};
	};
	class FlareWhite_GP25: CA_Magazine
	{
		ace_gl_table[] = {{50,37},{100,80},{150,132},{200,183},{250,237},{300,300},{350,358},{400,450}};
	};
};
class cfgWeapons
{
	class RifleCore;
	class Rifle: RifleCore
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 0;
	};
	class M16_base;
	class M16A2;
	class M16A2GL: M16A2
	{
		ace_gl_zero = 150;
	};
	class m16a4: M16A2{};
	class M16A4_GL: m16a4
	{
		ace_gl_zero = 150;
	};
	class M16A4_ACG_GL: M16A4_GL
	{
		ace_gl_zero = 150;
	};
	class M4A1;
	class M4A1_RCO_GL: M4A1
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 17;
	};
	class M4A1_HWS_GL: M4A1_RCO_GL
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 27;
	};
	class M4A1_Aim: M4A1{};
	class M4A1_AIM_SD_camo: M4A1_Aim{};
	class M4A1_HWS_GL_SD_Camo: M4A1_AIM_SD_camo
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 9;
	};
	class M4A1_HWS_GL_camo: M4A1_HWS_GL
	{
		ace_gl_zero = 150;
	};
	class M4A3_CCO_EP1;
	class M4A3_RCO_GL_EP1: M4A3_CCO_EP1
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 21;
	};
	class m8_base;
	class m8_carbineGL: m8_base
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = -10;
	};
	class AK_BASE: Rifle
	{
		ace_gl_zero = 150;
	};
	class AK_74_GL: AK_BASE{};
	class AK_74_GL_kobra: AK_74_GL
	{
		ace_gl_fineadj = 0;
	};
	class GrenadeLauncher_EP1;
	class M32_EP1: GrenadeLauncher_EP1
	{
		ace_gl_zero = 200;
		ace_gl_fineadj = -20;
	};
	class M79_EP1: GrenadeLauncher_EP1
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 29;
	};
	class Mk13_EP1: GrenadeLauncher_EP1
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 39;
	};
	class SCAR_Base: M16_base
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 39;
	};
	class CZ805_A1_ACR: Rifle
	{
		ace_gl_fineadj = 38;
	};
	class BAF_L85A2_RIS_Holo;
	class BAF_L85A2_UGL_Holo: BAF_L85A2_RIS_Holo
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 130;
	};
	class BAF_L85A2_RIS_SUSAT;
	class BAF_L85A2_UGL_SUSAT: BAF_L85A2_RIS_SUSAT
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 130;
	};
	class BAF_L85A2_RIS_ACOG;
	class BAF_L85A2_UGL_ACOG: BAF_L85A2_RIS_ACOG
	{
		ace_gl_zero = 150;
		ace_gl_fineadj = 130;
	};
};
//};
