#define THIS_FILE "x_commonfuncs.sqf"
#include "x_setup.sqf"

#ifndef __TT__
FUNC(KBSendMsgAll) = {
	private "_kbsound";
	_kbsound = if (count _this > 2) then {_this select 2} else {[]};
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),_this select 0,["1","",_this select 1,_kbsound],true];
};
FUNC(KBSendMsgUnit) = {
	private "_kbsound";
	_kbsound = if (count _this > 3) then {_this select 3} else {[]};
	GVAR(kb_logic1) kbTell [_this select 0,GVAR(kb_topic_side),_this select 1,["1","",_this select 2,_kbsound],true];
};
#else
FUNC(KBSendMsgAll) = {
	private "_kbsound";
	_kbsound = if (count _this > 3) then {_this select 3} else {[]};
	if ((_this select 0) == "") then {
		GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W",_this select 1,["1","",_this select 2,_kbsound],true];
		GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E",_this select 1,["1","",_this select 2,_kbsound],true];
	} else {
		switch (_this select 0) do {
			case "HQ_W": {GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W",_this select 1,["1","",_this select 2,_kbsound],true]};
			case "HQ_E": {GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E",_this select 1,["1","",_this select 2,_kbsound],true]};
		};
	};
};
FUNC(KBSendMsgUnit) = {
	private "_kbsound";
	_kbsound = if (count _this > 3) then {_this select 3} else {[]};
	switch (side (_this select 0)) do {
		case west: {GVAR(hq_logic_en1) kbTell [_this select 0,"HQ_W",_this select 1,["1","",_this select 2,_kbsound],true]};
		case east: {GVAR(hq_logic_ru1) kbTell [_this select 0,"HQ_E",_this select 1,["1","",_this select 2,_kbsound],true]};
	};
};
#endif

FUNC(KBUseName) = {
	switch (worldName) do {
		case "chernarus": {
			_usename = switch (_this) do {
				case "Stary Sobor": {"StarySobor"};
				case "Pustoschka": {"Pustoshka"};
				case "Berezino Harbour": {"Town"};
				default {""};
			};
			if (_usename == "") then {_this} else {_usename}
		};
		case "Takistan": {
			_usename = switch (_this) do {
				case "Mulladost": {"Mulladoost"};
				case "Feruz-Abad": {"FeeruzAbad"};
				case "Sakhe": {"Sakhee"};
				case "Chak Chak": {"ChakChak"};
				default {""};
			};
			if (_usename == "") then {_this} else {_usename}
		};
		default {
			"Town"
		};
	}
};

FUNC(subSelect) = {
	/************************************************************
		Subarray Select
		By Andrew Barron

	Returns a sub-selection of the passed array. There are various
	methods the sub-array can be determined.

	Parameters: [array, beg, <end>]
	Returns: subarray

	array - Array to select sub array from.
	beg - Index of array to begin sub-array. If negative, index is
		counted from the end of array.
	end - Optional. Index of array to end the sub-array. If ommitted,
		remainder of the array will be selected. If negative, it
		specifies the length of the sub-array (in absolute form).

	Examples:

		_array = ["a","b",true,3,8];
		[_array, 2] call FUNC(subSelect); //returns [true,3,8]
		[_array, -2] call FUNC(subSelect); //returns [3,8]
		[_array, 1, 3] call FUNC(subSelect); //returns ["b",true,3]
		[_array, 1, -2] call FUNC(subSelect); //returns ["b",true]

	************************************************************/

	private ["_ary","_beg","_len","_end","_ret","_i"];
	PARAMS_2(_ary,_beg);
	_ret = [];
	_len = (count _ary)-1;
	if (_beg < 0) then {_beg = _len + _beg + 1};
	_end = if (count _this > 2) then {_this select 2} else {_len};
	if (_end < 0) then {_end = _beg - _end - 1};
	if (_end > _len) then {_end = _len};
	for "_i" from _beg to _end do {_ret set [count _ret, _ary select _i]};
	_ret
};

FUNC(arrayInsert) = {
	/************************************************************
		Array Insert
		By Andrew Barron

	Parameters: [base array, insert array, index]
	Returs: [array]

	Inserts the elements of one array into another, at a specified
	index.

	Neither arrays are touched by reference, a new array is returned.

	Example: [[0,1,2,3,4], ["a","b","c"], 1] call FUNC(arrayInsert)
	Returns: [0,"a","b","c",1,2,3,4]
	************************************************************/

	private ["_baseArray","_toInsert","_index","_ret"];
	PARAMS_3(_baseArray,_toInsert,_index);
	if (_index > 0) then {
		_ret = [_baseArray, 0, _index-1] call FUNC(subSelect);
		[_ret, _toInsert] call FUNC(arrayPushStack2);
	} else {
		_ret = _toInsert;
	};
	[_ret, [_baseArray, _index] call FUNC(subSelect)] call FUNC(arrayPushStack2);
	_ret
};

FUNC(returnVehicleTurrets) = {
	/*
		File: fn_returnVehicleTurrets.sqf
		Author: Joris-Jan van 't Land

		Description:
		Function return the path to all turrets and sub-turrets in a vehicle.

		Parameter(s):
		_this select 0: vehicle config entry (Config)

		Returns:
		Array of Scalars and Arrays - path to all turrets
	*/
	if (count _this < 1) exitWith {[]};
	private "_entry";
	PARAMS_1(_entry);
	if (typeName _entry != typeName configFile) exitWith {[]};
	private ["_turrets", "_turretIndex"];
	_turrets = [];
	_turretIndex = 0;
	for "_i" from 0 to (count _entry - 1) do {
		private "_subEntry";
		_subEntry = _entry select _i;
		if (isClass _subEntry) then {
			private "_hasGunner";
			_hasGunner = [_subEntry, "hasGunner"] call FUNC(returnConfigEntry);
			if (!isNil "_hasGunner") then {
				if (_hasGunner == 1) then {
					_turrets set [count _turrets, _turretIndex];
					if (isClass (_subEntry >> "Turrets")) then {
						_turrets set [count _turrets, [_subEntry >> "Turrets"] call FUNC(returnVehicleTurrets)];
					} else {
						_turrets set [count _turrets, []];
					};
				};
			};
			__INC(_turretIndex);
		};
	};
	_turrets
};

FUNC(returnConfigEntry) = {
	/*
		File: returnConfigEntry.sqf
		Author: Joris-Jan van 't Land

		Description:
		Explores parent classes in the run-time config for the value of a config entry.
		
		Parameter(s):
		_this select 0: starting config class (Config)
		_this select 1: queried entry name (String)
		
		Returns:
		Number / String - value of the found entry
	*/
	if (count _this < 2) exitWith {nil};
	private ["_config", "_entryName"];
	PARAMS_2(_config,_entryName);
	if (typeName _config != typeName configFile) exitWith {nil};
	if (typeName _entryName != typeName "") exitWith {nil};
	private ["_entry", "_value"];
	_entry = _config >> _entryName;
	if (configName (_config >> _entryName) == "" && !((configName _config) in ["CfgVehicles", "CfgWeapons", ""])) then {
		[inheritsFrom _config, _entryName] call FUNC(returnConfigEntry);
	} else {
		if (isNumber _entry) then {
			_value = getNumber _entry;
		} else {
			if (isText _entry) then {_value = getText _entry};
		};
	};
	if (isNil "_value") exitWith {nil};
	_value
};

// FUNC(ARTY_PV_NETSADARM) = {
    // private ["_type", "_px", "_py", "_pz", "_dx", "_dy", "_dz", "_xoff", "_yoff", "_zoff", "_dir", "_pos", "_offset", "_hmag", "_burst"];
    // _type = _this select 0;_pos = _this select 1;_offset = _this select 2;
    // _px = _pos select 0;_py = _pos select 1;_pz = _pos select 2;
    
    // _xoff = _offset select 0;_yoff = _offset select 1;_zoff = _offset select 2;
    
    // if (!isNull player && (_pos distance player) < 900) then {
        // _burst = "ARTY_SADARM_BURST" createVehicleLocal [_px, _py, _pz + 5];
        // _burst setPos [_px, _py, _pz + 5];
    // };
    
    // _projectile = _type createVehicleLocal [_px, _py, _pz + 5];
    // _projectile setPos [_px, _py, _pz + 5];
    
    ////Calculate direction
    // _mag = sqrt(_xoff*_xoff + _yoff*_yoff + _zoff*_zoff);
    // _dir = [_xoff/_mag, _yoff/_mag, _zoff/_mag];
    // _dx = _dir select 0;
    // _dy = _dir select 1;
    // _dz = _dir select 2;
    // _hmag = sqrt(_dx*_dx + _dy*_dy);
    // _zcomp = -_dz/_hmag;
    // _ux = _zcomp*_dx;
    // _uy = _zcomp*_dy;
    // _uz = _hmag;
    // _projectile setVectorDir _dir;
    // _projectile setVectorUp [_ux,_uy,_uz];
    // _projectile setVelocity [(_dir select 0) * 300, (_dir select 1) * 300, (_dir select 2) * 300];
// };

// FUNC(SadarmDeploy) = {
	// private ["_altitude", "_targets", "_targetToHit", "_projectile", "_px", "_py", "_pz", "_v0", "_seekerHits"];
	// _shell = _this select 0;
	// _deployPos = getPos _shell;
	// deleteVehicle _shell;
	// _targetFound = 0;
	// _px = _deployPos select 0; _py = _deployPos select 1; _pz = _deployPos select 2;
	// _simFallRate = -36;
	// _lastFrame = time;

	// waitUntil {
		// if (_pz < 275 and _pz > 75) then {
			// _seekerHits = [_px, _py, 0] nearEntities [["Car","Tank","StaticCannon"], 200];
			// _targets = [];
			// {if (alive _x) then {_targets set [count _targets, _x]}} forEach _seekerHits;
			// if (count _targets > 0) then {
				// _targetToHit = _targets select floor(random(count _targets));
				// sleep (random 3); 
				// _targetFound=1;
			// };
		// };
		// _pz = _pz + _simFallRate*(time - _lastFrame);
		// _lastFrame = time;
		// sleep 0.2;
		// (_pz < 10 or _targetFound==1);
	// };

	// if (_targetFound==1) then {
		// _burst = "ARTY_SADARM_BURST" createVehicleLocal [_px, _py, _pz + 5];
		// _burst setPos [_px, _py, _pz + 5];
		// _projectile = "ARTY_SADARM_PROJO" createVehicleLocal [_px, _py, _pz + 5];
		// _projectile setPos [_px, _py, _pz + 5];

		// _xoff = (getPos _targetToHit select 0) - _px;
		// _yoff = (getPos _targetToHit select 1) - _py;
		// _zoff = - _pz;
		// _mag = sqrt(_xoff*_xoff + _yoff*_yoff + _zoff*_zoff);
		// _dir = [_xoff/_mag, _yoff/_mag, _zoff/_mag];
		// _dx = _dir select 0;
		// _dy = _dir select 1;
		// _dz = _dir select 2;
		// _hmag = sqrt(_dx*_dx + _dy*_dy);
		// _zcomp = -_dz/_hmag;
		// _ux = _zcomp*_dx;
		// _uy = _zcomp*_dy;
		// _uz = _hmag;

		// [QGVAR(ARTY_SADARM_NET), ["ARTY_SADARM_NET", [_px, _py, _pz + 5], [_xoff, _yoff, _zoff]]] call FUNC(NetCallEvent);

		// _projectile setVectorDir _dir;
		// _projectile setVectorUp [_ux,_uy,_uz];
		// _projectile setVelocity [(_dir select 0) * 300, (_dir select 1) * 300, (_dir select 2) * 300];
	// };
// };

FUNC(MHQFunc) = {
	_this setVariable [QGVAR(MHQ_Deployed), false];
	if (isServer) then {
		if (GVAR(NoMHQTeleEnemyNear) > 0) then {
			_this call FUNC(removeMHQEnemyTeleTrig);
		};
	};
};

FUNC(ConvertTime) = {
	private ["_timelong", "_mod", "_days", "_mod2", "_hours", "_mod3", "_minutes", "_seconds"];
	_timelong = _this;
	_mod = _timelong % 86400;
	_days = if (_mod == _timelong) then {0} else {floor(_timelong / 86400)};
	_mod2 = _mod % 3600;
	_hours = if (_mod2 == _mod) then {0} else {floor(_mod / 3600)};
	_mod3 = _mod2 % 60;
	_minutes = if (_mod3 == _mod2) then {0} else {floor(_mod2 / 60)};
	_seconds = round _mod3;
	_days = if (_days < 10) then {"0" + (str _days)} else {str _days};
	_hours = if (_hours < 10) then {"0" + (str _hours)} else {str _hours};
	_minutes = if (_minutes < 10) then {"0" + (str _minutes)} else {str _minutes};
	_seconds = if (_seconds < 10) then {"0" + (str _seconds)} else {str _seconds};
	(_days + "d " + _hours + "h " + _minutes + "m " + _seconds + "s")
};

x_commonfuncs_compiled = true;