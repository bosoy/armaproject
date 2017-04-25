/* ace_sys_minesweeper (.pbo) | (c) 2013 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_distance","_mines","_mine","_dSnd","_fnc_inRange"];

#define __DR 1.3

// TODO: If ACRE installed, create loss of radio signal due to GPR of AN PSS14 (Guess they don't have something like this implemented...)
// TODO: Check if another AN PSS14 is within 6 meters: 

#ifdef DEBUG_MODE_FULL
	dbg = "Sign_sphere10cm_EP1" createVehicleLocal [0,0,0];
#endif

/*
_fnc_inRange = {
	private ["_minePos","_Pos","_inX","_inY","_mineX","_mineY","_inRange"];
	_minePos = getPos (_this select 0);
	_Pos = _this select 1;
	
	_mineX = _minePos select 0; 
	_mineY = _minePos select 1;
	
	_inX = (((_Pos select 0) < (_mineX - 0.1)) || {((_Pos select 0) > (_mineX + 0.1))});
	_inY = (((_Pos select 1) < (_mineY - 0.1)) || {((_Pos select 1) > (_mineY + 0.1))});
	
	_inRange = (_inX || {_inY});
	_inRange
};*/


_dS = player getVariable [QGVAR(on),false];
if (_dS) exitWith { player setVariable [QGVAR(on),false,true]; TRACE_1("Exiting and switching off",_dS); };
if (!_dS) then { player setVariable [QGVAR(on),true,true]; };

_dSnd = "Sign_sphere10cm_EP1" createVehicleLocal [0,0,0];
_sr = getNumber(configFile >> "CfgWeapons" >> currentWeapon player >> "ACE" >> "ACE_MINESWEEPER" >> "range");
_sndPos = [0,0,0];

while { alive player && {currentWeapon player in ["ACE_Minedetector_US","ACE_VMH3","ACE_VMM3"]} && {vehicle player == player} && {player getVariable [QGVAR(on),false]} } do {
	_dP = player modelToWorld (player selectionPosition "granat");
	_dV = player weaponDirection "Put";
	_dPnt = [(_dP select 0)+__DR*(_dV select 0),(_dP select 1)+__DR*(_dV select 1),(_dP select 2)+__DR*(_dV select 2)];
	#ifdef DEBUG_MODE_FULL
		if (!isNull dbg) then {
			dbg setPos _dPnt;
		};
	#endif
	_mines = nearestObjects [_dPnt, ["ACE_Explosive_Object","ACE_Explosive_Helper","Land_IED_v1_PMC","Land_IED_v4_PMC"], 2.2];
	_mine = if (count _mines > 0) then { _mines select 0 } else { objNull };

	//hint format ["%1", (velocity _dSnd)];
	
	_scanning = false;
	
	if (!isNull _mine) then {
		_distance = _dPnt distance _mine; diag_log format ["distance %1",_distance];
		_detectable = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "detectable");
		#ifdef DEBUG_MODE_FULL
			player sidechat format ["%1 %2 %3 %4", typeof _mine,_sr,_distance,(_sr*_detectable)];
		#endif
		if (local player) then {
			if (_distance < (_sr*_detectable)/2) then {
				_scanning = true;
			} else {
				_scanning = false;
			};
		};
		//diag_log format ["snd dis dpnt %1",(_sndPos distance _dPnt)];
		if (_scanning && {(_sndPos distance _dPnt) > 0.08}) then {
			_sndPos = _dPnt;
			_dSnd attachto [player,[0,0,-3],""];
			_snd = if (_distance < 0.4) then { "ace_sweep_high" } else { "ace_sweep_low" };
			[_dSnd, player] say3D _snd;
			sleep 0.8;
			
			_scanning = false;
		};
		sleep 0.125;
	} else {
		sleep 0.125;
	};
};
player setVariable [QGVAR(on),false];
detach _dSnd;
deleteVehicle _dSnd;
