// fnc_throw.sqf | (c) 2009 by Inkompetent & Rommel & Rocko

#include "script_component.hpp"

private ["_selectionPosition", "_worldPosition", "_unitVelocity", "_unitDirection", "_tube", "_weaponDirection"];

PARAMS_2(_unit,_tubeModel);

TRACE_1("Dropping weapon","");

_selectionPosition = _unit selectionPosition "launcher";
_selectionPosition set [0, (_selectionPosition select 0) + 0.4]; // set tube to the right, so it does not push player away or make player hyper jump
_worldPosition = _unit modelToWorld _selectionPosition;

_tube = _tubeModel createVehicleLocal _worldPosition; // No need to broadcast, keep effect local

if (count _this > 2) then {	// Local event
	_weaponDirection = _this select 2;
	_tube attachTo [_unit,[0.4,0,0],"launcher"];
	waitUntil {sleep 0.1; _tube distance _unit < 2};
	detach _tube;
	_tube setVectorDir [sin (90 + (_weaponDirection select 0) atan2 (_weaponDirection select 1)), cos (90 + (_weaponDirection select 0) atan2 (_weaponDirection select 1)), _weaponDirection select 2];	// Eye-candy for local units
} else {
	_unitDirection = direction _unit;
	_unitPosATL = getPosATL _unit;
	_worldPosition set [2, _unitPosATL select 2];
	_tube setPosATL _worldPosition; // These coordinates are relative (check line 11)
	_tube setDir (_unitDirection - 270); // Direction is perpendicular to unit direction
	_tube setVelocity [(cos _unitDirection) / 6, (sin _unitDirection) / 6, 0]; // No need to check units velocity, the player cannot switch weapons while moving

};
_tube spawn {
	//Reset Tubes physics, attempt to avoid bouncy tubes
	sleep 1.5;
	_this setVelocity [0,0,0];
};

// New Cleaner
[_tube, 30] call ACE_fnc_add2fifo;
