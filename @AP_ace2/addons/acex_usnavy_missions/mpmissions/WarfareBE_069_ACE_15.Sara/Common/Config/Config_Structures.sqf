Private ["_n"];

/* Call in dynamically the west structures. */
Call Compile PreprocessFile Format["Common\Config\Core_Structures\%1\Structures_%2.sqf",WFBE_V_West_StructuresRootVersion,WFBE_V_West_StructuresFaction];

/* Call in dynamically the east structures. */
Call Compile PreprocessFile Format["Common\Config\Core_Structures\%1\Structures_%2.sqf",WFBE_V_East_StructuresRootVersion,WFBE_V_East_StructuresFaction];

switch (true) do {
	case WF_A2_Vanilla: {
		WFDEPOT = ["WarfareBDepot"];
		WFCAMP = ["WarfareBCamp"];
		WFHANGAR = ["WarfareBAirport"];
		WFFLAG = "FlagCarrierGUE";
		
		/* RESISTANCE STATIONARY DEFENSES */
		_n			= ["GUE_WarfareBMGNest_PK"];
		_n = _n		+ ["DSHKM_Gue"];
		_n = _n		+ ["SPG9_Gue"];
		_n = _n		+ ["ZU23_Gue"];

		['WFBE_RESISTANCEDEFENSENAMES',_n,true] Call SetNamespace;

	};	case WF_A2_Arrowhead: {
		WFDEPOT = ["Land_fortified_nest_big_EP1"];
		WFCAMP = ["Land_Fort_Watchtower_EP1"];
		WFHANGAR = ["Land_Mil_hangar_EP1"];
		WFFLAG = "FlagCarrierTakistan_EP1";

		/* RESISTANCE STATIONARY DEFENSES */
		_n			= ["WarfareBMGNest_PK_TK_GUE_EP1"];
		_n = _n		+ ["DSHKM_TK_GUE_EP1"];
		_n = _n		+ ["AGS_TK_GUE_EP1"];
		_n = _n		+ ["SPG9_TK_GUE_EP1"];
		_n = _n		+ ["ZU23_TK_GUE_EP1"];
		_n = _n		+ ["D30_TK_GUE_EP1"];

		['WFBE_RESISTANCEDEFENSENAMES',_n,true] Call SetNamespace;

	};	case WF_A2_CombinedOps: {
		WFDEPOT = ["Land_fortified_nest_big_EP1","WarfareBDepot"];
		WFCAMP = ["Land_Fort_Watchtower_EP1","WarfareBCamp"];
		WFHANGAR = ["Land_Mil_hangar_EP1","WarfareBAirport"];
		WFFLAG = "FlagCarrierTakistan_EP1";
		
		/* RESISTANCE STATIONARY DEFENSES */
		_n			= ["WarfareBMGNest_PK_TK_GUE_EP1"];
		_n = _n		+ ["GUE_WarfareBMGNest_PK"];
		_n = _n		+ ["DSHKM_Gue"];
		_n = _n		+ ["SPG9_Gue"];
		_n = _n		+ ["ZU23_Gue"];
		_n = _n		+ ["DSHKM_TK_GUE_EP1"];
		_n = _n		+ ["AGS_TK_GUE_EP1"];
		_n = _n		+ ["SPG9_TK_GUE_EP1"];
		_n = _n		+ ["D30_TK_GUE_EP1"];
		_n = _n		+ ["ZU23_TK_GUE_EP1"];

		['WFBE_RESISTANCEDEFENSENAMES',_n,true] Call SetNamespace;

	};
};

//--- Multiply the building cost when money only is being used.
if (paramMoneyOnly) then {
	Private ["_i","_list"];
	
	_list = 'WFBE_WESTSTRUCTURECOSTS' Call GetNamespace;
	for '_i' from 0 to count(_list)-1 do {
		_list set [_i, round((_list select _i) * 5)];
	};

	_list = 'WFBE_EASTSTRUCTURECOSTS' Call GetNamespace;
	for '_i' from 0 to count(_list)-1 do {
		_list set [_i, round((_list select _i) * 5)];
	};
};

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Structures: Initialization (West: %3 | East: %4) - [Done]",diag_frameno,diag_tickTime,WFBE_V_West_StructuresFaction,WFBE_V_East_StructuresFaction];