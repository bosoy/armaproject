// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_unit", "_center", "_angle", "_x1", "_y1", "_protection", "_dist", "_group"];

PARAMS_1(_unit);
if (!alive _unit) exitWith {};

_intensity = if (count _this > 1) then {_this select 1} else {15};

_protection = [_unit] call ACE_fnc_hasCrewProtection;
if (_protection && {damage _unit < 0.33}) exitWith {}; // Unit can't catch fire due to awesome-suit

// Put away weapon/getout/etc
if !(isPlayer _unit) then {
	_group = (group _unit);
	_vehicle = vehicle _unit;
	
	if (_vehicle != _unit) then {
		TRACE_1("Ejecting", _unit);
		_unit leaveVehicle _vehicle;
		unassignVehicle _unit;
		_unit action ["eject",_vehicle];
	};
	_unit disableAI "TARGET";
	_unit disableAI "AUTOTARGET";

	if (secondaryWeapon _unit != "") then {
		_unit removeWeapon (secondaryWeapon _unit);
	};
	if (primaryWeapon _unit != "") then {
		_unit removeWeapon (primaryWeapon _unit);
	};

	// Run away
	_center = getPosASL _unit;
	if (leader _group != _unit) then {
		[_unit] join grpNull;
	};
	_center_x = _center select 0;
	_center_y = _center select 1;
	_angle = floor (random 360);
	_dist = (20 + (random 35));
	_x1 = _center_x + (_dist * sin _angle);
	_y1 = _center_y + (_dist * cos _angle);
	_unit doMove [_x1, _y1, 0];
	_unit setSpeedMode "FULL";
} else {
	_dist = 0;
	_group = (group _unit);
	if (secondaryWeapon _unit != "") then {
		_unit action ["dropWeapon", _unit, secondaryWeapon _unit];
	};
	if (primaryWeapon _unit != "") then {
		_unit action ["dropWeapon", _unit, primaryWeapon _unit];
	};
};

if (_protection) exitWith {};

// Put on fire
[QGVAR(burnmen), [_unit, _intensity, time, true]] call CBA_fnc_globalEvent;

// _unit switchmove ""; // TODO: Won't this desynchronize with the rest of the machines, because switchMove is local?


// Handle damage and ability to undo burning
[_unit, _dist, _group, _intensity] spawn {
	private ["_unit", "_soundidx", "_sound", "_dist", "_group"];
	PARAMS_4(_unit,_dist,_group,_intensity);
	sleep (0.7 + random 0.3);
	_runTime = time+(_dist*0.125);
	
	while {alive _unit && {([_unit] call ACE_fnc_isBurning)}} do {
		[_unit, 0.1*(15/_intensity)] call FUNC(addDamage);

		if !(_unit call FUNC(isUncon)) then {
			_soundidx = floor (random 15) + 1;
			_sound = "ACE_VDBrutalScream" + (_soundidx call CBA_fnc_intToString);
			[[_unit], _sound] call CBA_fnc_globalSay;
			TRACE_2("global say",_unit,_sound);
		};
		if (isPlayer _unit) then {
			if ((animationState _unit) in ["amovppnemstpsraswrfldnon_amovppnemevaslowwrfldl", "amovppnemstpsraswrfldnon_amovppnemevaslowwrfldr","amovppnemstpsnonwnondnon_amovppnemevasnonwnondl","amovppnemstpsnonwnondnon_amovppnemevasnonwnondr"]) then {
				_ran = random 100;
				if (surfaceIsWater getpos _unit) then { _ran = _ran - 100 }; // If in water, kill fire immediately
				if (rain > 0.5) then { _ran = _ran - random 15 };
				TRACE_1("chance to kill fire",_ran);
				if (_ran < 40) then {
					[QGVAR(burnoff), _unit] call CBA_fnc_globalEvent;
				};
			};
		} else {
			if (time > _runTime) then {
				call FUNC(roll);
			};
		};
		sleep (3 + random 3);
	};

	if (alive _unit && {!isPlayer _unit}) then {
		[_unit] join _group;
		_unit enableAI "TARGET";
		_unit enableAI "AUTOTARGET";
	};
};
