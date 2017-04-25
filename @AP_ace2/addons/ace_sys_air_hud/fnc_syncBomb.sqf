//fnc_syncBomb
#include "script_component.hpp"
_player = _this select 0;
if(_player != player) then {
	_proxy = _this select 1;
	_position = _this select 2;
	_velocity = _this select 3;
	_bomb = nearestObject [_position, _proxy];
	_bomb setPos _position;
	_bomb setVelocity _velocity;
	_bomb setVectorDir _velocity;
	// player sideChat format["HIIIIIIIIIIIIIIIIIIIIIII: %1", _this];
	[_bomb] spawn {
		_bomb = _this select 0;
		while {alive _bomb} do {
			// drop ["\Ca\Data\Cl_basic","","Billboard",1,20,(getPos _bomb),[0,0,0],1,1.275,1.0,0.0,[5],[[1,0,0,1]],[0],0.0,2.0,"","",""];
			// player sideChat format["p: %1", (getPosASL _bomb)];
			_bomb setVectorDir (velocity _bomb);
			sleep 0.01;
		};
	};
};