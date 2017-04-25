/* ace_sys_muzzleblast | (c) 2008, 2009, 2010 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_distance", "_infov", "_fov", "_l", "_i", "_house"];

PARAMS_7(_vehicle,_weapon,_muzzle,_mode,_ammo,_magazine,_projectile);

if (!isDedicated) then {
	if (alive player) then {
		if ((player in _vehicle) && {([player] call ACE_fnc_isTurnedOut)}) then {
			[player,1,1] call ace_fx_fnc_flash;
			[player,6] call ace_fx_fnc_deaf;
		};
	};
};

_ts = getNumber(configFile>>"CfgAmmo">>_ammo>>"typicalSpeed");
_hp = getNumber(configFile>>"CfgAmmo">>_ammo>>"hit");

TRACE_2("",_ts,_hp);

_highpressure = if (_ts > 900 && {_hp > 400}) then { 1 } else { 0 };

_weapondirection = _vehicle weaponDirection _weapon;
_angle = (_weapondirection select 0) atan2 (_weapondirection select 1);

if (isServer) then { [_vehicle,_ammo,400,_angle] call FUNC(tankdebris); };
TRACE_4("",_vehicle,_ammo,_projectile,_angle);

_obj = (position _vehicle) nearEntities ["CaManBase",100];

if (count _obj == 0) exitWith { false };
switch _highpressure do {
	case 0: {
		TRACE_1("LOW PRESSURE","");
		{
			_distance = ceil(_x distance _vehicle);
			_house = if (_x == player) then { [_x] call ACE_fnc_inBuilding } else { false };
			_infov = [_vehicle,_x,_angle] call FUNC(fov);
			_fov = _infov select 2;
			TRACE_4("",_house,_fov,_x,_distance);
			if (local _x && {alive _x}) then {
				if (true) then { // hmmm...
					if (_distance <= 8) exitWith {
						if (_house) then {
							[_x,1,1] call ace_fx_fnc_flash;;
						} else {
							if (_x == player) then {
								[_x, true,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",true] call ace_fx_fnc_ring;
								[_x,1,1] call ace_fx_fnc_flash;
								//[_x,6] call ace_fx_fnc_deaf;
							};
							if (isNil "ace_sys_wounds_enabled") then {
								_x setdamage(damage _x)+random .1;
							} else {
								[_x,"",random .1,objNull,""] call ace_sys_wounds_fnc_hd;
							};
						};
					};
					if (_x == player) then {
						if (_distance <= 16) exitWith {
							if (_house) then {
								[_x,1,1] call ace_fx_fnc_flash;
							} else {
								[_x, true,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",false] call ace_fx_fnc_ring;
								[_x,1,1] call ace_fx_fnc_flash;
								//[_x,6] call ace_fx_fnc_deaf;
							};
						};
						if (_house && {_distance <= 24}) exitWith {
							//[_x, false,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",12.4] call ace_fx_fnc_ring;
						};
					};
				};
			};
		} forEach _obj;
	};

	case 1: {
		TRACE_1("HIGH PRESSURE","");
		{
			_distance = ceil(_x distance _vehicle);
			_house = if (_x == player) then { [_x] call ACE_fnc_inBuilding } else { false };
			_infov = [_vehicle,_x,_angle] call FUNC(fov);
			_fov = _infov select 2;
			TRACE_4("",_house,_fov,_x,_distance);
			if (local _x && {alive _x}) then {
				if (true) then { // hmmm....
					// 7 radius
					if (_distance<= 7) exitWith {
						if (_fov) then {
							if !(_house) then {
								if (isNil "ace_sys_wounds_enabled") then {
									_x setdamage(damage _x)+.6;
								} else {
									[_x,"",random .6,objNull,""] call ace_sys_wounds_fnc_hd;
								};
							};
						} else {
							//if !(_house) then { [_x,15,false] spawn ace_fx_fnc_knockout; };
							if (isNil "ace_sys_wounds_enabled") then {
								_x setdamage(damage _x)+random .1;
							} else {
								[_x,"",random .1,objNull,""] call ace_sys_wounds_fnc_hd;
							};
						};
						if (_x == player) then {
							[_x, true,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",true] call ace_fx_fnc_ring;
							[_x,1,3] call ace_fx_fnc_flash;
							//[_x,6] call ace_fx_fnc_deaf;
						};
					};
					// 12  radius
					if (_distance <= 12) exitWith {
						if (_x == player) then { [_x,1,1] call ace_fx_fnc_flash; };
						if (_fov) then {
							if !(_house) then {
								if (isNil "ace_sys_wounds_enabled") then {
									_x setdamage(damage _x)+.55;
								} else {
									[_x,"",random .55,objNull,""] call ace_sys_wounds_fnc_hd;
								};
							};
							if (_x == player) then {
								[_x, true,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",true] call ace_fx_fnc_ring;
								//[_x,6] call ace_fx_fnc_deaf;
							};
						} else {
							if !(_house) then {
								if (_x == player) then {
									[_x, true,_distance,"ACE_Ring_Muzzleblast1","ACE_Ring_Muzzleblast2",false] call ace_fx_fnc_ring;
									//[_x,6] call ace_fx_fnc_deaf;
								};
								//if (isNil "ace_sys_wounds_enabled") then {
								//	_x setdamage(damage _x)+random .2;
								//} else {
								//	[_x,"",random .2,objNull,""] call ace_sys_wounds_fnc_hd;
								//};
							};
						};
					};

					// 19 radius
					if (_distance <= 19) exitWith {
						if (_fov) then {
							if !(_house) then {
								if (isNil "ace_sys_wounds_enabled") then {
									_x setdamage(damage _x)+.5;
								} else {
									[_x,"",random .5,objNull,""] call ace_sys_wounds_fnc_hd;
								};
								[_x,10,false] spawn ace_fx_fnc_knockout;
							};
							if (_x == player) then { [_x,1,1] call ace_fx_fnc_flash; };
							if (isNil "ace_sys_wounds_enabled") then {
								_x setdamage(damage _x)+random .5;
							} else {
								[_x,"",random .5,objNull,""] call ace_sys_wounds_fnc_hd;
							};
						} else {
							if (!_house && {_x == player}) then { [_x, false,_distance,"ACE_Ring_Muzzleblast2","ACE_Ring_Muzzleblast2",false] call ace_fx_fnc_ring; };
						};
					};
					//if (_x == player) then {
						//if (_fov && !(_house)) then {
							//if ( _distance <= 50 ) then { [_x, false,_distance,"ACE_Ring_Muzzleblast2","ACE_Ring_Muzzleblast2",true] call ace_fx_fnc_ring; };
							//if ( _distance <= 100 ) then { [_x,1,1] call ace_fx_fnc_flash; };
						//};
					//};
				};
			};
		} forEach _obj;
	};
};
