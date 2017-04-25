////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:35:18 2011 : Created on Fri Oct 21 13:35:18 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_brdm : config.bin{
class CfgPatches
{
	class acex_veh_brdm
	{
		units[] = {"ACE_BRDM2_SA9_TK"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWheeled","acex_main","acex_m_veh_brdm","acex_t_veh_brdm"};
		version = "1.12.0.347";
	};
};
class WeaponCloudsMGun;
class CfgVehicles
{
	class BRDM2_Base;
	class BRDM2_ATGM_Base: BRDM2_Base
	{
		class Hitpoints;
		class Turrets;
		class MainTurret;
		class AnimationSources;
	};
	class ACE_BRDM2_ATGM_Base: BRDM2_ATGM_Base
	{
		model = "\x\acex\addons\m_veh_brdm\BRDM2_ATGM";
		driverAction = "BRDM2_Driver";
		driverInAction = "BRDM2_Driver";
		forceHideDriver = 1;
		forceHideGunner = 0;
		hideProxyInCombat = 1;
		threat[] = {0.5,0.75,0.1};
		class HitPoints: HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "karoserie";
				passThrough = 1;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerAction = "BRDM2_Gunner";
				gunnerInAction = "BRDM2_Gunner";
				forceHideGunner = 0;
				outGunnerMayFire = 0;
				viewGunnerInExternal = 0;
				gunnerOpticsModel = "\ca\weapons\2Dscope_ATGM";
				gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGunnerOutOptics = "gunnerview_ext";
				gunnerForceOptics = 0;
				gunnerOutForceOptics = 0;
				gunnerFireAlsoInInternalCamera = 0;
				LODTurnedOut = 1200;
			};
		};
		class AnimationSources: AnimationSources
		{
			class Launcher_reload
			{
				source = "reload";
				weapon = "ACE_AT5B_Launcher";
			};
			class Launcher_revolving
			{
				source = "revolving";
				weapon = "ACE_AT5B_Launcher";
			};
		};
	};
	class ACE_BRDM2_SA9_Base: ACE_BRDM2_ATGM_Base
	{
		displayName = "$STR_ACE_VDN_ACE_BRDM2_SA9_BASE";
		model = "\x\acex\addons\m_veh_brdm\BRDM2_SA9B";
		threat[] = {0,0,0.9};
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+8+16";
		class HitPoints: HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "karoserie";
				passThrough = 0;
			};
			class HitGlass1
			{
				armor = 0.4;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_9K31Launcher"};
				magazines[] = {"ACE_9M31_4","ACE_9M31_2"};
				minElev = -20;
				maxElev = 50;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				gunnerAction = "Mi17_Cargo02";
				gunnerInAction = "Mi17_Cargo02";
				forceHideGunner = 0;
				outGunnerMayFire = 0;
				viewGunnerInExternal = 1;
				gunnerOpticsModel = "x\acex\addons\m_veh_brdm\optika_9P31_gunner";
				gunnerOutOpticsModel = "x\acex\addons\m_veh_brdm\optika_9P31_gunner";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGunnerOutOptics = "gunnerview_ext";
				gunnerForceOptics = 0;
				gunnerOutForceOptics = 0;
				gunnerFireAlsoInInternalCamera = 1;
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.8;
						material = -1;
						name = "vez";
						visual = "turret";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 0.4;
						material = -1;
						name = "zbran";
						visual = "gun";
						passThrough = 0;
					};
				};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -45;
					maxAngleY = 45;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewOptics
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					initFov = 0.33333;
					minFov = "0.33333- 0.2";
					maxFov = "0.33333+ 0.4";
				};
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.33333;
						minFov = "0.33333- 0.2";
						maxFov = "0.33333+ 0.4";
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "x\acex\addons\m_veh_brdm\optika_9P31_gunner";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Launcher_reload
			{
				source = "reload";
				weapon = "ACE_9K31Launcher";
			};
			class Launcher_revolving
			{
				source = "revolving";
				weapon = "ACE_9K31Launcher";
			};
		};
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_brdm\9P31_01_co.paa","\ca\wheeled\data\brdm2_02_co.paa","\x\acex\addons\t_veh_brdm\9K31M_Launcher_co.paa","\x\acex\addons\t_veh_brdm\9P31_turret_co.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\brdm2\data\detailmapy\brdm2_01.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_01.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_01_destruct.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_02.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_02.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_02_destruct.rvmat","ca\wheeled_e\brdm2\data\brdm_in_base.rvmat","ca\wheeled_e\brdm2\data\brdm_in_base.rvmat","ca\wheeled_e\brdm2\data\brdm_in_base_destruct.rvmat","ca\wheeled_e\brdm2\data\brdm_in_second.rvmat","ca\wheeled_e\brdm2\data\brdm_in_second.rvmat","ca\wheeled_e\brdm2\data\brdm_in_second_destruct.rvmat","ca\wheeled_e\brdm2\data\brdm_in_forth.rvmat","ca\wheeled_e\brdm2\data\brdm_in_forth.rvmat","ca\wheeled_e\brdm2\data\brdm_in_forth_destruct.rvmat","ca\wheeled_e\brdm2\data\brdm_in_third.rvmat","ca\wheeled_e\brdm2\data\brdm_in_third.rvmat","ca\wheeled\data\brdm_in_third_destruct.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_atgm_01.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_atgm_01.rvmat","ca\wheeled_e\brdm2\data\detailmapy\brdm2_atgm_01_destruct.rvmat","x\acex\addons\c_veh_brdm\9P31_Turret.rvmat","x\acex\addons\c_veh_brdm\9P31_Turret.rvmat","x\acex\addons\c_veh_brdm\9P31_Turret_destruct.rvmat","x\acex\addons\c_veh_brdm\9P31_Launcher.rvmat","x\acex\addons\c_veh_brdm\9P31_Launcher.rvmat","x\acex\addons\c_veh_brdm\9P31_Launcher_destruct.rvmat"};
		};
	};
	class ACE_BRDM2_SA9_TK: ACE_BRDM2_SA9_Base
	{
		scope = 2;
		side = 0;
		faction = "BIS_TK";
		accuracy = 0.5;
		crew = "TK_Soldier_EP1";
		typicalCargo[] = {"TK_Soldier_EP1","TK_Soldier_EP1","TK_Soldier_EP1","TK_Soldier_EP1"};
		hiddenSelectionsTextures[] = {"\ca\wheeled_E\BRDM2\Data\BRDM2_01_TKA_CO.paa","\ca\wheeled\data\brdm2_02_co.paa","\x\acex\addons\t_veh_brdm\9K31M_Launcher_Dummy_co.paa","\x\acex\addons\t_veh_brdm\9P31_Turret_Dummy_co.paa"};
	};
};
//};
