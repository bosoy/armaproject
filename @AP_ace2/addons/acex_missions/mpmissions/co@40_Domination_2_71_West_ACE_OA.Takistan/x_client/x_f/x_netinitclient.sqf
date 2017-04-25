//#define __DEBUG__
#define THIS_FILE "x_netinitclient.sqf"
#include "x_setup.sqf"

FUNC(create_boxNet) = {
	private "_box";
	_box = objNull;
	_box = GVAR(the_box) createVehicleLocal (_this select 0);
	_box setPos (_this select 0);
	player reveal _box;
	_box allowDamage false;
	_box addAction [(localize "STR_DOM_MISSIONSTRING_300") call FUNC(BlueText), "x_client\x_savelayout.sqf"];
	_box addAction [(localize "STR_DOM_MISSIONSTRING_301") call FUNC(BlueText), "x_client\x_clearlayout.sqf"];
	[_box] call FUNC(weaponcargo);
};

#ifndef __TT__
FUNC(jet_service_facNet) = {
	if (__XJIPGetVar(GVAR(jet_serviceH))) then {
		private ["_element", "_pos", "_dir", "_fac"];
		if (GVAR(string_player) in GVAR(is_engineer) || GVAR(with_ai) || GVAR(with_ai_features) == 0) then {[0] spawn FUNC(XFacAction)};
		_element = GVAR(aircraft_facs) select 0;
		_pos = _element select 0;
		_dir = _element select 1;
		_fclass = switch (true) do {
			case (__OAVer): {"Land_vez_ruins"};
			case (__COVer): {"Land_budova2_ruins"};
		};
		_fac = _fclass createVehicleLocal _pos;
		_fac setDir _dir;
		_fac setPos _pos;
	};
};

FUNC(chopper_service_facNet) = {
	if (__XJIPGetVar(GVAR(chopper_serviceH))) then {
		private ["_element", "_pos", "_dir", "_fac"];
		if (GVAR(string_player) in GVAR(is_engineer) || GVAR(with_ai)|| GVAR(with_ai_features) == 0) then {[1] spawn FUNC(XFacAction)};
		_element = GVAR(aircraft_facs) select 1;
		_pos = _element select 0;
		_dir = _element select 1;
		_fclass = switch (true) do {
			case (__OAVer): {"Land_vez_ruins"};
			case (__COVer): {"Land_budova2_ruins"};
		};
		_fac = _fclass createVehicleLocal _pos;
		_fac setDir _dir;
		_fac setPos _pos;
	};
};

FUNC(wreck_repair_facNet) = {
	if (__XJIPGetVar(GVAR(wreck_repairH))) then {
		private ["_element", "_pos", "_dir", "_fac"];
		if (GVAR(string_player) in GVAR(is_engineer) || GVAR(with_ai) || GVAR(with_ai_features) == 0) then {[2] spawn FUNC(XFacAction)};
		_element = GVAR(aircraft_facs) select 2;
		_pos = _element select 0;
		_dir = _element select 1;
		_fclass = switch (true) do {
			case (__OAVer): {"Land_vez_ruins"};
			case (__COVer): {"Land_budova2_ruins"};
		};
		_fac = _fclass createVehicleLocal _pos;
		_fac setDir _dir;
		_fac setPos _pos;
	};
};
#endif

FUNC(ataxiNet) = {
	switch (_this select 1) do {
		case 0: {(localize "STR_DOM_MISSIONSTRING_634") call FUNC(HQChat)};
		case 1: {(localize "STR_DOM_MISSIONSTRING_635") call FUNC(HQChat);GVAR(heli_taxi_available) = true};
		case 2: {(localize "STR_DOM_MISSIONSTRING_636") call FUNC(HQChat);GVAR(heli_taxi_available) = true};
		case 3: {(localize "STR_DOM_MISSIONSTRING_637") call FUNC(HQChat)};
		case 4: {(localize "STR_DOM_MISSIONSTRING_638") call FUNC(HQChat);GVAR(heli_taxi_available) = true};
		case 5: {(localize "STR_DOM_MISSIONSTRING_639") call FUNC(HQChat)};
		case 6: {(localize "STR_DOM_MISSIONSTRING_640") call FUNC(HQChat)};
	};
};

#ifdef __TT__
FUNC(dattention) = {[format [(localize "STR_DOM_MISSIONSTRING_641"), _this select 0, str(_this select 1), str(_this select 2)], "GLOBAL"] call FUNC(HintChatMsg)};
#endif

FUNC(player_stuff) = {
	__TRACE_1("player_stuff","_this");
	_this = _this select 1;
	__TRACE_1("player_stuff new _this","_this");
	GVAR(player_autokick_time) = _this select 0;
#ifdef __TT__
	private ["_prev_side", "_same_side"];
	_prev_side = _this select 5;
	_same_side = false;
	if (_prev_side != sideUnknown) then {
		if (GVAR(player_side) != _prev_side) then {
			[QGVAR(attention), [GVAR(name_pl), _prev_side, GVAR(player_side)]] call FUNC(NetCallEventToClients);
		} else {
			_same_side = true;
		};
	};
#endif
	
	private "_can_select";
	_can_select = true;
	if (GVAR(WithRevive) == 0) then {
		if ((_this select 8) == -1 && xr_max_lives != -1) then {
			_can_select = false;
			0 spawn {
				waitUntil {!GVAR(still_in_intro)};
				__TRACE("player_stuff, calling park_player");
				[false] spawn xr_fnc_park_player;
			};
		};
	};
	if (_can_select) then {
		// TODO: if player wasn't in a vehicle, ask him if he wants to spawn at the position where he left the server, add dialog ? Do it all ? Aka, does it make sense ?
		// _this select 10 = weapons player
		// _this select 11 = magazines player
		// _this select 12 = position player
		// _this select 13 = true = player wasn not in vehicle, false = player was in vehicle
#ifndef __TT__
		if (count (_this select 10) > 0 && !GVAR(LimitedWeapons)) then {
#else
		if (count (_this select 10) > 0 && !GVAR(LimitedWeapons) && _same_side) then {
#endif
			private "_p";
			_p = player;
			removeAllWeapons _p;
			removeAllItems _p;
			{_p addMagazine _x} forEach (_this select 11);
			{_p addWeapon _x} forEach (_this select 10);
			_primw = primaryWeapon _p;
			if (_primw != "") then {
				_p selectWeapon _primw;
				_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
				_p selectWeapon (_muzzles select 0);
			};
		};
	};
	if (GVAR(domdatabase)) then {
		GVAR(player_stats) = [
			_this select 14, // total score
			_this select 15, // total time played on this server
			_this select 17 // number played on this server
		];
	};
};

FUNC(dropansw) = {
	switch (_this select 1) do {
		case 0: {(localize "STR_DOM_MISSIONSTRING_642") call FUNC(HQChat)};
		case 1: {(localize "STR_DOM_MISSIONSTRING_643") call FUNC(HQChat)};
		case 2: {(localize "STR_DOM_MISSIONSTRING_644") call FUNC(HQChat)};
		case 3: {(localize "STR_DOM_MISSIONSTRING_645") call FUNC(HQChat)};
		case 4: {(localize "STR_DOM_MISSIONSTRING_646") call FUNC(HQChat)};
	};
};

FUNC(mhqdeplNet) = {
	private ["_mhq", "_isdeployed", "_name", "_vside"];
	PARAMS_2(_mhq,_isdeployed);
	_name = GV(_mhq,GVAR(vec_name));
	if (isNil "_name") exitWith {};
#ifdef __TT__
	_vside = GV(_mhq,GVAR(side));
	if (isNil "_vside") exitWith {};
	if (GVAR(player_side) != _vside) exitWith {};
#endif
	_m = GV(_mhq,GVAR(marker));
	if (_isdeployed) then {
		(format [(localize "STR_DOM_MISSIONSTRING_647"), _name]) call FUNC(HQChat);
		if (!isNil "_m") then {_m setMarkerTextLocal format [(localize "STR_DOM_MISSIONSTRING_261"), GV(_mhq,GVAR(marker_text))]};
	} else {
		(format [(localize "STR_DOM_MISSIONSTRING_648"), _name]) call FUNC(HQChat);
		if (!isNil "_m") then {_m setMarkerTextLocal (GV(_mhq,GVAR(marker_text)))};
	};
};

#ifndef __TT__
FUNC(intel_updNet) = {
	switch (_this select 0) do {
		case 0: {
			format [(localize "STR_DOM_MISSIONSTRING_649"), _this select 1] call FUNC(HQChat)
		};
		case 1: {
			format [(localize "STR_DOM_MISSIONSTRING_650"), _this select 1] call FUNC(HQChat)
		};
		case 2: {
			format [(localize "STR_DOM_MISSIONSTRING_651"), _this select 1] call FUNC(HQChat)
		};
		case 3: {
			format [(localize "STR_DOM_MISSIONSTRING_652"), _this select 1] call FUNC(HQChat)
		};
		case 4: {
			format [(localize "STR_DOM_MISSIONSTRING_653"), _this select 1] call FUNC(HQChat)
		};
		case 5: {
			format [(localize "STR_DOM_MISSIONSTRING_654"), _this select 1] call FUNC(HQChat)
		};
		case 6: {
			format [(localize "STR_DOM_MISSIONSTRING_655"), _this select 1] call FUNC(HQChat)
		};
	};
};
#endif