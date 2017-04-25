Private ["_damage","_damages","_isStuned","_lastWound","_type","_unit"];

_unit = _this select 0;
_type = _this select 1;
_damages = _this select 2;

if (vehicle _unit == _unit) then {
	_isStuned = _unit getVariable "stunned";
	_lastWound = _unit getVariable "lastWound";
	if (isNil "_isStuned") then {_isStuned = false};
	if (isNil "_lastWound") then {_lastWound = round(time)};
	if (_isStuned) exitWith {
		if (time - _lastWound > 3) then {_damages} else {false}
	};

	_unit setVariable ["lastWound",round time];
	_damage = true;

	switch (_type) do {
		case "head_hit": {
			if (_damages > 0.4 && _damages < 1) then {
				if (random 100 > 40) then {_unit setVariable ['stunned',true,true];_isStuned = true};
			};
			if (_damages >= 1 && _damages < 5) then {
				if (random 100 > 40) then {_unit setVariable ['stunned',true,true];_isStuned = true;_damage = false};
			};
		};
		case "body": {
			if (_damages > 0.65 && _damages < 1) then {
				if (random 100 > 50) then {_unit setVariable ['stunned',true,true];_isStuned = true};
			};
			if (_damages >= 1 && _damages < 20) then {
				if (random 100 > 40) then {_unit setVariable ['stunned',true,true];_isStuned = true;_damage = false};
			};
		};
		case "hands": {
			if (_damages > 0.76 && _damages < 1) then {
				if (random 100 > 50) then {_unit setVariable ['stunned',true,true];_isStuned = true};
			};
			if (_damages >= 1 && _damages < 20) then {
				if (random 100 > 50) then {_unit setVariable ['stunned',true,true];_isStuned = true;_damage = false};
			};
		};
		case "legs": {
			if (_damages > 0.68 && _damages < 1) then {
				if (random 100 > 50) then {_unit setVariable ['stunned',true,true];_isStuned = true};
			};
			if (_damages >= 1 && _damages < 20) then {
				if (random 100 > 50) then {_unit setVariable ['stunned',true,true];_isStuned = true;_damage = false};
			};
		};
		case "": {
			_damage = false;
		};
	};

	if (_isStuned) then {[_unit] Spawn ISIS_Wounded};

	if (_damage) then {_damages} else {false};
} else {
	_damages
};