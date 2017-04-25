//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define DISP(A) (_disp displayCtrl A)

private ["_captionname","_featurename","_disp", "_fnc_verison", "_fnc_selection", "_control", "_txt", "_idx", "_prefix", "_main", "_pname", "_bdc", "_drift", "_scan", "_cinfo", "_pinfo", "_select", "_stance", "_roundcount", "_msize", "_useidx", "_menabled", "_markercolors", "_mcolor", "_config", "_overall", "_i", "_cnow", "_curclassname", "_curclassfull", "_e", "_cinside", "_feature", "_featurefull", "_key", "_keystr", "_shift", "_ctrl", "_alt","_g2enabled"];
disableSerialization;
_disp = uiNamespace getVariable "ACE_SETTINGS_DIALOG";

if (ctrlEnabled DISP(9999)) then {
	0 spawn {
		private ["_disp", "_i"];
		disableSerialization;
		_disp = uiNamespace getVariable "ACE_SETTINGS_DIALOG";
		DISP(9999) ctrlEnable false;
		for "_i" from 10 to 0 step -1 do {
			if (isNull _disp || {!ctrlVisible 9999}) exitWith {};
			DISP(9999) ctrlSetText str(_i);
			uiSleep 1;
		};
		if (!isNull _disp && {ctrlVisible 9999}) then {
			DISP(9999) ctrlSetText (localize "STR_BUTTONS_EXECUTE");
			DISP(9999) ctrlEnable true;
		};
	};
};

_fnc_version = {
	private ["_control", "_txt"];
	PARAMS_2(_idx,_prefix);
	_txt = getText(configFile >> "CfgPatches" >> (_prefix + "_main") >> "versionstr");
	if (_txt == "") then {_txt = OPTION_NA};
	DISP(_idx) ctrlSetText ((toUpper _prefix) + ": " + _txt);
};

_fnc_selection = {
	#define DEF_OPTIONS OPTION_NO, OPTION_YES
	private "_value";
	PARAMS_1(_config);
	_options = if (count _this > 1) then {_this select 1} else {[DEF_OPTIONS]};
	_value = _config call (uiNamespace getVariable QUOTE(FUNC(getNumber)));
	INC(_id);
	_control = DISP(_id);
	lbClear _control;
	{ _control lbAdd _x } forEach _options;
	_control lbSetCurSel _value;
	[_id,_value];
};

[10000,"ace"] call _fnc_version;
[10001,"acex"] call _fnc_version;
[10002,"cba"] call _fnc_version;
[10003,"acex_ru"] call _fnc_version;
[10004,"acex_usnavy"] call _fnc_version;


// !!
// Refer to script_translations.hpp for Options
// Add options to stringtable.xml if not present

// ## FILL SP CLIENT OPTIONS

_id = 1099; // Set startID for function _fnc_selection

_bdc = [["ACE", "ACE_SIGHT_ADJUSTMENT_RIFLE_CONFIG", "enable_BDC"]] call _fnc_selection;
_drift = [["ACE", "ACE_WIND_CONFIG", "enable_drift"]] call _fnc_selection;
_scan = [["ACE", "ACE_RECOGNITION", "Scanning_Method"], [OPTION_KEY_SPACEBAR,OPTION_KEY_MOUSEWHEEL,OPTION_CONSTANT]] call _fnc_selection;
_cinfo = [["ACE", "ACE_RECOGNITION", "Complex_Unit_Info"]] call _fnc_selection;
_pinfo = [["ACE", "ACE_RECOGNITION", "Player_Unit_Info"]] call _fnc_selection;
_select = [["ACE", "ACE_WEAPONSELECT", "firemodes_only"], [OPTION_ALL,OPTION_CUR]] call _fnc_selection;
_stance = [["ACE", "ACE_STANCEINDICATOR", "enabled"]] call _fnc_selection;
_roundcount = [["ACE", "ACE_ROUNDCOUNT", "show_icon"], [OPTION_ICON,OPTION_TEXT]] call _fnc_selection;
_immersive = [["ACE", "sys_immersive_dismount", "enabled"]] call _fnc_selection;
_brass = [["ACE", "sys_cartridges", "enabled"]] call _fnc_selection;
_gesture = [["ACE", "sys_handsignals", "background_enabled"]] call _fnc_selection;
_gesture_method = [["ACE", "sys_handsignals", "method"],[OPTION_GESTURE,OPTION_ACTIONMENU,OPTION_NUMPAD]] call _fnc_selection; // 0,1,2

// Grenade throwing
_gcursor = [["ACE", "sys_grenadethrow", "cursor_type"], [OPTION_NONE,OPTION_CURSOR,OPTION_ICON]] call _fnc_selection;
_gswitch = [["ACE", "sys_grenadethrow", "switch_to_weapon"]] call _fnc_selection;
_greset = [["ACE", "sys_grenadethrow", "reset_mode"]] call _fnc_selection;
_ginvmb = [["ACE", "sys_grenadethrow", "swap_mouse_buttons"]] call _fnc_selection;
_gampl = [["ACE", "sys_grenadethrow", "fast_throw_ampl"],["0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1"]] call _fnc_selection;
_ggain = [["ACE", "sys_grenadethrow", "holding_ampl_gain"],["0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1","1.1","1.2","1.3","1.4","1.5"]] call _fnc_selection;
// GrenadeThrow2
_g2enabled = [["ACE", "sys_grenadethrow2", "enabled"]] call _fnc_selection; //Default: YES //TRACE_1("",_g2enable);

// Interaction Menu Toggle
_imtoggle = [["ACE", "sys_interaction", "toggle"],[OPTION_PRESSKEY,OPTION_HOLDKEY]] call _fnc_selection; //0,1

// rwr
// ALWAYS NEED TO MOVE IN BETWEEN LAST  _fnc_selection,  and  TRACKING entry
// Also adjust in ACE_SettingsDialog.hpp!
_rwr_pos = ["ACE", "sys_air_rwr", "resource_pos"] call (uiNamespace getVariable QUOTE(FUNC(getNumber)));
_control = DISP(1120); // ADJUST ME when adding more _fnc_selections above.
lbClear _control;
{
	_idx = _control lbAdd _x;
} forEach [OPTION_BR,OPTION_TR,OPTION_TL,OPTION_BL];
_control lbSetCurSel _rwr_pos;


// tracking
//_msize = ["ACE", "sys_tracking", "MarkersSize"] call (uiNamespace getVariable QUOTE(FUNC(getNumber)));
//
//_control = DISP(1200);
//lbClear _control;
//_useidx = 0;
//{
//	_idx = _control lbAdd _x;
//	if (str(_msize) == _x) then {
//		_useidx = _idx;
//	};
//} forEach ["0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1"];
//_control lbSetCurSel _useidx;

// ## FILL CLIENT OPTIONS CUSTOM

//_id = 1200; // Set startID for function _fnc_selection
//_menabled = [["ACE", "sys_tracking", "MarkersEnabled"]] call _fnc_selection;

/* colors
_markercolors = ["Default","ColorBlack","ColorRed","ColorRedAlpha","ColorGreen","ColorGreenAlpha","ColorBlue","ColorYellow","ColorOrange","ColorWhite","ColorPink","ColorBrown","ColorKhaki"];
_mcolor = ["ACE", "sys_tracking", "SideColors", "EAST", "friendly"] call (uiNamespace getVariable QUOTE(FUNC(getText)));

_control = DISP(1202);
lbClear _control;
_useidx = 0;
{
	_idx = _control lbAdd _x;
	if (_mcolor == _x) then {
		_useidx = _idx;
	};
} forEach _markercolors;

_control lbSetCurSel _useidx;

_mcolor = ["ACE", "sys_tracking", "SideColors", "WEST", "friendly"] call (uiNamespace getVariable QUOTE(FUNC(getText)));

_control = DISP(1203);
lbClear _control;
_useidx = 0;
{
	_idx = _control lbAdd _x;
	if (_mcolor == _x) then {
		_useidx = _idx;
	};
} forEach _markercolors;

_control lbSetCurSel _useidx;

_mcolor = ["ACE", "sys_tracking", "SideColors", "GUER", "friendly"] call (uiNamespace getVariable QUOTE(FUNC(getText)));

_control = DISP(1204);
lbClear _control;
_useidx = 0;
{
	_idx = _control lbAdd _x;
	if (_mcolor == _x) then {
		_useidx = _idx;
	};
} forEach _markercolors;

_control lbSetCurSel _useidx;

_mcolor = ["ACE", "sys_tracking", "SideColors", "CIV", "friendly"] call (uiNamespace getVariable QUOTE(FUNC(getText)));

_control = DISP(1205);
lbClear _control;
_useidx = 0;
{
	_idx = _control lbAdd _x;
	if (_mcolor == _x) then {
		_useidx = _idx;
	};
} forEach _markercolors;

_control lbSetCurSel _useidx;

_mcolor = ["ACE", "sys_tracking", "SideColors", "ENEMY", "friendly"] call (uiNamespace getVariable QUOTE(FUNC(getText)));

_control = DISP(1206);
lbClear _control;
_useidx = 0;
{
	_idx = _control lbAdd _x;
	if (_mcolor == _x) then {
		_useidx = _idx;
	};
} forEach _markercolors;

_control lbSetCurSel _useidx;
*/
// Hide Options Control Group
DISP(1000) ctrlShow false; 
DISP(1000) ctrlCommit 0;

// ## FILL SP CLIENT OPTIONS

_id = 1299; // Set startID for function _fnc_selection

_spplayermedic = [["ace", "sys_wounds", "sp_player_medic"]] call _fnc_selection;

// Hide SP Options Control Group
DISP(1003) ctrlShow false; 
DISP(1003) ctrlCommit 0;

// ## FILL KEY SETTINGS DIALOG

#define KEYGROUP_IDC_KEYCONFIG 1400
#define COMBO_IDC_CLIENTCONFIG_SP 1300
#define KEYCAPTION_IDC_KEYCONFIG 1500
#define KEYFEATURE_IDC_KEYCONFIG 2000
#define KEYTEXTBOX_IDC_KEYCONFIG 2500
#define KEYTALT_IDC_KEYCONFIG 3000
#define KEYTCTRL_IDC_KEYCONFIG 3500
#define KEYTSHIFT_IDC_KEYCONFIG 4000

private ["_group","_componentName","_shift","_ctrl","_alt"];

_grp_vehicle = [localize "STR_TITLESMAIN_VEH"]; // TODO: localize
_grp_item = [localize "STR_TITLESMAIN_ITEM"];
_grp_weapon = [localize "STR_TITLESMAIN_WEP"];
_grp_other = [localize "STR_TITLESMAIN_OTHER"];
_grp_empty = [""];
_grp_interact = [localize "STR_TITLESMAIN_INTERACTION"];

_config = configFile >> "CfgSettings" >> "CBA" >> "events";

uiNamespace setVariable [QGVAR(key_save), []];
uiNamespace setVariable [QGVAR(key_save_name), []];

_key_ar = [];
for "_i" from 0 to (count _config - 1) do {
	_cur_config_now = _config select _i;
	_cur_component = configName _cur_config_now;
	_cur_component_full = _cur_component;
	_ar = [];
	_cur_component_ar = toArray _cur_component;
	
	for "_j" from 0 to 3 do {
		//PUSH(_ar,_cur_component_ar select _j);
		_ar set [count _ar, _cur_component_ar select _j];
	};
	
	if (_cur_component_full != "ace_keys_ver" && {toString _ar == "ace_"}) then {
		if (isText(configFile >> "CfgPatches" >> _cur_component_full >> "ACE_Options" >> "group")) then {
			_group = getText(configFile >> "CfgPatches" >> _cur_component_full >> "ACE_Options" >> "group");
		} else {
			_group = "Empty";
		};
		if (isText(configFile >> "CfgPatches" >> _cur_component_full >> "ACE_Options" >> "title")) then {
			_componentName = getText(configFile >> "CfgPatches" >> _cur_component_full >> "ACE_Options" >> "title");
		} else {
			_componentName = [_cur_component_full, "ace_sys_", ""] call (uiNamespace getVariable QUOTE(FUNC(replace)));
			_componentName = [_componentName, "_", " "] call (uiNamespace getVariable QUOTE(FUNC(replace)));
			_componentName = [_componentName] call (uiNamespace getVariable QUOTE(FUNC(capitalize)));
		};
		for "_e" from 0 to (count _cur_config_now - 1) do {
			_cinside = _cur_config_now select _e;
			_key_name = configName _cinside;
			_key_name_full = _key_name;
			
			_keynamehelper = "CBA_Events_" + _cur_component_full + "_" + _key_name_full + "_";
			
			if (isText(configFile >> "CfgPatches" >> _cur_component_full >> "ACE_Options" >> _key_name >> "title")) then {
				_key_name = getText (configFile >> "CfgPatches" >> _cur_component_full >> "ACE_Options" >> _key_name >> "title");
			} else {
				_key_name = [_key_name, "_", " "] call (uiNamespace getVariable QUOTE(FUNC(replace)));
				_key_name = [_key_name] call (uiNamespace getVariable QUOTE(FUNC(capitalize)));
			};
			_key = ["CBA", "Events", _cur_component_full, _key_name_full, "key"] call (uiNamespace getVariable QUOTE(FUNC(getNumber)));
			_feature_not_found = false;
			if (_key == 0) then {
				_key = getNumber(_cinside >> "key");
				_feature_not_found = true;
			};
			
			// huh ?
			_isint_ac = 0;
			if (_cur_component_full == "ace_sys_interaction") then {
				if (_key_name_full == "Interaction_Menu") then {
					uiNamespace setVariable [QGVAR(old_interaction_menu), _key];
					_isint_ac = 1;
				} else {
					uiNamespace setVariable [QGVAR(old_interaction_menu_self), _key];
					_isint_ac = 2;
				};
			};
			
			if (_feature_not_found) then {
				_shift = getNumber(_cinside >> "shift");
			} else {
				_shift = ["CBA", "Events", _cur_component_full, _key_name_full, "shift"] call (uiNamespace getVariable QUOTE(FUNC(getNumber)));
			};
			switch (_isint_ac) do {
				case 1: {uiNamespace setVariable [QGVAR(old_interaction_menu_shift), (_shift == 1)]};
				case 2: {uiNamespace setVariable [QGVAR(old_interaction_menu_self_shift), (_shift == 1)]};
			};
			
			if (_feature_not_found) then {
				_ctrl = getNumber(_cinside >> "ctrl");
			} else {
				_ctrl = ["CBA", "Events", _cur_component_full, _key_name_full, "ctrl"] call (uiNamespace getVariable QUOTE(FUNC(getNumber)));
			};
			switch (_isint_ac) do {
				case 1: {uiNamespace setVariable [QGVAR(old_interaction_menu_ctrl), (_ctrl == 1)]};
				case 2: {uiNamespace setVariable [QGVAR(old_interaction_menu_self_ctrl), (_ctrl == 1)]};
			};			
			
			if (_feature_not_found) then {
				_alt = getNumber(_cinside >> "alt");
			} else {
				_alt = ["CBA", "Events", _cur_component_full, _key_name_full, "alt"] call (uiNamespace getVariable QUOTE(FUNC(getNumber)));
			};
			switch (_isint_ac) do {
				case 1: {uiNamespace setVariable [QGVAR(old_interaction_menu_alt), (_alt == 1)]};
				case 2: {uiNamespace setVariable [QGVAR(old_interaction_menu_self_alt), (_alt == 1)]};
			};			
			
			_sub_key_ar = [_key_name,_key,_shift,_ctrl,_alt, _keynamehelper];
			_key_ar set [count _key_ar,_sub_key_ar];
			_sub_key_ar = [];
		};
		_component_store_ar = [_componentName,_key_ar];
		_key_ar = [];
		
		switch (_group) do {
			case "INTERACTION": {
				_grp_interact set [count _grp_interact,_component_store_ar];
				_component_store_ar = [];
			};			
			case "VEH": {
				_grp_vehicle set [count _grp_vehicle,_component_store_ar];
				_component_store_ar = [];
			};
			case "ITEMS": {
				_grp_item set [count _grp_item,_component_store_ar];
				_component_store_ar = [];				
			};
			case "WEP": {
				_grp_weapon set [count _grp_weapon,_component_store_ar];
				_component_store_ar = [];				
			};
			case "OTHER": {
				_grp_other set [count _grp_other,_component_store_ar];
				_component_store_ar = [];				
			};
			case "Empty": {
				_grp_empty set [count _grp_empty,_component_store_ar];
				_component_store_ar = [];				
			};
		};
	};
};

_overall = 0;
{
	_ar = _x;
	_D_groupname = _ar select 0;
	_control = _disp displayCtrl (KEYFEATURE_IDC_KEYCONFIG + _overall);
	_control ctrlSetStructuredText (parseText format ["<t size='0.8' font='Zeppelin33' color='#FFFFFF' underline='1'>%1</t>",_D_groupname]);
	_control ctrlCommit 0;
	_kst = uiNamespace getVariable QGVAR(key_save);
	_kst set [_overall, -999];
	_kst = uiNamespace getVariable QGVAR(key_save_name);
	_kst set [_overall, ""];
	INC(_overall);
	for "_q" from 1 to (count _ar - 1) do {
		_k_ar = _ar select _q;
		_D_component_name = _k_ar select 0;
		_control = _disp displayCtrl (KEYFEATURE_IDC_KEYCONFIG + _overall);
		// Change width 
		_control_pos = ctrlPosition _control;
		_control_pos set [2, 0.7];
		_control ctrlSetPosition _control_pos;
		// Scale text if too long		
		if (count toArray(_D_component_name) > 40) then {
			_control ctrlSetStructuredText (parseText format ["<t size='0.7' font='Zeppelin33' color='#DFD8A6'>  %1</t>",_D_component_name]);
		} else {		
			_control ctrlSetStructuredText (parseText format ["<t size='0.8' font='Zeppelin32' color='#DFD8A6'>  %1</t>",_D_component_name]);
		};
		_control ctrlCommit 0;
		_kk_ar = _k_ar select 1;
		if ((toArray _D_component_name) select 0 != 32) then {
			_kst = uiNamespace getVariable QGVAR(key_save);
			_kst set [_overall, -999];
			_kst = uiNamespace getVariable QGVAR(key_save_name);
			_kst set [_overall, ""];
			INC(_overall);
		};
		for "_w" from 0 to (count _kk_ar - 1) do {
			_D_key_info = _kk_ar select _w;
			_D_feature_name = _D_key_info select 0;
			_control = _disp displayCtrl (KEYFEATURE_IDC_KEYCONFIG + _overall);
			_control ctrlSetStructuredText (parseText format ["<t size='0.65' font='Zeppelin32' color='#FFFFFF' shadow='2'>    %1</t>",_D_feature_name]);
			_control ctrlCommit 0;	
			
			_D_feature_key = _D_key_info select 1;
			
			_kst = uiNamespace getVariable QGVAR(key_save);
			_kst set [_overall, _D_feature_key];
			_kst = uiNamespace getVariable QGVAR(key_save_name);
			_kst set [_overall, _D_key_info select 5];
			
			_keystr = call compile format ["%1", keyName _D_feature_key];
			_control = _disp displayCtrl (KEYTEXTBOX_IDC_KEYCONFIG + _overall);
			_control ctrlSetText _keystr;
			_control ctrlCommit 0;
		
			_D_feature_key_shift = _D_key_info select 2;
			_control = _disp displayCtrl (KEYTSHIFT_IDC_KEYCONFIG + _overall);
			if (_D_feature_key_shift == 1) then {
				_control ctrlSetText QPATHTO_T(data\shift_ca.paa);
			} else {
				_control ctrlSetText "";
			};
			_control ctrlCommit 0;
			
			_D_feature_key_ctrl = _D_key_info select 3;
			_control = _disp displayCtrl (KEYTCTRL_IDC_KEYCONFIG + _overall);
			if (_D_feature_key_ctrl == 1) then {
				_control ctrlSetText QPATHTO_T(data\ctrl_ca.paa);
			} else {
				_control ctrlSetText "";
			};
			_control ctrlCommit 0;
			
			_D_feature_key_alt = _D_key_info select 4;
			_control = _disp displayCtrl (KEYTALT_IDC_KEYCONFIG + _overall);
			if (_D_feature_key_alt == 1) then {
				_control ctrlSetText QPATHTO_T(data\alt_ca.paa);
			} else {
				_control ctrlSetText "";
			};
			_control ctrlCommit 0;
			
			INC(_overall);
		};
	};
} foreach [_grp_interact,_grp_item,_grp_weapon,_grp_vehicle,_grp_other,_grp_empty];

// Hide Key Settings Control Group
DISP(1002) ctrlShow false; 
DISP(1002) ctrlCommit 0;

// Hide Fix Headbug
DISP(6000) ctrlShow false; 
DISP(6000) ctrlCommit 0;

if (isNil "ace_settings_enable_vd_change") then {
	DISP(33001) ctrlShow false;	// Hide VD VALUE text
	DISP(33002) ctrlShow false; // Hide VD SLIDER
} else {
	DISP(33003) ctrlShow false; // Hide DISABLED text
	_control = DISP(33002);
	_vd = missionNamespace getVariable ["ace_viewdistance_limit",10000];
	_limitvd = (_vd min 10000) max 200;
	_control sliderSetRange [200,_limitvd];
	_vdr = round viewDistance;
	_control sliderSetPosition _vdr;
	_control ctrlCommit 0;
	DISP(33001) ctrlSetText str(_vdr);
};

if (isNil "ace_settings_enable_tg_change") then {
	DISP(33012) ctrlShow false; // Hide TG COMBO box
} else {
	DISP(33013) ctrlShow false; // Hide DISABLED text

	uiNamespace setVariable  ["ace_settings_first_tg_sel_change_done", false];
	_control = DISP(33012);
	lbClear _control;
	{
		_control lbAdd _x;
	} forEach [OPTION_FULL,OPTION_MEDIUM,OPTION_NONE1];
	_control lbSetCurSel 1;
};

DISP(8000) ctrlShow (!isMultiPlayer);
DISP(8000) ctrlCommit 0;

["options"] call (uiNamespace getVariable "ace_settings_fnc_showmenu");

uiNamespace setVariable ["ace_settings_KeyChangeDo", false];

_disp displaySetEventHandler ["KeyDown", "_this call (uiNamespace getVariable 'ace_settings_fnc_keychangerkeydown')"];
