// by Xeno
private ["_hangar", "_poss", "_vehicle", "_lvec"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_44);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(sm_44_1);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos2]; // index: 44,   Steal chopper prototype near Zavark
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_863");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_796");
};

if (isServer) then {
	__PossAndOther
	_hangar = createVehicle [GVAR(sm_hangar), _poss, [], 0, "NONE"];
	_hangar setDir (markerDir QGVAR(sm_44));
	_hangar setPos _poss;
	__AddToExtraVec(_hangar)
	sleep 1.0123;
	_vehicle = createVehicle [GVAR(sm_chopper), _poss, [], 0, "NONE"];
	_vehicle setDir ((direction _hangar) + 180);
	_vehicle setPos _poss;
	sleep 2.123;
	["specops", 1, "basic", 1, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.221;
	["shilka", 1, "bmp", 1, "tank", 1, _pos_other,1,400,true] spawn FUNC(CreateArmor);
	sleep 2.543;
	[_vehicle] execVM "x_missions\common\x_sidesteal.sqf";
	_vehicle addMPEventHandler ["MPKilled", {
		if (isServer) then {
			private "_vec";
			_vec = _this select 0;
			__addDead(_vec);
		};
	}];
	_vehicle setDamage 0;
#ifdef __ACE__
	_lvec = createVehicle [(localize "STR_DOM_MISSIONSTRING_797"), _poss, [], 0, "NONE"];
	__addDead(_lvec)
#endif
};