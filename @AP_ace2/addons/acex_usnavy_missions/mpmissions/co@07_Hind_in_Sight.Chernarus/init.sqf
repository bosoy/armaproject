if (!isDedicated) then {
	 // Loadingtext
	if (time < 10) then {
		[] spawn {
			waitUntil {!isNil "BIS_fnc_init"};
			// Info text
			["Hind in Sight", "USMC MARSOC", "Chernarus"] spawn BIS_fnc_infoText;
		};
	};

	execVM "briefing.sqf";
};

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [6];
"dynamicBlur" ppEffectCommit 0;
"dynamicBlur" ppEffectAdjust [0.0];
"dynamicBlur" ppEffectCommit 7;

execVM "weather.sqf";

execVM "helipad1.sqf";

setViewDistance 500;

{nul = [_x, 0.03] execvm "foggy_breath.sqf" } foreach units (group player);

ace_sys_spectator_playable_only = true;

{ _x setVariable ["BIS_noCoreConversations", true] } forEach allUnits;

if (!isDedicated) then {
	_pos = position vehicle player;
	_ps = "#particlesource" createVehicleLocal _pos;
	_ps setParticleParams [["\Ca\Data\ParticleEffects\Universal\universal.p3d" , 16, 12, 13, 0], "", "Billboard", 1, 10, [0, 0, -6], [0, 0, 0], 1, 1.275, 1, 0, [4], [[1, 1, 1, 0], [1, 1, 1, 0.04], [1, 1, 1, 0]], [1000], 1, 0, "", "", nul];
	_ps setParticleRandom [3, [40, 40, 0], [0, 0, 0], 2, 0.5, [0, 0, 0, 0.1], 0, 0];
	_ps setParticleCircle [0.1, [0, 0, 0]];
	_ps setDropInterval 0.01;


	while {true} do {
		waituntil {vehicle player == player};
		_ps setpos position vehicle player;
		onTeamSwitch {execVM "briefing.sqf"; playMusic "";};
		sleep 1;
	};
};