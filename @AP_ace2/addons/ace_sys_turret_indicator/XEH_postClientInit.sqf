#include "script_component.hpp"
#define __dsp (uiNamespace getVariable "ACE_RscTurretIndicator")
#define __ctrl (__dsp displayCtrl 1591514)
#define __ctrl_bg (__dsp displayCtrl 1591513)
#define __path "\x\ace\addons\sys_turret_indicator\data\gun"
#define __step 15

ADDON = false;

LOG(MSG_INIT);

PREP(indicator);
PREP(direction);

FUNC(direction_com) = 
{
	private ["_vd","_wd","_a","_wvec","_p","_p1"];
	_vd = getdir _this;
	_p = positionCameraToWorld [0,0,0];
	_p1 = positionCameraToWorld [0,0,1];
	_wvec = [(_p1 select 0)-(_p select 0),(_p1 select 1)-(_p select 1),(_p1 select 2)-(_p select 2)];
	_wd = (_wvec select 0) atan2 (_wvec select 1);	//gun dir
	if (_wd < 0) then {_wd = _wd + 360};
	_a = _wd - _vd;
	if (_a < 0) then {_a = 360 + _a};
	_a
};


GVAR(running) = false;

FUNC(getIn) = {
	PARAMS_3(_veh,_pos,_unit);
	if(_unit == player) then {
		if (getNumber (configFile >> "CfgVehicles" >> (typeOf _veh) >> QGVAR(enable)) > 0) then {
			if (player in [driver _veh, gunner _veh, commander _veh]) then {
				if !(GVAR(running)) then
				{
					GVAR(running) = true;
					_veh spawn FUNC(indicator);
				};
			};
		};
	};
};

[] spawn {
	//preload all textures so it doesn't blink in the beginning
	sleep 3;
	GVAR(running) = true;
	13533 cutRsc ["ACE_RscTurretIndicator", "PLAIN",0];
	__ctrl ctrlSetTextColor [0,0,0,0];
	__ctrl_bg ctrlSetTextColor [0,0,0,0];
	sleep 0.1;
	for "_i" from 0 to 360 step __step do
	{
		__ctrl ctrlSetText format[__path+"%1"+".paa",_i];
		sleep 0.1;
	};
	if !(isNull __dsp) then { 13533 cutRsc ["Default", "PLAIN",0] };
	GVAR(running) = false;
	if ((vehicle player) != player) then {
		[(vehicle player), "", player] call FUNC(getIn);
	};
};


ADDON = true;
