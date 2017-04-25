#include "script_component.hpp"
#include "script_dialog_defines.hpp"

private ["_disp", "_controldt", "_cposdt", "_toh"];

PARAMS_2(_typeui,_paramsdisp);

_toh = isClass (configFile >> "CfgPatches" >> "HSim_UI_H");

_disp = 1;
if (_typeui == "OnLoad") then {
	if (typeName (_paramsdisp select 0) == "DISPLAY") then {
		_disp = _paramsdisp select 0;
	};
	uiNamespace	setVariable [QGVAR(main_display), _disp];	
} else {
	uiNamespace	setVariable [QGVAR(main_display), nil];
};

#define DISP(A) (_disp displayCtrl A)
#define __add 0.101903
#define __add2 0.013

if (_typeui == "OnLoad") then {
	/*if (typeName _disp != "SCALAR" && !_toh) then {
		{
			_controldt = DISP(_x);
			_cposdt = ctrlPosition _controldt;
			_btn_y = _cposdt select 1;
			_controldt ctrlSetPosition [_cposdt select 0, _btn_y + __add2, _cposdt select 2, _cposdt select 3];
			_controldt ctrlCommit 0;
		} forEach [138, 105, 102,768];

		{
			_controldt = DISP(_x);
			_cposdt = ctrlPosition _controldt;
			_btn_y = _cposdt select 1;
			_controldt ctrlSetPosition [_cposdt select 0, _btn_y + __add + __add2, _cposdt select 2, _cposdt select 3];
			_controldt ctrlCommit 0;
		} forEach [1001, 140, 106];
	};*/
	
	//_control1 = DISP(1001);
	//_control2 = DISP(109);
	//_control1 ctrlSetText format [localize "STR_ACE_disp_profile", ctrlText _control2];
	
	// if (isClass (configFile >> "CfgPatches" >> "cwr2_UI")) then {
		// DISP(768) ctrlShow false;
		// DISP(1104) ctrlShow false;
		////DISP(113805) ctrlShow false;
	// } else {
		DISP(769) ctrlShow false;
	// };
	if (isClass (configFile >> "CfgPatches" >> "rhs_ui")) then {
		DISP(11023) ctrlShow false;
		DISP(118) ctrlSetPosition [(SafeZoneW + SafeZoneX) - 0.23, (SafeZoneH + SafeZoneY) - (1 - 0.92), 0.5, 0.05];
		DISP(118) ctrlCommit 0;
	};
	if (isClass (configFile >> "CfgPatches" >> "cwr2_UI")) then {
		_cpos = ctrlPosition DISP(44);
		_cpos set [1, (_cpos select 1) - 0.01];
		DISP(44) ctrlSetPosition _cpos;
		DISP(44) ctrlCommit 0;
	};
};

if (_toh) then {
	if (_typeui == "OnLoad") then {
		if (typeName _disp != "SCALAR") then {
			DISP(1104) ctrlShow false;
			
			_controldt = DISP(105);
			_p1 = (ctrlPosition _controldt) select 1;
			_controldt = DISP(138);
			_posfirst = ctrlPosition _controldt;
			_p2 = _posfirst select 1;
			
			_gap = _p1 - _p2;

			{
				_controldt = DISP(_x);
				_cposdt = ctrlPosition _controldt;
				_controldt ctrlSetPosition [_cposdt select 0, (_cposdt select 1) + _gap, _cposdt select 2, _cposdt select 3];
				_controldt ctrlCommit 0;
			} forEach [1001, 140];

			_controldt = DISP(768);
			_posfirst set [1, (_posfirst select 1) + (_gap * 3)];
			_controldt ctrlSetPosition _posfirst;
			_controldt ctrlCommit 0;
			
			// logo
			//_controldt = DISP(113805);
			// _cposdt = ctrlPosition _controldt;
			
			// _xp = 1 * (1 / 32) + safezoneX;
			// _wp = (10 * (1/ 32)) - 0.08;
			// _yp = (1 * ((1 / 1.2) / 20) + (safezoneY + safezoneH - (1 / 1.2))) - 0.011;
			// _controldt ctrlSetPosition [_xp + _wp, _yp, _cposdt select 2, _cposdt select 3];
			// _controldt ctrlCommit 0;
		};
	};
	
	_this call compile preprocessfilelinenumbers "\hsim\ui_h\scripts\init_GUI.sqf"
};
