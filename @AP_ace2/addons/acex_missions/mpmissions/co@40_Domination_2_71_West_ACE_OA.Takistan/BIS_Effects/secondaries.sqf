//Small secondary fuel explosions
//By Maddmatt for ArmA 2
// #define __DEBUG__
#define THIS_FILE "secondaries.sqf"
#include "x_setup.sqf"
private ["_v", "_int", "_list", "_lifecheck", "_stime", "_data"];
PARAMS_2(_v,_int);
__TRACE_2("","_v","_int");
if (isNull _v) exitWith {};
_list = [];
_lifecheck = if (count _this > 2) then {_this select 2} else {true};

//Generate intervals between explosions
_stime = time;
while {_int > 1} do {
	__DEC(_int);
	_stime = _stime + (random 45) + 1;
	_list set [count _list, _stime];
};

_data = [_lifecheck, _list, 0, _v selectionPosition "destructionEffect2"];

__TRACE_1("","_data");

if (isNull _v) exitWith {};

GVAR(BISsecondaries) set [count GVAR(BISsecondaries), [_v, _data]];
