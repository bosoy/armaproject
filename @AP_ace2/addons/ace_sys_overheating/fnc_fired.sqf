//#define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("",_this);

private ["_temp", "_pos", "_tmp", "_pos2", "_wpn", "_smk", "_bullet", "_vc", "_vx", "_vy", "_vz", "_disp", "_wd", "_s", "_spd","_dif","_lastShotTime"];

PARAMS_5(_unit,_weapon,_muzzle,_mode,_ammo);
if (_weapon != primaryweapon _unit) exitwith {};

_bullet = _this select 6; // uses BIS Fired EH
_pos = getPosATL _bullet;

_wpn = primaryWeapon player;
call FUNC(weaponArrays);

// Tracking of weapon temperature - rocko
_lastShotTime = _unit getVariable [QGVAR(lastShotTime), time];
_dif = time - _lastShotTime;
_unit setVariable [QGVAR(lastShotTime), time, false];
{
	_temp = (_x select 1) - (_x select 2)*_dif;
	if (_temp < 0) then { _temp = 0 };
	_x set [1, _temp];
} foreach [GVAR(cur), GVAR(prev)];

_jam = GVAR(cur) select 3;
TRACE_1("",_jam);
//---------------------------------------------------------------------------------------------

TRACE_2("WPN  T", _wpn, (GVAR(cur) select 1));

_temp = (GVAR(cur) select 1) + 1;
GVAR(cur) set [1, _temp];

if (isNull _bullet) exitwith {};
if (_temp > 70) then {
	// smoke effects
	_vel = velocity _bullet;
	_spd = _vel call ACE_fnc_magnitude;
	_wd = _unit weapondirection _weapon;
	_tmp = [0.28, 0.33, 0.37];
	_smk = (_temp/2000) min 0.3;
	{
		_s = 0.05 + random 0.27;
		_pos2 = [(_pos select 0) + (_wd select 0)*_s,(_pos select 1) + (_wd select 1)*_s,(_pos select 2) + (_wd select 2)*_s];
		drop [QUOTE(PATHTOF(ace_flatsmoke)), "", "Billboard", 1, 1.5,_pos2, [0, 0, 0], 1, 7.0, 5.5, 0.075,_tmp, [[.5, .5, .5, _smk], [.6, .6, .6,_smk*0.2]], [random 1,random 1,random 1], 0, 0, "", "", ""];
										//9.5, 7.5
	} foreach [0, 1];

	// dispersion effects above 150
	if (_temp > 100) then {
		_disp = (sqrt _temp)/4;
		_disp = _disp*_spd/1000;
		_vc = 1; //velocity coefficient
		if (_temp > 400) then { _vc = (1 - random (_temp/1000)) max 0.08}; //bullet speed starts falling
		_vx = (_vel select 0) - (random _disp) + (random _disp); // hopefully correct now
		_vy = (_vel select 1) - (random _disp) + (random _disp);
		_vz = (_vel select 2) - (random _disp) + (random _disp);
		TRACE_3("",_vx,_vy,_vz);
		TRACE_1("",_vc);
		_bullet setvelocity [_vx*_vc, _vy*_vc, _vz*_vc];
	};
	// cookoff spawn // common cookoff temperature is 160° C
	if (_temp > 160 && {(random 10 < 5)} && {(GVAR(cur) select 4) == 1}) then {
		if !(_unit getVariable [QGVAR(cookoff),false]) then {
			[_unit,_wpn,_mode,""] spawn FUNC(cookoff);
		};
	};
};

//stoppages
//_temp/3000;	//	0.1% probab at temp == 300
TRACE_1("",GVAR(jammed));
if (isNil QGVAR(jammed) || {!GVAR(jammed)}) then {
	private ["_val1","_val2"];
	_val1 = (_temp * .15) min (_jam + random _temp/5);
	_val2 = (random 500) max 50; // adjust to lower/higher values ? I was able to fire at least more than 230 rounds with my M249 before it jammed, seems to be ok
	TRACE_2("",_val1,_val2);
	if (_val1 > _val2) then {
		[_unit,_weapon,_muzzle,_unit ammo _muzzle] spawn FUNC(stoppage);
	};
};

if (GVAR(debugjam)) then {
	[_unit,_weapon,_muzzle,_unit ammo _muzzle] spawn FUNC(stoppage);
};
