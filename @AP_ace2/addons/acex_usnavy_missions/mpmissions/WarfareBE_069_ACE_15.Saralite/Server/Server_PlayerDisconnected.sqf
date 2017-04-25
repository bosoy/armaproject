/* 
	Author: Benny
	Name: Server_PlayerDisconnected.sqf
	Parameters:
	  0 - User ID
	  1 - User Name
	Description:
	  This file is called upon a player disconnection, the player's information are updated.
*/
Private ['_buildings','_closestRespawn','_cmdrTeam','_funds','_get','_hq','_name','_respawnLoc','_side','_sideText','_slotIndex','_team','_units','_uid'];
_uid = _this select 0;
_name = _this select 1;

diag_log Format["[WFBE (INFORMATION)][frameno:%3 | ticktime:%4] Server_PlayerDisconnected: Player %1 (%2) has left the game",_name,_uid,diag_frameno,diag_tickTime];

//--- Grab the player info (if they exist).
_get = Format["WFBE_JIP_USER%1",_uid] Call GetNamespace;
if (isNil '_get') exitWith {diag_log Format ["[WFBE (INFORMATION)][frameno:%3 | ticktime:%4] Server_PlayerDisconnected: Player %1 (%2) don't have any information stored.",_name,_uid,diag_frameno,diag_tickTime]};

//--- Check this mess.
_side = _get select 4;
_sideText = str _side;
_slotIndex = _get select 1;
_team = Call Compile Format ["group %1",_get select 6];
if (isNull _team) exitWith {diag_log Format ["[WFBE (INFORMATION)][frameno:%3 | ticktime:%4] Server_PlayerDisconnected: Player %1 (%2) team is null.",_name,_uid,diag_frameno,diag_tickTime]};

//--- MySQL Update.
if (mysql && !gameOver) then {
	Private ['_strTrans'];
	_strTrans = if (_side == west) then {'west'} else {'east'};
	WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_Disconnect_Player?%1?%2?%3?%4?%5",_uid,_name,round(time - (_get select 5)),_strTrans,worldName]]];
};

//--- Force the unit out if it has a vehicle.
if !(isNull(assignedVehicle (leader _team))) then {
	unassignVehicle (leader _team);
	[leader _team] orderGetIn false;
	[leader _team] allowGetIn false;
};

//--- Is unit driving the HQ?
_hq = (_sideText) Call GetSideHQ;
if (vehicle(leader _team) == _hq) then {(leader _team) action ["EJECT", _hq]};

//--- Keep AI over JIP?
if !(paramKeepAI) then {
	diag_log Format ["[WFBE (INFORMATION)][frameno:%7 | ticktime:%8] Server_PlayerDisconnected: Removing units (Team: %1, Team Side: %2, Team Leader: %3) for Player %4 (%5)   DEBUG:%6.",_team,side _team,leader _team,_name,_uid,_get,diag_frameno,diag_tickTime];
	_units = units _team;
	_units = _units - [leader _team];
	_units = _units + ([_team,false] Call GetTeamVehicles) - [_hq];
	{deleteVehicle _x} forEach _units;
};

//--- Save the Client Cash.
_funds = _team Call GetTeamFunds;
_get set [2,_funds];

//--- SetPos the AI.
_buildings = (_sideText) Call GetSideStructures;
_respawnLoc = _hq;
if (count _buildings > 0) then {
	_closestRespawn = [leader _team,_buildings] Call SortByDistance;
	_respawnLoc = _closestRespawn select 0;
};
(leader _team) setPos ([getPos _respawnLoc,20,30] Call GetRandomPosition);

//--- ISIS.
if (('WFBE_ISIS' Call GetNamespace) != 0) then {(leader _team) addEventHandler['handleDamage',{_this Call ISIS_Wound}]}; 

//--- Update.
[Format["WFBE_JIP_USER%1",_uid],_get,true] Call SetNamespace;

//--- Player was commander?.
_cmdrTeam = (_side) Call GetCommanderTeam;
if !(isNull (_cmdrTeam)) then {
	if (_team == _cmdrTeam) then {
		WF_Logic setVariable [Format ["%1CommanderTeam",_sideText],objNull,true];
		WFBE_LocalizeMessage = [_side,'CLTFNCLOCALIZEMESSAGE',['CommanderDisconnected']];
		publicVariable 'WFBE_LocalizeMessage';
		
		//--- High Command (Remove).
		if (paramHighCommand && count (hcAllGroups (leader _team)) > 0) then {HCRemoveAllGroups (leader _team)};
		
		//--- AI Can move freely now & respawn at the default location.
		{[_x,false] Call SetTeamAutonomous;[_x, ""] Call SetTeamRespawn;} forEach (Format["WFBE_%1TEAMS",_sideText] Call GetNamespace);
	};
};