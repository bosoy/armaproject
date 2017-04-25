#include "script_component.hpp"
private ["_levelId", "_squadId", "_level", "_squad", "_designations", "_des"];
PARAMS_2(_levelId,_squadId);

_level = SIX_ARMY select _levelId;
_squad = _level select 0;
_designations = _level select 1;
_des = _designations select _squadId;
(_squad + " " + _des)
