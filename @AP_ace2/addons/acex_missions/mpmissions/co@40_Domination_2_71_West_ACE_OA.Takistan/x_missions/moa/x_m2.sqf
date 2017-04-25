// by Xeno
private ["_hangar", "_poss", "_vehicle"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_2);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(sm_2_1);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos2];
// No TT: //  steal plane prototype, Rasman, second array position armor
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
#ifdef __TT__
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_749");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_750");
#else
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_839");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_750");
#endif
};

if (isServer) then {
	__PossAndOther
	_vehicle = objNull;
	_vehicle = createVehicle [GVAR(sm_plane), _poss, [], 0, "NONE"];
	_vehicle setDir (markerDir QGVAR(sm_2));
	_vehicle setPos _poss;
	sleep 2.123;
	["specops", 1, "basic", 1, _poss,300,true] spawn FUNC(CreateInf);
	sleep 2.221;
	["shilka", 1, "bmp", 1, "tank", 1, _pos_other,1,400,true] spawn FUNC(CreateArmor);
	[_vehicle] execVM "x_missions\common\x_sidesteal.sqf";
	_vehicle addMPEventHandler ["MPKilled", {
		if (isServer) then {
			private "_vec";
			_vec = _this select 0;
			__addDead(_vec);
			if (GVAR(domdatabase)) then {
				if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddPlaneKillPoints)};
			};
		};
	}];
	_vehicle setDamage 0;
};