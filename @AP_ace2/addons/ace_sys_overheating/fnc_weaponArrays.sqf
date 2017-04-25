//#define DEBUG_MODE_FULL
#include "script_component.hpp"
private ["_wpn", "_cool", "_s"];
_wpn = primaryweapon player;
if (_wpn != (GVAR(cur) select 0)) then {
	if (_wpn == "") exitwith {};
	if (_wpn == (GVAR(prev) select 0)) then {
		_s = +GVAR(cur);
		GVAR(cur) = +GVAR(prev);
		GVAR(prev) = _s;

	} else {
		if ((_wpn == (GVAR(cur) select 0) + "_CQB") || {((GVAR(cur) select 0) == _wpn + "_CQB")}) exitwith {
			GVAR(cur) set [0, _wpn];
		};
		GVAR(prev) set [0, (GVAR(cur) select 0)];
		GVAR(prev) set [1, (GVAR(cur) select 1)];
		GVAR(prev) set [2, (GVAR(cur) select 2)]; // cool rate
		GVAR(prev) set [3, (GVAR(cur) select 3)]; // jam rate
		GVAR(prev) set [4, (GVAR(cur) select 4)]; // cookoff

		GVAR(cur) set [0, _wpn];
		GVAR(cur) set [1, 0];
		_cool = getArray (configfile >> "cfgWeapons" >> _wpn >> "ace_jam") select 2;
		GVAR(cur) set [2, _cool];
		_jam = getArray (configfile >> "cfgWeapons" >> _wpn >> "ace_jam") select 0;
		GVAR(cur) set [3, _jam];
		_cock = getArray (configfile >> "cfgWeapons" >> _wpn >> "ace_jam") select 1;
		GVAR(cur) set [4, _cock];	
	};
};
