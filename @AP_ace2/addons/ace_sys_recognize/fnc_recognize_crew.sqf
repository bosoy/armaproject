/* ace_sys_spacebar | (c) 2009 by rocko */

#include "script_component.hpp"

#define __LAYER 135696
#define __DISP ((uiNamespace getVariable "ACE_Recog_Vehicle_Overlay") displayCtrl -1)
#define __N "<br/>"
#define RDRIVER "\ca\ui\data\i_driver_ca.paa"
#define RGUNNER "\ca\ui\data\i_gunner_ca.paa"
#define RCOMMANDER "\ca\ui\data\i_commander_ca.paa"
#define RCARGO "\CA\ui\data\i_cargo_ca.paa"

if (isNil QGVAR(time)) then {GVAR(time) = -5};
if (time < GVAR(time)) exitWith {};

if (getNumber(configFile >> "CfgVehicles" >> typeOf _this >> "isBicycle") == 1) exitWith {};

_ar_P = [];
_ar_AI = [];

{
	if (alive _x) then {
		if (isPlayer _x) then {
			_ar_P set [count _ar_P, _x];
		} else {
			_ar_AI set [count _ar_AI, _x];
		};
	};
} foreach (crew _this);

// First build player names
_s_p = "";
if ((count _ar_P) > 0) then {
	_s_p = "<t align='left'>";
	{
		_role = assignedVehicleRole _x;
		if (count _role > 0) then {
			private "_rpic";
			if (commander _this == _x) then {
				_rpic = RCOMMANDER;
			} else {
				if (driver _this == _x) then {
					_rpic = RDRIVER;
				} else {
					_rpic = switch (toUpper (_role select 0)) do {
						case "TURRET": {RGUNNER};
						default {RCARGO};
					};
				};
			};
			_s_p = _s_p + "<img image='" + _rpic + "'/> " + (name _x) + __N;
		};
	} foreach _ar_P;
	_s_p = _s_p + "</t>";
};

_s_ai = "";
if (count _ar_AI > 0) then {
	_s_ai = "<t align='left'>";
	{
		_role = assignedVehicleRole _x;
		if (count _role > 0) then {
			private "_rpic";
			if (commander _this == _x) then {
				_rpic = RCOMMANDER;
			} else {
				if (driver _this == _x) then {
					_rpic = RDRIVER;
				} else {
					_rpic = switch (toUpper (_role select 0)) do {
						case "DRIVER": {RDRIVER};
						case "TURRET": {RGUNNER};
						default {RCARGO};
					};
				};
			};
			_s_ai = _s_ai + "<img image='" + _rpic + "'/> " + (name _x) + " (AI)" + __N;
		};
	} foreach _ar_AI;
	_s_ai = _s_ai + "</t>";
};

_t = "<t size='0.5'><t align='left'>Crew</t>" + __N + __N + _s_p + _s_ai + "</t>";

__LAYER cutRsc ["ACE_Recog_Vehicle_Overlay","PLAIN",0];
__DISP ctrlSetPosition [SafeZoneX + SafeZoneW - 0.23, SafeZoneY + 0.2,0.3,0.4];
__DISP ctrlSetStructuredText parseText _t;
__DISP ctrlCommit 0;

GVAR(shown) = true;
GVAR(time) = time + 5;
0 spawn {
	_timeend = time + 5;
	waitUntil {(time >= _timeend) || {!(alive player)}};
	__LAYER cutRsc ["DEFAULT", "PLAIN"];
	GVAR(shown) = false;
};