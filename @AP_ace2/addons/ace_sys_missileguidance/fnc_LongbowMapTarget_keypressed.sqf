#include "script_component.hpp"
private ["_veh"];

_veh = vehicle player;

if !(alive _veh && {player == gunner _veh}) exitWith {false};

if !(currentWeapon _veh == "ACE_HellfireLauncher_Apache") exitWith {false};

openMap [true,false];
hint "Click target position on the map.\nHold Shift while clicking to clear the target.";

onMapSingleClick "
	private ['_vehicle','_logic'];
	_vehicle = vehicle player;
	[_vehicle] call ace_sys_missileguidance_fnc_longbowTarget_clear;
	if (currentWeapon _vehicle == 'ACE_HellfireLauncher_Apache' && !_shift) then {
		_logic = 'Logic' createVehicleLocal [0,0,0];
		_logic setPosASL [_pos select 0, _pos select 1, getTerrainHeightASL _pos];
		ace_sys_missileguidance_maptargets set [count ace_sys_missileguidance_maptargets,_logic];
		_vehicle setVariable ['ace_sys_missileguidance_longbowTarget', _logic];
		hint format ['Target set on grid\n%1', mapGridPosition _pos];
	} else {
		hint 'Target cleared';
	};
	openMap [false,false];
	onMapSingleClick ''
";
// allow setting "private waypoint" marker
false
