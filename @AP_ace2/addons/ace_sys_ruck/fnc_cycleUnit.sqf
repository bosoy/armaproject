// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

PARAMS_2(_data,_advance);
private ["_control", "_display", "_IDC", "_unit", "_group", "_units", "_size", "_index", "_index_o", "_able", "_leader", "_index_p", "_fnc_next", "_advance", "_unit_n"];
_control = _data select 0;
_display = ctrlParent _control;
_IDC = ([(str _display), "#"] call CBA_fnc_split) select 1;
_unit = _display call FUNC(uiGetCallingUnit);
_group = group _unit;
_units = units _group;
_size = count _units;
_index = _units find _unit;
_index_o = _index;

_able = true;
_leader = leader _group;

//if ( _group != (group player) ) then { _able = false }; //should never be outside own group AFAIK
if ( isPlayer _leader && {player != _leader} ) then { //must be leader
	_able = false;
} else {
	_index_p = _units find player;
	if(_index_p != 0) then {
		for "_x" from 0 to (_index_p - 1) do { //or highest ranking
			if ( isPlayer(_units select _x) ) then { _able = false; };
		};
	};
};

if (_able) then {
	_fnc_next = {
		if ( _advance ) then {
			INC(_index);
			if ( _index >= _size ) then { _index = 0; };
		} else {
			DEC(_index);
			if ( _index < 0 ) then { _index = _size - 1; };
		};
	};

	call _fnc_next;
	while { _unit_n = _units select _index; TRACE_1("while",_unit_n); _index != _index_o && {( ! local _unit_n || {( isPlayer _unit_n && {_unit_n != player} )} || {_unit_n != vehicle _unit_n} || {!alive _unit_n}  )} } do { call _fnc_next };
	if ( _index != _index_o ) then {
		call compile format["closeDialog %1",_IDC];
		(_units select _index) action ["GEAR",""];
	};
};

//click handled
true
