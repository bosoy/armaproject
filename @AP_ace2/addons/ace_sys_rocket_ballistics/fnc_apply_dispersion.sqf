//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_bullet,_vel,_dirAndUp);

_bullet = nearestObject _bullet;

if (isNull _bullet) exitwith {
	WARNING("Null Bullet");
};

_bullet setVelocity _vel;
_bullet setVectorDirAndUp _dirAndUp;
//_bullet setPos getPos _bullet;

TRACE_4("",_bullet,vectorDir _bullet,velocity _bullet,vectorUp _bullet);
