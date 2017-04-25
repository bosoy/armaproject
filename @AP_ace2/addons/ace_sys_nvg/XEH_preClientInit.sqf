#include "script_component.hpp"
ADDON = false;

LOG(MSG_INIT);

// NVG settings
GVAR(on) = false;
GVAR(settingon) = true;

GVAR(sensitivity) = uiNamespace getVariable [QGVAR(sensitivity), __INIT_APERTURE];
if (isNil QGVAR(rangelimit_enabled)) then { GVAR(rangelimit_enabled) = false }; 

GVAR(trkcamview) = false;
GVAR(trkvehpos) = false;

FUNC(NVGon) = {
	GVAR(on) = true;
	setAperture GVAR(sensitivity);
	if (GVAR(rangelimit_enabled)) then {
		if ((vehicle player) isKindOf "Air" && {!((vehicle player) isKindOf "ParachuteBase")} && {!((vehicle player) isKindOf "BIS_Steerable_Parachute")}) exitwith {};
		if ((_this select 1)==0) then {GVAR(vd) = viewdistance};
		call FUNC(setVD);
		[] spawn FUNC(trk_camview);
		[] spawn FUNC(trk_vehpos);
	};
};

FUNC(TIon) = {
	if (GVAR(rangelimit_enabled)) then {
		if ((vehicle player) isKindOf "Air" && {!((vehicle player) isKindOf "ParachuteBase")} && {!((vehicle player) isKindOf "BIS_Steerable_Parachute")}) exitwith {};
		if ((_this select 1)==0) then {GVAR(vd) = viewdistance};
		call FUNC(setVD);
		[] spawn FUNC(trk_camview);
		[] spawn FUNC(trk_vehpos);
	};
};

FUNC(TIoff) = {
	if (GVAR(rangelimit_enabled)) then {
		GVAR(trkcamview) = false;
		GVAR(trkvehpos) = false;
		if (typename GVAR(vd) == "scalar") then {setviewdistance GVAR(vd)};
	};
};

//track player entering/leaving optics while in NV mode to set appropriate VD for NV scope or NV goggles correspondingly.
FUNC(trk_camview) = {
	sleep 0.2;
	if (GVAR(trkcamview)) exitwith {};
	GVAR(trkcamview) = true;
	private ["_oldcamview", "_camview"];
	_oldcamview = cameraview;
	while {GVAR(trkcamview)} do {
		_camview = cameraview;
		if (_camview != _oldcamview) then {
			if ((_camview == "gunner" || {_oldcamview == "gunner"}) && {currentVisionmode player != 0}) then {
				call FUNC(setVD);
			};
			_oldcamview = _camview;
		};
		sleep 0.1;
	};
};

//track player's vehicle and position inside it while in NV mode to set appr. viewdistance
FUNC(trk_vehpos) = {
	sleep 0.2;
	if (GVAR(trkvehpos)) exitwith {};
	GVAR(trkvehpos) = true;
	private ["_oldveh", "_veh","_oldpos","_pos"];
	_oldveh = vehicle player;
	_oldpos = if (_oldveh != player) then {assignedVehicleRole player} else {[]};
	while {GVAR(trkvehpos)} do {
		_veh = vehicle player;
		if (_veh != _oldveh) then { //vehicle changed
			_oldveh = _veh;
			_oldpos = if (_veh != player) then {assignedVehicleRole player} else {[]};
			if ((currentVisionmode player) != 0) then {
				call FUNC(setVD);
			};
		} else {
			if (_veh != player) then {
				_pos = assignedVehicleRole player;
				if (!([_pos,_oldpos] call BIS_fnc_areEqual)) then { //position inside vehicle changed
					_oldpos = _pos;
					if (currentVisionmode player != 0) then {
						call FUNC(setVD);
					};
				};
			} else {
				_oldpos = [];
			};
		};
		sleep 0.5;
	};
};

FUNC(trk_altitude) = {
	sleep 1;
	private ["_h","_h1"];
	_h = (getposATL (vehicle player)) select 2;
	while {GVAR(trkvehpos)} do {
		_h1 = (getposATL (vehicle player)) select 2;
		if (abs (_h1 - _h) > 1) then {
			setviewdistance sqrt(_h1^2 + _this^2);
			//hint format ["%1",sqrt(_h1^2 + _this^2)];
		};
		sleep 1;
	};
};

PREP(NVGoff);
PREP(setVD);
PREP(animtype);
PREP(keypressed);
PREP(isusingoptics_veh);
PREP(curoptics);

["ace_nvg_off", {call FUNC(NVGoff)}] call CBA_fnc_addEventhandler;
["ace_nvg_on", {call FUNC(NVGon)}] call CBA_fnc_addEventhandler;
["ace_ti_off", {call FUNC(TIoff)}] call CBA_fnc_addEventhandler;
["ace_ti_on", {call FUNC(TIon)}] call CBA_fnc_addEventhandler;

[QUOTE(ADDON), "brightnessUP", { [1] call FUNC(keyPressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "brightnessDOWN", { [0] call FUNC(keyPressed) }] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
