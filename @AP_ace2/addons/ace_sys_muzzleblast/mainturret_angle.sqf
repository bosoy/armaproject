#include "script_component.hpp"
private["_unit", "_angle", "_body", "_mainturret"];
PARAMS_1(_unit);
_angle = 0;
_body = getDir _unit;
_mainturret = deg(_unit animationPhase "mainturret");
if (_mainturret<= 0) then { (-_mainturret)mod 360 };
if (_mainturret>0) then { (360 - _mainturret)mod 360 };
_angle = _body+_mainturret;
if (typeName _angle == "ARRAY") then { _angle = (round(((_angle select 0)atan2(_angle select 1))+360))mod 360; }
else { _angle = round _angle; };
if (_angle<0) then { _angle = 360-((-angle)mod 360); }
else { _angle = _angle mod 360; };
_angle
