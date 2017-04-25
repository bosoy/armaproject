Private ["_award","_camp","_camps","_index","_marker","_name","_captureSideID","_town","_townSideID","_units"];

_town = _this Select 0;
_captureSideID = _this Select 1;
_camp = _this Select 2;

if !(clientInitComplete) exitWith {};

_camps = _town getVariable "camps";
_name = _town getVariable "name";
_townSideID = _town getVariable "sideID";
_index = _camps find _camp;

if (_index != -1) then {
	_marker = Format["%1Camp%2",str _town,_index];
	if (sideID == _captureSideID) then {
		_award = false;
		if (Leader Group player == player) then {
			_units = units group player;
			{if (_x distance _camp < 5) then {_award = true}} forEach _units;
		};

		if (player Distance _camp < 5 || _award) then {
			('WFBE_CAMPCAPTUREBOUNTY' Call GetNamespace) Call ChangePlayerFunds;		
			WFBE_RequestChangeScore = ['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCORECAPTURECAMP' Call GetNamespace)]];
			publicVariable 'WFBE_RequestChangeScore';
			if (isHostedServer) then {['SRVFNCREQUESTCHANGESCORE',[player,score player + ('WFBE_SCORECAPTURECAMP' Call GetNamespace)]] Spawn HandleSPVF};
			Format[localize "STR_WF_Camp_Captured_Bounty",_name,'WFBE_CAMPCAPTUREBOUNTY' Call GetNamespace] Call CommandChatMessage;
			if (mysql) then {
				WF_Logic setVariable ["WF_MYSQL_CLIENT",(WF_Logic getVariable "WF_MYSQL_CLIENT") + [Format ["MYSQLDATA§WFBE_Update§%1§%2§campcaptured§%3",getPlayerUID(player),name player,worldName]],true];
			};
		} else {
			Format[localize "STR_WF_Camp_Captured",_name] Call CommandChatMessage;
		};
		_marker setMarkerColorLocal ("Friendly" Call GetMarkerColoration);
	} else {
		if (_townSideID == sideID || getMarkerColor _marker == ("Friendly" Call GetMarkerColoration)) then {
			Format[localize "STRWFCAMPCAPTUREDBYENEMY",_name] Call CommandChatMessage;
			_marker setMarkerColorLocal ("Enemy" Call GetMarkerColoration);
		};
	};
};
