//#define DEBUG_MODE_FULL
#include "script_component.hpp"

uiNamespace setVariable [QUOTE(FUNC(fillsettingsDialog)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_fillSettingsDialog.sqf"];
uiNamespace setVariable [QUOTE(FUNC(showmenu)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_showmenu.sqf"];
uiNamespace setVariable [QUOTE(FUNC(keychangerkeydown)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_keychangerkeydown.sqf"];
uiNamespace setVariable [QUOTE(FUNC(linkbuttonclicked)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_linkbuttonclicked.sqf"];
uiNamespace setVariable [QUOTE(FUNC(OneKeyChangerButtons)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_OneKeyChangerButtons.sqf"];
uiNamespace setVariable [QUOTE(FUNC(saveall)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_saveall.sqf"];
uiNamespace setVariable [QUOTE(FUNC(vdsliderchanged)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_vdsliderchanged.sqf"];
uiNamespace setVariable [QUOTE(FUNC(tgselchanged)), compile preprocessFileLineNumbers "\x\ace\addons\settings\fnc_tgselchanged.sqf"];

uiNamespace setVariable [QUOTE(FUNC(join)), {
	private ["_separator"];
	PARAMS_1(_array);
	_separator = if (count _this < 2) then {""} else {_this select 1};
	private ["_joined", "_element"];

	if (count _array > 0) then {
		_element = _array select 0;
		_joined = if (IS_STRING(_element)) then { _element } else { str _element };

		for "_i" from 1 to ((count _array) - 1) do {
			_element = _array select _i;
			_element = if (IS_STRING(_element)) then { _element } else { str _element };
			_joined = _joined + _separator + _element;
		};
	} else {
		_joined = "";
	};

	_joined; // Return.
}];

uiNamespace setVariable [QUOTE(FUNC(split2)), {
	private ["_string", "_separator", "_strar", "_separ", "_countstr", "_countsepstr", "_split", "_curidx", "_curstr", "_char", "_sepidx", "_sephelper", "_newidx", "_i", "_cchar", "_schar"];
	PARAMS_2(_string,_separator);
	_strar = toArray _string;
	_separ = toArray _separator;
	_countstr = count _strar;
	_countsepstr = count _separ;
	if (_countsepstr > _countstr) exitWith {[]};
	_split = [];
	if (_separator == "") then {
		{
			_split set [count _split, toString[_x]];
		} forEach _strar;
	} else {
		_curidx = 0;
		_curstr = [];
		while {_curidx < _countstr} do {
			_char = _strar select _curidx;
			if (_char != _separ select 0) then {
				PUSH(_curstr,_char);
			} else {
				_sepidx = 0;
				_sephelper = [];
				_newidx = 0;
				for "_i" from _curidx to _curidx + _countsepstr do {
					if (_sepidx >= _countsepstr) exitWith {};
					if (_i >= _countstr) exitWith {};
					_cchar = _strar select _i;
					_schar = _separ select _sepidx;
					if (_cchar != _schar) exitWith {};
					PUSH(_sephelper,_cchar);
					INC(_sepidx);
					_newidx = _i;
				};
				if (count _sephelper == _countsepstr) then { // match
					_curidx = _newidx;
					PUSH(_split,toString _curstr);
					_curstr = [];
				} else {
					PUSH(_curstr,_char);
				};
			};
			INC(_curidx);
		};
		if (count _curstr > 0) then {
			PUSH(_split,toString _curstr);
		} else {
			PUSH(_split,"");
		};
	};
	_split
}];

uiNamespace setVariable [QUOTE(FUNC(replace)), {
	PARAMS_3(_string,_pattern,_replacement);
	// Return.
	[[_string, _pattern] call (uiNamespace getVariable QUOTE(FUNC(split2))), _replacement] call (uiNamespace getVariable QUOTE(FUNC(join)));
}];

uiNamespace setVariable [QUOTE(FUNC(capitalize)), {
	PARAMS_1(_string);

	// Make the whole string into a lower case character array.
	_string = toArray (toLower _string);

	// If there is a first letter, capitalise it.
	if (count _string > 0) then {
		_string set [0, (toArray (toUpper (toString [_string select 0]))) select 0];
	};

	toString _string; // Return.
}];

uiNamespace setVariable [QUOTE(FUNC(readSetting)), {
	private "_currentValue";
	PARAMS_2(_setting,_defaultValue);
	_setting = toLower _setting;

	// Return current value, or return default if non existent.
	_currentValue = uiNamespace getVariable _setting; // TODO: Replace with uiNamespace getVariable [_setting, _defaultValue];  at new patch.
	//TRACE_2("readSetting",_setting,_currentValue);
	_currentValue = if (isNil "_currentValue") then { _defaultValue } else { _currentValue };

	// Call a local event
	// TODO: Do we really need an event when reading? Sounds a bit expensive
	// [format['QGVAR(read)_%1', _setting], [_setting, _currentValue]] call CBA_fnc_localEvent;

	if (isNil "_currentValue") then { nil } else { _currentValue };
}];

uiNamespace setVariable [QUOTE(FUNC(saveSetting)), {
	private ["_ar", "_original_value"];
	PARAMS_2(_setting,_value);
	_setting = toLower _setting;

	// Save current setting-key in store array for reference
	_ar = uiNamespace getVariable QGVAR(settings);
	if !(_setting in _ar) then { PUSH(_ar,_setting) } else { _original_value = uiNamespace getVariable _setting };

	// Save (new)Value
	uiNamespace setVariable [_setting, _value];

	// Call a local event
	if (!isNil "CBA_fnc_localEvent") then {
		[format['QGVAR(save)_%1', _setting], [_setting, _value, if (isNil "_original_value") then { nil } else { _original_value }]] call CBA_fnc_localEvent;
	};
}];

// TODO: Don't keep reading the default values from config....
uiNamespace setVariable [QUOTE(FUNC(getValue)), {
	private "_cfg";
	_cfg = configFile >> "CfgSettings";
	{ _cfg = (_cfg >> _x) } forEach _this;
	[[_this, "_"] call (uiNamespace getVariable QUOTE(FUNC(join))), _cfg];
}];

uiNamespace setVariable [QUOTE(FUNC(getText)), {
	private "_data";
	_data = _this call (uiNamespace getVariable QUOTE(FUNC(getValue)));
	_value = [_data select 0, getText(_data select 1)] call (uiNamespace getVariable QUOTE(FUNC(readSetting)));
	if (typeName _value != "STRING") then { ERROR("Didn't return a String!") };
	_value;
}];

uiNamespace setVariable [QUOTE(FUNC(getNumber)), {
	private "_data";
	_data = _this call (uiNamespace getVariable QUOTE(FUNC(getValue)));
	_value = [_data select 0, getNumber(_data select 1)] call (uiNamespace getVariable QUOTE(FUNC(readSetting)));
	if (typeName _value != "SCALAR") then { ERROR("Didn't return a Scalar!") };
	_value;
}];

// Serialization
#define SPLIT_VALUES ","
#define SPLIT_SETS ";"
#define TAG QUOTE(ace_settings_store)
uiNamespace setVariable [QUOTE(FUNC(serialize)), {
	private "_ar";
	_ar = uiNamespace getVariable QGVAR(settings);
	_ar2 = [];
	{
		_ar2 set [count _ar2, [[_x, str(uiNamespace getVariable _x)], SPLIT_VALUES] call (uiNamespace getVariable QUOTE(FUNC(join)))];
	} forEach _ar;
	_string = [_ar2, SPLIT_SETS] call (uiNamespace getVariable QUOTE(FUNC(join)));
	(TAG + SPLIT_SETS + _string + SPLIT_SETS);
	// TODO: Write string
}];


// Read all settings from a persistent store
uiNamespace setVariable [QUOTE(FUNC(deserialize)), {
	PARAMS_1(_string);
	private ["_ar", "_sets", "_newAr", "_data", "_setting"];
	_sets = [];

	_settings = [_string] call (uiNamespace getVariable QUOTE(FUNC(splitfast)));
	if (count _settings == 0) exitWith { diag_log "nosets";};
	if ((_settings select 0) select 0 != TAG) exitWith { diag_log "no tag";};

	{
		_data = _x;
		if (count _data > 1) then {
			// Data type conversion
			_d = _data select 1;
			_ar = toArray _d;
			_numbers = true;
			{
				if !((toString [_x]) in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "."]) exitWith { _numbers = false};
			} forEach _ar;

			// If numbers, do conversion by call compiule
			if (_numbers) then { _data set [1, call compile _d] } else {
				// If string, do conversion by removing leading and trailing "
				_newAr = [];
				for "_i" from 1 to (count _ar - 2) do {
					PUSH(_newAr,_ar select _i);
				};
				_data set [1, toString(_newAr)];
			};

			uiNamespace setVariable _data;

			// Save current setting-key in store array for reference
			_setting = _data select 0;
			_ar = uiNamespace getVariable QGVAR(settings);
			if !(_setting in _ar) then { PUSH(_ar,_setting) };
		};
		//TRACE_1("DATA",_data);
	} forEach _settings;
}];

uiNamespace setVariable [QUOTE(FUNC(splitfast)), {
	PARAMS_1(_string);
	private ["_stringArray", "_retar", "_curstr", "_curar", "_aridx"];
	_stringArray = toArray _string;
	_retar = [];
	_curar = [];
	_aridx = 0;
	_curstr = "";
	{
		switch (_x) do {
			case 44: { // ,
				_curar set [_aridx, _curstr];
				INC(_aridx);
				_curstr = "";
			};
			case 59: { // ;
				_curar set [_aridx, _curstr];
				_curstr = "";
				_aridx = 0;
				_retar set [count _retar, _curar];
				_curar = [];
			};
			default {
				_curstr = _curstr + toString [_x];
			};
		};
	} forEach _stringArray;
	_retar
}];

// Clipboard
uiNamespace setVariable [QUOTE(FUNC(dumpToClipboard)), {
	private "_data";
	_data = call (uiNamespace getVariable QUOTE(FUNC(serialize)));
	//TRACE_1("DUMPING",_data);
	copyToClipboard _data;
}];

uiNamespace setVariable [QUOTE(FUNC(importFromClipboard)), {
	private "_data";
	_data = copyFromClipboard;
	//TRACE_1("IMPORTING",_data);
	[_data] call (uiNamespace getVariable QUOTE(FUNC(deserialize)));
	// TODO: Run 'update keys', like is done in the menu 'save' action?
}];

if (productVersion select 3 >= 97105 || {isClass (configFile >> "CfgPatches" >> "HSim_UI_H")}) then {
	uiNamespace setVariable [QGVAR(profilenamespace_available), true];
} else {
	// be compatible for older OA versions
	profileNamespace = missionNamespace;
};

// Profilenamespace
uiNamespace setVariable [QUOTE(FUNC(writeToProfileNamespace)), {
	{
		profileNamespace setVariable [_x, uiNamespace getVariable _x];
	} forEach (uiNamespace getVariable QGVAR(settings));
	profileNamespace setVariable [QGVAR(settings), uiNamespace getVariable QGVAR(settings)];
	saveProfileNamespace;
}];

uiNamespace setVariable [QGVAR(settings), []];
if (isNil {uiNamespace getVariable QGVAR(profilenamespace_available)}) then {
	// Load user settings
	private ["_data"];
	_data = loadFile "\userconfig\ACE\settings.ace";
	if !(isNil "_data") then {
		if (_data == "") exitWith {};
		//TRACE_1("LOADING",_data);
		[_data] call (uiNamespace getVariable QUOTE(FUNC(deserialize)));
		//TRACE_1("ACE Settings Database Loaded", nil);
	};
} else {
	private "_setar";
	_setar = profileNamespace getVariable QGVAR(settings);
	if (!isNil "_setar") then {
		uiNamespace setVariable [QGVAR(settings), _setar];
		{
			uiNamespace setVariable [_x, profileNamespace getVariable _x];
		} forEach (uiNamespace getVariable QGVAR(settings));
	};
};