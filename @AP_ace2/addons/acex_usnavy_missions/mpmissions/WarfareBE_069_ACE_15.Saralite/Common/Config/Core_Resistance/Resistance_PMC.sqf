Private ["_n","_u"];

//--- Resistance Key Units.
['WFBE_GUERCREW','Soldier_Crew_PMC',true] Call SetNamespace;
['WFBE_GUERPILOT','Soldier_Pilot_PMC',true] Call SetNamespace;
['WFBE_GUERSOLDIER','Soldier_PMC',true] Call SetNamespace;

//--- Town Resistance.
_n		= ["Group"];
_u		= ["Guerrila", "PMC_BAF", "Infantry", "PMC_Field_Security_Team"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["GroupAssault"];
_u		= ["Guerrila", "PMC_BAF", "Infantry", "PMC_Security_Detail"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["GroupWeapons"];
_u		= ["Guerrila", "PMC_BAF", "Infantry", "PMC_Security_Specialists"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Patrol1"];
_u		= ["Guerrila", "PMC_BAF", "Infantry", "PMC_VIP_Bodyguard"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Patrol2"];
_u		= ["Guerrila", "PMC_BAF", "Infantry", "PMC_Field_Security_Patrol"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["ATTeam"];
_u		= ["Soldier_AT_PMC"];
_u = _u + ["Soldier_AT_PMC"];
_u = _u + ["Soldier_Bodyguard_M4_PMC"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["AATeam"];
_u		= ["Soldier_TL_PMC"];
_u = _u + ["Soldier_AA_PMC"];
_u = _u + ["Soldier_AA_PMC"];
_u = _u + ["Soldier_Bodyguard_M4_PMC"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SniperTeam"];
_u		= ["Soldier_Sniper_KSVK_PMC"];
_u = _u + ["Soldier_Sniper_PMC"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Militia"];
_u		= ["Guerrila", "PMC_BAF", "Infantry", "PMC_Field_Support_Team"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["Technical"];
_u		= ["Soldier_TL_PMC"];
_u = _u + ["Offroad_DSHKM_TK_GUE_EP1"];
_u = _u + ["Offroad_SPG9_TK_GUE_EP1"];
_u = _u + ["ArmoredSUV_PMC"];
_u = _u + ["Soldier_MG_PMC"];
_u = _u + ["Soldier_GL_PMC"];
_u = _u + ["Soldier_Sniper_KSVK_PMC"];
_u = _u + ["Soldier_AT_PMC"];
_u = _u + ["Soldier_Bodyguard_M4_PMC"];
_u = _u + ["Soldier_Medic_PMC"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MotorizedGroup"];
_u		= ["Guerrila", "PMC_BAF", "Motorized", "PMC_Armored_Patrol"] Call GetGroupFromConfig;
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MotorizedAATeam"];
_u		= ["Soldier_TL_PMC"];
_u = _u + ["Ural_ZU23_TK_GUE_EP1"];
_u = _u + ["Soldier_Sniper_PMC"];
_u = _u + ["Soldier_AA_PMC"];
_u = _u + ["Soldier_PMC"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MechanizedPatrol"];
_u		= ["Soldier_Bodyguard_M4_PMC"];
_u = _u + ["BTR40_MG_TK_GUE_EP1"];
_u = _u + ["BRDM2_TK_GUE_EP1"];
_u = _u + ["Soldier_Bodyguard_AA12_PMC"];
_u = _u + ["Soldier_PMC"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MechanizedGroup"];
_u		= ["Soldier_TL_PMC"];
_u = _u + ["T34_TK_GUE_EP1"];
_u = _u + ["ArmoredSUV_PMC"];
_u = _u + ["Soldier_MG_PMC"];
_u = _u + ["Soldier_Bodyguard_AA12_PMC"];
_u = _u + ["Soldier_AT_PMC"];
_u = _u + ["Soldier_Bodyguard_M4_PMC"];
_u = _u + ["Soldier_Sniper_KSVK_PMC"];
_u = _u + ["Soldier_AT_PMC"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LightArmor"];
_u		= ["T34_TK_GUE_EP1"];
_u = _u + ["T34_TK_GUE_EP1"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["HeavyArmor"];
_u		= ["T55_TK_GUE_EP1"];
_u = _u + ["T55_TK_GUE_EP1"];
[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

//--- Patroling Resistance.
if (('WFBE_RESPATROL' Call GetNamespace) > 0) then {
	['WFBE_RESPATROLTYPE10',['Soldier_PMC','Soldier_MG_PKM_PMC','Soldier_Sniper_PMC','Soldier_Medic_PMC'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE11',['Soldier_TL_PMC','Soldier_MG_PMC','Soldier_M4A3_PMC','Soldier_AT_PMC','Soldier_GL_PMC'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE12',['ArmoredSUV_PMC','ArmoredSUV_PMC'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE20',['BTR40_MG_TK_GUE_EP1','Ural_ZU23_TK_GUE_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE21',['SUV_PMC','Soldier_TL_PMC','Soldier_AT_PMC','Soldier_Bodyguard_AA12_PMC'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE22',['BTR40_MG_TK_GUE_EP1','Soldier_AA_PMC','Soldier_AA_PMC','Soldier_Medic_PMC'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE30',['T34_TK_GUE_EP1','T34_TK_GUE_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE31',['T55_TK_GUE_EP1','T55_TK_GUE_EP1'],true] Call SetNamespace;
	['WFBE_RESPATROLTYPE32',['Ka60_GL_PMC','Soldier_TL_PMC','Soldier_AT_PMC','Soldier_Bodyguard_M4_PMC','Soldier_Bodyguard_M4_PMC'],true] Call SetNamespace;
};

//--- Base Attacker Resistance.
if (('WFBE_RESSTRIKER' Call GetNamespace) > 0) then {
	['WFBE_RESSTRIKERTYPE10',['ArmoredSUV_PMC','Soldier_PMC','Soldier_PMC'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE11',['Soldier_TL_PMC','Soldier_Bodyguard_M4_PMC','Soldier_M4A3_PMC','Soldier_AT_PMC','Soldier_AA_PMC'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE12',['Soldier_TL_PMC','Soldier_Bodyguard_AA12_PMC','Soldier_AA_PMC','Soldier_Engineer_PMC'],true] Call SetNamespace;
	['WFBE_RESSTRIKERTYPE13',['Ka60_PMC','Soldier_MG_PMC','Soldier_Medic_PMC','Soldier_AT_PMC','Soldier_AT_PMC'],true] Call SetNamespace;
};

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Resistance_PMC: Initialization - [Done]",diag_frameno,diag_tickTime];