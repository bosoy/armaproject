////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 18 19:05:20 2011 : Created on Fri Nov 18 19:05:20 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_ai_skill : config.bin{
class CfgPatches
{
	class ace_c_ai_skill
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.59;
		requiredAddons[] = {"ace_main"};
		version = "1.12.1.519";
	};
};
class CfgAISkill
{
	aimingAccuracy[] = {0,0,1,0.9};
	aimingShake[] = {0,0,1,0.5};
	aimingSpeed[] = {0,0.2,1,0.7};
	courage[] = {0,0,1,1};
	commanding[] = {0,1,1,3};
	endurance[] = {0,1,1,2};
	general[] = {0,1,1,3};
	reloadSpeed[] = {0,1,1,1};
	spotDistance[] = {0,0.5,1,1.5};
	spotTime[] = {0,0.5,1,1};
};
//};
