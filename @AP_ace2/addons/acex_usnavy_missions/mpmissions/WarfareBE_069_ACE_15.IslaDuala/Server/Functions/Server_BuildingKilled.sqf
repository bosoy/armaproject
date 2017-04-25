Private ['_current','_find','_killer','_structure','_structures','_side','_tked','_type','_uid'];
_structure = _this select 0;
_killer = _this select 1;
_side = _this select 2;
_type = _this select 3;

diag_log Format["[WFBE (INFORMATION)][frameno:%3 | ticktime:%4] Server_BuildingKilled: A %1 %2 Structure has been destroyed (By: %5)",str _side,_type,diag_frameno,diag_tickTime,_killer];

//--- Building Teamkill.
if ((side _killer == _side)&&(isPlayer(_killer))) then {
	_uid = getPlayerUID _killer;
	if !(paramShowUID) then {_uid = "xxxxxxx"};
	_tked = [_type, 'displayName'] Call GetConfigInfo;
	WFBE_LocalizeMessage = [_side,'CLTFNCLOCALIZEMESSAGE',['BuildingTeamkill',name _killer,_uid,_tked]];
	publicVariable 'WFBE_LocalizeMessage';
	if (isHostedServer) then {[_side,'CLTFNCLOCALIZEMESSAGE',['BuildingTeamkill',name _killer,_uid,_tked]] Spawn HandlePVF};
	if (mysql) then {
		WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_Update?%1?%2?teamkillstr?%3",_uid,name _killer,worldName]]];
	};
	
	diag_log Format["[WFBE (INFORMATION)][frameno:%3 | ticktime:%4] Server_BuildingKilled: Player %1 (%2) has teamkilled a friendly building.",name _killer,_uid,diag_frameno,diag_tickTime];
};

if (mysql) then {
	if ((side _killer != _side)&&(isPlayer(_killer))) then {
		WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKAI?%1?%2?%3?%4?3?%5",_type,getPlayerUID _killer,name _killer,"killed",worldName]]];
	};
};

//--- Decrement building limit.
_find = (Format ['WFBE_%1STRUCTURENAMES',_side] Call GetNamespace) find _type;
if (_find != -1) then {
	_current = Call Compile Format ['%1BuildingsCurrent',_side];
	_current set [_find - 1, (_current select (_find-1)) - 1];
	Call Compile Format ['%1BuildingsCurrent = _current',_side];
	publicVariable Format ['%1BuildingsCurrent',_side];
};

Call Compile Format ["%1BaseStructures = %1BaseStructures - [_structure] - [objNull]; publicVariable '%1BaseStructures';",str _side];

["Destroyed",_type,_side] Spawn SideMessage;

//--- Can be fixed with workers.
if (paramUseWorkers) then {
	Private ["_nearLogic","_position","_sold"];
	
	_sold = _structure getVariable "sold";
	
	if (isNil '_sold') then {
		//--- Grab the logic.
		_position = getPos _structure;
		_nearLogic = _position nearEntities [["LocationLogicStart"],15];
		if (count _nearLogic > 0) then {_nearLogic = ([_position, _nearLogic] Call SortByDistance) select 0} else {_nearLogic = objNull};
		
		if (isNull _nearLogic) exitWith {};
		
		//--- Completed at 25% on destruction, dropping until it reach 0 (delete).
		_nearLogic setVariable ["WFBE_B_Completion", 25];
		//--- The ratio gets lower after each destruction.
		_nearLogic setVariable ["WFBE_B_CompletionRatio", (_nearLogic getVariable "WFBE_B_CompletionRatio")*0.8];
		//--- Can be repaired.
		_nearLogic setVariable ["WFBE_B_Repair", true];
		
		[Format ["WFBE_WORKERS_%1LOGIC",str _side],((Format ["WFBE_WORKERS_%1LOGIC",str _side]) Call GetNamespace) + [_nearLogic],true] Call SetNamespace;
		
		[_nearLogic, typeOf _structure, _side, _find - 1] Spawn HandleBuildingRepair;
	};
};

sleep 10;

deleteVehicle _structure;
