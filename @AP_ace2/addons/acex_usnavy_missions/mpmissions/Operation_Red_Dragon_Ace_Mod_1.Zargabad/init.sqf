if(!isServer) then {waitUntil{!isNull player}};
DAC_Zone = compile preprocessFile "DAC\Scripts\DAC_Init_Zone.sqf";
DAC_Objects	= compile preprocessFile "DAC\Scripts\DAC_Create_Objects.sqf";
execVM "DAC\DAC_Config_Creator.sqf";

ASfirstrun = true;

execVM "bon_recruit_units\init.sqf";


// START OF COIN SETTINGS
myMoney = 5000;

myCoin setvariable ["BIS_COIN_name","Base"];
myCoin setvariable ["BIS_COIN_rules",[player]];
myCoin setvariable ["BIS_COIN_areasize",[5000,5000]];
myCoin setvariable ["BIS_COIN_categories",["Base", "Defence", "Sandbag Barriers", "Fortifications", "Ammunition Crates", "Other"]];
myCoin setvariable ["BIS_COIN_items",
	[
		//--- Class, Category, Cost or [fundsID,Cost], (display name)
		["WarfareBCamp","Base",300,"Barracks"],
		["MASH","Base",200],
		["LAV25_HQ_unfolded","Base",400],
		["WarfareBMGNest_M240_US_EP1","Defence",100],
                ["USMC_WarfareBUAVterminal","Defence",100],
                ["Land_Antenna","Defence",100],
                ["WarfareBCamp","Defence",100],
                ["Land_fortified_nest_big","Fortifications",100],
                ["Fort_EnvelopeSmall_EP1","Fortifications",100],
                ["Land_fortified_nest_small","Fortifications",100],
                ["Land_Fort_Watchtower","Fortifications",100],
                ["Land_fort_bagfence_long","Sandbag Barriers",100],
                ["Land_fort_bagfence_corner","Sandbag Barriers",100],
                ["Land_fort_bagfence_round","Sandbag Barriers",100],
                ["Fort_RazorWire","Sandbag Barriers",100],
                ["USBasicAmmunitionBox","Ammunition Crates",10],
                ["USLaunchersBox","Ammunition Crates",10],
                ["USOrdnanceBox","Ammunition Crates",10],
                ["USBasicWeaponsBox","Ammunition Crates",10],
                ["HeliH","Other",10],
                ["Land_CamoNet_NATO","Other",10],
                ["Land_CamoNetVar_NATO","Other",10],
                ["Land_CamoNetB_NATO","Other",10]
	]
];
myCoin setvariable ["BIS_COIN_funds",["myMoney"]];
myCoin setvariable ["BIS_COIN_fundsDescription",["$"]];
myCoin setvariable ["BIS_COIN_onPurchase",{sleep 2}];
// END OF COIN SETTINGS

_done = [];
myCoin setvariable ["BIS_COIN_funds",["myMoney"]];
myCoin setvariable ["BIS_COIN_fundsDescription",["$"]];
myCoin setvariable ["BIS_COIN_onPurchase",{sleep 2}];
// END OF COIN SETTINGS

_done = [];