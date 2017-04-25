#include "script_component.hpp"

// ClusterFuck
if (getNumber(configFile >> "CfgAmmo" >> _this select 4 >> QGVAR(BURST)) == 1) then {
	_this spawn FUNC(Cluster);
};
