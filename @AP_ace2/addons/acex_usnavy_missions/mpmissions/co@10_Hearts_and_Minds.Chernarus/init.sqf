if (!isDedicated) then {
	 // Loadingtext
	if (time < 10) then {
		[] spawn {
			waitUntil {!isNil "BIS_fnc_init"};
			// Info text
			["Hearts & Minds", "US Army Special Forces", "Chernarus"] spawn BIS_fnc_infoText;
		};
	};

	execVM "briefing.sqf";
};

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [6];
"dynamicBlur" ppEffectCommit 0;
"dynamicBlur" ppEffectAdjust [0.0];
"dynamicBlur" ppEffectCommit 7;

ASfirstrun = true;

ace_sys_spectator_playable_only = true;

{ _x setVariable ["BIS_noCoreConversations", true] } forEach allUnits;

if (!isDedicated) then {
	while {true} do {
		onTeamSwitch {execVM "briefing.sqf"; playMusic "";};
	};
};