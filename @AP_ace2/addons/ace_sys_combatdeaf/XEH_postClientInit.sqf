#include "script_component.hpp"

GVAR(dv) = 0;
GVAR(deaf) = false;

player setVariable [QGVAR(dv), 0];
player setVariable [QGVAR(deaf), false];
player setVariable [QGVAR(prior), 0];
// Check for SP
if (player == player) then {
	execFSM "\x\ace\addons\sys_combatdeaf\sys_combatdeaf.fsm";
};
