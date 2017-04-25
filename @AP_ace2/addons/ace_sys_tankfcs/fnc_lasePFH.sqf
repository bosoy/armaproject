//lase for range, update display and set elevation/lead

#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __magcfg configFile >> "cfgMagazines" >> _mag
#define __maxrng getNumber(__vehcfg >> "ace_tankfcs_maxlrfrange")
#define __minrng getNumber(__vehcfg >> "ace_tankfcs_minlrfrange")
#define __maxranges getArray(__vehcfg >> "ace_tankfcs_maxranges")
#define __acc getNumber(__vehcfg >> "ace_tankfcs_lrfaccuracy")
#define __cooltime getNumber(__vehcfg >> "ace_tankfcs_lrfcooldowntime")

if (cameraView != "GUNNER") exitwith {};

_veh = vehicle player;
if (time - (_veh getvariable ["ace_tankfcs_lastlasetime", 0]) < __cooltime) exitwith {};

_handle = [
			{ /* loop */
					_alive = true;
				_newpos = getPos _pulse;
				_newposASL = getPosASL _pulse;
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
				_pulse setPos _pulsePos;
				_p = getposASL _pulse;
				_p1 = positionCameraToWorld [_offset select 0,_offset select 1,1 + (_offset select 2)];
				_pulse setPos _p1;
				_p1 = getposASL _pulse;
				_laservec = [(_p1 select 0)-(_p select 0),(_p1 select 1)-(_p select 1),(_p1 select 2)-(_p select 2)];
				_pulse setPos _pulsePos;
				_pulse setVelocity [(_laserVec select 0) * _spd, (_laserVec select 1) * _spd, (_laserVec select 2) * _spd];
				_range = 0;
				_alive = false;
				_newpos = nil;
				_newposASL = nil;
			},
			{ /* exit code */
				if (isNil "_newpos") exitWith { hint "error processing distance"};
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
				_veh setvariable ["ace_fcs_lrfdata",[_range,_newpos,_newposASL,_laservec,_p]];
				_veh setvariable ["ace_tankfcs_lastlasetime", time];

				_mag = currentmagazine _veh;
				_magz = __maxranges;
				_maxrng = __maxrng;
				_minrng = __minrng;

				// flash if range outside of LRF limits
				if (_range > _maxrng) then {
					//diag_log format["%3: ACE Tank FCS: measured range too high (%1) fps %2 veh %4 mag %5",_range,diag_fps,time,typeof _veh,_mag];
					[0,_maxrng,_minrng] spawn FUNC(rangedisplay);
					_rd = true;
				};
				if (_range < _minrng) then {
					//diag_log format["%3: ACE Tank FCS: measured range too low (%1) fps %2 veh %4 mag %5",_range,diag_fps,time,typeof _veh,_mag];
					[0,_maxrng,_minrng] spawn FUNC(rangedisplay);
					_rd = true;
					_range = _minrng;
				};
				if !(_rd) then {
					_range = _range + random (__acc) - random (__acc);
					if (_mag in _magz) then {
						_maxrng = _magz select ((_magz find _mag)+1);
						_rd = true;
					} else {
						//check max missile control range if it's selected, flash if exceeded
						_ammo = getText(__magcfg>>"ammo");
						if (_ammo isKindOf "MissileBase") then {
							_maxrng = getNumber(configFile>>"cfgAmmo">>_ammo>>"maxcontrolrange");
						};
					};
					[_range,_maxrng,_minrng] spawn FUNC(rangedisplay);
					if (_range > _maxrng && _rd) then {_range = _maxrng};
				};

				// for low velocity projectiles, account for vert angle to target
				if (_mag in _magz)  then {
					if (getNumber(__magcfg >> "initspeed") <= 300) then {
						_range = _range*cos abs(_p);
					};
				};
				[_veh,_range,_magz,_wpn,false] call FUNC(setsolution);
			},
			{ /* Run condition - default true */
				!(isNull _pulse)
			},
			{ _alive && isNull _pulse }, /* exit condition */
			[ /* Private variables, available throughout all states and conditions */
				"_alive","_offset","_ammo","_magz","_rd","_maxrng","_minrng","_lrf","_range","_veh","_wpn",
				"_tarveh","_l1","_l2","_l3","_offset","_newpos","_spd","_laserVec","_pulsePos","_pulse","_range","_target","_projectile","_newposASL","_p","_p1"
			]
		] call cba_common_fnc_addPerFrameHandlerLogic;

_handle