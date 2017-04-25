#ifdef __ACE__
// override for ACE. ACE 2 has it's own backpack/ruck feature
GVAR(WithBackpack) = false;

if (GVAR(WithWounds) == 0) then {
	if (isServer) then {
		ace_sys_wounds_enabled = true; publicVariable "ace_sys_wounds_enabled";
	};
	
	if (GVAR(wounds_no_ai) == 1) then {ace_sys_wounds_noai = true};
	
	ACE_IFAK_Capacity = GVAR(IFAK_Capacity);
	
	if (!isDedicated) then {
		if (GVAR(no_rpunish) == 0) then {
			ace_sys_wounds_no_rpunish = true;
		};
	};
};
if (GVAR(ace_vec_weaponcheck) != 0) then {
	if (isNil "ace_sys_eject_fnc_weaponCheckEnabled") then {
		[] spawn {
			waitUntil {!isNil "ace_sys_eject_fnc_weaponCheckEnabled"};
			ace_sys_eject_fnc_weaponCheckEnabled = {false};
		};
	} else {
		ace_sys_eject_fnc_weaponCheckEnabled = {false};
	};
};
#endif

setViewDistance GVAR(InitialViewDistance);

if (GVAR(WithAcre)) then {
	[GVAR(AcreSignalLoss) / 100] call acre_api_fnc_setLossModelScale; // there is /100 as conversion from %, because propper value is from 0.0 to 1.0, but "description.ext" does not support float numbers, so value in params is percentual
	if (GVAR(AcreRadioOnBackWorks) == 1) then {
		["onBack", true] call acre_api_fnc_toggleAceFeatureCompat
	};
};

// this will remove setVehicleInits in BIS effects and should fix sky in fire bug
// probably breaks addons like WarFX, dunno, I'm not using it
#ifndef __ACE__
if (GVAR(OverrideBISEffects) == 0) then {
	0 spawn {
		sleep 0.2;
		waitUntil {!isNil "BIS_Effects_Secondaries"};
		sleep 0.5;
		GVAR(BISsecondaries) = [];
		__cppfln(BIS_Effects_EH_Killed,BIS_Effects\killed.sqf);
		__cppfln(BIS_Effects_AirDestruction,BIS_Effects\airdestruction.sqf);
		__cppfln(BIS_Effects_AirDestructionStage2,BIS_Effects\airdestructionstage2.sqf);
		__cppfln(BIS_Effects_Burn,BIS_Effects\burn.sqf);
		__cppfln(BIS_Effects_Secondaries,BIS_Effects\secondaries.sqf);
		// one script handles secondary explosions of all vehicles now instead of one script per vehicle
		execVM "BIS_Effects\secondaryloop.sqf";
		sleep 0.5;
		if (!isNil "JSRS_Distance_Killed") then {
			JSRS_Distance_Killed = {};
			//JSRS_Distance_Fired = {};
		};
	};
};
#endif

GVAR(number_targets_h) = GVAR(MainTargets);

if (GVAR(MainTargets) >= 50) then {
	_h = switch (GVAR(MainTargets)) do {
		case 50: {7};
		case 60: {5};
		case 70: {8};
		case 90: {21};
	};
	GVAR(MainTargets) = _h;
};

if (GVAR(GrasAtStart) == 1) then {setterraingrid 50};

if (isServer) then {skiptime GVAR(TimeOfDay)};

// WEST, EAST or GUER for own side, setup in x_setup.sqf
#ifdef __OWN_SIDE_WEST__
GVAR(own_side) = "WEST";
GVAR(enemy_side) = "EAST";
#endif
#ifdef __OWN_SIDE_EAST__
GVAR(own_side) = "EAST";
GVAR(enemy_side) = "WEST";
#endif
#ifdef __OWN_SIDE_GUER__
GVAR(own_side) = "GUER";
GVAR(enemy_side) = "EAST";
#endif
#ifdef __TT__
GVAR(enemy_side) = "GUER";
GVAR(own_side) = "WEST";
#endif

// setup in x_setup.sqf
GVAR(version) = [];
#define __adddv(dtype) GVAR(version) set [count GVAR(version), #dtype]
#ifdef __OA__
__adddv(OA);
GVAR(COVer) = false;
#endif
#ifdef __CO__
__adddv(CO);
GVAR(COVer) = true;
#endif
if (GVAR(with_ai)) then {__adddv(AI)};
#ifdef __TT__
__adddv(TT);
#endif
#ifdef __ACE__
__adddv(ACE);
if (GVAR(WithWounds) == 0) then {
	__adddv(WOUNDS);
	GVAR(WithRevive) = 1;
};
#endif
if (GVAR(with_ranked)) then {__adddv(RANKED)};
if (GVAR(WithRevive) == 0) then {__adddv(REVIVE)};

#ifdef __ACE__
if (GVAR(WithWounds) == 0) then {
	ace_sys_wounds_enabled = true; publicVariable "ace_sys_wounds_enabled";
	if (GVAR(wounds_no_ai) == 1) then {ace_sys_wounds_noai = true};
} else {
	ace_w_no_handledamage = true;
	publicVariable "ace_w_no_handledamage";
	if (!isDedicated) then {
		0 spawn {
			waitUntil {!isNull player};
			_eh = __pGetVar(ace_w_eh);
			if (!isNil "_eh") then {
				player removeEventHandler ["handleDamage", _eh];
			};
			player setVariable ["ace_w_eh", 0];
		};
		0 spawn {
			waitUntil {!isNil "ace_w_setunitdam"};
			ace_w_setunitdam = {};
		};
	};
};
#endif

if (!GVAR(dom4)) then {
	GVAR(last_target_idx) = -1;
	GVAR(target_names) = [];
	for "_i" from 0 to 100000 do {
		_ar = [];
		_mname = format [QGVAR(target_%1), _i];
		_dtar = __getMNsVar2(_mname);
		if (isNil "_dtar") exitWith {
			GVAR(last_target_idx) = _i - 1;
		};
		_dtar enableSimulation false;
		
		// please be aware that DOM4only targets must follow after DOM2 targets.
		// you can't mix them
		// means, you can't have d_target_2 and d_target_4 DOM2only and d_target_3 DOM4only
		_check = GV(_dtar,GVAR(dom4only));
		if (isNil "_check") then {		
			_name = GV(_dtar,GVAR(cityname));
			if (!isNil "_name") then {
				_pos = getPosASL _dtar;
				_pos set [2, 0];
				_ar set [count _ar, _pos]; // position CityCenter by logic
				if (isServer) then {
					_dtar setDir 0;
				};
				_ar set [count _ar, _name]; // name village/city
				_radius = GV(_dtar,GVAR(cityradius));
				_ar set [count _ar, if (isNil "_radius") then {300} else {_radius}];
			} else {
				_nlocs = nearestLocations [getPosASL _dtar, ["NameCityCapital","NameCity","NameVillage"], 1000];
				if (count _nlocs > 0) then {
					_nl = nearestLocations [locationPosition (_nlocs select 0), ["CityCenter"], 1000];
					_pos = if (count _nl > 0) then {
						locationPosition (_nl select 0)
					} else {
						locationPosition (_nlocs select 0)
					};
					_pos set [2, 0];
					_ar set [count _ar, _pos]; // position CityCenter
					if (isServer) then {
						_dtar setDir 0;
						_dtar setPos _pos;
					};
					_name = text (_nlocs select 0);
					_ar set [count _ar, _name]; // name village/city
					_radius = GV(_dtar,GVAR(cityradius));
					_ar set [count _ar, if (isNil "_radius") then {300} else {_radius}];
					_dtar setVariable [QGVAR(cityname), _name];
				} else {
					hint ("No city found near target location " + _mname);
				};
			};
		};
		__TRACE_1("All targets found","_ar")
		GVAR(target_names) set [count GVAR(target_names), _ar];
	};
} else {
#include "x_buildtargets.sqf"
};

#ifdef __DEBUG__
// only for debugging, creates markers at all main target positions
// {
	// _pos = _x select 0;
	// _name = _x select 1;
	// _size = _x select 2;
	// _marker= createMarkerLocal [_name, _pos];
	// _marker setMarkerShapeLocal "ELLIPSE";
	// _name setMarkerColorLocal "ColorGreen";
	// _name setMarkerSizeLocal [_size,_size];
	// _name = _name + "xx";
	// _marker= createMarkerLocal [_name, _pos];
	// _marker setMarkerTypeLocal "mil_dot";
	// _name setMarkerColorLocal "ColorBlack";
	// _name setMarkerSizeLocal [0.5,0.5];
	// _name setMarkerTextLocal _name;
// } forEach GVAR(target_names);
#endif

GVAR(side_enemy) = switch (GVAR(enemy_side)) do {
	case "EAST": {east};
	case "WEST": {west};
	case "GUER": {resistance};
};

GVAR(side_player) =
#ifdef __OWN_SIDE_EAST__
	east;
#endif
#ifdef __OWN_SIDE_WEST__
	west;
#endif
#ifdef __OWN_SIDE_GUER__
	resistance;
#endif
#ifdef __TT__
	west;
#endif

GVAR(side_player_str) =
#ifdef __OWN_SIDE_EAST__
	"east";
#endif
#ifdef __OWN_SIDE_WEST__
	"west";
#endif
#ifdef __OWN_SIDE_GUER__
	"guerrila";
#endif
#ifdef __TT__
	"west";
#endif

GVAR(own_side_trigger) =
#ifdef __OWN_SIDE_EAST__
	"EAST";
#endif
#ifdef __OWN_SIDE_WEST__
	"WEST";
#endif
#ifdef __OWN_SIDE_GUER__
	"GUER";
#endif
#ifdef __TT__
	"WEST";
#endif

GVAR(ai_enemy_sides) =
#ifdef __OWN_SIDE_EAST__
	[west];
#endif
#ifdef __OWN_SIDE_WEST__
	[east];
#endif
#ifdef __OWN_SIDE_GUER__
	[east];
#endif
#ifdef __TT__
	[east,west];
#endif

#ifdef __OA__
GVAR(rep_truck_west) = "MtvrRepair_DES_EP1";
GVAR(rep_truck_east) = "UralRepair_TK_EP1";
#endif
#ifdef __CO__
GVAR(rep_truck_west) = "MtvrRepair";
GVAR(rep_truck_east) = "KamazRepair";
#endif

#ifndef __TT__
GVAR(rep_truck) = if (GVAR(enemy_side) == "EAST") then {GVAR(rep_truck_west)} else {GVAR(rep_truck_east)};
#endif

GVAR(version_string) =
#ifdef __OWN_SIDE_EAST__
	"East";
#endif
#ifdef __OWN_SIDE_WEST__
	"West";
#endif
#ifdef __OWN_SIDE_GUER__
	"Guer";
#endif
#ifdef __TT__
	"Two Teams";
#endif

//default flag GUER
#ifdef __OWN_SIDE_WEST__
GVAR(FLAG_BASE) setflagtexture (if !(GVAR(COVer)) then {"\ca\Ca_E\data\flag_us_co.paa"} else {"\ca\data\flag_usa_co.paa"});
#endif
#ifdef __OWN_SIDE_EAST__
switch (true) do {
	case (__OAVer): {GVAR(FLAG_BASE) setflagtexture "\ca\Ca_E\data\flag_tka_co.paa"};
	case (__COVer): {GVAR(FLAG_BASE) setflagtexture "\ca\data\flag_rus_co.paa"};
};
#endif

if (GVAR(with_mgnest)) then {
	GVAR(mg_nest) = 
#ifdef __OWN_SIDE_GUER__
	"GUE_WarfareBMGNest_PK";
#endif
#ifdef __OWN_SIDE_EAST__
	switch (true) do {
		case (__OAVer): {"WarfareBMGNest_PK_TK_EP1"};
		case (__COVer): {"RU_WarfareBMGNest_PK"};
	};
#endif
#ifdef __OWN_SIDE_WEST__
	switch (true) do {
		case (__OAVer): {"WarfareBMGNest_M240_US_EP1"};
		case (__COVer): {"USMC_WarfareBMGNest_M240"};
	};
#endif
#ifdef __TT__
	"";
#endif
};

GVAR(sm_bonus_vehicle_array) = (
#ifdef __DEFAULT__
	switch (GVAR(own_side)) do {
		case "GUER": {["A10","AH1Z","UH1Y","AV8B","AV8B2", "F35B", "M1A2_TUSK_MG","M1A1"]};
		case "WEST": {
			switch (true) do {
				case (__OAVer): {
					if (__ACEVer) then {
						["A10_US_EP1","AH64D_EP1","AH6J_EP1","M1A1_US_DES_EP1","M1A2_US_TUSK_MG_EP1","M6_EP1","ACE_M1A1HC_DESERT","ACE_M1A1HC_TUSK_DESERT","ACE_M1A1HC_TUSK_CSAMM_DESERT","ACE_M1A1HA_TUSK_CSAMM_DESERT","UH60M_EP1"]
					} else {
						["A10_US_EP1","AH64D_EP1","AH6J_EP1","M1A1_US_DES_EP1","M1A2_US_TUSK_MG_EP1","M6_EP1","UH60M_EP1"]
					};
				};
				case (__ACEVer): {
					["A10","AH1Z","UH1Y","AV8B","AV8B2", "F35B", "M1A2_TUSK_MG","M1A1", "AH64D", "ACE_Stryker_MGS_Slat" ,"ACE_Stryker_TOW","ACE_Stryker_TOW_MG","ACE_AH6_GAU19","ACE_AH6","ACE_AH1W_AGM_W","ACE_AH1W_AGM_D","ACE_M2A2_W","ACE_M2A2_D","ACE_M6A1_W","ACE_M6A1_D","ACE_AH1Z_AGM_D","ACE_AH1Z_AGM_AGM_D","ACE_AH1Z_AGM_AGM_W","ACE_M1A1HC_DESERT"]
				};
				case (__COVer): {
					["A10","AH1Z","UH1Y","AV8B","AV8B2", "F35B", "M1A2_TUSK_MG","M1A1","AH64D"]
				};
			}
		};
		case "EAST": {
			switch (true) do {
				case (__OAVer): {
					["Su25_TK_EP1","L39_TK_EP1","Mi24_D_TK_EP1","T72_TK_EP1","T55_TK_EP1","ZSU_TK_EP1"]
				};
				case (__ACEVer): {
					["Su34","Ka52","Ka52Black","Mi24_P","Mi24_V","Su39","T72_RU","2S6M_Tunguska","T90","ACE_T72B_RU","ACE_T72BA_RU","ACE_Su27_CAP","ACE_Su27_CAS","ACE_Su27_CASP"]
				};
				case (__COVer): {
					["Su34","Ka52","Ka52Black","Mi24_P","Mi24_V","Su39","T72_RU","2S6M_Tunguska","T90"]
				};
			}
		};
	}
#endif
#ifdef __TT__
	switch (true) do {
		case (__OAVer): {
			[
				["A10_US_EP1","AH64D_EP1","AH6J_EP1","M1A1_US_DES_EP1","M1A2_US_TUSK_MG_EP1","M6_EP1"],
				["Su25_TK_EP1","L39_TK_EP1","Mi24_D_TK_EP1","T72_TK_EP1","T55_TK_EP1","ZSU_TK_EP1"]
			]
		};
		case (__ACEVer): {
			[
				["A10","AH1Z","UH1Y","AV8B","AV8B2", "F35B", "M1A2_TUSK_MG","M1A1", "AH64D", "ACE_Stryker_MGS_Slat" ,"ACE_Stryker_TOW","ACE_Stryker_TOW_MG","ACE_AH6_GAU19","ACE_AH6","ACE_AH1W_AGM_W","ACE_AH1W_AGM_D","ACE_M2A2_W","ACE_M2A2_D","ACE_M6A1_W","ACE_M6A1_D","ACE_AH1Z_AGM_D","ACE_AH1Z_AGM_AGM_D","ACE_AH1Z_AGM_AGM_W","ACE_M1A1HC_DESERT"],
				["Su34","Ka52","Ka52Black","Mi24_P","Mi24_V","Su39","T72_RU","2S6M_Tunguska","T90","ACE_T72B_RU","ACE_T72BA_RU","ACE_Su27_CAP","ACE_Su27_CAS","ACE_Su27_CASP"]
			]
		};
		case (__COVer): {
			[
				["A10","AH1Z","UH1Y","AV8B","AV8B2", "F35B", "M1A2_TUSK_MG","M1A1","AH64D"],
				["Su34","Ka52","Ka52Black","Mi24_P","Mi24_V","Su39","T72_RU","2S6M_Tunguska","T90"]
			]
		};
	}
#endif
);
#ifdef __DEFAULT__
if (GVAR(with_dlc)) then {
	if (GVAR(own_side) == "WEST") then {
		if (!(__ACEVer) && __OAVer) then {
			GVAR(sm_bonus_vehicle_array) = GVAR(sm_bonus_vehicle_array) + ["BAF_FV510_D","BAF_Jackal2_GMG_D","BAF_Jackal2_L2A1_D","BAF_Apache_AH1_D","AW159_Lynx_BAF","Ka60_GL_PMC","BRDM2_Desert_ACR","Dingo_DST_ACR","Dingo_GL_DST_ACR","Pandur2_ACR","L159_ACR","L39_2_ACR","Mi24_D_CZ_ACR","BMP2_Des_ACR","T72_ACR"];
		};
	};
};
#endif

GVAR(mt_bonus_vehicle_array) =
#ifdef __DEFAULT__
switch (GVAR(own_side)) do {
	case "GUER": {["BMP2_Gue","BRDM2_Gue","T34","HMMWV_M2","HMMWV_MK19","HMMWV_TOW","HMMWV_Avenger"]};
	case "WEST": {
		switch (true) do {
			case (__OAVer): {
				["M1126_ICV_M2_EP1","M1126_ICV_mk19_EP1","M1128_MGS_EP1","M1129_MC_EP1","M1135_ATGMV_EP1","M2A2_EP1","M2A3_EP1","HMMWV_M1151_M2_DES_EP1","HMMWV_M1151_M2_DES_EP1","HMMWV_M998_crows_M2_DES_EP1","HMMWV_M998_crows_MK19_DES_EP1","HMMWV_M998A2_SOV_DES_EP1","HMMWV_MK19_DES_EP1","HMMWV_TOW_DES_EP1","HMMWV_M1151_M2_CZ_DES_EP1","LandRover_Special_CZ_EP1"]
			};
			case (__ACEVer): {
				["AAV","LAV25","HMMWV_M2","HMMWV_MK19","HMMWV_TOW","HMMWV_Avenger", "ACE_Stryker_ICV_M2", "ACE_Stryker_ICV_M2_SLAT","ACE_Stryker_ICV_MK19","ACE_Stryker_ICV_MK19_SLAT","ACE_Stryker_RV","ACE_M113A3","ACE_Vulcan","ACE_HMMWV_GMV","ACE_HMMWV_GMV_MK19"]
			};
			case (__COVer): {
				["AAV","LAV25","HMMWV_M2","HMMWV_MK19","HMMWV_TOW","HMMWV_Avenger"]
			};
		};
	};
	case "EAST": {
		switch (true) do {
			case (__OAVer): {
				["BMP2_TK_EP1","BRDM2_ATGM_TK_EP1","BRDM2_TK_EP1","BTR60_TK_EP1","M113_TK_EP1","LandRover_MG_TK_EP1","LandRover_SPG9_TK_EP1","UAZ_AGS30_TK_EP1","UAZ_MG_TK_EP1","Ural_ZU23_TK_EP1"]
			};
			case (__ACEVer): {
				["BMP3","BTR90","GAZ_Vodnik","GAZ_Vodnik_HMG","UAZ_AGS30_RU","ACE_BMP2D_RU","ACE_BRDM2_ATGM_RU","ACE_BRDM2_RU","ACE_Ural_ZU23_RU","ACE_BRDM2_SA9_RU","ACE_Offroad_SPG9_INS"]
			};
			case (__COVer): {
				["BMP3","BTR90","GAZ_Vodnik","GAZ_Vodnik_HMG","UAZ_AGS30_RU"]
			};
		};
	};
};
#endif
#ifdef __TT__
switch (true) do {
	case (__OAVer): {
		[
			["M1126_ICV_M2_EP1","M1126_ICV_mk19_EP1","M1128_MGS_EP1","M1129_MC_EP1","M1135_ATGMV_EP1","M2A2_EP1","M2A3_EP1","HMMWV_M1151_M2_DES_EP1","HMMWV_M1151_M2_DES_EP1","HMMWV_M998_crows_M2_DES_EP1","HMMWV_M998_crows_MK19_DES_EP1","HMMWV_M998A2_SOV_DES_EP1","HMMWV_MK19_DES_EP1","HMMWV_TOW_DES_EP1","HMMWV_M1151_M2_CZ_DES_EP1","LandRover_Special_CZ_EP1"],
			["BMP2_TK_EP1","BRDM2_ATGM_TK_EP1","BRDM2_TK_EP1","BTR60_TK_EP1","M113_TK_EP1","LandRover_MG_TK_EP1","LandRover_SPG9_TK_EP1","UAZ_AGS30_TK_EP1","UAZ_MG_TK_EP1","Ural_ZU23_TK_EP1"]
		]
	};
	case (__ACEVer): {
		[
			["AAV","LAV25","HMMWV_M2","HMMWV_MK19","HMMWV_TOW","HMMWV_Avenger", "ACE_Stryker_ICV_M2", "ACE_Stryker_ICV_M2_SLAT","ACE_Stryker_ICV_MK19","ACE_Stryker_ICV_MK19_SLAT","ACE_Stryker_RV","ACE_M113A3","ACE_Vulcan","ACE_HMMWV_GMV","ACE_HMMWV_GMV_MK19"],
			["BMP3","BTR90","GAZ_Vodnik","GAZ_Vodnik_HMG","UAZ_AGS30_RU","ACE_BMP2D_RU","ACE_BRDM2_ATGM_RU","ACE_BRDM2_RU","ACE_Ural_ZU23_RU","ACE_BRDM2_SA9_RU","ACE_Offroad_SPG9_INS"]
		]
	};
	case (__COVer): {
		[
			["AAV","LAV25","HMMWV_M2","HMMWV_MK19","HMMWV_TOW","HMMWV_Avenger"],
			["BMP3","BTR90","GAZ_Vodnik","GAZ_Vodnik_HMG","UAZ_AGS30_RU"]
		]
	};
};
#endif
#ifdef __DEFAULT__
if (GVAR(with_dlc)) then {
	if (GVAR(own_side) == "WEST") then {
		if (!(__ACEVer) && __OAVer) then {
			GVAR(mt_bonus_vehicle_array) = GVAR(mt_bonus_vehicle_array) + ["ArmoredSUV_PMC","M1114_AGS_ACR","M1114_DSK_ACR"];
		};
	};
};
#endif

// positions for aircraft factories (if one get's destroyed you're not able to service jets/service choppers/repair wrecks)
// first jet service, second chopper service, third wreck repair

#ifndef __TT__
_mpos = markerPos QGVAR(base_jet_fac);
_mpos set [2,0];
if (str(_mpos) != "[0,0,0]") then {
	_mpos2 = markerPos QGVAR(base_chopper_fac);
	_mpos2 set [2,0];
	_mpos3 = markerPos QGVAR(base_wreck_fac);
	_mpos3 set [2,0];
	GVAR(aircraft_facs) = [[_mpos, markerDir QGVAR(base_jet_fac)],[_mpos2, markerDir QGVAR(base_chopper_fac)],[_mpos3, markerDir QGVAR(base_wreck_fac)]];
} else {
	GVAR(aircraft_facs) = [];
};
#else
GVAR(aircraft_facs) = [];
#endif

GVAR(x_drop_array) =
#ifdef __OWN_SIDE_GUER__
	switch (true) do {
		case (__ACEVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "M119"], [(localize "STR_DOM_MISSIONSTRING_19"),"HMMWV"], [(localize "STR_DOM_MISSIONSTRING_20"), "USBasicAmmunitionBox"]]
		};
		case (__OAVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "D30_TK_GUE_EP1"], [(localize "STR_DOM_MISSIONSTRING_21"),"Pickup_PK_TK_GUE_EP1"], [(localize "STR_DOM_MISSIONSTRING_20"), "USBasicAmmunitionBox"]]
		};
		case (__COVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "M119"], [(localize "STR_DOM_MISSIONSTRING_19"),"HMMWV"], [(localize "STR_DOM_MISSIONSTRING_20"), "USBasicAmmunitionBox"]]
		};
	};
#endif
#ifdef __OWN_SIDE_WEST__
	switch (true) do {
		case (__ACEVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "M119"], [(localize "STR_DOM_MISSIONSTRING_19"),"HMMWV"], [(localize "STR_DOM_MISSIONSTRING_20"), "USBasicAmmunitionBox"]]
		};
		case (__OAVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "M119_US_EP1"], [(localize "STR_DOM_MISSIONSTRING_19"),"HMMWV_M1035_DES_EP1"], [(localize "STR_DOM_MISSIONSTRING_20"), "USBasicAmmunitionBox_EP1"]]
		};
		case (__COVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "M119"], [(localize "STR_DOM_MISSIONSTRING_19"),"HMMWV"], [(localize "STR_DOM_MISSIONSTRING_20"), "USBasicAmmunitionBox"]]
		};
	};
#endif
#ifdef __OWN_SIDE_EAST__
	switch (true) do {
		case (__ACEVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "D30_RU"], [(localize "STR_DOM_MISSIONSTRING_22"),"UAZ_RU"], [(localize "STR_DOM_MISSIONSTRING_20"), "RUBasicAmmunitionBox"]]
		};
		case (__OAVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "D30_TK_EP1"], [(localize "STR_DOM_MISSIONSTRING_22"),"UAZ_Unarmed_TK_EP1"], [(localize "STR_DOM_MISSIONSTRING_20"), "TKBasicAmmunitionBox_EP1"]]
		};
		case (__COVer): {
			[[(localize "STR_DOM_MISSIONSTRING_18"), "D30_RU"], [(localize "STR_DOM_MISSIONSTRING_22"),"UAZ_RU"], [(localize "STR_DOM_MISSIONSTRING_20"), "RUBasicAmmunitionBox"]]
		};
	};
#endif
#ifdef __TT__
	[[(localize "STR_DOM_MISSIONSTRING_18"), "M119"], [(localize "STR_DOM_MISSIONSTRING_19"),"HMMWV"], [(localize "STR_DOM_MISSIONSTRING_20"), "USBasicAmmunitionBox"]];
#endif

// side of the pilot that will fly the drop air vehicle
GVAR(drop_side) = GVAR(own_side);

#ifndef __TT__
for "_i" from 0 to (count GVAR(sm_bonus_vehicle_array) - 1) do {
	GVAR(sm_bonus_vehicle_array) set [_i, toUpper(GVAR(sm_bonus_vehicle_array) select _i)];
};
for "_i" from 0 to (count GVAR(mt_bonus_vehicle_array) - 1) do {
	GVAR(mt_bonus_vehicle_array) set [_i, toUpper(GVAR(mt_bonus_vehicle_array) select _i)];
};
#else
for "_i" from 0 to (count (GVAR(sm_bonus_vehicle_array) select 0) - 1) do {
	(GVAR(sm_bonus_vehicle_array) select 0) set [_i, toUpper((GVAR(sm_bonus_vehicle_array) select 0) select _i)];
};
for "_i" from 0 to (count (GVAR(sm_bonus_vehicle_array) select 1) - 1) do {
	(GVAR(sm_bonus_vehicle_array) select 1) set [_i, toUpper((GVAR(sm_bonus_vehicle_array) select 1) select _i)];
};
for "_i" from 0 to (count (GVAR(mt_bonus_vehicle_array) select 0) - 1) do {
	(GVAR(mt_bonus_vehicle_array) select 0) set [_i, toUpper((GVAR(mt_bonus_vehicle_array) select 0) select _i)];
};
for "_i" from 0 to (count (GVAR(mt_bonus_vehicle_array) select 1) - 1) do {
	(GVAR(mt_bonus_vehicle_array) select 1) set [_i, toUpper((GVAR(mt_bonus_vehicle_array) select 1) select _i)];
};
#endif

// these vehicles can be lifted by the wreck lift chopper (previous chopper 4), but only, if they are completely destroyed
#ifndef __TT__
GVAR(heli_wreck_lift_types) = GVAR(sm_bonus_vehicle_array) + GVAR(mt_bonus_vehicle_array);
#else
GVAR(heli_wreck_lift_types) = (GVAR(sm_bonus_vehicle_array) select 0) + (GVAR(sm_bonus_vehicle_array) select 1) + (GVAR(mt_bonus_vehicle_array) select 0) + (GVAR(mt_bonus_vehicle_array) select 1);
#endif
{GVAR(heli_wreck_lift_types) set [_forEachIndex, toUpper _x]} forEach GVAR(heli_wreck_lift_types);

// internal
GVAR(next_jump_time) = -1;

// d_jumpflag_vec = empty ("") means normal jump flags for HALO jump get created
// if you add a vehicle typename to d_jumpflag_vec (d_jumpflag_vec = "UAZ"; for example) only a vehicle gets created and no HALO jump is available
GVAR(jumpflag_vec) = "";

// internal
GVAR(side_mission_winner) = 0;
GVAR(objectID1) = objNull;
GVAR(objectID2) = objNull;

if (isServer) then {
	MEDIC_TENT1 addEventHandler ["handleDamage", {0}];
	AMMOBUILDING addEventHandler ["handleDamage", {0}];
	MEDIC_TENT2 addEventHandler ["handleDamage", {0}];
	#ifndef __TT__
	WALL1 addEventHandler ["handleDamage", {0}];
	WALL2 addEventHandler ["handleDamage", {0}];
	WALL3 addEventHandler ["handleDamage", {0}];
	#else
	AMMOBUILDING2 addEventHandler ["handleDamage", {0}];
	#endif
};

#ifndef __TT__
GVAR(player_entities) =  switch (true) do {
	case (__OAVer): {
		["RESCUE","RESCUE2","alpha_1","alpha_2","alpha_3","alpha_4","alpha_5","alpha_6","alpha_7","alpha_8","bravo_1","bravo_2","bravo_3","bravo_4","bravo_5","bravo_6","bravo_7","bravo_8","charlie_1","charlie_2","charlie_3","charlie_4","charlie_5","charlie_6","charlie_7","charlie_8","delta_1","delta_2","delta_3","delta_4","delta_5","delta_6","echo_1","echo_2","echo_3","echo_4","echo_5","echo_6","echo_7","echo_8"]
	};
	case (__ACEVer): {
		["RESCUE","RESCUE2","alpha_1","alpha_2","alpha_3","alpha_4","alpha_5","alpha_6","alpha_7","alpha_8","bravo_1","bravo_2","bravo_4","bravo_5","bravo_6","bravo_7","bravo_8","charlie_1","charlie_2","charlie_4","charlie_5","charlie_6","charlie_7","charlie_8","delta_1","delta_2","delta_3","delta_4","delta_5","echo_1","echo_2","echo_4","echo_5","echo_6","echo_7","echo_8","pilot_1","pilot_2","pilot_3","pilot_4"]
	};
	case (__COVer): {
		["RESCUE","RESCUE2","alpha_1","alpha_2","alpha_3","alpha_4","alpha_5","alpha_6","alpha_7","alpha_8","bravo_1","bravo_2","bravo_3","bravo_4","bravo_5","bravo_6","bravo_7","bravo_8","charlie_1","charlie_2","charlie_3","charlie_4","charlie_5","charlie_6","charlie_7","charlie_8","delta_1","delta_2","delta_3","delta_4","delta_5","delta_6","echo_1","echo_2","echo_3","echo_4","echo_5","echo_6","echo_7","echo_8"]
	};
};
#else
GVAR(entities_tt_west) = ["RESCUE","west_1","west_2","west_3","west_4","west_5","west_6","west_7","west_8","west_9","west_10","west_11","west_12","west_13","west_14","west_15","west_16","west_17","west_18","west_19"];
GVAR(entities_tt_east) = ["RESCUE2","east_1","east_2","east_3","east_4","east_5","east_6","east_7","east_8","east_9","east_10","east_11","east_12","east_13","east_14","east_15","east_16","east_17","east_18","east_19"];
#endif
if (!isDedicated) then {
	GVAR(player_roles) = switch (true) do {
		case (__OAVer): {
			["PLT LD","PLT SGT","SL","SN","MG","AT","GL","CM","AR","AM","TL","OP","GL","MG","MM","CM","GL","DS","SL","SN","AR","AT","RM","CM","MG","AT","EN","EN","EN","EN","EN","EN","SL","SN","AR","AT","RM","CM","MG","AT"]
		};
		case (__ACEVer): {
			["PLT LD","PLT SGT","SL","SN","MG","AT","GL","CM","AR","AM","TL","OP","MG","MM","CM","GL","DS","SL","SN","AR","AT","RM","CM","AT","EN","EN","EN","EN","EN","SL","SN","AT","RM","CM","MG","AT","PL","PL","PL","PL"]
		};
		case (__COVer): {
			["PLT LD","PLT SGT","SL","SN","MG","AT","GL","CM","AR","AM","TL","OP","GL","MG","MM","CM","GL","DS","SL","SN","AR","AT","RM","CM","MG","AT","EN","EN","EN","EN","EN","EN","SL","SN","AR","AT","RM","CM","MG","AT"]
		};
	};
};

// position base, a,b, for the enemy at base trigger and marker
#ifdef __DEFAULT__
_mpos = markerPos QGVAR(base_marker);
_mpos set [2,0];
_hasbasemarker = str(_mpos) != "[0,0,0]";
QGVAR(base_marker) setMarkerAlphaLocal 0;
_msize = markerSize QGVAR(base_marker);
GVAR(base_array) =[_mpos, _msize select 0, _msize select 1, markerDir QGVAR(base_marker)];
#endif
#ifdef __TT__
_mpos = markerPos QGVAR(base_marker_w);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(base_marker_e);
_mpos2 set [2,0];
_hasbasemarker = (str(_mpos) != "[0,0,0]") && (str(_mpos2) != "[0,0,0]");
QGVAR(base_marker_w) setMarkerAlphaLocal 0;
QGVAR(base_marker_e) setMarkerAlphaLocal 0;
_msize = markerSize QGVAR(base_marker_w);
_msize2 = markerSize QGVAR(base_marker_e);
GVAR(base_array) = [
	[_mpos, _msize select 0, _msize select 1, markerDir QGVAR(base_marker_w)], // West
	[_mpos2, _msize2 select 0, _msize2 select 1, markerDir QGVAR(base_marker_e)] // East
];
#endif

#ifdef __TT__
GVAR(tt_points) = [
	30, // points for the main target winner team
	7, // points if draw (main target)
	15, // points for destroying main target radio tower
	5, // points for main target mission
	10, // points for sidemission
	5, // points for capturing a camp (main target)
	10, // points that get subtracted when loosing a mt camp again
	4, // points for destroying a vehicle of the other team
	2 // points for killing a member of the other team
];
#endif

// position of radar and anti air at own base
#ifdef __DEFAULT__
_mpos = markerPos QGVAR(base_radar_pos);
_mpos set [2,0];
GVAR(base_radar_pos) = _mpos;
_mpos = markerPos QGVAR(base_anti_air1);
_mpos set [2,0];
GVAR(base_anti_air1) = _mpos;
_mpos = markerPos QGVAR(base_anti_air2);
_mpos set [2,0];
GVAR(base_anti_air2) = _mpos;
#endif

QGVAR(isledefense_marker) setMarkerAlphaLocal 0;

if (GVAR(sub_kill_points) != 0) then {
	GVAR(sub_kill_points) = GVAR(sub_kill_points) * -1;
};

#ifdef __OA__
GVAR(WarfareAircraftFactory_East) = "TK_WarfareBAircraftFactory_EP1";
GVAR(WarfareAircraftFactory_West) = "US_WarfareBAircraftFactory_EP1";
GVAR(WarfareAircraftFactory_Guer) = "TK_GUE_WarfareBAircraftFactory_EP1";
#endif
#ifdef __CO__
GVAR(WarfareAircraftFactory_East) = "RU_WarfareBAircraftFactory";
GVAR(WarfareAircraftFactory_West) = "USMC_WarfareBAircraftFactory";
GVAR(WarfareAircraftFactory_Guer) = "GUE_WarfareBAircraftFactory";
#endif

#ifdef __OA__
GVAR(illum_tower) = "Land_Ind_IlluminantTower";
GVAR(wcamp) = "Land_fortified_nest_big_EP1";
#endif
#ifdef __CO__
GVAR(illum_tower) = "Land_telek1";
GVAR(wcamp) = "WarfareBCamp";
#endif

#ifdef __OA__
GVAR(ProtectionZone) = "ProtectionZone_Ep1";
#endif
#ifdef __CO__
GVAR(ProtectionZone) = "ProtectionZone_Ep1";
#endif

GVAR(mash) =
#ifdef __CO__
"Mash";
#endif
#ifdef __OA__
"MASH_EP1";
#endif

GVAR(dropped_box_marker) = "mil_marker";