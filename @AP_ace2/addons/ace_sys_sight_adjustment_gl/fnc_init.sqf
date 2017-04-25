//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfgW (configFile >> "CfgWeapons")
#define __cfgM (configFile >> "CfgMagazines" >> _m)

private["_wpn","_m","_ammo","_table","_zero","_el","_eh","_zerodeg","_fineadj","_deg"];

//a 'valve' to cut off multiple key press events within 1 frame
if (GVAR(presstime) == time) exitwith {false};
GVAR(presstime) = time;

_m = currentMagazine player;
_ammo = getText(__cfgM >> "ammo");
if (_ammo isKindOf "BulletBase") exitwith {false};	//GL selected now (primary weap selected before)
if !(isArray(__cfgM >> "ace_gl_table")) exitwith {false};
_table = getArray(__cfgM >> "ace_gl_table");
_zero = getNumber(__cfgW >> currentweapon player >> "ace_gl_zero");
_fineadj = getNumber(__cfgW >> currentweapon player >> "ace_gl_fineadj");

TRACE_4("",_ammo,_table,_zero,_fineAdj);

GVAR(running) = false;
GVAR(sa_active) = true;
_el = player getVariable ["ace_sa_gl_el", _zero];
_eh = player getVariable "ace_sa_gl_firedEH";
if (isNil "_eh") then {
	_eh = player addEventHandler ["fired", { _this call FUNC(fired) }];
	player setVariable ["ace_sa_gl_firedEH",_eh];

	_zerodeg = _fineadj*180/(1000*pi) + ([_zero,_table] call FUNC(set_el));
	_deg = [_el,_table] call FUNC(set_el);
	player setVariable ["ace_sa_gl_el",_el];
	player setVariable ["ace_sa_gl_deg",_deg - _zerodeg];
};
