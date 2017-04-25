//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [CTB]
// Created: 20100815
// Contact: http://creobellum.org
// Purpose: Call in AI Support vehicles
///////////////////////////////////////////////////////////////////

private["_unit", "_veh", "_name", "_pos"];
_unit = _this select 0;
_veh = _this select 1;
_name = _this select 2;

// CLIENT actions
//- add actions & re-add on death
if (local player && leader player == player) then {
	[_veh, _name] spawn {
		_veh = _this select 0;
		_name = _this select 1;

		while {true} do {
			waitUntil {alive player};
			_act = player addAction [format["Call %1", _name], "crB_scripts\crB_CallSupport.sqf", [_veh, _name]];
			waitUntil {!alive player};
			player removeAction _act;
		};

		if (true) exitWith {};
	};
};

// ALL CLIENTS actions
//- remove marker
//- check if alive
//- notify players
//- mark map
//- wait until arrived or dead
//- remove marker
fc_callSupport = {
	private["_unit", "_veh", "_pos", "_name"];
	_unit = _this select 0;
	_veh = _this select 1;
	_pos = _this select 2;
	_name = _this select 3;

	_inuse = false;
	if (typeName callSupport == "ARRAY") then {
		_inuse = (currentCommand _veh == "" && (callSupport select 0) != _unit);
	};


	if (!alive _veh || _inuse) then {
		[side _unit, "Base"] sidechat format["%1 is not available", _name];
	} else {
		deleteMarker str _veh;
		_m = createMarker [str _veh, _pos];
		_m setMarkerText format["%1 destination", _name];
		_m setMarkerType "Pickup";
		_m setMarkerColor "ColorYellow";
		_m setMarkerSize [0.5, 0.5];

		waitUntil {!isNil "bis_fnc_init"};
		_grid = _pos call bis_fnc_PosToGrid;
		[side _unit, "Base"] sidechat format["%1 supporting %2 at %3%4", _name, name _unit, _grid select 0, _grid select 1];

		waitUntil{_veh distance _pos < 15 || !alive _veh};
		[side _unit, "Base"] sidechat format["%1 ready", _name];
		deleteMarker _m;
	};
};

if (!isServer) then {
	"callSupport" addPublicVariableEventHandler {
		callSupport spawn fc_callSupport;
	};
} else {
	// SERVER actions
	//- load units
	//- move vehicle
	//- wait until arrived or dead
	//- unload units
	fs_callSupport = {
		private["_unit", "_veh", "_pos"];
		_unit = _this select 0;
		_veh = _this select 1;
		_pos = _this select 2;
		_grp = group _veh;

		units _grp orderGetIn true;
		_veh move _pos;
		waitUntil{currentCommand _veh == "" || !alive _veh};
		(units _grp - [driver _veh]) orderGetIn false;
	};

	"callSupport" addPublicVariableEventHandler {
		callSupport spawn fs_callSupport;
	};
};
