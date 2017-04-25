/* ----------------------------------------------------------------------------
Function: ACE_fnc_unitvehpos

Description:
	Function to retrieve unit position in vehicle, analogous to assignedvehiclerole but more reliable

Parameters:
		unit

Returns:
		[] - on foot
		["Driver"] - driver 
 		["Cargo"] - cargo 
 		["Turret", [turret path]] - turret

Examples:
	(begin example)
		_vehpos = player call ACE_fnc_unitvehpos
	(end)

Author:
	(c) q1184/Rocko 
---------------------------------------------------------------------------- */


#include "script_component.hpp"
#define __cfg (configFile >> "CfgVehicles" >> (typeof _v) >> "turrets")

private ["_u","_v","_tc","_tp","_st","_stc","_ptp","_res","_fn"];
_fn = 
{
	private ["_c","_tc","_ar","_fn","_ind","_cnt","_cur"];
	_c = _this select 0;
	_ar = _this select 1;
	_fn = _this select 2;
	_ind = _this select 3;
	_tc  = count _c;
	_cnt = -1;
	if (_tc > 0) then
	{
		for "_i" from 0 to (_tc-1) do 
		{
			if (isclass (_c select _i)) then 
			{
				_cnt = _cnt+1;
				_cur = +_ind;
				_cur set [count _cur,_cnt];
				_ar set [count _ar,_cur];
				if (isclass ((_c select _i)>>"turrets")) then {[(_c select _i)>>"turrets",_ar,_fn,_cur] call _fn};
			};
		};
	};
	_ar	
};

_u = _this;
_v = vehicle _u;
if (_u == _v) exitwith {[]};
_tp = [__cfg,[],_fn,[]] call _fn;
//diag_log _tp;
_ptp = [];
{if (_u == _v turretUnit _x) exitwith {_ptp = _x}} foreach _tp;
if (count _ptp > 0) then 
{
	_res = ["Turret",_ptp];
} else
{
	_res = if (_u == driver _v) then {["Driver"]} else {["Cargo"]};
};
_res