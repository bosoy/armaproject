class CfgPatches
{
	class ace_sys_afterburner
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAAir","CAAir2","CAAir2_F35B","CAAir3","CAAir3_Su34"};
		version = "1.14.0.590";
		author[] = {"rocko"};
		class ACE_Options
		{
			group = "VEH";
			title = " ";
			class Afterburner
			{
				title = "$STR_ACE_TITLE_AFTERBURNER";
			};
		};
	};
};
class CfgSounds
{
	class ace_fx_planeABurner
	{
		name = "ace_fx_planeABurner";
		sound[] = {"\x\ace\addons\sys_afterburner\sounds\afterburner.ogg","db+65",1};
		titles[] = {};
	};
};
class CfgVehicles
{
	class Air;
	class Plane: Air
	{
		ace_hasAfterburner = 0;
	};
	class Su34: Plane
	{
		ace_hasAfterburner = 1;
		ace_afterburner_engines[] = {{1.14,-8.3,-1.0},{-1.14,-8.3,-1.0}};
	};
	class F35_base: Plane
	{
		ace_hasAfterburner = 1;
		ace_afterburner_engines[] = {{0,-5.3,0}};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_afterburner
	{
		clientInit = "call ('\x\ace\addons\sys_afterburner\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};