#include "script_component.hpp"
#define __wcfg configFile >> "CfgWeapons" >> _weapon
private ["_ammo","_bullet","_mv","_i","_dir"];

_bullet = _this select 6; // uses BIS Fired EH
if (isNull _bullet) exitwith {};
PARAMS_2(_unit,_weapon);
_ammo = _this select 4;
_mv = getArray(__wcfg >> "ace_mv");	// format is ["ammoclass1", vel1,...,"ammoclassn",veln]
_i = _mv find _ammo;
if (_i < 0) then {
	//might be improper case, 'find' failed
	for "_j" from 0 to (count _mv - 2) step 2 do {
		if (_ammo == (_mv select _j)) exitwith {_i = _j};
	};
};
if (_i < 0) exitwith {};
_mv = _mv select (_i + 1);
_dir = vectordir _bullet;
_bullet setVelocity [(_dir select 0)*_mv,(_dir select 1)*_mv,(_dir select 2)*_mv];
//hint format ["Vel %1",(velocity _bullet) call ACE_fnc_magnitude ];