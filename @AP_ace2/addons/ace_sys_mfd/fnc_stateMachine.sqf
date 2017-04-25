#include "script_component.hpp"

// how this works
// we get passed 2 vars. CurrentState, StateTable
// This file will just walk that state table, and call the appropriate string. 
// if state is nil or [], it will call the first state in the table
// each state needs to have ["Name", "functionNameToCall", [children]]
// state is kept as an array down the tree, so if it was Rxmt->Program, it would be ["Rxmt", "Program"]
// It calls the provided function name passing the state, and expecting state back
// then we pass that return state back to our caller


////// begin real function code
FUNC(walkStateTable) = {
	_state = _this select 0;
	_currentTable = _this select 1;
	_depth = _this select 2;
	
	if (_depth == (count _state) - 1) then {
		{
			_row = _x;
			if ((_state select _depth) == (_row select 0)) exitWith {
				_stateFunction = _row select 1;
			};
		} forEach _currentTable;
	} else {
		{
			_row = _x;
			if ((_state select _depth) == (_row select 0)) exitWith {
				_stateFunction = [_state, (_row select 2), _depth + 1] call FUNC(walkStateTable);
			};
		} forEach _currentTable;
	};
	_stateFunction
};

// Keep running into they stop changing the state
_stateTable = _this select 1;
_currentState = _this select 0;
_stateFunction = nil;

// Keep running into they stop changing the state
_exitFromLoop = false;
while {!_exitFromLoop} do {
	_exitFromLoop = false;
	_lastState =+ _currentState;
	if (!isNil "_stateTable") then {
		if (count _stateTable > 0) then {
			if (!isNil "_currentState") then {
				// here we start our table walk
				_stateFunction = [_currentState, _stateTable, 0] call FUNC(walkStateTable);
			} else {
				// nil state, just call the first one
				_stateFunction = (_stateTable select 0) select 1;
				_currentState = [(_stateTable select 0) select 0];
				_lastState = _currentState;
			};
		};
	};
	
	if (!isNil "_stateFunction") then {
		_currentState = [_currentState] call _stateFunction;
	};
	if (isNil "_currentState") exitWith  {
		_currentState = _this select 0;
	};

	if (count _lastState == count _currentState) then {
		_exitFromLoop = true;
	};
	if (_exitFromLoop) then {
		{
			_state = _x;
			_lastStateEntry = (_lastState select _forEachIndex);
			if (_state != _lastStateEntry) exitWith {
				_exitFromLoop = false;
			};
		} forEach _currentState;
	};
};
_currentState
