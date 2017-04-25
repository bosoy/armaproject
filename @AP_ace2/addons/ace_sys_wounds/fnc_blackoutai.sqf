#include "script_component.hpp"
private ["_grpunit", "_isLeader", "_uncontime", "_bleed", "_pain", "_doex", "_uconl", "_carrier", "_grp"];
PARAMS_2(_unit,_knockout);
if (!local _unit) exitWith {};
if (isPlayer _unit) exitWith {};
_unit setVariable ["ace_w_wakeup",1];
_unit setVariable ["BIS_IS_inAgony",true];
//_unit setUnconscious true;
_grp = group _unit;
_isLeader = (_unit == leader _grp);
if (_isLeader) then {
	_newl = objNull;
	{
		private "_isu";
		_isu = _x call FUNC(isUncon);
		if (_x != _unit && {!_isu} && {alive _x}) exitWith {_newl = _x}
	} forEach units _grp;
	[QGVAR(selLeader), [_grp, _newl]] call CBA_fnc_globalEvent;
	{if (alive _x && {_x != _unit}) then {_x doFollow _newl}} forEach units _grp;
};
{_unit disableAI _x} forEach ["TARGET","AUTOTARGET","MOVE"];
// Drop out of static weapons 
if (vehicle _unit isKindOf "StaticWeapon") then {
	_unit action ["eject", vehicle _unit];
};
// Fall down from ladders
if (animationState _unit in ["ladderriflestatic","laddercivilstatic"]) then {
	_unit action ["ladderOff", (nearestBuilding _unit)];
	// Unit perhaps falls to death so we can exit script here anyway
	// Cancel last move order otherwise it attempts to climb up ladder again on waking up, when probably going unconscious again (loop)
	// if (currentCommand _unit == "MOVE") then { }; // Order it to wait
};

[QGVAR(cap), [_unit,true]] call CBA_fnc_globalEvent;
_uncontime = 0;
while {(_unit call FUNC(isUncon)) && {alive _unit}} do {
	if (!isNil "ace_sys_wounds_enabled" && {!_knockout}) then {
		_uncontime = 3;
		_bleed = _unit getVariable "ace_w_bleed";
		_pain = _unit getVariable "ace_w_pain";
		if (_bleed > 0.3 || {_pain > 0.3}) then {_uncontime = _uncontime + (_bleed * 8) + (_pain * 8)};
	} else {
		_uncontime = 3;
	};
	if (!alive _unit) exitWith {};
	if (vehicle _unit == _unit && {_unit call FUNC(isUncon)} && {isNull (_unit getVariable ["ace_w_carry", objNull])}) then {
		if ((_unit call CBA_fnc_getUnitDeathAnim) != "") then {
			[_unit, 100] call FUNC(animator2);
		};
	};

	private ["_vecp","_endtime"];
	_vecp = vehicle _unit;
	_endtime = time + (_uncontime * 2);
	waitUntil {time >= _endtime || {!alive _unit} || {(_vecp != vehicle _unit)} || {!(_unit call FUNC(isUncon))}};
	if (!alive _unit || {!(_unit call FUNC(isUncon))}) exitWith {};
	if (vehicle _unit == _unit && {_unit call FUNC(isUncon)} && {isNull (_unit getVariable ["ace_w_carry", objNull])}) then {
		if ((_unit call CBA_fnc_getUnitDeathAnim) != "") then {
			[_unit, 100] call FUNC(animator2);
		};
	};
	if (vehicle _unit != _unit) then {
		_vecx = vehicle _unit;
		_vacm = _vecx getVariable "ace_canmove";
		_alv = if (isNil "_vacm") then {alive _vecx} else {_vecx call ace_v_alive};
		if (!_alv) then {
			_unit action ["eject", _vecx];
			waitUntil {vehicle _unit == _unit};
			[_unit, 100] call FUNC(animator2);
		};
	};
	_doex = false;
	if ((_unit getVariable "ace_w_state") != 802) then {
		_uconl = _unit getVariable "ace_w_unconlen";
		if (_uconl != -1 && {time > _uconl}) then {_doex = true};
	};
	if (_doex) exitWith {};
};
if (vehicle _unit != _unit) then {
	_vecx = vehicle _unit;
	_vacm = _vecx getVariable "ace_canmove";
	_alv = if (isNil "_vacm") then {alive _vecx} else {_vecx call ace_v_alive};
	if (!_alv) then {
		_unit action ["eject", _vecx];
		waitUntil {vehicle _unit == _unit};
		[_unit, 100] call FUNC(animator2);
	};
};
if (alive _unit) then {
	_unit setVariable ["ace_w_wakeup",0];
	sleep 5;
	if (!isNull (_unit getVariable "ace_w_carry")) then {
		_carrier = _unit getVariable "ace_w_carry";
		waitUntil {isNull (_unit getVariable "ace_w_carry") || {!alive _carrier} || {isNull _carrier}};
		_unit setVariable ["ace_w_carry", objNull];
		sleep 1;
	};
	_unit setUnitPos "DOWN";
	if (vehicle _unit == _unit) then {
		_sec = currentWeapon _unit;
		if (_sec != "" && _sec != " ") then {
			if (getNumber (configFile >> "CfgWeapons" >> _sec >> "type") == 4) then {
				_iswater = surfaceIsWater getPosASL _unit;
				_ppos = if (_iswater) then {getPosASL _unit} else {getPosATL _unit};
				_pdir = direction _unit;
				_ACE_HeadbugFix = "ACE_Headbug_Fix" createVehicleLocal _ppos;
				if (_iswater) then {_ACE_HeadbugFix setPosASL _ppos} else {_ACE_HeadbugFix setPosATL _ppos};
				_ACE_HeadbugFix setDir _pdir;
				_unit moveInDriver _ACE_HeadbugFix;
				waitUntil {vehicle _unit != _unit};
				unassignVehicle _unit;
				_unit action ["Eject", vehicle _unit];
				waitUntil {vehicle _unit == _unit};
				if (_iswater) then {_unit setposASL _ppos} else {_unit setposATL _ppos};
				_unit setDir _pdir;
				deleteVehicle _ACE_HeadbugFix;
			};
		};
		[_unit, 102] call FUNC(animator);
	};
	_unit setVariable ["ace_w_unconlen",-1];
	if (!isNil "ace_sys_wounds_enabled") then {
		_unit setVariable [QGVAR(uncon),false,true];
	} else {
		_unit setVariable [QGVAR(uncon),false];
	};
	_unit setVariable ["BIS_IS_inAgony",false];
	//_unit setUnconscious false;
	_unit setVariable ["ace_w_nextuncon", time + (30 + random 30)]; // TODO: rework it so that it also takes pain and bleeding into the calculation
	sleep 5 + random 5;
	if (alive _unit && {!(_unit call FUNC(isUncon))}) then {
		{_unit enableAI _x} forEach ["TARGET","AUTOTARGET","MOVE"];
		_unit setUnitPos "AUTO";
	};
};
[QGVAR(cap), [_unit,false]] call CBA_fnc_globalEvent;
if (alive _unit) then {
	if (rating _unit < 0) then {
		_unit addRating abs(rating _unit);
	};
	if (_isLeader) then {
		[QGVAR(selLeader), [_grp, _unit]] call CBA_fnc_globalEvent;
		{if (_x != _unit) then {_x doFollow _unit}} forEach units _grp;
	};
	// Handle AI use medical items
	if (!(_unit getVariable ["ace_w_check", false])) then {
		_unit setVariable ["ace_w_check", true];
		[_unit] spawn {
			PARAMS_1(_unit);
			sleep (4 + random 2);
			if (!alive _unit || {_unit call FUNC(isUncon)}) exitWith { _unit setVariable ["ace_w_check", false] };
			[_unit, _unit] call FUNC(help);
			_unit setVariable ["ace_w_check", false];
		};
	};
};
