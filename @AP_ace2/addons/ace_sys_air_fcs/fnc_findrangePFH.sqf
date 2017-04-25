//lase for range, update display and set elevation/lead

#include "script_component.hpp"

#define __cooldowntime 0.25
#define __tracker getText (configFile >> "CfgVehicles" >> typeOf _veh >> "Turrets" >> "MainTurret" >> "ace_sys_missileguidance_tracker");

if (cameraView != "GUNNER") exitwith {};

_handle = [
			{ /* loop */
				_alive = true;
				_newpos = getPosASL _pulse;
				_range = _pulse distance _veh;
				//diag_log [_newpos,velocity _pulse];
				if (((velocity _pulse) call ACE_fnc_magnitude) < 100) then {deletevehicle _pulse}; //can linger for several frames at near zero speed before disappearing
			},
			[], /* parameters */
			0, // delay
			{
				//init
				_veh = vehicle player;
				_wpn = (weapons _veh) select 0;
				_rd = false;

				_offset = [0,0,5];
				_newPos = [0,0,0];
				_spd = 600000;
				_pulsePos = positionCameraToWorld _offset;
				_pulse = "ACE_Missileguidance_LaserPulse" createVehicleLocal _pulsePos;
			//	_pulse setPos _pulsePos;
			//	_p = getposASL _pulse;
			//	_p1 = positionCameraToWorld [_offset select 0,_offset select 1,1 + (_offset select 2)];
			//	_pulse setPos _p1;
			//	_p1 = getposASL _pulse;
			//	_laservec = [(_p1 select 0)-(_p select 0),(_p1 select 1)-(_p select 1),(_p1 select 2)-(_p select 2)];
				_laservec = _veh weaponDirection __tracker;	// using this one unless we need to support multiple turrets on helicopter
				_pulse setPos _pulsePos;
				_pulse setVelocity [(_laserVec select 0) * _spd, (_laserVec select 1) * _spd, (_laserVec select 2) * _spd];
				_range = 0;
				_alive = false;
				_newpos = nil;
			},
			{ /* exit code */
				if (isNil "_newpos") exitWith { hint "Error processing distance"};
				
				// Trigger incoming laser detection on targeted vehicle
				_tarVeh = objNull;
				{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x } } forEach (_newpos nearEntities [["LandVehicle", "Air", "Ship"],12]);
				if !(isNull _tarVeh) then {
					["ace_lasertarget", [_veh, _tarVeh, objNull]] spawn CBA_fnc_globalEvent;
				};
				
				// elevation of target
				_l1 = _laservec select 0;
				_l2 = _laservec select 1;
				_l3 = _laservec select 2;
				_p =  _l3 atan2 sqrt(_l1^2+_l2^2);

				_range = _range*cos abs(_p);
				
				_range = _range + random (10) - random (10);
				_range = if (_range < 250) then {0} else {_range min 9999};

				[_veh,_range,magazines _veh,weapons _veh,true] call FUNC(setsolution);
				_veh setVariable ["AH_DISTANCE_TO_TARGET", _range, true];
				_veh setVariable ["RU_DISTANCE_TO_TARGET", _range, true];
			},
			{ /* Run condition - default true */
				!(isNull _pulse)
			},
			{ _alive && {isNull _pulse} }, /* exit condition */
			[ /* Private variables, available throughout all states and conditions */
				"_alive","_offset","_ammo","_magz","_rd","_maxrng","_minrng","_lrf","_range","_veh","_wpn",
				"_tarveh","_l1","_l2","_l3","_offset","_newpos","_spd","_laserVec","_pulsePos","_pulse","_range","_target","_projectile","_p","_p1"
			]
		] call cba_common_fnc_addPerFrameHandlerLogic;

_handle