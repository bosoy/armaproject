// Default medical-gear and ruck contents

#include "script_component.hpp"

private "_cont";
PARAMS_1(_unit);
DEFAULT_PARAM(1,_done,false);

if !(_unit call FUNC(medGearEnabled)) exitWith {};
if ([_unit] call FUNC(isMedic)) then {
	// Only add gear if not done already
	if (!_done && {local _unit}) then {
		TRACE_1("Adding Magazines",_unit);
		{ _unit addMagazine _x } forEach [KIT, KIT];
	};
	
	// TODO: Once Ruck gear is transfered properly over Network, this should also become sensitive to _done && local _unit (move localCheck?)
	if ([_unit] call ACE_fnc_HasRuck) then {
		TRACE_1("Adding RuckMagazines",_unit);
		{
			[_unit, _x, 10] call ACE_fnc_PackMagazine;
		} forEach [BND, LRGBND, MOR, EPI];
		[_unit, CAT, 4] call ACE_fnc_PackMagazine;
		[_unit, KIT, 4] call ACE_fnc_PackMagazine;
	};
};

_unit call ace_sys_ruck_fnc_uiIFAKupdate; //IFAK counts to magazines on spawn
