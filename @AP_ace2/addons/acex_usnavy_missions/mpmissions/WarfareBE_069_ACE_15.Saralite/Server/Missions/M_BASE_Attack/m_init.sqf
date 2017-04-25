/* Base Attack Script (Hybrid) */
Private ['_attackAfter','_attempts','_boundariesxy','_cpt','_group','_groups','_grps','_hq','_i','_inRange','_isHQDeployed','_jipHandler','_marker','_markerSize','_near','_pos','_position','_retVal','_runFor','_size','_spawnLocations','_structures','_target','_teamType','_uniqueIndex','_uniqueLabel','_vehicles'];

_uniqueLabel = _this select 0;
_uniqueIndex = _this select 1;
_runFor = _this select 2;

//--- Make sure that at least one building is available.
_structures = (_runFor) Call GetSideStructures;
if (count _structures == 0) exitWith{
	[Format['_WFBE_M_RUNNINGMISSIONS_%1',_runFor],((Format['_WFBE_M_RUNNINGMISSIONS_%1',_runFor]) Call GetNamespace) - 1, true] Call SetNamespace;
};

/* Radio the designated team that a new mission is available */
['NewMissionAvailable','',_runFor] Spawn SideMessage;

//--- Grab the HQ.
_isHQDeployed = (_runFor) Call GetSideHQDeployed;
if (_isHQDeployed) then {
	_hq = (_runFor) Call GetSideHQ;
	if (alive _hq) then {_structures = _structures + [_hq]};
};

//--- Pick a target.
_target = _structures select floor(random (count _structures));

//--- Progressive difficulty.
_grps = 2 + ('WFBE_TOWNRESISTANCEDIFFICULTY' Call GetNamespace);

//--- Create the groups.
_groups = [];
for [{_i = 0},{_i < _grps},{_i = _i + 1}] do {
	_groups = _groups + [createGroup resistance];
};

_markerSize = 700;
_size = _markerSize;

//--- Plan the attack delay.
_attackAfter = (300)+(random 100)-(random 100);

//--- Warn the client.
WFBE_M_BASE_Attack = [_runFor,'CLTFNCM_BASE_ATTACK',[_size/2,_uniqueLabel,_uniqueIndex,_target,_groups]];
publicVariable 'WFBE_M_BASE_Attack';
if (isHostedServer || local player) then {[_runFor,'CLTFNCM_BASE_ATTACK',[_size/2,_uniqueLabel,_uniqueIndex,_target,_groups]] Spawn HandlePVF};
_jipHandler = [_runFor,_size,_uniqueLabel,_uniqueIndex,_target,_groups] Spawn {
	Private ['_groups','_oldPlayerList','_runFor','_size','_target','_uniqueLabel','_uniqueIndex','_update'];
	_runFor = _this select 0;
	_size = (_this select 1)/2;
	_uniqueLabel = _this select 2;
	_uniqueIndex = _this select 3;
	_target = _this select 4;
	_groups = _this select 5;
	
	while {true} do {
		_oldPlayerList = playableUnits;
		sleep 15;
		_update = false;
		{
			if !(_x in _oldPlayerList) then {_update = true};
		} forEach playableUnits;
		
		if (_update) then {
			WFBE_M_BASE_Attack = [_runFor,'CLTFNCM_BASE_ATTACK',[_size,_uniqueLabel,_uniqueIndex,_target,_groups]];
			publicVariable 'WFBE_M_BASE_Attack';
			if (isHostedServer || local player) then {[_runFor,'CLTFNCM_BASE_ATTACK',[_size,_uniqueLabel,_uniqueIndex,_target,_groups]] Spawn HandlePVF};
		};
	};
};

sleep _attackAfter;

//--- Targert died?
if !(alive _target) then {
	//--- Pick another target if possible, else send them to the HQ (DoA).
	_structures = (_runFor) Call GetSideStructures;
	if (count _structures == 0) then {
		_hq = (_runFor) Call GetSideHQ;
		_target = _hq;
	} else {
		_target = _structures select floor(random (count _structures));
	};
};

//--- UPSMON Area Definition.
_marker = "";
if (paramUPSMON) then {
	_marker = Format['UPSMON_%1%2',_uniqueLabel,_uniqueIndex];
	createMarkerLocal [_marker, getPos _target];
	_marker setMarkerColorLocal "ColorBlue";
	_marker setMarkerShapeLocal "RECTANGLE";
	_marker setMarkerBrushLocal "BORDER";
	_marker setMarkerSizeLocal [300,300];
	_marker setMarkerAlphaLocal 0;
};

_spawnLocations = [];
_attempts = 0;
while {count _spawnLocations < 8} do {
	sleep 0.05;
	_position = ([getPos _target,(_markerSize * 0.75),(_markerSize)] Call GetRandomPosition);
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

_i = 0;
_vehicles = [];
while {_i < _grps} do {
	_teamType = Format ["WFBE_RESPATROLTYPE%1%2",1 + round(random 2),round(random 2)] Call GetNamespace;
	_group = _groups select _i;
	_pos = _spawnLocations select floor(random(count _spawnLocations));
	
	_retVal = [_teamType,_pos,resistance,paramResVehLock,_group] Call CreateTeamTemplate;
	_vehicles = _vehicles + (_retVal select 1);
	
	_group setFormation (['COLUMN','ECH RIGHT','LINE','FILE','DIAMOND'] select floor(random 5));
	
	_group setBehaviour 'COMBAT';
	_group setCombatMode 'RED';
	_group move (getPos _target);
	
	//--- If UPS is enabled, the ai will do a bit more than sitting in base.
	if (paramUPSMON) then {[(leader _group),_marker,"move","nofollow","reinforcement"] Spawn UPSMON};
	
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

//--- Delete UPSMON Marker if necessary.
if (paramUPSMON) then {deleteMarkerLocal _marker};