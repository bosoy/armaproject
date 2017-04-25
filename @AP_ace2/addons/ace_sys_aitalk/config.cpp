////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:43:28 2013 : Created on Sat Apr 06 11:43:28 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_aitalk : config.bin{
class CfgPatches
{
	class ace_sys_aitalk
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.590";
		author[] = {"Xeno"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_aitalk
		{
			list[] = {"ace_sys_aitalk"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_aitalk
	{
		init = "call ('\x\ace\addons\sys_aitalk\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_aitalk
	{
		init = "call ('\x\ace\addons\sys_aitalk\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Hit_EventHandlers
{
	class CAManBase
	{
		ace_sys_aitalk = "if (!isNil 'ace_sys_aitalk_enabled') then {if ((alive (_this select 0)) && {(vehicle (_this select 0) == (_this select 0))} && {((_this select 0) != (_this select 1))}) then {_this call ace_sys_aitalk_fnc_hit}}";
	};
};
class Extended_FiredNear_EventHandlers
{
	class CAManBase
	{
		ace_sys_aitalk = "if (!isNil 'ace_sys_aitalk_enabled') then {if (local (_this select 0)) then {if ((alive (_this select 0)) && {(vehicle (_this select 0) == (_this select 0))} && {((_this select 0) != (_this select 1))}) then {_this call ace_sys_aitalk_fnc_firednear}}}";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		ace_sys_aitalk = "if (!isNil 'ace_sys_aitalk_enabled') then {if (local (_this select 0)) then {if ((alive (_this select 0)) && {(vehicle (_this select 0) == (_this select 0))}) then {_this call ace_sys_aitalk_fnc_fired}}}";
	};
};
class CfgFactionClasses
{
	class Default
	{
		ACE_Language = "Russian";
	};
	class USMC
	{
		ACE_Language = "English";
	};
	class CDF
	{
		ACE_Language = "Russian";
	};
	class RU
	{
		ACE_Language = "Russian";
	};
	class INS
	{
		ACE_Language = "Russian";
	};
	class GUE
	{
		ACE_Language = "Russian";
	};
	class CIV
	{
		ACE_Language = "Russian";
	};
	class CIV_RU
	{
		ACE_Language = "Russian";
	};
	class BIS_US
	{
		ACE_Language = "English";
	};
	class BIS_CZ
	{
		ACE_Language = "Russian";
	};
	class BIS_GER
	{
		ACE_Language = "English";
	};
	class BIS_TK
	{
		ACE_Language = "Arab";
	};
	class BIS_TK_INS
	{
		ACE_Language = "Arab";
	};
	class BIS_TK_GUE
	{
		ACE_Language = "Arab";
	};
	class BIS_UN
	{
		ACE_Language = "Russian";
	};
	class BIS_TK_CIV
	{
		ACE_Language = "Arab";
	};
	class None
	{
		ACE_Language = "Russian";
	};
	class BIS_BAF
	{
		ACE_Language = "English";
	};
	class PMC_BAF
	{
		ACE_Language = "English";
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_AITalk_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_AITALK_ENABLE";
		icon = "\x\ace\addons\sys_aitalk\data\icn\icon_sys_aitalk_ca.paa";
		picture = "\x\ace\addons\sys_aitalk\data\icn\icon_sys_aitalk_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_aitalk_enabled = true;publicVariable 'ace_sys_aitalk_enabled'};";
		};
	};
	class ACE_RadioTalk_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_RADIOTALK_ENABLE";
		icon = "\x\ace\addons\sys_aitalk\data\icn\icon_sys_radiotalk_ca.paa";
		picture = "\x\ace\addons\sys_aitalk\data\icn\icon_sys_radiotalk_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_aitalk_radio_enabled = true;publicVariable 'ace_sys_aitalk_radio_enabled'};";
		};
	};
};
class CfgSounds
{
	class ACE_ahem01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem01.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem02.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem03.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem04.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem05.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem06.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem07.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem08.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem09.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem10.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_ahem11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\ahem11.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_belch01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\belch01.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_belch02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\belch02.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_belch03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\belch03.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough01.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough02.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough03.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough04.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough05.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough06.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough07.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_cough08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\cough08.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh01.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh02.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh03.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh04.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh05.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh06.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh07.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh08.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh09.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_laugh10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\laugh10.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh01.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh02.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh03.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh04.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh05.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh06.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh07.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sigh08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sigh08.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sneeze01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sneeze01.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_sneeze02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\sneeze02.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_yawn01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\generic\yawn01.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_idle061
	{
		name = "ACE_us_idle061";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle061.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle062
	{
		name = "ACE_us_idle062";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle062.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle063
	{
		name = "ACE_us_idle063";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle063.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle064
	{
		name = "ACE_us_idle064";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle064.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle065
	{
		name = "ACE_us_idle065";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle065.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle066
	{
		name = "ACE_us_idle066";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle066.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle067
	{
		name = "ACE_us_idle067";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle067.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle068
	{
		name = "ACE_us_idle068";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle068.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle069
	{
		name = "ACE_us_idle069";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle069.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle070
	{
		name = "ACE_us_idle070";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle070.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle071
	{
		name = "ACE_us_idle071";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle071.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle072
	{
		name = "ACE_us_idle072";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle072.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle073
	{
		name = "ACE_us_idle073";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle073.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle074
	{
		name = "ACE_us_idle074";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle074.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle075
	{
		name = "ACE_us_idle075";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle075.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle076
	{
		name = "ACE_us_idle076";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle076.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle077
	{
		name = "ACE_us_idle077";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle077.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle078
	{
		name = "ACE_us_idle078";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle078.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle079
	{
		name = "ACE_us_idle079";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle079.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle080
	{
		name = "ACE_us_idle080";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle080.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle081
	{
		name = "ACE_us_idle081";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle081.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle082
	{
		name = "ACE_us_idle082";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle082.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle083
	{
		name = "ACE_us_idle083";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle083.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle084
	{
		name = "ACE_us_idle084";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle084.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle085
	{
		name = "ACE_us_idle085";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle085.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle086
	{
		name = "ACE_us_idle086";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle086.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle087
	{
		name = "ACE_us_idle087";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle087.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle088
	{
		name = "ACE_us_idle088";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle088.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle089
	{
		name = "ACE_us_idle089";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle089.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle090
	{
		name = "ACE_us_idle090";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle090.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle091
	{
		name = "ACE_us_idle091";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle091.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle092
	{
		name = "ACE_us_idle092";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle092.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle093
	{
		name = "ACE_us_idle093";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle093.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle094
	{
		name = "ACE_us_idle094";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle094.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle095
	{
		name = "ACE_us_idle095";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle095.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle096
	{
		name = "ACE_us_idle096";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle096.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle097
	{
		name = "ACE_us_idle097";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle097.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle098
	{
		name = "ACE_us_idle098";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle098.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle099
	{
		name = "ACE_us_idle099";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle099.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle100
	{
		name = "ACE_us_idle100";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle100.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle101
	{
		name = "ACE_us_idle101";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle101.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle102
	{
		name = "ACE_us_idle102";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle102.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle103
	{
		name = "ACE_us_idle103";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle103.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle104
	{
		name = "ACE_us_idle104";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle104.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle105
	{
		name = "ACE_us_idle105";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle105.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle106
	{
		name = "ACE_us_idle106";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle106.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle107
	{
		name = "ACE_us_idle107";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle107.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle108
	{
		name = "ACE_us_idle108";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle108.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle109
	{
		name = "ACE_us_idle109";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle109.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle110
	{
		name = "ACE_us_idle110";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle110.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle111
	{
		name = "ACE_us_idle111";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle111.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle112
	{
		name = "ACE_us_idle112";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle112.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle113
	{
		name = "ACE_us_idle113";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle113.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle114
	{
		name = "ACE_us_idle114";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle114.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle115
	{
		name = "ACE_us_idle115";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle115.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle116
	{
		name = "ACE_us_idle116";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle116.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle117
	{
		name = "ACE_us_idle117";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle117.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle118
	{
		name = "ACE_us_idle118";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle118.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle119
	{
		name = "ACE_us_idle119";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle119.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle120
	{
		name = "ACE_us_idle120";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle120.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle121
	{
		name = "ACE_us_idle121";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle121.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle122
	{
		name = "ACE_us_idle122";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle122.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle123
	{
		name = "ACE_us_idle123";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle123.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle124
	{
		name = "ACE_us_idle124";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle124.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle125
	{
		name = "ACE_us_idle125";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle125.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle126
	{
		name = "ACE_us_idle126";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle126.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle127
	{
		name = "ACE_us_idle127";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle127.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle128
	{
		name = "ACE_us_idle128";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle128.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle129
	{
		name = "ACE_us_idle129";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle129.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle130
	{
		name = "ACE_us_idle130";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle130.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle131
	{
		name = "ACE_us_idle131";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle131.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle132
	{
		name = "ACE_us_idle132";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle132.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle133
	{
		name = "ACE_us_idle133";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle133.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle134
	{
		name = "ACE_us_idle134";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle134.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle135
	{
		name = "ACE_us_idle135";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle135.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle136
	{
		name = "ACE_us_idle136";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle136.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle137
	{
		name = "ACE_us_idle137";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle137.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle138
	{
		name = "ACE_us_idle138";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle138.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle139
	{
		name = "ACE_us_idle139";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle139.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle140
	{
		name = "ACE_us_idle140";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle140.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle141
	{
		name = "ACE_us_idle141";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle141.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle142
	{
		name = "ACE_us_idle142";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle142.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle143
	{
		name = "ACE_us_idle143";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle143.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle144
	{
		name = "ACE_us_idle144";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle144.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle145
	{
		name = "ACE_us_idle145";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle145.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle146
	{
		name = "ACE_us_idle146";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle146.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle147
	{
		name = "ACE_us_idle147";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle147.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle148
	{
		name = "ACE_us_idle148";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle148.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle149
	{
		name = "ACE_us_idle149";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle149.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle150
	{
		name = "ACE_us_idle150";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle150.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle151
	{
		name = "ACE_us_idle151";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle151.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle152
	{
		name = "ACE_us_idle152";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle152.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle153
	{
		name = "ACE_us_idle153";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle153.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle154
	{
		name = "ACE_us_idle154";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle154.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle155
	{
		name = "ACE_us_idle155";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle155.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle156
	{
		name = "ACE_us_idle156";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle156.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle157
	{
		name = "ACE_us_idle157";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle157.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle158
	{
		name = "ACE_us_idle158";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle158.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle159
	{
		name = "ACE_us_idle159";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle159.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle160
	{
		name = "ACE_us_idle160";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle160.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle161
	{
		name = "ACE_us_idle161";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle161.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle162
	{
		name = "ACE_us_idle162";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle162.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle163
	{
		name = "ACE_us_idle163";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle163.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle164
	{
		name = "ACE_us_idle164";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle164.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle165
	{
		name = "ACE_us_idle165";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle165.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle166
	{
		name = "ACE_us_idle166";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle166.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle167
	{
		name = "ACE_us_idle167";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle167.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle168
	{
		name = "ACE_us_idle168";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle168.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle169
	{
		name = "ACE_us_idle169";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle169.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle170
	{
		name = "ACE_us_idle170";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle170.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle171
	{
		name = "ACE_us_idle171";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle171.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle172
	{
		name = "ACE_us_idle172";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle172.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle173
	{
		name = "ACE_us_idle173";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle173.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle174
	{
		name = "ACE_us_idle174";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle174.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle175
	{
		name = "ACE_us_idle175";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle175.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle176
	{
		name = "ACE_us_idle176";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle176.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle177
	{
		name = "ACE_us_idle177";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle177.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle178
	{
		name = "ACE_us_idle178";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle178.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle179
	{
		name = "ACE_us_idle179";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle179.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle180
	{
		name = "ACE_us_idle180";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle180.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle181
	{
		name = "ACE_us_idle181";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle181.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle182
	{
		name = "ACE_us_idle182";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle182.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle183
	{
		name = "ACE_us_idle183";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle183.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle184
	{
		name = "ACE_us_idle184";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle184.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle185
	{
		name = "ACE_us_idle185";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle185.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle186
	{
		name = "ACE_us_idle186";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle186.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle187
	{
		name = "ACE_us_idle187";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle187.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle188
	{
		name = "ACE_us_idle188";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle188.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle189
	{
		name = "ACE_us_idle189";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle189.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle190
	{
		name = "ACE_us_idle190";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle190.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle191
	{
		name = "ACE_us_idle191";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle191.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle192
	{
		name = "ACE_us_idle192";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle192.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle193
	{
		name = "ACE_us_idle193";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle193.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle194
	{
		name = "ACE_us_idle194";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle194.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle195
	{
		name = "ACE_us_idle195";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle195.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle196
	{
		name = "ACE_us_idle196";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle196.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle197
	{
		name = "ACE_us_idle197";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle197.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle198
	{
		name = "ACE_us_idle198";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle198.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle199
	{
		name = "ACE_us_idle199";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle199.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle200
	{
		name = "ACE_us_idle200";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle200.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle201
	{
		name = "ACE_us_idle201";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle201.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle202
	{
		name = "ACE_us_idle202";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle202.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle203
	{
		name = "ACE_us_idle203";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle203.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle204
	{
		name = "ACE_us_idle204";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle204.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle205
	{
		name = "ACE_us_idle205";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle205.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle206
	{
		name = "ACE_us_idle206";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle206.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle207
	{
		name = "ACE_us_idle207";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle207.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle208
	{
		name = "ACE_us_idle208";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle208.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle209
	{
		name = "ACE_us_idle209";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle209.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle210
	{
		name = "ACE_us_idle210";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle210.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle211
	{
		name = "ACE_us_idle211";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle211.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle212
	{
		name = "ACE_us_idle212";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle212.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle213
	{
		name = "ACE_us_idle213";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle213.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle214
	{
		name = "ACE_us_idle214";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle214.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle215
	{
		name = "ACE_us_idle215";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle215.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle216
	{
		name = "ACE_us_idle216";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle216.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle217
	{
		name = "ACE_us_idle217";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle217.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle218
	{
		name = "ACE_us_idle218";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle218.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle219
	{
		name = "ACE_us_idle219";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle219.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle220
	{
		name = "ACE_us_idle220";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle220.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle221
	{
		name = "ACE_us_idle221";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle221.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle222
	{
		name = "ACE_us_idle222";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle222.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle223
	{
		name = "ACE_us_idle223";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle223.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle224
	{
		name = "ACE_us_idle224";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle224.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle225
	{
		name = "ACE_us_idle225";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle225.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle226
	{
		name = "ACE_us_idle226";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle226.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle227
	{
		name = "ACE_us_idle227";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle227.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle228
	{
		name = "ACE_us_idle228";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle228.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle229
	{
		name = "ACE_us_idle229";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle229.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle230
	{
		name = "ACE_us_idle230";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle230.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle231
	{
		name = "ACE_us_idle231";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle231.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle232
	{
		name = "ACE_us_idle232";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle232.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle233
	{
		name = "ACE_us_idle233";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle233.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle234
	{
		name = "ACE_us_idle234";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle234.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle235
	{
		name = "ACE_us_idle235";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle235.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle236
	{
		name = "ACE_us_idle236";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle236.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle237
	{
		name = "ACE_us_idle237";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle237.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle238
	{
		name = "ACE_us_idle238";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle238.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle239
	{
		name = "ACE_us_idle239";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle239.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle240
	{
		name = "ACE_us_idle240";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle240.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle241
	{
		name = "ACE_us_idle241";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle241.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle242
	{
		name = "ACE_us_idle242";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle242.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle243
	{
		name = "ACE_us_idle243";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle243.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle244
	{
		name = "ACE_us_idle244";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle244.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle245
	{
		name = "ACE_us_idle245";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle245.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle246
	{
		name = "ACE_us_idle246";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle246.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle247
	{
		name = "ACE_us_idle247";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle247.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle248
	{
		name = "ACE_us_idle248";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle248.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle249
	{
		name = "ACE_us_idle249";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle249.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle250
	{
		name = "ACE_us_idle250";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle250.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle251
	{
		name = "ACE_us_idle251";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle251.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle252
	{
		name = "ACE_us_idle252";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle252.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle253
	{
		name = "ACE_us_idle253";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle253.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle254
	{
		name = "ACE_us_idle254";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle254.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle255
	{
		name = "ACE_us_idle255";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle255.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle256
	{
		name = "ACE_us_idle256";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle256.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle257
	{
		name = "ACE_us_idle257";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle257.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle258
	{
		name = "ACE_us_idle258";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle258.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle259
	{
		name = "ACE_us_idle259";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle259.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle260
	{
		name = "ACE_us_idle260";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle260.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle261
	{
		name = "ACE_us_idle261";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle261.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle262
	{
		name = "ACE_us_idle262";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle262.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle263
	{
		name = "ACE_us_idle263";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle263.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle264
	{
		name = "ACE_us_idle264";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle264.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle265
	{
		name = "ACE_us_idle265";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle265.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle266
	{
		name = "ACE_us_idle266";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle266.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle267
	{
		name = "ACE_us_idle267";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle267.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle268
	{
		name = "ACE_us_idle268";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle268.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle269
	{
		name = "ACE_us_idle269";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle269.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle270
	{
		name = "ACE_us_idle270";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle270.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle271
	{
		name = "ACE_us_idle271";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle271.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle272
	{
		name = "ACE_us_idle272";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle272.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle273
	{
		name = "ACE_us_idle273";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle273.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle274
	{
		name = "ACE_us_idle274";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle274.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle275
	{
		name = "ACE_us_idle275";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle275.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle276
	{
		name = "ACE_us_idle276";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle276.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle277
	{
		name = "ACE_us_idle277";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle277.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle278
	{
		name = "ACE_us_idle278";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle278.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle279
	{
		name = "ACE_us_idle279";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle279.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle280
	{
		name = "ACE_us_idle280";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle280.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle281
	{
		name = "ACE_us_idle281";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle281.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle282
	{
		name = "ACE_us_idle282";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle282.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle283
	{
		name = "ACE_us_idle283";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle283.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle284
	{
		name = "ACE_us_idle284";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle284.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle285
	{
		name = "ACE_us_idle285";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle285.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle286
	{
		name = "ACE_us_idle286";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle286.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle287
	{
		name = "ACE_us_idle287";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle287.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle288
	{
		name = "ACE_us_idle288";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle288.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle289
	{
		name = "ACE_us_idle289";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle289.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle290
	{
		name = "ACE_us_idle290";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle290.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle291
	{
		name = "ACE_us_idle291";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle291.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle292
	{
		name = "ACE_us_idle292";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle292.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle293
	{
		name = "ACE_us_idle293";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle293.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle294
	{
		name = "ACE_us_idle294";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle294.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle295
	{
		name = "ACE_us_idle295";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle295.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle296
	{
		name = "ACE_us_idle296";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle296.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle297
	{
		name = "ACE_us_idle297";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle297.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle298
	{
		name = "ACE_us_idle298";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle298.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle299
	{
		name = "ACE_us_idle299";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle299.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle300
	{
		name = "ACE_us_idle300";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle300.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle301
	{
		name = "ACE_us_idle301";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle301.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle302
	{
		name = "ACE_us_idle302";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle302.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle303
	{
		name = "ACE_us_idle303";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle303.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle304
	{
		name = "ACE_us_idle304";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle304.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle305
	{
		name = "ACE_us_idle305";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle305.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle306
	{
		name = "ACE_us_idle306";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle306.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle307
	{
		name = "ACE_us_idle307";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle307.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle308
	{
		name = "ACE_us_idle308";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle308.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle309
	{
		name = "ACE_us_idle309";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle309.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle310
	{
		name = "ACE_us_idle310";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle310.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle311
	{
		name = "ACE_us_idle311";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle311.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle312
	{
		name = "ACE_us_idle312";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle312.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle313
	{
		name = "ACE_us_idle313";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle313.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle314
	{
		name = "ACE_us_idle314";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle314.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle315
	{
		name = "ACE_us_idle315";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle315.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle316
	{
		name = "ACE_us_idle316";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle316.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle317
	{
		name = "ACE_us_idle317";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle317.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle318
	{
		name = "ACE_us_idle318";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle318.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle319
	{
		name = "ACE_us_idle319";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle319.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle320
	{
		name = "ACE_us_idle320";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle320.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle321
	{
		name = "ACE_us_idle321";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle321.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle322
	{
		name = "ACE_us_idle322";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle322.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle323
	{
		name = "ACE_us_idle323";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle323.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle324
	{
		name = "ACE_us_idle324";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle324.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle325
	{
		name = "ACE_us_idle325";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle325.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle326
	{
		name = "ACE_us_idle326";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle326.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle327
	{
		name = "ACE_us_idle327";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle327.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle328
	{
		name = "ACE_us_idle328";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle328.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle329
	{
		name = "ACE_us_idle329";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle329.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle330
	{
		name = "ACE_us_idle330";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle330.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle331
	{
		name = "ACE_us_idle331";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle331.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle332
	{
		name = "ACE_us_idle332";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle332.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle333
	{
		name = "ACE_us_idle333";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle333.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle334
	{
		name = "ACE_us_idle334";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle334.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle335
	{
		name = "ACE_us_idle335";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle335.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle336
	{
		name = "ACE_us_idle336";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle336.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle337
	{
		name = "ACE_us_idle337";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle337.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle338
	{
		name = "ACE_us_idle338";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle338.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle339
	{
		name = "ACE_us_idle339";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle339.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle340
	{
		name = "ACE_us_idle340";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle340.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle341
	{
		name = "ACE_us_idle341";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle341.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle342
	{
		name = "ACE_us_idle342";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle342.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle343
	{
		name = "ACE_us_idle343";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle343.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle344
	{
		name = "ACE_us_idle344";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle344.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle345
	{
		name = "ACE_us_idle345";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle345.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle346
	{
		name = "ACE_us_idle346";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle346.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle347
	{
		name = "ACE_us_idle347";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle347.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle348
	{
		name = "ACE_us_idle348";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle348.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle349
	{
		name = "ACE_us_idle349";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle349.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle350
	{
		name = "ACE_us_idle350";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle350.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle351
	{
		name = "ACE_us_idle351";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle351.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle352
	{
		name = "ACE_us_idle352";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle352.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle353
	{
		name = "ACE_us_idle353";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle353.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle354
	{
		name = "ACE_us_idle354";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle354.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle355
	{
		name = "ACE_us_idle355";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle355.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle356
	{
		name = "ACE_us_idle356";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle356.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle357
	{
		name = "ACE_us_idle357";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle357.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle358
	{
		name = "ACE_us_idle358";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle358.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle359
	{
		name = "ACE_us_idle359";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle359.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle360
	{
		name = "ACE_us_idle360";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle360.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle361
	{
		name = "ACE_us_idle361";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle361.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle362
	{
		name = "ACE_us_idle362";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle362.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle363
	{
		name = "ACE_us_idle363";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle363.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle364
	{
		name = "ACE_us_idle364";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle364.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle365
	{
		name = "ACE_us_idle365";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle365.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle366
	{
		name = "ACE_us_idle366";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle366.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle367
	{
		name = "ACE_us_idle367";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle367.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle368
	{
		name = "ACE_us_idle368";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle368.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle369
	{
		name = "ACE_us_idle369";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle369.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle370
	{
		name = "ACE_us_idle370";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle370.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle371
	{
		name = "ACE_us_idle371";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle371.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle372
	{
		name = "ACE_us_idle372";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle372.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle373
	{
		name = "ACE_us_idle373";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle373.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle374
	{
		name = "ACE_us_idle374";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle374.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle375
	{
		name = "ACE_us_idle375";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle375.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle376
	{
		name = "ACE_us_idle376";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle376.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle377
	{
		name = "ACE_us_idle377";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle377.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle378
	{
		name = "ACE_us_idle378";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle378.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle379
	{
		name = "ACE_us_idle379";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle379.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle380
	{
		name = "ACE_us_idle380";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle380.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle381
	{
		name = "ACE_us_idle381";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle381.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle382
	{
		name = "ACE_us_idle382";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle382.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle383
	{
		name = "ACE_us_idle383";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle383.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle384
	{
		name = "ACE_us_idle384";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle384.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle385
	{
		name = "ACE_us_idle385";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle385.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle386
	{
		name = "ACE_us_idle386";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle386.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle387
	{
		name = "ACE_us_idle387";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle387.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle388
	{
		name = "ACE_us_idle388";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle388.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle389
	{
		name = "ACE_us_idle389";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle389.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle390
	{
		name = "ACE_us_idle390";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle390.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle391
	{
		name = "ACE_us_idle391";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle391.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle392
	{
		name = "ACE_us_idle392";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle392.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle393
	{
		name = "ACE_us_idle393";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle393.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle394
	{
		name = "ACE_us_idle394";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle394.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle395
	{
		name = "ACE_us_idle395";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle395.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle396
	{
		name = "ACE_us_idle396";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle396.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle397
	{
		name = "ACE_us_idle397";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle397.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle398
	{
		name = "ACE_us_idle398";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle398.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle399
	{
		name = "ACE_us_idle399";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle399.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle400
	{
		name = "ACE_us_idle400";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle400.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle401
	{
		name = "ACE_us_idle401";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle401.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle402
	{
		name = "ACE_us_idle402";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle402.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle403
	{
		name = "ACE_us_idle403";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle403.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle404
	{
		name = "ACE_us_idle404";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle404.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle405
	{
		name = "ACE_us_idle405";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle405.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle406
	{
		name = "ACE_us_idle406";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle406.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle407
	{
		name = "ACE_us_idle407";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle407.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle408
	{
		name = "ACE_us_idle408";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle408.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle409
	{
		name = "ACE_us_idle409";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle409.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle410
	{
		name = "ACE_us_idle410";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle410.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle411
	{
		name = "ACE_us_idle411";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle411.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle412
	{
		name = "ACE_us_idle412";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle412.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle413
	{
		name = "ACE_us_idle413";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle413.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle414
	{
		name = "ACE_us_idle414";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle414.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle415
	{
		name = "ACE_us_idle415";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle415.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle416
	{
		name = "ACE_us_idle416";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle416.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle417
	{
		name = "ACE_us_idle417";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle417.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle418
	{
		name = "ACE_us_idle418";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle418.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle419
	{
		name = "ACE_us_idle419";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle419.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle420
	{
		name = "ACE_us_idle420";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle420.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle421
	{
		name = "ACE_us_idle421";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle421.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle422
	{
		name = "ACE_us_idle422";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle422.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle423
	{
		name = "ACE_us_idle423";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle423.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle424
	{
		name = "ACE_us_idle424";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle424.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle425
	{
		name = "ACE_us_idle425";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle425.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle426
	{
		name = "ACE_us_idle426";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle426.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle427
	{
		name = "ACE_us_idle427";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle427.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle428
	{
		name = "ACE_us_idle428";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle428.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle429
	{
		name = "ACE_us_idle429";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle429.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle430
	{
		name = "ACE_us_idle430";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle430.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle431
	{
		name = "ACE_us_idle431";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle431.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle432
	{
		name = "ACE_us_idle432";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle432.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle433
	{
		name = "ACE_us_idle433";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle433.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle434
	{
		name = "ACE_us_idle434";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle434.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle435
	{
		name = "ACE_us_idle435";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle435.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle436
	{
		name = "ACE_us_idle436";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle436.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle437
	{
		name = "ACE_us_idle437";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle437.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle438
	{
		name = "ACE_us_idle438";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle438.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle439
	{
		name = "ACE_us_idle439";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle439.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle440
	{
		name = "ACE_us_idle440";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle440.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle441
	{
		name = "ACE_us_idle441";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle441.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle442
	{
		name = "ACE_us_idle442";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle442.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle443
	{
		name = "ACE_us_idle443";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle443.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle444
	{
		name = "ACE_us_idle444";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle444.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle445
	{
		name = "ACE_us_idle445";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle445.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle446
	{
		name = "ACE_us_idle446";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle446.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle447
	{
		name = "ACE_us_idle447";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle447.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle448
	{
		name = "ACE_us_idle448";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle448.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle449
	{
		name = "ACE_us_idle449";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle449.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle450
	{
		name = "ACE_us_idle450";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle450.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle451
	{
		name = "ACE_us_idle451";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle451.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle452
	{
		name = "ACE_us_idle452";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle452.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle453
	{
		name = "ACE_us_idle453";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle453.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle454
	{
		name = "ACE_us_idle454";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle454.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle455
	{
		name = "ACE_us_idle455";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle455.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle456
	{
		name = "ACE_us_idle456";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle456.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle457
	{
		name = "ACE_us_idle457";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle457.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle458
	{
		name = "ACE_us_idle458";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle458.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_idle459
	{
		name = "ACE_us_idle459";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMIdle\us_idle459.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware036
	{
		name = "ACE_us_aware036";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware036.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware037
	{
		name = "ACE_us_aware037";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware037.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware038
	{
		name = "ACE_us_aware038";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware038.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware039
	{
		name = "ACE_us_aware039";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware039.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware040
	{
		name = "ACE_us_aware040";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware040.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware041
	{
		name = "ACE_us_aware041";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware041.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware042
	{
		name = "ACE_us_aware042";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware042.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware043
	{
		name = "ACE_us_aware043";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware043.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware044
	{
		name = "ACE_us_aware044";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware044.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware045
	{
		name = "ACE_us_aware045";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware045.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware046
	{
		name = "ACE_us_aware046";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware046.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware047
	{
		name = "ACE_us_aware047";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware047.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware048
	{
		name = "ACE_us_aware048";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware048.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware049
	{
		name = "ACE_us_aware049";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware049.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware050
	{
		name = "ACE_us_aware050";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware050.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware051
	{
		name = "ACE_us_aware051";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware051.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware052
	{
		name = "ACE_us_aware052";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware052.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware053
	{
		name = "ACE_us_aware053";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware053.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware054
	{
		name = "ACE_us_aware054";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware054.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware055
	{
		name = "ACE_us_aware055";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware055.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware056
	{
		name = "ACE_us_aware056";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware056.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware057
	{
		name = "ACE_us_aware057";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware057.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware058
	{
		name = "ACE_us_aware058";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware058.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware059
	{
		name = "ACE_us_aware059";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware059.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware060
	{
		name = "ACE_us_aware060";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware060.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware061
	{
		name = "ACE_us_aware061";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware061.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware062
	{
		name = "ACE_us_aware062";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware062.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware063
	{
		name = "ACE_us_aware063";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware063.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware064
	{
		name = "ACE_us_aware064";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware064.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware065
	{
		name = "ACE_us_aware065";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware065.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware066
	{
		name = "ACE_us_aware066";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware066.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware067
	{
		name = "ACE_us_aware067";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware067.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware068
	{
		name = "ACE_us_aware068";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware068.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware069
	{
		name = "ACE_us_aware069";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware069.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware070
	{
		name = "ACE_us_aware070";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware070.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware071
	{
		name = "ACE_us_aware071";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware071.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware072
	{
		name = "ACE_us_aware072";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware072.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware073
	{
		name = "ACE_us_aware073";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware073.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware074
	{
		name = "ACE_us_aware074";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware074.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware075
	{
		name = "ACE_us_aware075";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware075.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware076
	{
		name = "ACE_us_aware076";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware076.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware077
	{
		name = "ACE_us_aware077";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware077.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware078
	{
		name = "ACE_us_aware078";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware078.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware079
	{
		name = "ACE_us_aware079";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware079.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware080
	{
		name = "ACE_us_aware080";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware080.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware081
	{
		name = "ACE_us_aware081";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware081.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware082
	{
		name = "ACE_us_aware082";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware082.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware083
	{
		name = "ACE_us_aware083";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware083.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware084
	{
		name = "ACE_us_aware084";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware084.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware085
	{
		name = "ACE_us_aware085";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware085.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware086
	{
		name = "ACE_us_aware086";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware086.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware087
	{
		name = "ACE_us_aware087";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware087.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware088
	{
		name = "ACE_us_aware088";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware088.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware089
	{
		name = "ACE_us_aware089";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware089.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware090
	{
		name = "ACE_us_aware090";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware090.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware091
	{
		name = "ACE_us_aware091";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware091.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware092
	{
		name = "ACE_us_aware092";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware092.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware093
	{
		name = "ACE_us_aware093";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware093.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware094
	{
		name = "ACE_us_aware094";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware094.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware095
	{
		name = "ACE_us_aware095";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware095.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware096
	{
		name = "ACE_us_aware096";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware096.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware097
	{
		name = "ACE_us_aware097";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware097.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware098
	{
		name = "ACE_us_aware098";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware098.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware099
	{
		name = "ACE_us_aware099";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware099.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware100
	{
		name = "ACE_us_aware100";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware100.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware101
	{
		name = "ACE_us_aware101";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware101.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware102
	{
		name = "ACE_us_aware102";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware102.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware103
	{
		name = "ACE_us_aware103";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware103.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware104
	{
		name = "ACE_us_aware104";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware104.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware105
	{
		name = "ACE_us_aware105";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware105.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware106
	{
		name = "ACE_us_aware106";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware106.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware107
	{
		name = "ACE_us_aware107";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware107.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware108
	{
		name = "ACE_us_aware108";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware108.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware109
	{
		name = "ACE_us_aware109";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware109.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware110
	{
		name = "ACE_us_aware110";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware110.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware111
	{
		name = "ACE_us_aware111";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware111.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware112
	{
		name = "ACE_us_aware112";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware112.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware113
	{
		name = "ACE_us_aware113";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware113.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware114
	{
		name = "ACE_us_aware114";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware114.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware115
	{
		name = "ACE_us_aware115";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware115.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware116
	{
		name = "ACE_us_aware116";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware116.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware117
	{
		name = "ACE_us_aware117";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware117.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware118
	{
		name = "ACE_us_aware118";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware118.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware119
	{
		name = "ACE_us_aware119";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware119.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware120
	{
		name = "ACE_us_aware120";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware120.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware121
	{
		name = "ACE_us_aware121";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware121.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware122
	{
		name = "ACE_us_aware122";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware122.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware123
	{
		name = "ACE_us_aware123";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware123.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware124
	{
		name = "ACE_us_aware124";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware124.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware125
	{
		name = "ACE_us_aware125";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware125.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware126
	{
		name = "ACE_us_aware126";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware126.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware127
	{
		name = "ACE_us_aware127";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware127.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware128
	{
		name = "ACE_us_aware128";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware128.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware129
	{
		name = "ACE_us_aware129";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware129.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware130
	{
		name = "ACE_us_aware130";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware130.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware131
	{
		name = "ACE_us_aware131";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware131.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware132
	{
		name = "ACE_us_aware132";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware132.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware133
	{
		name = "ACE_us_aware133";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware133.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware134
	{
		name = "ACE_us_aware134";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware134.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware135
	{
		name = "ACE_us_aware135";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware135.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware136
	{
		name = "ACE_us_aware136";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware136.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware137
	{
		name = "ACE_us_aware137";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware137.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware138
	{
		name = "ACE_us_aware138";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware138.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware139
	{
		name = "ACE_us_aware139";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware139.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware140
	{
		name = "ACE_us_aware140";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware140.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware141
	{
		name = "ACE_us_aware141";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware141.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware142
	{
		name = "ACE_us_aware142";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware142.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware143
	{
		name = "ACE_us_aware143";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware143.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware144
	{
		name = "ACE_us_aware144";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware144.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware145
	{
		name = "ACE_us_aware145";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware145.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware146
	{
		name = "ACE_us_aware146";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware146.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware147
	{
		name = "ACE_us_aware147";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware147.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware148
	{
		name = "ACE_us_aware148";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware148.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware149
	{
		name = "ACE_us_aware149";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware149.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware150
	{
		name = "ACE_us_aware150";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware150.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware151
	{
		name = "ACE_us_aware151";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware151.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware152
	{
		name = "ACE_us_aware152";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware152.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware153
	{
		name = "ACE_us_aware153";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware153.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware154
	{
		name = "ACE_us_aware154";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware154.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware155
	{
		name = "ACE_us_aware155";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware155.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware156
	{
		name = "ACE_us_aware156";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware156.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware157
	{
		name = "ACE_us_aware157";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware157.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware158
	{
		name = "ACE_us_aware158";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware158.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware159
	{
		name = "ACE_us_aware159";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware159.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware160
	{
		name = "ACE_us_aware160";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware160.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware161
	{
		name = "ACE_us_aware161";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware161.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware162
	{
		name = "ACE_us_aware162";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware162.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware163
	{
		name = "ACE_us_aware163";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware163.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware164
	{
		name = "ACE_us_aware164";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware164.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware165
	{
		name = "ACE_us_aware165";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware165.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware166
	{
		name = "ACE_us_aware166";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware166.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware167
	{
		name = "ACE_us_aware167";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware167.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware168
	{
		name = "ACE_us_aware168";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware168.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware169
	{
		name = "ACE_us_aware169";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware169.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware170
	{
		name = "ACE_us_aware170";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware170.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware171
	{
		name = "ACE_us_aware171";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware171.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware172
	{
		name = "ACE_us_aware172";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware172.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware173
	{
		name = "ACE_us_aware173";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware173.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware174
	{
		name = "ACE_us_aware174";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware174.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware175
	{
		name = "ACE_us_aware175";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware175.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware176
	{
		name = "ACE_us_aware176";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware176.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware177
	{
		name = "ACE_us_aware177";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware177.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware178
	{
		name = "ACE_us_aware178";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware178.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware179
	{
		name = "ACE_us_aware179";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware179.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware180
	{
		name = "ACE_us_aware180";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware180.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware181
	{
		name = "ACE_us_aware181";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware181.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware182
	{
		name = "ACE_us_aware182";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware182.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware183
	{
		name = "ACE_us_aware183";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware183.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware184
	{
		name = "ACE_us_aware184";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware184.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware185
	{
		name = "ACE_us_aware185";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware185.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware186
	{
		name = "ACE_us_aware186";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware186.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware187
	{
		name = "ACE_us_aware187";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware187.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware188
	{
		name = "ACE_us_aware188";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware188.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware189
	{
		name = "ACE_us_aware189";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware189.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware190
	{
		name = "ACE_us_aware190";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware190.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware191
	{
		name = "ACE_us_aware191";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware191.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware192
	{
		name = "ACE_us_aware192";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware192.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware193
	{
		name = "ACE_us_aware193";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware193.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware194
	{
		name = "ACE_us_aware194";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware194.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware195
	{
		name = "ACE_us_aware195";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware195.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware196
	{
		name = "ACE_us_aware196";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware196.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware197
	{
		name = "ACE_us_aware197";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware197.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware198
	{
		name = "ACE_us_aware198";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware198.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware199
	{
		name = "ACE_us_aware199";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware199.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware200
	{
		name = "ACE_us_aware200";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware200.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware201
	{
		name = "ACE_us_aware201";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware201.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware202
	{
		name = "ACE_us_aware202";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware202.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware203
	{
		name = "ACE_us_aware203";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware203.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware204
	{
		name = "ACE_us_aware204";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware204.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware205
	{
		name = "ACE_us_aware205";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware205.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware206
	{
		name = "ACE_us_aware206";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware206.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware207
	{
		name = "ACE_us_aware207";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware207.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware208
	{
		name = "ACE_us_aware208";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware208.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware209
	{
		name = "ACE_us_aware209";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware209.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware210
	{
		name = "ACE_us_aware210";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware210.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware211
	{
		name = "ACE_us_aware211";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware211.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware212
	{
		name = "ACE_us_aware212";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware212.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware213
	{
		name = "ACE_us_aware213";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware213.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware214
	{
		name = "ACE_us_aware214";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware214.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware215
	{
		name = "ACE_us_aware215";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware215.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware216
	{
		name = "ACE_us_aware216";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware216.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware217
	{
		name = "ACE_us_aware217";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware217.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware218
	{
		name = "ACE_us_aware218";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware218.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware219
	{
		name = "ACE_us_aware219";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware219.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware220
	{
		name = "ACE_us_aware220";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware220.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware221
	{
		name = "ACE_us_aware221";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware221.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware222
	{
		name = "ACE_us_aware222";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware222.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware223
	{
		name = "ACE_us_aware223";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware223.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware224
	{
		name = "ACE_us_aware224";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware224.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware225
	{
		name = "ACE_us_aware225";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware225.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware226
	{
		name = "ACE_us_aware226";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware226.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware227
	{
		name = "ACE_us_aware227";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware227.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware228
	{
		name = "ACE_us_aware228";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware228.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware229
	{
		name = "ACE_us_aware229";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware229.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware230
	{
		name = "ACE_us_aware230";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware230.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware231
	{
		name = "ACE_us_aware231";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware231.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware232
	{
		name = "ACE_us_aware232";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware232.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware233
	{
		name = "ACE_us_aware233";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware233.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware234
	{
		name = "ACE_us_aware234";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware234.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware235
	{
		name = "ACE_us_aware235";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware235.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware236
	{
		name = "ACE_us_aware236";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware236.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware237
	{
		name = "ACE_us_aware237";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware237.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware238
	{
		name = "ACE_us_aware238";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware238.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware239
	{
		name = "ACE_us_aware239";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware239.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware240
	{
		name = "ACE_us_aware240";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware240.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware241
	{
		name = "ACE_us_aware241";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware241.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware242
	{
		name = "ACE_us_aware242";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware242.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware243
	{
		name = "ACE_us_aware243";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware243.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware244
	{
		name = "ACE_us_aware244";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware244.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware245
	{
		name = "ACE_us_aware245";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware245.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware246
	{
		name = "ACE_us_aware246";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware246.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware247
	{
		name = "ACE_us_aware247";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware247.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware248
	{
		name = "ACE_us_aware248";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware248.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware249
	{
		name = "ACE_us_aware249";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware249.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware250
	{
		name = "ACE_us_aware250";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware250.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware251
	{
		name = "ACE_us_aware251";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware251.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware252
	{
		name = "ACE_us_aware252";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware252.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware253
	{
		name = "ACE_us_aware253";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware253.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware254
	{
		name = "ACE_us_aware254";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware254.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware255
	{
		name = "ACE_us_aware255";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware255.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware256
	{
		name = "ACE_us_aware256";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware256.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware257
	{
		name = "ACE_us_aware257";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware257.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware258
	{
		name = "ACE_us_aware258";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware258.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware259
	{
		name = "ACE_us_aware259";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware259.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware260
	{
		name = "ACE_us_aware260";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware260.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware261
	{
		name = "ACE_us_aware261";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware261.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware262
	{
		name = "ACE_us_aware262";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware262.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware263
	{
		name = "ACE_us_aware263";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware263.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware264
	{
		name = "ACE_us_aware264";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware264.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware265
	{
		name = "ACE_us_aware265";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware265.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware266
	{
		name = "ACE_us_aware266";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware266.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware267
	{
		name = "ACE_us_aware267";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware267.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware268
	{
		name = "ACE_us_aware268";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware268.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware269
	{
		name = "ACE_us_aware269";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware269.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware270
	{
		name = "ACE_us_aware270";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware270.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware271
	{
		name = "ACE_us_aware271";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware271.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware272
	{
		name = "ACE_us_aware272";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware272.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware273
	{
		name = "ACE_us_aware273";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware273.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware274
	{
		name = "ACE_us_aware274";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware274.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware275
	{
		name = "ACE_us_aware275";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware275.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware276
	{
		name = "ACE_us_aware276";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware276.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware277
	{
		name = "ACE_us_aware277";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware277.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware278
	{
		name = "ACE_us_aware278";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware278.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_aware279
	{
		name = "ACE_us_aware279";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMAware\us_aware279.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_combat167
	{
		name = "ACE_us_combat167";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat167.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat168
	{
		name = "ACE_us_combat168";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat168.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat169
	{
		name = "ACE_us_combat169";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat169.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat170
	{
		name = "ACE_us_combat170";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat170.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat171
	{
		name = "ACE_us_combat171";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat171.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat172
	{
		name = "ACE_us_combat172";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat172.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat173
	{
		name = "ACE_us_combat173";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat173.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat174
	{
		name = "ACE_us_combat174";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat174.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat175
	{
		name = "ACE_us_combat175";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat175.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat176
	{
		name = "ACE_us_combat176";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat176.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat177
	{
		name = "ACE_us_combat177";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat177.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat178
	{
		name = "ACE_us_combat178";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat178.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat179
	{
		name = "ACE_us_combat179";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat179.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat180
	{
		name = "ACE_us_combat180";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat180.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat181
	{
		name = "ACE_us_combat181";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat181.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat182
	{
		name = "ACE_us_combat182";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat182.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat183
	{
		name = "ACE_us_combat183";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat183.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat184
	{
		name = "ACE_us_combat184";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat184.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat185
	{
		name = "ACE_us_combat185";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat185.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat186
	{
		name = "ACE_us_combat186";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat186.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat187
	{
		name = "ACE_us_combat187";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat187.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat188
	{
		name = "ACE_us_combat188";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat188.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat189
	{
		name = "ACE_us_combat189";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat189.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat190
	{
		name = "ACE_us_combat190";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat190.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat191
	{
		name = "ACE_us_combat191";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat191.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat192
	{
		name = "ACE_us_combat192";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat192.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat193
	{
		name = "ACE_us_combat193";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat193.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat194
	{
		name = "ACE_us_combat194";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat194.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat195
	{
		name = "ACE_us_combat195";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat195.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat196
	{
		name = "ACE_us_combat196";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat196.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat197
	{
		name = "ACE_us_combat197";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat197.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat198
	{
		name = "ACE_us_combat198";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat198.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat199
	{
		name = "ACE_us_combat199";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat199.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat200
	{
		name = "ACE_us_combat200";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat200.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat201
	{
		name = "ACE_us_combat201";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat201.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat202
	{
		name = "ACE_us_combat202";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat202.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat203
	{
		name = "ACE_us_combat203";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat203.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat204
	{
		name = "ACE_us_combat204";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat204.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat205
	{
		name = "ACE_us_combat205";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat205.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat206
	{
		name = "ACE_us_combat206";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat206.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat207
	{
		name = "ACE_us_combat207";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat207.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat208
	{
		name = "ACE_us_combat208";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat208.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat209
	{
		name = "ACE_us_combat209";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat209.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat210
	{
		name = "ACE_us_combat210";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat210.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat211
	{
		name = "ACE_us_combat211";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat211.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat212
	{
		name = "ACE_us_combat212";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat212.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat213
	{
		name = "ACE_us_combat213";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat213.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat214
	{
		name = "ACE_us_combat214";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat214.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat215
	{
		name = "ACE_us_combat215";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat215.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat216
	{
		name = "ACE_us_combat216";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat216.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat217
	{
		name = "ACE_us_combat217";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat217.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat218
	{
		name = "ACE_us_combat218";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat218.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat219
	{
		name = "ACE_us_combat219";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat219.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat220
	{
		name = "ACE_us_combat220";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat220.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat221
	{
		name = "ACE_us_combat221";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat221.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat222
	{
		name = "ACE_us_combat222";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat222.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat223
	{
		name = "ACE_us_combat223";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat223.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat224
	{
		name = "ACE_us_combat224";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat224.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat225
	{
		name = "ACE_us_combat225";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat225.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat226
	{
		name = "ACE_us_combat226";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat226.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat227
	{
		name = "ACE_us_combat227";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat227.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat228
	{
		name = "ACE_us_combat228";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat228.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat229
	{
		name = "ACE_us_combat229";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat229.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat230
	{
		name = "ACE_us_combat230";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat230.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat231
	{
		name = "ACE_us_combat231";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat231.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat232
	{
		name = "ACE_us_combat232";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat232.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat233
	{
		name = "ACE_us_combat233";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat233.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat234
	{
		name = "ACE_us_combat234";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat234.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat235
	{
		name = "ACE_us_combat235";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat235.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat236
	{
		name = "ACE_us_combat236";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat236.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat237
	{
		name = "ACE_us_combat237";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat237.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat238
	{
		name = "ACE_us_combat238";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat238.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat239
	{
		name = "ACE_us_combat239";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat239.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat240
	{
		name = "ACE_us_combat240";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat240.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat241
	{
		name = "ACE_us_combat241";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat241.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat242
	{
		name = "ACE_us_combat242";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat242.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat243
	{
		name = "ACE_us_combat243";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat243.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat244
	{
		name = "ACE_us_combat244";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat244.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat245
	{
		name = "ACE_us_combat245";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat245.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat246
	{
		name = "ACE_us_combat246";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat246.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat247
	{
		name = "ACE_us_combat247";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat247.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat248
	{
		name = "ACE_us_combat248";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat248.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat249
	{
		name = "ACE_us_combat249";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat249.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat250
	{
		name = "ACE_us_combat250";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat250.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat251
	{
		name = "ACE_us_combat251";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat251.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat252
	{
		name = "ACE_us_combat252";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat252.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat253
	{
		name = "ACE_us_combat253";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat253.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat254
	{
		name = "ACE_us_combat254";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat254.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat255
	{
		name = "ACE_us_combat255";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat255.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat256
	{
		name = "ACE_us_combat256";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat256.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat257
	{
		name = "ACE_us_combat257";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat257.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat258
	{
		name = "ACE_us_combat258";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat258.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat259
	{
		name = "ACE_us_combat259";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat259.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat260
	{
		name = "ACE_us_combat260";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat260.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat261
	{
		name = "ACE_us_combat261";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat261.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat262
	{
		name = "ACE_us_combat262";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat262.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat263
	{
		name = "ACE_us_combat263";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat263.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat264
	{
		name = "ACE_us_combat264";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat264.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat265
	{
		name = "ACE_us_combat265";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat265.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat266
	{
		name = "ACE_us_combat266";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat266.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat267
	{
		name = "ACE_us_combat267";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat267.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat268
	{
		name = "ACE_us_combat268";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat268.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat269
	{
		name = "ACE_us_combat269";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat269.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat270
	{
		name = "ACE_us_combat270";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat270.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat271
	{
		name = "ACE_us_combat271";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat271.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat272
	{
		name = "ACE_us_combat272";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat272.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat273
	{
		name = "ACE_us_combat273";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat273.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat274
	{
		name = "ACE_us_combat274";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat274.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat275
	{
		name = "ACE_us_combat275";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat275.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat276
	{
		name = "ACE_us_combat276";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat276.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat277
	{
		name = "ACE_us_combat277";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat277.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat278
	{
		name = "ACE_us_combat278";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat278.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat279
	{
		name = "ACE_us_combat279";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat279.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat280
	{
		name = "ACE_us_combat280";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat280.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat281
	{
		name = "ACE_us_combat281";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat281.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat282
	{
		name = "ACE_us_combat282";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat282.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat283
	{
		name = "ACE_us_combat283";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat283.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat284
	{
		name = "ACE_us_combat284";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat284.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat285
	{
		name = "ACE_us_combat285";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat285.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat286
	{
		name = "ACE_us_combat286";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat286.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat287
	{
		name = "ACE_us_combat287";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat287.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat288
	{
		name = "ACE_us_combat288";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat288.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat289
	{
		name = "ACE_us_combat289";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat289.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat290
	{
		name = "ACE_us_combat290";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat290.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat291
	{
		name = "ACE_us_combat291";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat291.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat292
	{
		name = "ACE_us_combat292";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat292.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat293
	{
		name = "ACE_us_combat293";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat293.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat294
	{
		name = "ACE_us_combat294";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat294.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat295
	{
		name = "ACE_us_combat295";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat295.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat296
	{
		name = "ACE_us_combat296";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat296.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat297
	{
		name = "ACE_us_combat297";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat297.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat298
	{
		name = "ACE_us_combat298";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat298.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat299
	{
		name = "ACE_us_combat299";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat299.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat300
	{
		name = "ACE_us_combat300";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat300.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat301
	{
		name = "ACE_us_combat301";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat301.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat302
	{
		name = "ACE_us_combat302";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat302.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat303
	{
		name = "ACE_us_combat303";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat303.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat304
	{
		name = "ACE_us_combat304";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat304.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat305
	{
		name = "ACE_us_combat305";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat305.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_combat306
	{
		name = "ACE_us_combat306";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMCombat\us_combat306.ogg","ACE_ACE_GENERAL_SPEECH_SOUND_LEVEL2",1};
		titles[] = {};
	};
	class ACE_us_detect052
	{
		name = "ACE_us_detect052";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect052.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect053
	{
		name = "ACE_us_detect053";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect053.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect054
	{
		name = "ACE_us_detect054";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect054.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect055
	{
		name = "ACE_us_detect055";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect055.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect056
	{
		name = "ACE_us_detect056";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect056.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect057
	{
		name = "ACE_us_detect057";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect057.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect058
	{
		name = "ACE_us_detect058";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect058.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect059
	{
		name = "ACE_us_detect059";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect059.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect060
	{
		name = "ACE_us_detect060";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect060.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect061
	{
		name = "ACE_us_detect061";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect061.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect062
	{
		name = "ACE_us_detect062";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect062.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect063
	{
		name = "ACE_us_detect063";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect063.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect064
	{
		name = "ACE_us_detect064";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect064.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect065
	{
		name = "ACE_us_detect065";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect065.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect066
	{
		name = "ACE_us_detect066";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect066.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect067
	{
		name = "ACE_us_detect067";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect067.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect068
	{
		name = "ACE_us_detect068";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect068.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect069
	{
		name = "ACE_us_detect069";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect069.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect070
	{
		name = "ACE_us_detect070";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect070.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect071
	{
		name = "ACE_us_detect071";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect071.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect072
	{
		name = "ACE_us_detect072";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect072.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect073
	{
		name = "ACE_us_detect073";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect073.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect074
	{
		name = "ACE_us_detect074";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect074.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect075
	{
		name = "ACE_us_detect075";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect075.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect076
	{
		name = "ACE_us_detect076";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect076.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect077
	{
		name = "ACE_us_detect077";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect077.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect078
	{
		name = "ACE_us_detect078";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect078.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect079
	{
		name = "ACE_us_detect079";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect079.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect080
	{
		name = "ACE_us_detect080";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect080.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect081
	{
		name = "ACE_us_detect081";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect081.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect082
	{
		name = "ACE_us_detect082";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect082.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect083
	{
		name = "ACE_us_detect083";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect083.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect084
	{
		name = "ACE_us_detect084";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect084.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect085
	{
		name = "ACE_us_detect085";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect085.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect086
	{
		name = "ACE_us_detect086";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect086.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect087
	{
		name = "ACE_us_detect087";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect087.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect088
	{
		name = "ACE_us_detect088";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect088.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect089
	{
		name = "ACE_us_detect089";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect089.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect090
	{
		name = "ACE_us_detect090";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect090.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect091
	{
		name = "ACE_us_detect091";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect091.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect092
	{
		name = "ACE_us_detect092";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect092.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect093
	{
		name = "ACE_us_detect093";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect093.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect094
	{
		name = "ACE_us_detect094";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect094.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect095
	{
		name = "ACE_us_detect095";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect095.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect096
	{
		name = "ACE_us_detect096";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect096.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect097
	{
		name = "ACE_us_detect097";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect097.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect098
	{
		name = "ACE_us_detect098";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect098.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect099
	{
		name = "ACE_us_detect099";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect099.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect100
	{
		name = "ACE_us_detect100";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect100.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect101
	{
		name = "ACE_us_detect101";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect101.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect102
	{
		name = "ACE_us_detect102";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect102.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect103
	{
		name = "ACE_us_detect103";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect103.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect104
	{
		name = "ACE_us_detect104";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect104.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect105
	{
		name = "ACE_us_detect105";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect105.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect106
	{
		name = "ACE_us_detect106";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect106.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect107
	{
		name = "ACE_us_detect107";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect107.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect108
	{
		name = "ACE_us_detect108";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect108.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect109
	{
		name = "ACE_us_detect109";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect109.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect110
	{
		name = "ACE_us_detect110";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect110.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect111
	{
		name = "ACE_us_detect111";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect111.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect112
	{
		name = "ACE_us_detect112";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect112.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect113
	{
		name = "ACE_us_detect113";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect113.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect114
	{
		name = "ACE_us_detect114";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect114.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect115
	{
		name = "ACE_us_detect115";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect115.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect116
	{
		name = "ACE_us_detect116";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect116.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect117
	{
		name = "ACE_us_detect117";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect117.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect118
	{
		name = "ACE_us_detect118";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect118.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect119
	{
		name = "ACE_us_detect119";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect119.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect120
	{
		name = "ACE_us_detect120";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect120.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect121
	{
		name = "ACE_us_detect121";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect121.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect122
	{
		name = "ACE_us_detect122";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect122.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect123
	{
		name = "ACE_us_detect123";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect123.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect124
	{
		name = "ACE_us_detect124";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect124.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect125
	{
		name = "ACE_us_detect125";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect125.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect126
	{
		name = "ACE_us_detect126";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect126.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect127
	{
		name = "ACE_us_detect127";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect127.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect128
	{
		name = "ACE_us_detect128";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect128.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect129
	{
		name = "ACE_us_detect129";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect129.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect130
	{
		name = "ACE_us_detect130";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect130.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect131
	{
		name = "ACE_us_detect131";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect131.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect132
	{
		name = "ACE_us_detect132";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect132.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect133
	{
		name = "ACE_us_detect133";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect133.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect134
	{
		name = "ACE_us_detect134";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect134.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect135
	{
		name = "ACE_us_detect135";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect135.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect136
	{
		name = "ACE_us_detect136";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect136.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect137
	{
		name = "ACE_us_detect137";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect137.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect138
	{
		name = "ACE_us_detect138";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect138.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect139
	{
		name = "ACE_us_detect139";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect139.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect140
	{
		name = "ACE_us_detect140";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect140.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect141
	{
		name = "ACE_us_detect141";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect141.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect142
	{
		name = "ACE_us_detect142";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect142.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect143
	{
		name = "ACE_us_detect143";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect143.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect144
	{
		name = "ACE_us_detect144";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect144.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect145
	{
		name = "ACE_us_detect145";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect145.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect146
	{
		name = "ACE_us_detect146";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect146.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect147
	{
		name = "ACE_us_detect147";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect147.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect148
	{
		name = "ACE_us_detect148";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect148.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect149
	{
		name = "ACE_us_detect149";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect149.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect150
	{
		name = "ACE_us_detect150";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect150.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect151
	{
		name = "ACE_us_detect151";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect151.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect152
	{
		name = "ACE_us_detect152";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect152.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect153
	{
		name = "ACE_us_detect153";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect153.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect154
	{
		name = "ACE_us_detect154";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect154.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect155
	{
		name = "ACE_us_detect155";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect155.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect156
	{
		name = "ACE_us_detect156";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect156.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_detect157
	{
		name = "ACE_us_detect157";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMContact\us_detect157.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_us_retreat014
	{
		name = "ACE_us_retreat014";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat014.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat015
	{
		name = "ACE_us_retreat015";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat015.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat016
	{
		name = "ACE_us_retreat016";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat016.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat017
	{
		name = "ACE_us_retreat017";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat017.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat018
	{
		name = "ACE_us_retreat018";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat018.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat019
	{
		name = "ACE_us_retreat019";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat019.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat020
	{
		name = "ACE_us_retreat020";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat020.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat021
	{
		name = "ACE_us_retreat021";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat021.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat022
	{
		name = "ACE_us_retreat022";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat022.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat023
	{
		name = "ACE_us_retreat023";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat023.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat024
	{
		name = "ACE_us_retreat024";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat024.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat025
	{
		name = "ACE_us_retreat025";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat025.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat026
	{
		name = "ACE_us_retreat026";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat026.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat027
	{
		name = "ACE_us_retreat027";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat027.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat028
	{
		name = "ACE_us_retreat028";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat028.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat029
	{
		name = "ACE_us_retreat029";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat029.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat030
	{
		name = "ACE_us_retreat030";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat030.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat031
	{
		name = "ACE_us_retreat031";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat031.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_us_retreat032
	{
		name = "ACE_us_retreat032";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\CAMFleeing\US_retreat032.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_RP_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\ROBERTPOLO\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\ROBERTPOLO\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\ROBERTPOLO\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\ROBERTPOLO\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\ROBERTPOLO\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\HOWARD\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\HOWARD\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\HOWARD\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\HOWARD\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\HOWARD\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\MATHEW\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\MATHEW\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\MATHEW\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\MATHEW\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\MATHEW\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\BRIAN\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\BRIAN\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\BRIAN\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\BRIAN\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\BRIAN\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DAN\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DAN\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DAN\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DAN\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DAN\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DUSAN\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DUSAN\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DUSAN\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DUSAN\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\DUSAN\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RUSSELL\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RUSSELL\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RUSSELL\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RUSSELL\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RUSSELL\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\JEFF\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\JEFF\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\JEFF\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\JEFF\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\JEFF\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_S_Univ_v55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RYAN\UNIV_v55.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_S_Univ_v56
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RYAN\UNIV_v56.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_S_Univ_v57
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RYAN\UNIV_v57.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_S_Univ_v62
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RYAN\UNIV_v62.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_S_Univ_v63
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Safe\RYAN\UNIV_v63.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\ROBERTPOLO\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\HOWARD\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\MATHEW\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\BRIAN\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DAN\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\DUSAN\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RUSSELL\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\JEFF\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v23.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v32.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v33.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v34.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v41.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v44.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v45.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v46.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v47.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v49.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_C_Univ_v65
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Combat\RYAN\UNIV_v65.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\ROBERTPOLO\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\ROBERTPOLO\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\ROBERTPOLO\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\ROBERTPOLO\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\ROBERTPOLO\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\ROBERTPOLO\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\HOWARD\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\HOWARD\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\HOWARD\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\HOWARD\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\HOWARD\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\HOWARD\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\BRIAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\BRIAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\BRIAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\BRIAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\BRIAN\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\BRIAN\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DAN\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DAN\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DUSAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DUSAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DUSAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DUSAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DUSAN\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\DUSAN\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\JEFF\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\JEFF\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\JEFF\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\JEFF\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\JEFF\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\JEFF\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\MATHEW\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\MATHEW\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\MATHEW\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\MATHEW\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\MATHEW\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\MATHEW\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RUSSELL\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RUSSELL\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RUSSELL\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RUSSELL\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RUSSELL\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RUSSELL\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_CO_Univ_v15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RYAN\UNIV_v15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_CO_Univ_v21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RYAN\UNIV_v21.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_CO_Univ_v22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RYAN\UNIV_v22.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_CO_Univ_v26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RYAN\UNIV_v26.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_CO_Univ_v37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RYAN\UNIV_v37.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_CO_Univ_v38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Contact\RYAN\UNIV_v38.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\ROBERTPOLO\UNIV_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\ROBERTPOLO\UNIV_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\ROBERTPOLO\UNIV_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\ROBERTPOLO\UNIV_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\HOWARD\UNIV_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\HOWARD\UNIV_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\HOWARD\UNIV_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\HOWARD\UNIV_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\BRIAN\Univ_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\BRIAN\Univ_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\BRIAN\Univ_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\BRIAN\Univ_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DAN\Univ_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DAN\Univ_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DAN\Univ_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DAN\Univ_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DUSAN\Univ_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DUSAN\Univ_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DUSAN\Univ_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\DUSAN\Univ_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\JEFF\Univ_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\JEFF\Univ_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\JEFF\Univ_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\JEFF\Univ_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\MATHEW\Univ_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\MATHEW\Univ_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\MATHEW\Univ_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\MATHEW\Univ_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RUSSELL\Univ_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RUSSELL\Univ_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RUSSELL\Univ_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RUSSELL\Univ_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_EK_Univ_v12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RYAN\Univ_v12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_EK_Univ_v27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RYAN\Univ_v27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_EK_Univ_v45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RYAN\Univ_v45.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_EK_Univ_v47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\EnemyKilled\RYAN\Univ_v47.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\ROBERTPOLO\UNIV_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\ROBERTPOLO\UNIV_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\ROBERTPOLO\UNIV_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\ROBERTPOLO\UNIV_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\ROBERTPOLO\UNIV_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\HOWARD\UNIV_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\HOWARD\UNIV_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\HOWARD\UNIV_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\HOWARD\UNIV_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\HOWARD\UNIV_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\BRIAN\Univ_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\BRIAN\Univ_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\BRIAN\Univ_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\BRIAN\Univ_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\BRIAN\Univ_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DAN\Univ_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DAN\Univ_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DAN\Univ_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DAN\Univ_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DAN\Univ_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DUSAN\Univ_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DUSAN\Univ_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DUSAN\Univ_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DUSAN\Univ_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\DUSAN\Univ_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\JEFF\Univ_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\JEFF\Univ_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\JEFF\Univ_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\JEFF\Univ_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\JEFF\Univ_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\MATHEW\Univ_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\MATHEW\Univ_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\MATHEW\Univ_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\MATHEW\Univ_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\MATHEW\Univ_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RUSSELL\Univ_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RUSSELL\Univ_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RUSSELL\Univ_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RUSSELL\Univ_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RUSSELL\Univ_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_F_Univ_v01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RYAN\Univ_v01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_F_Univ_v04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RYAN\Univ_v04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_F_Univ_v16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RYAN\Univ_v16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_F_Univ_v17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RYAN\Univ_v17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_F_Univ_v36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Fleeing\RYAN\Univ_v36.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\ROBERTPOLO\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\HOWARD\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\BRIAN\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DAN\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\DUSAN\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\JEFF\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\MATHEW\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RUSSELL\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v43.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v39.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v42.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v48.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v40.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_Misc_Univ_v30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Misc\RYAN\UNIV_v30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\ROBERTPOLO\UNIV_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\ROBERTPOLO\UNIV_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\ROBERTPOLO\UNIV_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\HOWARD\UNIV_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\HOWARD\UNIV_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\HOWARD\UNIV_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\BRIAN\Univ_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\BRIAN\Univ_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\BRIAN\Univ_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\DAN\Univ_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\DAN\Univ_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\DAN\Univ_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\DUSAN\Univ_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\DUSAN\Univ_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\DUSAN\Univ_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\JEFF\Univ_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\JEFF\Univ_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\JEFF\Univ_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\MATHEW\Univ_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\MATHEW\Univ_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\MATHEW\Univ_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\RUSSELL\Univ_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\RUSSELL\Univ_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\RUSSELL\Univ_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_OK_Univ_v10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\RYAN\Univ_v10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_OK_Univ_v11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\RYAN\Univ_v11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_OK_Univ_v18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\OwnKilled\RYAN\Univ_v18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\ROBERTPOLO\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\ROBERTPOLO\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\ROBERTPOLO\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\ROBERTPOLO\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\HOWARD\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\HOWARD\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\HOWARD\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_HO_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\HOWARD\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\BRIAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\BRIAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\BRIAN\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_BR_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\BRIAN\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DAN\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DA_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DAN\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DUSAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DUSAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DUSAN\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_DU_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\DUSAN\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\JEFF\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\JEFF\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\JEFF\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_JE_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\JEFF\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\MATHEW\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\MATHEW\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\MATHEW\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_MA_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\MATHEW\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RUSSELL\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RUSSELL\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RUSSELL\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RU_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RUSSELL\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_UF_UNIV_v28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RYAN\UNIV_v28.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_UF_UNIV_v29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RYAN\UNIV_v29.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_UF_UNIV_v52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RYAN\UNIV_v52.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RY_UF_UNIV_v53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\UnderFire\RYAN\UNIV_v53.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_RP_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\ROBERTPOLO\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_w_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\ROBERTPOLO\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_w_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\ROBERTPOLO\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_w_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\ROBERTPOLO\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RP_w_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\ROBERTPOLO\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\HOWARD\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_w_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\HOWARD\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_w_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\HOWARD\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_w_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\HOWARD\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_HO_w_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\HOWARD\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\BRIAN\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_W_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\BRIAN\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_W_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\BRIAN\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_W_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\BRIAN\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_BR_W_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\BRIAN\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DAN\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_W_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DAN\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_W_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DAN\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_W_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DAN\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DA_W_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DAN\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DUSAN\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_W_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DUSAN\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_W_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DUSAN\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_W_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DUSAN\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_DU_W_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\DUSAN\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\JEFF\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_W_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\JEFF\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_W_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\JEFF\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_W_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\JEFF\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_JE_W_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\JEFF\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\MATHEW\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_W_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\MATHEW\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_W_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\MATHEW\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_W_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\MATHEW\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_MA_W_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\MATHEW\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RUSSELL\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_W_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RUSSELL\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_W_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RUSSELL\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_W_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RUSSELL\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RU_W_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RUSSELL\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_W_Univ_v05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RYAN\UNIV_v05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_W_Univ_v06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RYAN\UNIV_v06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_W_Univ_v07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RYAN\UNIV_v07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_W_Univ_v50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RYAN\UNIV_v50.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_RY_W_Univ_v51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\eng\Wounded\RYAN\UNIV_v51.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat33
	{
		name = "ACE_rus_combat33";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat33.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat34
	{
		name = "ACE_rus_combat34";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat34.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat35
	{
		name = "ACE_rus_combat35";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat35.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat36
	{
		name = "ACE_rus_combat36";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat36.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat37
	{
		name = "ACE_rus_combat37";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat37.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat38
	{
		name = "ACE_rus_combat38";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat38.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat39
	{
		name = "ACE_rus_combat39";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat39.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat40
	{
		name = "ACE_rus_combat40";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat40.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat41
	{
		name = "ACE_rus_combat41";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat41.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat42
	{
		name = "ACE_rus_combat42";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat42.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat43
	{
		name = "ACE_rus_combat43";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat43.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat44
	{
		name = "ACE_rus_combat44";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat44.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat45
	{
		name = "ACE_rus_combat45";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat45.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat46
	{
		name = "ACE_rus_combat46";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat46.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat47
	{
		name = "ACE_rus_combat47";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat47.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat48
	{
		name = "ACE_rus_combat48";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat48.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat49
	{
		name = "ACE_rus_combat49";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat49.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat50
	{
		name = "ACE_rus_combat50";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat50.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat51
	{
		name = "ACE_rus_combat51";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat51.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat52
	{
		name = "ACE_rus_combat52";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat52.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat53
	{
		name = "ACE_rus_combat53";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat53.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat54
	{
		name = "ACE_rus_combat54";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat54.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat55
	{
		name = "ACE_rus_combat55";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat55.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat56
	{
		name = "ACE_rus_combat56";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat56.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat57
	{
		name = "ACE_rus_combat57";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat57.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat58
	{
		name = "ACE_rus_combat58";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat58.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat59
	{
		name = "ACE_rus_combat59";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat59.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat60
	{
		name = "ACE_rus_combat60";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat60.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat61
	{
		name = "ACE_rus_combat61";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat61.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat62
	{
		name = "ACE_rus_combat62";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat62.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat63
	{
		name = "ACE_rus_combat63";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat63.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat64
	{
		name = "ACE_rus_combat64";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat64.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat65
	{
		name = "ACE_rus_combat65";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat65.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat66
	{
		name = "ACE_rus_combat66";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat66.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat67
	{
		name = "ACE_rus_combat67";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat67.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat68
	{
		name = "ACE_rus_combat68";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat68.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat69
	{
		name = "ACE_rus_combat69";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat69.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat70
	{
		name = "ACE_rus_combat70";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat70.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat71
	{
		name = "ACE_rus_combat71";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat71.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat72
	{
		name = "ACE_rus_combat72";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat72.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat73
	{
		name = "ACE_rus_combat73";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat73.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat74
	{
		name = "ACE_rus_combat74";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat74.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat75
	{
		name = "ACE_rus_combat75";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat75.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat76
	{
		name = "ACE_rus_combat76";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat76.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat77
	{
		name = "ACE_rus_combat77";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat77.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat78
	{
		name = "ACE_rus_combat78";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat78.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat79
	{
		name = "ACE_rus_combat79";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat79.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat80
	{
		name = "ACE_rus_combat80";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat80.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat81
	{
		name = "ACE_rus_combat81";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat81.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat82
	{
		name = "ACE_rus_combat82";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat82.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat83
	{
		name = "ACE_rus_combat83";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat83.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat84
	{
		name = "ACE_rus_combat84";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat84.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat85
	{
		name = "ACE_rus_combat85";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat85.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat86
	{
		name = "ACE_rus_combat86";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat86.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat87
	{
		name = "ACE_rus_combat87";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat87.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat88
	{
		name = "ACE_rus_combat88";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat88.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat89
	{
		name = "ACE_rus_combat89";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat89.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat90
	{
		name = "ACE_rus_combat90";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat90.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat91
	{
		name = "ACE_rus_combat91";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat91.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat92
	{
		name = "ACE_rus_combat92";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat92.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat93
	{
		name = "ACE_rus_combat93";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat93.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat94
	{
		name = "ACE_rus_combat94";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat94.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat95
	{
		name = "ACE_rus_combat95";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat95.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat96
	{
		name = "ACE_rus_combat96";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat96.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat97
	{
		name = "ACE_rus_combat97";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat97.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat98
	{
		name = "ACE_rus_combat98";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat98.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat99
	{
		name = "ACE_rus_combat99";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat99.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat100
	{
		name = "ACE_rus_combat100";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat100.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat101
	{
		name = "ACE_rus_combat101";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat101.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat102
	{
		name = "ACE_rus_combat102";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat102.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat103
	{
		name = "ACE_rus_combat103";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat103.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat104
	{
		name = "ACE_rus_combat104";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat104.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat105
	{
		name = "ACE_rus_combat105";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat105.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat106
	{
		name = "ACE_rus_combat106";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat106.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat107
	{
		name = "ACE_rus_combat107";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat107.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat108
	{
		name = "ACE_rus_combat108";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat108.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat109
	{
		name = "ACE_rus_combat109";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat109.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat110
	{
		name = "ACE_rus_combat110";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat110.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat111
	{
		name = "ACE_rus_combat111";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat111.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat112
	{
		name = "ACE_rus_combat112";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat112.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat113
	{
		name = "ACE_rus_combat113";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat113.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat114
	{
		name = "ACE_rus_combat114";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat114.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat115
	{
		name = "ACE_rus_combat115";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat115.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat116
	{
		name = "ACE_rus_combat116";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat116.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat117
	{
		name = "ACE_rus_combat117";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat117.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat118
	{
		name = "ACE_rus_combat118";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat118.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat119
	{
		name = "ACE_rus_combat119";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat119.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat120
	{
		name = "ACE_rus_combat120";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat120.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat121
	{
		name = "ACE_rus_combat121";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat121.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat122
	{
		name = "ACE_rus_combat122";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat122.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat123
	{
		name = "ACE_rus_combat123";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat123.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat124
	{
		name = "ACE_rus_combat124";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat124.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat125
	{
		name = "ACE_rus_combat125";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat125.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat126
	{
		name = "ACE_rus_combat126";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat126.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat127
	{
		name = "ACE_rus_combat127";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat127.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat128
	{
		name = "ACE_rus_combat128";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat128.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat129
	{
		name = "ACE_rus_combat129";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat129.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat130
	{
		name = "ACE_rus_combat130";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat130.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat131
	{
		name = "ACE_rus_combat131";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat131.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat132
	{
		name = "ACE_rus_combat132";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat132.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat133
	{
		name = "ACE_rus_combat133";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat133.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat134
	{
		name = "ACE_rus_combat134";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat134.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat135
	{
		name = "ACE_rus_combat135";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat135.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat136
	{
		name = "ACE_rus_combat136";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat136.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat137
	{
		name = "ACE_rus_combat137";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat137.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat138
	{
		name = "ACE_rus_combat138";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat138.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat139
	{
		name = "ACE_rus_combat139";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat139.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat140
	{
		name = "ACE_rus_combat140";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat140.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat141
	{
		name = "ACE_rus_combat141";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat141.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat142
	{
		name = "ACE_rus_combat142";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat142.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat143
	{
		name = "ACE_rus_combat143";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat143.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat144
	{
		name = "ACE_rus_combat144";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat144.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat145
	{
		name = "ACE_rus_combat145";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat145.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat146
	{
		name = "ACE_rus_combat146";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat146.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat147
	{
		name = "ACE_rus_combat147";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat147.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat148
	{
		name = "ACE_rus_combat148";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat148.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat149
	{
		name = "ACE_rus_combat149";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat149.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat150
	{
		name = "ACE_rus_combat150";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat150.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat151
	{
		name = "ACE_rus_combat151";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat151.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat152
	{
		name = "ACE_rus_combat152";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat152.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat153
	{
		name = "ACE_rus_combat153";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat153.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat154
	{
		name = "ACE_rus_combat154";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat154.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat155
	{
		name = "ACE_rus_combat155";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat155.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat156
	{
		name = "ACE_rus_combat156";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat156.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat157
	{
		name = "ACE_rus_combat157";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat157.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat158
	{
		name = "ACE_rus_combat158";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat158.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat159
	{
		name = "ACE_rus_combat159";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat159.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat160
	{
		name = "ACE_rus_combat160";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat160.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat161
	{
		name = "ACE_rus_combat161";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat161.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat162
	{
		name = "ACE_rus_combat162";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat162.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat163
	{
		name = "ACE_rus_combat163";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat163.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat164
	{
		name = "ACE_rus_combat164";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat164.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat165
	{
		name = "ACE_rus_combat165";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat165.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat166
	{
		name = "ACE_rus_combat166";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat166.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat167
	{
		name = "ACE_rus_combat167";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat167.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat168
	{
		name = "ACE_rus_combat168";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat168.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat169
	{
		name = "ACE_rus_combat169";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat169.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat170
	{
		name = "ACE_rus_combat170";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat170.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat171
	{
		name = "ACE_rus_combat171";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat171.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat172
	{
		name = "ACE_rus_combat172";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat172.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat173
	{
		name = "ACE_rus_combat173";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat173.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat174
	{
		name = "ACE_rus_combat174";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat174.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat175
	{
		name = "ACE_rus_combat175";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat175.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat176
	{
		name = "ACE_rus_combat176";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat176.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat177
	{
		name = "ACE_rus_combat177";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat177.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat178
	{
		name = "ACE_rus_combat178";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat178.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat179
	{
		name = "ACE_rus_combat179";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat179.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat180
	{
		name = "ACE_rus_combat180";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat180.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat181
	{
		name = "ACE_rus_combat181";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat181.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat182
	{
		name = "ACE_rus_combat182";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat182.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat183
	{
		name = "ACE_rus_combat183";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat183.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat184
	{
		name = "ACE_rus_combat184";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat184.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat185
	{
		name = "ACE_rus_combat185";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat185.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat186
	{
		name = "ACE_rus_combat186";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat186.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat187
	{
		name = "ACE_rus_combat187";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat187.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat188
	{
		name = "ACE_rus_combat188";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat188.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat189
	{
		name = "ACE_rus_combat189";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat189.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat190
	{
		name = "ACE_rus_combat190";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat190.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat191
	{
		name = "ACE_rus_combat191";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat191.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat192
	{
		name = "ACE_rus_combat192";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat192.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat193
	{
		name = "ACE_rus_combat193";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat193.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat194
	{
		name = "ACE_rus_combat194";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat194.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat195
	{
		name = "ACE_rus_combat195";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat195.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat196
	{
		name = "ACE_rus_combat196";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat196.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat197
	{
		name = "ACE_rus_combat197";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat197.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat198
	{
		name = "ACE_rus_combat198";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat198.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat199
	{
		name = "ACE_rus_combat199";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat199.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat200
	{
		name = "ACE_rus_combat200";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat200.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat201
	{
		name = "ACE_rus_combat201";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat201.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat202
	{
		name = "ACE_rus_combat202";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat202.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat203
	{
		name = "ACE_rus_combat203";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat203.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat204
	{
		name = "ACE_rus_combat204";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat204.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat205
	{
		name = "ACE_rus_combat205";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat205.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat206
	{
		name = "ACE_rus_combat206";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat206.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat207
	{
		name = "ACE_rus_combat207";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat207.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat208
	{
		name = "ACE_rus_combat208";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat208.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat209
	{
		name = "ACE_rus_combat209";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat209.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_combat210
	{
		name = "ACE_rus_combat210";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Combat\rus_combat210.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_aware030
	{
		name = "ACE_rus_aware030";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware030.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware031
	{
		name = "ACE_rus_aware031";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware031.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware032
	{
		name = "ACE_rus_aware032";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware032.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware033
	{
		name = "ACE_rus_aware033";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware033.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware034
	{
		name = "ACE_rus_aware034";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware034.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware035
	{
		name = "ACE_rus_aware035";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware035.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware036
	{
		name = "ACE_rus_aware036";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware036.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware037
	{
		name = "ACE_rus_aware037";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware037.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware038
	{
		name = "ACE_rus_aware038";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware038.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware039
	{
		name = "ACE_rus_aware039";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware039.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware040
	{
		name = "ACE_rus_aware040";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware040.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware041
	{
		name = "ACE_rus_aware041";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware041.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware042
	{
		name = "ACE_rus_aware042";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware042.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware043
	{
		name = "ACE_rus_aware043";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware043.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware044
	{
		name = "ACE_rus_aware044";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware044.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware045
	{
		name = "ACE_rus_aware045";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware045.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware046
	{
		name = "ACE_rus_aware046";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware046.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware047
	{
		name = "ACE_rus_aware047";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware047.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware048
	{
		name = "ACE_rus_aware048";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware048.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_aware049
	{
		name = "ACE_rus_aware049";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Aware\rus_aware049.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idlevodka1
	{
		name = "ACE_rus_idlevodka1";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_vodka1.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idlevodka2
	{
		name = "ACE_rus_idlevodka2";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_vodka2.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle052
	{
		name = "ACE_rus_idle052";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle052.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle053
	{
		name = "ACE_rus_idle053";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle053.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle054
	{
		name = "ACE_rus_idle054";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle054.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle055
	{
		name = "ACE_rus_idle055";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle055.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle056
	{
		name = "ACE_rus_idle056";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle056.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle057
	{
		name = "ACE_rus_idle057";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle057.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle058
	{
		name = "ACE_rus_idle058";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle058.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle059
	{
		name = "ACE_rus_idle059";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle059.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_idle060
	{
		name = "ACE_rus_idle060";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_idle\rus_idle060.ogg","db-25",1};
		titles[] = {};
	};
	class ACE_rus_detect18
	{
		name = "ACE_rus_detect18";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect18.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect19
	{
		name = "ACE_rus_detect19";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect19.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect20
	{
		name = "ACE_rus_detect20";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect20.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect21
	{
		name = "ACE_rus_detect21";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect21.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect22
	{
		name = "ACE_rus_detect22";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect22.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect23
	{
		name = "ACE_rus_detect23";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect23.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect24
	{
		name = "ACE_rus_detect24";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect24.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect25
	{
		name = "ACE_rus_detect25";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect25.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect26
	{
		name = "ACE_rus_detect26";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect26.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect27
	{
		name = "ACE_rus_detect27";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect27.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect28
	{
		name = "ACE_rus_detect28";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect28.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect29
	{
		name = "ACE_rus_detect29";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect29.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect30
	{
		name = "ACE_rus_detect30";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect30.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect31
	{
		name = "ACE_rus_detect31";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect31.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect32
	{
		name = "ACE_rus_detect32";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect32.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect33
	{
		name = "ACE_rus_detect33";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect33.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect34
	{
		name = "ACE_rus_detect34";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect34.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect35
	{
		name = "ACE_rus_detect35";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect35.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect36
	{
		name = "ACE_rus_detect36";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect36.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect37
	{
		name = "ACE_rus_detect37";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect37.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect38
	{
		name = "ACE_rus_detect38";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect38.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect39
	{
		name = "ACE_rus_detect39";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect39.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect40
	{
		name = "ACE_rus_detect40";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect40.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect41
	{
		name = "ACE_rus_detect41";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect41.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect42
	{
		name = "ACE_rus_detect42";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect42.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect43
	{
		name = "ACE_rus_detect43";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect43.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect44
	{
		name = "ACE_rus_detect44";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect44.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect45
	{
		name = "ACE_rus_detect45";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect45.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect46
	{
		name = "ACE_rus_detect46";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect46.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect47
	{
		name = "ACE_rus_detect47";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect47.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect48
	{
		name = "ACE_rus_detect48";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect48.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect49
	{
		name = "ACE_rus_detect49";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect49.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect50
	{
		name = "ACE_rus_detect50";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect50.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_detect51
	{
		name = "ACE_rus_detect51";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\CAMRus_Contact\rus_detect51.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_rus_idle001
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle001.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle002
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle002.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle003
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle003.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle004
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle004.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle005
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle005.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle006
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle006.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle007
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle007.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle008
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle008.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle009
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle009.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle010
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle010.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle011
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle011.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle012
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle012.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle013
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle013.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle014
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle014.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle015
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle015.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle016
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle016.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle017
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle017.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle018
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle018.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle019
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle019.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle020
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle020.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle021
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle021.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle022
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle022.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle023
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle023.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle024
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle024.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle025
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle025.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle026
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle026.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle027
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle027.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle028
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle028.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle029
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle029.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_idle030
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_idle\rus_idle030.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware08.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware09.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware14.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware15.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware19
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware19.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware20
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware20.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware21.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware22.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware23.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware24
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware24.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware25
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware25.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware26.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware28.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_aware29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_aware\rus_aware29.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat08.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat09.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat14.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat15.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat17.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat18.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat19
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat19.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat20
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat20.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat21.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat22.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat23.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat24
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat24.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat25
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat25.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat26.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat27.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat28.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat29.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat30.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat31
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat31.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_combat32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_combat\rus_combat32.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_rus_wounded1
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_extra\rus_amerikanskije.wss","db-20",1.0};
		titles[] = {};
	};
	class ACE_rus_wounded2
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_extra\rus_mamocka.wss","db-20",1.0};
		titles[] = {};
	};
	class ACE_rus_wounded3
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_extra\rus_trevoga.wss","db-20",1.0};
		titles[] = {};
	};
	class ACE_rus_wounded4
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_extra\rus_vperjod.wss","db-20",1.0};
		titles[] = {};
	};
	class ACE_rus_wounded5
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_extra\rus_zdescisto.wss","db-20",1.0};
		titles[] = {};
	};
	class ACE_rus_begite
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\rus\rus_extra\rus_begite.wss","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_coverme_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_coverme_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_coverme_01b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_coverme_01b.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_coverme_01c
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_coverme_01c.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_coverme_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_coverme_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_suppress_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_suppress_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_suppress_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_suppress_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_suppress_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_suppress_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_suppress_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_suppress_04.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_suppress_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_suppress_05.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_suppress_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_suppress_07.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_suppress_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_action_suppress_08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_04.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_05.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_06.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_07.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_11.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_attack_infantry_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_attack_infantry_12.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_armoredvehicle_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_armoredvehicle_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_armoredvehicle_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_armoredvehicle_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_barrels_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_barrels_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_barrels_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_barrels_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_barrels_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_barrels_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_barricade_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_barricade_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_barricade_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_barricade_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_barricade_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_barricade_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_barricade_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_barricade_04.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_boxes_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_boxes_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_boxes_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_boxes_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_boxes_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_boxes_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_cover_boxes_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_order_cover_boxes_04.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_04.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_05.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_06.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_07.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_08.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_10.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_11.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_12.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_13.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_14.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_generic_15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_combat\4\AB_4_threat_infantry_generic_15.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_01b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_01b.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_02b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_02b.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_03b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_03b.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_04.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_04b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_04b.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_05.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_05b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_05b.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_06.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_threat_infantry_exposed_06b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_contact\AB_4_threat_infantry_exposed_06b.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_generic_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_generic_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_generic_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_generic_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_generic_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_generic_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_08.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_09.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_11.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_12.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_13.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_14.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_15.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_killfirm_infantry_16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_enemykilled\4\AB_4_inform_killfirm_infantry_16.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_08.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_09.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_attack_grenade_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_inform_attack_grenade_10.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_grenade_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_grenade\4\AB_4_order_action_grenade_08.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_action_boost_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_firing\4\AB_4_order_action_boost_08.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_follow_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_follow_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_follow_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_follow_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_follow_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_follow_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_follow_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_follow_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_follow_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_follow_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_forward_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_forward_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_forward_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_forward_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_forward_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_forward_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_forward_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_forward_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_forward_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_forward_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_forward_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_forward_06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_generic_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_generic_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_generic_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_generic_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_generic_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_generic_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_generic_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_generic_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_generic_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_generic_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_generic_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_generic_06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_order_move_generic_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_formationleader\4\AB_4_order_move_generic_07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_01b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_01b.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_02b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_02b.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_02c
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_02c.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_02e
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_02e.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_03b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_03b.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_reaction_casualty_generic_04b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_ownkilled\4\AB_4_reaction_casualty_generic_04b.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_suppressed_generic_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_underfire\4\AB_4_inform_suppressed_generic_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_suppressed_generic_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_underfire\4\AB_4_inform_suppressed_generic_02.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_suppressed_generic_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_underfire\4\AB_4_inform_suppressed_generic_03.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_suppressed_generic_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_underfire\4\AB_4_inform_suppressed_generic_07.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_suppressed_generic_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_underfire\4\AB_4_inform_suppressed_generic_09.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_AB_4_inform_suppressed_generic_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_underfire\4\AB_4_inform_suppressed_generic_01.ogg","db-20",1.0};
		titles[] = {};
	};
	class ACE_ab4_death_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_death_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_death_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_death_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_death_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_death_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_death_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_death_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_death_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_death_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_meleeattack_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_meleeattack_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_meleeattack_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_meleeattack_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_meleecharge_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_meleecharge_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_meleecharge_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_meleecharge_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_pain_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_pain_01.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_pain_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_pain_02.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_pain_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_pain_03.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_pain_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_pain_04.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_pain_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_pain_05.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_pain_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_pain_06.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_ab4_pain_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\voices\arab\arab_wounded\4\ab4_pain_07.ogg","db-25",1.0};
		titles[] = {};
	};
	class ACE_us_mrn_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_01.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_02.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_03.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_04.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_05.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_06.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_07.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_08.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_09.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_10.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_11.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_12.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_13.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_mrn_14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_land_rc\us_mrn_14.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_01.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_02.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_03.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_04.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_05.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_06.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_07.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_08.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_09.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_10.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_11.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_12.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_13.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_14.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_15.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_16.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_17.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_18.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_19
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_19.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_20
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_20.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_21.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_22.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_23.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_24
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_24.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_25
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_25.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_26.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_27.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_28.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_29.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_30.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_31
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_31.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_32.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_33.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_34.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_35
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_35.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_36.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_37.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_rus_land_rc_38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\rus_land_rc\rus_land_rc_38.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_01.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_02.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_03.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_04.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_05.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_06.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_07.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_08.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_09.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_10.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_11.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_12.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_13.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_14.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_15.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_16.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_17.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_18.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_19
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_19.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_20
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_20.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_21.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_22.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_23.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_24
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_24.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_25
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_25.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_26.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_27.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_28.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_29.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_30.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_31
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_31.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_32.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_33.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_34.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_35
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_35.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_36.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_37.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_38.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_39.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_40.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_41.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_42.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_43.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_land_rc_44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_land_rc\us_alpha_44.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_01.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_02.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_03.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_04.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_05.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_06.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_07.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_08.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_09.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_10.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_11.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_12.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_13.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_14.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_15.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_16.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_17.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_18.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_19
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_19.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_20
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_20.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_21.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_22.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_23.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_24
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_24.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_25
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_25.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_26.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_27.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_gb_attk_28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\gb_attk_28.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_01.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_02.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_03.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_04.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_05.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_06.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_07.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_08.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_09.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_10.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_11.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_12.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_13.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_14
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_14.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_15
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_15.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_16
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_16.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_17
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_17.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_18
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_18.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_19
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_19.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_20
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_20.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_21
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_21.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_22
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_22.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_23
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_23.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_24
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_24.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_25
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_25.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_26
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_26.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_27
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_27.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_28
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_28.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_29
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_29.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_30
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_30.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_31
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_31.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_32
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_32.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_33
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_33.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_34
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_34.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_35
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_35.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_36
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_36.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_37
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_37.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_38
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_38.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_39
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_39.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_40
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_40.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_41
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_41.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_42
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_42.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_43
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_43.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_44
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_44.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_45
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_45.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_46
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_46.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_47
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_47.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_48
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_48.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_49
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_49.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_50
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_50.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_51
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_51.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_52
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_52.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_53
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_53.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_54
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_54.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_air_gen_55
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_air_gen_55.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_01.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_01a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_01a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_01b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_01b.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_02.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_02a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_02a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_02b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_02b.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_03.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_03a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_03a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_03b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_03b.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_04.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_04a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_04a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_04b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_04b.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_05.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_05a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_05a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_05b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_05b.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_06.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_06a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_06a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_06b
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_06b.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_07.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_07a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_07a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_08a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_08a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_ep_09a
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_ep_09a.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_01
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_01.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_02
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_02.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_03
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_03.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_04
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_04.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_05
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_05.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_06
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_06.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_07
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_07.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_08
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_08.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_09
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_09.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_10
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_10.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_11
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_11.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_12
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_12.ogg","db-27",1};
		titles[] = {};
	};
	class ACE_us_tkr_13
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_aitalk\sounds\radio\us_air_rc\us_tkr_13.ogg","db-27",1};
		titles[] = {};
	};
};
//};
