/* ace_sys_wounds(.pbo) - fnc_stretcher.sqf | (c) 2012, 2013 by rocko */

#include "script_component.hpp"

private ["_stretcher", "_var", "_target"];

// Stretcher init
PARAMS_1(_stretcher);

_stretcher spawn {
	sleep 1;
	//_this lock true; // Locking stretcher is not good, blocks "pulling out units from vehicles"
};
player reveal _stretcher;

_var = _stretcher getVariable "ace_stretcher_front_grab";
if (isNil "_var") then {
	_stretcher setVariable ["ace_stretcher_front_grab",false];
};
_var = _stretcher getVariable "ace_stretcher_back_grab";
if (isNil "_var") then {
	_stretcher setVariable ["ace_stretcher_back_grab",false];
};

// Adding two useractions to grab stretcher front and back end
_stretcher addAction [
	localize "STR_ACE_UA_CARRY_STRETCHER_FRONT",
	QPATHTO_C(ua_grab_stretcher.sqf),
	["front", "grab", "ace_stretcher_front_grab", ["rotate_driver1",1]],
	-1,false,true,"",
	"(vehicle player == player) && {!(_target getVariable ""ace_stretcher_front_grab"")"
];
// Hintermann gets only the action WHEN frontman is already in (prevents Hintermann being locked in stretcher)
_stretcher addAction [
	localize "STR_ACE_UA_CARRY_STRETCHER_BACK",
	QPATHTO_C(ua_grab_stretcher.sqf),
	["back", "grab", "ace_stretcher_back_grab", ["rotate_driver2",1]],
	-1,false,true,"",
	"(vehicle player == player) && {!(_target getVariable ""ace_stretcher_back_grab"")} && {(_target getVariable ""ace_stretcher_front_grab"")}"
];
// Adding useraction to put stretcher on back
_stretcher addAction [
	localize "STR_ACE_UA_PICKUP_STRETCHER",
	QPATHTO_C(ua_grab_stretcher.sqf),
	["", "pickup", "", ["",""]],
	-1,false,true,"",
	"(vehicle player == player) && {!(_target getVariable ""ace_stretcher_front_grab"")} && {!(_target getVariable ""ace_stretcher_back_grab"")} && {(count(crew _target) == 0)}"
];
