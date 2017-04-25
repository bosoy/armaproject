/* ace_sys_flashbang (.pbo) | (c) 2008, 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_combatMode", "_behaviour"];

PARAMS_3(_unit,_pos_bangATL,_type);

_pos_bangASL = ATLToASL _pos_bangATL;

// TODO: How direct?
// _modDirect = if (_direct) then { 1 } else { 0 }; // not used, removed

// Distance between unit and blast
// _distance = getPosATL _unit distance _pos_bangATL; // removed. not used

// Is LOS between bang and unit obstructed? (Need to check if small object is obstructing view or if large object, e.g wall or vehicle etc.)
_clearLOS = lineIntersects [eyePos _unit,_pos_bangASL]; // _unit removed from lineIntersects. lineIntersects does not check for objects of type CAManBase
//_modLOS = if (_clearLOS) then { 1 } else { 0 }; // not used, removed
TRACE_2("LOS [CLEAR,MODIFIER]",_unit,_clearLOS);

// TODO: Check for terrainIntersec ?

_moves = [
	"AmelPercMstpSnonWnonDnon_zasah1",
	"AmelPercMstpSnonWnonDnon_zasah2",
	"AmelPercMstpSnonWnonDnon_zasah3hard",
	"AmelPercMstpSnonWnonDnon_zasah4",
	"AmelPercMstpSnonWnonDnon_zasah5hard",
	"AmelPercMstpSnonWnonDnon_zasah6hlava"
];

switch(_type) do {
	// 1: AI
	case 1: {
		if (!_clearLOS) then { // AI is always affected by bang if in range and not obstructed
			//_combatMode = combatMode _unit;
			//_behaviour = behaviour _unit;
			TRACE_1("AI LOS",_unit);
			_unit setCombatMode "Green";
			_unit setBehaviour "SAFE";
			_unit disableAI "AUTOTARGET";
			_unit disableAI "TARGET";
			_unit doWatch [(position _unit) select 0,(position _unit) select 1, 1000];
			_unit setDir (direction _unit)+180;
			_unitpos = unitPos _unit;
			_ran = random 100;
			if (_ran < 33) then {
				_unit setUnitPos "Middle";
			} else {
				if (_ran < 66) then {
					_unit setUnitPos "Down";
				};
			};
			_unit disableAI "MOVE";
			sleep (10 + (random 5));
			_unit enableAI "AUTOTARGET";
			_unit enableAI "TARGET";
			_unit enableAI "MOVE";
			_unit setUnitPos "Auto";
			// let's set the unit at least to aware and yellow. Otherwise it seems they are put to safe and green and they don't react anyore.
			_unit setBehaviour "AWARE";
			_unit setCombatMode "YELLOW";
			_unit setUnitPos _unitpos;
			//_unit setCombatMode _combatMode;
			//_unit setBehaviour _behaviour;
			_unit dowatch objNull;
		};
	};
	 // 2: PLAYER
	case 2:	{
		//#ifndef DEBUG_MODE_FULL
		// Is unit looking directly at bang position?
		_direct = ([_unit, _pos_bangATL] call CBA_fnc_headDir) select 2;
		//TRACE_1("Looking at flashbang",_direct); // If looking directly at bang then suffer from longer blindness, if not blindness is rather short but bang sound
		// Blindness reduction for a player wearing eye protection
		_blindness_reduction = if (_direct && {[_unit] call ace_sys_goggles_fnc_eyeprotection}) then { 4 } else { 0 }; // 3 seconds less dizzy and blinding effect if wearing a goggle
		if (!_clearLOS && {_direct}) then {
			_unit setDir (direction _unit)+80+(random 100);
			[_unit,(5-_blindness_reduction),4] call ace_fx_fnc_flash; 			// Flash
			[_unit,(12-_blindness_reduction)] call ace_fx_fnc_blurry; 			// Blurry
			[_unit,30-(4*_blindness_reduction),0.08] call ace_fx_fnc_dizzy; 	// Make dizzy
			[_unit,false,-1,"ACE_Ring_Flashbang","",true] call ace_fx_fnc_ring; // Always play bang sound, because it's meant to be loud	
		} else {
			[_unit,(7-_blindness_reduction)] call ace_fx_fnc_blurry;
			[_unit,10-(4*_blindness_reduction),0.08] call ace_fx_fnc_dizzy;
			[_unit,false,-1,"ACE_Ring_Flashbang","",true] call ace_fx_fnc_ring;
		};
		//#endif
	};
};
