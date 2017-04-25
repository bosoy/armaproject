// by Xeno
#define THIS_FILE "x_jip.sqf"
#include "x_setup.sqf"
if (!X_Client) exitWith {};

if (!isNil QGVAR(jip_started)) exitWith {};
GVAR(jip_started) = true;

if (GVAR(FastTime) > 0) then {
	if (X_Client && !X_Server) then {
		0 setOvercast 0;
		0 spawn {
			waitUntil {sleep 0.221;!isNil {__XJIPGetVar(currentTime)}};
			while {true} do {
				sleep 1;
				skipTime (__XJIPGetVar(currentTime) - DayTime);
			};
		};
	};
};

__ccppfln(x_client\x_setupplayer.sqf);

#ifdef __CARRIER__
0 spawn {
	sleep 2;
	player setPosASL [getPosASL player select 0, getPosASL player select 1, 9.26];
};
#endif