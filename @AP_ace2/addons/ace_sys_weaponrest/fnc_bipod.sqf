/* ace_sys_weaponrest | fnc_bipod.sqf - " Useable bipods " | (c) 2009 by rocko */

#include "script_component.hpp"

TRACE_1("",_this);

PARAMS_4(_anim,_oldanim,_text,_SB);

_snd = format ["ace_deployweapon_%1", round (1 + random 2)];
_t = "ACE_LogicDummy" createVehicleLocal (player ModelToWorld [0, 0, 0]);
_t say _snd;

player switchmove _anim;

_text spawn ace_fnc_visual;

#define __WD (player weaponDirection (currentWeapon player))
#define __DIR ((_wd select 0) atan2 (_wd select 1))

_wd = __WD;
_dir0 = __DIR;
while {animationstate player == _anim } do {
	_wd = __WD;
	_dir = __DIR;
	if (_dir < 0) then { _dir = _dir + 360 };
	_res = _dir0 - _dir;
	if (_res < -180) then { _res = 360 + _res };
	if (_res > 180) then { _res = _res - 360 };
	sleep 0.5;
	if ( (abs _res > 10) && {_SB} ) exitwith { player switchmove (_oldanim select 0) };
};
deletevehicle _t;