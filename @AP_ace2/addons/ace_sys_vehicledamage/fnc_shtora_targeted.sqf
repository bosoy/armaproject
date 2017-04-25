// #define DEBUG_MODE_FULL
#define MAX_SMOKE 15
#define TIME_LIMIT 30

#include "script_component.hpp"

// TODO: Need special logic for sys_missileguidance! As there's no incomingMissile event played.
// LOBL is now covered in sys_missileguidance

private ["_wpn","_distance", "_enabled", "_failure", "_count", "_laser", "_gunner", "_smokeData"];
PARAMS_3(_who,_unit,_laserObj);

// Shtora Enabled/Disabled on this unit (Player/Action sensitive)?
_enabled = _unit getVariable [QGVAR(shtora), true]; // Set the variable ?
if !(_enabled) exitWith {};

if !(alive _unit) exitWith {
	TRACE_1("Abort. Unit not alive",_unit);
};

// ATM targeted event only LOCAL to targeter.
_gunner = gunner _unit;
if (isNull _gunner) exitWith {
	TRACE_1("Abort. No gunner",_unit);
};

if (isNull (commander _unit)) exitWith {
	TRACE_1("Abort. No commander (to fire smoke)", _unit); // fire command only works when there's an AI in the seat
};

if (isPlayer (commander _unit)) exitWith {
	TRACE_1("Abort. Player commander", _unit); // fire command only works with AI
};

_busy = _unit getVariable [QGVAR(busy_laser), false];
if (_busy) exitWith { TRACE_1("Abort. Already busy",_unit) };
_unit setVariable [QGVAR(busy_laser), true];

_enabled = false; _failure = false; _laser = false;

_laser = true;
_enabled = true;

// Turn turret to unit
// Find more methods to turn turret? doWatch might give target and fire upon _who :P
// Locallity isues? Where to execute it ?
if (isNull _gunner) then {
	// TODO: Use Dummy AI incase gunnery is Null ??
} else {
	// TODO: How to do when gunner is a player?? Should find a setWeaponDirection
	if (isPlayer _gunner) then {
		TRACE_2("Player - Commanding to watch",_unit,_gunner);
		_gunner commandWatch (getPos _who);
	} else {
		TRACE_2("AI - Moving turret",_unit,_gunner);
		_gunner doWatch (getPos _who);
	};
};

_smokeData = _unit getVariable [QGVAR(smoke), [0, 0]];
_count = _smokeData select 0;
if (_count <= MAX_SMOKE && {time > (_smokeData select 1)}) then {
	// wait until turret turns in general direction of threat, fire shmoke
	// if veh is moving fast perpendicular or towards the threat, no use in smoke
	if ((speed _unit < 15) || {([getpos _unit,[(getDir _unit)-180] call CBA_fnc_simplifyAngle,90,getpos _who] call BIS_fnc_inAngleSector)}) then {
		ADD(_count,1);
		_smokeData set [0, _count];
		_smokeData set [1, time + TIME_LIMIT];
		_unit setVariable [QGVAR(smoke), _smokeData, true];

		_wpn = (weapons _unit) select 0;
		[_unit,_who,_wpn] spawn {
			PARAMS_3(_unit,_who,_wpn);
			private ["_sl","_waz","_t"];
			_sl = false;
			_t = time;
			waituntil {
				if (_sl) then { sleep 0.3 };	//quick reaction if already good to launch
				_sl = true;
				_waz = (_unit weapondirection _wpn) call CBA_fnc_vectDir;
				((time - _t) > 5) || {([getpos _unit,_waz,90,getpos _who] call BIS_fnc_inAngleSector)}
			};
			if (isNull (commander _unit)) exitWith {
				TRACE_1("Abort. No commander (to fire smoke)", _unit); // fire command only works when there's an AI in the seat
			};

			if (isPlayer (commander _unit)) exitWith {
				TRACE_1("Abort. Player commander", _unit); // fire command only works with AI
			};

			TRACE_1("Shtora Firing smoke",_unit);
			_unit selectweapon "SmokeLauncher";
			_unit fire ["SmokeLauncher","SmokeLauncher","SmokeLauncherMag"];
			_unit selectweapon _wpn;
		};
	};
} else {
	_failure = true; // But what if there's till smoke in the air :P
};
TRACE_3("Laser",_enabled,_failure,_count);

_unit setVariable [QGVAR(busy_laser), false];

// Play alert sound on player computers of players that are inside vehicle
[QGVAR(alarm), [_unit, _who]] call CBA_fnc_globalEvent;

_failure;