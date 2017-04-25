// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// TODO: Add check for heavy tripods that cannot be deployed while prone?

#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")

#define __MG_CFG configFile >> "CfgVehicles" >> _tripodType

private ["_tripod","_secWep","_confirmTripod","_offset","_worldPos","_ATLpos"];

PARAMS_1(_unit);

_confirmType = getText(configfile >> "CfgWeapons" >> secondaryWeapon _unit >> "ACE" >> "ACE_CREWSERVED" >> "tripodGhost");
_tripodType = getText(configfile >> "CfgWeapons" >> secondaryWeapon _unit >> "ACE" >> "ACE_CREWSERVED" >> "tripod");

_busy = _unit getVariable [QGVAR(busy), false];

if (!_busy) then {
	_confirmTripod = _confirmType createVehicleLocal [0,0,0];

	_unit setVariable [QGVAR(busy), true];
	_unit setVariable [QGVAR(tripod_confirmed), false];
	_unit setVariable [QGVAR(tripod_cancelled), false];

	_ACE_confirmDeployTripod = _unit addAction [ACE_TEXT_SILVER(localize "STR_ACE_AC_CONF"), QPATHTO_F(confirmDeployTripod),[],100];
	_ACE_cancelDeployTripod = _unit addAction [ACE_TEXT_RED(localize "STR_ACE_AC_CANCEL"), QPATHTO_F(cancelDeployTripod),[],99];

	_fConfirmed = { _unit getVariable QGVAR(tripod_confirmed) };
	_fCancelled = { _unit getVariable QGVAR(tripod_cancelled) };

	_tripodProxy = secondaryWeapon _unit;
		
	while {alive _unit && {!(call _fConfirmed)} && {!(call _fCancelled)}} do {
		_offset = [0, 4 + (_unit weaponDirection primaryWeapon _unit select 2) * 2,0];
		_ATLpos = getposATL _unit;
		_worldPos = _unit modelToWorld _offset;
		_confirmTripod setPosATL [_worldPos select 0,_worldPos select 1,_ATLpos select 2];
		_confirmTripod setDir (getDir _unit);
		sleep 0.1;
	};

	deleteVehicle _confirmTripod;
	_unit removeAction _ACE_confirmDeployTripod;
	_unit removeAction _ACE_cancelDeployTripod;
	if (call _fCancelled || {!alive _unit}) exitWith {
		_unit setVariable [QGVAR(tripod_confirmed), nil];
		_unit setVariable [QGVAR(tripod_cancelled), nil];
		_unit setVariable [QGVAR(busy), false];
	};

	// PROGRESS BAR
	_unit setVariable ["ACE_PB_Result", 0];
	_time = getNumber(__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "mountTime"); if (isNil "_time") then { _time = 5; };
	[_time,[""],false,true,_unit,true] spawn ace_progressbar;
	waitUntil { 
		if !(_unit hasWeapon _tripodProxy) then {
			_unit setVariable ["ACE_PB_Abort", true];
			_unit setVariable ["ACE_PB_Result", -1];
		};
		_unit getVariable "ACE_PB_Result" != 0 
	};
	_exit = (_unit getVariable "ACE_PB_Result" != 1);
	_unit setVariable ["ACE_PB_Result", 0];
	_unit setVariable ["ACE_PB_Abort", false];
	if (_exit) exitWith {
		_unit setVariable [QGVAR(tripod_confirmed), nil];
		_unit setVariable [QGVAR(tripod_cancelled), nil];
		_unit setVariable [QGVAR(busy), false];
	};
	
	_unit removeWeapon _tripodProxy;
	_unit setVariable [QGVAR(tripod_confirmed), nil];
	_unit setVariable [QGVAR(tripod_cancelled), nil];
	_tripod = _tripodType createVehicle [0,0,0];
	_tripod setDir (getDir _unit);
	_tripod setPosATL [_worldPos select 0,_worldPos select 1,_ATLpos select 2];

	_unit reveal _tripod;

	[QGVAR(noam), _tripod] call CBA_fnc_globalEvent;

	sleep 2;
	_unit setVariable [QGVAR(busy), false];
};
