//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_vec);

TRACE_2("",(typeOf _vec),player);

if (player in _vec) then {
	if (getNumber(configFile >> "CfgVehicles" >> typeOf _vec >> QGVAR(hasrwr)) == 1) then {
		_type = getText(configFile >> "CfgVehicles" >> typeOf _vec >> QGVAR(type));
		if (getNumber(CFGSETTINGS >> _type >> QGVAR(type)) == 1) then {
			_this spawn FUNC(rwr_us);
		} else {
			_this spawn FUNC(rwr_ru);
		};
	};
};
