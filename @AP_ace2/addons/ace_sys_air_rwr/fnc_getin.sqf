#include "script_component.hpp"

PARAMS_1(_vec);

if (getNumber(configFile >> "CfgVehicles" >> typeOf _vec >> QGVAR(hasrwr)) == 0) exitWith {};
_type = getText(configFile >> "CfgVehicles" >> typeOf _vec >> QGVAR(type));
if (getNumber(CFGSETTINGS >> _type >> QGVAR(type)) == 1) then {
	_this spawn FUNC(rwr_us);
} else {
	_this spawn FUNC(rwr_ru);
};
