// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define C_AMMO configFile >> "CfgAmmo"

private ["_ammo", "_startTime", "_endLife"];
_ammo = _this select 4;

// _size = ""; // Perhaps grab from config, tracerScale
_tr = "ACE_Shell_Tracer_Red" createVehicleLocal [0,0,100]; // TODO grab from config

[_this select 6, _tr, time + getNumber(C_AMMO >> _ammo >> "tracerStartTime"), time + getNumber(C_AMMO >> _ammo >> "tracerEndTime")] spawn {
	PARAMS_4(_pr,_tr,_startTime,_endLife);

	waitUntil {time > _startTime};
	if (_endLife <= time) exitWith { deleteVehicle _tr }; // No need to burn if we are already past the end time

	//_tracer = true;

	// TODO Double check if you really can't use attachTo instead :D
	// Using waitUntil due to cycle-per-frame
	waitUntil {
		_v = if (alive _pr) then {velocity _pr} else {[0,0,0]};
		// Always verify the condition BEFORE executing code
		if (alive _pr && {time < _endLife} && {(_v call ACE_fnc_magnitude) > 30}) then {
			if !(isNull _tr) then {
				_tr setVectorUp _v;
				_tr setPosATL (getPosATL _pr);
				/*
				if (_tracer) then {
					if ((abs (_v select 0) + abs (_v select 1) + abs (_v select 2)) < 460) then
					{
						_tr setpos _p;
						deleteVehicle _tr;
						_trDud = _trDudType createVehicleLocal (getPosATL _pr);
						_trLight LightAttachObject [_trDud, [0,0,0]];
						_tracer = false;
					};
				};
				*/
			};
			/*
			if !(_tracer) then
			{
				if !(isNull _trDud) then
				{
					_trDud setVectorUp _v;
					_trDud setPosATL (getPosATL _pr);
				};
			};
			*/

			false;
		} else {
			true;
		};
	};

	//TRACE_3("End of Life",_trLight,_tr,_trDud);
	{
		if !(isNull _x) then {
			_p = getpos _x;
			_p = [_p select 0,_p select 1,1000];
			_x setpos _p; //putting smw far first to prevent the illusion of them 'bouncing off'
			deleteVehicle _x;
		};
	} forEach [_tr]; //[_trLight, _tr, _trDud];
};