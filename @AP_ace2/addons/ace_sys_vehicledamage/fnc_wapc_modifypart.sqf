//modify part and side hit in special cases


#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

private["_abort","_turret","_type","_ex","_angles","_d"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);
// if (! alive _unit) exitwith { TRACE_1("Abort - unit not alive",_unit) }; // Don't exit with wrong data!

_ex = false;
_abort = false;	//abort main function

//mines and whatnots
if (_ammo isKindOf "TimeBombCore" || {_ammo isKindOf "ACE_SLAMBottomEFP"}) then {
	_type = getNumber(__ammocfg >> "ace_minetype");
	TRACE_1("Modpart: MineType",_type);
	_ex = true;
	_angles = switch (_type) do {
		case 1:	{ //only wheels - already damaged before
			_abort = true;
			[0,1,1,1];
		};
		case 2:	{ //heat mine
			_part = "hull";
			[5,0,89,0.95];
		};
		default { //dumb satchels
			[round (random 3),1,1,1];
		};
	};
};
if (_ammo isKindOf "BombCore") then {
	_angles = [round (random 3),1,1,1];
	_ex = true;
};
if (_ex) exitwith {[_part,_angles,_abort]};

//scripted projectiles etc
if (isNumber(__ammocfg >> "ace_impactside")) then {
	if (isNull _injurer) then {
		_ex = true;
		_d = getNumber(__ammocfg >> "ace_impactside");
		_angles = [_d,1,1,1];
	};
};
if (_ex) exitwith {[_part,_angles,_abort]};

_turret = false;
if (_part == "turret") then {
	if !( isNull _injurer || {isPlayer (gunner _injurer)}) then {
		if (0.33 > random 1) then {_part = "hull"} else {_turret = true};
	};
};
_angles = switch (getNumber(__ammocfg >> "ace_topattack")) do {
	case 1: {
	 	//top
		[4,0,89,0.95];
	};
	case -1: {
		//bottom
		_part = "hull";
		[5,0,89,1];
	};
	default {
		[_unit,_injurer,_ammo,_turret] call FUNC(shooter_direction);
	};
};

[_part,_angles,_abort];
