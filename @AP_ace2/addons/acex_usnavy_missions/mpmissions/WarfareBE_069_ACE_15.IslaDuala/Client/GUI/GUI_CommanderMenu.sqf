disableSerialization;

_display = _this select 0;
_map = _display DisplayCtrl 23002;

_hqDeployed = (sideJoined) Call GetSideHQDeployed;
if (!_hqDeployed || !paramUseWorkers) then {ctrlEnable [23004, false];ctrlEnable [23006, false]};
if !(paramUseWorkers) then {ctrlSetText[23005, localize 'STR_WF_Disabled']};

MenuAction = -1;

_maxWorkers = 'WFBE_WORKERS_MAX' Call GetNamespace;
_workerPrice = 'WFBE_WORKERS_PRICE' Call GetNamespace;
_incomeSystem = 'WFBE_INCOMESYSTEM' Call GetNamespace;
_incomeDividision = 'WFBE_INC_DIVIDE_COM' Call GetNamespace;
_aliveWorkers = [];
_workers = [];
_lastWorkersUpdate = -10;
_lastComboUpdate = -30;
_lastPurchase = -5;
_income = 0;
_updateComboWorker = true;
_hasStarted = true;

if (_incomeSystem in [3,4]) then {
	sliderSetRange[23010,0,100];
	_income = Call Compile Format["%1CommanderPercent",sideJoined];
	sliderSetPosition[23010, _income];
} else {
	ctrlEnable [23012, false];
};

while {alive player && dialog} do {	
	if (side player != sideJoined) exitWith {closeDialog 0};
	if !(dialog) exitWith {};
	
	_funds = Call GetPlayerFunds;
	
	//--- Income System.
	if (_incomeSystem in [3,4]) then {
		ctrlSetText[23011, Format["%1%2",_income,"%"]];
		_currentPercent = Call Compile Format["%1CommanderPercent",sideJoined];
		
		_income = floor(sliderPosition 23010);
		
		sliderSetPosition[23010, _income];
		
		_calInc = (sideJoined) Call GetTownsIncome;
		
		if (_currentPercent != _income || _hasStarted) then {
			if (_hasStarted) then {_hasStarted = false};
			
			_income_players = 0;
			_income_commander = 0;
			switch (_incomeSystem) do {
				case 3: {
					_income_players = round(_calInc * (((100 - _income)/100)/maxPlayers));
					_income_commander = round((_calInc * (_income/100)) / _incomeDividision) + _income_players;
				};
				case 4: {
					_income_players = round(_calInc * (100 - _income) / 100);
					_income_commander = round((_calInc - _income_players)*maxPlayers) + _income_players;
				};
			};
			
			ctrlSetText [23013, localize 'STR_WF_Income_Sys_Com' + ": $" + str(_income_commander) + "."];
			ctrlSetText [23014, localize 'STR_WF_Income_Sys_Ply' + ": $" + str(_income_players) + "."];
		};
		
		if (MenuAction == 3) then {
			MenuAction = -1;
			
			if (_currentPercent != _income) then {
				Call Compile Format["%1CommanderPercent = _income; publicVariable '%1CommanderPercent';",sideJoined]; 
			};
		};
	};
	
	//--- Workers System.
	if (paramUseWorkers) then {
		if (time - _lastComboUpdate > 5) then {
			_updateComboWorker = true;
			_lastComboUpdate = time;
		};
	
		_workers = Call Compile Format ["WF_%1Workers",sideJoinedText];
		if (time - _lastWorkersUpdate > 5) then {_aliveWorkers = (_workers) Call GetLiveUnits;_lastWorkersUpdate = time};
		_hqDeployed = (sideJoined) Call GetSideHQDeployed;
		
		if (!_hqDeployed || time - _lastPurchase < 3 || count _aliveWorkers >= _maxWorkers || _funds < _workerPrice) then {ctrlEnable [23004, false]} else {ctrlEnable [23004, true]};
		
		//--- Workers tracker.
		if (_updateComboWorker) then {
			_updateComboWorker = false;
			lbClear 23007;
			
			for '_i' from 0 to count(_aliveWorkers)-1 do {
				lbAdd [23007, localize "STR_WF_Workers" + " " + str(_i+1)];
			};
		};
		
		ctrlSetText [23005, Format ["$%1. (%2/%3)",_workerPrice,count _aliveWorkers,_maxWorkers]];
	};
	
	//--- Hire Workers.
	if (MenuAction == 1) then {
		MenuAction = -1;
		
		//--- Which index.
		_index = 0;
		for '_i' from 0 to count(_workers)-1 do {
			if (isNull (_workers select _i)) exitWith {_index = _i};
		};
		
		if (_index == 0 && count(_workers) > 0) then {_index = count _workers};
		
		if (count _aliveWorkers <= _maxWorkers && _hqDeployed) then {
			-(_workerPrice) Call ChangePlayerFunds;
		
			WFBE_RequestWorker = ['SRVFNCREQUESTWORKER',[sideJoined,(sideJoined) Call GetSideHQ,_index]];
			publicVariable 'WFBE_RequestWorker';
			if (isHostedServer) then {['SRVFNCREQUESTWORKER',[sideJoined,(sideJoined) Call GetSideHQ,_index]] Spawn HandleSPVF};
			
			_workers set [_index, WF_Logic];
			Call Compile Format ["WF_%1Workers = _workers; publicVariable 'WF_%1Workers';",sideJoinedText];
			
			_lastPurchase = time;
			_lastWorkersUpdate = -10;
			_updateComboWorker = true;
		};
	};
	
	//--- Disband Worker.
	if (MenuAction == 2) then {
		MenuAction = -1;
		
		_value = lbCurSel 23007;
		
		if (_value != -1) then {
			(_aliveWorkers select _value) setDammage 1;
			_lastWorkersUpdate = -10;
			_updateComboWorker = true;
		};
	};
	
	//--- Minimap update.
	if (MenuAction == 100) then {
		MenuAction = -1;
		_value = lbCurSel 23007;
		
		if (_value != -1) then {
			ctrlMapAnimClear _map;
			_map ctrlMapAnimAdd [1,.175,getPos(_aliveWorkers select _value)];
			ctrlMapAnimCommit _map;
		};
	};
	
	sleep 0.1;
};