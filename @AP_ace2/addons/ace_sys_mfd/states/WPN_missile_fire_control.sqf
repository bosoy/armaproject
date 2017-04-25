//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_mfd\script_component.hpp"

TRACE_1("ENTER","");
private ["_maxRows", "_currentCode", "_fireMode", "_fireModeString", "_burstLevel", "_hasCbuSelection"];
private ["_hasFireModeSelection"];

//_state = _this select 0;
PARAMS_1(_state);

// find if we have CBU's, if so, add the menu
_hasCbuSelection = false;
if((vehicle player) isKindOf "Plane") then {
	// TODO: Check that we actually support CBU's on the plane
	_burstLevel = (vehicle player) getVariable QUOTE(ace_sys_clusterbombs_burst_altitude);
	
	if(isNil "_burstLevel") then {
		_burstLevel = 50;
		(vehicle player) setVariable [QUOTE(ace_sys_clusterbombs_burst_altitude), _burstLevel, false];
	};
	_hasCbuSelection = true;
};

// find if we have a fire mode
// TODO: Check that we actually support hellfires
_hasFireModeSelection = false;
if((vehicle player) isKindOf "Helicopter" || {(vehicle player) isKindOf "MQ9PredatorB"}) then {
	LOG("we have fire modes");
	_fireMode = (vehicle player) getVariable QUOTE(ace_sys_missileguidance_hellfire_mode);
	
	if(isNil "_fireMode") then {
		_fireMode = 0;
		
		(vehicle player) setVariable [QUOTE(ace_sys_missileguidance_hellfire_mode), 0, false];
	};
	TRACE_1("",_fireMode);
	switch (_fireMode) do {
		case 1: {_fireModeString = "LOAL - DIR"; };
		case 2: {_fireModeString = "LOAL - DIR LOW"; };
		case 3: {_fireModeString = "LOAL - DIR HI"; };
		default	{_fireModeString = "LOBL"; };
	};
	
	_hasFireModeSelection = true;
};

[] call FUNC(clearAllText);
switch (GVAR(lastKeyPressed)) do {
	case "1": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN"];
	};
	case "3": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control", "set_cbu_altitude"];
	};
	case "4": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control", "set_fire_mode"];
	};
	case "2": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control", "set_laser_code"];
	};
	default {
		_currentCode = (vehicle player) getVariable "ACE_CURRENT_LASERTARGET_CODE";
		
		if (!isNil QGVAR(lastKeyPressed)) then {
			// do our key-presses for up/down here
			if(GVAR(lastKeyPressed) == "7") then {
				if(_currentCode == 1999) then {
					_currentCode = 1001;
				} else {
					_currentCode = _currentCode + 1;
				};
				(vehicle player) setVariable ["ACE_CURRENT_LASERTARGET_CODE", _currentCode, false];
			} else {
				if(GVAR(lastKeyPressed) == "4") then {
					if(_currentCode == 1001) then {
						_currentCode = 1999;
					} else {
						_currentCode = _currentCode - 1;
					};
					(vehicle player) setVariable ["ACE_CURRENT_LASERTARGET_CODE", _currentCode, false];
				};
			};
		};
		
		_maxRows = ([] call FUNC(getMaxRows)) - 2;
		TRACE_1("", _maxRows);
		[1, format["   Current Laser Code: %1",_currentCode]] call FUNC(setRowText);
		
		if(_hasFireModeSelection) then {
			[3, format["   Current Fire Mode: %1", _fireModeString]] call FUNC(setRowText);
			[(_maxRows - 5), format["Change Fire Mode 4."]] call FUNC(setRowText_AlignRight);
		};
		
		if(_hasCbuSelection) then {
			[2, format["   CBU Burst Alt: %1m", _burstLevel]] call FUNC(setRowText);
			[(_maxRows - 4), format["Change Burst Alt 3."]] call FUNC(setRowText_AlignRight);
		};
		
		[(_maxRows - 3), format["Change Laser Code 2."]] call FUNC(setRowText_AlignRight);
		[(_maxRows - 2), format["Back 1."]] call FUNC(setRowText_AlignRight);
	};
};

_state
