// #define DEBUG_MODE_FULL
#include "script_component.hpp"

if (_this isKindOf "CAManBase") then {
	getDir _this; // or weaponDirection ? currentWeapon is said to only work on "the player" ?
} else {
	_weapons = getArray(configFile >> "CfgVehicles" >> typeOf _this >> "Turrets" >> "MainTurret" >> "weapons");
	_array = _this weaponDirection (_weapons select 0);
	(_array select 0) atan2 (_array select 1);
};
