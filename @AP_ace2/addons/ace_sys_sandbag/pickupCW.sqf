#include "script_component.hpp"

_wire = _this;
_unit = player;

_wireFast = ["wire_2","wire_3","wire_4","wire_5","wire_6","wire_7","wire_8","wire_9","wire_10","wire_11","wire_12","wire_13","wire_14","wire_15","wire_16","wire_17","wire_18"]; // fast

_hasProf = ((getNumber(configFile >> "CfgVehicles" >> typeOf player >> "engineer")) == 1 || {(getNumber(configFile >> "CfgVehicles" >> typeOf player >> "canDeactivateMines")) == 1});
_delay = if (_hasProf) then { 60 } else { 120 };

// PROGRESS BAR
_unit setVariable ["ACE_PB_Result", 0];
[_delay,[_text],false,true,_unit,true] spawn ace_progressbar;
waitUntil { _unit getVariable "ACE_PB_Result" != 0 };
_exit = _unit getVariable "ACE_PB_Result" != 1;
_unit setVariable ["ACE_PB_Result", 0];

if (_exit) exitWith {};

{
	_wire animate [_x,1];
} foreach _wireFast;
waituntil {_wire animationPhase "wire_2" == 1};

_pos_w = getpos _wire;
_dir_w = getdir _wire;
_wirecoil = "ACE_ConcertinaWireCoil" createvehicle [0,0,0];
deletevehicle _wire;

_wirecoil setpos _pos_w;
_wirecoil setdir _dir_w;
_wirecoil setvelocity [0,0,0];
