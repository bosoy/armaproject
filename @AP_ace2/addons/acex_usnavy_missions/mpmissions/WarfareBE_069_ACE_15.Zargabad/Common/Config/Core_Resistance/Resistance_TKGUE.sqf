Private ["_n","_u"];

//--- Resistance Key Units.
['WFBE_GUERCREW','TK_GUE_Soldier_EP1',true] Call SetNamespace;
['WFBE_GUERPILOT','TK_GUE_Soldier_EP1',true] Call SetNamespace;
['WFBE_GUERSOLDIER','TK_GUE_Soldier_EP1',true] Call SetNamespace;

//--- Town Resistance.
_n		= ["Group"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Infantry", "TK_GUE_Group"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["GroupAssault"];
_u		= ["TK_GUE_Warlord_EP1"];
_u = _u + ["TK_GUE_Soldier_4_EP1"];
_u = _u + ["TK_GUE_Soldier_AT_EP1"];
_u = _u + ["TK_GUE_Soldier_AR_EP1"];
_u = _u + ["TK_GUE_Soldier_MG_EP1"];
_u = _u + ["TK_GUE_Soldier_HAT_EP1"];
_u = _u + ["TK_GUE_Soldier_5_EP1"];
_u = _u + ["TK_GUE_Bonesetter_EP1"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["GroupWeapons"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Infantry", "TK_GUE_GroupWeapons"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Patrol1"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Infantry", "TK_GUE_Patrol"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Patrol2"];
_u		= ["TK_GUE_Soldier_EP1"];
_u = _u + ["TK_GUE_Soldier_AR_EP1"];
_u = _u + ["TK_GUE_Soldier_4_EP1"];
_u = _u + ["TK_GUE_Soldier_HAT_EP1"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["ATTeam"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Infantry", "TK_GUE_ATTeam"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["AATeam"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Infantry", "TK_GUE_AATeam"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SniperTeam"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Infantry", "TK_GUE_SniperTeam"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Militia"];
_u		= ["TK_GUE_Soldier_2_EP1"];
_u = _u + ["TK_GUE_Soldier_3_EP1"];
_u = _u + ["TK_GUE_Soldier_4_EP1"];
_u = _u + ["TK_GUE_Soldier_5_EP1"];
_u = _u + ["TK_GUE_Bonesetter_EP1"];
_u = _u + ["TK_GUE_Soldier_EP1"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Technical"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Motorized", "TK_GUE_Technicals"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MotorizedGroup"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Motorized", "TK_GUE_MotorizedGroup"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MotorizedAATeam"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Motorized", "TK_GUE_MotorizedPatrol"] Call GetGroupFromConfig;
_u = _u + ["Ural_ZU23_TK_GUE_EP1"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MechanizedPatrol"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Mechanized", "TK_GUE_MechanizedPatrol"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MechanizedGroup"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Mechanized", "TK_GUE_MechanizedGroup"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LightArmor"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Armored", "TK_GUE_T34Platoon"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["HeavyArmor"];
_u = 	  ["Guerrila", "BIS_TK_GUE", "Armored", "TK_GUE_T55Section"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

//--- Patroling Resistance.
if (('WFBE_RESPATROL' Call GetNamespace) > 0) then {
	['WFBE_RESPATROLTYPE10',['TK_GUE_Soldier_EP1','TK_GUE_Soldier_MG_EP1','TK_GUE_Soldier_Sniper_EP1','TK_GUE_Bonesetter_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE11',['TK_GUE_Warlord_EP1','TK_GUE_Soldier_AR_EP1','TK_GUE_Soldier_3_EP1','TK_GUE_Soldier_AT_EP1','TK_GUE_Soldier_4_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE12',['Offroad_DSHKM_TK_GUE_EP1','Offroad_SPG9_TK_GUE_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE20',['BTR40_MG_TK_GUE_EP1','Ural_ZU23_TK_GUE_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE21',['V3S_TK_GUE_EP1','TK_GUE_Warlord_EP1','TK_GUE_Soldier_AT_EP1','TK_GUE_Soldier_MG_EP1','TK_GUE_Soldier_HAT_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE22',['BTR40_MG_TK_GUE_EP1','TK_GUE_Soldier_AA_EP1','TK_GUE_Soldier_AA_EP1','TK_GUE_Bonesetter_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE30',['T34_TK_GUE_EP1','T34_TK_GUE_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE31',['T55_TK_GUE_EP1','T55_TK_GUE_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE32',['TK_GUE_Soldier_Sniper_EP1','TK_GUE_Soldier_5_EP1','TK_GUE_Soldier_Sniper_EP1'],true] Call SetNamespace;
};

//--- Base Attacker Resistance.
if (('WFBE_RESSTRIKER' Call GetNamespace) > 0) then {
	['WFBE_RESSTRIKERTYPE10',['TK_GUE_Soldier_EP1','TK_GUE_Soldier_5_EP1','TK_GUE_Soldier_Sniper_EP1'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE11',['TK_GUE_Warlord_EP1','TK_GUE_Soldier_AR_EP1','TK_GUE_Soldier_3_EP1','TK_GUE_Soldier_AT_EP1','TK_GUE_Soldier_4_EP1'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE12',['TK_GUE_Warlord_EP1','TK_GUE_Soldier_AA_EP1','TK_GUE_Soldier_AA_EP1','TK_GUE_Soldier_3_EP1'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE13',['TK_GUE_Warlord_EP1','TK_GUE_Soldier_MG_EP1','TK_GUE_Bonesetter_EP1','TK_GUE_Soldier_AT_EP1','TK_GUE_Soldier_AT_EP1'],true] Call SetNamespace;
};

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Resistance_TKGUE: Initialization - [Done]",diag_frameno,diag_tickTime];