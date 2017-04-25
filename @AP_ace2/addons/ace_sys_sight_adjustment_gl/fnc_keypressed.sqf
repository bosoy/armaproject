#include "script_component.hpp"
private["_class","_wpn","_s","_muzzles","_hasGL","_eh"];

#define __dsp (uiNameSpace getVariable "ACE_RscGenericNF")
#define __ctrl (__dsp displayCtrl 1358009)

//a 'valve' to cut off multiple key press events within 1 frame
if (GVAR(presstime) == time) exitwith {false};
GVAR(presstime) = time;

if (GVAR(running)) exitwith { GVAR(running) = false; false }; //switch info off
if (player != vehicle player) exitwith { false };
if (primaryWeapon player == "") exitwith { false };
if !(player call FUNC(hasGL)) exitwith { false };

GVAR(running) = true;
GVAR(sa_active) = false;

_eh = player getVariable "ace_sa_gl_firedEH";
if (isNil "_eh") then {
	_eh = player addEventHandler ["fired", { _this call FUNC(fired) }];
	player setVariable ["ace_sa_gl_firedEH",_eh];
};

[currentWeapon player] spawn {
	private ["_unit","_sign","_i","_min_i","_s","_elev","_range","_wd","_x1","_y","_z","_table","_mindiff","_diff"];
	PARAMS_1(_wpn);
	_unit = player;
	//_s = player addEventHandler ["fired", { _this call FUNC(fired) }];
	_table =
	[
		[50,37],
		[100,80],
		[150,132],
		[200,183],
		[250,237],
		[300,300],
		[350,358],
		[400,450],
		[400,1070],
		[350,1160],
		[300,1230],
		[250,1300],
		[200,1360],
		[150,1410],
		[100,1470]
	];
	cutRsc ["ACE_RscGenericNF","PLAIN"];
	while {GVAR(running) && {player == _unit} && {_wpn == primaryweapon player}} do {
		_range = 0;
		_wd = player weaponDirection _wpn;
		_x1 = _wd select 0;
		_y = _wd select 1;
		_z = _wd select 2;
		_elev = _z atan2 sqrt(_x1^2 + _y^2);
		//mils
		_elev = 1000*pi*_elev/180;
		_mindiff = 10000;
		_min_i = 0;
		_i = 0;
		_sign = "";
		{
			_diff = abs (_elev - (_x select 1));
			if (_diff <= 20 ) then {
				if (_diff <= 5) exitwith { __ctrl ctrlSetTextColor [1, 0, 0, 1];_range = _x select 0 };
				if (_diff > 5) exitwith { __ctrl ctrlSetTextColor [1, 1, 1, 1];_range = _x select 0 };
			}
			else {
				if (_diff < _mindiff) then { _mindiff = _diff;_min_i = _i };
			};
			_i = _i + 1;
		} foreach _table;
		if (_range == 0) then {
			_range = (_table select _min_i) select 0;
			if (_elev < (_table select _min_i) select 1) then { _sign = "<" } else { _sign = ">" };
			//invert signs for indirect fire angles
			if (_elev > 1089) then { if (_sign == "<") then { _sign = ">" } else { _sign = "<" } };
			__ctrl ctrlSetTextColor [1, 1, 1, 1];
		};
		__ctrl ctrlSetText format["%1: %2%3 m", localize "STR_ACE_SA_ATGL_RANGE", _sign, _range];
		if (isNull (ACE_Rsc_GenericNF)) then { GVAR(running) = false };
		sleep 0.08;
	};
	GVAR(running) = false;
	if (typeName __ctrl == "control") then { __ctrl ctrlShow false; cutText ["","PLAIN"];  };
	//player removeEventHandler ["fired", _s];
};

false
