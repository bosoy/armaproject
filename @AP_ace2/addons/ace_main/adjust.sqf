#include "script_component.hpp"
#include "script_dialog_defines.hpp"
private ["_toh", "_disp", "_controldt", "_cposdt", "_xp", "_wp", "_yp"];
PARAMS_2(_typeui,_paramsdisp);

_toh = isClass (configFile >> "CfgPatches" >> "HSim_UI_H");

_disp = 1;
if (_typeui == "OnLoad") then {
	if (typeName (_paramsdisp select 0) == "DISPLAY") then {
		_disp = _paramsdisp select 0;
	};
	
	#define DISP(A) (_disp displayCtrl A)
	
	if (isNil {uiNamespace getVariable "ace_editor_debugc_available"}) then {
		DISP(1212) ctrlShow false;
	};
};

//baseline button
// _controldt = DISP(PG_Abort_IDC);
// _cposdt = ctrlPosition _controldt;
// _btn_hgt = _cposdt select 3;
// _bot_pos = (_cposdt select 1) + _btn_hgt;

//make ACE_settings second button from bottom
// _controldt = DISP(ACE_SETTINGS_IDC);
// _cposdt = ctrlPosition _controldt;
// _controldt ctrlSetPosition [_cposdt select 0, _bot_pos - _btn_hgt * 2, _cposdt select 2, _cposdt select 3];
// _controldt ctrlCommit 0;

//change mainback to 5 button graphics from MP menu
// _controldt = DISP(Mainback_IDC);
// _cposdt = ctrlPosition _controldt;
// _controldt ctrlSetPosition [_cposdt select 0, (_cposdt select 1) - _btn_hgt, _cposdt select 2, _cposdt select 3];
// _controldt ctrlCommit 0;
// _controldt ctrlSetText "\ca\ui\data\ui_background_mp_pause_ca.paa";

//move all buttons and items above it
// {
	// _controldt = DISP(_x);
	// _cposdt = ctrlPosition _controldt;
	// _controldt ctrlSetPosition [_cposdt select 0, (_cposdt select 1) - _btn_hgt, _cposdt select 2, _cposdt select 3];
	// _controldt ctrlCommit 0;
// } forEach [CA_PGTitle_IDC, ACE_LOGO_IDC, PG_Save_IDC, PG_Skip_IDC, PG_Revert_IDC, PG_Again_IDC, PG_Options_IDC];

if (_toh) then {
	if (_typeui == "OnLoad") then {
		// logo
		_controldt = DISP(113805);
		_cposdt = ctrlPosition _controldt;
		
		_xp = 1 * (1 / 32) + safezoneX;
		_wp = (10 * (1/ 32)) - 0.08;
		_yp = 5.5 * ((1 / 1.2) / 20) + (safezoneY + safezoneH - (1 / 1.2)) - 0.011;
		_controldt ctrlSetPosition [_xp + _wp, _yp, _cposdt select 2, _cposdt select 3];
		_controldt ctrlCommit 0;
		
		_this call compile preprocessfilelinenumbers "\hsim\ui_h\scripts\init_GUI.sqf";
	};
} else {
	if (_typeui == "OnLoad") then {
		_paramsdisp call compile preprocessFile "pauseOnload.sqf";
		[_paramsdisp,"onload"] call compile preprocessFile "\ca\ui\scripts\pauseCutScene.sqf";
		["Init", _paramsdisp] execVM "\ca\ui\scripts\pauseLoadinit.sqf";
		[] call compile preprocessFile "\ca\ui\scripts\uiPostEffectBlur.sqf";
	};
};
