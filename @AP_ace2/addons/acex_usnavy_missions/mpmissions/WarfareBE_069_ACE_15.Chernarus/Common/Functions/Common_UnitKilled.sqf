Private ["_bounty","_crew","_get","_group","_isAIControlled","_iskilledplayer","_iskillerplayer","_isMan","_killed","_killedname","_killeduid","_killer","_killerID","_killername","_killerTeam","_killerVehName","_killertype","_killeruid","_lost","_objects","_objectType","_side","_sideKiller","_sideVictim","_sta","_uid","_vehicle"];
_killed = _this select 0;
_killer = _this select 1;
_sideVictim = _this select 2;
_sideKiller = side _killer;

_group = group _killed;
_killerTeam = group _killer;
_killerVehName = vehicleVarName (leader _killerTeam);
_vehicle = vehicle _killer;
_objectType = typeOf _killed;
_killertype = "";
_killeruid = "";
_killername = "";
_killeduid = "";
_killedname = "";
_iskilledplayer = false;

_isMan = if (_killed isKindOf "Man") then {true} else {false};

_iskillerplayer = if (isPlayer _killer) then {true} else {false};
if (mysql) then {
	_killertype = typeOf _killer;
	_iskilledplayer = if (isPlayer _killed) then {true} else {false};
	_killeruid = if (_iskillerplayer) then {getPlayerUID(_killer)} else {"0"};
	_killeduid = if (_iskilledplayer) then {getPlayerUID(_killed)} else {"0"};
	_killername = if (_iskillerplayer) then {name _killer} else {"nil"};
	_killedname = if (_iskilledplayer) then {name _killed} else {"nil"};
};

//--- Renegade.
if (_sideKiller == sideEnemy) then {
	if (_killer isKindOf westSoldierBaseClass) then {_sideKiller = west};
	if (_killer isKindOf eastSoldierBaseClass) then {_sideKiller = east};
};
if (_sideVictim == sideEnemy) then {
	if (_killed isKindOf westSoldierBaseClass) then {_sideVictim = west};
	if (_killed isKindOf eastSoldierBaseClass) then {_sideVictim = east};
};

//--- Benny's Garbage Collector.
if (WF_A2_Vanilla) then {
	/* Vanilla use the old garbage system */
	if (!(isServer) || local player) then {
		_objects = (WF_Logic getVariable "trash") + [_killed];
		WF_Logic setVariable ["trash",_objects,true];
	} else {
		trashQueu = trashQueu + [_killed];
		_killed Spawn TrashObject;
	};
} else {
	/* OA use the evolved system which no longer require network variables */
	if (isServer) then {
		trashQueu = trashQueu + [_killed];
		_killed Spawn TrashObject;
	};
};

sleep (random 3);

if (_isMan && (_sideVictim == west || _sideVictim == east)) then {[str _sideVictim,'Casualties',1] Call UpdateStatistics};
if (!_isMan && (_sideVictim == west || _sideVictim == east)) then {[str _sideVictim,'VehiclesLost',1] Call UpdateStatistics};

_killerID = (leader _killerTeam) Call GetClientID;
_get = _objectType Call GetNamespace;

_isAIControlled = true;
if (_killerID > 0) then {_isAIControlled = if (isPlayer (leader _killerTeam)) then {false} else {true}};

//--- Normal kill.
if (!isNull _killerTeam && !isNil '_get' && (_sideKiller != sideEnemy) && (_sideKiller != _sideVictim) && (_sideKiller != Civilian)) then {
	if (_killerID > 0 && !_isAIControlled) then {
		/* Bounty */
		if (paramBounty) then {
			WFBE_AwardBounty = [_killerVehName,'CLTFNCAWARDBOUNTY',[_objectType, false]];
			publicVariable 'WFBE_AwardBounty';
			if (isHostedServer) then {[_killerVehName,'CLTFNCAWARDBOUNTY',[_objectType, false]] Spawn HandlePVF};
			
			//--- Kill Assist.
			if (!(_vehicle isKindOf 'Man') && alive _vehicle) then {
				_crew = [driver _vehicle, gunner _vehicle, commander _vehicle] - [_killer, player];
				{
					if !(isNull _x) then {
						if (isPlayer _x && group _x != _killerTeam) then {
							WFBE_AwardBounty = [vehicleVarName _x,'CLTFNCAWARDBOUNTY',[_objectType, true]];
							publicVariable 'WFBE_AwardBounty';
							if (isHostedServer) then {[vehicleVarName _x,'CLTFNCAWARDBOUNTY',[_objectType, true]] Spawn HandlePVF};
						};
					};
				} forEach _crew;
			};
		};
		
		/* AI Score */
		if !(_iskillerplayer) then {
			[_objectType,leader _killerTeam] Spawn {
				Private ['_player','_point','_type'];
				_type = _this select 0;
				_player = _this select 1;
				
				_point = switch (true) do {
					case (_type isKindOf "Infantry"): {1};
					case (_type isKindOf "Car"): {2};
					case (_type isKindOf "Ship"): {4};
					case (_type isKindOf "Motorcycle"): {1};
					case (_type isKindOf "Tank"): {4};
					case (_type isKindOf "Helicopter"): {4};
					case (_type isKindOf "Plane"): {6};
					case (_type isKindOf "StaticWeapon"): {2};
					case (_type isKindOf "Building"): {2};
					default {1};
				};

				sleep random(3);
				
				if (isServer) then {
					['SRVFNCREQUESTCHANGESCORE',[_player,score _player + _point]] Spawn HandleSPVF;
				} else {
					WFBE_RequestChangeScore = ['SRVFNCREQUESTCHANGESCORE',[_player,score _player + _point]];
					publicVariable 'WFBE_RequestChangeScore';
					if (isHostedServer) then {['SRVFNCREQUESTCHANGESCORE',[_player,score _player + _point]] Spawn HandleSPVF};
				};
			};
		};
		
		/* MySQL */
		if (mysql) then {
			_sta = switch (true) do {
				case (_objectType isKindOf "Infantry"): {1};
				case (_objectType isKindOf "Car"): {2};
				case (_objectType isKindOf "Ship"): {2};
				case (_objectType isKindOf "Motorcycle"): {1};
				case (_objectType isKindOf "Tank"): {4};
				case (_objectType isKindOf "Helicopter"): {6};
				case (_objectType isKindOf "Plane"): {8};
				case (_objectType isKindOf "StaticWeapon"): {3};
				case (_objectType isKindOf "Building"): {3};
				default {1};
			};
			if (isServer) then {
				if (_iskilledplayer) then {
					WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKP?%1?%2?%3?%4?%5",_killeduid,_killedname,_killeruid,_killername,worldName]]];
					WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKAI?%1?%2?%3?%4?%5?%6",_killertype,_killeduid,_killedname,"killedby",_sta,worldName]]];
				} else {
					WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKAI?%1?%2?%3?%4?%5?%6",_objectType,_killeruid,_killername,"killed",_sta,worldName]]];
				};
			} else {
				if (_iskilledplayer) then {
					WF_Logic setVariable ["WF_MYSQL_CLIENT",(WF_Logic getVariable "WF_MYSQL_CLIENT") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKP?%1?%2?%3?%4?%5",_killeduid,_killedname,_killeruid,_killername,worldName]],true];
					WF_Logic setVariable ["WF_MYSQL_CLIENT",(WF_Logic getVariable "WF_MYSQL_CLIENT") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKAI?%1?%2?%3?%4?%5?%6",_killertype,_killeduid,_killedname,"killedby",_sta,worldName]],true];
				} else {
					WF_Logic setVariable ["WF_MYSQL_CLIENT",(WF_Logic getVariable "WF_MYSQL_CLIENT") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKAI?%1?%2?%3?%4?%5?%6",_objectType,_killeruid,_killername,"killed",_sta,worldName]],true];
				};
			};
		};
	};
	
	if (mysql) then {
		if (_isAIControlled) then {
			if (isServer) then {
				if (mysql && _iskilledplayer) then {
					WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKAI?%1?%2?%3?%4?0?%5",_killertype,_killeduid,_killedname,"killedby",worldName]]];
				};
			} else {
				if (mysql && _iskilledplayer) then {
					WF_Logic setVariable ["WF_MYSQL_CLIENT",(WF_Logic getVariable "WF_MYSQL_CLIENT") + [Format ["MYSQLDATA?WFBE_InsertOrUpdate_PKAI?%1?%2?%3?%4?0?%5",_killertype,_killeduid,_killedname,"killedby",worldName]],true];
				};
			};
		};
	};
	
	/* Playable AI Kill */
	if (paramAI && _killerID > 0 && _isAIControlled) then {
		if (isServer) then {
			_bounty = (_get select QUERYUNITPRICE) * ('WFBE_BOUNTYMODIFIER' Call GetNamespace);
			_bounty = _bounty - (_bounty % 1);
			[_killerTeam,_bounty] Call ChangeTeamFunds;
		};
	};
};

//--- Teamkill.
if (!isNull _killerTeam && !isNil '_get' && (_sideKiller != sideEnemy) && (_sideKiller == _sideVictim) && (_sideKiller != Civilian) && _isMan) then {
	if (_killerID > 0 && !_isAIControlled) then {
		WFBE_LocalizeMessage = [_killerVehName,'CLTFNCLOCALIZEMESSAGE',['Teamkill']];
		publicVariable 'WFBE_LocalizeMessage';
		if (isHostedServer) then {[_killerVehName,'CLTFNCLOCALIZEMESSAGE',['Teamkill']] Spawn HandlePVF};
		if (mysql) then {
			if (isServer) then {
				WF_Logic setVariable ["WF_MYSQL_SERVER",(WF_Logic getVariable "WF_MYSQL_SERVER") + [Format ["MYSQLDATA?WFBE_Update?%1?%2?teamkill?%3",_killeruid,_killername,worldName]]];
			} else {
				WF_Logic setVariable ["WF_MYSQL_CLIENT",(WF_Logic getVariable "WF_MYSQL_CLIENT") + [Format ["MYSQLDATA?WFBE_Update?%1?%2?teamkill?%3",_killeruid,_killername,worldName]],true];
			};
		};
	};
};
