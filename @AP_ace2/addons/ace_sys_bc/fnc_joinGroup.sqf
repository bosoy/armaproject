#include "script_component.hpp"

PARAMS_2(_unit,_group);

// TODO: Evaluate if local _unit works and is useful

_unit enableAI "MOVE";
_unit setCaptive false;
[_unit] join _group;
