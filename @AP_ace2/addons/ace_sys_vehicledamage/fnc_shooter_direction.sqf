// finds side from which came the projectile

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit

#define __sideangle 60	//60 -> 120 deg sector
#define __rightmin 90 - __sideangle
#define __rightmax 90 + __sideangle
#define __leftmin 270 - __sideangle
#define __leftmax 270 + __sideangle

private ["_vlimit","_vup","_cosvec","_dir","_a","_vec","_pos","_pinj","_b","_dir1","_z","_zinj","_dist","_zdiff","_weapon","_cos", "_weapons"];
PARAMS_4(_unit,_inj,_ammo,_turret);

if (_inj != _unit && {isClass(configFile >> "cfgVehicles" >> (typeof _inj))}) then {
	_pos = getpos _unit;
	_pinj = getpos _inj;
	if (_turret) then {
		_weapons = getArray (__unitcfg >> "Turrets" >> "Mainturret" >> "weapons");
		if (count _weapons > 0) then {
			_weapon = _weapons select 0;
			_dir = _unit weapondirection _weapon;
			_dir = (_dir select 0) atan2 (_dir select 1);
			if (_dir < 0) then {_dir = _dir + 360};
			//[format["Wpn %1 Direction %2",_weapon,_dir]] call cba_fnc_debug;
		} else {
			_dir = getDir _unit;
		};
	} else {
		_dir = getdir _unit;
	};
	//vec to the firer
	_vec = [-(_pos select 0)+(_pinj select 0),-(_pos select 1)+(_pinj select 1),-(_pos select 2)+(_pinj select 2)];
	//dir to the firer
	_a = (_vec select 0) atan2 (_vec select 1);
	if (_a < 0) then {_a = _a + 360};
	_dir = _a - _dir;
	if (_dir < 0) then {_dir = _dir + 360};

	if (true) then {
		if (_dir >= __leftmax || {_dir <= __rightmin}) exitwith {_a = 0; _cos = abs (cos _dir)};	//a=[front,left,right,back,top]
		if (_dir > __rightmin && {_dir < __rightmax}) exitwith {_a = 2; _cos = abs (sin _dir)};
		if (_dir >= __rightmax && {_dir <= __leftmin}) exitwith {_a = 3; _cos = abs (cos _dir)};
		if (_dir > __leftmin && {_dir < __leftmax}) exitwith {_a = 1; _cos = abs (sin _dir)};
	};

	// vertical angle calculations
	/*
	_zinj = (getposASL _inj) select 2;
	_z = (getposASL _unit) select 2;
	_dist = _inj distance _unit;
	_zdiff = 1 + _zinj - _z;		//avg expected gun height 1 m
	_dir1 = asin (_zdiff/_dist);	//vertical angle to shooter
	if (_dir1 >= 30) then {_a = 4; _cos = sin _dir1};	//from top
	*/
	_cosvec = [vectorUp _unit,_vec] call FUNC(mat_cos3Dvec);
	//[format["Angles: v.cos %1 v.angle %2",_cosvec,90 - (acos _cosvec)]] call cba_fnc_debug;
	_vlimit = if (_turret || {_a != 3}) then {0.36} else {0.22};  //20 deg for turret and front-side, 13 deg for hull-back
	if (_cosvec > _vlimit) then { //over 20 degrees of elevation is considered from top
		_a = 4;
		_cos = _cosvec;
		_dir1 = 90 - (acos _cos);
	}
	else
	{
		_zinj = (getposASL _inj) select 2;
		_z = (getposASL _unit) select 2;
		_dist = _inj distance _unit;
		_zdiff = 1 + _zinj - _z;		//avg expected gun height 1 m
		_dir1 = asin (_zdiff/_dist);	//vertical angle to shooter
	};
} else { //createvehicle'd ammo
	_a = round(random 3);
	_dir = 0;
	_dir1 = 0;
	_cos = random 1;
};
//turret is kinda round
_cos = if (_turret) then {0.8 max _cos} else {0.3 max _cos};
//return: [index of side,azimuth to shooter,elev to shooter,cos of incidence angle]
[_a,_dir,_dir1,_cos]