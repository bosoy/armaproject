// magic repair

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit

PARAMS_1(_unit);

switch (true) do {
	case (! alive _unit): {};
	case (_unit getvariable "ace_onfire"): {};
	case (_unit isKindOf "Tank"): {
		{
			[_unit,_x,0] call FUNC(sethit);
		} foreach ["ltrack","rtrack","engine","hull","turret","gun"];
		[_unit, "ace_canmove", true] call ace_sys_vehicleDamage_fnc_setVar;
		[_unit, "ace_canshoot", true] call ace_sys_vehicleDamage_fnc_setVar;
		[_unit, "ace_tankfcs_down", nil] call ace_sys_vehicleDamage_fnc_setVar;
		_unit setdamage 0;
		[QGVAR(handle_remove_eh), _unit] call CBA_fnc_globalEvent;
	};
	case (_unit isKindOf "Wheeled_APC"): {
		{
			[_unit,_x,0] call FUNC(sethit);
		} foreach ["lfwheel","lf2wheel","lmwheel","lbwheel","rfwheel","rf2wheel","rmwheel","rbwheel","engine","hull","turret","gun","fuel"];
		[_unit, "ace_canmove", true] call ace_sys_vehicleDamage_fnc_setVar;
		[_unit, "ace_canshoot", true] call ace_sys_vehicleDamage_fnc_setVar;
		[_unit, "ace_tankfcs_down", nil] call ace_sys_vehicleDamage_fnc_setVar;
		_unit setdamage 0;
		[QGVAR(handle_remove_eh), _unit] call CBA_fnc_globalEvent;
	};
	default {};
};
