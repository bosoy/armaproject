#define DEBUG_MODE_FULL

#include "script_component.hpp"

#define __br (parseText "<br />")
#define __det (parseText (format ["%1",localize "STR_ACE_VERSION_DETECT"]))
#define __server (parseText (format ["Server Version: %1", _serverVersion]))
#define __client (parseText (format ["Client Version:  <t color ='#FF0F00'>%1</t>", _localVersion]))
#define __update (parseText (format ["%1", localize "STR_ACE_VERSION_UPDATE"]))

private "_i";
PARAMS_3(_serverVersion,_localVersion,_player);

if (isNil "ACE_MISMATCH") then {ACE_MISMATCH = true}; // Allow an override set by developer during testing or else.

#define CTRL(A) ((findDisplay 114111) displayCtrl A)

_i = 0;
while {ACE_MISMATCH} do {
	waitUntil {!dialog};
	if (_i > 5) exitWith {endMission "END6"}; // disconnect after more than 5 repeats.
	INC(_i);

	createDialog "ACE_VERSION_MISMATCH";
	CTRL(114112) ctrlSetText (localize "STR_ACE_VERSION_WARNING");
	CTRL(114113) ctrlSetStructuredText (composeText [__det, __br, __br, __server, __br, __client, __br, __br, __br, __update]);
	CTRL(114114) ctrlSetText (localize "STR_DISP_MAIN_CONTINUE");
	sleep 10;
};
