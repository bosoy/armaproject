Private ["_n","_u"];

//--- Resistance Key Units.
['WFBE_GUERCREW','GUE_Soldier_Crew',true] Call SetNamespace;
['WFBE_GUERPILOT','GUE_Soldier_1',true] Call SetNamespace;
['WFBE_GUERSOLDIER','GUE_Soldier_1',true] Call SetNamespace;

//--- Town Resistance.
_n = 	  ["Group"];
_u = 	  ["Guerrila", "GUE", "Infantry", "GUE_InfSquad"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["GroupAssault"];
_u =	  ["Guerrila", "GUE", "Infantry", "GUE_InfSquad_Assault"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["GroupWeapons"];
_u		= ["Guerrila", "GUE", "Infantry", "GUE_InfSquad_Weapons"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Patrol1"];
_u		= ["Guerrila", "GUE", "Infantry", "GUE_InfTeam_1"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Patrol2"];
_u		= ["Guerrila", "GUE", "Infantry", "GUE_InfTeam_2"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["ATTeam"];
_u		= ["Guerrila", "GUE", "Infantry", "GUE_InfTeam_AT"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["AATeam"];
_u		= ["Guerrila", "GUE", "Infantry", "GUE_GrpInf_TeamAA"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SniperTeam"];
_u		= ["Guerrila", "GUE", "Infantry", "GUE_GrpInf_TeamSniper"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Militia"];
_u		= ["Guerrila", "GUE", "Infantry", "GUE_MilitiaSquad"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Technical"];
_u		= ["Guerrila", "GUE", "Motorized", "GUE_MotInfSection"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MotorizedGroup"];
_u		= ["Guerrila", "GUE", "Motorized", "GUE_MotInfSquad"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MotorizedAATeam"];
_u		= ["Guerrila", "GUE", "Mechanized", "GUE_MechInfSection"] Call GetGroupFromConfig;
_u = _u + ["Ural_ZU23_Gue"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MechanizedPatrol"];
_u		= ["Guerrila", "GUE", "Mechanized", "GUE_MechInfSquad"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LightArmor"];
_u		= ["BMP2_GUE"];
_u = _u + ["BMP2_GUE"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["HeavyArmor"];
_u		= ["Guerrila", "GUE", "Armored", "GUE_TankSection"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

//--- Patroling Resistance.
if (('WFBE_RESPATROL' Call GetNamespace) > 0) then {
	['WFBE_RESPATROLTYPE10',['GUE_Soldier_1','GUE_Soldier_MG','GUE_Soldier_Sniper','GUE_Soldier_Medic'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE11',['GUE_Soldier_CO','GUE_Soldier_AR','GUE_Soldier_3','GUE_Soldier_AT','GUE_Soldier_2'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE12',['Offroad_DSHKM_Gue','Offroad_SPG9_Gue'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE20',['BRDM2_GUE','BRDM2_GUE'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE21',['V3S_GUE','GUE_Soldier_CO','GUE_Soldier_AT','GUE_Soldier_MG','GUE_Soldier_AT'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE22',['BMP2_GUE','GUE_Soldier_AA','GUE_Soldier_AA','GUE_Soldier_Medic'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE30',['BMP2_GUE','BMP2_GUE'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE31',['T72_GUE','T72_GUE'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE32',['GUE_Soldier_Sniper','GUE_Soldier_Scout','GUE_Soldier_Sniper'],true] Call SetNamespace;
};

//--- Base Attacker Resistance.
if (('WFBE_RESSTRIKER' Call GetNamespace) > 0) then {
	['WFBE_RESSTRIKERTYPE10',['GUE_Soldier_Sab','GUE_Soldier_Scout','GUE_Soldier_Sniper'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE11',['GUE_Soldier_CO','GUE_Soldier_AR','GUE_Soldier_3','GUE_Soldier_AT','GUE_Soldier_2'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE12',['GUE_Soldier_CO','GUE_Soldier_AA','GUE_Soldier_AA','GUE_Soldier_3'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE13',['GUE_Soldier_CO','GUE_Soldier_MG','GUE_Soldier_Medic','GUE_Soldier_AT','GUE_Soldier_AT'],true] Call SetNamespace;
};

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Resistance_GUE: Initialization - [Done]",diag_frameno,diag_tickTime];