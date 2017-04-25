//modify part and side hit in special cases

//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo
#define __parts ["engine","hull","ltrack","rtrack"]

private["_addpart","_d","_tur_dmg","_hull_dmg","_tracks_dmg","_turret","_type","_ex","_angles","_dparts"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);
// if (! alive _unit) exitwith { TRACE_1("Abort - unit not alive",_unit) }; // Don't exit with wrong data!

_ex = false;
_addpart = "";
//mines and whatnots
if (_ammo isKindOf "TimeBombCore" || {_ammo isKindOf "ACE_SLAMBottomEFP"} || {isNumber(__ammocfg >> "ace_minetype")}) then {
	_type = getNumber(__ammocfg >> "ace_minetype");
	//[format["Modpart: minetype %1",_type]] call CBA_fnc_debug;
	_ex = true;
	_angles = switch (_type) do {
		case 1:	{ //anti-track mines
			_dparts = _unit getvariable "ace_dparts";
			_part = if ((_dparts select 2) >= (_dparts select 3)) then {"ltrack"} else {"rtrack"};
			_partdamage = 0.8;
			[5,0,89,0.95];
			//[0,1,1,1];
		};
		case 2:	{ //HEAT mines
			_part = "hull";
			_partdamage = 0.5;	//to pass the threshold
			[5,0,89,0.95];
		};
		case 3: { // EFP type mine (DM31 AT)
			_part = "hull";
			_partdamage = 0.8;
			[5,0,100,1];
		};
		default { //dumb satchels/IEDs
			//_dparts = _unit getvariable "ace_dparts";
			//_part = if ((_dparts select 2) >= (_dparts select 3)) then {"ltrack"} else {"rtrack"};
			//_partdamage = 1;
			[round(random 3),1,1,1];
		};
	};
};
if (_ammo isKindOf "BombCore") then {
	_angles = [round (random 3),1,1,1];
	_ex = true;
};
if (_ex) exitwith {[_part,_angles,_partdamage,_addpart]};

//scripted projectiles etc
if (isNumber(__ammocfg >> "ace_impactside")) then {
	if (isNull _injurer) then {
		_ex = true;
		_d = getNumber(__ammocfg >> "ace_impactside");
		if (_d in [1,2]) then {
			//if tracks then probly hull too
			if (_part in ["ltrack","rtrack"]) then {
				if (0.75 > random 1) then {_addpart = _part;_part = "hull"};
			};
		};
		_angles = [_d,1,1,1];
	};
};
if (_ex) exitwith {[_part,_angles,_partdamage,_addpart]};

_turret = false;

//sometimes turret triggers even when hull is hit - if damages are comparable, prefer hull
if (_part in ["gun","turret"]) then {
	if ( isNull _injurer || {isPlayer (gunner _injurer)}) then {
		_d = _unit getvariable "ace_dparts";
		_tur_dmg = (_d select 4) max (_d select 5);
		_hull_dmg = (_d select 0) max (_d select 1);
		_tracks_dmg = (_d select 2) max (_d select 3);
		_hull_dmg = _hull_dmg max _tracks_dmg;

		if (0.93*_tur_dmg <= _hull_dmg) then {
			_d = _d find _hull_dmg;
			_part = __parts select _d;
		} else {
			_turret = true;
			if (_part == "gun") then
			{	//if gun then probly turret hit
				if (0.9 > random 1) then {_part = "turret"};
			};
		};
	} else {	//if shooter is AI, then they might hit hull instead of turret
		if (0.33 > random 1) then {_part = "hull"} else {_turret = true};
	};
};

//if tracks then probly hull too
if (_part in ["ltrack","rtrack"]) then {
	if (0.75 > random 1) then {_addpart = _part;_part = "hull"};
};

switch (getNumber(__ammocfg >> "ace_topattack")) do {
	case 1: {
		//top
		_angles = [4,0,89,0.95];
	};
	case -1: {
		//bottom
		_angles = [5,0,89,1];
		_part = "hull";
	};
	default {
		_angles = [_unit,_injurer,_ammo,_turret] call FUNC(shooter_direction);
		//safety for rear-engined tanks
		switch (_angles select 0) do {
			case 0:	{ //front
				if (_part == "engine" && {!(_unit isKindOf "Tracked_APC")}) then {_part = "hull"};
			};
			case 3:	{ //back
				if (_part == "hull" && {!(_unit isKindOf "Tracked_APC")}) then {_part = "engine"};
			};
		};
	};
};

[_part,_angles,_partdamage,_addpart];
