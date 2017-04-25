/* ace_sys_overheating | Barrel Temperature for Static weapons | (c) 2011 rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define ACE_TEXT_ORANGE(Text) ("<t color='#ffa500'>" + ##Text + "</t>")

private ["_temp", "_pos", "_tmp", "_pos2","_smk", "_ammo", "_bullet", "_vc", "_vx", "_vy", "_vz", "_disp", "_wd", "_s", "_spd","_dif","_lastShotTime"];

PARAMS_7(_vehicle,_weapon,_muzzle,_mode,_ammo,_magazine,_bullet);

if !(isArray (configfile >> "cfgWeapons" >> _weapon >> "ace_jam")) exitWith {};

_pos = getPosATL _bullet;

_lastShotTime = _vehicle getVariable [QGVAR(lastShotTime_static), time];
_dif = time - _lastShotTime;
_vehicle setVariable [QGVAR(lastShotTime_static), time, false];	//GVAR
_weapontemp = _vehicle getVariable [QGVAR(temp),0];

_cf = getArray (configfile >> "cfgWeapons" >> _weapon >> "ace_jam") select 2;
_jam = getArray (configfile >> "cfgWeapons" >> _weapon >> "ace_jam") select 0;
_cock = getArray (configfile >> "cfgWeapons" >> _weapon >> "ace_jam") select 1;
_temp = _weapontemp - _cf*_dif;
if (_temp < 0) then { _temp = 0 };
_vehicle setVariable [QGVAR(temp),_temp];

TRACE_1("T cool",_temp);

INC(_temp);
TRACE_1("T fired",_temp);
_vehicle setVariable [QGVAR(temp),_temp];

if (isNull _bullet) exitwith { TRACE_1("bullet isnull",""); };

if (_temp > 70) then {
	_vel = velocity _bullet;
	_spd = _vel call ACE_fnc_magnitude;
	_wd = _vehicle weapondirection _weapon;
	_tmp = [0.28, 0.33, 0.37];
	_smk = (_temp/2000) min 0.3;
	{
		_s = 0.05 + random 0.27;
		_pos2 = [(_pos select 0) - (_wd select 0)*_s,(_pos select 1) - (_wd select 1)*_s,(_pos select 2) - (_wd select 2)*_s];
		drop [QUOTE(PATHTOF(ace_flatsmoke)), "", "Billboard", 1, 1.5,_pos2, [0, 0, 0], 1, 7.0, 5.5, 0.075,_tmp, [[.5, .5, .5, _smk], [.6, .6, .6,_smk*0.2]], [random 1,random 1,random 1], 0, 0, "", "", ""];
	} foreach [0, 1];

	if (_temp > 100) then {
		_disp = (sqrt _temp)/4;
		_disp = _disp*_spd/1000;
		_vc = 1;
		if (_temp > 400) then { _vc = (1 - random (_temp/1000)) max 0.08};
		_vx = (_vel select 0) - (random _disp) + (random _disp);
		_vy = (_vel select 1) - (random _disp) + (random _disp);
		_vz = (_vel select 2) - (random _disp) + (random _disp);
		_bullet setvelocity [_vx*_vc, _vy*_vc, _vz*_vc];
	};
	// cookoff spawn
	//if (_temp > 160 && {(random 10 < 5)} && {_cock == 1}) then {
	//	if !(_vehicle getVariable [QGVAR(cookoff),false]) then {
	//		[_vehicle,_weapon,_mode] spawn FUNC(cookoff_static);
	//	};
	//};
};

if ((GVAR(debugjam) || {(((_temp * .15) min (_jam + random _temp/5)) > ((random 500) + 15))}) && {isNil {_vehicle getVariable QGVAR(jammed)}}) then {
	_vehicle setVariable [QGVAR(ac),(_vehicle ammo _weapon),true]; // Store current ammo count
	_vehicle setVehicleAmmo 0; // TODO: GlobalEvent?
	_vehicle setVariable [QGVAR(jammed),_muzzle,true];
	
	if (vehicle player == _vehicle) then {
		[localize "STR_ACE_JAM",[1,0,0,1],true,0] spawn ace_fnc_visual; // VISUAL FEEDBACK
	};
	_s = _vehicle addaction [ACE_TEXT_ORANGE(localize "STR_ACE_JAMCLEARACT"), QPATHTO_F(action_unjam_static)];
	
	_vehicle setVariable [QGVAR(aid),_s,true];
	_vehicle setVariable [QGVAR(mag),_magazine,true];
	_vehicle setVariable [QGVAR(wep),_weapon,true];
	
	[_vehicle] spawn FUNC(jam_static_loop)
};

if (GVAR(debugjam)) then {
	[_vehicle,_weapon,_muzzle,_vehicle ammo _muzzle] spawn FUNC(stoppage);
};
