/* ace_sys_explosives (.pbo)| Pipebomb | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

private ["_A_ID","_mine"];
_ar = _this;
if (count _this > 1) then {
	_A_ID = _this select 2;
	_mine = _this select 3;
	player removeAction _A_ID;
} else {
	_mine = _this select 0; // Has no trigger!
};

if (isNull _mine) exitwith { false };

_type = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "explosion_type");
_type createVehicle [(position _mine) select 0,(position _mine) select 1, 0.2 + ([_mine] call CBA_fnc_realHeight)];
[_mine] call FUNC(removeMine);
