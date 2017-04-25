//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

//Workaround to replace BIS killed EH and other scripts!
[] spawn {
	sleep 0.5;
	waitUntil {!isNil "BIS_Effects_Secondaries"};
	// keep references, just to be sure
	BIS_Effects_EH_Killed = FUNC(killed);
	BIS_Effects_AirDestruction = FUNC(airdestruction);
	BIS_Effects_AirDestructionStage2 = FUNC(airdestructionstage2);
	BIS_Effects_Burn = FUNC(burn);
	BIS_Effects_Secondaries = FUNC(secondaries);
	BIS_Effects_Rocket = FUNC(rocket);
	BIS_Effects_SmokeLauncher = FUNC(smokelauncher);
	BIS_Effects_SmokeShell = FUNC(smokeshell);
	BIS_Effects_Cannon = FUNC(cannon);
	BIS_Effects_HeavyCaliber = FUNC(heavycaliber);
	BIS_Effects_HeavySniper = FUNC(heavysniper);
	BIS_Effects_Rifle = FUNC(rifle);
	LOG("BIS Effects Replaced");
	if (!isNil "JSRS_Distance_Killed") then {
		JSRS_Distance_Killed = {};
		//JSRS_Distance_Fired = {};
	};
};

ADDON = true;
