#include "script_component.hpp"
PARAMS_4(_unit,_blood,_pain,_epi);
if (_blood != 0) then { _unit setVariable ["ace_w_bleed_add",(_unit getVariable "ace_w_bleed_add") + _blood] };
if (_pain != 0) then { _unit setVariable ["ace_w_pain_add",(_unit getVariable "ace_w_pain_add") + _pain] };
if (_unit getVariable "ace_w_epi" != 1) then {_unit setVariable ["ace_w_epi",_epi]};
