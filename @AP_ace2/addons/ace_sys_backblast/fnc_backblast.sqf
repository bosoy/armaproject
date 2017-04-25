//* ace_sys_backblast (.pbo) | (c) 2008, 2009 by rocko

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __SHOULDER 

private ["_posShooter","_posShooterBack","_posShooterTop","_clearedBack","_clearedBackTerrain","_inBuilding"];

PARAMS_7(_unit,_bla,_bla,_bla,_ammo,_bla,_shot);

//TODO: PFH!

// Code run on all clients, due to fire eh being global

// Deafen the firer, more impact if inside a building
if (alive _unit && {_unit == player}) then {
	_posShooter = getPosASL _unit;
	_posShooterBack = [(_posShooter select 0) - ((sin direction _unit) * 5), (_posShooter select 1) - ((cos direction _unit) * 5),(_posShooter select 2) + 0.5];
	_posShooterTop = [(_posShooter select 0),(_posShooter select 1),(_posShooter select 2) + 5];
	_obstructedBack = lineIntersects [_posShooter,_posShooterBack,_unit];
	_obstructedBackTerrain = terrainIntersectASL [_posShooter, _posShooterBack]; //TODO: Needed? Does _obstructedBack the same job?
	_inBuilding = lineIntersects [_posShooter,_posShooterTop,_unit];
	
	TRACE_3("LOS stuff",_obstructedBack,_obstructedBackTerrain,_inBuilding);
	if (_obstructedBack || {_obstructedBackTerrain}) then {
		[_unit,10,0.5] call ace_fx_fnc_deaf;
		[player,5,0.1] call ace_fx_fnc_dizzy;
	} else {
		if (_inBuilding) then {
			[_unit,15,0.9] call ace_fx_fnc_deaf;
			[player,7.5,0.15] call ace_fx_fnc_dizzy;
			// Apply overpressure effect when firing inside buildings, unless it's RPG or AT4 CS or any other that has this capability
			_confinedSpace = getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_BACKBLAST" >> "confinedSpace") == 1;
			if (!_confinedSpace && {_inBuilding} && {_obstructedBack}) then {
				_overpressure = getText(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_BACKBLAST" >> "overpressureEffect");
				for "_i" from 0 to 1 do {
					#ifdef DEBUG_MODE_FULL
						_overpressure = "RoadCone";
					#endif
					_overpressure_shrapnel = _overpressure createVehicle _posShooterBack;
					_overpressure_shrapnel setPos _posShooterBack;
					_overpressure_shrapnel setVelocity [-(sin _direction)*100,-(cos _direction)*100, -(_unit weaponDirection (currentWeapon _unit) select 2)*100];
				};
			};			
		} else {
			[_unit,10,0.7] call ace_fx_fnc_deaf;
		};
	};
};

// Backblast debris creation - on server
if (isServer) then {
	private ["_dir", "_shrapnel", "_i","_ammo_shrapnel","_debriscount","_direction"];
	
	_weaponDirection = _unit weaponDirection (currentWeapon _unit);
	_position = getPosATL _unit;
	_direction = (_weaponDirection select 0) atan2 (_weaponDirection select 1);
	_position set [0,(_position select 0)-(sin (_direction) * 2)];
	_position set [1,(_position select 1)-(cos (_direction) * 2)];
	_position set [2,((_unit selectionPosition "rightshoulder") select 2)];

	_debriscount = ceil (random 10);

	if (animationState _unit == "ACE_launcherProne") then {
		_position set [0,(_position select 0)-(sin (_direction) * .41)];
		_position set [1,(_position select 1)-(cos (_direction) * .41)];
		_position set [2,(((_unit selectionPosition "rightshoulder") select 2) + 0.4)];
		_debriscount = _debriscount + 20; 
	};	

	// Debris
	// TODO: GetSurface type, Calculate amount of debris "dust" value should do...
	
	_shotvelz = -((vectorDir _shot) select 2);
	_direction = (getDir _unit)-180;
	_position_shooter = getPosATL _unit;   
	_position = [(_position_shooter select 0) + (sin (_direction) * 0.3), (_position_shooter select 1) + (cos (_direction) * 0.3),(((_unit selectionPosition "rightshoulder") select 2) + (_position_shooter select 2))];
	_angle = getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_BACKBLAST" >> "angle");
	
	for "_j" from 1 to _debriscount do {
		_dir = (_direction - _angle/2) + random _angle;
       	_ammo_shrapnel = "ACE_ATDEBRIS";
		#ifdef DEBUG_MODE_FULL
			_ammo_shrapnel = "RoadCone";
		#endif
       	_shrapnel = _ammo_shrapnel createVehicle _position;
       	_shrapnel setPos _position;
       	_shrapnel setVelocity [(sin _dir * 290),(cos _dir * 290),(_shotvelz*58)];
	};
};

// Collect units behind player & type of backblast
_softlaunch = getText(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_BACKBLAST" >> "type") == "Softlaunch"; // Softlaunch is also hazardous! Ignore comments
_dangerRange = getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_BACKBLAST" >> "dangerzone"); // Range where it's hazardous for other players
_cautionRange = getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_BACKBLAST" >> "cautionzone");
_angle = getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_BACKBLAST" >> "angle");
_killRange = if (_softlaunch) then { -1 } else { 2 };

_obj = (position _unit) nearEntities ["CaManBase",if (_softlaunch) then { _dangerRange } else { _dangerRange + _cautionRange }];
_obj = _obj - [_unit];

if (count _obj == 0) exitWith {};

{
	// Run single on every client (_obj-list)
	_distance = _x distance _unit; TRACE_1("",_distance);
	// If taking cover i.e prone add to distance
	if (true) then {};
	_pos_shooter = getPosATL _unit;
	_pos_x =  getPosATL _x;
	_inLOS = lineIntersects [(eyepos _x),(aimPos _unit)];
	
	// Find personel within dangerRange
	if (_distance <= _dangerRange) then {
		// Find personel within angle
		_inSector = [_pos_shooter,((getDir _unit)-180),_angle,_pos_x] call BIS_fnc_inAngleSector; TRACE_1("",_inSector);
		if (!_softlaunch && {_distance < _killrange} && {animationState _unit != "ACE_launcherProne"} && {_inSector}) exitWith { _x setDammage 1; TRACE_1("El stupido",""); }; // Someone stupid enough to stay directly behind the exitmuzzle
		// Knockout and injuries, Flash
		// TODO: Deconstruct order
		if (_inSector && {_distance > 0} && {_distance <= _dangerRange/3}) then { // 0  - 1/3 of dangerzone
			if (local _x && {alive _x}) then {
				if (isNil "ace_sys_wounds_enabled") then {
					_x setDamage ((getDammage _x) + ((1 - (getDammage _x)) * (1/(_distance*2))));
				} else {
					if (local _x) then {
						[_x,"",0.1 * (1/(_distance*2)),objNull,""] call ace_sys_wounds_fnc_hd;
					} else {
						["ace_sys_wounds_addDloc", [_x, 0.1 * (1/(_distance*2))]] call CBA_fnc_globalEvent;
					};
				};
				if (!_softlaunch && {_distance <= _dangerRange/2}) then { [_x,(5.1 + random 5),true] spawn ace_fx_fnc_knockout }; // meh...
				if (_x == player && {alive _x}) then {
					[_x,false,_distance,"ACE_Ring_Muzzleblast1","",true] call ace_fx_fnc_ring;
					[_x,2,1] call ace_fx_fnc_flash;
				};				
			};
			TRACE_1("Knockout and injuries, Flash, Earring","");
		};
		//Earring, Flash, Dizzy ,Tilt
		if (_inSector && {_distance > _dangerRange/3} && {_distance <= _dangerRange*0.666}) then { // 1/3 to 2/3 of dangerzone
			//TODO: Dizzy
			if (_x == player && {alive _x}) then { 
				[_x,false,_distance,"ACE_Ring_Backblast","",true] call ace_fx_fnc_ring;
				[_x,1,1] call ace_fx_fnc_flash;
			};
			if (!_softlaunch) then { [_x,1,false] spawn ace_fx_fnc_knockout };
			TRACE_1("No Knockout, Earring, Flash, Dizzy","");
		};
		// Flash
		if (_inSector && {_distance > _dangerRange*0.666} && {_distance <= _dangerRange}) then { // 2/3 to 3/3 of dangerzone
			if (_x == player && {alive _x}) then { 
				[_x,0.7,0.65] call ace_fx_fnc_flash;
			};
			TRACE_1("Flash","");
		};
	};
	// TODO
	//if (_distance > _dangerRange && {_distance <= _cautionRange/2} && {_x == player}) then { // in cautionzone, earring depending on range
	//	// Earring, soft??
	//	[_x,0.5,0.5] call ace_fx_fnc_flash;
	//	//[_x,false,_distance,"ACE_Ring_Backblast","",false] call ace_fx_fnc_ring;
	//	TRACE_1("Cautionzone","");
	//};
} forEach _obj;
