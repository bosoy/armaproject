#include "script_component.hpp"
#define __dsp (uiNamespace getVariable "ACE_RscTurretIndicator")
#define __ctrl_digind (__dsp displayCtrl 1591516)
#define __ctrl_com (__dsp displayCtrl 1591515)
#define __ctrl (__dsp displayCtrl 1591514)
#define __ctrl_bg (__dsp displayCtrl 1591513)
#define __path "\x\ace\addons\sys_turret_indicator\data\gun"
#define __step 15
#define __step_com 15
#define __color [0.24,0.74,0.22,1]

private ["_color","_angle","_ar","_wpn","_iscom","_p","_k"];
_wpn = _this weaponsturret [0];
if (count _wpn == 0) exitwith {};
 _wpn = _wpn select 0;
13533 cutRsc ["ACE_RscTurretIndicator", "PLAIN",0];

__ctrl ctrlsetposition [SafeZoneX+0.1,SafeZoneY+0.05,0.08*SafezoneH,0.08*SafezoneH]; //,0.117*SafeZoneW,0.15*SafeZoneW];
__ctrl ctrlcommit 0;
__ctrl_bg ctrlsetposition [SafeZoneX+0.1,SafeZoneY+0.05,0.08*SafezoneH,0.08*SafezoneH]; //,0.117*SafeZoneW,0.15*SafeZoneW];
__ctrl_bg ctrlcommit 0;
__ctrl ctrlSetTextColor __color;
__ctrl_bg ctrlSetTextColor __color;
_iscom = (player == commander _this);
_p = ctrlposition __ctrl;
_k = 0.55/(getresolution select 5);
__ctrl_com ctrlsetposition [(_p select 0)+0.125*(_p select 2),(_p select 1)+0.125*(_p select 3),0.75*(_p select 2),0.75*(_p select 3)];
__ctrl_com ctrlcommit 0;
__ctrl_digind ctrlsetposition [(_p select 0),(_p select 1)+0.08*SafezoneH,(_p select 2)/_k,0.04*SafezoneH/_k];
__ctrl_digind ctrlsetscale _k;
__ctrl_digind ctrlcommit 0;

if (_iscom) then
{
	__ctrl_com ctrlSetTextColor [1,1,0,1];
	__ctrl_digind ctrlSetTextColor [1,1,0,1];
} else
{
	__ctrl_com ctrlSetTextColor [0,0,0,0];
	__ctrl_digind ctrlSetTextColor [0,0,0,0];
};
GVAR(running) = true;
while {GVAR(running)} do {
	if (visiblemap) then {
		if (ctrlshown __ctrl) then {__ctrl ctrlshow false};
		if (ctrlshown __ctrl_com) then {__ctrl_com ctrlshow false};
		if (ctrlshown __ctrl_bg) then {__ctrl_bg ctrlshow false};
		if (ctrlshown __ctrl_digind) then {__ctrl_digind ctrlshow false};
	} else {
		if !(ctrlshown __ctrl) then {__ctrl ctrlshow true};
		if !(ctrlshown __ctrl_com) then {__ctrl_com ctrlshow true};
		if !(ctrlshown __ctrl_bg) then {__ctrl_bg ctrlshow true};
		if !(ctrlshown __ctrl_digind) then {__ctrl_digind ctrlshow true};
		_angle = [_this,_wpn] call FUNC(direction);
		_ar = (round ((_angle select 0)/__step))*__step;
		_ar = format[__path+"%1"+".paa",_ar];
		__ctrl ctrlSetText _ar;

		if (player == commander _this && {player != gunner _this}) then
		{
			__ctrl_digind ctrlSetTextColor __color;
			__ctrl_digind ctrlSetText format ["GUN: %1",round(_angle select 1)];

			if(cameraview == "gunner") then
			{
				__ctrl_com ctrlSetTextColor [1,1,0,1];
				_angle = _this call FUNC(direction_com);
				_angle = (round (_angle/__step_com))*__step_com;
				_ar = format[__path+"%1"+".paa",_angle];
				__ctrl_com ctrlSetText _ar;
			} else
			{
				__ctrl_com ctrlSetTextColor [0,0,0,0];
			};
		} else
		{
			__ctrl_com ctrlSetTextColor [0,0,0,0];
			__ctrl_digind ctrlSetTextColor [0,0,0,0];
		};
	};
	if(!(player in [driver _this, gunner _this, commander _this]) || {!alive player}) then {
		GVAR(running) = false;
	};
	sleep 0.1;
};
if !(isNull __dsp) then { 13533 cutRsc ["Default", "PLAIN",0] };
