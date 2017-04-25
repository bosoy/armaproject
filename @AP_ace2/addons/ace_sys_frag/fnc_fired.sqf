#include "script_component.hpp"

if (!GVAR(enabled)) exitWith {};

private ["_gun", "_type", "_round", "_doFragTrack", "_skip", "_explosive", "_indirectRange", "_force"];

_gun = _this select 0;
_type = _this select 4;
_round = _this select 6;

if(_round in GVAR(blackList)) exitWith {
	GVAR(blackList) = GVAR(blackList) - [_round];
};

_doFragTrack = false;
if(_gun == player) then {
	_doFragTrack = true;
} else {
	if((gunner _gun) == player) then {
		_doFragTrack = true;
	} else {
		if(local _gun && {!(isPlayer (gunner _gun))} && {!(isPlayer _gun)}) then {
			_doFragTrack = true;
		};
	};
};
if(_doFragTrack && {alive _round}) then {
	_skip = getNumber (configFile >> "CfgAmmo" >> _type >> "ACE_FRAG_SKIP");
	if(_skip == 0) then {
		_explosive = getNumber (configFile >> "CfgAmmo" >> _type >> "explosive");
		_indirectRange = getNumber (configFile >> "CfgAmmo" >> _type >> "indirectHitRange");
		_force = getNumber (configFile >> "CfgAmmo" >> _type >> "ACE_FRAG_FORCE");
		_fragPower = getNumber(configFile >> "CfgAmmo" >> _type >> "indirecthit")*(sqrt(_indirectRange));
		if((_explosive > 0.5 && {_indirectRange >= 4.5} && {_fragPower >= 35}) || {_force == 1} ) then {
			GVAR(trackedObjects) set[(count GVAR(trackedObjects)), _round];
			[FUNC(trackFragRound), 0, [_round, (getPosASL _round), (velocity _round), _type, time, _gun]] call cba_fnc_addPerFrameHandler;
		};
	};
};
