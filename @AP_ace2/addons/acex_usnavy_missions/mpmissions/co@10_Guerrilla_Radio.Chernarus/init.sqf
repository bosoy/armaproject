if (!isDedicated) then {
	 // Loadingtext
	if (time < 10) then {
		[] spawn {
			waitUntil {!isNil "BIS_fnc_init"};
			// Info text
			["Guerrilla Radio", "USMC MEU", "Chernarus"] spawn BIS_fnc_infoText;
		};
	};

	execVM "briefing.sqf";
};

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [6];
"dynamicBlur" ppEffectCommit 0;
"dynamicBlur" ppEffectAdjust [0.0];
"dynamicBlur" ppEffectCommit 7;

ace_sys_spectator_playable_only = true;

{ _x setVariable ["BIS_noCoreConversations", true] } forEach allUnits;

if (!isDedicated) then {
	while {true} do {
		onTeamSwitch {execVM "briefing.sqf"; playMusic "";};
		0 setRain 0;
	};
};