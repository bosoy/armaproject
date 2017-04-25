Private ["_award","_bounty","_location","_locationName","_marker1","_mysqlUpdate","_name","_locations","_objective","_ptask","_range","_side","_sideName","_sideValue","_task","_units"];

_location = _this select 0;
_sideValue = _this select 1;

if !(clientInitComplete) exitWith {};

_name = str _location;
_mysqlUpdate = "";

_task = _location getVariable 'taskLink';
_ptask = currentTask player;
if (isNil '_task') then {_task = objNull};
_locationName = _location getVariable "name";

_sideName = localize "STR_WF_Side_East";
if (_sideValue == WESTID) then {_sideName = localize "STR_WF_Side_West"};

[Format[Localize "STR_WF_Town_Captured",_locationName,_sideName]] Call TitleTextMessage;
_marker1 = Format["%1Depot",_name];

if (_sideValue == sideID) then {_marker1 setMarkerColorLocal ("Friendly" Call GetMarkerColoration)} else {_marker1 setMarkerColorLocal ("Enemy" Call GetMarkerColoration)};

if (_sideValue == sideID) then {
	_award = false;
	if ((Leader Group player) == player) then {
		_units = Units Group player;
		{if (_x distance _location < ('WFBE_TOWNCAPTURERANGE' Call GetNamespace)) then {_award = true};} ForEach _units;
	};

	if (player distance _location < ('WFBE_TOWNCAPTURERANGE' Call GetNamespace) || _award) then {
		if (_task == _ptask) then {
			["TownHintDone",_location] Spawn TaskSystem;
			('WFBE_TOWNMISSIONCAPTUREBOUNTY' Call GetNamespace) Call ChangePlayerFunds;
			WFBE_RequestChangeScore = ['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCORECAPTURETOWN' Call GetNamespace)]];
			publicVariable 'WFBE_RequestChangeScore';
			if (isHostedServer) then {['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCORECAPTURETOWN' Call GetNamespace)]] Spawn HandleSPVF};
			Format[Localize "STR_WF_Town_Bounty_Full",_locationName,('WFBE_TOWNMISSIONCAPTUREBOUNTY' Call GetNamespace)] Call CommandChatMessage;
			_mysqlUpdate = "towncaptured";
		} else {
			('WFBE_TOWNCAPTUREBOUNTY' Call GetNamespace) Call ChangePlayerFunds;
			WFBE_RequestChangeScore = ['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCORECAPTURETOWN' Call GetNamespace)]];
			publicVariable 'WFBE_RequestChangeScore';
			if (isHostedServer) then {['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCORECAPTURETOWN' Call GetNamespace)]] Spawn HandleSPVF};
			Format[Localize "STR_WF_Town_Bounty_Full",_locationName,('WFBE_TOWNCAPTUREBOUNTY' Call GetNamespace)] Call CommandChatMessage;
			_mysqlUpdate = "towncaptured";
		};
	} else {
		_range = (_location getVariable "range") * ('WFBE_TOWNCAPTUREASSISTRANGEMODIFIER' Call GetNamespace);
		if (player distance _location < _range) then {
			if (_task == _ptask) then {
				["TownHintDone",_location] Spawn TaskSystem;
				('WFBE_TOWNMISSIONASSISTCAPTUREBOUNTY' Call GetNamespace) Call ChangePlayerFunds;
				WFBE_RequestChangeScore = ['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCOREASSISTCAPTURETOWN' Call GetNamespace)]];
				publicVariable 'WFBE_RequestChangeScore';
				if (isHostedServer) then {['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCOREASSISTCAPTURETOWN' Call GetNamespace)]] Spawn HandleSPVF};
				Format[Localize "STR_WF_Town_Bounty_Full",_locationName,('WFBE_TOWNMISSIONASSISTCAPTUREBOUNTY' Call GetNamespace)] Call CommandChatMessage;
				_mysqlUpdate = "townassist";
			} else {
				('WFBE_TOWNASSISTCAPTUREBOUNTY' Call GetNamespace) Call ChangePlayerFunds;
				WFBE_RequestChangeScore = ['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCOREASSISTCAPTURETOWN' Call GetNamespace)]];
				publicVariable 'WFBE_RequestChangeScore';
				if (isHostedServer) then {['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCOREASSISTCAPTURETOWN' Call GetNamespace)]] Spawn HandleSPVF};
				Format[Localize "STR_WF_Town_Bounty_Assist",_locationName,('WFBE_TOWNASSISTCAPTUREBOUNTY' Call GetNamespace)] Call CommandChatMessage;
				_mysqlUpdate = "townassist";
			};	
		};
	};
};

if (mysql) then {
	if (_mysqlUpdate != "") then {
		WF_Logic setVariable ["WF_MYSQL_CLIENT",(WF_Logic getVariable "WF_MYSQL_CLIENT") + [Format ["MYSQLDATA?WFBE_Update?%1?%2?%3?%4",getPlayerUID(player),name player,_mysqlUpdate,worldName]],true];
	};
};

if (!isNull commanderTeam && sideID == _sideValue) then {
	if (commanderTeam == Group player) then {
		_bounty = (_location getVariable "startingSupplyValue") * ('WFBE_COMMANDERTOWNCAPTURECOEF' Call GetNamespace);
		_bounty Call ChangePlayerFunds;
		WFBE_RequestChangeScore = ['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_COMMANDERTOWNCAPTURESCORE' Call GetNamespace)]];
		publicVariable 'WFBE_RequestChangeScore';
		if (isHostedServer) then {['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_COMMANDERTOWNCAPTURESCORE' Call GetNamespace)]] Spawn HandleSPVF};
		Format[Localize "STR_WF_Commander_Bounty_Town",_bounty,_locationName] Call CommandChatMessage;
	};
};

/* Task Handling */
["TownUpdate",_location] Spawn TaskSystem;
if (sideID == _sideValue) then {
	if !(isNull _task) then {
		if (_ptask == _task) then {
			["TownAssignClosest"] Spawn TaskSystem;
		};
	};
};