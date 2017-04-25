//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_unit", "_lines", "_wgt", "_wgt_line", "_ruck_line", "_vol", "_vol_line", "_scope", "_scope_line", "_use_line", "_text"];
_unit = player;

if (!alive _unit) exitWith {false};
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith {false};

_lines = [];

// Weight
_wgt = _unit call FUNC(GearWeight);
if (! isNil "_wgt") then {
	if (_wgt >= 0) then {
		_wgt_line = parseText format[
				"<t align='left' size='1.1'><t color='#99ffffff'>%1</t> %2 %3</t>",
				localize "STR_ACE_SYS_RUCK_WEIGHT",
				[_wgt, 1, 0, true] call CBA_fnc_formatNumber,
				localize "STR_ACE_SYS_RUCK_KILOGRAM"
			];
		PUSH(_lines,_wgt_line);
		PUSH(_lines,lineBreak);
	};
};

_ruck_line = parseText format["<t align='left' size='1.2' color='#99ffffff'>%1:</t>", localize "STR_DN_ACE_RUCKSACK"];
PUSH(_lines,_ruck_line);
PUSH(_lines,lineBreak);

_vol = _unit call FUNC(RuckInventorySize);
if (! isNil "_vol") then {
	if (_vol < 0) then {
		if (_vol < -1) then {
			_vol_line = localize "STR_ACE_SYS_RUCK_TOOFULL";
			GVAR(oversize) = abs(_vol) / 100; //weight penalty
		} else {
			_vol_line = localize "STR_ACE_SYS_RUCK_NORUCK";
			GVAR(oversize) = 0;
		};
	} else {
		_vol_line = format[
				"%1 %2 %3",
				[_vol, 1, 0, true] call CBA_fnc_formatNumber,
				localize "STR_ACE_SYS_RUCK_CUBICCENTIMETERS",
				localize "STR_ACE_SYS_RUCK_FREESPACE"
			];
	};
	_vol_line = parseText format["<t align='left' size='1.1'>  %1</t>", _vol_line];
	PUSH(_lines,_vol_line);
	PUSH(_lines,lineBreak);
};

_scope = _unit getVariable ["ACE_Ruck_Lock_Scope","Team"];
_scope_line = if (_scope == "") then {
	localize "STR_DN_ACE_RUCK_LOCKED"
} else {
	format["%1 %2", localize ("STR_DN_ACE_RUCK_" + toUpper(_scope)), localize "STR_DN_ACE_RUCK_UNLOCK"]
};
_scope_line = parseText format["<t align='left' size='1.1'>  %1</t>", _scope_line];
PUSH(_lines,_scope_line);
PUSH(_lines,lineBreak);

if (_unit call FUNC(RuckBusy)) then {
	_use_line = format["%1 %2",
            localize "STR_DN_ACE_RUCK_IN_USE",
            _unit getVariable "ACE_Ruck_Lock"
            ];
	_use_line = parseText format["<t align='left' size='1.1'>  %1</t>", _use_line];
	PUSH(_lines,_use_line);
	PUSH(_lines,lineBreak);
};


_text = composeText _lines;
hintSilent _text;

true
