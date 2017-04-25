// by Xeno
private ["_vehicle", "_poss"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_3);
_mpos set [2,0];
_mpos1 = markerPos QGVAR(sm_3_1);
_mpos1 set [2,0];
_mpos2 = markerPos QGVAR(sm_3_2);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos1, _mpos2]; //  steal tank prototype, Timurkalay, array 2 and 3 = infantry and armor positions
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
#ifndef __TT__
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_852");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_769");
#else
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_853");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_771");
#endif
};

if (isServer) then {
	__PossAndOther
	_pos_other2 = GVAR(x_sm_pos) select 2;
	_vehicle = objNull;
	_vehicle = createVehicle [GVAR(sm_tank), _poss, [], 0, "NONE"];
	_vehicle setDir  markerDir QGVAR(sm_3);
	_vehicle setPos _poss;
#ifndef __TT__
	sleep 2.123;
	["specops", 1, "basic", 1, _pos_other,250,true] spawn FUNC(CreateInf);
	sleep 2.321;
	["shilka", 1, "bmp", 1, "tank", 0, _pos_other2,1,400,true] spawn FUNC(CreateArmor);
	[_vehicle] execVM "x_missions\common\x_sidesteal.sqf";
	_vehicle addMPEventHandler ["MPKilled", {
		if (isServer) then {
			private "_vec";
			_vec = _this select 0;
			__addDead(_vec);
			if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddTankKillPoints)};
		};
	}];
	_vehicle setDamage 0;
#else
	_vehicle addEventHandler ["killed", FUNC(KilledSMTargetTT)];
	_vehicle lock true;
	__AddToExtraVec(_vehicle)
	sleep 2.123;
	["specops", 1, "basic", 1, _pos_other,250,true] spawn FUNC(CreateInf);
	sleep 2.321;
	["shilka", 1, "bmp", 1, "tank", 0, _pos_other2,2,400,true] spawn FUNC(CreateArmor);
#endif
};