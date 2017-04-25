#include "script_component.hpp"
#define __cfg configFile >> "CfgAmmo" >> _ammo
#define __vcfg configFile >> "cfgVehicles" >> typeof _cur

private ["_ammo","_bullet","_handle"];

PARAMS_1(_unit);
_ammo = _this select 4;
_bullet = _this select 6;

if (isNull _bullet) exitwith {};
_handle = [
			{ /* loop */
				if !(isNull _bullet) then {
					_pos = getPos _bullet;
					//_posASL = getPosASL _bullet;
					_vel = velocity _bullet;
					//diag_log [_pos,_vel];
				} else	 //follow-up tracker to find the exact impact pos
				{
					if(! _aliveb) then
					{
						_b = "ace_at_tracker" createvehiclelocal [_pos select 0,_pos select 1,1000+(_pos select 2)];
						_b setvelocity _vel;
						_b setpos _pos;
						_aliveb = true;
						//diag_log "tracker alive";
					} else
					{
						_posb = getPos _b;
						//diag_log ["tracker:",_posb,velocity _b];
						if (((velocity _b) call ACE_fnc_magnitude) < 5) then {_exit = true};
					};
				};
			},
			[_bullet,_unit,_ammo], /* parameters */
			0, // delay
			{
				//init
				_bullet = _this select 0;
				_unit = _this select 1;
				_ammo = _this select 2;
				_pos = [0,0,0];
				_vel = [0,0,0];
				_posb = [0,0,0];
				_d = 1.5*getNumber(__cfg>>"indirecthitrange");
				_exit = false;
				_aliveb = false;
				_b = objNull;
			},
			{ /* exit code */
				//diag_log ["proceeding",_posb];;
				_obj = _posb nearEntities ["CaManBase",_d]; 
				_objV = _posb nearEntities [["StaticWeapon","Car","Motorcycle","Tank","Boat"],_d];
				_aliveobj = [];
				{ if (alive _x) then {_aliveobj set [count _aliveobj,[_x,_x distance _posb]]} } foreach _obj;
				{
					_cur = _x;
					if (getNumber(__vcfg >> "ACE_NBC_Protection") == 0) then
					{
						_dst = _cur distance _posb;
						{ if (alive _x) then {_aliveobj set [(count _aliveobj),[_x,_dst min (_x distance _posb)]]} } foreach (crew _cur);
					};
				} foreach _objV;

				if (count _aliveobj > 0) then
				{
					[QGVAR(handle_injure), [_aliveobj,_d]] call CBA_fnc_globalEvent;
				};
				//diag_log [_d,_aliveobj];
			},
			{ /* Run condition - default true */
				!(_exit)
			},
			{_exit}, /* exit condition */
			[ /* Private variables, available throughout all states and conditions */
				"_bullet","_unit","_ammo","_pos","_vel","_aliveb","_exit",
				"_cur","_objV","_obj","_b","_aliveobj","_posb","_posASLb","_d","_dst"
			]
		] call cba_common_fnc_addPerFrameHandlerLogic;
_handle