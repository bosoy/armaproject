
private ["_enable","_exited"];
MenuAction = -1;

while {alive player && dialog} do {
	//--- Command AI.
	_enable = false;
	if (!isNull(commanderTeam)) then {if (commanderTeam == group player) then {_enable = true}};
	ctrlEnable [13001,_enable]; //--- Team Orders
	ctrlEnable [13004,_enable]; //--- Commander Menu
	ctrlEnable [13002,commandInRange]; //--- Special Menu
	ctrlEnable [13003,commandInRange]; //--- Upgrade Menu
	
	sleep 0.1;
	
	if (side player != sideJoined) exitWith {closeDialog 0};
	if !(dialog) exitWith {};
	
	//--- Command AI.
	if (MenuAction == 1) exitWith {
		MenuAction = -1;
		CloseDialog 0;
		CreateDialog "RscOrderMenu";
	};
	
	//--- Artillery Menu.
	if (MenuAction == 2) exitWith {
		MenuAction = -1;
		CloseDialog 0;
		CreateDialog "RscArtilleryMenu";
	};

	//--- Upgrade Menu.
	if (MenuAction == 3) exitWith {
		MenuAction = -1;
		CloseDialog 0;
		CreateDialog "RscUpgradeMenu";
	};	
	
	//--- Commander Menu.
	if (MenuAction == 4) exitWith {
		MenuAction = -1;
		CloseDialog 0;
		CreateDialog "RscCommanderMenu";
	};

	//--- Support Menu.
	if (MenuAction == 5) exitWith {
		MenuAction = -1;
		CloseDialog 0;
		CreateDialog "RscSupportMenu";
	};
};