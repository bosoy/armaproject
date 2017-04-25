// by Xeno
#define THIS_FILE "x_missionsetup.sqf"
#include "x_setup.sqf"

// I'm using x_mXX.sqf for the mission filename where XX (index number) has to be added to GVAR(sm_array)
GVAR(mission_filename) = "x_m";

// GVAR(sm_array) contains the indices of the sidemissions (it gets shuffled later)
// to remove a specific side mission just remove the index from GVAR(sm_array)
#ifdef __DEFAULT__
GVAR(sm_array) = switch (true) do {
	case (__OAVer): {[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,36,40,41,42,44,46,47,49,50,51,52]};
	case (__COVer): {[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,36,37,38,39,40,41,42,44,45,46,47,48,49,50,51,52]};
};

if (__OAVer) then {
	if (GVAR(enemy_side) == "WEST") then {
		GVAR(sm_array) = GVAR(sm_array) - [7,11];
	};
};

if (!isNil QGVAR(with_carrier)) then {GVAR(sm_array) = GVAR(sm_array) - [3]};

if (GVAR(FastTime) > 0) then {GVAR(sm_array) = GVAR(sm_array) - [51,52]};
#endif
#ifdef __TT__
GVAR(sm_array) = switch (true) do {
	case (__OAVer): {[0,1,2,3,4,5,6,7,8,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,36,40,42,44,46,47]};
	case (__COVer): {[0,1,3,4,5,6,7,8,10,11,12,13,14,15,16,18,19,20,21,22,23,24,25,26,27,28,29,31,32,33,34,36,37,38,39,40,41,42,45,46,47,48,49,50]};
};
#endif

GVAR(number_side_missions) = count GVAR(sm_array);

// just for debugging
// it will create markers at each sidemission position
#ifdef __SMMISSIONS_MARKER__
0 spawn {
	sleep 1;
	{
		_ffolder = switch (true) do {
			case (__OAVer): {"moa"};
			case (__COVer): {"m"};
		};
		_mfolder = "x_missions\" + _ffolder + "\%2%1.sqf";
		[1,1] call compile preprocessFileLineNumbers (format [_mfolder, _x, GVAR(mission_filename)]);
		_start_pos = GVAR(x_sm_pos) select 0;
		_name = format [(localize "STR_DOM_MISSIONSTRING_711"), _x];
		_marker= createMarkerLocal [_name, _start_pos];
		_marker setMarkerTypeLocal "DOT";
		_name setMarkerColorLocal "ColorBlack";
		_name setMarkerSizeLocal [0.2,0.2];
		_name setMarkerTextLocal _name;
		diag_log [_name, GVAR(x_sm_pos)];
	} forEach GVAR(sm_array);
};
#endif

if (isServer) then {
	FUNC(CheckSMShotHD) = {
		if ((toUpper(getText(configFile >> "CfgAmmo" >> (_this select 4) >> "simulation")) in GVAR(hd_sim_types)) || ((_this select 4) == "ACE_PipebombExplosion")) then {
			_this select 2
		} else {
			0
		}
	};
	
	FUNC(KilledSMTargetNormal) = {
		private ["_dvec", "_killer"];
		PARAMS_2(_dvec,_killer);
		if !(_dev isKindOf "CAManBase") then {
			__addDead(_dvec)
		};
		if (!isNull _killer && _killer != _dvec) then {
			GVAR(side_mission_winner) = if (side (group _killer) == GVAR(side_player)) then {2} else {-1};
		} else {
			GVAR(side_mission_winner) = -1;
		};
		GVAR(side_mission_resolved) = true;
	};
#ifdef __TT__
	FUNC(KilledSMTargetTT) = {
		private ["_dvec", "_killer"];
		PARAMS_2(_dvec,_killer);
		if !(_dvec isKindOf "CAManBase") then {
			__addDead(_dvec)
		};
		if (!isNull _killer && _killer != _dvec) then {
			GVAR(side_mission_winner) = switch (side (group _killer)) do {case east:{1}; case west:{2}; default{-1};};
		} else {
			GVAR(side_mission_winner) = -1;
		};
		GVAR(side_mission_resolved) = true;
	};
	
	FUNC(AddSMPoints) = {
		switch (side (group (_this select 1))) do {case west: {__INC(GVAR(sm_points_west))};case east: {__INC(GVAR(sm_points_east))}};
	};
#endif
	FUNC(KilledSMTarget500) = {
		GVAR(side_mission_winner) = -500;
		GVAR(side_mission_resolved) = true;
	};
	
	// these vehicles get spawned in a convoy sidemission. Be aware that it is the best to use a wheeled vehicle first as leader.
	// at least wheeled AI vehicles try to stay on the road somehow
#ifdef __CO__
	GVAR(sm_convoy_vehicles) = switch (GVAR(enemy_side)) do {
		case "EAST": {["BTR90","BMP3", "2S6M_Tunguska", "KamazRepair", "KamazRefuel", "KamazReammo", "T90"]};
		case "WEST": {["LAV25","AAV", "HMMWV_Avenger", "MtvrRepair", "MtvrRefuel", "MtvrReammo", "M1A2_TUSK_MG"]};
		case "GUER": {["BRDM2_Gue","BMP2_Gue", "Ural_ZU23_Gue", "V3S_Gue", "V3S_Gue", "V3S_Gue", "T72_Gue"]};
	};
#endif
#ifdef __OA__
	GVAR(sm_convoy_vehicles) = switch (GVAR(enemy_side)) do {
		case "EAST": {["BTR60_TK_EP1","BMP2_TK_EP1", "ZSU_TK_EP1", GVAR(rep_truck_east), "UralRefuel_TK_EP1", "UralReammo_TK_EP1", "T72_TK_EP1"]};
		case "WEST": {["M1126_ICV_M2_EP1","M2A3_EP1", "M6_EP1", GVAR(rep_truck_west), "MtvrRefuel_DES_EP1", "MtvrReammo_DES_EP1", "M1A2_US_TUSK_MG_EP1"]};
		case "GUER": {["BTR40_MG_TK_GUE_EP1","BRDM2_TK_GUE_EP1", "Ural_ZU23_TK_GUE_EP1", "V3S_Repair_TK_GUE_EP1", "V3S_Refuel_TK_GUE_EP1", "V3S_Reammo_TK_GUE_EP1", "T55_TK_GUE_EP1"]};
	};
#endif
};

// Instead of a random vehicle chosen for winning a side mission you can setup it in the mission yourself now
// Add GVAR(current_sm_bonus_vec) to the beginning of a sidemission script with a vehicle class string and that vehicle gets chosen instead of a random one.
// Examples:
// GVAR(current_sm_bonus_vec) = "M1A1_US_DES_EP1";
// TT (first west then east):
// GVAR(current_sm_bonus_vec) = ["M1A1_US_DES_EP1", "T72_TK_EP1"];
// DON'T CHANGE IT HERE IN X_MISSIONSETUP.SQF!!!!!!!!!!!!!!!!!!!!!!!!!
if (isServer) then {
	#ifndef __TT__
	GVAR(current_sm_bonus_vec) = "";
	#else
	GVAR(current_sm_bonus_vec) = ["",""];
	#endif
};