if (!isDedicated) then {
	 // Loadingtext
	if (time < 10) then {
		[] spawn {
			waitUntil {!isNil "BIS_fnc_init"};
			// Info text
			["Pest Control", "US Army Airborne", "Chernarus"] spawn BIS_fnc_infoText;
		};
	};

	execVM "briefing.sqf";
	
	[] spawn {
		waitUntil {!isNull player};
		player action ["NVGoggles", player];
	};
};

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [6];
"dynamicBlur" ppEffectCommit 0;
"dynamicBlur" ppEffectAdjust [0.0];
"dynamicBlur" ppEffectCommit 7;

execVM "LightsOutFOB.sqf";

execVM "LightsOutGorka.sqf";

execVM "helipad1.sqf";

execVM "helipad2.sqf";

ace_sys_spectator_playable_only = true;

ace_settings_enable_vd_change = true;

{ _x setVariable ["BIS_noCoreConversations", true] } forEach allUnits;

if (!isDedicated) then {
	while {true} do {
		0 setOvercast 0;
		onTeamSwitch {execVM "briefing.sqf"; playMusic "";};
	};
} else {
	while {true} do {
		0 setOvercast 0;
	};
};