// by Xeno
#define THIS_FILE "x_recruitsetup.sqf"
#include "x_setup.sqf"

private ["_D_AI_HUT","_script","_marker_name"];
waitUntil {sleep 0.512;!isNil {__XJIPGetVar(GVAR(AI_HUT))}};
_D_AI_HUT = __XJIPGetVar(GVAR(AI_HUT));
player reveal _D_AI_HUT;

_marker_name = "d_RecruitB_100000000";
[_marker_name, getPosASL _D_AI_HUT,"ICON","ColorYellow",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_313"),0,"mil_dot"] call FUNC(CreateMarkerLocal);

_D_AI_HUT addAction [(localize "STR_DOM_MISSIONSTRING_314") call FUNC(BlueText), "x_client\x_recruitaiaction.sqf"];

if (!isNil QGVAR(additional_recruit_buildings)) then {
	{
		if (!isNil "_x") then {
			if (!isNull _x) then {
				_marker_name = "d_RecruitB_" + str(_forEachIndex);
				[_marker_name, getPosASL _x,"ICON","ColorYellow",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_313"),0,"mil_dot"] call FUNC(CreateMarkerLocal);

				_x addAction [(localize "STR_DOM_MISSIONSTRING_314") call FUNC(BlueText), "x_client\x_recruitaiaction.sqf"];
			};
		};
	} forEach GVAR(additional_recruit_buildings);
};

GVAR(current_ai_num) = 0;
GVAR(current_ai_units) = [];

if (isNil QGVAR(UnitsToRecruit)) then {
	GVAR(UnitsToRecruit) =
	#ifdef __OA__
	switch (GVAR(player_side)) do {
		case west: {
			["US_Soldier_EP1", "US_Soldier_AT_EP1", "US_Soldier_Medic_EP1", "US_Soldier_MG_EP1", "US_Soldier_GL_EP1", "US_Soldier_Sniper_EP1", "US_Soldier_AA_EP1", "US_Delta_Force_Night_EP1"]
		};
		case east: {
			["TK_Soldier_EP1", "TK_Soldier_AT_EP1", "TK_Soldier_Medic_EP1", "TK_Soldier_MG_EP1", "TK_Soldier_GL_EP1", "TK_Soldier_Sniper_EP1", "TK_Soldier_AA_EP1", "TK_Special_Forces_EP1"]
		};
	};
	#endif
	#ifdef __CO__
	switch (GVAR(player_side)) do {
		case west: {
			["USMC_Soldier", "USMC_Soldier_AT", "USMC_Soldier_Medic", "USMC_Soldier_MG", "USMC_SoldierS_Sniper", "USMC_Soldier_AA", "FR_Sapper"]
		};
		case east: {
			["RU_Soldier", "RU_Soldier_AT", "RU_Soldier_Medic", "RU_Soldier_MG", "RU_SoldierS_Sniper", "RU_Soldier_AA", "RUS_Soldier_Sab"]
		};
	};
	#endif
};

__pSetVar [QGVAR(recdbusy), false];
