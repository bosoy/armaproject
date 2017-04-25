/* ace_sys_spacebar | (c) 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __LAYER 135999
#define __DISP ((uiNamespace getVariable "ACE_Recog_Overlay") displayCtrl -1)
#define __GETCOLOR configFile >> "CfgInGameUI" >> "CommandBar"
#define __COLOR [0,0.6,0,_alpha]

PARAMS_4(_name,_name_mod,_target,_max);

private "_color";

_max = switch (true) do {
	// Evening to Night
	case (dayTime > 18.2 && dayTime < 18.4 ): {20};
	case (dayTime > 18.4 && dayTime < 18.7 ): {18};
	case (dayTime > 18.7 && dayTime < 19 ): {14};
	// Night
	case (dayTime > 19): {12};
	// Night to morning
	case (dayTime > 5 && dayTime < 5.5): {20};
	case (dayTime > 5.5 && dayTime < 6): {22};
	default {_max};
};
if (currentVisionMode player in [1,2]) then {_max = _max * 1.66}; // Safer

__LAYER cutRsc ["ACE_Recog_Overlay","PLAIN",0];
__DISP ctrlSetStructuredText (composeText _name);

if (!isnull __DISP && {!ace_sys_spectator_SPECTATINGON}) then {
	GVAR(ctrl_timeout) = time + 2;
	_distance = player distance _target;
	// Der Name wird abhängig von der Entfernung ausgeblendet.
	// Bei maximaler Entfernung, also < 30, ist die maximale Alphaeinblendung 0.1 %.
	_alpha = (0.9 - ((floor(_distance))/_max) + 0.1) / _name_mod;
	// _screenPos = worldToScreen (getPos _target);
	// __DISP ctrlSetPosition _screenPos;
	// __DISP ctrlCommit 0;
	//if (_target in (groupSelectedUnits player) && _target in units group player) then
	if (_target in units group player) then {
		switch (assignedTeam _target) do {
			case "WHITE": { _color = getArray(__GETCOLOR >> "colorWhiteTeam") };
			case "BLUE": { _color = getArray(__GETCOLOR >> "colorBlueTeam") };
			case "YELLOW": { _color = getArray(__GETCOLOR >> "colorYellowTeam") };
			case "RED": { _color = getArray(__GETCOLOR >> "colorRedTeam") };
			case "GREEN": { _color = getArray(__GETCOLOR >> "colorGreenTeam") };
			case "MAIN": { _color = getArray(__GETCOLOR >> "colorWhiteTeam") };
			default { _color = getArray(__GETCOLOR >> "colorWhiteTeam") };
		};
		_color set [3,_alpha];
		__DISP ctrlSetTextColor _color;
	} else {
		__DISP ctrlSetTextColor __COLOR; //Default color for name tags (greenish)
	};
	if (isNil QGVAR(ctrl_cutted)) then {
		GVAR(ctrl_cutted) = true;
		0 spawn {
			waitUntil {time >= GVAR(ctrl_timeout) || {!alive player}};
			__LAYER cutRsc ["DEFAULT", "PLAIN"];
			GVAR(ctrl_cutted) = nil;
		};
	};
};
