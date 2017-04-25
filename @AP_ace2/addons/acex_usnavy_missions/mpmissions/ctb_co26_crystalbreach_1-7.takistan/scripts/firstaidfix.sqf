if (isserver) then {
	BIS_FA_MPFixArray = [];
	publicVariable "BIS_FA_MPFixArray"; // init across network
};

waituntil {not isnull player}; //ensure JIP

//BIS_FA_MPFixArray is the JIP array, to track all AIS players
//BIS_FA_MPFix_newunit is the unit that just died and is to be re-initialised

sleep 1;

BIS_fnc_FA_MPFix_initUnit = {
	private "_unit";
	_unit = _this;
	if (isserver) then {
		//remove dead old units
		BIS_FA_MPFixArray = BIS_FA_MPFixArray - [objnull];
		{if (not alive _x) then {BIS_FA_MPFixArray = BIS_FA_MPFixArray - [_x]}} foreach BIS_FA_MPFixArray;
		BIS_FA_MPFixArray = BIS_FA_MPFixArray + [_unit]; //add new unit
		publicvariable "BIS_FA_MPFixArray";
	};
	if (local _unit) then {
		private "_aish";
		_aish = _unit getvariable "BIS_IS_agonyHandle"; //check if agony script already running
		if (not isnil {_aish}) then {
			_aish setFSMVariable ["who",player]; //fix the re-assignment, so it updates to new player object
		} else {
			[_unit] execFSM BIS_AIS_path + "data\fsms\agony.fsm"; // it hasn't started? restart it
		};
		_unit addEventHandler ["animStateChanged", "_this execFSM BIS_BC_Path + BIS_PATH_FSM + 'animHandler.fsm'; _this execFSM BIS_BC_Path + BIS_PATH_FSM + 'animHandlerNon.fsm'"];
		_unit setVariable ["BIS_BC_animHandlerStarted",true];
	};
	_unit setVariable ["BIS_BC_HASACTIONS", false]; //reset so actions can be added to new unit TODO: remove actions on old unit
	[_unit] execVM BIS_BC_Path + BIS_PATH_SQF + "BC_addActions.sqf";
	[_unit] execVM BIS_FA_Path + BIS_PATH_SQF + "FA_addActions.sqf";

	{
		if (isnil {_unit getvariable (_x select 0)}) then { //init variables, don't override (incase unit is currently injured or needing to be dragged)
			_unit setVariable _x;
		};
	} foreach [
		["BIS_BC_dragged",false],
		["BIS_BC_carried",false],
		["BIS_BC_dragger",false],
		["BIS_BC_carrier",false],
		["BIS_BC_dragWanted",false],
		["BIS_BC_carryWanted",false],
		["BIS_FA_healer",false],
		["BIS_FA_healEnabled",true],
		["BIS_FA_canHealTo",0.5],
		["BIS_IS_inAgony",false]
	];
};

"BIS_FA_MPFix_newunit" addPublicVariableEventHandler {
	(_this select 1) call BIS_fnc_FA_MPFix_initUnit;
};

BIS_fnc_FA_MPFix_killed = {
	waituntil {alive player};
	player call BIS_fnc_FA_MPFix_initUnit; //init for the player

	BIS_FA_MPFix_newunit = player;
	publicVariable "BIS_FA_MPFix_newunit"; //init remotely
};

player addEventHandler ["Killed",{
	[] spawn BIS_fnc_FA_MPFix_killed;
}];

if (not isnil "BIS_FA_MPFixArray") then { //JIP fix
	if (count BIS_FA_MPFixArray > 0) then {
		{
			_x call BIS_fnc_FA_MPFix_initUnit; //init all units in the array
		} foreach BIS_FA_MPFixArray;
	};
};