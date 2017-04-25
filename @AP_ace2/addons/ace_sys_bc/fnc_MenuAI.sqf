#include "script_component.hpp"
if (GETVAR(_state) < 2) then
{
	hint "Mission not yet initialized, plz wait";
 } else {
	switch (_this select 0) do
	{
		case 11:
		{
			_lasers = call ace_sys_tracking_fnc_findLaser;
			_lasersLocal = _lasers select 0;
			if (count _lasersLocal == 0) then
			{
				hint "No laser marker found";
				_exit = true;
			} else {
				hint format["Using LaserMarker as Arty Position (%1)",getPos (_lasersLocal select 0)];
			};
		};
		case 12:
		{
			private ["_aT", "_aL", "_pos", "_cond", "_msg", "_type", "_pos", "_exit", "_mag", "_b", "_bar"];
			_exit = false;
			_lasers = call ace_sys_tracking_fnc_findLaser;
			_lasersLocal = _lasers select 0;
			if (count _lasersLocal == 0) then
			{
				hint "No laser marker found";
				_exit = true;
			} else {
				if ("SIX_WeapLaser" in (magazines player)) then
				{
					_mag = "SIX_WeapLaser";
				} else {
					if ("Laserbatteries" in (magazines player)) then
					{
						_mag = "Laserbatteries";
					} else {
						_exit = true;
						hint "Laser Marker is out of Power, Need refill";
					};
				};
			};
			if (_exit) exitWith {};
			_pos = getPos (_lasersLocal select 0); // TODO: 'Closest Local laser?'
			_time = (SIX_BC_SUPPORT select (_this select 1)) select 0;
			_count = (SIX_BC_SUPPORT select (_this select 1)) select 1;

			switch (_this select 1) do
			{
				case 0:
				{
					_type = "Artillery";
					_aL = (SIX_BC_CONFIG select 2) select 1;
					_pos set [2, 0];
				};

				case 1:
				{
					_type = "Airstrike";
					_aL = (SIX_BC_CONFIG select 3) select 1;
					_pos set [2, 100];
				};

				default { _count = 0; _type = "" };
			};
			_aT = time - _time;

			if (_count > 0) then
			{
				_msg = format[" Please Wait: %1 seconds",_aL-_aT];
				if (_aT > _aL) then
				{
					player removeMagazine _mag;
					closeDialog 0;
					hint format ["Sending %1 Request at %2", _type, _pos];

					SIX_BC_SUPPORT set [_this select 1, [time, _count -1]];
					publicVariable "SIX_BC_SUPPORT";

					switch (_this select 1) do
					{
						case 0:
						{
							// Arty
							[ 0, compile format["[_this, %1, %2, %3] spawn DAC_fCallArti", _pos, _this select 2, SIX_BC_SUPSPREAD], player ] call CBA_fnc_globalExecute;
						};
						case 1:
						{
							// Airstrike
							sleep (30 + random 30);
							_bar = [_pos, [(_pos select 0) + 40, (_pos select 1) + 40, _pos select 2], [(_pos select 0) - 40, (_pos select 1) - 40, _pos select 2]];
							{ ["Bo_GBU12_LGB", _x, 0, "", "this setVectorUp [0,-1,0]"] call CBA_network_fnc_cV; sleep 0.1 } forEach _bar;
						};
					};
				} else {
					hint format ["%1 Not available Atm.%2", _type, _msg];
				};
			} else {
				hint format["No More %1 available", _type];
			};
		};
	};
 };

