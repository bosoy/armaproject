/* ----------------------------------------------------------------------------
Function: ACE_fnc_addMagazineCargoEx

Description:
	Add magazines with a specific bullet count to the cargo space of vehicles.

Parameters:
	vehicle: Object - vehicle to add the magazines to
	magazineName: String - magazine name
	bulletCount: Number - number of bullets

Optional Parameters:
	_wh - Set to true to create a weaponholder at _vehicle position [Boolean]

Returns:
		nothing

Examples:
	(begin example)
		[Car1,"100Rnd_M240_LaserBullets",10] call ACE_fnc_addMagazineCargoEx;
	(end)

Author:
	rocko
---------------------------------------------------------------------------- */
#include "script_component.hpp"

// TODO: Where does the AI have to be? Server, Local to vehicle?
//if !(isServer || {isDedicated}) exitWith { diag_log "exiting"; };
_this spawn {
	PARAMS_3(_vehicle,_magazine,_bulletcount); // TODO: Make run where _vehicle is local?
	DEFAULT_PARAM(3,_wh,false);
	_dummy = createAgent ["ACE_CivDummy", [10,10,0], [], 0, "FORM"];
	waitUntil { alive _dummy };
	
	_dummy disableAI "TARGET";
	_dummy disableAI "AUTOTARGET";
	_dummy disableAI "MOVE";
	_dummy disableAI "ANIM";
	removeAllWeapons _dummy;
	removeAllItems _dummy;
	player reveal _dummy;	
	
	_dummy addMagazine [_magazine,_bulletcount];
	if (_wh) then {
		_dummy setPosATL getPosATL _vehicle;
		_dummy action ["DropMagazine",_dummy,_magazine];
	} else {
		_dummy action ["DropMagazine",_vehicle,_magazine];
	};
	sleep 2;
	deleteVehicle _dummy;
};
