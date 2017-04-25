////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Aug 11 06:51:21 2014 : Created on Mon Aug 11 06:51:21 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_su34 : config.bin{
class CfgPatches
{
	class acex_ru_veh_su34
	{
		units[] = {"ACE_Su34","ACE_Su34Wreck"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","acex_c_vehicle","Extended_EventHandlers","CAA10","CAAir3","CAAir3_Su34","CAWeapons","CA_Anims","CAData","acex_ru_m_veh_su34","acex_ru_t_veh_su34","acex_ru_c_veh_su_common","acex_ru_m_veh_su_common","acex_ru_t_veh_su_common"};
		version = "1.14.0.76";
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Su27_Pilot = "Su27_Pilot";
		Su27_Gunner = "Su27_Gunner";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Su27_Dead: DefaultDie
		{
			actions = "DeadActions";
			file = "\x\acex_ru\addons\c_veh_su27\Anim\KIA_Su27_Pilot.rtm";
			speed = "1e10";
			terminal = 0;
			soundEnabled = 1;
		};
		class Crew;
		class Su27_Pilot: Crew
		{
			file = "\x\acex_ru\addons\c_veh_su27\Anim\Su27_Pilot.rtm";
			connectTo[] = {"Su27_Dead",1};
		};
		class Su27_Gunner: Crew
		{
			file = "\x\acex_ru\addons\c_veh_su27\Anim\Su27_Pilot.rtm";
			connectTo[] = {"Su27_Dead",1};
		};
	};
};
class CfgVehicles
{
	class Air;
	class Plane: Air
	{
		class NewTurret;
		class ViewPilot;
	};
	class Su34: Plane
	{
		model = "\x\acex_ru\addons\m_veh_su34\aus_su34.p3d";
		icon = "\x\acex_ru\addons\c_veh_su34\data\icon\icon_su34_ca.paa";
		picture = "\x\acex_ru\addons\c_veh_su34\data\picture\picture_su34_ca.paa";
		weapons[] = {"ACE_GSh301","CMFlareLauncher"};
		magazines[] = {"ACE_180Rnd_30mm_GSh301","120Rnd_CMFlare_Chaff_Magazine"};
		ACE_hasAfterburner = 1;
		ace_afterburner_engines[] = {{1.14,-8.3,-1.0},{-1.14,-8.3,-1.0}};
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_MULTICREW = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ace_ejection_seat = "ACE_K36";
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_34.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
		damageResistance = 0.00168;
		class AnimationSources
		{
			class UserAB
			{
				source = "user";
				animPeriod = 1.0;
			};
			class UserDisplay
			{
				source = "user";
				animPeriod = 0.01;
			};
			class UserDisplayLoadout
			{
				source = "user";
				animPeriod = 0.01;
			};
			class UserWeapon
			{
				source = "user";
				animPeriod = 0.01;
			};
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				weapons[] = {"ACE_R73Launcher","ACE_R27Launcher","ACE_Kh29Launcher"};
				magazines[] = {"ACE_4Rnd_R73","ACE_6Rnd_Kh29","ACE_2Rnd_R27"};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_su_common\Su_skla.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_in.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_in_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_in_damage.rvmat","x\acex_ru\addons\c_veh_su34\Su34_01.rvmat","x\acex_ru\addons\c_veh_su34\Su34_01_damage.rvmat","x\acex_ru\addons\c_veh_su34\Su34_01_destruct.rvmat","x\acex_ru\addons\c_veh_su34\Su34_02.rvmat","x\acex_ru\addons\c_veh_su34\Su34_02_damage.rvmat","x\acex_ru\addons\c_veh_su34\Su34_02_destruct.rvmat","x\acex_ru\addons\c_veh_su_common\Su_interier.rvmat","x\acex_ru\addons\c_veh_su_common\Su_interier.rvmat","x\acex_ru\addons\c_veh_su_common\Su_interier_destruct.rvmat","x\acex_ru\addons\c_veh_su_common\Su_wheels.rvmat","x\acex_ru\addons\c_veh_su_common\Su_wheels_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_wheels_destruct.rvmat","x\acex_ru\addons\c_veh_su34\int_new.rvmat","x\acex_ru\addons\c_veh_su34\int_new_damage.rvmat","x\acex_ru\addons\c_veh_su34\int_new_destruct.rvmat","x\acex_ru\addons\c_veh_su34\Su34_int.rvmat","x\acex_ru\addons\c_veh_su34\Su34_int_damage.rvmat","x\acex_ru\addons\c_veh_su34\Su34_int_destruct.rvmat"};
		};
		hiddenSelections[] = {"Camo1","Camo2","num1","num2","num3","ExtraJAM","ExtraMH"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_su34\body1_co.paa","\x\acex_ru\addons\t_veh_su34\body2_co.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_B3_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_B8_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_B1_ca.paa"};
	};
	class ACE_Su34: Su34
	{
		scope = 1;
	};
	class ACE_Su34_MR: ACE_Su34
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_SU34_MR";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_R73Launcher","ACE_R27Launcher","ACE_Kh25Launcher","ACE_KAB500KRLauncher","ACE_KAB500LLauncher"};
				magazines[] = {"ACE_4Rnd_R73","ACE_2Rnd_Kh25","ACE_2Rnd_KAB500KR","ACE_2Rnd_KAB500L","ACE_2Rnd_R27"};
			};
		};
	};
	class ACE_Su34_Des: ACE_Su34
	{
		scope = 2;
		accuracy = 1000;
		vehicleClass = "ACE_AirD";
		crew = "ACE_RU_Soldier_Pilot_D";
		hiddenSelections[] = {"Camo1","Camo2","num1","num2","num3","ExtraJAM","ExtraMH"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_su34\body1_des_co.paa","\x\acex_ru\addons\t_veh_su34\body2_des_co.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R3_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R6_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R7_ca.paa"};
	};
	class ACE_Su34_MR_Des: ACE_Su34_MR
	{
		scope = 2;
		accuracy = 1000;
		vehicleClass = "ACE_AirD";
		crew = "ACE_RU_Soldier_Pilot_D";
		hiddenSelections[] = {"Camo1","Camo2","num1","num2","num3","ExtraJAM","ExtraMH"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_su34\body1_des_co.paa","\x\acex_ru\addons\t_veh_su34\body2_des_co.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R3_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R6_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R8_ca.paa"};
	};
	class PlaneWreck;
	class ACE_Su34_Wreck: PlaneWreck
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		model = "\ca\Air3\SU34\SU34Wreck.p3d";
		typicalCargo[] = {};
		irTarget = 0;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		transportSoldier = 2;
	};
};
//};
