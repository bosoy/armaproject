#include "script_component.hpp"
private ["_effect2pos", "_expl"];
sleep (random 8);
_effect2pos = _this selectionposition "destructionEffect2";
_expl = "ace_fuelexpbig" createvehicle (_this modelToWorld _effect2pos);
