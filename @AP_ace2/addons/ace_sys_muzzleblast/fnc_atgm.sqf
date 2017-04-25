/* ace_sys_muzzleblast | (c) 2008, 2009, 2010 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_obj", "_distance"];

_this call BIS_Effects_EH_Fired; // TODO: Actually all vehicles already have this! - and we re-Enabled effects for men as well - so why is this here? // No idea - rocko

PARAMS_7(_vehicle,_weapon,_muzzle,_mode,_ammo,_magazine,_projectile);
_shooter = [_vehicle, _weapon] call CBA_fnc_getFirer; TRACE_1("Shooter",_shooter);

if (!isDedicated) then {
	if (alive player) then {
		if (player in _vehicle && {(_shooter select 0) != player} && {[player] call ACE_fnc_isTurnedOut}) then {
			[player,1,1] call ace_fx_fnc_flash;
			[player,6] call ace_fx_fnc_deaf;
		};
	};
};

if (isServer) then { [_vehicle,_ammo,50,(getDir _projectile) - 180,_projectile] spawn FUNC(tankdebris); };

if (!isDedicated) then {
	_obj = (position _vehicle) nearEntities ["CaManBase",200]; TRACE_1("",_obj);
	if (count _obj == 0) exitWith { false };
	if (alive player) then {
		if (player in _obj) then {
			_distance = player distance _vehicle;
			if (_distance < 8) then {
				[player,true,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",true] call ace_fx_fnc_ring;
				[player, _distance / 2, 1] call ace_fx_fnc_flash;
			} else {
				if (_distance <= 11) then { [player,false,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",false] call ace_fx_fnc_ring; };
			};
		};
	};
};
