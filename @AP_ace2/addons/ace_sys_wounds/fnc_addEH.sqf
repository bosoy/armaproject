//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_aceweh", "_woundsEnabled"];

PARAMS_1(_u);

_woundsEnabled = !isNil "ace_sys_wounds_enabled";
_aceWEH = _u getVariable "ace_w_eh";
if (isNil "_aceweh") then {
	if (isNil "ace_w_no_handledamage") then {
		_add = if (!_woundsEnabled) then {
			(isPlayer _u) || (_u in switchableUnits)
		} else {
			true
		};
		if (_add) then {_u setVariable [QGVAR(hdeh), _u addEventHandler ["handleDamage", {if (local (_this select 0)) then {_this call FUNC(hd)}}]]};
	};
	if (isNil "ace_w_no_handleheal") then {
		if (!isNil "ace_sys_wounds_enabled") then {
			_u removeAllEventHandlers "handleHeal";
			_u addEventHandler ["handleHeal", {_this call FUNC(hh)}];
		};
	};
	if (isMultiplayer) then {
		if (isNil "ace_w_docoreconv") then {
			_u setVariable ["BIS_noCoreConversations", true];
		};
	};
};
_u setVariable ["ace_w_initialized", nil];

if (_woundsEnabled) then {
	// TODO: Is this fine that it's not delayed? - aka due to adding weapons/magazines during briefing = reset gear / unsaved gear changes??
	[_u] call FUNC(initIFAK);

	// _u getVariable ["SLX_XEH_PLAYABLE", false] &&  // Problem in SP Scenarios?..
	if (CBA_MISSION_START) then {
		TRACE_1("normal addMedicalGear",_u);
		_u call FUNC(addMedicalInt);
	} else {
		// Fix for playable units loosing the gear when going from Briefing screen, when there is overload.
		TRACE_1("delay addMedicalGear",_u);
		PUSH(GVAR(medical_gear_units),_u);
	};

	if ([_u] call FUNC(isMedic)) then {
		[_u] execFSM QPATHTO_C(AIAttendantHandling.fsm);
	};
};

_u setVariable ["ace_w_eh", 0];
