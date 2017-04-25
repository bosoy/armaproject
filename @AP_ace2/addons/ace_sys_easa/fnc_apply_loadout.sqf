/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_veh);

if (({alive _x} count crew _veh) > 0) exitWith {
	format["Safety Violation. %1 has crew onboard",_veh] spawn ace_fnc_visual;
	closeDialog 0;
	false
};

_idc = [100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123];
private["_loadorder","_entry"];
_loadorder = [];
for "_x" from 0 to (count _idc) - 1 do {
	if (ctrlVisible (_idc select _x)) then {
		_index = lbCurSel (_idc select _x);
		_entry = lbData [_idc select _x, _index];
		if !(_entry == "") then {
			_loadorder set [count _loadorder, _entry];
		} else {
			_loadorder set [count _loadorder, "FakeWeapon"];
		};
	};
};
// Coming from dialog = local
_time = (count _loadorder) * 6;
_string = format[localize "CONFIG_DEPOT.SQF5" +": " + "%1",(typeOf _veh)];
player setVariable ["ACE_PB_Result", 0];
[_time,[_string],false,false] spawn ace_progressbar;
closeDialog 0;
[_veh,_loadorder] spawn {
	PARAMS_2(_veh,_loadorder);
	sleep 1;
	waitUntil { player getVariable "ACE_PB_Result" != 0 };

	if (isMultiPlayer) then {
		[QGVAR(load), [_veh,_loadorder,"C"]] call CBA_fnc_globalEvent;
	} else {
		[_veh,_loadorder,"C"] spawn FUNC(load);
	};
};

false
