#include "script_component.hpp"
private ["_disp", "_control", "_selidx", "_seltxt"];
disableSerialization;

#define DISP(A) (_disp displayCtrl A)
_disp = uiNamespace getVariable "ACE_SETTINGS_DIALOG";

// client settings
// idc start = 1100

_control = DISP(1100);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_SIGHT_ADJUSTMENT_RIFLE_CONFIG_enable_BDC", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1101);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_WIND_CONFIG_enable_drift", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1102);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_RECOGNITION_Scanning_Method", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));

	if (!isNil "ace_sys_recognize_fnc_change_recognize") then {
		[_selidx] call ace_sys_recognize_fnc_change_recognize;
	};
};

_control = DISP(1103);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_RECOGNITION_Complex_Unit_Info", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));

	if (isNil "ace_sys_recognize_info_override") then {
		ace_sys_recognize_info_complex = _selidx;
	};
};

_control = DISP(1104);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_RECOGNITION_Player_Unit_Info", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));

	if (isNil "ace_sys_recognize_info_override") then {
		ace_sys_recognize_info_players = _selidx;
	};
};

_control = DISP(1105);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_WEAPONSELECT_firemodes_only", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1106);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_STANCEINDICATOR_enabled", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1107);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_ACE_ROUNDCOUNT_show_icon", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1108);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_sys_immersive_dismount_enabled", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1109);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_sys_cartridges_enabled", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1110);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_sys_handsignals_background_enabled", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1111);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_sys_handsignals_method", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1112);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_grenadethrow_cursor_type", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1113);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_grenadethrow_switch_to_weapon", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1114);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_grenadethrow_reset_mode", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1115);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_grenadethrow_swap_mouse_buttons", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1116);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_grenadethrow_fast_throw_ampl", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1117);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_grenadethrow_holding_ampl_gain", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1118);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_grenadethrow2_enabled", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};


_control = DISP(1119);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_interaction_toggle", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
	[] spawn { sleep 3; call ace_sys_interaction_fnc_toggle; };
};


_control = DISP(1120);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_sys_air_rwr_resource_pos", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};


// tracking
/*
_control = DISP(1200);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	_seltxt = _control lbText _selidx;
	["ACE_sys_tracking_MarkersSize", parseNumber _seltxt] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1201);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ACE_sys_tracking_MarkersEnabled", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1202);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	_seltxt = _control lbText _selidx;
	["ACE_sys_tracking_SideColors_EAST_friendly", _seltxt] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1203);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	_seltxt = _control lbText _selidx;
	["ACE_sys_tracking_SideColors_WEST_friendly", _seltxt] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1204);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	_seltxt = _control lbText _selidx;
	["ACE_sys_tracking_SideColors_GUER_friendly", _seltxt] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1205);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	_seltxt = _control lbText _selidx;
	["ACE_sys_tracking_SideColors_CIV_friendly", _seltxt] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

_control = DISP(1206);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	_seltxt = _control lbText _selidx;
	["ACE_sys_tracking_SideColors_ENEMY_friendly", _seltxt] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};
*/
// single player settings
// idc start = 1300

_control = DISP(1300);
_selidx = lbCurSel _control;
if (_selidx != -1) then {
	["ace_sys_wounds_sp_player_medic", _selidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
};

// keys

#define KEYCAPTION_IDC_KEYCONFIG 1500
#define KEYFEATURE_IDC_KEYCONFIG 2000
#define KEYTEXTBOX_IDC_KEYCONFIG 2500
#define KEYTALT_IDC_KEYCONFIG 3000
#define KEYTCTRL_IDC_KEYCONFIG 3500
#define KEYTSHIFT_IDC_KEYCONFIG 4000

_config = configFile >> "CfgSettings" >> "CBA" >> "events";
for "_i" from 0 to (count _config - 1) do {
	_cnow = _config select _i;
	_curclassname = toLower(configName _cnow);
	_ar = [];
	_curClassAr = toArray _curClassname;
	for "_j" from 0 to 3 do {
		PUSH(_ar,_curClassAr select _j);
	};
	if (_curclassname != "ace_keys_ver" && {toString _ar == "ace_"}) then {
		for "_e" from 0 to (count _cnow - 1) do {
			_cinside = _cnow select _e;
			_feature = configName _cinside;
			_handlertxt = _curclassname + "_" + _feature;
			_complete = "CBA_Events_" + _curclassname + "_" + _feature + "_";
			
			_keyhelperidx = (uiNamespace getVariable QGVAR(key_save_name)) find _complete;
			
			if (_keyhelperidx != -1) then {
				_control = DISP(KEYTEXTBOX_IDC_KEYCONFIG + _keyhelperidx);
				[_complete + "key", (uiNamespace getVariable QGVAR(key_save)) select _keyhelperidx] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));

				_control = DISP(KEYTSHIFT_IDC_KEYCONFIG + _keyhelperidx);
				[_complete + "shift", (if (ctrlText _control == QPATHTO_T(data\shift_ca.paa)) then {1} else {0})] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
				_shifty = (ctrlText _control == QPATHTO_T(data\shift_ca.paa));
				
				_control = DISP(KEYTCTRL_IDC_KEYCONFIG + _keyhelperidx);
				[_complete + "ctrl", (if (ctrlText _control == QPATHTO_T(data\ctrl_ca.paa)) then {1} else {0})] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
				_ctrly = (ctrlText _control == QPATHTO_T(data\ctrl_ca.paa));
				
				_control = DISP(KEYTALT_IDC_KEYCONFIG + _keyhelperidx);
				[_complete + "alt", (if (ctrlText _control == QPATHTO_T(data\alt_ca.paa)) then {1} else {0})] call (uiNamespace getVariable QUOTE(FUNC(saveSetting)));
				_alty = (ctrlText _control == QPATHTO_T(data\alt_ca.paa));			
				
				
				if (_curclassname != "ace_sys_interaction") then {
					if (!isNil "CBA_fnc_changeKeyHandler") then {
						[_handlertxt, (uiNamespace getVariable QGVAR(key_save)) select _keyhelperidx, [_shifty,_ctrly,_alty], "keydown"] call CBA_fnc_changeKeyHandler;
						[_handlertxt, (uiNamespace getVariable QGVAR(key_save)) select _keyhelperidx, [_shifty,_ctrly,_alty], "keyup"] call CBA_fnc_changeKeyHandler;
					};
				} else {
					if (!isNil "cba_ui_typeMenuSources") then {
						// quick hack to update the interaction menu keys.
						// those are added with CBA_ui_fnc_add and are stored in cba_ui_typeMenuSources
						private ["_which_key", "_which_shift", "_which_ctrl", "_which_alt"];
						if (_feature == "interaction_menu") then {
							_which_key = uiNamespace getVariable QGVAR(old_interaction_menu);
							_which_shift = uiNamespace getVariable QGVAR(old_interaction_menu_shift);
							_which_ctrl = uiNamespace getVariable QGVAR(old_interaction_menu_ctrl);
							_which_alt = uiNamespace getVariable QGVAR(old_interaction_menu_alt);
						} else {
							_which_key = uiNamespace getVariable QGVAR(old_interaction_menu_self);
							_which_shift = uiNamespace getVariable QGVAR(old_interaction_menu_self_shift);
							_which_ctrl = uiNamespace getVariable QGVAR(old_interaction_menu_self_ctrl);
							_which_alt = uiNamespace getVariable QGVAR(old_interaction_menu_self_alt);
						};
						{
							_artc = _x select 1;
							_arkar = _artc select 0;
							_arscaar = _arkar select 1;
							if (_arkar select 0 == _which_key) then {
								if (str(_which_shift) == str(_arscaar select 0) && {str(_which_ctrl) == str(_arscaar select 1)} && {str(_which_alt) == str(_arscaar select 2)}) then {
									_arkar set [0, (uiNamespace getVariable QGVAR(key_save)) select _keyhelperidx];
									_arkar set [1, [_shifty,_ctrly,_alty]];
								};
							};
						} forEach cba_ui_typeMenuSources;
					};
				};
			};
		};
	};
};
uiNamespace setVariable [QGVAR(key_save), nil];
uiNamespace setVariable [QGVAR(key_save_name), nil];

if (isNil {uiNamespace getVariable QGVAR(profilenamespace_available)}) then {
	call (uiNamespace getVariable QUOTE(FUNC(dumpToClipboard)));
} else {
	call (uiNamespace getVariable QUOTE(FUNC(writeToProfileNamespace)));
};

if (!isNil "CBA_logic") then {
	_message = if (isNil {uiNamespace getVariable QGVAR(profilenamespace_available)}) then {
		localize "STR_UCFG_SAVED"
	} else {
		localize "STR_UCFG_SAVED2";
	};
	CBA_logic globalChat _message;
} else {
	if (isNil {uiNamespace getVariable QGVAR(profilenamespace_available)}) then {
		1357 cutRsc ["ACE_SettingsMainMenu_Feedback", "PLAIN"];
	} else {
		1357 cutRsc ["ACE_SettingsMainMenu_Feedback2", "PLAIN"];
	};
};

if (!isNil "ace_sys_cartridges_enabled") then {
	// to change enable staying brass on the fly
	ace_sys_cartridges_enabled = (["ACE", "sys_cartridges", "enabled"] call ace_settings_fnc_getNumber) == 1;
};
