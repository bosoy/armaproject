/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private "_parts";

PARAMS_2(_data,_mode);

_wire = _data select 0;
_killer = _data select 1;

if (isNull _killer || {_killer == _wire} || {_killer == gunner (vehicle _killer)}) exitWith {};

// _mode = 0 = Single Coil
// _mode = 1 = Triple Coil


// --------------------------------
// L              M               R
//                                4.54929 (4)
//              6.13564 (6)
//9.78744 (10)


_distance = _wire distance _killer;
if (_distance > 14 || {_distance < 2}) exitWith {}; // Fix if shooting wire

_type = typeOf _wire;
_anim = _wire animationPhase "wire_2";
_pos_w = getPos _wire;
_dir_w = getDir _wire;
_vehicle = vehicle _killer;

if (_mode == 0) then {
	private "_found";
	_x = _pos_w select 0;
	_y = _pos_w select 1;
	// Check if two Single coils are placed next to each other (i.e playes have built a big wire obstacle)
	_wireCheckPosAr = [
		[_x + (sin (_dir_w+90) * 1.5),_y + (cos (_dir_w+90) * 1.5)],
		[(_x-(sin _dir_w)) + (sin (_dir_w+90) * 1.5),(_y-(cos _dir_w)) + (cos (_dir_w+90) * 1.5)],
		[_x + (sin (_dir_w-90) * 1.5),_y + (cos (_dir_w-90) * 1.5)],
		[(_x-(sin _dir_w)) + (sin (_dir_w-90) * 1.5),(_y-(cos _dir_w)) + (cos (_dir_w-90) * 1.5)]
	];
	{
		_found = false;
		_no = nearestObjects [_x, [typeOf _wire], 3]; 	//diag_log _no; diag_log ".....";
		_no = _no - [_wire];							//diag_log _no;
		if (count _no > 0) exitWith {
			_found = true;								//diag_log "found";
		};
	} foreach _wireCheckPosAr;
	// Double coil found!
	if (_found) then {
		_mode = 1;
	} else {
		// Randomly make a single coil also catch tanks, if speed is high
		if (_vehicle isKindOf "Tank" && {20 > random 100} && {speed _vehicle > 30}) then {
			_mode = 1;
		} else {
			if !(_vehicle isKindOf "Tank") then {
				_mode = 1;
			};
		};
	};
};

if (_mode == 1) then {
	switch (true) do {
		case (_vehicle isKindOf "Tank"): {
			_parts = ["ltrack","rtrack"];		
		};
		case (_vehicle isKindOf "Wheeled_APC" || {_vehicle isKindOf "Car"}): {
			_parts = ["lfwheel","lf2wheel","lmwheel","lbwheel","rfwheel","rf2wheel","rmwheel","rbwheel"];		
		};
	};
} else {
	switch (true) do {
		case (_vehicle isKindOf "Wheeled_APC" || {_vehicle isKindOf "Car"}): {
			_parts = ["lfwheel","lf2wheel","lmwheel","lbwheel","rfwheel","rf2wheel","rmwheel","rbwheel"];		
		};
	};
};

if (canMove _vehicle) then {
	{
		_selectionPart = "hit" + _x;
		if (isText(configFile >> "CfgVehicles" >> typeOf _vehicle >> "hitpoints" >> _selectionPart >> "name")) then {
			_selection = getText(configFile >> "CfgVehicles" >> typeOf _vehicle  >> "hitpoints" >> _selectionPart >> "name");
			_vehicle setHit [_selection,1];
		};
	} foreach _parts; //TODO: Check sys_vehicle_damage compatibility
};

if (_mode == 1) then {
	[_vehicle,_wire] spawn {
		_vehicle = _this select 0;
		if (_vehicle isKindOf "StaticWeapon") exitWith {}; 
		sleep 0.1;
		_wire = _this select 1;
		_vel = velocity _vehicle;
		_vehicle setvelocity [(_vel select 0)*0.75, (_vel select 1)*0.75, (_vel select 2)*0.75];
		//_vehicle setVelocity [0,0,0];
		// Set vehicle back in front of wire, since the wire will make the vehicle jump, and a wire with no geometry lod is undestructible and not recognizeable
		_vPos = getPos _vehicle; //_wire; 
		_vDir = getDir _vehicle;
		_vehicle setPos [(_vPos select 0) - ((sin _vDir) * .35), (_vPos select 1) - ((cos _vDir) * .35), 0]; 
		// TODO: Needs to be placed in safe distance to wire, so we do not constantly re-spawn new wires
	};
};


//TODO: Create broken geoless wire (two version)
//TODO: Make wire remains stop vehicles


