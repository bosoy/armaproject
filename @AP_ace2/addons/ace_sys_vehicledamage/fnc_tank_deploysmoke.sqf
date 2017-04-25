#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _this

//_c = commander _this;
//_c action ["useWeapon",_this,_c,5]

PARAMS_2(_unit,_injurer);

// if (alive (gunner _unit)) then
// {
	//(gunner _unit) dowatch _injurer;
// };
if (!isPlayer (commander _unit) && {count(crew _unit) > 0}) then {
	sleep (random 3);
	_unit selectweapon "SmokeLauncher";
	_unit fire ["SmokeLauncher","SmokeLauncher","SmokeLauncherMag"];
};

