// by Xeno
#define THIS_FILE "x_sabotage.sqf"
#include "x_setup.sqf"
private ["_grp","_leader","_mags","_no","_obj","_obj_pos","_one_shell","_shell_unit"];
if (!isServer) exitWith {};

PARAMS_1(_grp);

_grp setBehaviour "AWARE";
_grp setCombatMode "YELLOW";

if (isNull _grp) exitWith {};

#ifdef __OA__
{_x addMagazine "PipeBomb"} forEach (units _grp);
#endif

while {(_grp call FUNC(GetAliveUnitsGrp)) > 0} do {
	__MPCheck;
	if (isNull _grp) exitWith {};
	_leader = leader _grp;
	if (isNull _leader) then {
		sleep 5.121;
	};
	if (!isNull _leader) then {
		_no = nearestObjects [_leader,[GVAR(WarfareAircraftFactory_East), GVAR(WarfareAircraftFactory_West)], 300];
		sleep 0.32;
		if (count _no > 0) then {
			_obj = _no call FUNC(RandomArrayVal);
			if (alive _obj) then {
				_obj_pos = position _obj;
				_units = units _grp;
				for "_i" from 1 to 3 do {
					_one_shell = "";
					_shell_unit = objNull;
					{
						scopeName "xxxx3";
						_mags = magazines _x;
						_shell_unit = _x;
						{
							if (_x == "PipeBomb") then {
								_one_shell = _x;
								breakOut "xxxx3";
							};
						} forEach _mags;
						sleep 0.011;
					} forEach _units;
					if (_shell_unit == objNull) exitWith {};
					_units = _units - [_shell_unit];
					if (_one_shell != "") then {
						_shell_unit selectWeapon "PipeBombMuzzle";
						if (_leader == _shell_unit) then {
							_shell_unit doMove _obj_pos;
							_shell_unit doTarget _obj;
							_shell_unit doFire _obj;
						} else {
							_shell_unit commandMove _obj_pos;
							_shell_unit commandTarget _obj;
							_shell_unit commandFire _obj;
						};
					};
					if (!alive _obj) exitWith {};
				};
			};
		};
		_no = nil;
	};
	_timeend = time + 240 + (random 80);
	waitUntil {sleep 3.472; (time > _timeend || isNull _grp)};
	if (isNull _grp) exitWith {};
};
