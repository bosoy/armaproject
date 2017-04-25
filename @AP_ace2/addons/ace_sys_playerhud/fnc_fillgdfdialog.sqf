//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_disp", "_basem", "_ctop", "_basepist", "_cpist", "_cfg", "_type", "_size", "_img", "_i", "_ctrl", "_cpos", "_ifak","_ifak_type"];

disableSerialization;
_disp = uiNamespace getVariable "ACE_RscGearFast";
#define CTRL(A) (_disp displayCtrl A)
#define __cfgM(MAG) configFile>>"CfgMagazines">>MAG

_basem = 109;
_ctop = 0;
_basepist = 122;
_cpist = 0;
_bifak = player getVariable "ACE_IFAK_Contents";
if (isNil "_bifak") then {_bifak = [0,0,0]};
_ifak =+ _bifak;
if (!isNil "ace_sys_wounds_enabled") then {
	_ifak_type = (player call ace_sys_ruck_fnc_detIFAK) select 0;
};
{
	_doadd = true;
	TRACE_1("",_x);
	if (!isNil "ace_sys_wounds_enabled") then {
		switch (_x) do {
			case (_ifak_type select 0): {
				_num = _ifak select 0;
				if (_num < 1) then {
					_ifak set [0, _num + 1];
					_doadd = false;
				};
			};
			case (_ifak_type select 1): {
				_num = _ifak select 1;
				if (_num < 1) then {
					_ifak set [1, _num + 1];
					_doadd = false;
				};
			};
			case (_ifak_type select 2): {
				_num = _ifak select 2;
				if (_num < 1) then {
					_ifak set [2, _num + 1];
					_doadd = false;
				};
			};
		};
	};
	if (_doadd) then {
		_cfg = __cfgM(_x);
		_type = getNumber(_cfg >> "type");
		if (_type < 256) then {
			_size = _type / 16;
			_img = getText(_cfg >> "picture");
			CTRL(_basepist) ctrlSetText _img;
			INC(_basepist);
			_cpist = _cpist + _size;
		} else {
			_size = _type / 256;
			_img = getText(_cfg >> "picture");
			CTRL(_basem) ctrlSetText _img;
			INC(_basem);
			_ctop = _ctop + _size;
		};
	};
} forEach (magazines player);

if (_ctop < 12) then {
	for "_i" from _ctop to 12 do {
		_img = if (_basem < 115) then {
			"\ca\ui\data\ui_gear_mag_gs.paa"
		} else {
			"\ca\ui\data\ui_gear_mag2_gs.paa"
		};
		CTRL(_basem) ctrlSetText _img;
		INC(_basem);
	};
};
if (_cpist < 8) then {
	for "_i" from _cpist to 8 do {
		CTRL(_basepist) ctrlSetText "\ca\ui\data\ui_gear_hgunmag_gs.paa";
		INC(_basepist);
	};
};

if (!isNil "ace_sys_wounds_enabled") then {
	if (count _ifak_type != 0) then {
		CTRL(1050) ctrlSetText getText(__cfgM(_ifak_type select 0) >> "picture");
		CTRL(1051) ctrlSetText getText(__cfgM(_ifak_type select 1) >> "picture");
		CTRL(1052) ctrlSetText getText(__cfgM(_ifak_type select 2) >> "picture");

		CTRL(1100) ctrlSetText str(_ifak select 0);
		CTRL(1101) ctrlSetText str(_ifak select 1);
		CTRL(1102) ctrlSetText str(_ifak select 2);
	} else {
		CTRL(1100) ctrlSetText "";
		CTRL(1101) ctrlSetText "";
		CTRL(1102) ctrlSetText "";	
	};
};

_ctrl = CTRL(1000);
_cpos = ctrlPosition _ctrl;
_cpos set [0, SafeZoneX + safeZoneW - 0.228];
_ctrl ctrlSetPosition _cpos;
_ctrl ctrlCommit 0.3;

0 spawn {
	private ["_endtime", "_disp", "_ctrl", "_cpos"];
	disableSerialization;
	_endtime = time + 3;
	waitUntil {sleep 0.221; time >= _endtime || {!alive player} || {(player call ace_sys_wounds_fnc_isUncon)}};
	_disp = uiNamespace getVariable "ACE_RscGearFast";
	_ctrl = CTRL(1000);
	_cpos = ctrlPosition _ctrl;
	_cpos set [0, SafeZoneX + safeZoneW + 0.01];
	_ctrl ctrlSetPosition _cpos;
	_ctrl ctrlCommit 0.3;
	GVAR(mag_check_open) = false;
};
