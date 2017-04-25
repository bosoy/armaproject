private ["_resType","_n","_u"];
_resType = 'WFBE_RESISTANCEFACTION' Call GetNamespace;
if (isNil '_resType') then {_resType = -1};

if (WF_A2_Vanilla || _resType == 0) then {
	_n		= ["Group"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_AR"];
	_u = _u + ["GUE_Soldier_1"];
	_u = _u + ["GUE_Soldier_3"];
	_u = _u + ["GUE_Soldier_2"];
	_u = _u + ["GUE_Soldier_Medic"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["GroupAssault"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_AR"];
	_u = _u + ["GUE_Soldier_MG"];
	_u = _u + ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_2"];
	_u = _u + ["GUE_Soldier_Medic"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["GroupWeapons"];
	_u		= ["GUE_Soldier_2"];
	_u = _u + ["GUE_Soldier_MG"];
	_u = _u + ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_Sab"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Patrol1"];
	_u		= ["GUE_Soldier_2"];
	_u = _u + ["GUE_Soldier_MG"];
	_u = _u + ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_GL"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Patrol2"];
	_u		= ["GUE_Soldier_1"];
	_u = _u + ["GUE_Soldier_AR"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_2"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["ATTeam"];
	_u		= ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_AR"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["AATeam"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["GUE_Soldier_AA"];
	_u = _u + ["GUE_Soldier_AA"];
	_u = _u + ["GUE_Soldier_AR"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SniperTeam"];
	_u		= ["GUE_Soldier_Sniper"];
	_u = _u + ["GUE_Soldier_Scout"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Militia"];
	_u		= ["GUE_Worker2"];
	_u = _u + ["GUE_Woodlander3"];
	_u = _u + ["GUE_Villager3"];
	_u = _u + ["GUE_Woodlander2"];
	_u = _u + ["GUE_Woodlander1"];
	_u = _u + ["GUE_Villager4"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Technical"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["Offroad_DSHKM_Gue"];
	_u = _u + ["Offroad_SPG9_Gue"];
	_u = _u + ["Pickup_PK_GUE"];
	_u = _u + ["GUE_Soldier_MG"];
	_u = _u + ["GUE_Soldier_3"];
	_u = _u + ["GUE_Soldier_Sniper"];
	_u = _u + ["GUE_Soldier_AR"];
	_u = _u + ["GUE_Soldier_Medic"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MotorizedGroup"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["V3S_GUE"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_1"];
	_u = _u + ["GUE_Soldier_AR"];
	_u = _u + ["GUE_Soldier_MG"];
	_u = _u + ["GUE_Soldier_AT"];
	_u = _u + ["GUE_Soldier_Medic"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MotorizedAATeam"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["Ural_ZU23_Gue"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_AA"];
	_u = _u + ["GUE_Soldier_1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MechanizedPatrol"];
	_u		= ["GUE_Soldier_AR"];
	_u = _u + ["BRDM2_GUE"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MechanizedGroup"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["BMP2_GUE"];
	_u = _u + ["GUE_Soldier_MG"];
	_u = _u + ["GUE_Soldier_GL"];
	_u = _u + ["GUE_Soldier_3"];
	_u = _u + ["GUE_Soldier_AR"];
	_u = _u + ["GUE_Soldier_Sniper"];
	_u = _u + ["GUE_Soldier_AT"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LightArmor"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["BMP2_GUE"];
	_u = _u + ["BMP2_GUE"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["HeavyArmor"];
	_u		= ["GUE_Soldier_CO"];
	_u = _u + ["T72_GUE"];
	_u = _u + ["T72_GUE"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
};

if (WF_A2_Arrowhead || _resType == 1) then {
	_n		= ["Group"];
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	_u = _u + ["TK_GUE_Soldier_AR_EP1"];
	_u = _u + ["TK_GUE_Soldier_EP1"];
	_u = _u + ["TK_GUE_Soldier_5_EP1"];
	_u = _u + ["TK_GUE_Soldier_5_EP1"];
	_u = _u + ["TK_GUE_Bonesetter_EP1"];
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
	_u		= ["TK_GUE_Soldier_5_EP1"];
	_u = _u + ["TK_GUE_Soldier_MG_EP1"];
	_u = _u + ["TK_GUE_Soldier_AT_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	_u = _u + ["TK_GUE_Soldier_AT_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Patrol1"];
	_u		= ["TK_GUE_Soldier_5_EP1"];
	_u = _u + ["TK_GUE_Soldier_MG_EP1"];
	_u = _u + ["TK_GUE_Soldier_AT_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Patrol2"];
	_u		= ["TK_GUE_Soldier_EP1"];
	_u = _u + ["TK_GUE_Soldier_AR_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	_u = _u + ["TK_GUE_Soldier_HAT_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["ATTeam"];
	_u		= ["TK_GUE_Soldier_AT_EP1"];
	_u = _u + ["TK_GUE_Soldier_AT_EP1"];
	_u = _u + ["TK_GUE_Soldier_AR_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["AATeam"];
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["TK_GUE_Soldier_AA_EP1"];
	_u = _u + ["TK_GUE_Soldier_AA_EP1"];
	_u = _u + ["TK_GUE_Soldier_AR_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SniperTeam"];
	_u		= ["TK_GUE_Soldier_Sniper_EP1"];
	_u = _u + ["TK_GUE_Soldier_2_EP1"];
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
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["Offroad_DSHKM_TK_GUE_EP1"];
	_u = _u + ["Offroad_SPG9_TK_GUE_EP1"];
	_u = _u + ["Pickup_PK_TK_GUE_EP1"];
	_u = _u + ["TK_GUE_Soldier_MG_EP1"];
	_u = _u + ["TK_GUE_Soldier_5_EP1"];
	_u = _u + ["TK_GUE_Soldier_Sniper_EP1"];
	_u = _u + ["TK_GUE_Soldier_HAT_EP1"];
	_u = _u + ["TK_GUE_Soldier_AR_EP1"];
	_u = _u + ["TK_GUE_Bonesetter_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MotorizedGroup"];
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["V3S_TK_GUE_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	_u = _u + ["TK_GUE_Soldier_AT_EP1"];
	_u = _u + ["TK_GUE_Soldier_EP1"];
	_u = _u + ["TK_GUE_Soldier_AR_EP1"];
	_u = _u + ["TK_GUE_Soldier_MG_EP1"];
	_u = _u + ["TK_GUE_Soldier_HAT_EP1"];
	_u = _u + ["TK_GUE_Bonesetter_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MotorizedAATeam"];
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["Ural_ZU23_TK_GUE_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	_u = _u + ["TK_GUE_Soldier_AA_EP1"];
	_u = _u + ["TK_GUE_Soldier_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MechanizedPatrol"];
	_u		= ["TK_GUE_Soldier_AR_EP1"];
	_u = _u + ["BTR40_MG_TK_GUE_EP1"];
	_u = _u + ["BRDM2_TK_GUE_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	_u = _u + ["TK_GUE_Soldier_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MechanizedGroup"];
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["T34_TK_GUE_EP1"];
	_u = _u + ["BTR40_MG_TK_GUE_EP1"];
	_u = _u + ["TK_GUE_Soldier_MG_EP1"];
	_u = _u + ["TK_GUE_Soldier_4_EP1"];
	_u = _u + ["TK_GUE_Soldier_HAT_EP1"];
	_u = _u + ["TK_GUE_Soldier_AR_EP1"];
	_u = _u + ["TK_GUE_Soldier_Sniper_EP1"];
	_u = _u + ["TK_GUE_Soldier_AT_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LightArmor"];
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["T34_TK_GUE_EP1"];
	_u = _u + ["T34_TK_GUE_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["HeavyArmor"];
	_u		= ["TK_GUE_Warlord_EP1"];
	_u = _u + ["T55_TK_GUE_EP1"];
	_u = _u + ["T55_TK_GUE_EP1"];
	[Format["WFBE_RES%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
};

diag_log "[WFBE (INIT)] Config_Resistance: Intialization - [Done]";