/* ----------------------------------------------------------------------------
Function: ACE_fnc_enumWeapons

Description:
	Enumurates the available weapons and their types for specified side and type

Parameters:
	_faction - Faction [String]

Parameters:
	_range - Range ("SHORT", "MEDIUM", "LONG")  [String]


Returns:
	List of weapons [Array]

Examples:
	(begin example)
		_ar = [0, []] call ace_fnc_enumWeapons;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL

#include "script_component.hpp"
#define __armory _obj >> "Armory" >> "disabled"
private ["_filter", "_faction", "_type", "_range", "_i", "_obj", "_objList", "_totobj", "_rootclass", "_models", "_c", "_types", "_armory", "_armoryCheck"];

PARAMS_2(_faction,_type);
_range = [];
if (count _this > 2) then {
	_t = _this select 2;
	if (typeName _t == "ARRAY") then {
		_range = _this select 2;
		TRACE_1("",_range);
	};
};

_armoryCheck = !("noarmorycheck" in _this);

if ("filter" in _this) then {
	_filter = true;
	_models = [];
} else {
	_filter = false;
};

_rootClass = "CfgWeapons";
_totobj = count (configfile >> _rootClass);
_objList = [];
_types = [];
_c = 0;

TRACE_1("range",_range);

for "_i" from 0 to _totobj - 1 do {
	_obj = (configfile >> _rootClass) select _i;
	if (isClass _obj) then {
		if (getNumber(_obj >> "scope") == 2) then {
			private ["_model", "_cfg", "_displayName", "_cfgSides", "_cfgTypes", "_objName", "_Zoom", "_attachments", "_exit", "_objType"];

			_objName = configName _obj;
			if (isNumber(_obj >> QGVAR(TYPE))) then {
				_objType = getNumber(_obj >> QGVAR(TYPE));
			} else {
				_objType = getNumber(_obj >> "type");
			};
			if (_objType > 131072) exitWith { TRACE_2("High (VEH) Type",_objName,_objType) };

			_cfgTypes = [];
			_cfgSides = [];
			_model = "";
			_exit = false;
			_attachments = [];
			TRACE_1("",_objName);

			_armory = if (_armoryCheck && {isNumber(__armory)}) then { getNumber(__armory) } else { 0 };
			if (_armory == 1) exitWith { TRACE_1("Abort. Armory",_armory) };
			if (_armoryCheck && {getNumber(_obj >> "ace_hide") == 1}) exitWith { TRACE_1("Abort. ACE_Hide",_armory) }; // Should be deprecated, use Armory->disabled instead

			_cfg = (_obj >> QGVAR(side));
			if (isArray _cfg) then { _cfgSides = getArray _cfg };
			if (_faction != "") then {
				TRACE_2("",_faction,_cfgSides);
				if ("DEFAULT" in _cfgSides) exitWith {}; // DEFAULT means all
				if !(_faction in _cfgSides) exitWith { _exit = true };
			};
			if (_exit) exitWith {};

			switch _objType do {
				case 1: {
					_cfgTypes = ["RIFLE"];
					// How to figure SMG and MG? (ACE doesnt use type 5 for mg's)
					// Sniper we figure ouyt in the range...
				};
				case 2: {
					_cfgTypes = ["PISTOL"];
					// How to figure SMG and MG?
					// Sniper we figure ouyt in the range...
				};
				case 3: {
					_cfgTypes = ["SNIPER"];
				};
				case 4: {
					_cfgTypes = ["LAUNCHER"];
				};
				case 5: {
					_cfgTypes = ["MG"];
				};
				case 6: {
					_cfgTypes = ["AR"];
				};
				case 4094: {
					_cfgTypes = ["RUCK"];
				};
				case 4096: {
					_cfgTypes = ["EQUIP"];
				};
				case 131072: {
					_cfgTypes = ["ITEM"];
				};
			};

			if ((count _type) > 0 && {(count _cfgTypes) > 0}) then {
				_exit = true; {
					if (_x in _cfgTypes) exitWith { _exit = false };
				} forEach _type;
				TRACE_3("",_type,_cfgTypes,_exit);
			};
			if (_exit) exitWith {};

			_zoom = _objName call FUNC(determineZoom);
			TRACE_1("zoom",_zoom);
			if ((count _range) > 0 && {(count _zoom) > 0} && {_objType in [1, 3, 5, 6]}) then {
				_exit = true; {
					if (_x in _range) exitWith { _exit = false };
				} forEach _zoom;
				TRACE_3("",_zoom,_range,_exit);
			};
			if (_exit) exitWith {};

			_cfg = (configFile >> "CfgSettings" >> "ACE" >> "sys_attachments" >> "Weapons" >> _objName);
			if (isClass _cfg) then {
				if (isClass (_cfg >> "ACE_Attach")) then {
					#define __obj (_cfg >> "ACE_Attach" >> "ACE_ATTACH_AVAILABLE")
					if (isArray __obj) then {
						_attachments = getArray __obj;
					};

/*
					#define __obj (_cfg >> "ACE_Attach" >> "ACE_ATTACH_IRON")
					if (isText __obj) then {
						if ((getText __obj) != "THIS") then {
							_exit = true;
						};
					};
*/
					// Filter CQB weapons when lock enabled
					#define __obj (_cfg >> "ACE_CQB" >> "ACE_CQB_CQB")
					if (GVAR(lock) select 0) then {
						if (isText __obj) then {
							if ((getText __obj) == "THIS") then {
								_exit = true;
							};
						};
					};
				};
			};
			TRACE_1("Attachments",_exit);
			if (_exit) exitWith {};

			_model = getText (_obj >> "model");
			if (_filter) then {
				if (_model in _models) exitWith { _exit = true };
				PUSH(_models,_model);
				TRACE_3("",_filter,_model,_exit);
			};
			if (_exit) exitWith {};

			_displayName = getText (_obj >> "displayName");
			TRACE_3("",_displayName,_objName,_cfgTypes);
			if (_displayName == "") exitWith {};
 {
				private ["_idx", "_ar"];
				_idx = _types find _x;
				if (_idx == -1) then {
					_idx = _c;
					_types set [_idx, _x];
					_objList set [_idx, []];
					_c = _c + 1;
				};
				_ar = _objList select _idx;
				_bla = [_objName, _displayName, _zoom, _cfgTypes, _cfgSides, _model, _attachments];
				PUSH(_ar,_bla);
				_objList set [_idx, _ar];
			} forEach _cfgTypes;
		};
	};
};
[_objList, _types]
