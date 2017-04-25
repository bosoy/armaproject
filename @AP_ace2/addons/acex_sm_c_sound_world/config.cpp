////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:49 2011 : Created on Fri Oct 21 14:00:49 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_world : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_world
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CASounds","acex_sm_s_world"};
		version = "1.12.0.97";
	};
};
class CfgEnvSounds
{
	class Rain
	{
		volume = "rain*(1-night)*(1-forest)";
		randSamp1[] = {"x\acex_sm\addons\s_world\rain\waterdripa1.wss",0.11,1,25,0.125,8,10,15};
		randSamp2[] = {"x\acex_sm\addons\s_world\rain\waterdripa2.wss",0.104,1,25,0.125,8,10,15};
		randSamp3[] = {"x\acex_sm\addons\s_world\rain\waterdripa3.wss",0.102,1,25,0.125,8,10,15};
		randSamp4[] = {"x\acex_sm\addons\s_world\rain\waterdripa4.wss",0.11,1,25,0.125,8,10,15};
		randSamp5[] = {"x\acex_sm\addons\s_world\rain\waterdripa5.wss",0.103,1,25,0.125,8,10,15};
		randSamp6[] = {"x\acex_sm\addons\s_world\rain\waterdripa6.wss",0.11,1,25,0.125,8,10,15};
		randSamp7[] = {"x\acex_sm\addons\s_world\rain\waterdripa7.wss",0.101,1,25,0.125,8,10,15};
		randSamp8[] = {"x\acex_sm\addons\s_world\rain\waterdripa8.wss",0.11,1,25,0.125,8,10,15};
		random[] = {"randSamp1","randSamp2","randSamp3","randSamp4","randSamp5","randSamp6","randSamp7","randSamp8"};
	};
	class Meadows2
	{
		sound[] = {"x\acex_sm\addons\s_world\misc\null.wss",0.0,0.0};
		soundNight[] = {"x\acex_sm\addons\s_world\misc\null.wss",0.0,0.0};
		volume = "rain*(1-night)";
		randSamp1[] = {"x\acex_sm\addons\s_world\Frog\Frog1.wss",0.209828,1,25,0.2,15,35,40};
		randSamp2[] = {"x\acex_sm\addons\s_world\Frog\Frog2.wss",0.208428,1,25,0.2,15,35,40};
		randSamp3[] = {"x\acex_sm\addons\s_world\Frog\Frog3.wss",0.209428,1,25,0.2,15,35,40};
		randSamp4[] = {"x\acex_sm\addons\s_world\Frog\Frog4.wss",0.198428,1,25,0.2,15,35,40};
		randSamp5[] = {"x\acex_sm\addons\s_world\Frog\Frog5.wss",0.209428,1,25,0.2,15,35,40};
		randSamp6[] = {"x\acex_sm\addons\s_world\Frog\Frog6.wss",0.199428,1,25,0.2,15,35,40};
		randSamp7[] = {"x\acex_sm\addons\s_world\Frog\Frog7.wss",0.209428,1,25,0.2,15,35,40};
		random[] = {"randSamp1","randSamp2","randSamp3","randSamp4","randSamp5","randSamp6","randSamp7"};
	};
	class Meadows2Night
	{
		sound[] = {"x\acex_sm\addons\s_world\misc\null.wss",0.0,0.0};
		soundNight[] = {"x\acex_sm\addons\s_world\misc\null.wss",0.0,0.0};
		volume = "rain*night";
		randSamp1[] = {"x\acex_sm\addons\s_world\Frog\Frog1.wss",0.199828,1,25,0.21,15,35,40};
		randSamp2[] = {"x\acex_sm\addons\s_world\Frog\Frog2.wss",0.198428,1,25,0.21,15,35,40};
		randSamp3[] = {"x\acex_sm\addons\s_world\Frog\Frog3.wss",0.199428,1,25,0.21,15,35,40};
		randSamp4[] = {"x\acex_sm\addons\s_world\Frog\Frog4.wss",0.198428,1,25,0.21,15,35,40};
		randSamp5[] = {"x\acex_sm\addons\s_world\Frog\Frog5.wss",0.199428,1,25,0.21,15,35,40};
		randSamp6[] = {"x\acex_sm\addons\s_world\Frog\Frog6.wss",0.199428,1,25,0.21,15,35,40};
		randSamp7[] = {"x\acex_sm\addons\s_world\Frog\Frog7.wss",0.199428,1,25,0.21,15,35,40};
		random[] = {"randSamp1","randSamp2","randSamp3","randSamp4","randSamp5","randSamp6","randSamp7"};
	};
};
//};
