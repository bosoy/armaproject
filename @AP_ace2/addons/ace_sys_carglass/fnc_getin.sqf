#include "script_component.hpp"

#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")

private ["_check", "_check2", "_target"];

PARAMS_3(_veh,_p,_unit);

if (!local _unit) exitWith {};

_check = _veh getVariable "ACE_glass_damage";
if (isNil "_check") then {
	_veh setVariable ["ACE_glass_damage", 0];
	_check = 0;
};
if (damage _veh == 0) then {
	if (_check > 0) then {
		_veh setVariable ["ACE_glass_damage", 0]; // maybe the car got repaired
		_veh setVariable ["ACE_glass_broken", false, true];
	};
};
_check = _veh getVariable "ACE_glass_broken";
if (isNil "_check") then {
	_veh setVariable ["ACE_glass_broken", false, true];
};

GVAR(caraction) = _veh addaction [ACE_TEXT_RED(localize "STR_ACE_BREAKCARGLASS"),QPATHTO_F(glassaction),"glass1",-1,false,false,"","(player == driver _target) && {((_target getVariable 'ACE_glass_damage') >= 0.5)} && {((_target getVariable 'ACE_glass_damage') < 1)} && {!(_target getVariable 'ACE_glass_broken')} && {((speed _target) < 1)} && {!(player getVariable ['ace_sys_wounds_uncon',false])}"];