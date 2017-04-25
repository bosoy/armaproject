/*
	max range values for NVG/TI are read from:
	- Rifles/Launchers: weapon(muzzle) config 
	- NVG/Binos: corresponding cfgweapons class
	- vehicles:  corresponding turret in cfgvehicles (body for drivers)

	value names: "ace_sys_nvg_nvrange" and "ace_sys_nvg_tirange"
*/
#include "script_component.hpp"
private ["_range_property","_w","_path","_newvd","_woptics","_veh","_cfgoptic","_mode","_abort","_ass", "_cfgveh", "_cfgweapons"];
_mode = currentVisionmode player;
if (_mode == 0) exitwith {};

_range_property = if (_mode == 1) then {"ace_sys_nvg_nvrange"} else {"ace_sys_nvg_tirange"};
_newvd = 0;
_path = "";
_abort = false;

_cfgweapons = configfile >> "cfgweapons";

if (player == vehicle player) then
{
	_cfgoptic = _cfgweapons;
	_w = player call FUNC(animtype);
	switch (_w) do
	{
		case 0: //rifle
		{
			if (cameraview == "gunner") then
			{
				_cfgoptic = _cfgweapons >> (primaryweapon player);
				if (currentmuzzle player != primaryweapon player) then
				{
					_cfgoptic = _cfgoptic >> (currentmuzzle player);
				};
				_woptics = getText (_cfgoptic >> "modeloptics");
				if (_woptics != "" && {_woptics != "-"}) then {
					_w = [_cfgoptic,_mode] call FUNC(curoptics);
					switch (_w) do {
						case 1: {_path = _cfgoptic}; //NV/Ti-enabled optics
						case 2: {_abort = true}; //non-NV-enabled optics
						default {};
					};
				};
			};
		};
		//skipping pistol
		case 2: //AT
		{
			if (cameraview == "gunner") then
			{
				_woptics = getText (_cfgweapons >> (secondaryweapon player) >> "modeloptics");
				if (_woptics != "" && {_woptics != "-"}) then
				{
					_path = _cfgweapons >> (secondaryweapon player);
				};
			};
		};
		case 3: //bino
		{
			if (cameraview == "gunner") then
			{
				_w = "";
				{
					if (getText(_cfgweapons >> _x >> "simulation") == "Binocular") exitwith {_w = _x};
				} foreach (weapons player);
				if (_w != "") then
				{
					_path = _cfgweapons >> _w;
				};
			};
		};
		default {};
	};
	if (typename _path != "config") then //it's NVG
	{
		_w = "";
		{
			if (getText(_cfgweapons >> _x >> "simulation") == "NVGoggles") exitwith {_w = _x};
		} foreach (weapons player);
		if (_w != "") then {
			_path = _cfgweapons >> _w;
		};
	};
	if (typename _path != "config") exitwith {};
	if (isNumber(_path >> _range_property)) then
	{
		_newvd = getNumber(_path >> _range_property)
	};
	if (isNil "_newvd") exitwith {};
	if (_newvd <= 0) exitwith {};

	if (_newvd < viewdistance) then
	{
		setviewdistance _newvd;
		player setVariable [QGVAR(vddd),_newvd];
	};
	if (_abort) then {player switchcamera "internal"};
}
else
{
	if (cameraview == "gunner") then
	{
		_veh = typeof (vehicle player);
		_cfgveh = configfile >> "cfgvehicles" >> _veh;
		_ass = assignedvehiclerole player;
		/*if (isArray(_cfgveh>>(_range_property+"arr")) && ([vehicle player,_ass select 1,_mode] call FUNC(isusingoptics_veh))) exitwith
		{
			_path = getArray(_cfgveh>>(_range_property+"arr"));
			_newvd = switch (_ass select 0) do {
				case "Driver": {_path select 0};
				case "Turret": {};
				default {""};
			};
		};*/
		_path = switch (_ass select 0) do {
			case "Driver": {_cfgveh};
			case "Turret": {
				if ([vehicle player,_ass select 1,_mode] call FUNC(isusingoptics_veh)) then {
					[vehicle player,_ass select 1] call cba_fnc_getturret;
				} else {""};
			};
			default {""};
		};
		//player sidechat format ["%1",_path];
	};
	if (typename _path != "config") then
	{
		_w = "";
		{
			if (getText(_cfgweapons >> _x >> "simulation")=="NVGoggles") exitwith {_w = _x};
		} foreach (weapons player);
		if (_w != "") then {_path = _cfgweapons >> _w};
	};
	if (typename _path != "config") exitwith {};
	if (isNumber(_path >> _range_property)) then
	{
		_newvd = getNumber(_path >> _range_property);
	};
	if (_newvd <= 0) exitwith {};
	if (viewdistance > _newvd) then
	{
		setviewdistance _newvd;
	};
};
//hint format ["%1",[_path,_newvd]];