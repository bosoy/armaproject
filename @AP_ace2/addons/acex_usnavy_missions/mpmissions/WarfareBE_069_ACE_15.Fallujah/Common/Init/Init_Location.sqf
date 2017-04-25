Private ['_camps','_location','_locationName','_marker','_maxSupplyValue','_probability','_range','_resistanceTeamTypes','_startingSupplyValue'];

_location = _this select 0;
_locationName = _this select 1;
_resistanceTeamTypes = ["Group","Group"];
_probability = 70;
_startingSupplyValue = 10;
_maxSupplyValue = 50;
_range = 400;

if (count _this > 3) then {_startingSupplyValue = _this Select 2};
if (count _this > 4) then {_maxSupplyValue = _this Select 3};
if (count _this > 5) then {_range = _this Select 4};
if (count _this > 6) then {_resistanceTeamTypes = _this Select 5};
if (count _this > 7) then {_probability = _this Select 6};

if (isNull _location) exitWith {};

_camps = _location getVariable "camps";
if (isNil "_camps") then {_location setVariable ["camps",[]]};

_location setVariable ["name",_locationName];
_location setVariable ["range",_range];
_location setVariable ["startingSupplyValue",_startingSupplyValue];
_location setVariable ["maxSupplyValue",_maxSupplyValue];

diag_log Format["[WFBE (INIT)][frameno:%3 | ticktime:%4] Init_Location: Town '%1' (%2) initialization - [Done]",str _location,_locationName,diag_frameno,diag_tickTime];

waitUntil {commonInitComplete};

if (isServer) then {
	//--- Don't pause.
	[_location,_startingSupplyValue,_range,_resistanceTeamTypes,_probability,_maxSupplyValue] Spawn {
		Private ["_defenses","_isSet","_location","_marker","_maxSupplyValue","_probability","_range","_resistanceTeamTypes","_size","_startingSupplyValue"];
		_location = _this select 0;
		_startingSupplyValue = _this select 1;
		_range = _this select 2;
		_resistanceTeamTypes = _this select 3;
		_probability = _this select 4;
		_maxSupplyValue = _this select 5;
		
		/* OA Depots are made of kryptonite */
		if (WF_A2_Arrowhead || WF_A2_CombinedOps) then {_location addEventHandler ['handleDamage',{false}]};
		_isSet = _location getVariable 'sideID';
		if (isNil '_isSet') then {_location setVariable ["sideID",RESISTANCEID,true]};
		_location setVariable ["supplyValue",_startingSupplyValue,true];
		_location setVariable ["resistanceTypes",_resistanceTeamTypes];
		sleep (random 1);
		waitUntil {serverInitComplete && townInit};
		//--- Town SV & Control script.
		[_location,_range] ExecFSM "Server\FSM\updatetown.fsm";
		if !(paramRes) then {
			_defenses = _location nearEntities['WFBE_RESISTANCEDEFENSENAMES' Call GetNamespace,_range];
			{deleteVehicle _x} forEach _defenses;
		};
		//--- Main AI Script
		if (paramOccup || paramRes) then {[_location, _resistanceTeamTypes, _probability] ExecFSM "Server\FSM\updatetownai.fsm"};

		//--- UPSMON Area Definition.
		if (paramUPSMON) then {
			_marker = Format['UPSMON_TOWN_%1',str _location];
			createMarkerLocal [_marker, getPos _location];
			_marker setMarkerColorLocal "ColorBlue";
			_marker setMarkerShapeLocal "RECTANGLE";
			_marker setMarkerBrushLocal "BORDER";
			_size = 'WFBE_UPSMONTOWNAREASIZE' Call GetNamespace;
			_marker setMarkerSizeLocal [_size select 0,_size select 1];
			_marker setMarkerAlphaLocal 0;
		};
	};
};

towns = towns + [_location];

if (local player) then {
	waitUntil {clientInitComplete};
	_marker = Format["%1Depot",str _location];
	createMarkerLocal [_marker,getPos _location];
	_marker setMarkerTypeLocal "Depot";
	_marker setMarkerColorLocal ("Resistance" Call GetMarkerColoration);
};