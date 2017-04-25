#include "script_component.hpp"

if !(isNil QGVAR(player_loop_started)) exitWith {};

GVAR(player_loop_started) = true;

[] spawn FUNC(loop);
