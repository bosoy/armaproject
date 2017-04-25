#include "script_component.hpp"
private["_handle"];
PARAMS_3(_veh,_dirOffset,_pitchOffset);

_handle = [
			{ /* loop */
				if !(isNull _pulse) then {
					_alive = true;
					_pos = getPosASL _pulse;
					_newpos = _pos;
					//diag_log [_pos,_newpos,velocity _pulse];
					if (((velocity _pulse) call ACE_fnc_magnitude) < 100) then {deletevehicle _pulse}; //can linger for several frames at near zero speed before disappearing
				};
			},
			[_veh,_diroffset,_pitchoffset], /* parameters */
			0, // delay
			{
				//init
				_veh = _this select 0;
				_diroffset = if (count _this > 1) then {_this select 1} else {0};
				_pitchOffset = if (count _this > 2) then {_this select 2} else {0};

				_weapon = "";
				{
					if (getNumber(configFile>>"cfgWeapons">>_x>>QGVAR(enableAirDesignator)) == 1) exitWith {_weapon = currentWeapon _veh};
				} forEach weapons _veh;
				if (_weapon == "") exitwith {GVAR(Kh29_lasinginprogress) = false};

				_lt = _veh getVariable QGVAR(laserObject);
				if (isNil "_lt") then { _lt = objNull};

				_tgtside = "LaserTargetE";
				_laserObject = objNull;
				_p = getPos _veh;
				_aid = "ACE_LogicDummy" createVehicleLocal [_p select 0,_p select 1,6000];
				_isPlayer = player in [driver _veh,gunner _veh];
				_vType = typeOf _veh;

				// Create laser target.
				_laserObject = switch true do {
					case (!(isNull _lt)): {
						_lt
					};
					default {//it means that we will create new marker
						_tgtside = switch (side _veh) do {
							case east: {"LaserTargetE"};
							case west: {"LaserTargetW"};
							default {"LaserTargetE"};//to do: create lt for resistance
						};
						_laserObject = _tgtside createVehicle [_p select 0,_p select 1,3000];
						deleteVehicle _lt;
						_veh setVariable [QGVAR(tracking),nil];
						// compatible with sys_rangefinder
						_laserObject setVariable ["SPON_RF_owner",name (effectiveCommander _veh),true];
						_laserObject setVariable ["ace_RF_owner",player,true];
						
						_veh setVariable [QGVAR(laserObject),_laserObject];
						_laserObject setVariable [QGVAR(pos),getPosASL _laserObject];
						_laserObject
					};
				};
				/******rangefinder******/
				// Offset to avoid collision with shooter
				_pulsePos = _veh modelToWorld [0,50,0];
				_aid setPos _pulsePos;
				_pulsePos = getPosASL _aid;

				_laserVec = switch true do {
					case (_dirOffset != 0 || {_pitchOffset != 0}): {
							_tpos = getPosASL _laserObject;
							_ppos = _pulsePos;
							_vecToTarget = [(_tpos select 0) - (_ppos select 0), (_tpos select 1) - (_ppos select 1), (_tpos select 2) - (_ppos select 2)];
							_dirtotarget = (( _vecToTarget select 0) atan2 (_vecToTarget select 1));
							_pitchtotarget = ((_vecToTarget select 2) atan2 ([_vecToTarget select 0,_vecToTarget select 1,0] call ACE_fnc_magnitude));
							_dir = _dirtotarget + _dirOffset;
							_pitch = _pitchtotarget + _pitchOffset;
							[(sin(_dir)*cos(_pitch)),(cos(_dir)*cos(_pitch)),(sin(_pitch))]
						};
					//if _dirOffset or _pitchOffset isNil here will be used value from "default" switch part
					default {
							_dir = getDir _veh;
							//_pitch = asin((_veh weapondirection _weapon) select 2);
							_pitch = asin((vectordir _veh) select 2);
							[(sin(_dir)*cos(_pitch)),(cos(_dir)*cos(_pitch)),(sin(_pitch))]
						};
				};
				_pulse = "ACE_MissileGuidance_LaserPulse" createVehicleLocal _pulsePos;
				_pulse setPosASL _pulsePos;
				_spd = 600000;
				_pulse setVelocity [(_laserVec select 0)*_spd,(_laserVec select 1)*_spd,(_laserVec select 2)*_spd];
				_range = 0;
				_newpos = nil;
				_alive = false;
				//diag_log ["start",time,_pulse,_alive,alive _pulse,isNull _pulse,getpos _pulse,_veh];
			},
			{ /* exit code */
				//diag_log ["end",time,_pulse,_alive,alive _pulse,isNull _pulse,_newpos];
				if (isNil "_newpos") exitWith { deleteVehicle _aid; deleteVehicle _laserObject;hint "error processing distance";GVAR(Kh29_lasinginprogress) = false };
				_pos = getPosASL _veh;
				_range = sqrt( ((_pos select 0)-(_newpos select 0))^2 + ((_pos select 1)-(_newpos select 1))^2 + ((_pos select 2)-(_newpos select 2))^2);
				if (_range <= 300) exitwith {deleteVehicle _aid; deleteVehicle _laserObject;hint "distance too low";GVAR(Kh29_lasinginprogress) = false};
				if (_range >= 8000) exitwith {deleteVehicle _aid; deleteVehicle _laserObject;hint "distance too high";GVAR(Kh29_lasinginprogress) = false};

				//don't target the air
				//_aid setPosASL _newPos;
				//if (((getPos _aid) select 2) > 20) exitwith {deleteVehicle _aid; deleteVehicle _laserObject;player sidechat "distance too high"};
				deleteVehicle _aid;

				_laserObject setVariable [QGVAR(pos),_newPos];
				_laserObject setPosASL _newPos;
				(group player) reveal _laserObject;
				// Spawning limits loop if it's not running already
				if (isNil {_veh getVariable QGVAR(tracking)}) then {
					_veh setVariable [QGVAR(tracking),true];
					[_veh, typeof _veh] spawn FUNC(Kh29_Limits);
				};
				//scripted guidance when designator on - will guide to target even when not locked on with Tab
				if (isNil {_veh getVariable QGVAR(Kh29_feh)}) then {
					_feh = _veh addeventhandler ["fired",
					{
						private ["_lt","_veh"];
						_veh = _this select 0;
						if (getNumber (configFile >> "CfgAmmo" >> _this select 4 >> "laserLock") == 1) then 
						{
							if (player in [driver _veh,gunner _veh]) then
							{
								if !(isNil {_veh getVariable QGVAR(tracking)}) then
								{
									_lt = _veh getVariable QGVAR(laserObject);
									if (isNil "_lt") then { _lt = objNull};
									if !(isNull _lt) then
									{
										_veh setVariable [QGVAR(curmis),_this select 6];
										_veh setVariable [QGVAR(launchtime),time];
										_veh setVariable [QGVAR(launchpos),getpos (_this select 6)];
										[_veh,_this select 6,_lt] call FUNC(missile_Kh29);
									};
								};
							};
						};
					}];
					_veh setVariable [QGVAR(Kh29_feh),_feh];
				};
				GVAR(Kh29_lasinginprogress) = false;
			},
			{ /* Run condition - default true */
				!(isNull _pulse)
			},
			{ _alive && {isNull _pulse} }, /* exit condition */
			[ /* Private variables, available throughout all states and conditions */
				"_veh","_pos","_alive","_weapon","_laserObject","_p","_tgtside","_newPos", "_spd", "_laserVec",
         			"_pulsePos", "_pulse", "_range", "_target", "_aid", "_lt","_dirOffset","_pitchOffset",
         			"_vType", "_pov", "_designation", "_tracker", "_gunnerInfo", "_turret","_feh","_lrf"
			]
		] call cba_common_fnc_addPerFrameHandlerLogic;

_handle