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
#define __bsgt getNumber(__vehcfg >> "ace_tankfcs_battlesight")

//if !(player in _veh) exitwith {};
if (cameraView != "GUNNER") exitwith {};

private ["_c","_magz","_index","_actions","_veh","_rolefnc","_comgun"];
_veh = vehicle player;
_comgun = getNumber(configfile>>"cfgVehicles">>typeof _veh>>"ace_tankfcs_commanderisgunner");

if !(isNil {_veh getvariable "ace_tankfcs_init"}) exitwith {};

_veh setvariable ["ace_tankfcs_init",true];

_index = _veh addaction [localize "STR_ACE_TFCSLASE",QPATHTO_C(action_lase.sqf),"",-7,false,false,"","cameraView == 'GUNNER'"];
_actions = [_index];
if (__lead > 0 && {_comgun == 0}) then {
	_index = _veh addaction [localize "STR_ACE_TFCSDUMP",QPATHTO_C(action_dump.sqf),"",-8,false,false,"","cameraView == 'GUNNER'"];
	_actions set [count _actions,_index];
	_veh spawn FUNC(turrettracker);
};
if (__bsgt > 0) then {
	_index = _veh addaction [localize "STR_ACE_TFCSBSGT",QPATHTO_C(action_battlesight.sqf),"",-9,false,false,"","cameraView == 'GUNNER'"];
	_actions set [count _actions,_index];
};
_index = _veh addaction [localize "STR_ACE_TFCSFCSOFF",QPATHTO_C(action_fcsoff.sqf),"",-10,false,false,"","cameraView == 'GUNNER'"];
_actions set [count _actions,_index];

_veh setvariable ["ace_tankfcs_actions",_actions];

_veh setvariable ["ace_tankfcs_lrfdata",[]];
_veh setvariable ["ace_turret_time",[]];
_veh setvariable ["ace_turret_azimuth",[]];
_veh setvariable ["ace_turret_elevation",[]];
_veh setvariable ["ace_tank_velocity",[]];
_veh setvariable ["ace_avg_tank_velocity",[0,0,0]];
_veh setvariable ["ace_turret_speed",[0,0]];
_veh setvariable ["ace_compute_lead",true];
_veh setvariable ["ace_tankfcs_azichangeprev",0];
_veh setvariable ["ace_tankfcs_flash",false];
_veh setvariable ["ace_tankfcs_range",0];
_veh setvariable ["ace_tankfcs_fired",[],true];
_veh setvariable ["ace_tankfcs_boreoffsetangleh",0];
if (isNil {_veh getvariable "ace_tankfcs_lastlasetime"}) then {
	_veh setvariable ["ace_tankfcs_lastlasetime", 0];
};

//optics offset correction
_veh call FUNC(boreoffset);

// digital range display

[0] spawn FUNC(startrangedisplay);

_rolefnc = {if (_comgun == 1) then {player == commander _veh} else {player == gunner _veh}};

waituntil {
	sleep 1;

	//range display only in optics view
	if (cameraview != "GUNNER" || {visiblemap}) then {
		if !(isNull __dsp) then { 135443 cutRsc ["Default", "PLAIN",0] };
	} else {
		//restoring display when in optics mode again
		if (isNull __dsp) then {
			[_veh getvariable "ace_tankfcs_range"] spawn FUNC(startrangedisplay);
		};
	};
	!(call _rolefnc) || {! alive player} || {! alive _veh} || {isNil {_veh getvariable "ace_tankfcs_init"}}
};

_veh setvariable ["ace_tankfcs_init",nil];
_veh setvariable ["ace_tankfcs_fired",nil,true];
_veh setvariable ["ace_compute_lead",false];

{_veh removeaction _x} foreach (_veh getvariable ["ace_tankfcs_actions", []]);

if !(isNull __dsp) then { 135443 cutRsc ["Default", "PLAIN",0] };

//(vehicle player) addaction ["FCS ON","\x\ace\addons\ace_sys_tankfcs\fnc_startfcs.sqf"];
