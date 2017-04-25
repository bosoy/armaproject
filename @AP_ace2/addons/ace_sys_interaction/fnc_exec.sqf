/* ace_sys_interaction (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_4(_unit,_caller,_id,_params);

_action = _params select 0;
_target = _params select 1;

if (!isNull _target && {!alive _target}) exitWith { TRACE_1("Exiting fnc_exec due to dead unit or objNull",""); };


switch (_action) do {
	case "freeze": {
		TRACE_1("FREEZE","");
		_unit groupChat localize "STR_ACE_CI_VCFREEZE"; // TODO: Localize
		_unit playActionNow "gestureFreeze";

		[QGVAR(ci_freeze), _target] call ACE_fnc_receiverOnlyEvent;
	};
	case "down": {
		_unit groupChat localize "STR_ACE_CI_VCGETDOWN"; // TODO: Localize
		_unit playActionNow "GestureAdvance";		

		if (isNull _target) then {
			private ["_targets","_entities"];
			_entities = (position _caller) nearEntities ["CaManBase",15];
			_targets = _entities - [_caller];
			TRACE_1("DOWN ALL",_targets);
			{ [QGVAR(ci_down), _x] call ACE_fnc_receiverOnlyEvent; TRACE_1("DOWN ALL X",_x); } foreach _targets;
		} else {
			TRACE_1("DOWN",_target);
			[QGVAR(ci_down), _target] call ACE_fnc_receiverOnlyEvent;
		};
	};
	case "away": {
		private "_targets";
		TRACE_1("AWAY","");
		_unit groupChat localize "STR_ACE_CI_VCCLEARAREA"; // TODO: Localize
		_unit playActionNow "gestureFreeze";		

		if (isNull _target) then {
			_entities = (position _caller) nearEntities ["CaManBase",15];
			_targets = _entities - [_caller];
			{ [QGVAR(ci_away), _x] call ACE_fnc_receiverOnlyEvent } foreach _targets;
		} else {		
			[QGVAR(ci_away), _target] call ACE_fnc_receiverOnlyEvent;
		};
	};
	case "inside": {
		private "_targets";	
		TRACE_1("INSIDE","");
		_unit groupChat localize "STR_ACE_CI_VCGETINSIDE"; // TODO: Localize
		_unit playActionNow "GesturePoint";		

		if (isNull _target) then {
			_entities = (position _caller) nearEntities ["CaManBase",15];
			_targets = _entities - [_caller];
			{ [QGVAR(ci_inside), _x] call ACE_fnc_receiverOnlyEvent } foreach _targets;
		} else {
			[QGVAR(ci_inside), _target] call ACE_fnc_receiverOnlyEvent;
		};
	};
	case "getout": {
		_unit groupChat localize "STR_ACE_CI_VCGETOUTCAR"; // TODO: Localize
		_unit playActionNow "GesturePoint";		

		[QGVAR(ci_getout), _target] call ACE_fnc_receiverOnlyEvent;		
	};
	case "stop": {
		_unit groupChat localize "STR_ACE_CI_VCSTOPCAR"; // TODO: Localize
		_unit playActionNow "gestureFreeze";

		[QGVAR(ci_stop), _target] call ACE_fnc_receiverOnlyEvent;		
	};
};
