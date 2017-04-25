#include "script_component.hpp"
/*	update_actions.sqf

Manages actions for player-controlled AI so that they can interact with
the crewed weapons components (tripods, weapons and fully assembled
weapons)

These are the actions that we manage here. They were previously in
a UserActions config class in ace_c_useractions but the performance
penalty was too large - when you selected one or more of your units,
the framerate dropped considerably.

ACE_AIMountCrewMG		"Mount Machine Gun"
ACE_AIPickupCrewTripod	"Pickup Tripod"
ACE_AIRotateMGLeft		"Rotate MG Left"
ACE_AIRotateMGRight		"Rotate MG Right"
ACE_AILoadMGAmmo		"Load/link Ammo"
ACE_AIUnloadMGAmmo		"Unload/unlink Ammo"
ACE_AIUnmountCrewMG		"Unmount MG"

*/
private ["_grp", "_units", "_remove", "_unit", "_busy","_idle"];

_grp = _this;
_units = (units _grp) - [player];
_remove = [];

// 1: If needed, initialise the per-unit action id variables and collect
{ //	human players and dead soldiers
		_unit = _x; {
			_aidVar = "ace_sys_crewserved_" + str(_x);
			_aid = _unit getVariable _aidVar;
			if (isNil "_aid") then { _unit setVariable[_aidVar, -1]; };
		} forEach GVAR(CSW_ACTIONS);
		_busy = _unit getVariable QGVAR(busy);
		if (isNil "_busy") then {_unit setVariable [QGVAR(busy),false] };
		if (isPlayer _unit || {!alive _unit}) then { _remove set [count _remove, _unit]; };
} forEach _units;

// 2: Remove actions previously added to players and corpses
_units = _units - _remove;
{_x call _fRemoveActions} forEach _remove;

{ // 3: Check conditions for each of the actions and add/remove them as needed
		_unit = _x;
		_busy = _unit getVariable QGVAR(busy);
		_idle = [!_busy, true] select (isNil"_busy");

		// "DeployTripod"
		if (_idle && {_unit call _fDeployTripod}) then {
			[_unit, "deploy"] call _fAddAction;
		} else {
			[_unit, "deploy"] call _fRemoveAction;
		};

		// "Mount Machine Gun"
		if (_idle && {_unit call _fMount}) then {
			[_unit, "mount"] call _fAddAction;
		} else {
			[_unit, "mount"] call _fRemoveAction;
		};

		// "Rotate MG Left",  "Rotate MG Right"
		if (_idle && {_unit call _fRotate}) then  {
			[_unit, "left"] call _fAddAction;
			[_unit, "right"] call _fAddAction;
		} else {
			[_unit, "left"] call _fRemoveAction;
			[_unit, "right"] call _fRemoveAction;
		};

		// "Load/link ammo"
		if (_idle && {_unit call _fLoad}) then {
			[_unit, "load"] call _fAddAction;
		} else {
			[_unit, "load"] call _fRemoveAction;
		};

		// "Unload/unlink ammo"
		if (_idle && {_unit call _fUnload}) then {
			[_unit, "unload"] call _fAddAction;
		} else {
			[_unit, "unload"] call _fRemoveAction;
		};

		// "Unmount MG"
		if (_idle && {_unit call _fUnmount}) then {
			[_unit, "unmount"] call _fAddAction;
		} else {
			[_unit, "unmount"] call _fRemoveAction;
		};

		// "Pick up tripod"
		if (_idle && {_unit call _fPickup}) then {
			[_unit, "pickup"] call _fAddAction;
		} else {
			[_unit, "pickup"] call _fRemoveAction;
		};
} forEach _units;
