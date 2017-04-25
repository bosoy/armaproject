#include "script_component.hpp"

PARAMS_5(_pos,_vel,_bullet,_geometry,_unit);

_bullet attachto [_geometry,[0,0,0]];

_geometry setPosASL _pos;
_geometry setVelocity _vel;
sleep 0.1;
_geometry setVelocity _vel;
//diag_log format ["%1 applyposvel this %2 local nade %3 newpos %4",time,_this,local _bullet,getposASL _bullet];

//_spd = _vel call ACE_fnc_magnitude;
//if (_spd > 0.5) then
//{
//	_geometry setVectorUp [(_vel select 0)/_spd,(_vel select 1)/_spd,(_vel select 2)/_spd];
//};

//destroy physics enforcer
while {alive _bullet} do { sleep 1 };
if !(isNull _geometry) then { deleteVehicle _geometry };