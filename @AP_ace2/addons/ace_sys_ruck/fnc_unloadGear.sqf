//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_unit"];

GVAR(diag_to_close) = nil;

[] spawn ace_sys_magazines_fnc_checkongearclosed;

if ( ! isNil QGVAR(lastUnit) ) then {
	_unit = GVAR(lastUnit);
	if ( ! isNull _unit ) then {
		if (!isNil "ace_sys_wounds_enabled") then { [_unit] call FUNC(uiIFAKupdate); };
/*	//disabled below because of #24051 --Robalo
		//attempt to keep rangefinders at last index
		{
			if (_x in __rangefinders) then {
				_unit removeWeapon _x;
				_unit addWeapon _x;
			};
		} forEach (weapons _unit);
*/
	};
};

TRACE_1("",_unit);

[QGVAR(gear_unload), [_unit]] call CBA_fnc_localEvent;

ACE_gearopen = nil;
