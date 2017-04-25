/* ace_sys_sniper_tools (.pbo) | (c) 2009 by rocko */
#include "script_component.hpp"

PARAMS_2(_unit,_weapon);

private ["_scopeType","_scope"];
_scopeType = _weapon;

if !(_weapon in (weapons _unit)) exitWith { false };
if (_weapon in (weapons _unit)) then { _unit removeWeapon _weapon };

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	_unit playMove "AmovPercMstpSrasWrflDnon_diary";
};

sleep 1;

_position = _unit modelToWorld [0,0,0];
_position set [0, (_position select 0) + (sin (direction _unit) * 0.8)];
_position set [1, (_position select 1) + (cos (direction _unit) * 0.8)];
_z = [_unit] call CBA_fnc_realHeight;
_position set [2,_z];

_scope = _scopeType createVehicle _position;
_scope setDir (direction _unit);
_scope setPos _position;
_unit reveal _scope;