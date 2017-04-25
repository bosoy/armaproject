#include "script_component.hpp"
private ["_handle"];
PARAMS_5(_pos,_vel,_bullet,_geometry,_unit);
_handle = [
			{ /* loop */
				// the geometry might get stuck on the player if setVelocity is used only once
				// so set the velocity till the distance is about 2 m
				if (_geometry distance _unit < 2) then {
					_geometry setVelocity _vel;
					_t = time;
				};
			},
			[_pos,_vel,_bullet,_geometry,_unit], /* parameters */
			0, // delay
			{
				//init
				_pos = _this select 0;
				_vel = _this select 1;
				_bullet = _this select 2;
				_geometry = _this select 3;
				_unit = _this select 4;
				_geometry setPosASL _pos;
				_bullet attachto [_geometry,[0,0,0]];
				_geometry setPosASL _pos;
				_geometry setVelocity _vel;
				_t = time;
			},
			{ /* exit code */
				_geometry setVelocity _vel;
				0 = [_geometry,_bullet] spawn {
					while {alive (_this select 1)} do { sleep 1 };
					if !(isNull _geometry) then { deleteVehicle (_this select 0)};
				};
			},
			{ /* Run condition - default true */
			},
			{time - _t  > 0.1 || {!alive _unit}}, /* exit condition */
			[ /* Private variables, available throughout all states and conditions */
				"_bullet","_unit","_ammo","_pos","_vel","_geometry","_t"
			]
		] call cba_common_fnc_addPerFrameHandlerLogic;
_handle