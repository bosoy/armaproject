if (!isDedicated) then {
	 // Loadingtext
	if (time < 10) then {
		[] spawn {
			waitUntil {!isNil "BIS_fnc_init"};
			// Info text
			["Steamroller", "USMC MEU", "Takistan"] spawn BIS_fnc_infoText;
		};
	};

	execVM "briefing.sqf";
	
	execVM "dust.sqf";

	execVM "sound.sqf";
};

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [6];
"dynamicBlur" ppEffectCommit 0;
"dynamicBlur" ppEffectAdjust [0.0];
"dynamicBlur" ppEffectCommit 7;

setViewDistance 400;

ace_sys_spectator_playable_only = true;

{ _x setVariable ["BIS_noCoreConversations", true] } forEach allUnits;

//Init UPSMON script
call compile preprocessFileLineNumbers "scripts\Init_UPSMON.sqf";

BIS_Effects_Burn=compile preprocessFile "\ca\Data\ParticleEffects\SCRIPTS\destruction\burn.sqf";

if (!isDedicated) then {
	while {true} do {
		cutRsc ["goggles","PLAIN"];
		setWind [5,5, true];		
		0 setRain 0;
		onTeamSwitch {execVM "briefing.sqf"; playMusic "";};
	};
} else {
	while {true} do {
		setWind [5,5, true];
		0 setRain 0;
	};
};