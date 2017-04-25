#include "script_component.hpp"
/*
disableSerialization;

private ["_pos", "_x", "_y", "_xgrid", "_pos", "_ygrid", "_lastY", "_lastX", "_xcoord", "_ycoord", "_sec", "_min", "_hour", "_time", "_display", "_speed", "_vic", "_dagrHeading", "_dagrGrid"];

if (local player) then {
	if (!DAGR_RUN) exitWith { false };
	135471 cutRsc ["DAGR_GPS_Display", "plain down"];
	_display = (uiNameSpace getVariable "DAGR_GPS_Display");
	_background = _display displayCtrl 266856;
	_background ctrlSetText QPATHTO_T(data\dagr_gps_show.paa);

	DAGR_DISPLAY_SELECTION = "GPS";
	
	[] spawn {
		while {DAGR_RUN} do {
			sleep DAGRSLEEP;
			if !(player hasweapon "ACE_DAGR") exitWith {
				DAGR_RUN = false;
				135471 cutRsc ["Default", "plain down"];
			};
		};
	};
	false
};*/
