#include "script_component.hpp"
private["_group", "_cs", "_idx", "_e", "_g", "_exec", "_callsigns", "_groups"];
PARAMS_2(_group,_cs);

if (isNil "ace_sys_menu_cs_GROUPS") then { ace_sys_menu_cs_GROUPS = [] };
if (isNil "ace_sys_menu_cs_CS") then { ace_sys_menu_cs_CS = [] };

_callsigns = [] + ace_sys_menu_cs_CS;
_groups = [] + ace_sys_menu_cs_GROUPS;

_exec = true;

for "_i" from 0 to (_c - 1) do {
	_entry = _callsigns select _i;
	if ((_entry select 0 == _cs select 0) && {(_entry select 1 == _cs select 1)}) then {
		if (!(isNull (_groups select _i))) then { _exec = false; _i = _c };
	};
};

if (!_exec) exitWith { hint "Can not set groupId, already in use" };

_idx = ace_sys_menu_cs_GROUPS find _group;
if (_idx>-1) then {
	ace_sys_menu_cs_CS set [_idx, _cs];
	publicVariable "ace_sys_menu_cs_CS";
} else {
	ace_sys_menu_cs_GROUPS = ace_sys_menu_cs_GROUPS + [_group];
	ace_sys_menu_cs_CS = ace_sys_menu_cs_CS + [_cs];
	publicVariable "ace_sys_menu_cs_GROUPS"; publicVariable "ace_sys_menu_cs_CS";
};

_group setGroupId [_cs call ace_sys_menu_fnc_getCs];
