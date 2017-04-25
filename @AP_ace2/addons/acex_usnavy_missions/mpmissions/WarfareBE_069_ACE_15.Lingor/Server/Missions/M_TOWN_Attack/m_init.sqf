/* Town Attack Script (Hybrid) */
Private ['_attackAfter','_attempts','_boundariesxy','_cpt','_group','_groups','_grps','_i','_inRange','_jipHandler','_markerSize','_near','_pos','_position','_resTypes','_retVal','_runFor','_sideID','_size','_spawnLocations','_sup','_teamType','_town','_towns','_uniqueIndex','_uniqueLabel','_vehicles'];

_uniqueLabel = _this select 0;
_uniqueIndex = _this select 1;
_runFor = _this select 2;

//--- Retrieve towns.
_towns = [];
_sideID = (_runFor) Call GetSideID;
{
	if (_x getVariable 'sideID' == _sideID) then {_towns = _towns + [_x]};
} forEach towns;

//--- Ensure that the team already has a town.
if (count _towns == 0) exitWith {
	[Format['_WFBE_M_RUNNINGMISSIONS_%1',_runFor],((Format['_WFBE_M_RUNNINGMISSIONS_%1',_runFor]) Call GetNamespace) - 1, true] Call SetNamespace;
};

/* Radio the designated team that a new mission is available */
['NewMissionAvailable','',_runFor] Spawn SideMessage;

//--- Pick a town.
_town = _towns select round(random((count _towns)-1));

_markerSize = 500;
_size = _markerSize;

//--- Get the groups depending on the SV.
_sup = _town getVariable 'supplyValue';
_grps = 1;
if (_sup < 30) then {_grps = 2};
if (_sup >= 30 && _sup < 50) then {_grps = 3};
if (_sup >= 50 && _sup < 80) then {_grps = 4};
if (_sup >= 80 && _sup < 100) then {_grps = 5};
if (_sup >= 100 && _sup < 120) then {_grps = 6};
if (_sup >= 120) then {_grps = 7};

//--- Create the groups.
_groups = [];
for [{_i = 0},{_i < _grps},{_i = _i + 1}] do {
	_groups = _groups + [createGroup resistance];
};

//--- Plan the attack delay.
_attackAfter = (200)+(random 100)-(random 100);

//--- Warn the client.
WFBE_M_TOWN_Attack = [_runFor,'CLTFNCM_TOWN_ATTACK',[_size/2,_uniqueLabel,_uniqueIndex,_town,_groups]];
publicVariable 'WFBE_M_TOWN_Attack';
if (isHostedServer || local player) then {[_runFor,'CLTFNCM_TOWN_ATTACK',[_size/2,_uniqueLabel,_uniqueIndex,_town,_groups]] Spawn HandlePVF};
_jipHandler = [_runFor,_size,_uniqueLabel,_uniqueIndex,_town,_groups] Spawn {
	Private ['_groups','_oldPlayerList','_runFor','_size','_town','_uniqueLabel','_uniqueIndex','_update'];
	_runFor = _this select 0;
	_size = (_this select 1)/2;
	_uniqueLabel = _this select 2;
	_uniqueIndex = _this select 3;
	_town = _this select 4;
	_groups = _this select 5;
	
	while {true} do {
		_oldPlayerList = playableUnits;
		sleep 15;
		_update = false;
		{
			if !(_x in _oldPlayerList) then {_update = true};
		} forEach playableUnits;
		
		if (_update) then {
			WFBE_M_TOWN_Attack = [_runFor,'CLTFNCM_TOWN_ATTACK',[_size,_uniqueLabel,_uniqueIndex,_town,_groups]];
			publicVariable 'WFBE_M_TOWN_Attack';
			if (isHostedServer || local player) then {[_runFor,'CLTFNCM_TOWN_ATTACK',[_size,_uniqueLabel,_uniqueIndex,_town,_groups]] Spawn HandlePVF};
		};
	};
};

//--- Wait...
sleep _attackAfter;

_spawnLocations = [];
_attempts = 0;
while {count _spawnLocations < 8} do {
	sleep 0.05;
	_position = ([getPos _town,(_markerSize * 0.75),(_markerSize)] Call GetRandomPosition);
	_pos = [_position, 50] Call GetSafePlace;
	
	_inRange = true;
	if (paramBoundaries) then {
		_boundariesxy = 'WFBE_BOUNDARIESXY' Call GetNamespace;
		if (((_pos select 0) < (_markerSize / 2) || (_pos select 0) > (_boundariesxy - (_markerSize / 2))) || ((_pos select 1) < (_markerSize / 2) || (_pos select 1) > (_boundariesxy - (_markerSize / 2)))) then {
			_inRange = false;
		};
	};

	_near = _pos nearEntities [['Man','Car','Motorcycle','Ship','Air','Tank','StaticCannon'],_markerSize/8];
	
	if (east countSide _near == 0 && west countSide _near == 0 && _inRange) then {_spawnLocations = _spawnLocations + [_pos];_size = 650};
	_attempts = _attempts + 1;
	
	if (_attempts > 50) then {
		_attempts = 0;
		_size = _size + (_markerSize/5);
	};
};

_resTypes = _town getVariable 'resistanceTypes';
_sideID = _town getVariable 'sideID';

_i = 0;
_vehicles = [];
while {_i < _grps} do {
	_teamType = Format ["WFBE_RES%1UNITS",_resTypes select floor(random(count _resTypes))] Call GetNamespace;
	_group = _groups select _i;
	_pos = _spawnLocations select floor(random(count _spawnLocations));
	
	_retVal = [_teamType,_pos,resistance,paramResVehLock,_group] Call CreateTeamTemplate;
	_vehicles = _vehicles + [_retVal select 1];
	
	_group setFormation (['COLUMN','ECH RIGHT','LINE','FILE','DIAMOND'] select floor(random 5));
	
	if (_sideID == RESISTANCEID) then {
		//--- Town is held by the resistance.
		_group setBehaviour 'AWARE';
		_group setCombatMode 'YELLOW';
		[_group,_town,150] Spawn AITownPatrol;
	} else {
		_group setBehaviour 'COMBAT';
		_group setCombatMode 'RED';
		_group move (getPos _town);
		//--- Town is held by the occupation.
	};
	
	//--- Enhance the experience with UPSMON.
	if (paramUPSMON) then {[(leader _group),Format ['UPSMON_TOWN_%1',str _town],"move","nofollow","reinforcement"] Spawn UPSMON};
	
	_i = _i + 1;
};

//--- Wait until everyone's dead.
waitUntil {
	sleep 1;

	_cpt = 0;
	{
		if !(isNil '_x') then {
			_cpt = _cpt + (count ((units _x) Call GetLiveUnits));
		};
	} forEach _groups;
	
	_cpt == 0
};

//--- Kill the spawned thread if it still runs.
if !(scriptDone _jipHandler) then {terminate _jipHandler};

//--- Wait for the client to end up his sync.
sleep 35;

//--- Free the mission.
[Format['_WFBE_M_RUNNINGMISSIONS_%1',_runFor],((Format['_WFBE_M_RUNNINGMISSIONS_%1',_runFor]) Call GetNamespace) - 1, true] Call SetNamespace;