#include "script_component.hpp"

private ["_part", "_secw"];
PARAMS_1(_u);
_secw = secondaryWeapon _u;
if (getNumber(configFile >> "CfgWeapons" >> _secw >> "ace_disposable_needpart") == 1) then {
	_part = getText(configFile >> "CfgWeapons" >> _secw >> "ace_disposable_neededpart");
	if (_part != "" && {!(_u hasWeapon _part)}) then {
		_u addWeapon _part
	};
};
