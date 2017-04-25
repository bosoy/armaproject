//repairs tracks or wheels depending on vehicle class

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit

PARAMS_1(_unit);

switch (true) do {
	case (_unit isKindOf "Tank"): {
		{
			[_unit,_x,0] call FUNC(sethit);
		} foreach ["ltrack","rtrack"];
	};
	case (_unit isKindOf "Wheeled_APC"): {
		{
			[_unit,_x,0] call FUNC(sethit);
		} foreach ["lfwheel","lf2wheel","lmwheel","lbwheel","rfwheel","rf2wheel","rmwheel","rbwheel"];
	};
	default {};
};