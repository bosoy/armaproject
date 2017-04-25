
private ["_xtra","_i","_descVehi","_isInVehicle","_desc","_text","_amount","_val","_val2",
"_ainumber","_finalNumber","_txt","_funds","_objects","_vehicle","_destroy","_units","_curUnitSel",
"_pos","_vehi","_timer","_curSel","_currentVD","_transferAmount","_lastvd","_lasttg","_is","_x"];
disableSerialization;

MenuAction = -1;

switch (votePopUp) do {
	case true: {CtrlShow [13017,false]};
	case false: {CtrlShow [13016,false]};
};

_currentVD = viewDistance;
_funds = Call GetPlayerFunds;
ctrlSetText [13002, Format [localize "STR_WF_ViewDistance",_currentVD]];
ctrlSetText [13004, Format [localize "STR_WF_TerrainGrid",currentTG]];
ctrlSetText [13006, Format [localize "STR_WF_MoneyTransfer",0]];
ctrlSetText [13010, Format [localize "STR_WF_Income",Call GetPlayerFunds,(sideJoined) Call GetIncome]];
	
SliderSetRange[13003,1,('WFBE_MAXVIEWDISTANCE' Call GetNamespace)];
SliderSetRange[13005,1,('WFBE_MAXCLUTTERDISTANCE' Call GetNamespace)];
SliderSetRange[13007,0,_funds];
SliderSetPosition[13003,_currentVD];
SliderSetPosition[13005,currentTG];
_lastvd = _currentVD;
_lasttg = currentTG;	
_timer = 0;

_i = 1;
{
	_xtra = if (isPlayer (leader _x)) then {name (leader _x)} else {"AI"};
	lbAdd[13008,Format ["[%1] %2",_i,_xtra]];
	_i = _i + 1;
} forEach clientTeams; 
lbSetCurSel[13008,0];

_units = ((Units Group player) Call GetLiveUnits);
_units = _units - [player];
{
	_desc = [typeOf _x, 'displayName'] Call GetConfigInfo;
	_finalNumber = (_x) Call GetAIDigit;
	_isInVehicle = "";
	if (_x != vehicle _x) then {
		_descVehi = [typeOf (vehicle _x), 'displayName'] Call GetConfigInfo;
		_isInVehicle = " [" + _descVehi + "] ";
	};
	_txt = "["+_finalNumber+"] "+ _desc + _isInVehicle;
	lbAdd[13013,_txt];
} forEach _units;
lbSetCurSel[13013,0];

{lbAdd[13018,_x]} forEach ["None","FX 1","FX 2","FX 3","FX 4","FX 5"];
lbSetCurSel[13018,currentFX];

while {alive player && dialog} do {
	sleep 0.05;
	
	if (Side player != sideJoined) exitWith {closeDialog 0};
	if (!dialog) exitWith {};
	
	_curSel = lbCurSel 13008;
	_currentVD = Floor (SliderPosition 13003);
	currentTG = Floor (SliderPosition 13005);
	_transferAmount = Floor (SliderPosition 13007);
	
	ctrlSetText [13002, Format [localize "STR_WF_ViewDistance",_currentVD]];
	ctrlSetText [13004, Format [localize "STR_WF_TerrainGrid",currentTG]];
	ctrlSetText [13006, Format [localize "STR_WF_MoneyTransfer",_transferAmount]];
	
	if (MenuAction == 1) then {
		MenuAction = -1;
		if ((_transferAmount != 0)&&((clientTeams select _curSel) != group player)) then {
			[(clientTeams select _curSel),_transferAmount] Call ChangeTeamFunds;
			-_transferAmount Call ChangePlayerFunds;
			_funds = Call GetPlayerFunds;
			WFBE_LocalizeMessage = [vehicleVarName leader (clientTeams select _curSel),'CLTFNCLOCALIZEMESSAGE',['FundsTransfer',_transferAmount,name player]];
			publicVariable 'WFBE_LocalizeMessage';
			if (isHostedServer) then {[vehicleVarName leader (clientTeams select _curSel),'CLTFNCLOCALIZEMESSAGE',['FundsTransfer',_transferAmount,name player]] Spawn HandlePVF};
			sliderSetRange[13007,0,_funds];
		};
	};
	
	if (MenuAction == 2) then {
		MenuAction = -1;
		_vehicle = vehicle player;
		if (player != _vehicle) then {
			if (getPos _vehicle select 2 > 3 && !surfaceIsWater (getPos _x)) then {
				[_vehicle, getPos _vehicle, 15] Call PlaceSafe;
			} else {
				_vehicle setPos [getPos _vehicle select 0, getPos _vehicle select 1, 0.5];
				_vehicle setVelocity [0,0,-0.5];
		};
		};
		if (player == _vehicle) then {
			_objects = player nearEntities[["Car","Motorcycle","Tank"],10];
			if (count _objects > 0) then {		
				{
					if (getPos _x select 2 > 3 && !surfaceIsWater (getPos _x)) then {
						[_x, getPos _x, 15] Call PlaceSafe;
					} else {
						_x setPos [getPos _x select 0, getPos _x select 1, 0.5];
						_x setVelocity [0,0,-0.5];
			};
				} forEach _objects;
		};
	};
	};
	
	if (MenuAction == 3) then {
		MenuAction = -1;
		_curUnitSel = lbCurSel 13013;
		if (_curUnitSel != -1) then {
			_vehicle = vehicle (_units select _curUnitSel);
			_destroy = [(_units select _curUnitSel)];
			if (_vehicle != (_units select _curUnitSel)) then {_destroy = _destroy + [_vehicle]};
			{
				if (_x isKindOf 'Man') then {removeAllWeapons _x};
				_x setDammage 1;
			} forEach _destroy;
			
			_units = ((Units Group player) Call GetLiveUnits);
			_units = _units - [leader group player];
			lbClear 13013;
			{
				_desc = [typeOf _x, 'displayName'] Call GetConfigInfo;
				_finalNumber = (_x) Call GetAIDigit;
				_isInVehicle = "";
				if (_x != vehicle _x) then {
					_descVehi = [typeOf (vehicle _x), 'displayName'] Call GetConfigInfo;
					_isInVehicle = " [" + _descVehi + "] ";
				};
				_txt = "["+_finalNumber+"] "+ _desc + _isInVehicle;
				lbAdd[13013,_txt];
			} forEach _units;
			lbSetCurSel[13013,0];
		};
	};
	
	if (MenuAction == 4) then {
		MenuAction = -1;
		closeDialog 0;
		titleCut["","BLACK FADED",0];
		_pos = position player;
		_vehi = "Lada1" createVehicle [0,0,0];
		player moveInCargo _vehi;
		deleteVehicle _vehi;
		player setPos _pos;
		titleCut["","BLACK IN",5];
	};
	
	if (MenuAction == 5) then {
		MenuAction = -1;
		if (votePopUp) then {votePopUp = false} else {votePopUp = true};
		switch (votePopUp) do {
			case true: {CtrlShow [13017,false];CtrlShow [13016,true]};
			case false: {CtrlShow [13016,false];CtrlShow [13017,true]};
		};
	};
	
	if (MenuAction == 6) then {
		MenuAction = -1;
		currentFX = lbCurSel 13018;
		[currentFX] Spawn FX;
	};
	
	if (_currentVD != _lastvd) then {setViewDistance _currentVD};
	if (currentTG != _lasttg) then {setTerrainGrid currentTG};
	_lastvd = _currentVD;
	_lasttg = currentTG;
	
	if (_timer > 2) then {ctrlSetText [13010, Format [localize "STR_WF_Income",Call GetPlayerFunds,(sideJoined) Call GetIncome]];_timer = 0};
	_timer = _timer + 0.05;
};
