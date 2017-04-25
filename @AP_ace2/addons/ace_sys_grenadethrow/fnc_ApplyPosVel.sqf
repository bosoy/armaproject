#include "script_component.hpp"

PARAMS_4(_pos,_vel,_bullet,_unit);

_bullet setVelocity _vel;
_bullet setPosASL _pos;

//diag_log format ["%1 applyposvel this %2 local nade %3 newpos %4",time,_this,local _bullet,getposASL _bullet];

sleep 0.1;
_bullet setVelocity _vel;