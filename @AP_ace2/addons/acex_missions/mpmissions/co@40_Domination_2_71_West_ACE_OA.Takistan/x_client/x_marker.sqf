// by Xeno
#define THIS_FILE "x_marker.sqf"
#include "x_setup.sqf"

FUNC(X_XMarkerVehicles) = {
	private "_rem";
	_rem = [];
	{
		if (!isNull _x && {alive _x}) then {
			_m = GV(_x,GVAR(marker));_m setMarkerPosLocal (getPosASL _x);if (GVAR(v_marker_dirs)) then {_m setMarkerDirLocal (direction _x)};
			_m setMarkerAlphaLocal (if (!canMove _x) then {0.5} else {1.0});
		} else {
			_rem set [count _rem, _x]
		};
	} forEach GVAR(marker_vecs);
	if (count _rem > 0) then {GVAR(marker_vecs) = GVAR(marker_vecs) - _rem};
};

#ifndef __TT__
FUNC(X_XMarkerPlayers) = {
	private ["_ap","_as","_isu"];
	{
		_ap = __getMNsVar2(_x);
		_as = _x;
		_isu = GV(_ap,xr_pluncon);
		if (isNil "_isu") then {_isu = false};
		if (!isNil "_ap" && {alive _ap && isPlayer _ap && !_isu}) then {
			_as setMarkerAlphaLocal 1;
			_as setMarkerPosLocal getPosASL _ap;
			_as setMarkerTextLocal (switch (GVAR(show_player_marker)) do {
				case 1: {name _ap};
				case 2: {""};
				case 3: {GVAR(player_roles) select _forEachIndex};
				case 4: {(localize "STR_DOM_MISSIONSTRING_280") + str(9 - round(9 * damage _ap))};
				default {""};
			});
			if (GVAR(p_marker_dirs)) then {_as setMarkerDirLocal (direction (vehicle _ap))};
		} else {
			_as setMarkerPosLocal [0,0];
			_as setMarkerTextLocal "";
			_as setMarkerAlphaLocal 0;
		};
	} forEach GVAR(player_entities);
};

if (GVAR(dont_show_player_markers_at_all) == 1) then {
	{[_x, [0,0],"ICON","ColorGreen",[0.4,0.4],"",0,GVAR(p_marker)] call FUNC(CreateMarkerLocal)} forEach GVAR(player_entities);
};

_ncpr = count GVAR(player_roles);
_ncpe = count GVAR(player_entities);
if (_ncpr != _ncpe) then {
	if (_ncpe > _ncpr) then {
		for "_e" from 1 to (_ncpe - _ncpr) do {
			GVAR(player_roles) set [count GVAR(player_roles), "AR"];
		};
	};
};

{
	GVAR(misc_store) setVariable [_x, [_forEachIndex, GVAR(player_roles) select _forEachIndex]];
} forEach GVAR(player_entities);
#endif

#ifdef __TT__
_cservicename = QGVAR(chopper_service);
_wrepname = QGVAR(wreck_service);
_telename = QGVAR(teleporter);
_jetservicename = QGVAR(aircraft_service);
_bonusairname = "bonus_air";
_bonusvecname = "bonus_vehicles";
_ammoload = "Ammobox Reload";
_vec_serv = QGVAR(vehicle_service);
_start_marker = "Start";
if (GVAR(player_side) == east) then {
	_cservicename = QGVAR(chopper_serviceR);
	_wrepname = QGVAR(wreck_serviceR);
	_telename = QGVAR(teleporter_1);
	_jetservicename = QGVAR(aircraft_serviceR);
	_bonusairname = "bonus_airR";
	_bonusvecname = "bonus_vehiclesR";
	_ammoload = "Ammobox ReloadR";
	_start_marker = "Start_east";
	_vec_serv = QGVAR(vehicle_serviceR);
};
{
	_x setMarkerAlphaLocal 1;
} forEach [_cservicename,_wrepname,_telename,_jetservicename,_bonusairname,_bonusvecname,_ammoload,_vec_serv,_start_marker];

GVAR(entities_tt) = if (GVAR(player_side) == west) then {
	GVAR(entities_tt_west)
} else {
	GVAR(entities_tt_east)
};

GVAR(player_roles_tt) = if (GVAR(player_side) == west) then {
	["PLT LD","SL","SN","MG","AT","GL","MD","MG","AT","EN","EN","SN","AA","SB","SB","AT","GL","MD","MG","AT"]
} else {
	["PLT LD","SL","SN","MG","AT","GL","MD","MG","AT","EN","EN","SN","AA","SB","SB","AT","GL","MD","MG","AT"]
};

_ncpr = count GVAR(player_roles_tt);
_ncpe = count GVAR(entities_tt);
if (_ncpr != _ncpe) then {
	if (_ncpe > _ncpr) then {
		for "_e" from 1 to (_ncpe - _ncpr) do {
			GVAR(player_roles_tt) set [count GVAR(player_roles_tt), "AR"];
		};
	};
};

{
	GVAR(misc_store) setVariable [GVAR(entities_tt) select _forEachIndex, [_forEachIndex, GVAR(player_roles_tt) select _forEachIndex]];
} forEach GVAR(entities_tt);

FUNC(X_XMarkerPlayers) = {
	private ["_ap","_as","_isu"];
	{
		_ap = __getMNsVar2(_x);
		_as = _x;
		_isu = GV(_ap,xr_pluncon);
		if (isNil "_isu") then {_isu = false};
		if (!isNil "_ap" && {alive _ap && isPlayer _ap && !_isu}) then {
			_as setMarkerAlphaLocal 1;
			_as setMarkerPosLocal getPosASL _ap;
			_as setMarkerTextLocal  (switch (GVAR(show_player_marker)) do {
				case 1: {name _ap};
				case 2: {""};
				case 3: {GVAR(player_roles) select _forEachIndex};
				case 4: {(localize "STR_DOM_MISSIONSTRING_280") + str(9 - round(9 * damage _ap))};
				default {""};
			});
			if (GVAR(p_marker_dirs)) then {_as setMarkerDirLocal (direction (vehicle _ap))};
		} else {
			_as setMarkerPosLocal [0,0];
			_as setMarkerTextLocal "";
			_as setMarkerAlphaLocal 0;
		};
	} forEach GVAR(entities_tt);
};

if (GVAR(dont_show_player_markers_at_all) == 1) then {
	{[_x, [0,0],"ICON","ColorGreen",[0.4,0.4],"",0,GVAR(p_marker)] call FUNC(CreateMarkerLocal)} forEach GVAR(entities_tt);
};
#endif

if (GVAR(with_ai)) then {
	for "_ai" from 2 to 40 do {
		[format ["AI_X%1%2", GVAR(string_player), _ai], [0,0],"ICON","ColorGreen",[0.4,0.4],"",0,GVAR(p_marker)] call FUNC(CreateMarkerLocal);
	};
    FUNC(X_XAI_Markers) = {
        private ["_units","_mkname","_mkr","_unit","_plobj","_ai","_unittext","_unitno"];
        _mkname = "AI_X%1%2";
		_plobj = __getMNsVar2(GVAR(string_player));
		if (!isNil "_plobj" && !isNull _plobj) then {
			_grppl = group _plobj;
			_units = units _grppl - [player];
			for "_ai" from 2 to 40 do {
				_mkr = format[_mkname, GVAR(string_player), _ai];
				if (_ai - 1 <= count _units) then {
					_unit = _units select _ai - 2;
					if (alive _unit && !isPlayer _unit) then {
						_mkr setMarkerAlphaLocal 1;
						_unittext = toArray(str _unit);
						_unitno = toString([_unittext select ((count _unittext) - 1)]);
						_mkr setMarkerPosLocal getPosASL _unit;
						_mkr setMarkerTextLocal (switch (GVAR(show_player_marker)) do {
							case 1: {_unitno};
							case 2: {""};
							case 3: {""};
							case 4: {(localize "STR_DOM_MISSIONSTRING_280") + str(9 - round(9 * damage _unit))};
							default {""};
						});
						//if (_plobj == player) then {
							//_mkr setMarkerColorLocal "ColorGreen";
						//};
						if (GVAR(p_marker_dirs)) then {_as setMarkerDirLocal (direction (vehicle _unit))};
					} else {
						_mkr setMarkerPosLocal [0,0];
						_mkr setMarkerTextLocal "";
						_mkr setMarkerAlphaLocal 0;
					};
				} else {
					_mkr setMarkerPosLocal [0,0];
					_mkr setMarkerTextLocal "";
					_mkr setMarkerAlphaLocal 0;
				};
			};
		};
    };
};

0 spawn {
	sleep 10;
	["marker_vecs", {if (visibleMap || GVAR(do_ma_update_n)) then {call FUNC(X_XMarkerVehicles)}}, 1.98] call FUNC(addPerFrame);
	["marker_units", {
		if (visibleMap || GVAR(do_ma_update_n)) then {
			if (GVAR(show_player_marker) > 0) then {
				call FUNC(X_XMarkerPlayers);
				if (GVAR(with_ai)) then {
					call FUNC(X_XAI_Markers);
				};
			};
		};
	}, 2.02] call FUNC(addPerFrame);
};