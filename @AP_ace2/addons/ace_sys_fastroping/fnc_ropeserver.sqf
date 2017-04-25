#include "script_component.hpp"

private ["_v", "_rope", "_rope1", "_posr", "_ropetype", "_sleeptime", "_touse", "_ropemodel", "_magHolder"];

PARAMS_3(_v,_rope,_rope1);

if (!isPlayer (driver _v)) then {
	[_v] spawn {
		PARAMS_1(_v);
		sleep 40;
		if (alive _v) then {
			_v setVariable ["ACE_RopeAbort", true, true];
		};
	};
};

waitUntil {sleep 0.121;(_v getVariable "ACE_RopeAbort") || {isNull (driver _v)} || {!alive _v} || {!canMove _v}};

[QGVAR(rma), _v] call CBA_fnc_globalEvent;

detach _rope;
_posr =+ position _rope;
_ropetype = typeOf _rope;
if (!isNull _rope1) then {
	detach _rope1;
};

[QGVAR(sv), _rope] call ACE_fnc_receiverOnlyEvent;
if (!isNull _rope1) then {
	[QGVAR(sv), _rope1] call ACE_fnc_receiverOnlyEvent;
};

_sleeptime = switch (toUpper _ropetype) do {
	case "ACE_FASTROPE_50": {2};
	case "ACE_FASTROPE_60": {2.5};
	case "ACE_FASTROPE_90": {3.5};
	case "ACE_FASTROPE_120": {5};
};

sleep _sleeptime;
deleteVehicle _rope;
if (!isNull _rope1) then {
	deleteVehicle _rope1;
};

_v setVariable ["ACE_RopeInUse", 0, true];
_v setVariable ["ACE_RopeController", objNull, true];

_touse = "";
{
	_ropemodel = getText(configFile >> "CfgMagazines" >> _x >> "ACE_FastRope_Model");
	if (_ropemodel == _ropetype) exitWith {_touse = _x};
} forEach ["ACE_Rope_M_50", "ACE_Rope_M_60", "ACE_Rope_M_90", "ACE_Rope_M_120"];

if (_touse != "") then {
	_magHolder = "WeaponHolder" createVehicle [0,0,0];
	_magHolder addMagazineCargoGlobal [_touse, 1];
	[QGVAR(wh), _magHolder] call CBA_fnc_globalEvent;
    _magHolder setPos [_posr select 0, _posr select 1,0];
};