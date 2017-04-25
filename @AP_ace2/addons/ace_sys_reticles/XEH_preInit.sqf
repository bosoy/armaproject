#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired);
PREP(reticle);
PREP(opticsconfig);
PREP(move);
PREP(scale);

PREP(keypressed);
PREP(veh_move);
PREP(veh_scale);
PREP(veh_reticle);
PREP(veh_opticsconfig);
PREP(veh_keypressed_sa);

GVAR(sightup) = false;
GVAR(illum) = false;
GVAR(el) = 0;
GVAR(wnd) = 0;
GVAR(milx) = 0;
GVAR(mily) = 0;
GVAR(mbtime) = 0;

GVAR(sightup_veh) = false;
GVAR(el_veh) = 0;
GVAR(wnd_veh) = 0;
GVAR(milx_veh) = 0;
GVAR(mily_veh) = 0;
GVAR(illum_veh) = false;

FUNC(rsc) = {
	#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
	#define __dspnil isNil {uiNameSpace getVariable "ACE_RscOpticsReticle"}
	switch (true) do {
		case (__dspnil): {
			13506 cutRsc ["ACE_RscOpticsReticle", "PLAIN",0];
		};
		case (isNull __dsp): {
			13506 cutRsc ["ACE_RscOpticsReticle", "PLAIN",0];
		};
		default {
			13506 cutRsc ["ACE_RscOpticsReticle", "PLAIN",0];
		};
	};
};
FUNC(deh_add) = {
	GVAR(handlerid_keydown) = (findDisplay 46) displayAddEventHandler ["keyDown", "[_this,0] call ace_sys_reticles_fnc_optkey"];
	if (65665 in (actionkeys "optics")) then { //right mouse button
		GVAR(handlerid_mousedown) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", "[_this,1] call ace_sys_reticles_fnc_optkey"];
		GVAR(handlerid_mouseup) = (findDisplay 46) displayAddEventHandler ["MouseButtonUp", "[_this,2] call ace_sys_reticles_fnc_optkey"];

	};
};
FUNC(deh_remove) = {
	if (!isNil QGVAR(handlerid_mousedown)) then	{
		(findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", GVAR(handlerid_mousedown)];
	};
	if (!isNil QGVAR(handlerid_mouseup)) then	{
		(findDisplay 46) displayRemoveEventHandler ["MouseButtonUp", GVAR(handlerid_mouseup)];
	};
	if (!isNil QGVAR(handlerid_keydown)) then	{
		(findDisplay 46) displayRemoveEventHandler ["keyDown", GVAR(handlerid_keydown)];
	};
	GVAR(handlerid_mousedown) = nil;
	GVAR(handlerid_mouseup) = nil;
	GVAR(handlerid_keydown) = nil;
};
FUNC(optkey) = {
	#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
	#define __ctrl (__dsp displayCtrl 1)
	#define __ctrlRing (__dsp displayCtrl 2)
	if !(GVAR(sightup)) exitwith {call FUNC(deh_remove)};
	private ["_type","_data","_dikCode", "_shift", "_ctrlKey", "_alt"];
	_data = _this select 0;
	_type = _this select 1;
	switch (_type) do {
		case 0: { //key down 
  			_ctrl = _data select 0;
  			_dikCode = _data select 1;
  			_shift = _data select 2;
  			_ctrlKey = _data select 3;
  			_alt = _data select 4;

  			if (!_shift && !_ctrlKey && !_alt) then {
   				if (_dikCode in (actionKeys "Optics")) then {
     					13506 cutRsc ["Default", "PLAIN",0];
   				};
  			};
		};
		case 1: { //MB down 
			if (!dialog && {(commandingmenu == "")} && {(_data select 1) == 1}) then {
				GVAR(mbtime) = time;
			};
		};
		case 2: { //MB up 
			if (!dialog && {(_data select 1) == 1}) then {
				if ((time - GVAR(mbtime)) <= 0.19) then {
					__ctrlRing ctrlshow false;
					time spawn {
						waituntil {time - _this > 0.19};
						if (cameraview == "gunner") then {
							__ctrlRing ctrlshow true;
						};
					};
				};
			};
		};
	};
	false
};

[QUOTE(ADDON), "Reticle_Illum", { _this call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Veh_Reticle_Up", { [_this, 1] call FUNC(veh_keypressed_sa) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Veh_Reticle_Down", { [_this, 0] call FUNC(veh_keypressed_sa) }] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;