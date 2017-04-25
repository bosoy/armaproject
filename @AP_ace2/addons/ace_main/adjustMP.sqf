#include "script_component.hpp"
#include "script_dialog_defines.hpp"

private ["_disp", "_controldt", "_sav_pos", "_cposdt", "_btn_hgt", "_bot_pos"];
PARAMS_2(_typeui,_paramsdisp);

_toh = isClass (configFile >> "CfgPatches" >> "HSim_UI_H");

_disp = 1;
if (_typeui == "OnLoad") then {
	if (typeName (_paramsdisp select 0) == "DISPLAY") then {
		_disp = _paramsdisp select 0;
	};
};

#define DISP(A) (_disp displayCtrl A)

// in a dedicated environment and in a hosted environment beeing a client simply hide the save menu entry and replace it with ACE Options
/*if (!isServer) then {
	_controldt = DISP(CA_B_SAVE_IDC);
	_sav_pos = ctrlPosition _controldt;
	_controldt ctrlShow false;

	_controldt = DISP(ACE_SETTINGS_IDC);
	_controldt ctrlSetPosition _sav_pos;
	_controldt ctrlCommit 0;
} else {
	//baseline button
	_controldt = DISP(CA_B_Abort_IDC);
	_cposdt = ctrlPosition _controldt;
	_btn_hgt = _cposdt select 3;
	_bot_pos = (_cposdt select 1) + _btn_hgt;

	//make ACE_settings second button from bottom
	_controldt = DISP(ACE_SETTINGS_IDC);
	_cposdt = ctrlPosition _controldt;
	_controldt ctrlSetPosition [_cposdt select 0, _bot_pos - _btn_hgt * 2, _cposdt select 2, _cposdt select 3];
	_controldt ctrlCommit 0;

	//change mainback to 6 button graphic (1024x1024 texture)
	_controldt = DISP(Mainback_IDC);
	_cposdt = ctrlPosition _controldt;
	_controldt ctrlSetPosition [_cposdt select 0, (_cposdt select 1) - _btn_hgt, (_cposdt select 2) * 2, (_cposdt select 3) * 2];
	_controldt ctrlCommit 0;
	_controldt ctrlSetText QPATHTO_T(data\ui_background_six_pause_ca.paa);

	//move all buttons and items above it
	{
		_controldt = DISP(_x);
		_cposdt = ctrlPosition _controldt;
		_controldt ctrlSetPosition [_cposdt select 0, (_cposdt select 1) - _btn_hgt, _cposdt select 2, _cposdt select 3];
		_controldt ctrlCommit 0;
	} forEach [Paused_Title_IDC, ACE_LOGO_IDC, CA_B_SAVE_IDC, CA_B_Skip_IDC, CA_B_REVERT_IDC, CA_B_Respawn_IDC, CA_B_Options_IDC];
};
*/

if (_toh) then {
	if (_typeui == "OnLoad") then {
		// logo
		_controldt = DISP(113805);
		_cposdt = ctrlPosition _controldt;
		
		_xp = 1 * (1 / 32) + safezoneX;
		_wp = (10 * (1/ 32)) - 0.08;
		_yp = 8 * ((1 / 1.2) / 20) + (safezoneY + safezoneH - (1 / 1.2)) - 0.011;
		_controldt ctrlSetPosition [_xp + _wp, _yp, _cposdt select 2, _cposdt select 3];
		_controldt ctrlCommit 0;
		
		_this call compile preprocessfilelinenumbers "hsim\ui_h\scripts\init_GUI.sqf";
	};
} else {
	if (_typeui == "OnLoad") then {
		["Init", _paramsdisp] execVM "\ca\ui\scripts\pauseLoadinit.sqf";
	};
};
