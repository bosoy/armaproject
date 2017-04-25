#include "script_component.hpp"

#define __dsp (uiNamespace getVariable "ACE_M1A1GPS_DISPLAY")
#define __thousandscontrol  (__dsp displayCtrl 432112)
#define __hundredscontrol  (__dsp displayCtrl 432113)
#define __tenscontrol  (__dsp displayCtrl 432114)
#define __onescontrol  (__dsp displayCtrl 432115)
#define __path "\x\ace\addons\sys_tankfcs\data\"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __maxrng getNumber(__vehcfg >> "ace_tankfcs_maxlrfrange")
#define __minrng getNumber(__vehcfg >> "ace_tankfcs_minlrfrange")
#define __lead getNumber(__vehcfg >> "ace_tankfcs_maxlead")
#define __maxranges getArray(__vehcfg >> "ace_tankfcs_maxranges")

//if !(player in _veh) exitwith {};
private ["_c","_magz","_index1","_index2","_actions","_veh"];
_veh = vehicle player;

if !(isNil {_veh getvariable "ace_tankfcs_com_init"}) exitwith {};

_veh setvariable ["ace_tankfcs_com_init",true];

_index1 = _veh addaction [localize "STR_ACE_TFCSLASE",QPATHTO_C(action_lase_com.sqf)];
_index2 = _veh addaction [localize "STR_ACE_TFCSFCSOFF",QPATHTO_C(action_fcsoff_com.sqf)];

_actions = [_index1,_index2];

_veh setvariable ["ace_tankfcs_com_actions",_actions];
_veh setvariable ["ace_tankfcs_lrfdata",[800,0,0,0,0]];
_veh setvariable ["ace_tankfcs_flash",false];
_veh setvariable ["ace_tankfcs_range",0];
if (isNil {_veh getvariable "ace_tankfcs_lastlasetime"}) then {
	_veh setvariable ["ace_tankfcs_lastlasetime", 0];
};
// digital range display

[0] spawn FUNC(startrangedisplay);

waituntil {
	sleep 3;

	//range display only in optics view
	if (cameraview != "GUNNER") then {
		if !(isNull __dsp) then { 135443 cutRsc ["Default", "PLAIN",0] };
	} else {
		//restoring display when in optics mode again
		if (isNull __dsp) then {
			[_veh getvariable "ace_tankfcs_range"] spawn FUNC(startrangedisplay);
		};
	};
	player != commander _veh || {!alive player} || {!alive _veh} || {isNil {_veh getvariable "ace_tankfcs_com_init"}}
};

_veh setvariable ["ace_tankfcs_com_init",nil];

{_veh removeaction _x} foreach (_veh getvariable "ace_tankfcs_com_actions");

if !(isNull __dsp) then { 135443 cutRsc ["Default", "PLAIN",0] };