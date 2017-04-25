// TODO: Look into not deleting markers until it's relevant object is null; instead, hide the markers until they are required again?
// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfgVehicle configFile >> "CfgVehicles" >> _type

private ["_markers", "_markersRun", "_markerId", "_fnc_setMarker", "_fnc_group", "_fnc_veh", "_pvt"];

_markers = []; 
_markerId = 0;

_fnc_manning = {
	private "_unit";
	_unit = commander _this;
	if !(isNull _unit) exitWith { [_x, _unit] };
	_unit = driver _this;
	if !(isNull _unit) exitWith { [_x, _unit] };
	_unit = gunner _this;
	if !(isNull _unit) exitWith { [_x, _unit] };
	[];
};

_fnc_marker = {
	// Uses _side, _grp
	PARAMS_3(_object1,_object2,_groupName);
	_type = typeOf (vehicle _object1);
	_oldName = _object2 getVariable QGVAR(oldname);
	_marker = _object2 getVariable QGVAR(marker);
	if (isNil "_oldname" || {_oldname != _groupName}) then {
		_arname = toArray _groupName;
		_arname set [0, -1]; 
		_arname set [1, -1];
		_arname = _arname - [-1];
		_object2 setVariable [QGVAR(oldname), _groupName];
		_groupName = toString _arname;
		_object2 setVariable [QGVAR(name), _groupName];
	} else {
		_groupName = _object2 getVariable QGVAR(name);
	};

	if (isNil "_marker") then {
		ADD(_markerId,1);
		_marker = format[QGVAR(marker) + "%1", _markerId];
		createMarkerLocal [_marker, getPosASL _object1];
		_marker setMarkerTextLocal _groupName;
		_marker setMarkerShapeLocal "Icon";
		_marker setMarkerColorLocal "ColorBlue";
		_marker setMarkerTypeLocal ([(__cfgVehicle >> QGVAR(marker)), "text", "DOT"] call CBA_fnc_getConfigEntry);
		_marker setMarkerSizeLocal [1,1];

		_object2 setVariable [QGVAR(name), _groupName];
		_object2 setVariable [QGVAR(type), _type];
		_object2 setVariable [QGVAR(marker), _marker];
		TRACE_6("Created Marker",_groupName,_object1,_object2,_type,_side,_marker);
	} else {
		_marker setMarkerTextLocal _groupName;
		_marker setMarkerPosLocal (getPosASL _object1);

		if (_type != _object2 getVariable QGVAR(type)) then {
			_object2 setVariable [QGVAR(type), _type];
			_marker setMarkerTypeLocal ([(__cfgVehicle >> QGVAR(marker)), "text", "DOT"] call CBA_fnc_getConfigEntry);
			_marker setMarkerSizeLocal [1,1];
		};

		TRACE_6("Updated Marker",_groupName,_object1,_object2,_type,_side,_marker);
	};
	PUSH(_markersRun,_marker);
};

_fnc_handle_group = {
	private ["_gpsReq", "_marker", "_groupName", "_leader", "_type", "_side", "_exit", "_oldName", "_override", "_veh"];
	_side = side _x; 
	_leader = leader _x;
	if !(count (units _x) > 0 && {!(captive _leader)} && {(_side == playerSide || {GVAR(markers_debug)})}) then {
		_x setVariable [QGVAR(marker), nil];
	} else {
		// Overrides
		_override = _leader getVariable QGVAR(marker_override);
		if !(isNil "_override") exitWith {};
		_override = _x getVariable QGVAR(marker_override);
		if !(isNil "_override") exitWith {};

		_veh = vehicle _leader;

		// Requirements
		_exit = false;
		if (_veh == _leader) then {
			// Radio Required
			private "_done";
			_exit = true; _done = false;
			{
				{ if (getNumber(configFile >> "CfgWeapons" >> _x >> "ace_is_radio") == 1) exitWith {_exit = false; _done = true} } forEach (weapons _x);
				if (_done) exitWith {};
			} forEach (units _x);

			// GPS Required
			private "_done";
			_exit = true; 
			_done = false;
			{ if (_x call FUNC(hasGPS)) exitWith {_exit = false} } forEach (units _x);
		} else {
			if (count (_veh call _fnc_manning) > 0) then { _exit = true }; // Vehicle marker takes precence atm - perhaps need to add the info in markertext?
		};
		if (_exit) exitWith {_x setVariable [QGVAR(marker), nil]};

		// Handle Marker
		[_leader, _x, str(_x)] call _fnc_marker;
	};
};

_pvt = ["_manning", "_unit", "_grp", "_side", "_vehicles", "_override"];
_fnc_handle_vehicle = { // Display empty vehicles later
	private _pvt;

	// Requirements: a) not overidden, b) Tracker activated
	_override = _x getVariable [QGVAR(marker_override), false];
	if (!isNil "_override" && {_override}) then {
		_x setVariable [QGVAR(marker), nil];
	} else {
		_activated = _x getVariable [QGVAR(device_active),false];
		if (!_activated) exitWith { _x setVariable [QGVAR(marker), nil] };
		
		// TODO: COLOR, CALLSIGN for 'complete component'
		_grpowner = _x getVariable [QGVAR(device_owner),objNull];
		_callsign = "";
		_grp = if (isNull _grpowner) then { NULL } else { group _grpowner};
		
		// Handle Marker
		// TODO: Formatting
		if (_callsign != "") then {
			[_x, _x, (str(_grp) + "("+ _callsign +")")] call _fnc_marker;
		} else {
			[_x, _x, str(_grp)] call _fnc_marker;		
		};
	};
};

// MarkerHandler - endless loop
private "_continue";
while { true } do {
	// Verify if we need to run, or cleanup and wait
	// Only show markers if player is in a BT / RT vehicle on the internal map
	// Only show markers if player has the device, then show on the internal map
	// Do not show on map of infantry
	
	_vehicle = player != vehicle player && {if ((vehicle player) isKindOf "Tank") then { player == (commander vehicle player) } else { player in [(commander vehicle player)] || {player in (assignedCargo vehicle player)} }};
	_hasGPS = player call FUNC(hasGPS);
	_hasRadio = ({getNumber(configFile >> "CfgWeapons" >> _x >> "ace_is_radio") == 1} count (weapons player)) > 0 || { "ItemRadio" in weapons player };
	// TODO: If ACRE is on, check bad connection
	_visiblemap = if (!_vehicle) then { !visibleMap } else { false }; // TODO: Decide wether to show markers on map if IN a vehicle with device or via device display only
	
	if (_vehicle) then { // Check for vehicle 
		_continue = _hasGPS && { (vehicle player) getVariable [QGVAR(device_active),false] }; //diag_log format ["Player: cont = %1 gps = %2 visibleMap = %3",_continue,_hasGPS,visibleMap];
	} else { // Check for infantry
		_continue = _hasGPS && {_hasRadio} && {!visibleMap}; //diag_log format ["Player: cont = %1 gps = %2 radio = %3 visibleMap = %4",_continue,_hasGPS,_hasRadio,visibleMap];
	};
	
	if (!_continue) then {
		{ deleteMarkerLocal _x } forEach _markers;
		{ _x setVariable [QGVAR(marker), nil] } forEach allGroups;
		{ _x setVariable [QGVAR(marker), nil] } forEach vehicles;
		_markers = []; 
		_markerId = 0;
		waitUntil { sleep 2; GVAR(enabled) };
	};

	_markersRun = [];
	if (_continue) then {
		// Handle groups
		{ call _fnc_handle_group } forEach allGroups;

		// Handle Vehicles
		{ call _fnc_handle_vehicle } forEach vehicles;

		// Cleanup
		{ deleteMarkerLocal _x } forEach (_markers - _markersRun);

		_markers = _markersRun;
	};
	sleep 2;
};
