if (!isDedicated) then {
	 // Loadingtext
	if (time < 10) then {
		[] spawn {
			waitUntil {!isNil "BIS_fnc_init"};
			// Info text
			["Reaper", "US Army Delta Force", "Takistan"] spawn BIS_fnc_infoText;
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

//Init UPSMON script
call compile preprocessFileLineNumbers "scripts\Init_UPSMON.sqf";

if (!isNil "SF1") then {
	SF1 addAction["Request Missile (Hellfire)","launchMissile.sqf",[SF1, missilestart,"M_Hellfire_AT",200]];
	SF1 addAction["Request Bomb (GBU)","launchMissile.sqf",[SF1, missilestart,"Bo_GBU12_LGB",200]];
};

if (!isNil "SF8") then {
	SF8 addAction["Request Missile (Hellfire)","launchMissile.sqf",[SF8, missilestart,"M_Hellfire_AT",200]];
	SF8 addAction["Request Bomb (GBU)","launchMissile.sqf",[SF8, missilestart,"Bo_GBU12_LGB",200]];
};

if (!isDedicated) then {
	while {true} do {
		onTeamSwitch {execVM "briefing.sqf"; playMusic "";};
	};
};