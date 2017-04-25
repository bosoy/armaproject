// by Xeno
#define THIS_FILE "x_initx.sqf"
#include "x_setup.sqf"
if (!isServer) exitWith{};

GVAR(allunits_add) = [];
GVAR(allunits_ai_add) = [];
GVAR(delvecsmt) = [];

__cppfln(FUNC(spawnVehicle),x_server\x_f\fn_spawnvehicle.sqf);
__cppfln(FUNC(spawnCrew),x_server\x_f\fn_spawncrew.sqf);
__cppfln(FUNC(taskDefend),x_server\x_f\fn_taskDefend.sqf);
__cppfln(FUNC(makegroup),x_server\x_makegroup.sqf);
__cppfln(FUNC(vehirespawn),x_server\x_vehirespawn.sqf);
__cppfln(FUNC(vehirespawn2),x_server\x_vehirespawn2.sqf);
__cppfln(FUNC(arifire),x_server\x_arifire.sqf);
__cppfln(FUNC(createpara3x),x_server\x_createpara3x.sqf);
#ifndef __TT__
__cppfln(FUNC(x_fackilled),x_server\x_fackilled.sqf);
__cppfln(FUNC(radarkilled),x_server\x_radarkilled.sqf);
#endif
__cppfln(FUNC(markercheck),x_server\x_markercheck.sqf);
__cppfln(FUNC(objectMapper),x_server\x_f\fn_objectMapper.sqf);
#ifdef __TT__
__cppfln(FUNC(checkveckillwest),x_common\x_checkveckillwest.sqf);
__cppfln(FUNC(checkveckilleast),x_common\x_checkveckilleast.sqf);
#endif

execFSM "fsms\NotAliveRemover.fsm";
execFSM "fsms\NotAliveRemoverUnits.fsm";
execFSM "fsms\GroupClean.fsm";

if (count GVAR(with_isledefense) > 0) then {execVM "x_server\x_isledefense.sqf"};

#ifndef __TT__
0 spawn {
	if (!isNil QGVAR(with_carrier)) then {sleep 20};
	private ["_x_objs", "_x_objs2", "_x_objs3", "_dgrp", "_unit_array"];
	_x_objs = [];
	_x_objs2 = [];
	_x_objs3 = [];
	_radar = "";
	if (GVAR(own_side) == "WEST") then {
		_radar = GVAR(baseAARadarUS);
		_x_objs = switch (true) do {
			case (__OAVer): {[GVAR(base_radar_pos), random 0, ["radar","us_army"], 0, [GVAR(ClamShell),GVAR(baseAARadarUS)]] call FUNC(objectMapper)};
			case (__COVer): {[GVAR(base_radar_pos), random 0, ["radar","usmc"], 0, [GVAR(ClamShell),GVAR(baseAARadarUS)]] call FUNC(objectMapper)};
		};
	} else {
		_radar = GVAR(baseAARadarEast);
		_x_objs = switch (true) do {
			case (__OAVer): {[GVAR(base_radar_pos), random 0, ["radar","tk_army"], 0, [GVAR(ClamShell),GVAR(baseAARadarEast)]] call FUNC(objectMapper)};
			case (__COVer): {[GVAR(base_radar_pos), random 0, ["radar","ru"], 0, [GVAR(ClamShell),GVAR(baseAARadarEast)]] call FUNC(objectMapper)};
		};
	};

	_dgrp = [GVAR(own_side)] call FUNC(creategroup);
	_unit_array = ["basic", GVAR(own_side)] call FUNC(getunitliste);
	[GVAR(base_radar_pos), _unit_array select 0, _dgrp,true] call FUNC(makemgroup);
	[_dgrp, GVAR(base_radar_pos)] call FUNC(taskDefend);

	if (GVAR(own_side) == "WEST") then {
		_x_objs2 = switch (true) do {
			case (__OAVer): {[GVAR(base_anti_air1), random 0, ["anti-air","us_army"]] call FUNC(objectMapper)};
			case (__COVer): {[GVAR(base_anti_air1), random 0, ["anti-air","usmc"]] call FUNC(objectMapper)};
		};
	} else {
		_x_objs2 = switch (true) do {
			case (__OAVer): {[GVAR(base_anti_air1), random 0, ["anti-air","tk_army"]] call FUNC(objectMapper)};
			case (__COVer): {[GVAR(base_anti_air1), random 0, ["anti-air","ru"]] call FUNC(objectMapper)};
		};
	};

	_dgrp = [GVAR(own_side)] call FUNC(creategroup);
	_unit_array = ["basic", GVAR(own_side)] call FUNC(getunitliste);
	[GVAR(base_anti_air1), _unit_array select 0, _dgrp,true] call FUNC(makemgroup);
	[_dgrp, GVAR(base_anti_air1)] call FUNC(taskDefend);

	if (GVAR(own_side) == "WEST") then {
		_x_objs3 = switch (true) do {
			case (__OAVer): {[GVAR(base_anti_air2), random 0, ["anti-air","us_army"]] call FUNC(objectMapper)};
			case (__COVer): {[GVAR(base_anti_air2), random 0, ["anti-air","usmc"]] call FUNC(objectMapper)};
		};
	} else {
		_x_objs3 = switch (true) do {
			case (__OAVer): {[GVAR(base_anti_air2), random 0, ["anti-air","tk_army"]] call FUNC(objectMapper)};
			case (__COVer): {[GVAR(base_anti_air2), random 0, ["anti-air","ru"]] call FUNC(objectMapper)};
		};
	};

	_dgrp = [GVAR(own_side)] call FUNC(creategroup);
	_unit_array = ["basic", GVAR(own_side)] call FUNC(getunitliste);
	[GVAR(base_anti_air2), _unit_array select 0, _dgrp,true] call FUNC(makemgroup);
	[_dgrp, GVAR(base_anti_air2)] call FUNC(taskDefend);

	{
		_rbox = false;
		if (__RankedVer) then {
			if (_x isKindOf "ReammoBox") then {
				deleteVehicle _x;
				_rbox = true;
			};
		};
		if (!_rbox) then {
			if !(_x isKindOf _radar) then {
				__addDead(_x)
				if ((toUpper (typeOf _x)) in GVAR(base_aavecs_check)) then {
					_x addEventHandler ["killed", FUNC(handleDeadVec)];
					_dgrp = [GVAR(own_side)] call FUNC(creategroup);
					_crew = [_x, _dgrp] call FUNC(spawnCrew);
				};
			} else {
				_x addEventHandler ["killed", FUNC(radarkilled)];
			};
		};
	} forEach _x_objs + _x_objs2 + _x_objs3;
};
#endif
